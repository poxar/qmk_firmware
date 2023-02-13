#include "action.h"
#include QMK_KEYBOARD_H
#include "poxar.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PX_CLR:
            if (record->event.pressed) {
                clear_oneshot_mods();
                clear_keyboard();
            }
            break;
        case PX_TERM:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("2"));
                SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
                SEND_STRING(SS_LGUI("1"));
                SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
            }
            break;
        case PX_TILE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
                SEND_STRING(SS_LALT(SS_TAP(X_ESCAPE)));
                SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
                SEND_STRING(SS_LALT(SS_TAP(X_ESCAPE)));
            }
            break;
    }
    return true;
};
