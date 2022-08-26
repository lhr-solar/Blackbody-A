/**
 * @file main.cpp
 * @author Matthew Yu (matthewjkyu@gmail.com)
 * @brief This program pipes the CAN message from Blackbody B to USB UART.
 * @version 0.1
 * @date 2021-10-20
 * @copyright Copyright (c) 2021
 */
#include "mbed.h"
#include <cstdint>

#define SENSOR_ID  0x630

static DigitalOut led(LED1);
static CAN can(D10, D2);

int main() {
    CANMessage msg;

    while (1) {
        if (can.read(msg)) {
            printf("%s\n", msg.data);
            led = !led;
        }
        ThisThread::sleep_for(50ms);
    }
}
