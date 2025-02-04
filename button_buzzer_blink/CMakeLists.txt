add_executable(button_buzzer_blink
    button_buzzer_blink.c
    )

# pull in common dependencies
target_link_libraries(button_buzzer_blink pico_stdlib)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(button_buzzer_blink pico_cyw43_arch_none hardware_pwm) 
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(button_buzzer_blink)

