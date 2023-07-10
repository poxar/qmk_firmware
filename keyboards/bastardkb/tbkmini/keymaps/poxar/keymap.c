#include QMK_KEYBOARD_H

// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3
#define _GAMING 4
#define _GAMING_RAISE 5

// Layer switching
#define SPC_RSE LT(_RAISE, KC_SPACE)
#define ENT_LWR LT(_LOWER, KC_ENTER)
#define TT_ADJ  TT(_ADJUST)

#define DF_BASE DF(_BASE)
#define DF_GAME DF(_GAMING)
#define OS_GRSE OSL(_GAMING_RAISE)

// Multiuse keys
#define LALTESC MT(MOD_LALT, KC_ESC)
#define CTLBSPC MT(MOD_RCTL, KC_BSPC)
#define RALTTAB MT(MOD_RALT, KC_TAB)

// Tap dance
tap_dance_action_t tap_dance_actions[] = {
    [0] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI),
};
#define CTL_GUI TD(0)

// Macros
#define KC_MICM KC_F20 // F20 mutes the microphone in linux
#define PX_APP1 LGUI(KC_1)
#define PX_APP2 LGUI(KC_2)
#define DSK_LFT LALT(LCTL(KC_LEFT))
#define DSK_RGT LALT(LCTL(KC_RIGHT))
#define SFT_LFT LALT(LCTL(LSFT(KC_LEFT)))
#define SFT_RGT LALT(LCTL(LSFT(KC_RIGHT)))

enum custom_keycodes {
    PX_TILE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               CTL_GUI, ENT_LWR, LALTESC,    RALTTAB, SPC_RSE, CTLBSPC
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, PX_APP1, PX_APP2, DSK_LFT, DSK_RGT, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_WBAK, KC_INS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, SFT_LFT, SFT_RGT, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_WFWD, _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______,  TT_ADJ, _______,    DF_GAME, _______, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_DEL,  PX_TILE, KC_VOLD, KC_VOLU, KC_MUTE,    KC_BSPC, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, KC_MICM, KC_MPRV, KC_MNXT, KC_MPLY,    KC_DEL,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______, _______, _______,    QK_BOOT, TT_ADJ, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,    KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, KC_NUM,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,    KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,    KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______, _______, _______,    _______, _______, _______
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
                               KC_LCTL,  KC_SPC, OS_GRSE,    KC_RALT, KC_ENT, DF_BASE
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_GAMING_RAISE] = LAYOUT_split_3x6_3(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                               _______, _______, _______,    _______, _______, _______
                           // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_GUI:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_LWR:
        case SPC_RSE:
            return TAPPING_TERM;
        default:
            return 0;
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
