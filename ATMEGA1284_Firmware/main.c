#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"
//#include ""
//#include ""
//#include ""

#define DELAY_MS 200

void init_analog()


int main(void) {
	lcd_init();
	for(;;){
		lcd_clrscr();
		lcd_puts("Hello World...");
			// make a long delay
		long_delay_ms(DELAY_MS);
	}
	return 0;
}
