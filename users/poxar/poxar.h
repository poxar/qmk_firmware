#pragma once
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Layer switching
#define SPC_RSE LT(_RAISE, KC_SPACE)
#define ENT_LWR LT(_LOWER, KC_ENTER)

// Dual use keys
enum {
    TD_LCTL_LGUI,
    TD_RCTL_LALT,
};

#define TD_LFT TD(TD_LCTL_LGUI)
#define TD_RGT TD(TD_RCTL_LALT)

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
    TILE = SAFE_RANGE,
    UNTILE,
};
