// PlusMinus37
#include QMK_KEYBOARD_H

// _BASE layer Combos
const uint16_t PROGMEM Escape[]    = {KC_Q,     KC_W,     COMBO_END};

// left hand alt tab / ctrl tab
const uint16_t PROGMEM Tab1[]      = {CTL_A,    SFT_S,    COMBO_END};
const uint16_t PROGMEM Tab2[]      = {GUI_D,    ALT_F,    COMBO_END};

const uint16_t PROGMEM Tab1_c[]    = {CTL_A,    SFT_R,    COMBO_END};
const uint16_t PROGMEM Tab2_c[]    = {GUI_S,    ALT__T,   COMBO_END};

//capslock
const uint16_t PROGMEM CapsLock[]  = {KC_Z,     KC_X,     COMBO_END};

//git bash
const uint16_t PROGMEM GitCopy[]   = {CTL_A,    KC_C,     COMBO_END};
const uint16_t PROGMEM GitPaste[]  = {CTL_A,    KC_V,     COMBO_END};


combo_t key_combos[] = {
   COMBO(Escape,     KC_ESC),

   COMBO(Tab1,       KC_TAB),
   COMBO(Tab2,       KC_TAB),
   COMBO(Tab1_c,     KC_TAB),
   COMBO(Tab2_c,     KC_TAB),

   COMBO(CapsLock,   KC_CAPS),

   COMBO(GitCopy,    LCTL(KC_INS)),
   COMBO(GitPaste,   LSFT(KC_INS))
};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */