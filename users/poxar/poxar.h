#pragma once

// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Layer switching
#define SPC_RSE LT(_RAISE, KC_SPACE)
#define ENT_LWR LT(_LOWER, KC_ENTER)

// Oneshot modifiers
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)

// Macros
#define KC_MICM KC_F20 // F20 mutes the microphone in linux
#define APP_1 LGUI(KC_1)
#define APP_2 LGUI(KC_2)
#define APP_3 LGUI(KC_3)
#define APP_4 LGUI(KC_4)
#define APP_5 LGUI(KC_5)
#define APP_6 LGUI(KC_6)
#define APP_7 LGUI(KC_7)
#define DSK_LFT LALT(LCTL(KC_LEFT))
#define DSK_RGT LALT(LCTL(KC_RIGHT))

enum custom_keycodes {
    PX_CLR = SAFE_RANGE,
    PX_TERM,
    PX_TILE,
    PX_MAIL,
    PX_NEWS,
    PX_SCLD,
    PX_LOFF,
    PX_LHLF,
    PX_LFLL,
};
