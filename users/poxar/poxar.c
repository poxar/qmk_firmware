#include QMK_KEYBOARD_H
#include "poxar.h"

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTL_LGUI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI),
    [TD_RCTL_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_LALT),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_LOWER, KC_ENTER):
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(0):
        case TD(1):
            return 350;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TILE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("2"));
                SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
                SEND_STRING(SS_LGUI("1"));
                SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
            }
            break;
        case UNTILE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("2"));
                SEND_STRING(SS_LGUI(SS_TAP(X_UP)));
                SEND_STRING(SS_LGUI("1"));
                SEND_STRING(SS_LGUI(SS_TAP(X_UP)));
            }
            break;
    }
    return true;
};
