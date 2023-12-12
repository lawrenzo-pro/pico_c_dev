#include "pico/stdlib.h"
#include  <math.h>
#define LEN  4
int tens[] = {2,3,4,5};
int ones[] = {6,7,8,9};
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