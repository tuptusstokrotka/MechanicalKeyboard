#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// #define TAP_CODE_DELAY 10
#define TAPPING_TERM 250
#define FORCE_NKRO

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 5

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_I2C
#define SPLIT_USB_DETECT

// #define MATRIX_ROW_PINS_LEFT  { D4, C6, D7, E6 }
// #define MATRIX_COL_PINS_LEFT  { F7, F6, F5, D3, D2, F4 }

// #define MATRIX_ROW_PINS_RIGHT { D4, C6, D7, E6 }
// #define MATRIX_COL_PINS_RIGHT { F6, F7, F5, F4, D3, D2 }

// #define SPLIT_MAX_CONNECTION_ERRORS 10
// #define SPLIT_CONNECTION_CHECK_TIMEOUT 500

#define ENCODERS_PAD_A       { B1 }
#define ENCODERS_PAD_B       { B3 }
#define ENCODER_RESOLUTION 4

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
