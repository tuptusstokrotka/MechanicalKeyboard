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

//
// OLED Timers defines
#define FRAME_DURATION 		50				// 1 frame time in millis
#define OLED_SLEEP 			10000			// turn off oled after no interaction in millis
static uint32_t frame_timer = 0;			// last frame refresh in millis
static uint32_t	sleep_timer = 0;			// last interaction in millis

// Draw over another text
static int high_layer = 0; 					// SWITCH wpm / vol / caps

// volume variables
#define VOL_SLEEP 			1000			// 1s
static uint8_t 	volume_key = 0;				// 0 - No action, 1 - Volume Down, 2 - Volume Up
static uint32_t volume_timer = 0-VOL_SLEEP;	// Value != 0 to Prevent render on bootup

// capslock variables
#define CAPS_SLEEP 			2000			// 2s
static uint32_t caps_timer = 0-CAPS_SLEEP;	// Value != 0 to Prevent render on bootup
static bool caps_state = false;				// 0 - lower case, 1 - upper case