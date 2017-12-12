#include "ledpoti.h"

#define POTI_VALUE_MAX 	1023
#define POTI_VALUE_MIN	0





void ledpoti_init(ledpoti_s *obj) {
	obj->poti = 0;
	obj->led = false;
	obj->lower_bound = 0;
	obj->upper_bound = 1023;
}





int ledpoti_get_poti_value(ledpoti_s *obj) {
	return obj->poti;
}






ledpoti_status_s ledpoti_set_poti_value(ledpoti_s *obj, int new_poti_value) {
	ledpoti_status_s res;

	if ( new_poti_value >= POTI_VALUE_MIN && new_poti_value <= POTI_VALUE_MAX) {
		obj->poti = new_poti_value;
		res.status = LEDPOTI_OK;
		return res;
	}
	res.status = LEDPOTI_OUTOFBOUNDS;
	return res;
}




bool ledpoti_evaluate_led_state(ledpoti_s *obj) {
	int v = ledpoti_get_poti_value(obj);
	obj->led = ((v >= obj->lower_bound) && (v <= obj->upper_bound));
	return obj->led;
}





ledpoti_status_s ledpoti_set_bounds(ledpoti_s *obj, int new_lower, int new_upper) {
	ledpoti_status_s res;

	if ( new_lower >= POTI_VALUE_MIN && new_upper <= POTI_VALUE_MAX) {
		if ( new_upper >= POTI_VALUE_MIN && new_upper <= POTI_VALUE_MAX) {
			if ( new_upper > new_lower) {
				obj->lower_bound = new_lower;
				obj->upper_bound = new_upper;
				res.status = LEDPOTI_OK;
			} else {
				res.status = LEDPOTI_INVALIDBOUNDS;
			}
		} else {
			res.status = LEDPOTI_OUTOFBOUNDS;
		}
	} else {
		res.status = LEDPOTI_OUTOFBOUNDS;
	}

	return res;
}
