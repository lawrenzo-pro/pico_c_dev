#include "pico/stdlib.h"
#include  <math.h>
#define LEN  4
int tens[] = {2,3,4,5};
int ones[] = {6,7,8,9};
void dec_to_bin_array(int decimal_number,int size,int* destination_array){
    int power = log2(decimal_number);
    int zero_padding = 0;
    if(power < size - 1){
        zero_padding = size - (power+1);
    }
    int destination_length = power + zero_padding;
    int i = 0;
    while(destination_length >= 0){
        int value = pow(2,destination_length);
        int remainder = decimal_number % value;
        int bit = decimal_number / value;
        decimal_number = remainder;
        destination_array[i] = bit;
        i++;
        destination_length--;
    }
}
void bcd_parse(int seg,int num){
    int array[4];
    dec_to_bin_array(num,LEN,array);
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
    bcd_parse(1,tens_place);
    bcd_parse(0,ones_place);
}
void bcd_init(){
    for(int i = 0; i < LEN; i++){
        gpio_init(tens[i]);
        gpio_init(ones[i]);
        gpio_set_dir(ones[i],GPIO_OUT);
        gpio_set_dir(tens[i],GPIO_OUT);
    }
}