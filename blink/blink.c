#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 500
#endif

#ifndef LED_PIN
#define LED_PIN 15
#endif

int main()
{
    int returnCode = cyw43_arch_init();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    hard_assert(returnCode == PICO_OK);
    while (true)
    {
        gpio_put(LED_PIN, true);
        sleep_ms(LED_DELAY_MS);
        gpio_put(LED_PIN, false);
        sleep_ms(LED_DELAY_MS);
    }
}