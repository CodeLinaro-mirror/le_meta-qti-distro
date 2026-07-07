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
# wayland:         Include the Wayland display server protocol.

DISTRO_FEATURES:append = " pam drm fbdev opencl opengl wayland"

## QTI defined distro features ##
# qti-audio-cal: Support QTI audio calibration solution
# qti-audio-encoder: Support QRI audio encoder
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

DISTRO_FEATURES:append = " qti-audio-cal qti-audio-encoder qti-bluetooth qti-camera qti-video qti-video-encoder qti-video-decoder qti-adsp qti-cdsp qti-security qti-slpi qti-sensors qti-fastcv secure-playback pulseaudio qti-audio selinux dm-verity qti-vble"

#To Disbale SELINUX
#Use - DISTRO_FEATURES:remove = 'selinux'
DISTRO_FEATURES_FILTER_NATIVE:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'selinux', ' selinux', '', d)}"
DISTRO_EXTRA_RDEPENDS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'selinux', ' packagegroup-selinux-minimal', '', d)}"
PREFERRED_PROVIDER_virtual/refpolicy = "${@bb.utils.contains('DISTRO_FEATURES', 'selinux', 'refpolicy-mls-xr', '', d)}"

#To remove dm-verity from distro, when dm-verity-none.
#Use - MACHINE_FEATURES:remove = "dm-verity-initramfs-v2"
#Use - MACHINE_FEATURES += " dm-verity-none"
DISTRO_FEATURES:remove = "${@bb.utils.contains('MACHINE_FEATURES', 'dm-verity-none', 'dm-verity', '', d)}"



# This is a list of packages that may have license conflicts.
# Carefully check individual package licences while adding
# as part of an image to avoid implications.
LICENSE_FLAGS_ACCEPTED  += " \
    commercial_ffmpeg \
    commercial_gstreamer1.0-libav \
    commercial_gstreamer1.0-omx \
    commercial_gstreamer1.0-plugins-ugly \
"
