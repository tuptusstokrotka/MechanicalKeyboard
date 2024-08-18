// PlusMinus44 based on mochi40
#include QMK_KEYBOARD_H
#include "variables.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
	sleep_timer = timer_read32();
	switch(get_highest_layer(layer_state)) {
		// Volume control
		default:
		case _BOTH:
		case _MAIN:
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
		// Flux Temperature
		case _LEFT:
			register_code(KC_LALT);
			register_code(KC_LSFT);

			if (clockwise) {
				// tap_code(KC_RGHT);
				tap_code(KC_PGUP);
			} else {
				// tap_code(KC_LEFT);
				tap_code(KC_PGDN);
			}
			unregister_code(KC_LALT);
			unregister_code(KC_LSFT);
			break;

		// Flux Brightness
		case _RIGHT:
			register_code(KC_LALT);
			if (clockwise) {
				// tap_code(KC_RGHT);
				tap_code(KC_PGUP);
			} else {
				// tap_code(KC_LEFT);
				tap_code(KC_PGDN);
			}
			unregister_code(KC_LALT);
			break;
	}
	return false;
}