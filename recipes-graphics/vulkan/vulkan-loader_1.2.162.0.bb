SUMMARY = "3D graphics and compute API common loader"
DESCRIPTION = "Vulkan is a new generation graphics and compute API \
that provides efficient access to modern GPUs. These packages \
provide only the common vendor-agnostic library loader, headers and \
the vulkaninfo utility."
HOMEPAGE = "https://www.khronos.org/vulkan/"
BUGTRACKER = "https://github.com/KhronosGroup/Vulkan-Loader"
SECTION = "libs"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=7dbefed23242760aa3475ee42801c5ac"

SRC_URI = "${CLO_LE_GIT}/external/khronosgroup/vulkan-loader.git;protocol=https;branch=khronosvull/sdk-1.2.162 \
          file://0001-Add-VkSharedPresentSurfaceCapabilitiesKHR_to_vkGetPhysicalDeviceSurfaceCapabilities2KHR.patch;patch=1 \
          "
SRC_URI[sha256sum] = "516aaa79fba7f648e042e0614b5fae5fbcb83d3b9bdd912110a2e41c0ea9ad17"
SRCREV = "767dfe935f13344313cbbbeb18e3f1fe6e23761a"
S = "${WORKDIR}/git"

inherit cmake features_check

## only selecting wayland configuration and not x11
ANY_OF_DISTRO_FEATURES = "wayland"

## it depends on vulkan headers project
DEPENDS += "vulkan-headers"

EXTRA_OECMAKE = "\
                 -DBUILD_TESTS=OFF \
                 -DPYTHON_EXECUTABLE=${HOSTTOOLS_DIR}/python3 \
                 -DASSEMBLER_WORKS=FALSE \
                 "

# must choose x11 or wayland or both
# Need only wayland backend support only.
PACKAGECONFIG ??= "${@bb.utils.filter('DISTRO_FEATURES', 'wayland', d)}"

# configured x11 package to disable building. and kept only wayland support build
PACKAGECONFIG[x11] = "-DBUILD_WSI_XLIB_SUPPORT=OFF -DBUILD_WSI_XCB_SUPPORT=OFF, -DBUILD_WSI_XLIB_SUPPORT=OFF -DBUILD_WSI_XCB_SUPPORT=OFF"
PACKAGECONFIG[wayland] = "-DBUILD_WSI_WAYLAND_SUPPORT=ON, -DBUILD_WSI_WAYLAND_SUPPORT=OFF, wayland"


UPSTREAM_CHECK_GITTAGREGEX = "sdk-(?P<pver>\d+(\.\d+)+)"

LEAD_SONAME="libvulkan.so"
FILES_${PN} += "/usr/lib/*.so"

CFLAGS += " -Wno-error "
