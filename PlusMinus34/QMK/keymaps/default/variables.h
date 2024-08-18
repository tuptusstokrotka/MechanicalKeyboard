// PlusMinus44 based on mochi40
#pragma once
// _BASE home row mods
#define CTL_A LCTL_T(KC_A)
#define SFT_S LSFT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define ALT_F LALT_T(KC_F)

#define ALT_J LALT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define SFT_L RSFT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

// _LEFT home row mods
#define _EXLM  LCTL_T(KC_EXLM)
#define _AT    LSFT_T(KC_AT)
#define _HASH  LGUI_T(KC_HASH)
#define _DLR   LALT_T(KC_DLR)

#define _AMPR  LALT_T(KC_AMPR)
#define _ASTR  RGUI_T(KC_ASTR)
#define _LPRN  RSFT_T(KC_LPRN)
#define _RPRN  RCTL_T(KC_RPRN)

// _RIGHT home row mods
#define _HOME LCTL_T(KC_HOME)
#define _END  LSFT_T(KC_END)
#define _PGUP LGUI_T(KC_PGUP)
#define _PGDN LALT_T(KC_PGDN)

#define _ARR_L LALT_T(KC_LEFT)
#define _ARR_D RGUI_T(KC_DOWN)
#define _ARR_U RSFT_T(KC_UP)
#define _ARR_R RCTL_T(KC_RGHT)


#define L_SPACE LT(1,KC_ENT)
#define R_SPACE LT(2,KC_SPC)

#define L_MONITOR SGUI(KC_LEFT)				// Previous Monitor
#define L_DESKTOP LGUI(LCTL(KC_LEFT))	// Previous Desktop
#define R_DESKTOP LGUI(LCTL(KC_RGHT))	// Next Desktop
#define R_MONITOR SGUI(KC_RGHT)				// Next Monitor

#define L_SNAP LGUI(KC_LEFT)				// Snap Window Left
#define D_SNAP LGUI(KC_DOWN)				// Snap Window Down
#define U_SNAP LGUI(KC_UP)					// Snap Window Up
#define R_SNAP LGUI(KC_RGHT)				// Snap Window Right

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LEFT,
    _RIGHT,
    _BOTH
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
	M0 = SAFE_RANGE,
  M1,
  M2,
  M3,
};