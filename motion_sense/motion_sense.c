#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "displib.c"

#define ADC_NUM 0
#define ADC_PIN (26 + ADC_NUM)
int main(){
    stdio_init_all();
    adc_init();

    adc_gpio_init(ADC_PIN);
    adc_select_input(ADC_NUM);

     while (1) {
        // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
        const float conversion_factor = 3.3f / (1 << 12);
        uint16_t result = adc_read();
        printf("Raw value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);
        sleep_ms(500);
    }

}

