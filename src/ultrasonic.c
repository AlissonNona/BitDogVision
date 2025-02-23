#include "ultrasonic.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define TRIG_PIN 14
#define ECHO_PIN 15

void ultrasonic_init() {
    gpio_init(TRIG_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_put(TRIG_PIN, 0);
    
    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}

uint16_t read_ultrasonic_distance() {
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    while (!gpio_get(ECHO_PIN)); // Aguarda pulso HIGH
    absolute_time_t start = get_absolute_time();
    
    while (gpio_get(ECHO_PIN)); // Aguarda pulso LOW
    absolute_time_t end = get_absolute_time();
    
    uint64_t pulse_length = absolute_time_diff_us(start, end);
    return pulse_length / 58; // Conversão para cm (usando HC-SR04)
}