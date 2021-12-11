#pragma once

#define DFT 0 // default layer
#define RSE 1 // raise layer, numbers, navigation, media
#define LWR 2 // lower layer, special characters
#define ADJ 3 // adjust layer, random stuff, that doesn't fit anywhere
#define GMG 4 // gaming layer, swaps space/enter and deactivates home row mods

enum {
    TD_CTL,
    TD_GUI,
};

// default layer

#define DEFAULT_0_LFT KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define DEFAULT_1_LFT KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define DEFAULT_2_LFT KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define DEFAULT_3_LFT KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define DEFAULT_4_LFT                            KC_LALT, TD(TD_CTL), LT(LWR, KC_ENT)

#define DEFAULT_0_RGT KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC
#define DEFAULT_1_RGT KC_Y,    KC_U,    KC_I,    KC_O,    KC_P     //either BSLS or BSPC
#define DEFAULT_2_RGT KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define DEFAULT_3_RGT KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT
#define DEFAULT_4_RGT LT(RSE, KC_SPC),  TD(TD_GUI), KC_RALT

#define DEFAULT_0 DEFAULT_0_LFT, DEFAULT_0_RGT
#define DEFAULT_1 DEFAULT_1_LFT, DEFAULT_1_RGT
#define DEFAULT_2 DEFAULT_2_LFT, DEFAULT_2_RGT
#define DEFAULT_3 DEFAULT_3_LFT, DEFAULT_3_RGT
#define DEFAULT_4 DEFAULT_4_LFT, DEFAULT_4_RGT

// raise layer

#define RAISE_0_LFT _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define RAISE_1_LFT _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define RAISE_2_LFT _______, KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE
#define RAISE_3_LFT _______, KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_MPLY
#define RAISE_4_LFT                            MO(ADJ), _______, _______

#define RAISE_0_RGT KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_DEL
#define RAISE_1_RGT KC_6,    KC_7,    KC_8,    KC_9,     KC_0     //either DEL or NO
#define RAISE_2_RGT KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PSCR, KC_INS
#define RAISE_3_RGT KC_HOME, KC_PGDN, KC_PGUP, KC_END,   XXXXXXX, DF(GMG)
#define RAISE_4_RGT _______, _______, _______

#define RAISE_0 RAISE_0_LFT, RAISE_0_RGT
#define RAISE_1 RAISE_1_LFT, RAISE_1_RGT
#define RAISE_2 RAISE_2_LFT, RAISE_2_RGT
#define RAISE_3 RAISE_3_LFT, RAISE_3_RGT
#define RAISE_4 RAISE_4_LFT, RAISE_4_RGT

// lower layer

#define LOWER_0_LFT _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define LOWER_1_LFT _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define LOWER_2_LFT _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE
#define LOWER_3_LFT _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY
#define LOWER_4_LFT                            _______, _______, _______

#define LOWER_0_RGT KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, KC_BSPC
#define LOWER_1_RGT KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX
#define LOWER_2_RGT KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV
#define LOWER_3_RGT KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD
#define LOWER_4_RGT MO(ADJ), _______, _______

#define LOWER_0 LOWER_0_LFT, LOWER_0_RGT
#define LOWER_1 LOWER_1_LFT, LOWER_1_RGT
#define LOWER_2 LOWER_2_LFT, LOWER_2_RGT
#define LOWER_3 LOWER_3_LFT, LOWER_3_RGT
#define LOWER_4 LOWER_4_LFT, LOWER_4_RGT

// adjust layer

#define ADJUST_0_LFT _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ADJUST_1_LFT KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6
#define ADJUST_2_LFT XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_3_LFT XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_4_LFT                            _______, _______, _______

#define ADJUST_0_RGT KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC
#define ADJUST_1_RGT KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12
#define ADJUST_2_RGT XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_3_RGT XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET
#define ADJUST_4_RGT _______, _______, _______

#define ADJUST_0 ADJUST_0_LFT, ADJUST_0_RGT
#define ADJUST_1 ADJUST_1_LFT, ADJUST_1_RGT
#define ADJUST_2 ADJUST_2_LFT, ADJUST_2_RGT
#define ADJUST_3 ADJUST_3_LFT, ADJUST_3_RGT
#define ADJUST_4 ADJUST_4_LFT, ADJUST_4_RGT

// gaming layer

#define GAMING_0_LFT KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define GAMING_1_LFT KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define GAMING_2_LFT KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define GAMING_3_LFT KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define GAMING_4_LFT                            KC_LALT, KC_LCTL, KC_SPC

#define GAMING_0_RGT KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC
#define GAMING_1_RGT KC_Y,    KC_U,    KC_I,    KC_O,    KC_P     //either BSLS or BSPC
#define GAMING_2_RGT KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define GAMING_3_RGT KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT
#define GAMING_4_RGT KC_ENT,  DF(DFT), KC_RALT

#define GAMING_0 GAMING_0_LFT, GAMING_0_RGT
#define GAMING_1 GAMING_1_LFT, GAMING_1_RGT
#define GAMING_2 GAMING_2_LFT, GAMING_2_RGT
#define GAMING_3 GAMING_3_LFT, GAMING_3_RGT
#define GAMING_4 GAMING_4_LFT, GAMING_4_RGT
