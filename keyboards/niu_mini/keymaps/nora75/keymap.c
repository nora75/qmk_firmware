/*
NORA75:
This file is my keymap.c file.
This file declare keys on keyboard.
You want to know more about these custom my keys, read the files of my directory.
*/

/* Include section {{{1 */
/* I want to separate this code to multiple file. */
#include QMK_KEYBOARD_H
/* #include "dynamic_macro.h" */
/* #include "nora_autoshift.h" */
/* #include "nora_lead.h" */
/* #include "nora_macro.h" */

/* Declare variables section {{{1 */
/* static bool bsdel_mods = false; */
/* static bool bs_del_was_shifted = false; */
/* static bool jp_us_is_switched = false; */
static bool alt_pressed = false;

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

/* Tap Dance Keys Declarations {{{2 */
enum {
    TD_LBRC,
    TD_RBRC,
    TD_DSTART,
    TD_DPLAY,
    TD_LOCK,
    TD_RESET
};

/* Leader keys initialize {{{2 */
/* LEADER Functions */
/* LEADER Key = <L> */
/* <L>q : Alt(Meta) + F4 close current window(GUI) */
LEADER_EXTERNS();

/* Macro keys initialize {{{2 */
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
    MY_EQL,
    MY_Q,
    QMKBEST
};
    /* DYNAMIC_MACRO_RANGE = SAFE_RANGE */
    /* MY_DEFAULT */
    /* M_BSDEL = SAFE_RANGE, */
    /* MY_MON = SAFE_RANGE */


/* Key maps {{{1 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0 Default Layer {{{2
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |   Esc    |     Q    |     W    |     E    |     R    |     T    |     Y    |     U    |     I    |     O    |     P    |    BS    |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * | CTL_Tab  |     A    |     S    |     D    |     F    |     G    |     H    |     J    |     K    |     L    |     ;    |   Enter  |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * | Sft_O_Sft|     Z    |     X    |     C    |     V    |     B    |     N    |     M    |     ,    |     .    |     /    |    '     |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |  SPECIAL |          |          |    Alt   |   Lower  |   Space  |   Enter  |   RAISE  |    GUI   |          |          |  TD_LOCK |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_DEFAULT] = LAYOUT_ortho_4x12(
            KC_ESC,                KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,     KC_P,    KC_BSPC,
            LCTL_T(KC_TAB),        KC_A,    KC_S,    KC_D,    KC_F,       KC_G,   KC_H,   KC_J,       KC_K,    KC_L,     KC_SCLN, KC_ENT,
            LSFT_T(OSM(MOD_LSFT)), KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,   KC_SLSH, KC_QUOT,
            TG(_SPECIAL),          XXXXXXX, XXXXXXX, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_LGUI, XXXXXXX,  XXXXXXX, TD(TD_LOCK)
            ),

    /* Layer 1 Lower Layer {{{2
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |     ~    |    F1    |    F2    |    F3    |    F4    |    F5    |    F6    |    F7    |    F8    |    F9    |    F10   |   Del    |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |   Vol-   |   Vol+   |   Mute   |    F11   |   F12    |   Left   |   Down   |    Up    |   Right  |  LEADER  |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |   Play   |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12(
            KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_DEL,
            _______,  KC_VOLD, KC_VOLU, KC_MUTE, KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_LEAD, _______,
            _______,  _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______,  _______, _______,
            _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
            ),

    /* Layer 2 Upper Layer {{{2
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |     1    |     2    |     3    |     4    |     5    |     6    |     7    |     8    |     9    |     0    |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |   PgDn   |   PgUp   |   HOME   |    END   |     `    |     \    |     -    |     =    |    [-{   |    ]-}   |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |  Insert  |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12(
            _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,        KC_0,        _______,
            _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END,  KC_GRV,  KC_BSLS, KC_MINS, KC_EQL,  TD(TD_LBRC), TD(TD_RBRC), _______,
            _______, _______, _______, _______, KC_INS,  _______, _______, _______, _______, _______,     _______,     _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,     _______
            ),

    /* Layer 3 Mouse Layer {{{2
     * MS = Mouse, MSW = Mouse Wheel, MSB = Mouse Button
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |   MSWUp  |   MSB2   |  MSLeft  |  MSDown  |   MSUp   |  MSRight |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |  MSWDown |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |  DEFAULT |          |          |          |          |   MSB1   |   MSB2   |          |          |          |          | TD_RESET |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_SPECIAL] = LAYOUT_ortho_4x12(
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, _______, XXXXXXX, XXXXXXX, TD(TD_RESET)
            ),

    /* Layer 4 Lock Layer {{{2
     * ,-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |  DEFAULT |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOCK] = LAYOUT_ortho_4x12(
            XXXXXXX, MY_Q, MY_2, XXXXXXX, XXXXXXX, XXXXXXX, MY_6, MY_7, MY_8, MY_9, MY_0, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            QMKBEST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_DEFAULT)
            )

};

/* Functions definitions {{{1 */

/* Tap dance functions definitions {{{2 */
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

