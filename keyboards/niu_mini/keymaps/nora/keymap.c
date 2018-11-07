#include QMK_KEYBOARD_H
#include "nora_tap.h"

/* readability */
#define _______  KC_TRNS
#define XXXXXXX  KC_NO

/* static bool bsdel_mods = false; */

/* enum custom_keycodes { */
/*     M_BSDEL = SAFE_RANGE, */
/* }; */

#define DEFAULT 0
#define LOWER 1
#define UPPER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |   Esc    |     Q    |     W    |     E    |     R    |     T    |     Y    |     U    |     I    |     O    |     P    |   Bksp   |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * | CTL_Tab  |     A    |     S    |     D    |     F    |     G    |     H    |     J    |     K    |     L    |     ;    |  Enter   |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |Sft_O_Sft |     Z    |     X    |     C    |     V    |     B    |     N    |     M    |     ,    |     .    |     /    |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |KC_NO-RES |          |          |    Alt   |  Layer1  |        Space        |  Layer2  |    GUI   |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [DEFAULT] = LAYOUT_planck_mit(
            KC_ESC,                KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
            LCTL_T(KC_TAB),        KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
            LSFT_T(OSM(MOD_LSFT)), KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
            TD(TD_NO_RES),         KC_NO,   KC_NO,   KC_LALT, MO(1),     KC_SPC,     MO(2), KC_LGUI, KC_NO,   KC_NO,   KC_NO
            ),

    /* Layer 1
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |     ~    |    F1    |    F2    |    F3    |    F4    |    F5    |    F6    |    F7    |    F8    |    F9    |    F10   |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |   Vol-   |   Vol+   |   Mute   |    F11   |   F12    |   Left   |   Down   |    Up    |   Right  |  LEADER  |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |   Play   |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [LOWER] = LAYOUT_planck_mit(
            KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
            _______,  KC_VOLD, KC_VOLU, KC_MUTE, KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_LEAD, _______,
            _______,  _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______,  _______, _______,
            _______,  _______, _______, _______, _______,     _______,      _______, _______, _______,  _______, _______
            ),

    /* Layer 2 (r_ Indicates RGB Controls)
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |     `    |     1    |     2    |     3    |     4    |     5    |     6    |     7    |     8    |     9    |     0    |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |   PgDn   |   PgUp   |   HOME   |    END   |          |     \    |     -    |     =    |  (-[-{   |   )-]-}  |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [UPPER] = LAYOUT_planck_mit(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,           KC_0,           _______,
            _______, KC_PGDN, KC_PGUP, KC_HOME,  KC_END, _______, KC_BSLS, KC_MINS, KC_EQL,  TD(TD_MY_LBRC), TD(TD_MY_RBRC), _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,        _______,
            _______, _______, _______, _______, _______,     _______,      _______, _______, _______,        _______,        _______
            )
};


/* void matrix_init_user(void) { */
/* } */

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

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
    /* switch(keycode){ */
    /*     case M_BSDEL: */
    /*         if (record->event.pressed) { */
    /*             uint8_t kc = KC_BSPC; */
    /*             if (record->event.pressed) { */
    /*                 if (keyboard_report->mods) { */
    /*                     kc = KC_DEL; */
    /*                 } */
    /*                 register_code (kc); */
    /*                 bsdel_mods = keyboard_report->mods; */
    /*             } */
    /*             else { */
    /*                 if (bsdel_mods) { */
    /*                     kc = KC_DEL; */
    /*                 } */
    /*                 unregister_code (kc); */
    /*             } */
    /*         } */
    /* } */

    /* return true; */
/* }; */

/* vim: set nonu : */ 
