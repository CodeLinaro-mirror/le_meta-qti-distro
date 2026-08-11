VALGRINDARCH:arm = "arm"
INHIBIT_PACKAGE_STRIP_FILES = "${PKGD}${libdir}/valgrind/vgpreload_memcheck-${VALGRINDARCH}-linux.so"

# Keep relro/now/noexecstack for all valgrind outputs.
LDFLAGS:append = " -Wl,-z,relro,-z,now,-z,noexecstack"
