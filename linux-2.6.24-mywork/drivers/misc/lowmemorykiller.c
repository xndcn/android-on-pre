/* drivers/misc/lowmemorykiller.c
 *
 * Copyright (C) 2007-2008 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/oom.h>
#include <linux/sched.h>
#include <linux/lowmemnotify.h>

static int lowmem_shrink(int nr_to_scan, gfp_t gfp_mask);

static struct shrinker lowmem_shrinker = {
	.shrink = lowmem_shrink,
	.seeks = DEFAULT_SEEKS * 16
};
static uint32_t lowmem_debug_level = 2;
static int lowmem_adj[6] = {
	0,
	1,
	6,
	12,
};
//<<<<<<< HEAD
//static int lowmem_adj_size = 3;
//=======
static int lowmem_adj_size = 4;
//>>>>>>> android mod
static size_t lowmem_minfree[6] = {
	3*512, // 6MB
	2*1024, // 8MB
	4*1024, // 16MB
	16*1024, // 64MB
};
//<<<<<<< HEAD
//static int lowmem_minfree_size = 3;
//=======
static int lowmem_minfree_size = 4;
//>>>>>>> android mod

#define lowmem_print(level, x...) do { if(lowmem_debug_level >= (level)) printk(x); } while(0)

module_param_named(cost, lowmem_shrinker.seeks, int, S_IRUGO | S_IWUSR);
module_param_array_named(adj, lowmem_adj, int, &lowmem_adj_size, S_IRUGO | S_IWUSR);
module_param_array_named(minfree, lowmem_minfree, uint, &lowmem_minfree_size, S_IRUGO | S_IWUSR);
module_param_named(debug_level, lowmem_debug_level, uint, S_IRUGO | S_IWUSR);

static int lowmem_shrink(int nr_to_scan, gfp_t gfp_mask)
{
	struct task_struct *p;
	struct task_struct *selected = NULL;
	int rem = 0;
	int tasksize;
	int i;
	int min_adj = OOM_ADJUST_MAX + 1;
	int selected_tasksize = 0;
	int array_size = ARRAY_SIZE(lowmem_adj);
//<<<<<<< HEAD
//	int other_free = memnotify_get_free();
//=======
	int other_free = global_page_state(NR_FREE_PAGES) + global_page_state(NR_FILE_PAGES);
//>>>>>>> android mod
	if(lowmem_adj_size < array_size)
		array_size = lowmem_adj_size;
	if(lowmem_minfree_size < array_size)
		array_size = lowmem_minfree_size;
	for(i = 0; i < array_size; i++) {
		if(other_free < lowmem_minfree[i]) {
			min_adj = lowmem_adj[i];
			break;
		}
	}
	if(nr_to_scan > 0)
		lowmem_print(3, "lowmem_shrink %d, %x, ofree %d, ma %d\n", nr_to_scan, gfp_mask, other_free, min_adj);
	read_lock(&tasklist_lock);
	for_each_process(p) {
		if(p->oomkilladj >= 0 && p->mm) {
			tasksize = get_mm_rss(p->mm);
			if(nr_to_scan > 0 && tasksize > 0 && p->oomkilladj >= min_adj) {
				if(selected == NULL ||
				   p->oomkilladj > selected->oomkilladj ||
				   (p->oomkilladj == selected->oomkilladj &&
				    tasksize > selected_tasksize)) {
					selected = p;
					selected_tasksize = tasksize;
					lowmem_print(2, "select %d (%s), adj %d, size %d, to kill\n",
					             p->pid, p->comm, p->oomkilladj, tasksize);
				}
			}
			rem += tasksize;
		}
	}
	if(selected != NULL) {
		lowmem_print(1, "send sigkill to %d (%s), adj %d, size %d\n",
		             selected->pid, selected->comm,
		             selected->oomkilladj, selected_tasksize);
		force_sig(SIGKILL, selected);
		rem -= selected_tasksize;
	}
	lowmem_print(4, "lowmem_shrink %d, %x, return %d\n", nr_to_scan, gfp_mask, rem);
	read_unlock(&tasklist_lock);
	return rem;
}

static int __init lowmem_init(void)
{
	lowmem_print(4, "lowmemorykiller loaded\n");

	register_shrinker(&lowmem_shrinker);
	return 0;
}

static void __exit lowmem_exit(void)
{
	unregister_shrinker(&lowmem_shrinker);
}

module_init(lowmem_init);
module_exit(lowmem_exit);

MODULE_LICENSE("GPL");

