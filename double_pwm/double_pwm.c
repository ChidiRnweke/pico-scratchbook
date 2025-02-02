#include "pico/stdlib.h"
#include "hardware/pwm.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 500
#endif

#ifndef PWM_WRAP
#define PWM_WRAP 65535
#endif

#ifndef PWM_CLKDIV
#define PWM_CLKDIV 4.0
#endif

#ifndef PWM_DELAY_MS
#define PWM_DELAY_MS 10
#endif

#ifndef PWM_STEP
#define PWM_STEP 500
#endif

#ifndef LED_PIN_1
#define LED_PIN_1 15
#endif

#ifndef LED_PIN_2
#define LED_PIN_2 14
#endif

void initialize_pwm(uint pin)
{
    gpio_init(pin);
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice, PWM_WRAP);
    pwm_set_clkdiv(slice, PWM_CLKDIV);
    pwm_set_enabled(slice, true);
}

int main()
{
    initialize_pwm(LED_PIN_1);
    initialize_pwm(LED_PIN_2);
    int current_pin = LED_PIN_1;

    while (true)
    {
        for (int duty = 0; duty < PWM_WRAP; duty += PWM_STEP)
        {
            pwm_set_gpio_level(current_pin, duty);
            sleep_ms(PWM_DELAY_MS);
        }
        for (int duty = PWM_WRAP; duty > 0; duty -= PWM_STEP)
        {
            pwm_set_gpio_level(current_pin, duty);
            sleep_ms(PWM_DELAY_MS);
        }
        current_pin = (current_pin == LED_PIN_1) ? LED_PIN_2 : LED_PIN_1;
    }
}