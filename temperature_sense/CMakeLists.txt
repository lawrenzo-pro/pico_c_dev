add_executable(temp_sense temp_sense.c)

target_link_libraries(temp_sense pico_stdlib hardware_adc)

# enable uart output, disable usb output
pico_enable_stdio_uart(temp_sense 0)
pico_enable_stdio_usb(temp_sense 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(temp_sense)

# add url via pico_set_program_url
example_auto_set_url(temp_sense)
