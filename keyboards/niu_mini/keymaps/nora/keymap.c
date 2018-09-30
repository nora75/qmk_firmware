#include QMK_KEYBOARD_H

// readability
#define _______  KC_TRNS
#define XXXXXXX  KC_NO
/* static bool bsdel_mods = false; */

/* enum custom_keycodes { */
/*     M_BSDEL = SAFE_RANGE, */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |  Alt |Layer1|    Space    |Layer2|  GUI |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [0] = LAYOUT_planck_mit(
            KC_ESC,         KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
            LCTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
            KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
            KC_NO,          KC_NO,   KC_NO,   KC_LALT, MO(1),     KC_SPC,     MO(2), KC_LGUI, KC_NO,   KC_NO,   KC_NO
            ),

    /* Layer 1
     * ,-----------------------------------------------------------------------------------.
     * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      | Vol+ | Vol- | Mute |  F11 |  F12 | Left | Down |  Up  | Right| Sleep| Wake |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      | Play |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [1] = LAYOUT_planck_mit(
            KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
            _______,  KC_VOLU, KC_VOLD, KC_MUTE, KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_SLEP, KC_WAKE,
            _______,  _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______,  _______, _______,
            _______,  _______, _______, _______, _______,     _______,      _______, _______, _______,  _______, _______
            ),

    /* Layer 2 (r_ Indicates RGB Controls)
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      | PgUP | PgDN | HOME |  END |      |      |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [2] = LAYOUT_planck_mit(
            KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
            _______, KC_PGUP, KC_PGDN, KC_END,  KC_HOME, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
            )
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

    return true;
};


/* vim: set nonu : */ 
