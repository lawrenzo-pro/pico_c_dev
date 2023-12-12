#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "bcdlib.c"
#include <math.h>
#define TEMPERATURE_UNITS 'C'

float read_onboard_temperature(const char unit) {
    const float conversionFactor = 3.3f / (1 << 12);

    float adc = (float)adc_read() * conversionFactor;
    float tempC = 27.0f - (adc - 0.706f) / 0.001721f;

    if (unit == 'C') {
        return tempC;
    } else if (unit == 'F') {
        return tempC * 9 / 5 + 32;
    }

    return -1.0f;
}
int main() {
    bcd_init();
    stdio_init_all();
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    while (true) {
        float temperature = read_onboard_temperature(TEMPERATURE_UNITS);
        printf("Ambient temperature = %.02f %c\n", temperature, TEMPERATURE_UNITS);
        bcd_print(round(temperature));
        sleep_ms(990);
    }
}