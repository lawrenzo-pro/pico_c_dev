add_executable(microdisp microdisp.c)
target_link_libraries(microdisp pico_stdlib pico_multicore)
pico_enable_stdio_usb(microdisp 1)
pico_enable_stdio_uart(microdisp 0)
pico_add_extra_outputs(microdisp)

example_auto_set_url(microdisp)