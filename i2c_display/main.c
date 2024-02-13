#include "display.c"
int main(){
    stdio_init_all();
    lcd_init();  
    int num = 86;
    char str[16];
    char *str2 = "something";
    sprintf(str,"%d", num);
    char *str3 = strcat(str,str2);
    while(true){
        //to be done later
        lcd_print("Hello !", 0,0);
        lcd_print(str3,1,0);
        printf("%s ", str3);
    }
}