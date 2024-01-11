/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

#pragma once

#define USB_POLLING_INTERVAL_MS 1

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY

#define ONESHOT_TAP_TOGGLE 2
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define USE_SERIAL_PD2
#define EE_HANDS

#ifdef RGBLIGHT_ENABLE
  #undef RGBLED_NUM
  #define RGBLIGHT_ANIMATIONS
  #define RGBLED_NUM 27
  #define RGBLIGHT_LIMIT_VAL 120
  #define RGBLIGHT_HUE_STEP 10
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 17
#endif

/* #define OLED_TRANSPORT = i2c */
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_UPDATE_INTERVAL 10
