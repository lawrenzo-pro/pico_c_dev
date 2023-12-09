#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "displib.c"
#include <stdio.h>

void countdown(){
    while(true){
       for(int i = 0;i<= 9;i++){
        print_num(i);
        sleep_ms(1000);
        clear();
       }
    }
}
int main(){
    stdio_init_all();
    setup();
    multicore_launch_core1(beepy);
    countdown();
}