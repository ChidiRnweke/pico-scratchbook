add_executable(double_pwm
    double_pwm.c
    )

# pull in common dependencies
target_link_libraries(double_pwm pico_stdlib)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(double_pwm pico_cyw43_arch_none hardware_pwm) 
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(double_pwm)

