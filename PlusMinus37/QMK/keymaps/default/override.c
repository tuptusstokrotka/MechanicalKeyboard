// PlusMinus37
#include QMK_KEYBOARD_H

// override the functionality
//RIGHT ALT + BACKSPACE = DELETE
const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_ALT, L_BSCP, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&backspace_key_override,
	NULL // Null terminate the array of overrides!
};