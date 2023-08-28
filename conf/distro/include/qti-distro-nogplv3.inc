######################################################################
# This configuration defines an OE Linux based distribution containing
# reference stack for running nogplv3 on qti chipsets.
######################################################################

# Get basic distro configuration
require conf/distro/include/qti-distro-base.inc

#Get rdkb specific configuration
require ${@bb.utils.contains("BBFILE_COLLECTIONS", "qti-rdkb", "conf/machine/include/rdkb-distro.inc", "", d)}

DISTRO_NAME = "QTI Linux nogplv3 distro."

# Allow checking of required and conflicting features across the distro
INHERIT += "features_check"

# Add Incompatible license details
INCOMPATIBLE_LICENSE += "GPL-3.0 LGPL-3.0 AGPL-3.0"

# Except recipes part of ALLOWED_GPLV2_RECIPES mask all other recipes
# from meta-gplv2 to avoid misuse
ALLOWED_GPLV2_RECIPES ?= "${@bb.utils.contains('BBFILE_COLLECTIONS', 'qti-rdkb', 'bash|elfutils|gettext|gdbm|m4|readline|coreutils|dosfstools|gawk', 'bash|elfutils|gettext|gdbm|m4|readline|coreutils', d)}"
BBMASK += "meta-gplv2/recipes-.*/((?!${ALLOWED_GPLV2_RECIPES}).)*/"

DISTRO_FEATURES_remove = " emmc-boot qti-ab-boot"

DISTRO_FEATURES_append = " selinux nand-boot qti-vble"
DISTRO_FEATURES_FILTER_NATIVE += " selinux"

# This is a list of packages that may have license conflicts.
# Carefully check individual package licences while adding
# as part of an image to avoid implications.
LICENSE_FLAGS_WHITELIST  += " \
    commercial_ffmpeg \
"
