######################################################################
# This configuration defines an OE Linux based distribution containing
# reference stack for running nogplv3 on qti chipsets.
######################################################################

# Get basic distro configuration
require conf/distro/include/qti-distro-base.inc

DISTRO_NAME = "QTI Linux nogplv3 distro."

# Allow checking of required and conflicting features across the distro
INHERIT += "features_check"

# Add Incompatible license details
INCOMPATIBLE_LICENSE += "GPL-3.0* LGPL-3.0* AGPL-3.0*"

# Except recipes part of ALLOWED_GPLV2_RECIPES mask all other recipes
# from meta-gplv2 to avoid misuse
ALLOWED_GPLV2_RECIPES ?= "bash|elfutils|gettext|gdbm|m4|readline|coreutils|gawk|tar"
BBMASK += "meta-gplv2/recipes-.*/((?!${ALLOWED_GPLV2_RECIPES}).)*/"

DISTRO_FEATURES:remove = " emmc-boot "

DISTRO_FEATURES:append = " selinux nand-boot qti-vble qti-ab-boot "
DISTRO_FEATURES_FILTER_NATIVE += " selinux"

# This is a list of packages that may have license conflicts.
# Carefully check individual package licences while adding
# as part of an image to avoid implications.
LICENSE_FLAGS_ACCEPTED  += " \
    commercial_ffmpeg \
"
