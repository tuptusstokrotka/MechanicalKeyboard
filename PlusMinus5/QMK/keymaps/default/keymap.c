// PlusMinus5 based on Eleksmaker TF05
#include QMK_KEYBOARD_H
#include "variables.h"

#ifdef ENCODER_ENABLE
	#include "encoder.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* MEDIA LAYER */
  [_MEDIA] = LAYOUT_macro_pad(
  KC_MPRV,    KC_MNXT,    KC_MPLY,
  KC_PAUSE,   __x__,      LT(_SELECT, CUSTOM_0)),

  /* FLUX LAYER */
  [_FLUX] = LAYOUT_macro_pad(
  FLUX_T_DN,  FLUX_T_UP,  KC_MPLY,
  FLUX_B_DN,  FLUX_B_UP,  LT(_SELECT, CUSTOM_1)),

  /* NAVIGATION */
  [_NAVI] = LAYOUT_macro_pad(
  KC_HOME,    KC_PGUP,    KC_MPLY,
  KC_END,     KC_PGDN,    LT(_SELECT, __x__)),

  /* BLANK */
  [_FOUR] = LAYOUT_macro_pad(
  __x__,      __x__,      KC_MPLY,
  __x__,      __x__,      LT(_SELECT, __x__)),

  /* TOGGLE LAYERS */
  [_SELECT] = LAYOUT_macro_pad(
  DF(_MEDIA), DF(_FLUX),   __x__,
  DF(_NAVI),  DF(_FOUR),  KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed){ // Key was pressed
    switch(keycode){
      case CUSTOM_0:{
        register_code(KC_LGUI);
        tap_code(KC_L);
        unregister_code(KC_LGUI);
        return true;  // Prevent KC_F13 from being sent
      }
      case CUSTOM_1:{
        register_code(KC_LALT);
        tap_code(KC_END);
        unregister_code(KC_LALT);
        return false;  // Prevent KC_F14 from being sent
      }
    }
  }
  return true;
}