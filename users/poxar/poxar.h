#pragma once

// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Layer switching
#define SPC_RSE LT(_RAISE, KC_SPACE)
#define ENT_LWR LT(_LOWER, KC_ENTER)

// Modifiers
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)

// Dual use modifiers (home row mods light)
#define MT_A MT(MOD_LSFT, KC_A)
#define MT_SCLN MT(MOD_LSFT, KC_SCLN)
#define MT_ESC MT(MOD_LGUI, KC_ESC)

// Macros
#define KC_MICM KC_F20
#define GUI_ALL LGUI(KC_A)
#define APP_1 LGUI(KC_1)
#define APP_2 LGUI(KC_2)
#define APP_3 LGUI(KC_3)
#define APP_4 LGUI(KC_4)
#define APP_5 LGUI(KC_5)
#define DSK_LFT LALT(LCTL(KC_LEFT))
#define DSK_RGT LALT(LCTL(KC_RIGHT))

#define MEH_1 MEH(KC_F1)
#define MEH_2 MEH(KC_F2)
#define MEH_3 MEH(KC_F3)

enum custom_keycodes {
    PX_TERM = SAFE_RANGE,
    PX_TILE,
};
