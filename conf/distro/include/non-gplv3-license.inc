#Eliminate gpl3 bash dependency
RDEPENDS:${PN}:remove:pn-packagegroup-qti-debug-tools = "perf"

# Eliminate gpl3 gdbserver dependency
RDEPENDS:${PN}:remove:pn-packagegroup-qti-debug-tools = "gdbserver"

