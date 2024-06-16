// Copyright 2022 Julian Tarczynski
// PlusMinus40 based on mochi40
#include QMK_KEYBOARD_H
#include "variables.h"

#ifdef OLED_ENABLE
	#include "oled.c"
#endif
#ifdef ENCODER_ENABLE
	#include "encoder.c"
#endif
#ifdef COMBO_ENABLE
	#include "combo.c"
#endif
#ifdef KEY_OVERRIDE_ENABLE
	#include "override.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* _MAIN
   * ,-------------------------------------------------------------------------------------.
   * |  ESC |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  BSPC  |  RALT(hold) + BSCP = DEL
   * |------+------+------+------+------+------+------+------+------+------+------+--------|  TAB + L_SHIFT     = CAPSLOCK
   * |  TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | ENTER |   \ (hold)         = R_SHIFT
   * |-------+------+------+------+------+------+------+------+------+------+------+-------|  CTRL + V          = SHIFT + INS
   * |  SHIFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   \  |
   * |--------+------+------+------+------+------+------+------+------+------+------+------|    ,----.
   * |  CTRL |  GUI  |  ALT  |  SPACE / _LEFT |   SPACE / _RIGHT   |  RALT |  APP  |  CTRL |   |PLAY |
   * `-------------------------------------------------------------------------------------'   `----'
   */
[_MAIN] = LAYOUT_split_space( /* MAIN */
KC_ESC,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BACKSPACE,
KC_TAB,       KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
KC_LSFT,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSFT_T(KC_BSLS),
KC_LCTL,      KC_LGUI,    KC_LALT,                L_SPACE,                            R_SPACE,                KC_RALT,    KC_APP,     KC_RCTL,          KC_MPLY),

  /* _LEFT
   * ,-------------------------------------------------------------------------------------.
   * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |    =   |
   * |------+------+------+------+------+------+------+------+------+------+------+--------|
   * |       |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   '   |
   * |-------+------+------+------+------+------+------+------+------+------+------+-------|
   * |  SHIFT |   +  |   -  |   *  |   /  |      |      |   [  |   ]  |   {  |   }  |   _  |
   * |--------+------+------+------+------+------+------+------+------+------+------+------|    ,----.
   * |  CTRL |  GUI  |  ALT  |                |   SPACE / _RIGHT   |       |       |       |   |PREV |
   * `-------------------------------------------------------------------------------------'   `----'
   */
[_LEFT] = LAYOUT_split_space( /* LEFT */
KC_GRV,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
KC_NO,        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_QUOT,
KC_TRNS,      KC_PPLS,    KC_PMNS,    KC_PAST,    KC_PSLS,    KC_NO,      KC_NO,      KC_LBRC,    KC_RBRC,    KC_LCBR,    KC_RCBR,    LSFT(KC_MINS),
KC_TRNS,      KC_TRNS,    KC_TRNS,                KC_TRNS,                            KC_TRNS,                KC_NO,      KC_NO,      KC_NO,            KC_MPRV),

  /* _RIGHT
  * ,-------------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
   * |------+------+------+------+------+------+------+------+------+------+------+--------|
   * |       | HOME |  END | PGUP | PGDN |      |      | LEFT | DOWN |  UP  | DOWN |       |
   * |-------+------+------+------+------+------+------+------+------+------+------+-------|
   * |  SHIFT |      |      |      |      |      |      |      |      |      |      |      |
   * |--------+------+------+------+------+------+------+------+------+------+------+------|    ,----.
   * |  CTRL |  GUI  |  ALT  |  SPACE / _LEFT |                    |       |       |       |   |NEXT |
   * `-------------------------------------------------------------------------------------'   `----'
   */
[_RIGHT] = LAYOUT_split_space( /* RIGHT */
KC_F1,        KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
KC_NO,        KC_HOME,    KC_END,     KC_PGUP,    KC_PGDN,    KC_NO,      KC_NO,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,
KC_TRNS,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_MPRV,    KC_NO,      KC_NO,      KC_MNXT,    KC_NO,
KC_TRNS,      KC_TRNS,    KC_TRNS,                KC_TRNS,                            KC_TRNS,                KC_NO,      KC_NO,      KC_NO,            KC_MNXT),

  /* _BOTH
   * ,-------------------------------------------------------------------------------------.  FLUX EN   - F.lux Enable / Disable
   * |      |      |      |      | DSKL | MONL | MONR | DSKR |      |      |      | FLUX EN|  DKSL/DKSR - Desktop Left/Right;
   * |------+------+------+------+------+------+------+------+------+------+------+--------|  MONL/MONR - Monitor Left/Right;
   * |       |      |      |      | SNPL | SNPD | SNPU | SNPR |      |      |      |       |  SNPL/SNPD/SNPU/SNPR/ - Snap window Left/Down/Up/Right;
   * |-------+------+------+------+------+------+------+------+------+------+------+-------|
   * |        |      |      |      |      |      |      | PREV |      |      | NEXT |      |
   * |--------+------+------+------+------+------+------+------+------+------+------+------|    ,----.
   * |       |       |       |                |                    |       |       |       |   |ANIM |
   * `-------------------------------------------------------------------------------------'   `----'
   */
[_BOTH] = LAYOUT_split_space( /* BOTH */
KC_NO,        KC_NO,      KC_NO,      KC_NO,      L_DESKTOP,  L_MONITOR,  R_MONITOR,  R_DESKTOP,   KC_NO,     KC_NO,      KC_NO,      FLUX_EN,
M0,           M1,         KC_NO,      KC_NO,      L_SNAP,     D_SNAP,     U_SNAP,     R_SNAP,      KC_NO,     KC_NO,      M2,         M3,
KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,     KC_NO,      KC_NO,      KC_NO,
KC_TRNS,      KC_TRNS,    KC_TRNS,                KC_NO,                              KC_NO,                  KC_NO,      KC_NO,      KC_NO,           KC_F13),
};

// Enable _BOTH layer only when 2 buttons pressed
// On release update layer state
// Eliminate issue where layer does not updates after release
layer_state_t layer_state_set_user(layer_state_t state){
	return update_tri_layer_state(state, _LEFT, _RIGHT, _BOTH);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed){               // Key was pressed
    sleep_timer = timer_read32();

    switch(keycode){
      case KC_F13:                          // Assign toy animation to F13
        toy_action=!toy_action;
        ball_frame = 0;                     // Reset ball position
        break;
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

bool led_update_user(led_t led_state) {
  if (caps_state != led_state.caps_lock) {  // When capslock state changed
    high_layer = 2;
    caps_state = led_state.caps_lock;       // Update flag
    caps_timer = timer_read32();            // Get last change time in millis()
  }
  return true;
}