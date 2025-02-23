#include "buzzer.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"

#define BUZZER_PIN 16

void buzzer_init() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_enabled(slice_num, true);
}

void play_alert(int frequency_hz, int duration_ms) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_wrap(slice_num, 125000 / frequency_hz);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, (125000 / frequency_hz) / 2);
    sleep_ms(duration_ms);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 0);
}