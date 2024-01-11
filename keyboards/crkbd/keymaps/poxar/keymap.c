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
#define LT_RSE LT(_RAISE, KC_SPACE)
#define LT_LWR LT(_LOWER, KC_ENTER)
#define MO_HYPR OSL(_HYPER)

// Modtap keys
#define SFT_TAB MT(MOD_LSFT, KC_TAB)
#define INT_BSP MT(MOD_RALT, KC_BACKSPACE)

#define HM_S MT(MOD_LGUI, KC_S)
#define HM_D MT(MOD_LALT, KC_D)
#define HM_F MT(MOD_LCTL, KC_F)

#define HM_J MT(MOD_RCTL, KC_J)
#define HM_K MT(MOD_LALT, KC_K)
#define HM_L MT(MOD_RGUI, KC_L)

// Macros
#define CTLBSPC LCTL(KC_BSPC)
#define KC_MICM KC_F20 // F20 mutes the microphone in linux

enum custom_keycodes {
    PX_TILE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_crkbd_wrapper(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESC,  KC_A,    HM_S,    HM_D,    HM_F,    KC_G,               KC_H,    HM_J,    HM_K,    HM_L,    KC_SCLN, KC_QUOT,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐ ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_DEL,  SFT_TAB, LT_LWR,    LT_RSE,  INT_BSP, KC_INS
                               // └────────┴────────┴────────┘ └────────┴────────┴────────┘
  ),
  [_RAISE] = LAYOUT_crkbd_wrapper(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_GRV,  XXXXXXX, KC_LBRC, KC_LPRN, KC_LCBR,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, _______,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_TILD, XXXXXXX, KC_RBRC, KC_RPRN, KC_RCBR,            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS, _______,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐ ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, MO_HYPR,   _______, _______, _______
                               // └────────┴────────┴────────┘ └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT_crkbd_wrapper(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_ESC,  PX_TILE, KC_VOLD, KC_VOLU, KC_MUTE,            XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_DEL,  KC_MICM, KC_MPRV, KC_MNXT, KC_MPLY,            XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐ ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,   MO_HYPR, KC_DEL,  _______
                               // └────────┴────────┴────────┘ └────────┴────────┴────────┘
  ),
  [_HYPER] = LAYOUT_crkbd_wrapper(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,            KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,            KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
 //├────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,            KC_0,    KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐ ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   _______, _______, _______,   _______, _______, _______
                               // └────────┴────────┴────────┘ └────────┴────────┴────────┘
  )
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_RSE:
        case LT_LWR:
        case INT_BSP:
        case SFT_TAB:
            return TAPPING_TERM;
        default:
            return 0;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_S:
        case HM_L:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PX_TILE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
                wait_ms(10);
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                wait_ms(10);
                SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
                wait_ms(10);
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
            }
            break;
    }
    return true;
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    oled_render_logo();
    return false;
}