/* Tap dance keys definitions {{{2 */
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

/* Leader keys definitions {{{2 */
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
        SEQ_ONE_KEY(KC_F1) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }
        SEQ_ONE_KEY(KC_W) {
            SEND_STRING(SS_LCTRL("s"));
        }
        /* SEQ_TWO_KEYS(KC_A, KC_S) { */
        /*   register_code(KC_LGUI); */
        /*   register_code(KC_S); */
        /*   unregister_code(KC_S); */
        /*   unregister_code(KC_LGUI); */
        /* } */
    }
}

/* Macro function definition {{{2 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MY_Q:
            if (record->event.pressed) {
                alt_pressed = get_mods() & (
                        MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT)
                        );
                if (alt_pressed) {
                    SEND_STRING(SS_LALT(SS_TAP(X_F4)));
                    return true;
                }
                SEND_STRING("q");
            }
            return true;
            break;
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        default:
            return true;
            break;
    }
    return true;
}

/* not yet complete (test) {{{3 */

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
/* case MY_DEFAULT: */
/* if (!jp_us_is_switched) { */
/*     layer_clear(); */
/*     layer_on(_DEFAULT); */
/* } else { */
/*     layer_clear(); */
/*     layer_on(_JDEFAULT); */
/* } */
/* break; */
        /* case MY_2: */
        /* case MY_6: */
        /* case MY_7: */
        /* case MY_8: */
        /* case MY_9: */
        /* case MY_0: */
        /*     if (record->event.pressed) { */
        /*         my_autoshift_flush(); */
        /*         my_autoshift_on(keycode); */
        /*     } else { */
        /*         my_autoshift_flush(); */
        /*     } */
        /*     return true; */
        /*     break; */
            /* case MY_LBRC: */
            /*     keycode = KC_RBRC; */
            /*     break; */
            /* case MY_RBRC: */
            /*     keycode = KC_BSLS; */
            /*     break; */
            /* case MY_QUOT: */
            /*     register_code(KC_LSFT); */
            /*     keycode = KC_7; */
            /* case MY_SCLN: */
            /*     keycode = KC_SCLN; */
            /* case MY_BSLS: */
            /*     keycode = JP_BSLS; */
            /* case MY_TILD: */
            /*     register_code(KC_LSFT); */
            /*     keycode = KC_EQL; */
            /* case MY_GRV: */
            /*     register_code(KC_LSFT); */
            /*     keycode = KC_LBRC; */
            /* case MY_MINUS: */
            /*     keycode = KC_MINUS; */
            /* case MY_EQL: */
            /*     register_code(KC_LSFT); */
                /* keycode = KC_MINUS; */
            /*     if (record->event.pressed) { */
            /*         my_autoshift_flush(); */
            /*         my_autoshift_on(keycode); */
            /*     } else { */
            /*         my_autoshift_flush(); */
            /*     } */
            /*     return true; */

/* case GRAVE_ESC: { */
/*   uint8_t shifted = get_mods() & ((MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT) */
/*                                   |MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))); */

/* #ifdef GRAVE_ESC_ALT_OVERRIDE */
/*   // if ALT is pressed, ESC is always sent */
/*   // this is handy for the cmd+opt+esc shortcut on macOS, among other things. */
/*   if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))) { */
/*     shifted = 0; */
/*   } */
/* #endif */

/* #ifdef GRAVE_ESC_CTRL_OVERRIDE */
/*   // if CTRL is pressed, ESC is always sent */
/*   // this is handy for the ctrl+shift+esc shortcut on windows, among other things. */
/*   if (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL))) { */
/*     shifted = 0; */
/*   } */
/* #endif */

/* #ifdef GRAVE_ESC_GUI_OVERRIDE */
/*   // if GUI is pressed, ESC is always sent */
/*   if (get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI))) { */
/*     shifted = 0; */
/*   } */
/* #endif */

/* #ifdef GRAVE_ESC_SHIFT_OVERRIDE */
/*   // if SHIFT is pressed, ESC is always sent */
/*   if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) { */
/*     shifted = 0; */
/*   } */
/* #endif */

/*   if (record->event.pressed) { */
/*     grave_esc_was_shifted = shifted; */
/*     add_key(shifted ? KC_GRAVE : KC_ESCAPE); */
/*   } */
/*   else { */
/*     del_key(grave_esc_was_shifted ? KC_GRAVE : KC_ESCAPE); */
/*   } */

/*   send_keyboard_report(); */
/*   return false; */
/* } */

/* if (!process_record_dynamic_macro(keycode, record)) { */
/*     return false; */
/* } */
/* case MOUSE: */
/*     if (record->event.pressed) { */
/*         layer_on(MOUSE); */
/*         update_tri_layer(MOUSE, RAISE, SPECIAL); */
/*     } else { */
/*         layer_off(MOUSE); */
/*         update_tri_layer(MOUSE, RAISE, SPECIAL); */
/*     } */
/*     return false; */
/*     break; */
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

/* vim: set fdm=marker fdl=1 fmr={{{,}}} : */
