#include "keycode.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _GAMING 3
#define _GAMING_RAISE 4

// Layer switching
#define DF_BASE DF(_BASE)
#define DF_GAME DF(_GAMING)
#define GAME_MO OSL(_GAMING_RAISE)
#define SPC_RSE LT(_RAISE, KC_SPACE)
#define ENT_LWR LT(_LOWER, KC_ENTER)

// Other multiuse keys
#define GUI_ESC MT(MOD_LGUI, KC_ESC)
#define CTLBSPC MT(MOD_RCTL, KC_BSPC)

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
  [_BASE] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    GUI_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,    KC_RGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_LALT, CTL_GUI, ENT_LWR,             SPC_RSE, CTLBSPC, KC_RALT
                               // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  ),
  [_RAISE] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, PX_APP1, PX_APP2, DSK_LFT, DSK_RGT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_INS,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, SFT_LFT, SFT_RGT, XXXXXXX, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_GRV,  DF_GAME,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,             _______, _______, _______
                               // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, PX_TILE, KC_VOLD, KC_VOLU, KC_MUTE,                      KC_BSPC, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, KC_MICM, KC_MPRV, KC_MNXT, KC_MPLY, _______,    _______, KC_DEL,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,             _______, _______, QK_BOOT
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
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, KC_MICM, XXXXXXX, XXXXXXX, KC_I,    _______,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,             _______, _______, _______
                               // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_GUI:
            return TAPPING_TERM + 150;
        case GUI_ESC:
            return TAPPING_TERM + 50;
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

/* const uint16_t PROGMEM open_cbrace[] =   {KC_A, KC_S, COMBO_END}; */
/* const uint16_t PROGMEM open_bracket[] =  {KC_S, KC_D, COMBO_END}; */
/* const uint16_t PROGMEM open_paren[] =    {KC_D, KC_F, COMBO_END}; */

/* const uint16_t PROGMEM close_paren[] =  {KC_J, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM close_bracket[] = {KC_K, KC_L, COMBO_END}; */
/* const uint16_t PROGMEM close_cbrace[] =   {KC_L, KC_SCLN, COMBO_END}; */

/* combo_t key_combos[] = { */
/*     COMBO(open_cbrace,   KC_LEFT_CURLY_BRACE), */
/*     COMBO(open_bracket,  KC_LEFT_BRACKET), */
/*     COMBO(open_paren,    KC_LEFT_PAREN), */
/*     COMBO(close_paren,   KC_RIGHT_PAREN), */
/*     COMBO(close_bracket, KC_RIGHT_BRACKET), */
/*     COMBO(close_cbrace,  KC_RIGHT_CURLY_BRACE), */
/* }; */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PX_TILE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
            }
            break;
    }
    return true;
};

const rgblight_segment_t PROGMEM default_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_OFF});

const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});
const rgblight_segment_t PROGMEM gaming_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});

const rgblight_segment_t PROGMEM caps_word_active[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_WHITE});
const rgblight_segment_t PROGMEM oneshot_active[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_PURPLE});
const rgblight_segment_t PROGMEM oneshot_locked[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_ORANGE});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    default_layer,
    gaming_layer,
    gaming_raise_layer,
    caps_word_active,
    oneshot_active,
    oneshot_locked
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
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(2, layer_state_cmp(state, _GAMING_RAISE));
    return state;
}

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(3, active);
}

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods) {
        rgblight_set_layer_state(4, true);
    } else {
        rgblight_set_layer_state(4, false);
    }
}

void oneshot_locked_mods_changed_user(uint8_t mods) {
    if (mods) {
        rgblight_set_layer_state(5, true);
    } else {
        rgblight_set_layer_state(5, false);
    }
}
