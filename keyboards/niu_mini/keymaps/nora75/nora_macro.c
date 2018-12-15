/*
NORA75:
This file declare custom macro.
*/

#include "nora_macro.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MY_2:
        case MY_6:
        case MY_7:
        case MY_8:
        case MY_9:
        case MY_0:
            if (record->event.pressed) {
                my_autoshift_flush();
                my_autoshift_on(keycode);
            } else {
                my_autoshift_flush();
            }
            return true;
            break;
        case MY_LBRC:
            keycode = KC_RBRC;
            break;
        case MY_RBRC:
            keycode = KC_BSLS;
            break;
        case MY_QUOT:
            register_code(KC_LSFT);
            keycode = KC_7;
        case MY_SCLN:
            keycode = KC_SCLN;
        case MY_BSLS:
            keycode = JP_BSLS;
        case MY_TILD:
            register_code(KC_LSFT);
            keycode = KC_EQL;
        case MY_GRV:
            register_code(KC_LSFT);
            keycode = KC_LBRC;
        case MY_MINUS:
            keycode = KC_MINUS;
        case MY_EQL:
            register_code(KC_LSFT);
            keycode = MINUS;
            if (record->event.pressed) {
                my_autoshift_flush();
                my_autoshift_on(keycode);
            } else {
                my_autoshift_flush();
            }
            return true;
        default:
            return true;
            break;
    }
    return true;
}

/* case MY_DEFAULT: */
/* if (!jp_us_is_switched) { */
/*     layer_clear(); */
/*     layer_on(_DEFAULT); */
/* } else { */
/*     layer_clear(); */
/*     layer_on(_JDEFAULT); */
/* } */
/* break; */

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
