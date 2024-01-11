#include QMK_KEYBOARD_H

// Layers
#define _BASE 0
#define _RIGHT 1
#define _LEFT 2
#define _ADJUST 3
#define _GAMING 4
#define _GAMING_ONE 5
#define _GAMING_TWO 6

// Layer switching
#define RGT_SPC LT(_RIGHT, KC_SPACE)
#define LFT_ENT LT(_LEFT, KC_ENTER)

#define OSL_RGT OSL(_RIGHT)
#define OSL_LFT OSL(_LEFT)
#define OSL_ADJ OSL(_ADJUST)

#define DF_BASE DF(_BASE)
#define DF_GAME DF(_GAMING)
#define OSG_ONE OSL(_GAMING_ONE)
#define OSG_TWO OSL(_GAMING_TWO)

// Modtap keys
#define MT_S MT(MOD_LGUI, KC_S)
#define MT_D MT(MOD_LALT, KC_D)
#define MT_F MT(MOD_LCTL, KC_F)

#define MT_J MT(MOD_LCTL, KC_J)
#define MT_K MT(MOD_LALT, KC_K)
#define MT_L MT(MOD_LGUI, KC_L)

// Macros
#define OSM_INT OSM(MOD_RALT)
#define KC_MICM KC_F20 // F20 mutes the microphone in linux
#define BR_FRST LCTL(KC_1)
#define BR_TABL LCTL(KC_PGUP)
#define BR_TABR LCTL(KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  KC_A,    MT_S,    MT_D,    MT_F,    KC_G,       KC_H,    MT_J,    MT_K,    MT_L,    KC_SCLN, KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               KC_TAB,  LFT_ENT, OSL_RGT,    OSL_LFT, RGT_SPC, KC_BSPC
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_RIGHT] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, BR_FRST, KC_MICM, KC_VOLD, KC_VOLU, KC_MUTE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, BR_TABL, BR_TABR, KC_MPRV, KC_MNXT, KC_MPLY,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______, OSL_ADJ, _______,    _______, _______, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_LEFT] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, OSM_INT, KC_LBRC, KC_LCBR, KC_LPRN, _______,    _______, KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_DEL,  KC_RBRC, KC_RCBR, KC_RPRN, _______,    _______, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______, _______, _______,    _______, OSL_ADJ, KC_DEL
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,    KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,    KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               DF_GAME, _______, _______,    _______, _______, QK_BOOT
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_GAMING] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               KC_LCTL,  KC_SPC, OSG_ONE,    DF_BASE, KC_ENT,  KC_RALT
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_GAMING_ONE] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_MICM, XXXXXXX, XXXXXXX, XXXXXXX, KC_I,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               KC_LALT, OSG_TWO, _______,    _______, _______, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_GAMING_TWO] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               KC_LALT, _______, _______,    _______, _______, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGT_SPC:
        case LFT_ENT:
            return true;
        default:
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGT_SPC:
        case LFT_ENT:
            return TAPPING_TERM;
        default:
            return 0;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_S:
        case MT_L:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
