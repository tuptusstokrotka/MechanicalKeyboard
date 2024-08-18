// PlusMinus44 based on mochi40
#pragma once

// Define Layers depends on L / R space press
enum keyboard_layers {
	_MAIN,
	_LEFT,
	_RIGHT,
	_BOTH,
};

// custom combinations
#define L_SPACE LT(1,KC_SPC)
#define R_SPACE LT(2,KC_SPC)

#define L_MONITOR SGUI(KC_LEFT)				// Previous Monitor
#define L_DESKTOP LGUI(LCTL(KC_LEFT))		// Previous Desktop
#define R_DESKTOP LGUI(LCTL(KC_RGHT))		// Next Desktop
#define R_MONITOR SGUI(KC_RGHT)				// Next Monitor

#define L_SNAP LGUI(KC_LEFT)				// Snap Window Left
#define D_SNAP LGUI(KC_DOWN)				// Snap Window Down
#define U_SNAP LGUI(KC_UP)					// Snap Window Up
#define R_SNAP LGUI(KC_RGHT)				// Snap Window Right

#define FLUX_EN LALT(KC_END)				// Flux Disable / Enable
#define FLUX_T_DN LSA(KC_PGDN)				// Flux Screen Temperature Warm
#define FLUX_T_UP LSA(KC_PGUP)				// Flux Screen Temperature Cold
#define FLUX_B_DN LALT(KC_PGDN)				// Flux Brightness-
#define FLUX_B_UP LALT(KC_PGUP)				// Flux Brightness+

//
// OLED Timers defines
#define FRAME_DURATION 		70				// 1 frame time in millis
#define OLED_SLEEP 			10000			// turn off oled after no interaction in millis
static uint32_t frame_timer = 0;			// last frame refresh in millis
static uint32_t	sleep_timer = 0;			// last interaction in millis

// PEDRO!!!
// static uint8_t	pedro_frame = 0;				// Pedro_frames