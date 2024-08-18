// PlusMinus44 based on mochi40
#include QMK_KEYBOARD_H
#include "variables.h"

static void render_vol (void);
static void render_caps(void);


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	oled_clear();								// Clear screen on bootup
    return OLED_ROTATION_180;  					// Flips the display 180 degrees
}

bool oled_task_user(void) {
	// WPM == 0 AND time passed -> sleep / turn off screen
	if (timer_elapsed32(sleep_timer) > OLED_SLEEP) {
		oled_off();
		return 0;
	}

	// Frame update time passed -> draw new frame
	if (timer_elapsed32(frame_timer) > FRAME_DURATION) {
		frame_timer = timer_read32();			// Get Last frame millis

		// Prepare OLED to render
		oled_clear();							// Turn on OLED and clear
		oled_on();

		oled_set_cursor(9, 0);
		switch(high_layer){
			default:
			case 0:
				// Render WPM
				oled_write(get_u8_str(get_current_wpm(), '0'), false);
				break;
			case 1:
				// Render volume control
				render_vol();
				break;
			case 2:
				// Render capslock indicator
				render_caps();
				break;
		}
		//oled_write(get_u8_str(get_highest_layer(layer_state), '0'), false);
	}
    return 0;
}

static void render_vol(void) {
	if(timer_elapsed32(volume_timer) > VOL_SLEEP){
		high_layer=0;
		return;
	}
	switch(volume_key)	{
		case 1:
			oled_write_ln_P(PSTR("VOL-"), false);
			break;
		case 2:
			oled_write_ln_P(PSTR("VOL+"), false);
			break;
	}
}

static void render_caps(void) {
	if(timer_elapsed32(caps_timer) > CAPS_SLEEP){
		high_layer=0;
		return;
	}
	if(caps_state)
    	oled_write_P(PSTR("ABC"), false);
	else
		oled_write_P(PSTR("abc"), false);
}