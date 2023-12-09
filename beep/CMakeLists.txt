add_executable(beep
        beep.c
        )

# pull in common dependencies
target_link_libraries(beep pico_stdlib pico_multicore)
pico_enable_stdio_usb(beep 1) 
pico_enable_stdio_uart(beep 0) 
# create map/bin/hex file etc.
pico_add_extra_outputs(beep)

# add url via pico_set_program_url
example_auto_set_url(beep)