#
# Makefile for the OneNAND MTD
#

#<<<<<<< HEAD
#  Core functionality.
#obj-$(CONFIG_MTD_ONENAND)		+= onenand.o
#=======
# Core functionality.
obj-$(CONFIG_MTD_ONENAND)		+= onenand.o onenand_bbt.o
#>>>>>>> android mod

#  Board specific.
obj-$(CONFIG_MTD_ONENAND_GENERIC)	+= generic.o
obj-$(CONFIG_MTD_ONENAND_OMAP2)		+= omap2.o

# Simulator
obj-$(CONFIG_MTD_ONENAND_SIM)		+= onenand_sim.o

ifeq ($(CONFIG_CPU_S3C6400),y)
onenand-objs = s3c_onenand.o
else ifeq ($(CONFIG_CPU_S3C6410),y)
onenand-objs = s3c_onenand.o
else
onenand-objs = onenand_base.o
endif
