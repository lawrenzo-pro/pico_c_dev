#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "displib.c"
#include <stdio.h>
void setup(){
    stdio_init_all();
    display_init();
}
void countdown(){
    while(true){
       print_num(3);
    }
}
void beepy(){
    while(true){
        gpio_put(BEEPER_PIN,1);
        sleep_ms(333);
        gpio_put(BEEPER_PIN,0);
        sleep_ms(333);
    }
}
int main(){
    setup();
    multicore_launch_core1(beepy);
    countdown();
}