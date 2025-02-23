#include "BUTTON.h"
#include "pico/stdlib.h"

#define BUTTON_PIN 18

void button_init() {
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
}

bool is_button_pressed() {
    return !gpio_get(BUTTON_PIN);
}