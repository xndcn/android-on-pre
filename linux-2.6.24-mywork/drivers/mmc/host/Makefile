#
# Makefile for MMC/SD host controller drivers
#

ifeq ($(CONFIG_MMC_DEBUG),y)
	EXTRA_CFLAGS		+= -DDEBUG
endif

obj-$(CONFIG_MMC_ARMMMCI)	+= mmci.o
obj-$(CONFIG_MMC_PXA)		+= pxamci.o
obj-$(CONFIG_MMC_IMX)		+= imxmmc.o
obj-$(CONFIG_MMC_SDHCI)		+= sdhci.o
obj-$(CONFIG_MMC_RICOH_MMC)	+= ricoh_mmc.o
obj-$(CONFIG_MMC_WBSD)		+= wbsd.o
obj-$(CONFIG_MMC_AU1X)		+= au1xmmc.o
obj-$(CONFIG_MMC_OMAP)		+= omap.o
obj-$(CONFIG_MMC_AT91)		+= at91_mci.o
obj-$(CONFIG_MMC_TIFM_SD)	+= tifm_sd.o
obj-$(CONFIG_MMC_GOLDFISH)	+= goldfish.o
obj-$(CONFIG_MMC_SPI)		+= mmc_spi.o
obj-$(CONFIG_MMC_OMAP2430)      += omap_hsmmc.o
obj-$(CONFIG_MMC_OMAP3430)      += omap_hsmmc.o
obj-$(CONFIG_MMC_HSMMC_PE)	+= omap_hsmmc_pe.o
obj-$(CONFIG_MMC_S3C)		+= s3cmci.o
obj-$(CONFIG_HSMMC_S3C)		+= s3c-hsmmc.o
