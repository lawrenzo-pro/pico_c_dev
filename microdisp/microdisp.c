#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>

int pins [] = {12,13,14,15,16,17,18,19};
int zero [] = {0,1,2,4,5,6}; // len = 6
int one  [] = {0,6}; // len = 2
int two  [] = {0,1,3,4,5}; //len = 5
int three[] = {0,1,3,5,6}; // len = 5
int four[]  = {0,2,3,6};   // len = 4
int five[]  = {1,2,3,5,6}; // len = 5
int six[]   = {1,2,3,4,5,6}; // len = 6
int seven[] = {0,1,6};       // len = 3
int eight[] = {0,1,2,3,4,5,6}; // len = 7
int nine[]  = {0,1,2,3,5,6}; // len = 6
//magic
void setup(){
    //a simple cheat
    int i = 0;
    while(i < 8){
       gpio_init(pins[i]);
       gpio_set_dir(pins[i],GPIO_OUT);
       printf("%d  ,", pins[i]);
       i++;
    }
    printf("have been initialized. \n");
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
   for(int i = 0; i < 7;i++){
    gpio_put(pins[i],0);
   }
}
//computers are stupid, I have to define the 9 digits,
//I'm still looking for a better way of doing this;
//TODO: See if making the functions return int makes it bettter
void print_zero(){
    for(int i = 0; i<6; i++){
        gpio_put(pins[zero[i]],1);
    }
}
void print_one(){
   for(int i = 0; i < 2; i++){
    gpio_put(pins[one[i]],1);
   }
}
void print_two(){
    for(int i = 0; i < 5; i++){
        gpio_put(pins[two[i]],1);
    }
}
void print_three(){
   for(int i = 0; i < 5; i++){
    gpio_put(pins[three[i]],1);
   }
}
void print_four(){
    for(int i = 0; i < 4; i++){
        gpio_put(pins[four[i]],1);
    }
}
void print_five(){
   for(int i = 0; i< 5; i++){
    gpio_put(pins[five[i]],1);
   }
}
void print_six(){
  for(int i = 0; i < 6;i++){
    gpio_put(pins[six[i]], 1);
  }
}
void print_seven(){
    for(int i = 0; i< 3;i++){
        gpio_put(pins[seven[i]],1);
    }
}
void print_eight(){
    //same here but this implementation is cursed either way
    for(int i = 0; i < 7;i++){
        gpio_put(pins[eight[i]],1);
    }
}
void print_nine(){
   for(int i = 0; i < 6;i++){
    gpio_put(pins[nine[i]],1);
   }
}
void countdown(){
    while(true){
        print_zero();
        sleep_ms(1000);
        clear();
        print_one();
        sleep_ms(1000);
        clear();
        print_two();
        sleep_ms(1000);
        clear();
        print_three();
        sleep_ms(1000);
        clear();
        print_four();
        sleep_ms(1000);
        clear();
        print_five();
        sleep_ms(1000);
        clear();
        print_six();
        sleep_ms(1000);
        clear();
        print_seven();
        sleep_ms(1000);
        clear();
        print_eight();
        sleep_ms(1000);
        clear();
        print_nine();
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