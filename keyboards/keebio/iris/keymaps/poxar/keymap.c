#include QMK_KEYBOARD_H

#define ENT_LWR LT(2, KC_ENT)
#define ENT_GMG LT(4, KC_ENT)
#define SPC_RSE LT(1, KC_SPC)
#define ALT_TAB LALT(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,         KC_EQL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                          KC_LALT, KC_LCTL, ENT_LWR,        SPC_RSE, KC_LGUI, KC_RALT
    ),
	[1] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
      KC_TRNS, KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_INS,
      KC_TRNS, KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_MPLY, KC_F11,          KC_F12, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   RESET,
                                          KC_TRNS, KC_TRNS, KC_NO,            KC_NO, KC_TRNS, DF(3)
    ),
    [2] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
      ALT_TAB, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                          KC_TRNS, KC_TRNS, KC_NO,            KC_NO, KC_TRNS, DF(3)
    ),
    // GAMING layer
	[3] = LAYOUT(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,        KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                          KC_LALT, KC_LCTL, KC_SPC,        ENT_GMG,  KC_LGUI, KC_RALT
    ),
	[4] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
      KC_TRNS, KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_INS,
      KC_TRNS, KC_LT,   KC_GT,   KC_MPRV, KC_MNXT, KC_MPLY,  KC_F11,         KC_F12, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
                                          KC_TRNS, KC_TRNS, KC_TRNS,          KC_NO, KC_TRNS, DF(0)
    ),

};

void keyboard_post_init_user(void) {
    rgblight_disable_noeeprom();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DF(0):
            if (record->event.pressed) {
                rgblight_disable_noeeprom();
            }
            return true;
        case DF(3):
            if (record->event.pressed) {
                rgblight_sethsv_noeeprom(0, 100, 100);
                rgblight_enable_noeeprom();
            }
            return true;
        default:
            return true;
    }
}
