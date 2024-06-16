// Copyright 2022 Julian Tarczynski
// PlusMinus40 based on mochi40
#pragma once

// Define Layers depends on L / R space press
enum keyboard_layers {
	_MAIN,
	_LEFT,
	_RIGHT,
	_BOTH,
};

enum custom_keycodes {
	M0 = SAFE_RANGE,
    M1,
    M2,
    M3,
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

// animation variables
static uint8_t	doge_frame = 0;				// doge frames 0 - 1 - 2
static bool 	toy_action = 0;				// 0 - No action, 1 - Throw ball
static uint8_t	ball_frame = 0;				// throwing ball frames

// Dog Picture Pixels
static const char PROGMEM doge_head[] = {
	0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,224, 28,
	2,  5,  2, 36,  4,  4,  2,169,
	30,224,  0,  0,  0,  0,  0,  0
};
static const char PROGMEM doge_body[3][32] = {
	{//tail left
	0,  0,  0,  0,  0,224,144,  8,
	24, 96, 16,  8,  4,  3,  0,  0,
	0,  0,  0,  0,  0,  2, 14,130,
	124,  3,  0,  0,  0,  0,  0,  0
	},
	{//tail middle
	0,  0, 12, 52, 68,136,144, 32,
	32, 96, 16,  8,  4,  3,  0,  0,
	0,  0,  0,  0,  0,  2, 14,130,
	124,  3,  0,  0,  0,  0,  0,  0
	},
	{//tail right
	0, 96, 80, 80,144,144,160, 32,
	32, 96, 16,  8,  4,  3,  0,  0,
	0,  0,  0,  0,  0,  2, 14,130,
	124,  3,  0,  0,  0,  0,  0,  0
	}
};
static const char PROGMEM doge_legs[] = {
	0,  0,  0,  0,  0,  0,  1,  2,
	4, 12, 16, 16, 32, 32, 32, 40,
	62, 28, 32, 32, 62, 15, 17, 31,
	0,  0,  0,  0,  0,  0,  0,  0
};

// Ball image
const bool ball_anim[8][8] = {
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Bouncing ball height function position translated to pixels
const uint8_t ball_height[] = {
	0, 1, 4, 8, 14, 20, 27, 34, 42, 49,	 			//down

	47, 41, 36, 31, 28, 26, 25, 25, 				//up
	26, 28, 30, 33, 37, 41, 45, 48, 51,				//down

	48, 45, 43, 41, 40, 39, 38,						//up
	38, 39, 40, 41, 43, 45, 47, 49, 51,				//down

	50, 49, 49, 48, 48, 							//up
	49, 49, 49, 50, 51, 51, 						//down

	50, 49, 50, 51, 50, 51, 51, 50, 49, 50, 51, 50,	//up
	51, 50, 51, 50, 50, 51, 51, 51, 51, 51, 51, 51, 51, 51
	};