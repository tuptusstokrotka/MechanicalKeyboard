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
		// Arrow Key Left / Right
		case _LEFT:
			if (clockwise) {
				tap_code(KC_RGHT);
			} else {
				tap_code(KC_LEFT);
			}
			break;

		// Arrow Key Up / Down
		case _RIGHT:
			if (clockwise) {
				tap_code(KC_DOWN);
			} else {
				tap_code(KC_UP);
			}
			break;
		// // Toy select
		case _BOTH:
		// 	toy_timer = timer_read32();
		// 	if (clockwise) {
		// 		toy_selector==3 ? toy_selector=0 : toy_selector++;
		// 	} else {
		// 		toy_selector==0 ? toy_selector=3 : toy_selector--;
		// 	}
			break;
	}
	return false;
}