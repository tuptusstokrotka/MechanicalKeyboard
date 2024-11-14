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
#define MOD_R LSFT_T(KC_R)
#define MOD_S LGUI_T(KC_S)
#define MOD_T LALT_T(KC_T)

// Right-hand home row mods
#define MOD_N RALT_T(KC_N)
#define MOD_E RGUI_T(KC_E)
#define MOD_I RSFT_T(KC_I)
#define MOD_O RCTL_T(KC_O)

#define L_SPACE LT(1,KC_V)
#define R_SPACE LT(2,KC_K)

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