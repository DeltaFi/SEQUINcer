#include <avr/io.h>
#include <util/delay.h>
#include <hd44780.h>

// Define pins
#define PIN_LED1    PD0
#define PIN_LED2    PD1
// Define the delay time in ms
#define DELAY_MS    200

// Define long delay function
void long_delay_ms(uint16_t ms) {
    for(ms /= 10; ms>0; ms--) _delay_ms(10);
}

// program entry point
int main(void) {
    lcd_init()
    for(;;){
      lcd_clrscr();
      lcd_puts("Hello World...");
        // make a long delay
      long_delay_ms(DELAY_MS);
    }

    return 0;   /* never reached */
}
