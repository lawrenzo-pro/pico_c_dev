add_executable(
    interrupted main.c
)
target_link_libraries(interrupted pico_stdlib hardware_timer hardware_gpio)
pico_enable_stdio_uart(interrupted 0)
pico_enable_stdio_usb(interrupted 1)

pico_add_extra_outputs(interrupted)