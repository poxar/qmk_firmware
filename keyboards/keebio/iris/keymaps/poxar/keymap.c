#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
      KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MINS, KC_EQL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      KC_LALT, KC_LCTL, KC_ENT, KC_SPC, MO(1), KC_RALT),
	[1] = LAYOUT(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL,
      KC_GRV, KC_LCBR, KC_RCBR, KC_VOLD, KC_VOLU, KC_MUTE, KC_PSCR, KC_END, KC_HOME, KC_LBRC, KC_RBRC, KC_INS,
      KC_TRNS, KC_LPRN, KC_RPRN, KC_MPRV, KC_MNXT, KC_MPLY, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, RESET,
      KC_TRNS, KC_LT, KC_GT, KC_NO, KC_NO, KC_LCBR, KC_F11, KC_F12, KC_RCBR, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_TRNS,
      KC_TRNS, KC_TRNS, LCTL(KC_ENT), KC_TRNS, KC_TRNS, DF(2)),
	[2] = LAYOUT(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MINS, KC_EQL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      KC_LALT, KC_LGUI, KC_ENT, KC_SPC, MO(3), KC_RALT),
	[3] = LAYOUT(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL,
      KC_GRV, KC_LCBR, KC_RCBR, KC_VOLD, KC_VOLU, KC_MUTE, KC_PSCR, KC_END, KC_HOME, KC_LBRC, KC_RBRC, KC_INS,
      KC_TRNS, KC_LPRN, KC_RPRN, KC_MPRV, KC_MNXT, KC_MPLY, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, RESET,
      KC_TRNS, KC_LT, KC_GT, KC_NO, KC_NO, KC_LCBR, KC_F11, KC_F12, KC_RCBR, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_TRNS,
      KC_TRNS, KC_TRNS, SGUI(KC_ENT), KC_TRNS, KC_TRNS, DF(0)),
    [4] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
      KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [5] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_UNDS, KC_PLUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};
