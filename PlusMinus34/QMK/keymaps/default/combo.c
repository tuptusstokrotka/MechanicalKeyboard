// PlusMinus44 based on mochi40
#include QMK_KEYBOARD_H

// _BASE layer Combos
const uint16_t PROGMEM Escape[]    = {KC_Q,     KC_W,     COMBO_END};
const uint16_t PROGMEM Tabulator[] = {CTL_A,    SFT_S,    COMBO_END};
const uint16_t PROGMEM CapsLock[]  = {KC_Z,     KC_X,     COMBO_END};
const uint16_t PROGMEM Equals[]    = {KC_9,     KC_0,     COMBO_END};


combo_t key_combos[] = {
   COMBO(Escape,    KC_ESC),
   COMBO(Tabulator, KC_TAB),
   COMBO(CapsLock,  KC_CAPS),
   COMBO(Equals,    KC_EQL),
};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */