// Copyright 2022 Julian Tarczynski
// PlusMinus40 based on mochi40
#include QMK_KEYBOARD_H
#include "variables.h"

static void render_ball(void);
static void render_doge(void);
static void render_vol (void);
static void render_caps(void);

#define INITIAL_HEIGHT 10.0 // Starting height, in abstract units
#define LOSS_FACTOR 0.6 // Factor of height loss on each bounce
#define BOUNCE_COUNT 3 // Number of bounces
#define TOTAL_FRAMES 55 // Total number of frames in the animation
#define GRAVITY 9.81 // Gravity, not directly used due to scaling

// Function to simulate and return the height of the ball at a given frame (x)
uint8_t getHeight(int x) {
    // Simplify the time to a scale of 0 to 3 representing the number of bounces
    double time = x * BOUNCE_COUNT / TOTAL_FRAMES;

    double totalTime = 0.0; // Total time simulated
    double height = INITIAL_HEIGHT;
    double velocity = 2 * INITIAL_HEIGHT; // Simplified, not using real gravity

    for (int i = 0; i < TOTAL_FRAMES; ++i) {
        double timeToFall = velocity; // Simplified
        if (time < totalTime + timeToFall) {
            double t = time - totalTime; // Time since start of this fall
            // Simplified calculation of height during fall
            double currentHeight = INITIAL_HEIGHT - 0.5 * t * t;
            // Map this height to the screen coordinate, inverting since 0 is max height
            return 51 - (currentHeight / INITIAL_HEIGHT * 51);
			//TODO do somethign later
        }
        totalTime += timeToFall;
        height *= LOSS_FACTOR;
        velocity = 2 * height; // Update for next bounce, simplified
    }
    // If time is beyond the simulation, assume the ball is on the ground
    return 51; // Ground position
}

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

		// Draw each element on the screen
		render_doge();
		render_ball();

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

// Rendering specific elements
static void render_doge(void) {
	doge_frame++;
	uint8_t tail_frame = (doge_frame%2 ? 1 : doge_frame%4);

	oled_set_cursor(0, 5);
    oled_write_raw_P(doge_head, sizeof(doge_head));
	oled_set_cursor(0, 6);
    oled_write_raw_P(doge_body[tail_frame], sizeof(doge_body[tail_frame]));
	oled_set_cursor(0, 7);
    oled_write_raw_P(doge_legs, sizeof(doge_legs));
}

static void render_ball(void){
	if(!toy_action){							// let the ball lay down
		return;
	}
	if(ball_frame < TOTAL_FRAMES)				// animate until the end of ball frames
		ball_frame++;


	uint8_t x = (ball_frame % 80 + 25) * 1.05; 	// strech X axis to whole OLED
	//uint8_t y = getHeight(x);
	uint8_t y = ball_height[ball_frame % 80];

	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			oled_write_pixel(x+j, y+i, ball_anim[i][j]);
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

/*
OLD STUFF HERE


*/