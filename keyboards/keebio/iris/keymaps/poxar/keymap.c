#include "keycode.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "poxar.h"

#define _GAMING 3
#define _GAMING_RAISE 4

#define DF_BASE DF(_BASE)
#define DF_GAME DF(_GAMING)
#define GAME_MO OSL(_GAMING_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,    KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   OS_LALT, OS_LCTL, ENT_LWR,             SPC_RSE, OS_LGUI, OS_RALT
                               // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  ),
  [_RAISE] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, PX_APP1, PX_APP2, DSK_LFT, DSK_RGT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ESC,  KC_INS,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, SFT_LFT, SFT_RGT, XXXXXXX, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, DF_GAME,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, PX_CLR,              _______, _______, _______
                               // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, PX_TILE, KC_VOLD, KC_VOLU, KC_MUTE,                      KC_BSPC, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, _______,    _______, KC_DEL,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,             PX_CLR,  _______, _______
                               // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  ),
  [_GAMING] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    GAME_MO,    KC_LGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_LALT, KC_LCTL, KC_SPC,              KC_ENT,  DF_BASE, KC_RALT
                               // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  ),
  [_GAMING_RAISE] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MICM,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_I,    _______,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,             _______, _______, _______
                               // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  )
};

const rgblight_segment_t PROGMEM default_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_OFF});
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_PURPLE});
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_ORANGE});
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});
const rgblight_segment_t PROGMEM gaming_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});
const rgblight_segment_t PROGMEM caps_word_active[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_WHITE});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    default_layer,
    raise_layer,
    lower_layer,
    gaming_layer,
    gaming_raise_layer,
    caps_word_active
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_enable_noeeprom();
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(4, layer_state_cmp(state, _GAMING_RAISE));
    return state;
}

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(5, active);
}
