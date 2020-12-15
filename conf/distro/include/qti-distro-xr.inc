######################################################################
# This configuration defines an OE Linux based distribution containing
# reference stack for running extended reality on qti chipsets.
######################################################################

# Get basic distro configuration
require conf/distro/include/qti-distro-base.inc

DISTRO_NAME = "QTI Linux extended realit distro."

##################################################################
# list of distro features
##################################################################
#
# drm:             Use DRM display drivers, provided machine supports it.
# fbdev:           Use FBDEV display drivers, provided machine supports it.
# opencl:          Include the Open Computing Language
# opengl:          Include the Open Graphics Library,
# pulseaudio:      Use pulseaudio audio server
# wayland:         Include the Wayland display server protocol.

DISTRO_FEATURES_append = " drm fbdev opencl opengl pulseaudio wayland"

## QTI defined distro features ##
# qti-audio-cal: Support QTI audio calibration solution
# qti-audio-encoder: Support QRI audio encoder
# qti-bluetooth: Support QTI bluetooth solution
# qti-camera:    Support QTI camera solution
# qti-video:     Support QTI video solution
# qti-video-encoder: Support QTI video encode
# qti-video-decoder: Support QTI video decode
# qti-adsp:      Support QTI adsp solution
# qti-security:      Support QTI security solution
# qti-slpi, qti-sensors:      Support QTI sensors solution
#

DISTRO_FEATURES_append = " qti-audio-cal qti-audio-encoder qti-bluetooth qti-camera qti-video qti-video-encoder qti-video-decoder qti-adsp qti-security qti-slpi qti-sensors qti-fastcv "

# Allow checking of required and conflicting features across the distro
INHERIT += "features_check"

# Set selinux in disabled state
DEFAULT_ENFORCING ?= "disabled"

# This is a list of packages that may have license conflicts.
# Carefully check individual package licences while adding
# as part of an image to avoid implications.
LICENSE_FLAGS_WHITELIST  += " \
    commercial_ffmpeg \
    commercial_gstreamer1.0-libav \
    commercial_gstreamer1.0-omx \
    commercial_gstreamer1.0-plugins-ugly \
"
