#include "pico/stdlib.h"
int main(){
    const uint LED_PIN = 12;
    const uint LED_PIN_2 = 13;
    const uint BUTTON_PIN = 18;
    gpio_init(LED_PIN);
    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN,GPIO_OUT);
    gpio_set_dir(LED_PIN_2,GPIO_OUT);
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN,GPIO_IN);
    gpio_pull_down(BUTTON_PIN);
    bool state = 0;
    while(true){
        if(gpio_get(BUTTON_PIN) == 1){
            state = !state;
            gpio_put(LED_PIN,state);
        }
        else{
            gpio_put(LED_PIN_2,!state);
        }
        sleep_ms(250);
    }
}