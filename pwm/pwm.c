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

#ifndef LED_PIN
#define LED_PIN 15
#endif

int main()
{
    gpio_init(LED_PIN);

    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(LED_PIN);

    pwm_set_wrap(slice, PWM_WRAP);
    pwm_set_clkdiv(slice, PWM_CLKDIV);
    pwm_set_enabled(slice, true);

    while (true)
    {
        for (int duty = 0; duty < PWM_WRAP; duty += PWM_STEP)
        {
            pwm_set_gpio_level(LED_PIN, duty);
            sleep_ms(PWM_DELAY_MS);
        }
        for (int duty = PWM_WRAP; duty > 0; duty -= PWM_STEP)
        {
            pwm_set_gpio_level(LED_PIN, duty);
            sleep_ms(PWM_DELAY_MS);
        }
    }
}