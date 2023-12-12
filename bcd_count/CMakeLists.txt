add_executable(bcd_count bcd_count.c)

target_link_libraries(bcd_count pico_stdlib pico_multicore)

# enable uart output, disable usb output
pico_enable_stdio_uart(bcd_count 0)
pico_enable_stdio_usb(bcd_count 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(bcd_count)

# add url via pico_set_program_url
example_auto_set_url(bcd_count)