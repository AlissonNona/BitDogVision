#include "pico/stdlib.h"
#include "buzzer.h"
#include "VIBRATION.h"
#include "ultrasonic.h"
#include "voice.h"
#include "BUTTON.h"

#define ALERT_DISTANCE_CM 50

int main() {
    stdio_init_all();
    buzzer_init();
    vibration_init();
    ultrasonic_init();
    voice_init();
    button_init();

    while (true) {
        uint16_t distance_cm = read_ultrasonic_distance();
        if (distance_cm > 0 && distance_cm < ALERT_DISTANCE_CM) {
            play_alert(1000, 200);
            activate_vibration(500);
            voice_announce("Objeto próximo a 50 centímetros");
        }
        sleep_ms(100);
    }
}