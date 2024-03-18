USERADD_PACKAGES ?= "${PN}"

USERADD_PARAM_${PN} ?= 	" \
			-u 5002 -U leprop; \
			-u 1000 -U system; \
			-u 1001 -U radio; \
			-u 1036 -U logd; \
			-u 2000 -U adb; \
			-u 9999 -U nobody; \
			-u 2906 -U qrtr; \
			"

GROUPADD_PARAM_${PN} ?=	" \
			-g 2901 kmsg; \
			-g 3004 net_raw; \
			-g 3005 net_admin; \
			-g 3010 wakelock; \
			-g 3013 qwes; \
			"
