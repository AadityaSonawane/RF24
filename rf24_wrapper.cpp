#include "RF24.h"

extern "C" {
    #include "rf24_wrapper.h"  // Include C-compatible header
}

// Create RF24 object
RF24 radio(22, 5);  // Use your defined GPIO pins

void init_rf24() {
    radio.begin();
    radio.setPALevel(RF24_PA_LOW);
    radio.setDataRate(RF24_250KBPS);
    radio.openWritingPipe(0xF0F0F0F0E1LL);
    radio.openReadingPipe(1, 0xF0F0F0F0E1LL);
    radio.startListening();
}

bool rf24_send(void *data, size_t len) {
    radio.stopListening();  // Switch to TX mode
    bool success = radio.write(data, len);
    return success;
}