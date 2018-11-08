/* Tapping term Functions */
/* TD_MY_LBRC : Single [ Double { */
/* TD_MY_RBRC : Single ] Double } */

void dance_my_lbrc_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LSFT);
    register_code(KC_9);
  } else if (state->count == 2) {
    register_code(KC_LBRC);
  } else {
    register_code(KC_LSFT);
    register_code(KC_LBRC);
  }
}

void dance_my_lbrc_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_LSFT);
    unregister_code(KC_9);
  } else if (state->count == 2) {
    unregister_code(KC_LBRC);
  } else {
    unregister_code(KC_LSFT);
    unregister_code(KC_LBRC);
  }
}

void dance_my_rbrc_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LSFT);
    register_code(KC_0);
  } else if (state->count == 2) {
    register_code(KC_RBRC);
  } else {
    register_code(KC_LSFT);
    register_code(KC_RBRC);
  }
}

void dance_my_rbrc_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_LSFT);
    unregister_code(KC_0);
  } else if (state->count == 2) {
    unregister_code(KC_RBRC);
  } else {
    unregister_code(KC_LSFT);
    unregister_code(KC_RBRC);
  }
}

/* Tap Dance Keys Declarations */
enum {
  /* TD_NO_RES = 0, */
  TD_MY_LBRC = 0,
  TD_MY_RBRC
};

/* Tap Dance Definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
  /* Tap once for NO, twice for RESET */
  /* [TD_NO_RES]  = ACTION_TAP_DANCE_DOUBLE(KC_NO, reset_keyboard()), */
  [TD_MY_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,KC_LCBR),

  [TD_MY_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC,KC_RCBR),
  /* [TD_MY_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_my_lbrc_finished, dance_my_lbrc_reset), */
  /* [TD_MY_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_my_rbrc_finished, dance_my_rbrc_reset), */
 /* Other declarations would go here, separated by commas, if you have them */
};


/* vim: set nonu : */ 
