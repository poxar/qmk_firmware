#include QMK_KEYBOARD_H
#include "poxar.h"

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LFT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI),
    [TD_RGT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LALT),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(LWR, KC_ENT):
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_LFT):
        case TD(TD_RGT):
            return 250;
        default:
            return TAPPING_TERM;
    }
}
