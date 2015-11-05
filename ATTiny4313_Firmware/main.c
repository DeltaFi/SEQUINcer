#include <avr/io.h>
#include <util/delay.h>

// Define pins
#define PIN_LED1    PD0
#define PIN_LED2    PD1
// Define the delay time in ms
#define DELAY_MS    200

// Define helper macros

// write digital "high" to pin <pn> on port <prt>
#define DIGIWRITE_H(prt, pn) prt |= (1<<pn)
// write digital "low" to pin <pn> on port <prt>
#define DIGIWRITE_L(prt, pn) prt &= ~(1<<pn)

// Define long delay function
void long_delay_ms(uint16_t ms) {
    for(ms /= 10; ms>0; ms--) _delay_ms(10);
}

// program entry point
int main(void) {
    // DDRB is the "data direction register" for port B
    // the ATtinyX5 only has port B with usable pins
    // we set both LED pins to "output"
    DDRD |= (1 << PIN_LED1) | (1 << PIN_LED2);

    // initially set the pins to "low"
    DIGIWRITE_L(PORTD, PIN_LED1);

    // main loop
    uint8_t toggle = 0;
    for(;;){
        // alternate between the LEDs to let them blink
        DIGIWRITE_L(PORTD, (toggle == 0 ? PIN_LED1 : PIN_LED2));
        DIGIWRITE_H(PORTD, (toggle == 0 ? PIN_LED2 : PIN_LED1));

        // alternave the toggle variable
        toggle = !toggle;

        // make a long delay
        long_delay_ms(DELAY_MS);
    }

    return 0;   /* never reached */
}
