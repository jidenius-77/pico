#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/cyw43_arch.h"

#define BUTTON_PIN 15

static bool led_on = false;

void button_callback(uint gpio, uint32_t events) {
    led_on = !led_on;
    // På W-modeller styr vi LED via Wi-Fi-chippet
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);
    
    printf("PRESSED -> LED is now %s\n", led_on ? "ON" : "OFF");
}

int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    printf("Pico 2 W Interrupt Ready!\n");

    while (true) {
        tight_loop_contents();
    }
}
