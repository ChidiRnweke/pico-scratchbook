#include "pico/stdlib.h"
#include "hardware/gpio.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 500
#endif

#ifndef DEBOUNCE_DELAY_MS
#define DEBOUNCE_DELAY_MS 50
#endif

#ifndef LED_PIN
#define LED_PIN 15
#endif

#ifndef BUTTON_PIN
#define BUTTON_PIN 14
#endif

static bool led_on = true;
static uint32_t last_clicked = 0;

void gpio_callback(uint gpio, uint32_t events)
{
    if (gpio == BUTTON_PIN)
    {
        uint32_t current_time = time_us_32() / 1000;
        if (current_time - last_clicked < DEBOUNCE_DELAY_MS)
        {
            return;
        }
        last_clicked = current_time;
        if (events & GPIO_IRQ_EDGE_FALL)
        {
            led_on = !led_on;
            gpio_put(LED_PIN, led_on);
        }
    }
}

int main()
{

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, led_on);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true)
    {
        tight_loop_contents();
    }
}