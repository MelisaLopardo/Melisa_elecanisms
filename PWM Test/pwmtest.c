#include <p24FJ128GB206.h>
#include "../lib/config.h"
#include "../lib/common.h"
#include "../lib/ui.h"
#include "../lib/timer.h"
#include "../lib/pin.h"
#include "./lib/oc.h"

int16_t main(void) {
	init_pin();
	init_ui();
	init_oc();
	init_timer();	
	pin_digitalOut(&D[2]);
	pin_digitalOut(&D[3]);
	pin_digitalOut(&D[4]);
	pin_digitalOut(&D[5]);
	pin_digitalOut(&D[6]);

        while (1) {
			led_on(&led1);

			//High
			pin_set(&D[2]);
			pin_set(&D[4]);
			pin_set(&D[5]);

			//Low
			pin_clear(&D[3]);
			pin_clear(&D[6]);
		}
}

