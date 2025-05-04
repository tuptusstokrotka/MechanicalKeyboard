// PlusMinus5 based on Eleksmaker TF05
#pragma once

enum keyboard_layers {
	_MEDIA,
	_FLUX,
	_NAVI,
	_FOUR,
	_SELECT,
};

#define __x__ 		KC_NO			// Ignore

#define CUSTOM_0	KC_F13			// Use F13 - F24 to Trigger custom combinations
#define CUSTOM_1	KC_F14

// F.Lux Hotkeys
#define FLUX_EN   	LALT(KC_END)	// Flux Disable / Enable
#define FLUX_T_DN 	LSA(KC_PGDN)	// Flux Screen Temperature Warm
#define FLUX_T_UP 	LSA(KC_PGUP)	// Flux Screen Temperature Cold
#define FLUX_B_DN 	LALT(KC_PGDN)	// Flux Brightness-
#define FLUX_B_UP 	LALT(KC_PGUP)	// Flux Brightness+