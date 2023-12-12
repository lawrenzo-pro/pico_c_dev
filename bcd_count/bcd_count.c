#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include <stdio.h>
#define LEN  4
int tens[] = {2,3,4,5};
int ones[] = {6,7,8,9};
void dec_to_bin_array(int num,int* dest){
    /* Magic code to convert an integer into an array of 1's and 0's,
    limited to 4 bit numbers though
    */
    int bit_3 = num / 8;
    int rem3 = num % 8;
    int bit_2 = rem3 / 4;
    int rem2 = rem3 % 4;
    int bit_1 = rem2 / 2;
    int rem1 = rem2 % 2;
    int bit_0 = rem1 / 1;
    int array[]= {bit_3,bit_2,bit_1,bit_0};
    for(int i = 0; i < LEN; i++){
        dest[i] = array[i];
    }
}
void bcd_parse(int seg,int num){
    int array[4];
    dec_to_bin_array(num,array);
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
    int ones_place = num % 10;
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