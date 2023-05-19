######################################################################
# This configuration defines an OE Linux based distribution containing
# reference stack for running extended reality usecases without display
# support on qti chipsets.
######################################################################

# Get basic distro configuration
require conf/distro/include/qti-distro-base.inc

DISTRO_NAME = "QTI Linux extended reality distro with out display."

##################################################################
# list of distro features
##################################################################
#

## QTI defined distro features ##
# qti-bluetooth: Support QTI bluetooth solution
# qti-camera:    Support QTI camera solution
# qti-video:     Support QTI video solution
# qti-video-encoder: Support QTI video encode
# qti-video-decoder: Support QTI video decode
# qti-adsp:      Support QTI adsp solution
# qti-cdsp:      Support QTI cdsp solution
# qti-security:      Support QTI security solution
# qti-slpi, qti-sensors:      Support QTI sensors solution
# qti-vble:      Support QTI Verified boot for LE
#

DISTRO_FEATURES_append = " qti-camera qti-video qti-video-encoder qti-video-decoder qti-adsp qti-cdsp qti-security qti-slpi qti-sensors qti-fastcv secure-playback selinux dm-verity qti-vble"

DISTRO_FEATURES_FILTER_NATIVE += " selinux "
DISTRO_EXTRA_RDEPENDS += "packagegroup-selinux-minimal"
PREFERRED_PROVIDER_virtual/refpolicy = "refpolicy-mls-xr"

# Allow checking of required and conflicting features across the distro
INHERIT += "features_check"


# This is a list of packages that may have license conflicts.
# Carefully check individual package licences while adding
# as part of an image to avoid implications.
LICENSE_FLAGS_WHITELIST  += " \
    commercial_ffmpeg \
    commercial_gstreamer1.0-libav \
    commercial_gstreamer1.0-omx \
    commercial_gstreamer1.0-plugins-ugly \
"
