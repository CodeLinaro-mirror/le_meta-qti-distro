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

INIT_MANAGER = "none"
DISTRO_FEATURES_BACKFILL_CONSIDERED_append = ""
VIRTUAL-RUNTIME_dev_manager = ""

IMAGE_DEV_MANAGER = ""
IMAGE_INIT_MANAGER = ""
IMAGE_INITSCRIPTS = ""

