#include QMK_KEYBOARD_H

#ifdef KEY_OVERRIDE_ENABLE
	#include "override.c"
#endif
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

// _BASE layer Combos
const uint16_t PROGMEM Escape[]    = {KC_Q,     KC_W,    COMBO_END};
const uint16_t PROGMEM Tabulator[] = {MOD_A,    MOD_R,   COMBO_END};
const uint16_t PROGMEM CapsLock[]  = {KC_Z,     KC_X,    COMBO_END};
const uint16_t PROGMEM Backspace[] = {KC_Y,     KC_SCLN, COMBO_END};
const uint16_t PROGMEM Enterros[]  = {MOD_I,    MOD_O,   COMBO_END};
const uint16_t PROGMEM Delete[]    = {KC_F9,    KC_F10,  COMBO_END};
const uint16_t PROGMEM Spacer[]    = {L_SPACE,  R_SPACE, COMBO_END};



combo_t key_combos[] = {
   COMBO(Escape,    KC_ESC),
   COMBO(Tabulator, KC_TAB),
   COMBO(CapsLock,  KC_CAPS),
   COMBO(Backspace, KC_BSPC),
   COMBO(Enterros,  KC_ENT),
   COMBO(Delete,    KC_DEL),
   COMBO(Spacer,    KC_SPC),

};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_basic(
        KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
        MOD_A,    MOD_R,    MOD_S,    MOD_T,    KC_G,     KC_M,     MOD_N,    MOD_E,    MOD_I,    MOD_O,
        KC_Z,     KC_X,     KC_C,     KC_D,     L_SPACE,  R_SPACE,  KC_H,     KC_COMM,  KC_DOT,   KC_SLSH
    ),
    [_LEFT] = LAYOUT_basic(
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,    KC_6,    KC_7,     KC_8,     KC_9,     KC_0,
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
        KC_PPLS,  KC_MINS,  KC_PAST,  KC_SLSH,  KC_TRNS, KC_TRNS, KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR
    ),
    [_RIGHT] = LAYOUT_basic(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_NO,   KC_NO,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS, KC_TRNS, KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT
    ),
    [_BOTH] = LAYOUT_basic(
        KC_NO,    KC_NO,    KC_NO,    L_DESKTOP,  L_MONITOR,  R_MONITOR,  R_DESKTOP,   KC_NO,     KC_NO,      KC_NO,
        M0,       M1,       KC_NO,    L_SNAP,     D_SNAP,     U_SNAP,     R_SNAP,      KC_NO,     M2,         M3,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,     KC_NO,      KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state){
	return update_tri_layer_state(state, _LEFT, _RIGHT, _BOTH);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed){               // Key was pressed
    switch(keycode){
      case M0:
        register_code(KC_LCTL);
        tap_code(KC_K);
        tap_code(KC_J);
        unregister_code(KC_LCTL);
        break;
      case M1:
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_RBRC);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        break;
      case M2:
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_LBRC);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        break;
      case M3:
        register_code(KC_LCTL);
        tap_code(KC_K);
        tap_code(KC_0);
        unregister_code(KC_LCTL);
        break;
    }
  }
  return true;
}