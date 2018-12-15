/*
NORA75:
This file is my keymap.c file.
This file declare keys on keyboard.
You want to know more about these custom my keys, read the files of my directory.
*/

#include QMK_KEYBOARD_H
/* #include "dynamic_macro.h" */
#include "nora_autoshift.h"
#include "nora_lead.h"
#include "nora_macro.h"

/* static bool bsdel_mods = false; */
/* static bool bs_del_was_shifted = false; */
/* static bool jp_us_is_switched = false; */

#define _DEFAULT  0
#define _LOWER    1
#define _RAISE    2
#define _SPECIAL  3
#define _LOCK     4
/* #define _JDEFAULT 5 */
/* #define _JLOWER   6 */
/* #define _JRAISE   7 */
/* #define VIM_N 10 */
/* #define VIM_V 11 */
/* #define VIM_I 12 */

/* Tap Dance Keys Declarations */
enum {
    TD_LBRC,
    TD_RBRC,
    TD_DSTART,
    TD_DPLAY,
    TD_LOCK,
    TD_RESET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |   Esc    |     Q    |     W    |     E    |     R    |     T    |     Y    |     U    |     I    |     O    |     P    |    BS    |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * | CTL_Tab  |     A    |     S    |     D    |     F    |     G    |     H    |     J    |     K    |     L    |     ;    |  Enter   |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * | Sft_O_Sft|     Z    |     X    |     C    |     V    |     B    |     N    |     M    |     ,    |     .    |     /    |    '     |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |  SPECIAL |          |          |    Alt   |   Lower  |        Space        |   RAISE  |    GUI   |          |          |  TD_LOCK |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_DEFAULT] = LAYOUT_planck_mit(
            KC_ESC,                KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,   KC_Y, KC_U,       KC_I,    KC_O,     KC_P,    KC_BSPC,
            LCTL_T(KC_TAB),        KC_A,    KC_S,    KC_D,    KC_F,       KC_G,   KC_H, KC_J,       KC_K,    KC_L,     KC_SCLN, KC_ENT,
            LSFT_T(OSM(MOD_LSFT)), KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,   KC_N, KC_M,       KC_COMM, KC_DOT,   KC_SLSH, KC_QUOT,
            TG(_SPECIAL),          XXXXXXX, XXXXXXX, KC_LALT, MO(_LOWER),    KC_SPC,    MO(_RAISE), KC_LGUI, XXXXXXX,  XXXXXXX, TD(TD_LOCK)
            ),

    /* Layer 1
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |     ~    |    F1    |    F2    |    F3    |    F4    |    F5    |    F6    |    F7    |    F8    |    F9    |    F10   |   Del    |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |   Vol-   |   Vol+   |   Mute   |    F11   |   F12    |   Left   |   Down   |    Up    |   Right  |  LEADER  |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |   Play   |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
            KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_DEL,
            _______,  KC_VOLD, KC_VOLU, KC_MUTE, KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_LEAD, _______,
            _______,  _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______,  _______, _______,
            _______,  _______, _______, _______, _______,     _______,      _______, _______, _______,  _______, _______
            ),

    /* Layer 2
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |     1    |     2    |     3    |     4    |     5    |     6    |     7    |     8    |     9    |     0    |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |   PgDn   |   PgUp   |   HOME   |    END   |     `    |     \    |     -    |     =    |    [-{   |    ]-}   |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |  Insert  |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
            _______, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,        KC_0,        _______,
            _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END, KC_GRV,  KC_BSLS, KC_MINS, KC_EQL,  TD(TD_LBRC), TD(TD_RBRC), _______,
            _______, _______, _______, _______, KC_INS, _______, _______, _______, _______, _______,     _______,     _______,
            _______, _______, _______, _______, _______,     _______,     _______, _______, _______,     _______,     _______
            ),

    /* Layer 3
     * MS = Mouse, MSW = Mouse Wheel, MSB = Mouse Button
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |          |          |          |   RESET  |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |   MSWUp  |   MSB2   |  MSLeft  |  MSDown  |   MSUp   |  MSRight |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |  MSWDown |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |  DEFAULT |          |          |          |          |         MSB1        |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_SPECIAL] = LAYOUT_planck_mit(
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, _______, XXXXXXX,      KC_BTN1,     XXXXXXX, _______, XXXXXXX, XXXXXXX, TD(TD_RESET)
            ),

    /* Layer 4
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |  DEFAULT |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOCK] = LAYOUT_planck_mit(
            XXXXXXX, XXXXXXX, MY_2, XXXXXXX, XXXXXXX, XXXXXXX, MY_6, MY_7, MY_8, MY_9, MY_0, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_DEFAULT)
            )

};

/* void matrix_init_user(void) { */
/* } */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/* if (!process_record_dynamic_macro(keycode, record)) { */
/*     return false; */
/* } */
/*     switch(keycode){ */
/*         case MOUSE: */
/*             if (record->event.pressed) { */
/*                 layer_on(MOUSE); */
/*                 update_tri_layer(MOUSE, RAISE, SPECIAL); */
/*             } else { */
/*                 layer_off(MOUSE); */
/*                 update_tri_layer(MOUSE, RAISE, SPECIAL); */
/*             } */
/*             return false; */
/*             break; */
/*         default: */
/*             return true; */
/*             break; */
/*             case M_BSDEL: */
/*                 if (record->event.pressed) { */
/*                     uint8_t kc = KC_BSPC; */
/*                     if (record->event.pressed) { */
/*                         if (keyboard_report->mods) { */
/*                             kc = KC_DEL; */
/*                         } */
/*                         register_code (kc); */
/*                         bsdel_mods = keyboard_report->mods; */
/*                     } */
/*                     else { */
/*                         if (bsdel_mods) { */
/*                             kc = KC_DEL; */
/*                         } */
/*                         unregister_code (kc); */
/*                     } */
/* } */
/* return true; */
/* } */

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

void dance_td_lock(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        layer_clear();
        layer_on(_LOCK);
    }
}

void dance_td_reset(qk_tap_dance_state_t *state, void *user_data) {
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
