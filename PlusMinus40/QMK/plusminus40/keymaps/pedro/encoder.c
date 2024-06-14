// Copyright 2022 Julian Tarczynski
// PlusMinus40 based on mochi40
#include QMK_KEYBOARD_H
#include "variables.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
	sleep_timer = timer_read32();
	switch(get_highest_layer(layer_state)) {
		// Volume control
		default:
		case _MAIN:
			if (clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
			break;
		// Arrow Key Left / Right
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

		// Arrow Key Up / Down
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