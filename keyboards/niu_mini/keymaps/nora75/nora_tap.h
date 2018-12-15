/*
NORA75:
This file declare function of tap dance keys.

Tapping term Functions
TD_LBRC    : Single [  Double {
TD_RBRC    : Single ]  Double }
TD_RBRC    : Single ]  Double }
TD_RESET   : Single NO Double RESET
TD_LOCK    : Single NO Double TG(LOCK)
*/

#ifndef _NORA_TAP_H_
#define _NORA_TAP_H_

#include "process_tap_dance.h"

/* Tap Dance Keys Declarations */
enum {
    TD_LBRC,
    TD_RBRC,
    TD_DSTART,
    TD_DPLAY,
    TD_LOCK,
    TD_RESET
};

void dance_td_lock(qk_tap_dance_state_t *state, void *user_data);
void dance_td_reset(qk_tap_dance_state_t *state, void *user_data);

/* Tap Dance Definitions */
qk_tap_dance_action_t tap_dance_actions[] = {};

#endif
