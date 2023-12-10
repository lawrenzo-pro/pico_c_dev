#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "displib.c"
#include <stdio.h>
#define BUTTON_UP 10
#define BUTTON_DOWN 11
void setup(){
    gpio_init(BUTTON_UP);
    gpio_init(BUTTON_DOWN);
    gpio_set_dir(BUTTON_UP,GPIO_IN);
    gpio_pull_down(BUTTON_UP);
    gpio_set_dir(BUTTON_DOWN,GPIO_IN);
    gpio_pull_down(BUTTON_DOWN);
    stdio_init_all();
    display_init();
}
void countdown(){
    int num = 0;
    while(true){
       if(gpio_get(BUTTON_UP) == 1){
         int limit = 9;
         if(num == limit){
            num = 0;
         }
         else{
             num = num + 1;
         }
         printf("Number %d will be displayed soon. \n", num);
         sleep_ms(200);
         clear();
       }
       if(gpio_get(BUTTON_DOWN) == 1){
         int limit = 0;
         if(num == limit){
            num = 9;
         }
         else{
            num = num - 1;
         }
         printf("Number %d will be displayed soon. \n", num);
         sleep_ms(200);
         clear();
       }
       print_num(num);
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