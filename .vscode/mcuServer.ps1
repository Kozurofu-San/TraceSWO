param([int] $cpu_frequency = 72000000)
openocd `
-f interface/stlink.cfg `
-f target/stm32f1x.cfg `
-c 'reset_config srst_only srst_nogate connect_assert_srst' `
-c 'set CONNECT_UNDER_RESET 1' `
-c 'gdb port 2000' `
-c 'tcl port 2001' `
-c 'telnet_port 2002' `
-c 'adapter speed 4000' `
-c 'bindto 0.0.0.0' `
-c "tpiu config internal - uart off ${cpu_frequency}" `
-c 'itm ports on'