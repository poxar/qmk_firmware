/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Philipp Millar <@poxar>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

#define LAYOUT_crkbd_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _HYPER 3

// Layer switching
#define SPC_RSE LT(_RAISE, KC_SPACE)
#define ENT_LWR LT(_LOWER, KC_ENTER)
#define MO_HYPR MO(_HYPER)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_crkbd_wrapper(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐ ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   OS_LALT, OS_LCTL, ENT_LWR,   SPC_RSE, KC_BSPC, OS_RALT
                               // └────────┴────────┴────────┘ └────────┴────────┴────────┘
  ),
  [_RAISE] = LAYOUT_crkbd_wrapper(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, PX_APP1, PX_APP2, DSK_LFT, DSK_RGT, XXXXXXX,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ESC,  KC_INS,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, SFT_LFT, SFT_RGT, XXXXXXX,            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, PX_CLR,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐ ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, MO_HYPR,   _______, _______, _______
                               // └────────┴────────┴────────┘ └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT_crkbd_wrapper(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, PX_TILE, KC_VOLD, KC_VOLU, KC_MUTE,            KC_BSPC, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,            KC_DEL,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐ ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,   MO_HYPR, _______, _______
                               // └────────┴────────┴────────┘ └────────┴────────┴────────┘
  ),
  [_HYPER] = LAYOUT_crkbd_wrapper(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐ ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,   _______, _______, _______
                               // └────────┴────────┴────────┘ └────────┴────────┴────────┘
  )
};

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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_RAISE 2
#define L_LOWER 4
#define L_HYPER 8

void oled_render_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("                   "), false);
            oled_write_ln_P(PSTR("                   "), false);
            oled_write_ln_P(PSTR("                   "), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("                   "), false);
            oled_write_ln_P(PSTR("     L O W E R     "), false);
            oled_write_ln_P(PSTR("                   "), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("                   "), false);
            oled_write_ln_P(PSTR("     R A I S E     "), false);
            oled_write_ln_P(PSTR("                   "), false);
            break;
        case L_HYPER:
        case L_HYPER|L_LOWER:
        case L_HYPER|L_RAISE:
        case L_HYPER|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("                   "), false);
            oled_write_ln_P(PSTR("     H Y P E R     "), false);
            oled_write_ln_P(PSTR("                   "), false);
            break;
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}
#endif // OLED_DRIVER_ENABLE
