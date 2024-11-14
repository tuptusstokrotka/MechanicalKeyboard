// PlusMinus30
#include QMK_KEYBOARD_H
#pragma once

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LEFT,
    _RIGHT,
    _BOTH
};

// Left-hand home row mods
#define MOD_A LCTL_T(KC_A)
#define MOD_S LSFT_T(KC_S)
#define MOD_D LGUI_T(KC_D)
#define MOD_F LALT_T(KC_F)

// Right-hand home row mods
#define MOD_J RALT_T(KC_J)
#define MOD_K RGUI_T(KC_K)
#define MOD_L RSFT_T(KC_L)
#define MOD_SCLN RCTL_T(KC_SCLN)

#define L_SPACE LT(1,KC_B)
#define R_SPACE LT(2,KC_N)

#define L_MONITOR SGUI(KC_LEFT)				// Previous Monitor
#define L_DESKTOP LGUI(LCTL(KC_LEFT))		// Previous Desktop
#define R_DESKTOP LGUI(LCTL(KC_RGHT))		// Next Desktop
#define R_MONITOR SGUI(KC_RGHT)				// Next Monitor

#define L_SNAP LGUI(KC_LEFT)				// Snap Window Left
#define D_SNAP LGUI(KC_DOWN)				// Snap Window Down
#define U_SNAP LGUI(KC_UP)					// Snap Window Up
#define R_SNAP LGUI(KC_RGHT)				// Snap Window Right

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
	M0 = SAFE_RANGE,
	M1,
	M2,
	M3,
};