// PlusMinus37
#include QMK_KEYBOARD_H
#include "variables.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
	switch(get_highest_layer(layer_state)) {
		// Volume control
		default:
		case _QWERTY:
		case _COLEMAK:
			if (clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
			break;
		// Flux Temperature
		case _LEFT:
			register_code(KC_LALT);
			register_code(KC_LSFT);

			if (clockwise) {
				tap_code(KC_PGUP);
			} else {
				tap_code(KC_PGDN);
			}
			unregister_code(KC_LALT);
			unregister_code(KC_LSFT);
			break;

		// Flux Brightness
		case _RIGHT:
			register_code(KC_LALT);
			if (clockwise) {
				tap_code(KC_PGUP);
			} else {
				tap_code(KC_PGDN);
			}
			unregister_code(KC_LALT);
			break;
	}
	return false;
}