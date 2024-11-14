// PlusMinus34
#include QMK_KEYBOARD_H

// Escape
const uint16_t PROGMEM Escape[]    = {KC_Q,     KC_W,     COMBO_END};
// Caps Lock
const uint16_t PROGMEM CapsLock[]  = {KC_Z,     KC_X,     COMBO_END};
// Git Bash
const uint16_t PROGMEM GitCopy[]   = {CTL_A,    KC_C,     COMBO_END};
const uint16_t PROGMEM GitPaste[]  = {CTL_A,    KC_V,     COMBO_END};
// Music
const uint16_t PROGMEM PlayPause[] = {KC_VOLD,  KC_VOLU,  COMBO_END};
// QWERTY
const uint16_t PROGMEM Tab1[]      = {CTL_A,    SFT_S,    COMBO_END};
const uint16_t PROGMEM Tab2[]      = {GUI_D,    ALT_F,    COMBO_END};
// COLEMAK
const uint16_t PROGMEM Tab1_C[]    = {CTL_A,    SFT_R,    COMBO_END};
const uint16_t PROGMEM Tab2_C[]    = {GUI_S,    ALT__T,   COMBO_END};

combo_t key_combos[] = {
   COMBO(Escape,     KC_ESC),

   COMBO(CapsLock,   KC_CAPS),

   COMBO(GitCopy,    LCTL(KC_INS)),
   COMBO(GitPaste,   LSFT(KC_INS)),

   COMBO(PlayPause,  KC_MPLY),

   COMBO(Tab1,       KC_TAB),
   COMBO(Tab2,       KC_TAB),

   COMBO(Tab1_C,     KC_TAB),
   COMBO(Tab2_C,     KC_TAB),
};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */