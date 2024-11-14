// PlusMinus30
#include QMK_KEYBOARD_H

// _BASE layer Combos
const uint16_t PROGMEM Escape[]     = {KC_Q,     KC_W,    COMBO_END};
const uint16_t PROGMEM Tab1[]       = {MOD_A,    MOD_R,   COMBO_END};
const uint16_t PROGMEM Tab2[]       = {MOD_S,    MOD_T,   COMBO_END};
const uint16_t PROGMEM CapsLock[]   = {KC_Z,     KC_X,    COMBO_END};

const uint16_t PROGMEM Backspace[]  = {KC_Y,     KC_SCLN, COMBO_END};
const uint16_t PROGMEM Enterros[]   = {MOD_I,    MOD_O,   COMBO_END};
const uint16_t PROGMEM Delete[]     = {KC_F9,    KC_F10,  COMBO_END};
const uint16_t PROGMEM Spacer[]     = {L_SPACE,  R_SPACE, COMBO_END};

combo_t key_combos[] = {
   COMBO(Escape,     KC_ESC),
   COMBO(Tab1,       KC_TAB),
   COMBO(Tab2,       KC_TAB),
   COMBO(CapsLock,   KC_CAPS),
   COMBO(Backspace,  KC_BSPC),
   COMBO(Enterros,   KC_ENT),
   COMBO(Delete,     KC_DEL),
   COMBO(Spacer,     KC_SPC),

};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */