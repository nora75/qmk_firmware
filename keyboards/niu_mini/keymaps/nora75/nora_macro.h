/*
NORA75:
This file declare custom macro.
*/

#ifndef _NORA_FUNCTION_H_
#define _NORA_FUNCTION_H_

/* custom keycodes declation */
enum custom_keycodes {
    MY_2 = SAFE_RANGE,
    MY_6,
    MY_7,
    MY_8,
    MY_9,
    MY_0,
    MY_LBRC,
    MY_RBRC,
    MY_QUOT,
    MY_SCLN,
    MY_BSLS,
    MY_TILD,
    MY_GRV,
    MY_MINUS,
    MY_EQL
};
    /* DYNAMIC_MACRO_RANGE = SAFE_RANGE */
    /* MY_DEFAULT */
    /* M_BSDEL = SAFE_RANGE, */
    /* MY_MON = SAFE_RANGE */


bool process_record_user(uint16_t keycode, keyrecord_t *record);

#endif
