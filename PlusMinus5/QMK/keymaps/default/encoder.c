// PlusMinus5 based on Eleksmaker TF05
#include QMK_KEYBOARD_H
#include "variables.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
	switch(get_highest_layer(layer_state)) {
		// Volume control
		case _ONE:
		case _TWO:
		case _THREE:
		case _FOUR:
		default:
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
		break;
	}
	return false;
}