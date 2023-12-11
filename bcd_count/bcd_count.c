#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include <stdio.h>
#define LEN  4
int tens[] = {2,3,4,5};
int ones[] = {6,7,8,9};
int  zero[] = {0,0,0,0};
int   one[] = {0,0,0,1};
int   two[] = {0,0,1,0};
int three[] = {0,0,1,1};
int  four[] = {0,1,0,0};
int  five[] = {0,1,0,1};
int   six[] = {0,1,1,0};
int seven[] = {0,1,1,1};
int eight[] = {1,0,0,0};
int  nine[] = {1,0,0,1};

void copy_array(int* source,int *dest){
    for(int i = 0; i < LEN;i++){
        dest[i] = source[i];
    }
}

void bcd_parse(int seg,int num){
    int array[4];
    switch(num){
        case 0:
            copy_array(zero,array);
            break;
        case 1:
            copy_array(one,array);
            break;
        case 2:
            copy_array(two,array);
            break;
        case 3:
            copy_array(three,array);
            break;
        case 4:
            copy_array(four,array);
            break;
        case 5:
            copy_array(five,array);
            break;
        case 6:
            copy_array(six,array);
            break;
        case 7:
            copy_array(seven,array);
            break;
        case 8:
            copy_array(eight,array);
            break;
        case 9:
            copy_array(nine,array);
            break;
        default:
             break;
    }
    if (seg == 0){
         for(int i = 0; i < LEN;i++){
            gpio_put(ones[i],array[i]);
         }
    }
    else {
         for(int i = 0; i < LEN;i++){
            gpio_put(tens[i],array[i]);
        }
    }
}
void bcd_print(int num){
    /*My Genius can clearly be seen here....*/
    int tens_place = num / 10;
    int ones_place = num - 10 * tens_place;
    printf("%d \n",tens_place);
    bcd_parse(1,tens_place);
    bcd_parse(0,ones_place);
    printf("%d \n ", ones_place);
}


int main(){
    stdio_init_all();
    for(int i = 0; i < LEN; i++){
        gpio_init(tens[i]);
        gpio_init(ones[i]);
        gpio_set_dir(ones[i],GPIO_OUT);
        gpio_set_dir(tens[i],GPIO_OUT);
    }
    while(true){
       for(int k = 0; k <= 99;k++){
         bcd_print(k);
         sleep_ms(1000);
       }
    }
}