#include QMK_KEYBOARD_H

// Layers
#define _STD 0
#define _NOS 1
#define _NAV 2
#define _SYM 3
#define _NUM 4
#define _ADJ 5
#define _GAMING 6
#define _GAMING_ONE 7
#define _GAMING_TWO 8

// Layer switching
#define OSL_NAV OSL(_NAV)
#define OSL_SYM OSL(_SYM)
#define OSL_NUM OSL(_NUM)
#define OSL_ADJ OSL(_ADJ)

#define SPC_NAV LT(_NAV, KC_SPACE)

#define DF_STD DF(_STD)
#define DF_NOS DF(_NOS)
#define DF_GAME DF(_GAMING)
#define OSG_ONE OSL(_GAMING_ONE)
#define OSG_TWO OSL(_GAMING_TWO)

// Homerow Mods
#define HM_S MT(MOD_LGUI, KC_S)
#define HM_L MT(MOD_RGUI, KC_L)
#define HM_MICM MT(MOD_LGUI, KC_F20) // F20 mutes the microphone in linux

#define HM_D MT(MOD_LALT, KC_D)
#define HM_K MT(MOD_LALT, KC_K)
#define HM_VOLD MT(MOD_LGUI, KC_VOLD)

#define HM_F MT(MOD_LCTL, KC_F)
#define HM_J MT(MOD_RCTL, KC_J)
#define HM_VOLU MT(MOD_LALT, KC_VOLU)

// Modifiers
#define CAPWTOG QK_CAPS_WORD_TOGGLE
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
#define OS_LSFT OSM(MOD_LSFT)

// International characters
#define OS_RALT OSM(MOD_RALT)

// Macros
enum custom_keycodes {
    MA_MAIL = SAFE_RANGE,
    MA_NAME,
    MA_LINE,
    MA_WORD,
    MA_SRCH,
    MA_DOT,
    MA_QUES,
    MA_DCOL,
    MA_BTAB,
    MA_BHIS,
    MA_SGDH,
    MA_BYE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Cancel oneshot with esc
    if (keycode == KC_ESC && record->event.pressed) {
        bool    rc   = true;
        uint8_t mods = 0;

        if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
            clear_oneshot_mods();
            unregister_mods(mods);
            rc = false;
        }

        if ((mods = get_oneshot_locked_mods())) {
            clear_oneshot_locked_mods();
            unregister_mods(mods);
            rc = false;
        }

        if (is_oneshot_layer_active()) {
            layer_clear();
            rc = false;
        }

        return rc;
    }

    if (keycode == MA_MAIL && record->event.pressed) {
        SEND_STRING("philipp.millar@poxar.net");
        return false;
    }

    if (keycode == MA_NAME && record->event.pressed) {
        SEND_STRING("Philipp Millar");
        return false;
    }

    if (keycode == MA_LINE && record->event.pressed) {
        // Select the line under cursor
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
        return false;
    }

    if (keycode == MA_WORD && record->event.pressed) {
        // Select the word under cursor
        SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
        return false;
    }

    if (keycode == MA_SRCH && record->event.pressed) {
        // Search selection in browser
        SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
        return false;
    }

    if (keycode == MA_DOT && record->event.pressed) {
        // End a sentence and make ready for the next
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT)); // Set one-shot mod for shift.
        return false;
    }

    if (keycode == MA_QUES && record->event.pressed) {
        // End a question and make ready for the next
        SEND_STRING("? ");
        add_oneshot_mods(MOD_BIT(KC_LSFT)); // Set one-shot mod for shift.
        return false;
    }

    if (keycode == MA_DCOL && record->event.pressed) {
        SEND_STRING("::");
        return false;
    }

    if (keycode == MA_BTAB && record->event.pressed) {
        // Search for tabs in browser
        SEND_STRING(SS_LCTL("l") SS_DELAY(100) "% ");
        return false;
    }

    if (keycode == MA_BHIS && record->event.pressed) {
        // Search browser history
        SEND_STRING(SS_LCTL("l") SS_DELAY(100) "^ ");
        return false;
    }

    if (keycode == MA_SGDH && record->event.pressed) {
        // Search browser history
        SEND_STRING("Sehr geehrte Damen und Herren," SS_TAP(X_ENTER) SS_TAP(X_ENTER));
        return false;
    }

    if (keycode == MA_BYE && record->event.pressed) {
        // Search browser history
        SEND_STRING("Mit freundlichen Gr" SS_RALT("ys") "en" SS_TAP(X_ENTER) "Philipp Millar");
        return false;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
    [_STD] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_ESC,  KC_A,    HM_S,    HM_D,    HM_F,    KC_G,       KC_H,    HM_J,    HM_K,    HM_L,    KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       OS_LSFT, OSL_SYM, OSL_NUM,    QK_REP,  SPC_NAV, OS_RALT
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    [_NOS] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_ESC,  KC_A,    HM_S,    HM_D,    HM_F,    KC_G,       KC_H,    HM_J,    HM_K,    HM_L,    KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       OS_LSFT, OSL_SYM, OSL_NUM,    QK_REP,  SPC_NAV, OS_RALT
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    [_NAV] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, XXXXXXX, HM_MICM, HM_VOLD, HM_VOLU, KC_MUTE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            OS_LSFT, KC_DEL,  XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, KC_ENT,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       _______, OSL_ADJ, _______,    _______, _______, _______
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    [_SYM] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,    KC_EQL,  KC_LPRN, KC_RPRN, KC_UNDS, MA_DCOL, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            CAPWTOG, KC_DEL,  XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,    KC_PLUS, KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX, KC_ENT,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       _______, _______, _______,    QK_AREP, OSL_ADJ, _______
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    [_NUM] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,    KC_ASTR, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,    KC_0,    KC_4,    KC_5,    KC_6,    KC_PLUS, KC_EQL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,    KC_SLSH, KC_1,    KC_2,    KC_3,    KC_DOT, KC_ENT,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       DF_GAME, _______, _______,    QK_AREP, KC_SPC,  KC_0
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    [_ADJ] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MA_BTAB,    MA_SRCH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            XXXXXXX, XXXXXXX, MA_SGDH, XXXXXXX, XXXXXXX, XXXXXXX,    MA_BHIS, XXXXXXX, MA_WORD, MA_LINE, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MA_BYE,     MA_NAME, MA_MAIL, XXXXXXX, MA_DOT,  MA_QUES, XXXXXXX,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       DF_NOS,  _______, _______,    _______, _______, QK_BOOT
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    [_GAMING] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       KC_LCTL, KC_SPC, OSG_ONE,     DF_STD,  KC_SPC,  KC_RALT
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    [_GAMING_ONE] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, KC_F20,  XXXXXXX, XXXXXXX, XXXXXXX, KC_I,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       KC_LALT, OSG_TWO, _______,    _______, _______, _______
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    [_GAMING_TWO] = LAYOUT_split_3x6_3(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // └────────┴────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┴────────┴────────┴────────┘
                                       KC_LALT, _______, _______,    _______, _______, _______
        //                            └────────┴────────┴────────┘  └────────┴────────┴────────┘
        ),
    // clang-format off
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_S:
        case HM_L:
            return TAPPING_TERM + 50;

        default:
            return TAPPING_TERM;
    }
}
