#include QMK_KEYBOARD_H
#include "variables.h"
#include "combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BASE
    * ,---------------------------------------------------------------------.
    * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
    * |------+------+------+------+------+------+------+------+------+------|
    * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
    * |------+------+------+------+------+------+------+------+------+------|
    * |   Z  |   X  |   C  |   V  | B/_L | N/_R |   M  |   ,  |   .  |   /  |
    * `--------------------+------+------+------+------+--------------------'
    */
    [_BASE] = LAYOUT_basic(
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        MOD_A,    MOD_S,    MOD_D,    MOD_F,    KC_G,     KC_H,     MOD_J,    MOD_K,    MOD_L,    MOD_SCLN,
        KC_Z,     KC_X,     KC_C,     KC_V,     L_SPACE,  R_SPACE,  KC_M,     KC_COMM,  KC_DOT,   KC_SLSH
    ),
    /* _LEFT
    * ,---------------------------------------------------------------------.
    * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
    * |------+------+------+------+------+------+------+------+------+------|
    * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |
    * |------+------+------+------+------+------+------+------+------+------|
    * |   +  |   -  |   *  |   /  |      |   _R |   [  |   ]  |   {  |   }  |
    * `--------------------+------+------+------+------+--------------------'
    */
    [_LEFT] = LAYOUT_basic(
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,    KC_6,    KC_7,     KC_8,     KC_9,     KC_0,
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
        KC_PPLS,  KC_MINS,  KC_PAST,  KC_SLSH,  KC_TRNS, KC_TRNS, KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR
    ),
    /* _RIGHT
    * ,---------------------------------------------------------------------.
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |
    * |------+------+------+------+------+------+------+------+------+------|
    * | HOME |  END | PGUP | PGDN |      |      | LEFT | DOWN |  UP  | DOWN |
    * |------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |   _L |      | PREV | VOL_U| VOL_D| NEXT |
    * `--------------------+------+------+------+------+--------------------'
    */
    [_RIGHT] = LAYOUT_basic(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_NO,   KC_NO,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS, KC_TRNS, KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT
    ),
    /* _BOTH
    * ,---------------------------------------------------------------------.
    * |      |      |      | DSKL | MONL | MONR | DSKR |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------|
    * |  M0  |  M1  |      | SNPL | SNPD | SNPU | SNPR |      |  M2  |  M3  |
    * |------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |
    * `--------------------+------+------+------+------+--------------------'
    */
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