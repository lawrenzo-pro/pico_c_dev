#include "pico/stdlib.h"
#include <stdio.h>
int main(){
    stdio_init_all();
    const uint LED_PIN = 12;
    const uint LED_PIN_2 = 13;
    const uint BUTTON_PIN = 18;
    const uint BUTTON_2 = 17;
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
    bool state = 0;
    bool state_2 = 0;
    while(true){
        if(gpio_get(BUTTON_PIN) == 1){
            state = !state;
            gpio_put(LED_PIN,state);
            printf("Blue is toggled to %d \n", state);
        }
        else if(gpio_get(BUTTON_2) == 1 ){
            state_2 = !state_2;
            gpio_put(LED_PIN_2, state_2);
            printf("Red is toggled to %d \n", state_2);
        }
        sleep_ms(275);
    }
}