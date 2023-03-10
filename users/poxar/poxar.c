#include "action.h"
#include QMK_KEYBOARD_H
#include "poxar.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
            return TAPPING_TERM + 150;
        case KC_RSFT:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PX_CLR:
            if (record->event.pressed) {
                clear_oneshot_mods();
                clear_keyboard();
            }
            break;
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
