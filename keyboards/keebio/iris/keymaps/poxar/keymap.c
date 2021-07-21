#include QMK_KEYBOARD_H

#define ENT_LWR LT(2, KC_ENT)
#define ENT_GMG LT(4, KC_ENT)
#define SPC_RSE LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,         KC_EQL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                          KC_LALT, KC_LCTL, ENT_LWR,        SPC_RSE, KC_RCTL, KC_RALT
    ),
	[1] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
      KC_TRNS, KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_INS,
      KC_TRNS, KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_MPLY, KC_F11,          KC_F12, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   RESET,
                                          KC_TRNS, KC_TRNS, KC_NO,            KC_NO, KC_TRNS, DF(3)
    ),
    [2] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
      KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
      KC_TRNS, KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,                            KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV,
      KC_TRNS, KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_NO,   KC_NO,            KC_NO, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD,
                                          KC_TRNS, KC_TRNS, KC_NO,            KC_NO, KC_TRNS, DF(3)
    ),
    // GAMING layer
	[3] = LAYOUT(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,        KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                          KC_LALT, KC_LCTL, KC_SPC,        ENT_GMG,  KC_RCTL, KC_RALT
    ),
	[4] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
      KC_TRNS, KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_INS,
      KC_TRNS, KC_LT,   KC_GT,   KC_MPRV, KC_MNXT, KC_MPLY,  KC_F11,         KC_F12, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
                                          KC_TRNS, KC_TRNS, KC_TRNS,          KC_NO, KC_TRNS, DF(0)
    ),

};

const rgblight_segment_t PROGMEM default_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_OFF});
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_PURPLE});
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_ORANGE});
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});
const rgblight_segment_t PROGMEM gaming_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_GREEN});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    default_layer,
    raise_layer,
    lower_layer,
    gaming_layer,
    gaming_raise_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_enable_noeeprom();
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}
