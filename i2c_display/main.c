#include "display.c"
int main(){
    stdio_init_all();
    lcd_init();  
    int i = 1;
    int prod = 1;
    while(i <= 10){
        prod *= i;
        fmt_print("Product:", prod);
        sleep_ms(300);
        i++;
    }
     lcd_clear();
    while(true){
        //to be done later
     scroll_print("This is a proof\nsomething ain't right at all.This is just a test.",100,0,0);
     sleep_ms(500);
    }
}