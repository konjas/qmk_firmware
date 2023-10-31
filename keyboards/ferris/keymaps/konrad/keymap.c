#include QMK_KEYBOARD_H

enum ferris_layers {
    _BASE,
    _YAPCO,
    _COMBOS_REF,
    _GAME,
    _MOUSE,
    _NAV,
    _SYM_R,
    _SYM_L,
    _FUN,
    _NUM,
    _SHORT,
    _MGMT,
};

enum custom_keycodes {
    KC_VIM_EXIT = SAFE_RANGE,
    KC_VIM_SAVE,
};

enum ferris_tap_dances {
    TD_Q_ESC,
    TD_M_ESC,
    TD_V_X,
    TD_Z_DOT_ACUTE,
};

enum unicode_names {
    POUND,
    EURO,
    LIKE,
};

const uint32_t PROGMEM unicode_map[] = {
    [POUND] = 0xA3,     // £
    [EURO]  = 0x20AC,   // €
    [LIKE]  = 0x1F44D,  // 👍
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x5_2(
        TD(TD_Q_ESC),       KC_W,               KC_F,               KC_P,               KC_G,               KC_J,               KC_L,               KC_U,               KC_Y,               UM(LIKE),
        LSFT_T(KC_A),       LT(_FUN,KC_R),      LT(_MOUSE,KC_S),    LT(_SYM_R,KC_T),    KC_D,               KC_H,               LT(_SYM_L,KC_N),    LT(_NAV,KC_E),      LT(_NUM,KC_I),      RSFT_T(KC_O),
        RALT_T(KC_Z),       LCTL_T(KC_X),       LALT_T(KC_C),       LGUI_T(KC_V),       KC_B,               KC_K,               RGUI_T(KC_M),       LALT_T(KC_COMMA),   RCTL_T(KC_DOT),     RALT_T(KC_SLASH),
                                                                    //KC_DELETE,          LT(_SHORT,KC_BSPC), LT(_MGMT,KC_SPACE), CW_TOGG
                                                                    KC_K,               LT(_SHORT,KC_D),    LT(_MGMT,KC_SPACE), KC_Z
    ),

    [_YAPCO] = LAYOUT_split_3x5_2(
        TD(TD_M_ESC),       KC_L,               KC_F,               KC_P,               TD(TD_V_X),         KC_Q,               KC_B,               KC_U,               KC_O,               KC_Y,
        LSFT_T(KC_W),       LT(_FUN,KC_R),      LT(_MOUSE,KC_S),    LT(_SYM_R,KC_T),    KC_G,               RALT(KC_N),         LT(_SYM_L,KC_N),    LT(_NAV,KC_E),      LT(_NUM,KC_A),      RSFT_T(KC_I),
        KC_C,               LCTL_T(RALT(KC_L)), LALT_T(RALT(KC_O)), LGUI_T(KC_J),       TD(TD_Z_DOT_ACUTE), RALT(KC_C),         RGUI_T(KC_H),       LALT_T(RALT(KC_E)), RCTL_T(RALT(KC_A)), RALT(KC_S),
                                                                    KC_K,               LT(_SHORT,KC_D),    LT(_MGMT,KC_SPACE), KC_Z
    ),

    [_COMBOS_REF] = LAYOUT_split_3x5_2(
        KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,              KC_F6,              KC_F7,              KC_F8,              KC_F9,              KC_F10,
        KC_1,               KC_2,               KC_3,               KC_4,               KC_5,               KC_6,               KC_7,               KC_8,               KC_9,               KC_0,
        KC_P1,              KC_P2,              KC_P3,              KC_P4,              KC_P5,              KC_P6,              KC_P7,              KC_P8,              KC_P9,              KC_P0,
                                                                    KC_A,               KC_B,               KC_C,               KC_D
    ),

    [_GAME] = LAYOUT_split_3x5_2(
        KC_TAB,             KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,               KC_Y,               KC_W,               KC_I,               KC_O,
        KC_LEFT_SHIFT,      KC_A,               KC_S,               KC_D,               KC_F,               KC_G,               KC_D,               KC_A,               KC_S,               KC_L,
        KC_LEFT_CTRL,       KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,               KC_N,               KC_M,               KC_P,               KC_LEFT_ALT,
                                                                    SH_T(KC_ESCAPE),    KC_SPACE,           LT(_MGMT,KC_P0),    XXXXXXX
    ),

    [_MOUSE] = LAYOUT_split_3x5_2(
        _______,            KC_BTN4,            _______,            KC_BTN5,            _______,            KC_BTN4,            KC_BTN1,            KC_BTN3,            KC_BTN2,            KC_BTN5,
        _______,            KC_BTN2,            XXXXXXX,            KC_BTN1,            KC_BTN3,            _______,            KC_MS_L,            KC_MS_D,            KC_MS_U,            KC_MS_R,
        _______,            _______,            _______,            _______,            _______,            _______,            KC_WH_L,            KC_WH_D,            KC_WH_U,            KC_WH_R,
                                                                    _______,            _______,            _______,            _______
    ),

    [_NAV] = LAYOUT_split_3x5_2(
        _______,            _______,            _______,            _______,            _______,            _______,            KC_APPLICATION,     _______,            _______,            _______,
        KC_LEFT,            KC_UP,              KC_DOWN,            KC_RIGHT,           _______,            _______,            LSFT(KC_LEFT_GUI),  XXXXXXX,            LCTL(KC_LALT),      _______,
        KC_HOME,            KC_PGUP,            KC_PGDN,            KC_END,             _______,            _______,            KC_LEFT_GUI,        _______,            _______,            _______,
                                                                    _______,            _______,            _______,            _______
    ),

    [_SYM_R] = LAYOUT_split_3x5_2( 
        _______,            _______,            _______,            _______,            _______,            KC_TILDE,           KC_QUESTION,        KC_EXCLAIM,         KC_PIPE,            KC_GRAVE,
        KC_CIRCUMFLEX,      KC_ASTERISK,        KC_AMPERSAND,       XXXXXXX,            _______,            KC_MINUS,           KC_COMMA,           KC_DOT,             KC_SLASH,           KC_QUOTE,
        _______,            _______,            _______,            _______,            _______,            KC_UNDERSCORE,      KC_SEMICOLON,       KC_COLON,           KC_BACKSLASH,       KC_DOUBLE_QUOTE,
                                                                    _______,            _______,            _______,            _______
    ),

    [_SYM_L] = LAYOUT_split_3x5_2(
        _______,            _______,            _______,            _______,            KC_PLUS,            _______,            _______,            _______,            _______,            UM(POUND),
        KC_LEFT_PAREN,      KC_RIGHT_PAREN,     KC_LCBR,            KC_RCBR,            KC_PERCENT,         _______,            XXXXXXX,            KC_AT,              KC_HASH,            KC_DOLLAR,
        KC_LT,              KC_GT,              KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,   KC_EQUAL,           _______,            _______,            _______,            _______,            UM(EURO),
                                                                    _______,            _______,            _______,            _______
    ),

    [_FUN] = LAYOUT_split_3x5_2(
        _______,            _______,            _______,            _______,            _______,            _______,            KC_F7,              KC_F8,              KC_F9,              KC_F10,
        _______,            XXXXXXX,            LCTL(KC_LALT),      _______,            _______,            _______,            KC_F4,              KC_F5,              KC_F6,              KC_F11,
        _______,            _______,            _______,            _______,            _______,            _______,            KC_F1,              KC_F2,              KC_F3,              KC_F12,
                                                                    _______,            _______,            _______,            _______
    ),

    [_NUM] = LAYOUT_split_3x5_2(
        KC_KP_ASTERISK,     KC_KP_7,            KC_KP_8,            KC_KP_9,            KC_KP_PLUS,         _______,            _______,            _______,            _______,            _______,
        KC_KP_0,            KC_KP_1,            KC_KP_2,            KC_KP_3,            KC_KP_MINUS,        _______,            _______,            _______,            XXXXXXX,            _______,
        KC_KP_SLASH,        KC_KP_4,            KC_KP_5,            KC_KP_6,            KC_KP_EQUAL,        _______,            _______,            _______,            _______,            _______,
                                                                    KC_KP_DOT,          KC_KP_COMMA,        _______,            _______
    ),

    [_SHORT] = LAYOUT_split_3x5_2(
        _______,            _______,            KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,   KC_SYSTEM_SLEEP,    _______,            _______,            _______,            _______,            _______,
        _______,            KC_AUDIO_MUTE,      KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,    KC_SYSTEM_WAKE,     _______,            _______,            _______,            _______,            _______,
        _______,            _______,            _______,            _______,            _______,            _______,            _______,            _______,            _______,            _______,
                                                                    _______,            XXXXXXX,            KC_BACKSPACE,       KC_DELETE
    ),

    [_MGMT] = LAYOUT_split_3x5_2(
        _______,            _______,            _______,            _______,            KC_PRINT_SCREEN,    DF(_YAPCO),         _______,            _______,            _______,            _______,
        _______,            _______,            _______,            KC_ENTER,           KC_INSERT,          DF(_GAME),          CW_TOGG,            _______,            _______,            _______,
        _______,            _______,            _______,            _______,            KC_PAUSE,           DF(_BASE),          _______,            _______,            _______,            _______,
                                                                    LSFT(KC_TAB),       KC_TAB,             XXXXXXX,            _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //case KC_VIM_EXIT:
        //    if (record->event.pressed) {
        //        SEND_STRING("\x1B:q!\n");
        //        return false;
        //    }
        //    break;
        //case KC_VIM_SAVE:
        //    if (record->event.pressed) {
        //        SEND_STRING("\x1B:wq\n");
        //        return false;
        //    }
        //    break;
        case LCTL_T(RALT(KC_L)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RALT(KC_L));
                return false;
            }
            break;
        case LALT_T(RALT(KC_O)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RALT(KC_O));
                return false;
            }
            break;
        case LALT_T(RALT(KC_E)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RALT(KC_E));
                return false;
            }
            break;
        case RCTL_T(RALT(KC_A)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RALT(KC_A));
                return false;
            }
            break;
    }
    return true;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC]       = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC), // Tap once for Q, twice for ESC
    [TD_M_ESC]       = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_ESC), // Tap once for W, twice for ESC
    [TD_V_X]         = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_X), // Tap once for V, twice for X
    [TD_Z_DOT_ACUTE] = ACTION_TAP_DANCE_DOUBLE(RALT(KC_Z), RALT(KC_X)), // Tap once for Ż, twice for Ź
};

