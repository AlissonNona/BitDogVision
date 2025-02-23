#include "VIBRATION.h"
#include "pico/stdlib.h"

#define VIBRATION_PIN 17

void vibration_init() {
    gpio_init(VIBRATION_PIN);
    gpio_set_dir(VIBRATION_PIN, GPIO_OUT);
}

void activate_vibration(int duration_ms) {
    gpio_put(VIBRATION_PIN, 1);
    sleep_ms(duration_ms);
    gpio_put(VIBRATION_PIN, 0);
}