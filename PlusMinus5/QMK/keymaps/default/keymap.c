// PlusMinus5 based on Eleksmaker TF05
#include QMK_KEYBOARD_H
#include "variables.h"

#ifdef ENCODER_ENABLE
	#include "encoder.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* _ONE
   * ,--------------------.
   * |   A  |   B  |   C  |
   * |------+------+------|
   * |   D  |   E  |   F  |
   * `--------------------'
   */

  /* MEDIA LAYER */
  [_ONE] = LAYOUT_macro_pad(
  KC_Q,       KC_W,       KC_E,
  KC_R,       KC_T,       LT(_SELECT, KC_1)),

  /* FLUX LAYER */
  [_TWO] = LAYOUT_macro_pad(
  KC_A,       KC_S,       KC_D,
  KC_F,       KC_G,       LT(_SELECT, KC_2)),

  [_THREE] = LAYOUT_macro_pad(
  KC_Z,       KC_X,       KC_C,
  KC_V,       KC_B,       LT(_SELECT, KC_3)),

  [_FOUR] = LAYOUT_macro_pad(
  KC_1,       KC_2,       KC_3,
  KC_4,       KC_5,       LT(_SELECT, KC_4)),

  /* _SELECT
   * ,--------------------.
   * |  L1  |  L2  |      |
   * |------+------+------|
   * |  L3  |  L4  |      |
   * `--------------------'
   */
  [_SELECT] = LAYOUT_macro_pad(
  DF(_ONE),   DF(_TWO),   KC_C,
  DF(_THREE), DF(_FOUR),  KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if (record->event.pressed){               // Key was pressed
  // }
  return true;
}