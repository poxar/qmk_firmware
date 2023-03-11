#pragma once

// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Layer switching
#define SPC_RSE LT(_RAISE, KC_SPACE)
#define ENT_LWR LT(_LOWER, KC_ENTER)

// One shot modifiers
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RALT OSM(MOD_RALT)

// Macros
#define KC_MICM KC_F20 // F20 mutes the microphone in linux
#define PX_APP1 LGUI(KC_1)
#define PX_APP2 LGUI(KC_2)
#define DSK_LFT LALT(LCTL(KC_LEFT))
#define DSK_RGT LALT(LCTL(KC_RIGHT))
#define SFT_LFT LALT(LCTL(LSFT(KC_LEFT)))
#define SFT_RGT LALT(LCTL(LSFT(KC_RIGHT)))

enum custom_keycodes {
    PX_CLR = SAFE_RANGE,
    PX_TILE,
};
