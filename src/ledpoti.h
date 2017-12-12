#ifndef __LEDPOTI_H
#define __LEDPOTI_H

/**
 * \brief Interface structure for Led Poti Example
 *
 * This stores the internal state and the bounds
 * for turning the led on or off.
 */
typedef struct ledpoti_s {

	int	poti;				/**< Last potentiometer value */

	bool led;			/**< Last LED state (true=on) */

	int lower_bound;		/**< LED goes on if poti in [lower_bound..upper_bound] */
	int upper_bound;		/**< LED goes on if poti in [lower_bound..upper_bound] */

} ledpoti_s;

/** error definitions */
enum ledpoti_status_e {
	LEDPOTI_OK = 0,
	LEDPOTI_OUTOFBOUNDS,
	LEDPOTI_INVALIDBOUNDS
};

/** status struct */
typedef struct ledpoti_status_s {
	bool	result;
	ledpoti_status_e	status;

} ledpoti_status_s;


/** \brief Initializes an empty struct, sets values to 0 */
void ledpoti_init(ledpoti_s *obj);

/** \brief returns the poti value */
int ledpoti_get_poti_value(ledpoti_s *obj);

/** \brief sets poti value, if bounds are ok */
ledpoti_status_s ledpoti_set_poti_value(ledpoti_s *obj, int new_poti_value);

/** \brief reset the bounds */
ledpoti_status_s ledpoti_set_bounds(ledpoti_s *obj, int new_lower, int new_upper);

/** \brief calculcates the led state */
bool ledpoti_evaluate_led_state(ledpoti_s *obj);

#endif
