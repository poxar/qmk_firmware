#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, MO(1), MO(2), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LALT, KC_LGUI, KC_SPC, KC_ENT, KC_RCTL, KC_RALT),
	[1] = LAYOUT(KC_ESC, KC_NO, KC_NO, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_DEL, KC_TAB, KC_NO, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, KC_END, KC_HOME, KC_LBRC, KC_RBRC, KC_INS, KC_LCTL, KC_PDOT, KC_P4, KC_P5, KC_P6, KC_PCMM, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_TRNS, KC_P0, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_TRNS, KC_LALT, KC_TRNS, KC_SPC, KC_ENT, KC_RCTL, KC_RALT),
	[2] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TAB, KC_BTN1, KC_MS_U, KC_BTN3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC__VOLUP, KC_MUTE, KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_MPLY, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, KC_LALT, KC_LGUI, KC_SPC, KC_ENT, KC_RCTL, KC_RALT)
};
