######################################################################
# This configuration defines an OE Linux based distribution containing
# basic libraries and utilities like libc, busybox, systemd, udev and
# a few init scripts required for running the system on qti chipsets.
######################################################################

# Pull in security flags
require ${COREBASE}/meta-qti-distro/conf/distro/include/security_flags.inc

# DISTRO CONFIGURATION
DISTRO_VERSION ?= "${BUILDNAME}"

DISTROOVERRIDES =. "qti-distro-base:"

# SDK variables.
SDK_VENDOR = "-qtisdk"
SDK_NAME_PREFIX = "${@d.getVar('DISTRO').replace('qti-distro-', '')}"
SDK_NAME = "${SDK_NAME_PREFIX}-${SDKMACHINE}-${IMAGE_BASENAME}-${TUNE_PKGARCH}-${MACHINE}"

# DISTRO FEATURE SELECTION
MICRO_GOLD ?= "ld-is-gold"

USE_DEVFS = "0"

# Use Debian naming scheme for library (.so) files
INHERIT += "recipe_sanity"

# TOOLCHAIN
PREFERRED_VERSION_autoconf = "2.68"
ARM_INSTRUCTION_SET       ?= "arm"

######################################################################
# Optimization flags.
######################################################################
COMMON_OPTIMIZATION = " \
  -g -Wa,--noexecstack -fexpensive-optimizations \
  -frename-registers -ftree-vectorize \
  -finline-functions -finline-limit=64 \
  -Wno-error=maybe-uninitialized -Wno-error=unused-result \
"

FULL_OPTIMIZATION  = " -O2 ${COMMON_OPTIMIZATION} "
DEBUG_OPTIMIZATION = " ${FULL_OPTIMIZATION} "

# NLS
USE_NLS = "no"
USE_NLS_glib-2.0 = "yes"
USE_NLS_glib-2.0-native = "yes"
USE_NLS_gcc-cross = "no"

# Disable GIO module cache creation
GIO_MODULE_PACKAGES=""

# Disable binary locale generation
ENABLE_BINARY_LOCALE_GENERATION = "0"

#Allow library symlinks to exist alongside soname files
PACKAGE_SNAP_LIB_SYMLINKS = "0"

# Don't install ldconfig and associated gubbins
USE_LDCONFIG = "0"
LDCONFIGDEPEND = ""
COMMERCIAL_LICENSE_DEPENDEES = ""

# Add qti custom user permissions
USERADDEXTENSION = "qpermissions"

##################################################################
# list of distro features
##################################################################
# eabi:       Embedded Application Binary Interface(EABI).
# ipv4,ipv6:  Basic networking tools - ipv6,ipv4.
# largefile:  LargeFile support in Linux.
# thumb-interwork: Linker can detect thumb function called from ARM
#             state and alter call, return sequences etc to change
#             processor state as necessary.
# xattr:      Extended attributes(xattr) to filesystem.
# selinux:    SELinux support
DISTRO_FEATURES += " eabi ipv6 ipv4 largefile thumb-interwork xattr ${DISTRO_FEATURES_LIBC} selinux"

## QTI Defined distro features ##
# emmc-boot:  Support eMMC device
# qti-wifi:   Support QTI WiFi solution
# qti-ab-boot:Support QTI a/b boot solution
DISTRO_FEATURES += " emmc-boot qti-wifi qti-ab-boot"

# Use systemd init manager for system initialization.
INIT_MANAGER = "systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED_append = " pulseaudio"
VIRTUAL-RUNTIME_dev_manager = "udev"

# Change Image features for systemd.
IMAGE_DEV_MANAGER = "udev"
IMAGE_INIT_MANAGER = "systemd"
IMAGE_INITSCRIPTS = ""

##
## Below section helps to replace busybox with toybox. Upon uncommenting
## busybox usage is blacklisted and brings in additional replacement packages.
## A few VIRTUAL-RUNTIME variables are also set to alternates of busybox.
##
# PNBLACKLIST[busybox] = "busybox is not supported by this distro"
# DISTRO_EXTRA_RDEPENDS += "packagegroup-qti-toybox-addons"
# PREFERRED_PROVIDER_virtual/base-utils = "toybox"
# VIRTUAL-RUNTIME_base-utils = "toybox"
# VIRTUAL-RUNTIME_base-utils-hwclock = "util-linux-hwclock"
# VIRTUAL-RUNTIME_base-utils-syslog = "rsyslog"

RM_WORK_EXCLUDE += "make-mod-scripts"

# include QTI scripts
PATH_prepend = "${QTIBASE}/scripts:"

# Update parallelism and resource usage parameters for xz
XZ_THREADS  = "${@oe.utils.less_or_equal('CPU_COUNT', '8', '${CPU_COUNT}', '8', d)}"
XZ_DEFAULTS = "--memlimit=${XZ_MEMLIMIT} --threads=${XZ_THREADS}"

# Enable uninative for reuse -native sstate across hosts
require conf/distro/include/yocto-uninative.inc
INHERIT += "uninative"

IMAGE_CLASSES += "${@['populate_sdk_base', 'populate_sdk_ext populate_sdk_ext_llvm']['linux' in d.getVar("SDK_OS")]}"
