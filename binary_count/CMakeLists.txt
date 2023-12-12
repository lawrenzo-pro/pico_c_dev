add_executable(binary_count binary_count.c)

target_link_libraries(binary_count pico_stdlib pico_multicore)

# enable uart output, disable usb output
pico_enable_stdio_uart(binary_count 0)
pico_enable_stdio_usb(binary_count 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(binary_count)

# add url via pico_set_program_url
example_auto_set_url(binary_count)