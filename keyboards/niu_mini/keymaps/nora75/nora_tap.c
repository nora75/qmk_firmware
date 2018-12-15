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

#include "nora_tap.h"
#include "process_tap_dance.h"

/* void dance_my_lbrc_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   if (state->count == 1) { */
/*     register_code(KC_LSFT); */
/*     register_code(KC_9); */
/*   } else if (state->count == 2) { */
/*     register_code(KC_LBRC); */
/*   } else { */
/*     register_code(KC_LSFT); */
/*     register_code(KC_LBRC); */
/*   } */
/* } */

/* void dance_my_lbrc_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   if (state->count == 1) { */
/*     unregister_code(KC_LSFT); */
/*     unregister_code(KC_9); */
/*   } else if (state->count == 2) { */
/*     unregister_code(KC_LBRC); */
/*   } else { */
/*     unregister_code(KC_LSFT); */
/*     unregister_code(KC_LBRC); */
/*   } */
/* } */

/* void dance_my_rbrc_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   if (state->count == 1) { */
/*     register_code(KC_LSFT); */
/*     register_code(KC_0); */
/*   } else if (state->count == 2) { */
/*     register_code(KC_RBRC); */
/*   } else { */
/*     register_code(KC_LSFT); */
/*     register_code(KC_RBRC); */
/*   } */
/* } */

/* void dance_my_rbrc_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   if (state->count == 1) { */
/*     unregister_code(KC_LSFT); */
/*     unregister_code(KC_0); */
/*   } else if (state->count == 2) { */
/*     unregister_code(KC_RBRC); */
/*   } else { */
/*     unregister_code(KC_LSFT); */
/*     unregister_code(KC_RBRC); */
/*   } */
/* } */

void my_dance_td_lock(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        layer_clear();
        layer_on(_LOCK);
    }
}

void my_dance_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

/* Tap Dance Definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,KC_LCBR),
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC,KC_RCBR),
    [TD_LOCK] = ACTION_TAP_DANCE_FN(dance_td_lock),
    [TD_RESET] = ACTION_TAP_DANCE_FN(dance_td_reset)
        /* [TD_DSTART] = ACTION_TAP_DANCE_DOUBLE(DYN_REC_START1,DYN_REC_START2), */
        /* [TD_DPLAY]  = ACTION_TAP_DANCE_DOUBLE(DYN_MACRO_PLAY1,DYN_MACRO_PLAY2), */
        /* [TD_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_my_lbrc_finished, dance_my_lbrc_reset), */
        /* [TD_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_my_rbrc_finished, dance_my_rbrc_reset), */
 };