uint8_t combo_ref_from_layer(uint8_t layer) {
    switch (get_highest_layer(layer_state)) {
        case _NUM: return _NUM;
        default:   return _COMBOS_REF;
    }
    return layer;
}

enum combo_events {
    BACKSPACE,
    CUT,
    COPY,
    PASTE,
    ENTER,
    VIM_EXIT,
    VIM_SAVE,
};

const uint16_t PROGMEM combo_backspace[]        = {KC_3,   KC_4,   COMBO_END};
const uint16_t PROGMEM combo_cut[]              = {KC_F4,  KC_F5,  COMBO_END};
const uint16_t PROGMEM combo_copy[]             = {KC_4,   KC_5,   COMBO_END};
const uint16_t PROGMEM combo_paste[]            = {KC_P4,  KC_P5,  COMBO_END};
const uint16_t PROGMEM combo_enter[]            = {KC_9,   KC_0,   COMBO_END};
const uint16_t PROGMEM combo_vim_exit[]         = {KC_F1,  KC_F10, COMBO_END};
const uint16_t PROGMEM combo_vim_save[]         = {KC_1,   KC_0,   COMBO_END};

combo_t key_combos[] = {
    [BACKSPACE]   = COMBO(combo_backspace,        KC_BACKSPACE),
    [CUT]         = COMBO(combo_cut,              LCTL(KC_X)),
    [COPY]        = COMBO(combo_copy,             LCTL(KC_C)),
    [PASTE]       = COMBO(combo_paste,            LCTL(KC_V)),
    [ENTER]       = COMBO(combo_enter,            KC_ENTER),
    //[VIM_EXIT]    = COMBO(combo_vim_exit,         KC_VIM_EXIT),
    //[VIM_SAVE]    = COMBO(combo_vim_save,         KC_VIM_SAVE),
};

//void process_combo_event(uint16_t combo_index, bool pressed) {
//    switch(combo_index) {
//        case VIM_EXIT:
//            if (pressed) {
//                SEND_STRING("\x1B:q!\n");
//            }
//            break;
//        case VIM_SAVE:
//            if (pressed) {
//                SEND_STRING("\x1B:wq\n");
//            }
//            break;
//    }
//}
