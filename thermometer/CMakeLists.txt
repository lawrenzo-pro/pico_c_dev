add_executable(thermometer thermometer.c)

target_link_libraries(thermometer pico_stdlib hardware_adc)

# enable uart output, disable usb output
pico_enable_stdio_uart(thermometer 0)
pico_enable_stdio_usb(thermometer 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(thermometer)

# add url via pico_set_program_url
example_auto_set_url(thermometer)