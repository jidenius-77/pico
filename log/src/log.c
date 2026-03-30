#include "pico/stdlib.h"
#include <stdio.h>

#ifndef LOG_DELAY_MS
#define LOG_DELAY_MS 250
#endif


int main() {
    stdio_init_all();
    
    sleep_ms(3000); 
    
    printf("Starting log demo...\n");
    
    while (true) {
        printf("LED state: 1\n");
        sleep_ms(LOG_DELAY_MS);
        printf("LED state: 0\n");
        sleep_ms(LOG_DELAY_MS);
    }
}
