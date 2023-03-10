#include "action.h"
#include QMK_KEYBOARD_H
#include "poxar.h"

// Macros
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
        case PX_MAIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_F2)));
                SEND_STRING("mosquitto_pub -t 'lights/main/set' -m 'toggle'\n");
            }
            break;
        case PX_KEYL:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_F2)));
                SEND_STRING("alacritty -e keylight toggle\n");
            }
            break;
        case PX_LOFF:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_F2)));
                SEND_STRING("mosquitto_pub -t 'lights/top/set' -m '0'\n");
            }
            break;
        case PX_LHLF:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_F2)));
                SEND_STRING("mosquitto_pub -t 'lights/top/set' -m '50'\n");
            }
            break;
        case PX_LFLL:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_F2)));
                SEND_STRING("mosquitto_pub -t 'lights/top/set' -m '100'\n");
            }
            break;
    }
    return true;
};
