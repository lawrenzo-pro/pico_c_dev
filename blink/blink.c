#include "pico/stdlib.h"
#include "pico/multicore.h"
#define LED_PIN 13
#define LED_PIN_2 12
void core_0_main(){
 while (true) {
    gpio_put(LED_PIN, 1);
    sleep_ms(300);
    gpio_put(LED_PIN, 0);
    sleep_ms(300);
  }
}
void core_1_main(){
  while(true){
    gpio_put(LED_PIN_2, 1);
    sleep_ms(275);
    gpio_put(LED_PIN_2, 0);
    sleep_ms(275);
  }
}
int main(){
  gpio_init(LED_PIN);
  gpio_init(LED_PIN_2);
  gpio_set_dir(LED_PIN_2,GPIO_OUT);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  multicore_launch_core1(core_1_main);
  core_0_main();
}
