/*
NORA75:
This file is my config.h file
This file written many options.
*/

#ifndef MY_CONFIG_H
#define MY_CONFIG_H

#include "../../config.h"

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
#define NO_DEBUG

/* disable print */
#define NO_PRINT

/* disable action features */
/* #define NO_ACTION_LAYER */
/* #define NO_ACTION_TAPPING */
/* #define NO_ACTION_ONESHOT */
/* #define NO_ACTION_MACRO */
/* #define NO_ACTION_FUNCTION */

/* tap dance */
#define TAPPING_TERM 200 /* Time to change mod from tap in MOD-Tap key? */
/* One Shot */
#define ONESHOT_TIMEOUT 7000  /* Time (in ms) before the one shot key is released */
/* Auto Shift */
#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_ALPHA /* It is not usefull when option is disabled */
/* #define NO_AUTO_SHIFT_SPECIAL */
/* LEADER KEY */
#define LEADER_TIMEOUT 300 /* Timeout timese of leader key */
/* mouse key options */
#define MOUSEKEY_DELAY             300
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         7
#define MOUSEKEY_TIME_TO_MAX       20
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#endif
