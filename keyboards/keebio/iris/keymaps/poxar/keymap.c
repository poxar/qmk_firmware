#include QMK_KEYBOARD_H
#include "poxar.h"

#define LAYOUT_iris_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_iris_wrapper(
    DEFAULT_0,
    DEFAULT_1,
    DEFAULT_2,
    DEFAULT_3_LFT, KC_MINS, KC_EQL, DEFAULT_3_RGT,
    DEFAULT_4
  ),
  [1] = LAYOUT_iris_wrapper(
    RAISE_0,
    RAISE_1,
    RAISE_2,
    RAISE_3_LFT, KC_F11, KC_F12, RAISE_3_RGT,
    RAISE_4
  ),
  [2] = LAYOUT_iris_wrapper(
    LOWER_0,
    LOWER_1,
    LOWER_2,
    LOWER_3_LFT, XXXXXXX, XXXXXXX, LOWER_3_RGT,
    LOWER_4
  ),
  [2] = LAYOUT_iris_wrapper(
    ADJUST_0,
    ADJUST_1,
    ADJUST_2,
    ADJUST_3_LFT, XXXXXXX, XXXXXXX, ADJUST_3_RGT,
    ADJUST_4
  ),
  // GAMING layer
  [4] = LAYOUT_iris_wrapper(
    GAMING_0,
    GAMING_1,
    GAMING_2,
    GAMING_3_LFT, KC_MINS, KC_EQL, GAMING_3_RGT,
    GAMING_4
  ),
  [5] = LAYOUT_iris_wrapper(
    GRAISE_0,
    GRAISE_1,
    GRAISE_2,
    GRAISE_3_LFT, KC_F11, KC_F12, GRAISE_3_RGT,
    GRAISE_4
  ),

};

const rgblight_segment_t PROGMEM default_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_OFF});
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_PURPLE});
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_ORANGE});
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_YELLOW});
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});
const rgblight_segment_t PROGMEM gaming_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_GREEN});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    default_layer,
    raise_layer,
    lower_layer,
    adjust_layer,
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
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    return state;
}
