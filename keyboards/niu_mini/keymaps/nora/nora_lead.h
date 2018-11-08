/* LEADER Functions */
/* LEADER Key = <L> */
/* <L>q : Alt(Meta) + F4 close current window(GUI) */

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        /* SEQ_ONE_KEY(KC_F) { */
        /*   // Anything you can do in a macro. */
        /*   SEND_STRING("QMK is awesome."); */
        /* } */
        /* SEQ_TWO_KEYS(KC_D, KC_D) { */
        /*   SEND_STRING(SS_LCTRL("a")SS_LCTRL("c")); */
        /* } */
        SEQ_ONE_KEY(KC_Q) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }
        /* SEQ_TWO_KEYS(KC_A, KC_S) { */
        /*   register_code(KC_LGUI); */
        /*   register_code(KC_S); */
        /*   unregister_code(KC_S); */
        /*   unregister_code(KC_LGUI); */
        /* } */
    }
}

/* vim: set nonu : */ 
