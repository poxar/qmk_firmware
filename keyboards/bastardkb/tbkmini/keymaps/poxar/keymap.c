#include QMK_KEYBOARD_H

// Layers
#define _STD 0
#define _NAV 1
#define _SYM 2
#define _NUM 3
#define _ADJ 4
#define _GAMING 5
#define _GAMING_ONE 6
#define _GAMING_TWO 7

// Layer switching
#define OSL_NAV OSL(_NAV)
#define OSL_SYM OSL(_SYM)
#define OSL_NUM OSL(_NUM)
#define OSL_ADJ OSL(_ADJ)

#define DF_BASE DF(_STD)
#define DF_GAME DF(_GAMING)
#define OSG_ONE OSL(_GAMING_ONE)
#define OSG_TWO OSL(_GAMING_TWO)

// Homerow Mods
#define HM_A MT(MOD_LSFT, KC_A)
#define HM_S MT(MOD_LGUI, KC_S)
#define HM_D MT(MOD_LALT, KC_D)
#define HM_F MT(MOD_LCTL, KC_F)

#define HM_J MT(MOD_RCTL, KC_J)
#define HM_K MT(MOD_LALT, KC_K)
#define HM_L MT(MOD_RGUI, KC_L)
#define HM_SCLN MT(MOD_RSFT, KC_SCLN)

// international characters on us keyboard
#define HM_G MT(MOD_RALT, KC_G)
#define HM_H MT(MOD_RALT, KC_H)

// Modifiers
#define CAPSTOG QK_CAPS_WORD_TOGGLE

// Shortcuts
#define KC_MICM KC_F20 // F20 mutes the microphone in linux

// Macros
enum custom_keycodes {
    MA_MAIL = SAFE_RANGE,
};

// Cancel oneshot with esc
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_ESC && record->event.pressed) {
        bool rc = true;
        uint8_t mods = 0;

        if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
            clear_oneshot_mods();
            unregister_mods(mods);
            rc = false;
        }

        if ((mods = get_oneshot_locked_mods())) {
            clear_oneshot_locked_mods();
            unregister_mods(mods);
            rc = false;
        }

        if (is_oneshot_layer_active()) {
            layer_clear();
            rc = false;
        }

        return rc;
    }

    if (keycode == MA_MAIL && record->event.pressed) {
      SEND_STRING("philipp.millar@poxar.net");
      return true;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_STD] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  HM_A,    HM_S,    HM_D,    HM_F,    HM_G,       HM_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               KC_ESC,  OSL_SYM, OSL_NUM,    OSL_NAV, KC_SPC,  QK_REP
//                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_NAV] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, KC_MICM, KC_VOLD, KC_VOLU, KC_MUTE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______, OSL_ADJ, _______,    _______, _______, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_SYM] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, CAPSTOG, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT,      XXXXXXX, KC_MINS, KC_EQL,  KC_BSLS, KC_PIPE, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    CAPSTOG, KC_DEL,  KC_RCBR, KC_RBRC, KC_RPRN, KC_GT,      XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______, _______, OSL_NAV,    OSL_ADJ, KC_BSPC, QK_AREP
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_NUM] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TAB,  XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,    KC_SLSH, KC_KP_7, KC_KP_8, KC_KP_9, KC_MINS, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX,    KC_ASTR, KC_KP_4, KC_KP_5, KC_KP_6, KC_PLUS, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,    XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_ENT,  _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               DF_GAME, _______, _______,    KC_KP_0, KC_SPC,  KC_KP_DOT
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_ADJ] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,    XXXXXXX, MA_MAIL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               KC_LCTL,  KC_SPC, OSG_ONE,    DF_BASE, KC_SPC,  KC_RALT
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_A:
        case HM_SCLN:
        case KC_LSFT:
            return TAPPING_TERM + 100;

        case HM_S:
        case HM_L:
            return TAPPING_TERM + 50;

        case HM_D:
        case HM_F:
        case HM_J:
        case HM_K:
            return TAPPING_TERM;

        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSL_NUM:
        case OSL_ADJ:
        case OSL_NAV:
        case OSL_SYM:
        case OSG_ONE:
        case OSG_TWO:
            return 500;
        default:
            return 0;
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _SYM:
            case _GAMING_ONE:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case _NUM:
            case _GAMING_TWO:
                rgb_matrix_set_color(i, RGB_GREEN);
                break;
            case _GAMING:
            case _ADJ:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            default:
                break;
        }
    }
    return false;
}
