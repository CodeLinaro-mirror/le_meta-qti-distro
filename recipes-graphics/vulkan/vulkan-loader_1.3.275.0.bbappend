## only selecting wayland configuration and not x11
ANY_OF_DISTRO_FEATURES:append = "wayland"

RRECOMMENDS:${PN}:remove = "mesa-vulkan-drivers"