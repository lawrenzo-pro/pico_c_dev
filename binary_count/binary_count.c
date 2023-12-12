#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>
int pins[]={2,3,4,5,6,7,8,9};
void dec_to_bin_array(int num,int* dest){
    /*Magic code to convert an integer into an array of 1's and 0's,
    limited to 8 bit numbers though
    */

    int bit_7 = num / 128;
    int rem7 = num % 128;
    int bit_6 = rem7 / 64;
    int rem6 = rem7 % 64;
    int bit_5 = rem6 / 32;
    int rem5 = rem6 % 32;
    int bit_4 = rem5 / 16;
    int rem4 = rem5 % 16;
    int bit_3 = rem4 / 8;
    int rem3 = rem4 % 8;
    int bit_2 = rem3 / 4;
    int rem2 = rem3 % 4;
    int bit_1 = rem2 / 2;
    int rem1 = rem2 % 2;
    int bit_0 = rem1 / 1;

    int array[]= {bit_7,bit_6,bit_5,bit_4,bit_3,bit_2,bit_1,bit_0};
    for(int i = 0; i < 8; i++){
        dest[i] = array[i];
    }
}
void binary_print(int num){
    int output[8];
    dec_to_bin_array(num,output);
    for(int i = 0; i< 8; i++){
        gpio_put(pins[i],output[i]);
    }
}
int main(){
    for(int i = 0;i<8;i++){
        gpio_init(pins[i]);
        gpio_set_dir(pins[i],GPIO_OUT);
    }
    while(true){
        for(int i = 0; i<256;i++){
            binary_print(i);
            sleep_ms(1000);
        }
    }
}