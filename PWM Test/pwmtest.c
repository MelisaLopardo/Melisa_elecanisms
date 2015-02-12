#include <p24FJ128GB206.h>
#include "../lib/config.h"
#include "../lib/common.h"
#include "../lib/ui.h"
#include "../lib/timer.h"
#include "../lib/pin.h"
#include "../lib/oc.h"

int16_t main(void) {
	init_pin();
	init_ui();
	init_oc();
	init_timer();	
	// Pin 2 - D2
	pin_digitalOut(&D[2]);
	// Pin 3 - D1
	pin_digitalOut(&D[3]);
	// Pin 4 - ENA
	pin_digitalOut(&D[4]);
	// Pin 5 - IN2
	pin_digitalOut(&D[5]);
	// Pin 6 - IN1
	pin_digitalOut(&D[6]);




        while (1) {
			led_on(&led1);

			//High

			pin_set(&D[5]); // In2 is high
			pin_set(&D[4]); // Ena
			oc_pwm(&oc5,&D[2],&timer3,5,100);
			//pin_set(&D[5]);

			//Low
			pin_clear(&D[3]);
			pin_clear(&D[6]);
		}
}

