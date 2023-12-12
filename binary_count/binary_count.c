#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>
#include <math.h>
#define LEN 8
int pins[]={2,3,4,5,6,7,8,9};
void dec_to_bin_array(int num,int size,int* dest){
    int power = log2(num);
    int offset = 0;
    if(power < size - 1){
        offset = size - (power+1);
    }
    power = power + offset;
    int i = 0;
    while(power >= 0){
        int val = pow(2,power);
        int rem = num % val;
        int bit = num / val;
        num = rem;
        dest[i] = bit;
        i++;
        power--;
    }
}
void binary_print(int num){
    int output[8];
    dec_to_bin_array(num,LEN,output);
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