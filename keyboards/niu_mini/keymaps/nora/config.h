/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

/* my configs */
/* tap dance */
#define TAPPING_TERM 180 /* Time to change mod from tap in MOD-Tap key? */
/* One Shot */
#define ONESHOT_TIMEOUT 7500  /* Time (in ms) before the one shot key is released */
/* Auto Shift */
#define AUTO_SHIFT_TIMEOUT 180
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

/* vim: set nonu: */ 
