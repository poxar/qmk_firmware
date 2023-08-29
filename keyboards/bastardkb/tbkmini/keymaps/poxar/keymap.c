#include QMK_KEYBOARD_H

// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3
#define _GAMING 4
#define _GAMING_RAISE 5

// Layer switching
#define LT_RSE LT(_RAISE, KC_SPACE)
#define LT_LWR LT(_LOWER, KC_ENTER)
#define OSL_ADJ OSL(_ADJUST)

#define DF_BASE DF(_BASE)
#define DF_GAME DF(_GAMING)
#define OS_GRSE OSL(_GAMING_RAISE)

// Modtap keys
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define INT_BSP MT(MOD_RALT, KC_BACKSPACE)

#define HM_S MT(MOD_LGUI, KC_S)
#define HM_D MT(MOD_LALT, KC_D)
#define HM_F MT(MOD_LCTL, KC_F)

#define HM_J MT(MOD_RCTL, KC_J)
#define HM_K MT(MOD_LALT, KC_K)
#define HM_L MT(MOD_RGUI, KC_L)

// Macros
#define CTLBSPC LCTL(KC_BSPC)
#define KC_MICM KC_F20 // F20 mutes the microphone in linux

enum custom_keycodes {
    PX_TILE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  KC_A,    HM_S,    HM_D,    HM_F,    KC_G,       KC_H,    HM_J,    HM_K,    HM_L,    KC_SCLN, KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               CTL_TAB, LT_LWR,  KC_DEL,     KC_ESC,  LT_RSE,  INT_BSP
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_GRV,  KC_BSLS, KC_LBRC, KC_LPRN, KC_LCBR,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_TILD, KC_PIPE, KC_RBRC, KC_RPRN, KC_RCBR,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQUO, _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______, OSL_ADJ, _______,    _______, _______, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_ESC,  PX_TILE, KC_VOLD, KC_VOLU, KC_MUTE,    KC_PSCR, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_DEL,  KC_MICM, KC_MPRV, KC_MNXT, KC_MPLY,    KC_INS,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
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
                               KC_LALT,  KC_SPC, OS_GRSE,    DF_BASE, KC_ENT,  KC_RALT
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_GAMING_RAISE] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_I,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               KC_LCTL, _______, _______,    _______, _______, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_RSE:
        case LT_LWR:
        case INT_BSP:
        case CTL_TAB:
            return TAPPING_TERM;
        default:
            return 0;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_S:
        case HM_L:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PX_TILE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
                wait_ms(10);
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                wait_ms(10);
                SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
                wait_ms(10);
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
            }
            break;
    }
    return true;
};
