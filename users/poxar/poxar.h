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
#define OS_LGUI OSM(MOD_LGUI)

// Macros
#define KC_MICM KC_F20 // F20 mutes the microphone in linux
#define DSK_LFT LALT(LCTL(KC_LEFT))
#define DSK_RGT LALT(LCTL(KC_RIGHT))
#define SFT_LFT LALT(LCTL(LSFT(KC_LEFT)))
#define SFT_RGT LALT(LCTL(LSFT(KC_RIGHT)))

enum custom_keycodes {
    PX_CLR = SAFE_RANGE,
    PX_TERM,
    PX_TILE,
    PX_MAIN,
    PX_KEYL,
    PX_LOFF,
    PX_LHLF,
    PX_LFLL,
};
