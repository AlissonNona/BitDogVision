#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>

void ultrasonic_init();
uint16_t read_ultrasonic_distance();

#endif