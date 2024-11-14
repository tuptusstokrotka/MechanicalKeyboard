// PlusMinus37
#include QMK_KEYBOARD_H
#include "37.h"
#include "variables.h"

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
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |  ESC |   Q  |   W  |   E  |   R  |   T  |                   |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------+
   * |  TAB |   A  |   S  |   D  |   F  |   G  |                   |   H  |   J  |   K  |   L  |   ;  |  ENT |
   * `------+------+------+------+------+------|                   |------+------+------+------+------+------'
   *        |   Z  |   X  |   C  |   V  |   B  |                   |   N  |   M  |   ,  |   .  |   /  |
   *        `--------------------+------+------| ,----.     ,------+------+------+------+------+------'
   *                                    | BSCP ||PLAY |     |SPC/_R| ENT/A|
   *                                    `------'`----'      `-------------'
   */
  [_QWERTY] = LAYOUT_split(
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSLS,
  KC_TAB,   CTL_A,   SFT_S,   GUI_D,   ALT_F,   KC_G,        KC_H,    ALT_J,   GUI_K,    SFT_L,   CTL_SCLN, KC_ENT,
            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
                                       L_BSCP,  KC_MPLY,     R_SPACE, R_ENT
  ),
  /* _COLEMAK
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |  ESC |   Q  |   W  |   F  |   P  |   B  |                   |   J  |   L  |   U  |   Y  |   ;  |   \  |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------+
   * |  TAB |   A  |   R  |   S  |   T  |   G  |                   |   M  |   N  |   E  |   I  |   O  |  ENT |
   * `------+------+------+------+------+------|                   |------+------+------+------+------+------'
   *        |   Z  |   X  |   C  |   D  |   V  |                   |   K  |   H  |   ,  |   .  |   /  |
   *        `--------------------+------+------| ,----.     ,------+------+------+------+------+------'
   *                                    | BSCP ||PLAY |     |SPC/_R| ENT/A|
   *                                    `------'`----'      `-------------'
   */
  [_COLEMAK] = LAYOUT_split(
  KC_ESC,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,     KC_Y,    KC_SCLN,  KC_BSLS,
  KC_TAB,   CTL_A,   SFT_R,   GUI_S,   ALT__T,  KC_G,        KC_M,    ALT_N,   GUI_E,    SFT_I,   CTL_O,    KC_ENT,
            KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,
                                       L_BSCP,  KC_MPLY,     R_SPACE, R_ENT
  ),
  // JUST FOR PRACTICE UNTIL I GET USED TO //
  [_COLEMAK_NOMODS] = LAYOUT_split(
  KC_ESC,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,     KC_Y,    KC_SCLN,  KC_BSLS,
  KC_TAB,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,     KC_I,    KC_O,     KC_ENT,
            KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,
                                       L_BSCP,  KC_MPLY,     R_SPACE, R_ENT
  ),
  /* _LEFT
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |  ESC |   1  |   2  |   3  |   4  |   5  |                   |   Y  |   U  |   I  |   O  |   P  |   '  |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------+
   * |  TAB |   !  |   @  |   #  |   $  |   %  |                   |   ^  |   &  |   *  |   (  |   )  |   _  |
   * `------+------+------+------+------+------|                   |------+------+------+------+------+------'
   *        |   +  |   -  |   *  |   /  |   =  |                   |      |   [  |   ]  |   {  |   }  |
   *        `--------------------+------+------| ,----.     ,------+------+------+------+------+------'
   *                                    |      ||PREV |     |SPC/_R| ENT/A|
   *                                    `------'`----'      `-------------'
   */
  [_LEFT] = LAYOUT_split(
  KC_NO,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_QUOT,
  KC_CALC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN,  LSFT(KC_MINS),
            KC_PPLS, KC_MINS, KC_PAST, KC_SLSH, KC_EQL,      KC_NO,   KC_LBRC, KC_RBRC,  KC_LCBR, KC_RCBR,
                                       KC_TRNS, KC_MPRV,     KC_TRNS, KC_TRNS
  ),

  /* _RIGHT
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                   |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------+
   * |      | HOME |  END | PGUP | PGDN |      |                   |      | LEFT | DOWN |  UP  | DOWN |  F12 |
   * `------+------+------+------+------+------|                   |------+------+------+------+------+------'
   *        |      |      |      |      |      |                   |      |      |      |      |      |
   *        `--------------------+------+------| ,----.     ,------+------+------+------+------+------'
   *                                    |      ||NEXT |     |SPC/_R| ENT/A|
   *                                    `------'`----'      `-------------'
   */
  [_RIGHT] = LAYOUT_split(
  KC_NO,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,
  KC_NO,    KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_NO,       KC_NO,   KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT,  KC_F12,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
                                       KC_TRNS, KC_MNXT,     KC_TRNS, KC_TRNS
  ),

  /* _BOTH
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |      |      |      |      | DSKL | MONL |                   | DSKL | MONL |      |      |      |      |  DKSL/DKSR - Desktop Left/Right;
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------+  MONL/MONR - Monitor Left/Right;
   * |      |  M0  |  M1  |      | SNPL | SNPD |                   | SNPU | SNPR |      |  M2  |  M3  |      |  SNPL/SNPD/SNPU/SNPR/ - Snap window Left/Down/Up/Right;
   * `------+------+------+------+------+------|                   |------+------+------+------+------+------'
   *        |      |      |      |      |      |                   |      |      |      |      |      |
   *        `--------------------+------+------| ,----.     ,------+------+------+------+------+------'
   *                                    |      ||     |     |SPC/_R| ENT/A|
   *                                    `------'`----'      `-------------'
   */
  [_BOTH] = LAYOUT_split(
  KC_NO,    QWER,    COLM,    CO_NM,   L_DESKTOP,L_MONITOR,   R_MONITOR,  R_DESKTOP,   KC_NO,    KC_NO,   KC_NO,    KC_NO,
  KC_NO,    M0,      M1,      KC_NO,   L_SNAP,   D_SNAP,      U_SNAP,     R_SNAP,      KC_NO,    M2,      M3,       KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,       KC_NO,      KC_NO,       KC_NO,    KC_NO,   KC_NO,
                                       KC_TRNS,  KC_NO,       KC_TRNS,    KC_TRNS
  ),
};

layer_state_t layer_state_set_user(layer_state_t state){
	return update_tri_layer_state(state, _LEFT, _RIGHT, _BOTH);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed){               // Key was pressed
    switch(keycode){
      case M0:{
        register_code(KC_LCTL);
        tap_code(KC_K);
        tap_code(KC_J);
        unregister_code(KC_LCTL);
        break;
      }
      case M1:{
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_RBRC);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        break;
      }
      case M2:{
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_LBRC);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        break;
      }
      case M3:{
        register_code(KC_LCTL);
        tap_code(KC_K);
        tap_code(KC_0);
        unregister_code(KC_LCTL);
        break;
      }
    }
  }
  return true;
}