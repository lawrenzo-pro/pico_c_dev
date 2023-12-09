#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>

int pins[] = {12,13,14,15,16,17,18,19};


//magic
void setup(){
    int i = 0;
    /*
    //the good way but it doesn't work for some reason
    int i = 0;
    while(i < sizeof(pins) - 1){
       gpio_init(pins[i]);
       gpio_set_dir(pins[i],GPIO_OUT);
       printf("%d  ,", pins[i]);
       i++;
    }
    printf("have been initialized. \n");
     */
    //so we have this, tedious mess of code
    gpio_init(pins[0]);
    gpio_init(pins[1]);
    gpio_init(pins[2]);
    gpio_init(pins[3]);
    gpio_init(pins[4]);
    gpio_init(pins[5]);
    gpio_init(pins[6]);
    gpio_init(pins[7]);
    gpio_set_dir(pins[0],GPIO_OUT);
    gpio_set_dir(pins[1],GPIO_OUT);
    gpio_set_dir(pins[2],GPIO_OUT);
    gpio_set_dir(pins[3],GPIO_OUT);
    gpio_set_dir(pins[4],GPIO_OUT);
    gpio_set_dir(pins[5],GPIO_OUT);
    gpio_set_dir(pins[6],GPIO_OUT);
    gpio_set_dir(pins[7],GPIO_OUT);

}
void beepy(){
    while(true){
        gpio_put(pins[7],1);
        sleep_ms(500);
        gpio_put(pins[7],0);
        sleep_ms(500);
    }
}
//clear the display
void clear(){
    gpio_put(pins[0],0);
    gpio_put(pins[1],0);
    gpio_put(pins[2],0);
    gpio_put(pins[3],0);
    gpio_put(pins[4],0);
    gpio_put(pins[5],0);
    gpio_put(pins[6],0);
}
//computers are stupid, I have to define the 9 digits,
//I'm still looking for a better way of doing this;
//TODO: See if making the functions return int makes it bettter
void zero(){
    gpio_put(pins[0],1);
    gpio_put(pins[1],1);
    gpio_put(pins[2],1);
    gpio_put(pins[4],1);
    gpio_put(pins[5],1);
    gpio_put(pins[6],1);
}
void one(){
    gpio_put(pins[0],1);
    gpio_put(pins[6],1);
}
void two(){
    gpio_put(pins[0],1);
    gpio_put(pins[1],1);
    gpio_put(pins[3],1);
    gpio_put(pins[4],1);
    gpio_put(pins[5],1);
}
void three(){
    gpio_put(pins[0],1);
    gpio_put(pins[1],1);
    gpio_put(pins[3],1);
    gpio_put(pins[5],1);
    gpio_put(pins[6],1);
}
void four(){
    gpio_put(pins[0],1);
    gpio_put(pins[2], 1);
    gpio_put(pins[3],1);
    gpio_put(pins[6],1);
}
void five(){
    gpio_put(pins[1],1);
    gpio_put(pins[2],1);
    gpio_put(pins[3],1);
    gpio_put(pins[5],1);
    gpio_put(pins[6],1);
}
void six(){
    gpio_put(pins[1],1);
    gpio_put(pins[2],1);
    gpio_put(pins[3],1);
    gpio_put(pins[4],1);
    gpio_put(pins[5],1);
    gpio_put(pins[6],1);
}
void seven(){
    gpio_put(pins[0],1);
    gpio_put(pins[1],1);
    gpio_put(pins[6],1);
}
void eight(){
    //same here but this implementation is cursed either way
    gpio_put(pins[0],1);
    gpio_put(pins[1],1);
    gpio_put(pins[2],1);
    gpio_put(pins[3],1);
    gpio_put(pins[4],1);
    gpio_put(pins[5],1);
    gpio_put(pins[6],1);
}
void nine(){
    gpio_put(pins[0],1);
    gpio_put(pins[1],1);
    gpio_put(pins[2],1);
    gpio_put(pins[3],1);
    gpio_put(pins[5],1);
    gpio_put(pins[6],1);
}
void countdown(){
    while(true){
        zero();
        sleep_ms(1000);
        clear();
        one();
        sleep_ms(1000);
        clear();
        two();
        sleep_ms(1000);
        clear();
        three();
        sleep_ms(1000);
        clear();
        four();
        sleep_ms(1000);
        clear();
        five();
        sleep_ms(1000);
        clear();
        six();
        sleep_ms(1000);
        clear();
        seven();
        sleep_ms(1000);
        clear();
        eight();
        sleep_ms(1000);
        clear();
        nine();
        sleep_ms(1000);
        clear();
    }
}
int main(){
    stdio_init_all();
    setup();
    multicore_launch_core1(beepy);
    countdown();
}