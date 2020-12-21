/*
NORA75:
This file declare custom function.

*/

#include "nora_autoshift.h"

uint16_t my_autoshift_time = 0;
uint16_t my_autoshift_timeout = AUTO_SHIFT_TIMEOUT;
uint16_t my_autoshift_lastkey = KC_NO;

void my_autoshift_on(uint16_t keycode) {
    my_autoshift_time = timer_read();
    my_autoshift_lastkey = keycode;
}

void my_autoshift_flush(void) {
    if (my_autoshift_lastkey != KC_NO) {
        uint16_t elapsed = timer_elapsed(my_autoshift_time);

        if (elapsed > my_autoshift_timeout) {
            switch(keycode) {
                case MY_2:
                    my_autoshift_lastkey = KC_LBRC;
                    break;
                case MY_6:
                    my_autoshift_lastkey = KC_EQL;
                    break;
                case MY_7:
                    register_code(KC_LSFT);
                    my_autoshift_lastkey = KC_6;
                    break;
                case MY_8:
                    register_code(KC_LSFT);
                    my_autoshift_lastkey = KC_QUOT;
                    break;
                case MY_9:
                    register_code(KC_LSFT);
                    my_autoshift_lastkey = KC_8;
                    break;
                case MY_0:
                    register_code(KC_LSFT);
                    my_autoshift_lastkey = KC_9;
                    break;
                /* case MY_LBRC: */
                /*     my_autoshift_lastkey = KC_RBRC; */
                /*     break; */
                /* case MY_RBRC: */
                /*     my_autoshift_lastkey = KC_BSLS; */
                /*     break; */
                /* case MY_QUOT: */
                /*     register_code(KC_LSFT); */
                /*     my_autoshift_lastkey = KC_2; */
                /*     break; */
                /* case MY_SCLN: */
                /*     my_autoshift_lastkey = KC_QUOTE; */
                /*     break; */
                /* case MY_BSLS: */
                /*     register_code(KC_LSFT); */
                /*     my_autoshift_lastkey = JP_YEN; */
                /*     break; */
                /* case MY_TILD: */
                /*     register_code(KC_LSFT); */
                /*     my_autoshift_lastkey = KC_EQL; */
                /*     break; */
                /* case MY_GRV: */
                /*     register_code(KC_LSFT); */
                /*     my_autoshift_lastkey = KC_EQL; */
                /*     break; */
                /* case MY_MINUS: */
                /*     register_code(KC_LSFT); */
                /*     my_autoshift_lastkey = JP_BSLS; */
                /*     break; */
                /* case MY_EQL: */
                /*     register_code(KC_LSFT); */
                /*     my_autoshift_lastkey = KC_SCLN; */
                /*     break; */

            }
        }

        register_code(my_autoshift_lastkey);
        unregister_code(my_autoshift_lastkey);
        unregister_code(KC_LSFT);

        my_autoshift_time = 0;
        my_autoshift_lastkey = KC_NO;
    }
}
