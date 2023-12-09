#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>
#define LED_PIN 12
#define LED_PIN_2 13
#define BUTTON_PIN 18
#define BUTTON_2 17
void core_1_main(){
    bool state = 0;
    while(true){
         if(gpio_get(BUTTON_PIN) == 1){
            state = !state;
            gpio_put(LED_PIN,state);
            printf("Blue is toggled to %d \n", state);
        }
         sleep_ms(275);
    }
}
int main(){
    //allow communication with stdout
    stdio_init_all();
    
    gpio_init(LED_PIN);
    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN,GPIO_OUT);
    gpio_set_dir(LED_PIN_2,GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN,GPIO_IN);
    gpio_pull_down(BUTTON_PIN);

    gpio_init(BUTTON_2);
    gpio_set_dir(BUTTON_2,GPIO_IN);
    gpio_pull_down(BUTTON_2);
    bool state_2 = 0;
    multicore_launch_core1(core_1_main);
    while(true){
        if(gpio_get(BUTTON_2) == 1 ){
            state_2 = !state_2;
            gpio_put(LED_PIN_2, state_2);
            printf("Red is toggled to %d \n", state_2);
        }
        sleep_ms(275);
    }
}