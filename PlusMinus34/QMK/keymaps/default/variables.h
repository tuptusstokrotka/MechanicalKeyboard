// PlusMinus34
#include QMK_KEYBOARD_H
#pragma once

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _COLEMAK,
    _LEFT,
    _RIGHT,
    _BOTH
};

//DEFAULT LAYER
#define COLM  DF(_QWERTY)
#define QWER  DF(_COLEMAK)

// _BASE home row mods
#define CTL_A LCTL_T(KC_A)
#define SFT_S LSFT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define ALT_F LALT_T(KC_F)

#define ALT_J LALT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define SFT_L RSFT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

// Colemak-DH home row
#define SFT_R LSFT_T(KC_R)
#define GUI_S LGUI_T(KC_S)
#define ALT__T LALT_T(KC_T)

#define ALT_N LALT_T(KC_N)
#define GUI_E RGUI_T(KC_E)
#define SFT_I RSFT_T(KC_I)
#define CTL_O RCTL_T(KC_O)

// LAYER CHANGE
#define L_SPACE LT(_LEFT,KC_SPC)
// #define R_SPACE LT(2,KC_ENT)
#define R_SPACE LT(_RIGHT,KC_SPC)
#define R_ENT   RALT_T(KC_ENT)

#define L_MONITOR SGUI(KC_LEFT)       // Previous Monitor
#define L_DESKTOP LGUI(LCTL(KC_LEFT)) // Previous Desktop
#define R_DESKTOP LGUI(LCTL(KC_RGHT)) // Next Desktop
#define R_MONITOR SGUI(KC_RGHT)       // Next Monitor

#define L_SNAP LGUI(KC_LEFT)				  // Snap Window Left
#define D_SNAP LGUI(KC_DOWN)				  // Snap Window Down
#define U_SNAP LGUI(KC_UP)            // Snap Window Up
#define R_SNAP LGUI(KC_RGHT)				  // Snap Window Right

#define FLUX_EN LALT(KC_END)				  // Flux Disable / Enable
#define FLUX_T_DN LSA(KC_PGDN)				// Flux Screen Temperature Warm
#define FLUX_T_UP LSA(KC_PGUP)				// Flux Screen Temperature Cold
#define FLUX_B_DN LALT(KC_PGDN)				// Flux Brightness-
#define FLUX_B_UP LALT(KC_PGUP)				// Flux Brightness+

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  M0 = SAFE_RANGE,
  M1,
  M2,
  M3,
};