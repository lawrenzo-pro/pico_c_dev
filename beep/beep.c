#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>

#define BEEP_ONE 12
#define BEEP_TWO 13


int setup(){
    stdio_init_all();
    gpio_init(BEEP_ONE);
    gpio_init(BEEP_TWO);

    gpio_set_dir(BEEP_ONE,GPIO_OUT);
    gpio_set_dir(BEEP_TWO,GPIO_OUT);
    return 0;
}
void beep_one(){
    int count_1 = 0;
    while(true){
        gpio_put(BEEP_ONE,1);
        sleep_ms(1000);
        gpio_put(BEEP_ONE,0);
        sleep_ms(1000);
        count_1++;
        printf("cycle %d for beep one starting soon \n",count_1);
    }
}
void beep_two(){
   int count_2 = 0;
   while(true){
    gpio_put(BEEP_TWO,1);
    sleep_ms(990);
    gpio_put(BEEP_TWO,0);
    sleep_ms(990);
    count_2++;
    printf("cycle %d for beep two starting soon. \n",count_2);
   }
}
int main(){
    setup();
    multicore_launch_core1(beep_one);
    beep_two();
    return 0;
}