// PlusMinus44 based on mochi40
#include QMK_KEYBOARD_H

// Define Combos Events (max 32)
enum combo_events { 
        SHIFT_TAB,                      // SHIFT + TAB = CAPSLOCK
        COMBO_LENGTH
     };

uint16_t COMBO_LEN = COMBO_LENGTH;      // remove the COMBO_COUNT define and use this instead!

// Define Keys Trigger and Combo Name 
const uint16_t PROGMEM CapsLock[] = {KC_TAB, KC_LSFT, COMBO_END};

combo_t key_combos[] = {
    [SHIFT_TAB] = COMBO(CapsLock, KC_CAPS)
};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */