/*
Copyright 2021 Philipp Millar <@poxar>
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "poxar.h"

#define LAYOUT_crkbd_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_crkbd_wrapper(DEFAULT_1, DEFAULT_2, DEFAULT_3, DEFAULT_4),
  [1] = LAYOUT_crkbd_wrapper(RAISE_1,   RAISE_2,   RAISE_3,   RAISE_4),
  [2] = LAYOUT_crkbd_wrapper(LOWER_1,   LOWER_2,   LOWER_3,   LOWER_4),
  [3] = LAYOUT_crkbd_wrapper(ADJUST_1,  ADJUST_2,  ADJUST_3,  ADJUST_4),
  [4] = LAYOUT_crkbd_wrapper(GAMING_1,  GAMING_2,  GAMING_3,  GAMING_4),
  [5] = LAYOUT_crkbd_wrapper(GRAISE_1,  GRAISE_2,  GRAISE_3,  GRAISE_4),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods && MOD_MASK_GUI) {
        oled_write_ln_P(PSTR("====== G U I ======"), false);
    }
    if (!mods) {
        oled_write_ln_P(PSTR("                   "), false);
    }
}

#define L_BASE 0
#define L_RAISE 2
#define L_LOWER 4
#define L_ADJUST 8
#define L_GAMING 16
#define L_GRAISE 32

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
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("                   "), false);
            oled_write_ln_P(PSTR("    A D J U S T    "), false);
            oled_write_ln_P(PSTR("                   "), false);
            break;
        case L_GAMING:
            oled_write_ln_P(PSTR("    G A M I N G    "), false);
            oled_write_ln_P(PSTR("                   "), false);
            oled_write_ln_P(PSTR("                   "), false);
            break;
        case L_GRAISE:
            oled_write_ln_P(PSTR("    G A M I N G    "), false);
            oled_write_ln_P(PSTR("     R A I S E     "), false);
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
