// PlusMinus44 based on mochi40
#include QMK_KEYBOARD_H
#include "variables.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
	sleep_timer = timer_read32();
	switch(get_highest_layer(layer_state)) {
		// Volume control
		default:
			volume_timer = timer_read32();
			high_layer = 1;
			if (clockwise) {
				tap_code(KC_VOLU);
				volume_key = 2;
			} else {
				tap_code(KC_VOLD);
				volume_key = 1;
			}
			break;
	}
	return false;
}