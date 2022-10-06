######################################################################
# This configuration defines an OE Linux based distribution containing
# libraries and utilities required for running the complete system on
# qti Telematics NAD chipsets.
######################################################################

# Get the default tele distro configuration
require conf/distro/include/qti-distro-tele.inc

DISTRO_NAME = "QTI Linux Telematics NAD and TelAF distro."

##################################################################
# list of distro features
##################################################################
#
# nand-squashfs    Generate squashfs system image
# Other distros will be added gradually

DISTRO_FEATURES_append = " nand-squashfs"
