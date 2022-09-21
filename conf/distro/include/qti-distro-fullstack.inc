######################################################################
# This configuration defines an OE Linux based distribution containing
# full reference stack for running the system on qti chipsets.
######################################################################

# Get basic distro configuration
require conf/distro/include/qti-distro-base.inc

DISTRO_NAME = "QTI Linux full refrence stack distro."

##################################################################
# list of distro features
##################################################################
#
# drm:             Use DRM display drivers, provided machine supports it.
# dm-verity:       Support block integrity check on system image
# fbdev:           Use FBDEV display drivers, provided machine supports it.
# opencl:          Include the Open Computing Language
# opengl:          Include the Open Graphics Library,
# pulseaudio:      Use pulseaudio audio server
# selinux:         Use selinux for mandatory access control.
# tensorflow-lite: Include the tensorflow lite inference engine.
# wayland:         Include the Wayland display server protocol.
# pam:             Include pam which is needed by fscrypt.

DISTRO_FEATURES:append = " drm dm-verity fbdev opencl opengl pulseaudio selinux pam  tensorflow-lite wayland"

## QTI defined distro features ##
# qti-afr-algo:  Support QTI Auto framing algo
# qti-audio:     Support QTI audio solution
# qti-bluetooth: Support QTI bluetooth solution
# qti-camera:    Support QTI camera solution
# qti-video:     Support QTI video solution
# qti-video-encoder: Support QTI video encode
# qti-video-decoder: Support QTI video decode
# qti-cdsp:      Support QTI cdsp solution
# qti-adsp:      Support QTI adsp solution
# qti-qmmf:      Support QTI QMMF solution
# qti-security:  Support QTI security solution
# qti-vble:      Support QTI Verified boot for LE
# qwesd:         Support QWES

DISTRO_FEATURES:append = " qti-audio qti-bluetooth qti-camera qti-video qti-video-encoder qti-video-decoder qti-cdsp qti-adsp qti-fastcv qti-qmmf qti-security qti-vble qwesd"

# Allow checking of required and conflicting features across the distro
INHERIT += "features_check"

# Include in native DISTRO_FEATURES if present in the target DISTRO_FEATURES.
DISTRO_FEATURES_FILTER_NATIVE += " selinux"

# Set selinux in enforcing state by default
DEFAULT_ENFORCING = "enforcing"

# This is a list of packages that may have license conflicts.
# Carefully check individual package licences while adding
# as part of an image to avoid implications.
LICENSE_FLAGS_ACCEPTED  += " \
    commercial_ffmpeg \
    commercial_gstreamer1.0-libav \
    commercial_gstreamer1.0-omx \
    commercial_gstreamer1.0-plugins-ugly \
"
