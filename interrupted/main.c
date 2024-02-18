#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"
#define LED1 10
#define LED2 11
#define BTN 13
#define LED3 14

bool state = false;
int num1 = 0;
bool repeating_callback(struct repeating_timer *t){
    gpio_put(LED1,state);
    printf("Led 1 triggered:%d . \n", num1);
    num1++;
    state = !state;
    return true;
}
int num2 = 0;
bool state_2 = false;
bool repeating_two(struct repeating_timer *t){
    gpio_put(LED2,state_2);
    printf("Led 2 triggered:%d . \n",num2);
    num2++;
    state_2= !state_2;
    return true;
}
bool st = true;
void handler(){
    gpio_put(LED3,st);
    st = !st;
}
int main(){
    gpio_init(LED1);
    gpio_init(LED2);
    gpio_init(LED3);
    gpio_init(BTN);
    gpio_set_dir(LED1,GPIO_OUT);
    gpio_set_dir(LED2,GPIO_OUT);
    gpio_set_dir(LED3,GPIO_OUT);
    gpio_set_dir(BTN,GPIO_IN);
    gpio_pull_down(BTN);
    stdio_init_all();
    
    struct repeating_timer timer;
    struct repeating_timer timer2;
    add_repeating_timer_ms(500,repeating_callback,NULL, &timer);
    add_repeating_timer_ms(490,repeating_two,NULL,&timer2);
    gpio_set_irq_enabled_with_callback(BTN,GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL,true,handler);
    while(true){
       tight_loop_contents();
    }
    return 0;
}