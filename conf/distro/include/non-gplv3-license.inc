#Eliminate gpl3 bash dependency
RDEPENDS:${PN}:remove:pn-packagegroup-qti-debug-tools = "perf"

# Eliminate gpl3 gdbserver dependency
RDEPENDS:${PN}:remove:pn-packagegroup-qti-debug-tools = "gdbserver"

# Eliminate gpl3 gdbm dependency
RDEPENDS:${PN}:remove:pn-packagegroup-qti-benchmark = "perl-module-gdbm-file"
PACKAGECONFIG:remove:pn-perl = "gdbm"
PACKAGECONFIG:remove:pn-python3 = "gdbm"
