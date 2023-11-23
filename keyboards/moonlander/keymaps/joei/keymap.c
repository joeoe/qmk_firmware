// #include <stdint.h>
#include <quantum.h>

#include "keycodes.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"
#include "repeat.h"
#include "swapper.h"

#include "keymap_german.h"
#include "g/keymap_combo.h"

const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);

const key_override_t **key_overrides = (const key_override_t *[]){&coln_key_override, NULL};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_moonlander(
        TG_GEM,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5, xxxxxxx,          KC_F13,  KC_6,     KC_7,    KC_8,     KC_9,    KC_0,    xxxxxxx,
        KC_TAB,    KC_MINS, KC_W,    KC_F,    KC_P,   KC_B, SC_TAB,           KC_F14,  KC_J,     KC_L,    KC_U,     KC_Y,    REPEAT,  KC_SCLN,
        MT_C_BSPC, KC_A,    KC_R,    KC_S,    KC_T,   KC_G, C_TAB,            KC_F15,  KC_M,     KC_N,    KC_E,     KC_I,    KC_O,    MT_C_QUOT,
        KC_Z,      KC_UNDS, KC_X,    KC_C,    KC_D,   KC_V,                            KC_K,     KC_H,    KC_COMM,  KC_DOT,  KC_SLSH, REPEAT,
        SYM,       OS_ALT,  OS_SHFT, OS_CTRL, KC_MEH,     LCAG(xxxxxxx),    CLEAR,               xxxxxxx, CAPSWORD, NUMWORD, xxxxxxx, TG(_CTRL),
                                         EXT, MT_SPC, LT(_NUM,KC_TAB),      LT(_MEDIA,KC_DEL), SYM, OS_SHFT
    ),
    [_SYM] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,      _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, DBL_DASH, _______,
        KC_DEL,  KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, GRV,     _______,      _______, KC_PLUS, OS_CTRL, OS_SHFT, OS_ALT,  OS_GUI,  _______,
        _______, KC_RBRC, KC_RCBR, KC_RPRN, KC_DQUO, ARROW,                          xxxxxxx, KC_COLN, KC_EQL,  KC_TILD, KC_BSLS, _______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                                FUN, _______, _______,      _______, CLEAR,   xxxxxxx
    ),
    [_NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,      _______, KC_PSCR, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
        _______, OS_GUI,  OS_ALT,  OS_SHFT, OS_CTRL, _______, _______,      _______, KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, ALT_TAB, C(KC_W), CTRL_TAB, _______,                       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, CLEAR,   _______
    ),
    [_EXT] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, OS_GUI,  OS_ALT,  OS_SHFT, OS_CTRL, _______, _______,      _______, _______, KC_QUES, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______,                        _______, _______, KC_LABK, KC_RABK, _______, _______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                            xxxxxxx, _______, _______,      _______, CLEAR,   FUN
    ),
    [_NUM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_PLUS, KC_ASTR, KC_PERC, _______, _______,      _______, KC_J,    _______, _______, _______, _______, _______,
        _______, KC_6,    KC_4,    KC_0,    KC_2,    NUM_G,   _______,      _______, _______, KC_3,    KC_1,    KC_5,    KC_7,    _______,
        _______, _______, _______, _______, KC_8,    _______,                        KC_K,    KC_9,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, CANCEL,  _______
    ),
    [_FUN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F6,    KC_F4,  KC_F10,  KC_F2,   KC_F12,  _______,      _______, KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,   _______,
        _______, _______, _______, _______, KC_F8,   _______,                        _______, KC_F9,   _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, CLEAR,   _______
    ),
    [_MEDIA] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,      _______, _______, OS_CTRL, OS_SHFT, OS_ALT, OS_GUI,  _______,
        _______, KC_MSTP, KC_MRWD, KC_MPLY, KC_MFFD, _______,                        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, _______, _______
    ),
    [_CTRL] = LAYOUT_moonlander(
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,  xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, RGB_TOG, RGB_MOD, RGB_RMOD, RESET,   xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_SPI, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                        xxxxxxx, RGB_SAD, RGB_HUD, RGB_VAD,  RGB_SPD, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,      xxxxxxx,          xxxxxxx, xxxxxxx, xxxxxxx,  xxxxxxx, _______,
                                            xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, xxxxxxx
    ),
    [_GAME] = LAYOUT_moonlander(
        TG_GEM,    KC_5,      KC_1, KC_2, KC_3,     KC_4,     KC_J,         _______, KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_MINS,
        KC_TAB,    KC_T,      KC_Q, KC_W, KC_E,     KC_R,     KC_I,         _______, KC_Y,    KC_U,    KC_UP,    KC_O,    KC_P,     KC_EQL,
        KC_BSPACE, KC_LSHIFT, KC_A, KC_S, KC_D,     KC_F,     KC_M,         _______, KC_H,    KC_LEFT, KC_DOWN,  KC_RIGHT,KC_ENTER, KC_RSHIFT,
        KC_P,      KC_LCTRL,  KC_Z, KC_X, KC_C,     KC_V,                            KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_RCTRL,
        MO(_GAME2), KC_G,     KC_B, KC_H, KC_LALT,            KC_ESC,       KC_LWIN,          KC_RALT, _______,  _______, _______,  _______,
                                          KC_SPACE, KC_TAB,  KC_ESC,       _______, MO(_GAME2),  KC_SPACE
    ),
    [_GAME2] = LAYOUT_moonlander(
        xxxxxxx, KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______,   KC_N,    _______, KC_U, KC_Y, _______,       _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_LSHIFT, _______, _______, _______, KC_O,    _______,    _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_LCTRL,  KC_J,    KC_K,    KC_L,    _______,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______,   _______, _______, KC_LALT,          _______,    _______,          _______, _______, _______, _______, _______,
                                              _______, _______, _______,    _______, _______, _______
    ),
};
// clang-format on

static uint16_t last_key_up = xxxxxxx;

bool gaming = false;

// Colors
// extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;


void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable = true;
    // debug_matrix   = true;
    // debug_keyboard = true;
    // debug_mouse=true;
    rgb_matrix_enable();
}

// clang-format off
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // column by column, top down, outside in
    [_BASE] = {
        CL_GAM,  CL_SEC,  CL_SEC,  CL_SEC,  CL_SEC,
        CL_SEC,   CL_BG,   CL_ACC,  CL_BG,   CL_SEC,
        CL_SEC,   CL_BG,   CL_ACC,  CL_BG,   CL_SEC,
        CL_SEC,   CL_BG,   CL_ACC,  CL_BG,   CL_SEC,
        CL_SEC,   CL_BG,   CL_ACC,  CL_BG,   CL_MOD,
        CL_SEC,   CL_BG,   CL_BG,   CL_BG,
        CL_SEC,   CL_SEC,  CL_SEC,
        CL_EXT,   CL_NAV,  CL_BG,   CL_MOD,

        CL_SEC,   CL_SEC,  CL_SEC,  CL_SEC , CL_SEC,
        CL_SEC,   CL_BG,   CL_ACC,  CL_BG,   CL_SEC,
        CL_SEC,   CL_BG,   CL_ACC,  CL_BG,   CL_SEC,
        CL_SEC,   CL_BG,   CL_ACC,  CL_BG,   CL_SEC,
        CL_SEC,   CL_BG,   CL_ACC,  CL_BG,   CL_SEC,
        CL_SEC,   CL_BG,   CL_BG,   CL_BG,
        CL_SEC,   CL_SEC,  CL_SEC,
        CL_SYM,   CL_MOD,  CL_BG,   CL_MOD
        },

    [_SYM]   = {
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_SYM,    CL_SYM,    CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_SYM,    CL_SYM,    CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_SYM,    CL_SYM,    CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_SYM,    CL_SYM,    CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_SYM,    CL_SYM,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_FUN,    CL_XXXXX,  CL_XXXXX,  CL_XXXXX,

        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX , CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_MOD,    CL_SYM,    CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_MOD,    CL_SYM,    CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_MOD,    CL_SYM,    CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_MOD,    CL_SYM,    CL_XXXXX,
        CL_XXXXX,  CL_SYM,    CL_SYM,    CL_SYM,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_BG,     CL_XXXXX,  CL_XXXXX
        },

    [_EXT]   = {
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,   CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,   CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,   CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,   CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,   CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,

        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NAV,    CL_NAV,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NAV,    CL_NAV,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NAV,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_FUN,    CL_BG,     CL_XXXXX,  CL_XXXXX
        },

    [_NAV]   = {
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_ACC,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_ACC,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_ACC,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,

        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_NAV,    CL_NAV,    CL_NAV,    CL_XXXXX,
        CL_XXXXX,  CL_NAV,    CL_NAV,    CL_NAV,    CL_XXXXX,
        CL_XXXXX,  CL_NAV,    CL_NAV,    CL_NAV,    CL_XXXXX,
        CL_XXXXX,  CL_NAV,    CL_NAV,    CL_NAV,    CL_XXXXX,
        CL_XXXXX,  CL_NAV,    CL_NAV,    CL_NAV,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_BG,     CL_XXXXX,  CL_XXXXX
        },

    [_NUM] = {
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_NUM,    CL_NUM,    CL_NUM,    CL_XXXXX,
        CL_XXXXX,  CL_NUM,    CL_NUM,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_NUM,    CL_NUM,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,

        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_NUM,    CL_NUM,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_NUM,    CL_XXXXX,
        CL_XXXXX,  CL_NUM,    CL_XXXXX,  CL_NUM,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_BG,     CL_XXXXX,  CL_XXXXX
    },

    [_FUN] = {
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_FUN,    CL_FUN,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,

        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_FUN,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_FUN,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_BG,     CL_XXXXX,  CL_XXXXX
        },

    [_MEDIA] = {
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_NUM,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_NUM,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_NUM,    CL_NUM,    CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,

        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_MOD,    CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_BG,     CL_XXXXX,  CL_XXXXX
        },

    [_CTRL]  = {
        CL_WARN,   CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,

        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_BG,
        CL_XXXXX,  CL_WARN,   CL_BG,     CL_BG,     CL_XXXXX,
        CL_XXXXX,  CL_BG,     CL_BG,     CL_BG,     CL_XXXXX,
        CL_XXXXX,  CL_BG,     CL_BG,     CL_BG,     CL_XXXXX,
        CL_XXXXX,  CL_BG,     CL_BG,     CL_BG,     CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,
        CL_XXXXX,  CL_XXXXX,  CL_XXXXX,  CL_XXXXX
        },

    [_GAME]  = {
        CL_BG,    CL_GAM,   CL_GAM,   CL_GAM,   CL_GAM_ALT,
        CL_GAM,  CL_GAM,   CL_GAM_MOD, CL_GAM_MOD, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM_HL, CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM_HL, CL_GAM_HL, CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM_HL, CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM,

        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM_HL, CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM_HL, CL_GAM_HL, CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM_HL, CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM
        },

    [_GAME2] = {
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,    CL_GAM_ALT,    CL_GAM,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT_HL,  CL_GAM_ALT,    CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT_HL, CL_GAM_ALT_HL,  CL_GAM_ALT,    CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT_HL,  CL_GAM_ALT,    CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,    CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,    CL_GAM_ALT,

        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT
        },
};
// clang-format on

const uint32_t PROGMEM unicode_map[] = {
    [EN_DASH] = 0x2013,
    [EM_DASH] = 0x2014,
    [SNEK] = 0x1F40D,
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        RGB rgb = {
            .r = pgm_read_byte(&ledmap[layer][i][0]),
            .g = pgm_read_byte(&ledmap[layer][i][1]),
            .b = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!rgb.r && !rgb.g && !rgb.b) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (!keyboard_config.rgb_matrix_enable) { return; }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        case 6:
            set_layer_color(6);
            break;
        case 7:
            set_layer_color(7);
            break;
        case 8:
            set_layer_color(8);
            break;
        case 9:
            set_layer_color(9);
            break;
        case 10:
            set_layer_color(10);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
            return true;
        default:
            return false;
    }
}

bool tap_undead_key(bool key_down, uint16_t code) {
    if (key_down) {
        tap_code16(code);
        // tap_code16(KC_SPACE);
    }
    return false;
}

void tap_space_shift(uint16_t key, bool key_down) {
    if (key_down) {
        tap_code16(key);
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
}

void double_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_tap_space(uint16_t keycode) {
    tap_code16(KC_SPC);
    double_tap(keycode);
    tap_code16(KC_SPC);
}

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    register_key_to_repeat(keycode);
}

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_parens_left(uint16_t left, uint16_t right) {
    tap_code16(left);
    tap_code16(right);
    tap_code16(KC_LEFT);
}

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // case REPEAT:
        // case REV_REP:
        //     return false;
        // Keycodes to ignore (don't disable caps word)
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case QU:
        // case EM_DASH:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        case REPEAT:
        case REV_REP:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            }
            break;
        default:
            if (record->event.pressed) {
                return true;
            }
            break;
    }
    return false;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        // case MT_SPC:
        case SYM:
        case NAV:
        case FUN:
        case EXT:
        case LT(_MEDIA, KC_DEL):
        case CLEAR:
        case OS_CTRL_SHFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_gui_state  = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_pre(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_pre(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_pre(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_post(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_post(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_post(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
}

bool tap_hold(uint16_t keycode) {
    switch (keycode) {
        case KC_DQUO:
        case KC_LABK:
        case KC_RABK:
        case KC_UNDS:
        case KC_DOT:
        case GRV:
        case KC_PIPE:
        case KC_AMPR:
        case KC_EQL:
        case KC_LPRN:
        case KC_LCBR:
        case KC_LBRC:
        case KC_PERC:
        case KC_SLSH:
        case KC_BSPC:
        case KC_COMM:
        case QU:
        case DBL_DASH:
        case ARROW:
        case KC_A ... KC_Z:
            return true;
        default:
            return false;
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case QU:
            SEND_STRING("qu");
            return;
        case DBL_DASH:
            send_unicode_string("—");
            return;
        case GRV:
            register_key_to_repeat(keycode);
            tap_undead_key(true, KC_GRV);
            return;
        case ARROW:
            SEND_STRING("=>");
            return;
        default:
            tap16_repeatable(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    disable_caps_word();

    switch (keycode) {
        case KC_LABK:
        case KC_RABK:
        case KC_UNDS:
        case KC_LPRN:
        case KC_LBRC:
        case KC_LCBR:
            double_tap(keycode);
            return;
        case KC_DOT:
        case KC_EQL:
            triple_tap(keycode);
            return;
        case GRV:
            tap_undead_key(true, KC_GRV);
            tap_undead_key(true, KC_GRV);
            tap_undead_key(true, KC_GRV);
            return;
        case KC_PIPE:
        case KC_AMPR:
            double_tap_space(keycode);
            return;
        case QU:
            SEND_STRING("Qu");
            return;
        case DBL_DASH:
            // shifted/held em_dash = en_dash
            send_unicode_string("–");
            return;
        case KC_COMM:
            tap16_repeatable(KC_SCLN);
            return;
        case KC_BSPC:
            tap16_repeatable(C(keycode));
            return;
        case ARROW:
            SEND_STRING("->");
            return;
        default:
            tap16_repeatable(S(keycode));
            // tap16_repeatable(keycode);
    }
}

uint16_t tap_hold_timeout(uint16_t keycode) {
    switch (keycode) {
        // Pinky/slow
        case KC_A:
        case KC_UNDS:
        case KC_6:
        case KC_7:
        case KC_SEMICOLON:
            return TAPPING_TERM + 20;
        // Awkward?
        case QU:
            return TAPPING_TERM + 10;
        default:
            return TAPPING_TERM;
    }
}

// Combos
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // Home-row and other tight combos
        case c_ctrl_l:
        case c_esc:
        case c_tab:
        case c_dquo:
        case c_olon:
        case c_enter:
        case c_quot:
        case c_ctrl_r:
        case c_save:
            return COMBO_TERM;
        // mid way relaxed?
        case capsword:
        case c_bspc:
        case c_equl:
            return COMBO_TERM + 10;

        // Vertical combos, very relaxed
        // case small_left_arrow:
        // case lt_eq:
        // case large_right_arrow:
        // case small_right_arrow:
        // case pipe_to:
        // case sp:
        // case sc_comb:
        // case gt_eq:
        //     return COMBO_TERM + 55;

        // Regular combos, slightly relaxed
        default:
            return COMBO_TERM + 20;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case num:
        case c_z:
        case c_del:
        case c_tab:
        case c_esc:
        case c_dquo:
        case c_olon:
        case c_enter:
        case c_quot:
        case c_save:
        case c_equl:
        case c_bspc:
        case c_q:
        case c_qu:
        case c_ctrl_l:

        case c_0:
        case c_1:
        case c_2:
        case c_3:
        case c_4:
        case c_5:
        case c_6:
        case c_7:
        case c_8:
        case c_9:
        case capsword:
            return false;
        default:
            return true;
    }
}

void enable_gaming_mode(void) {
    gaming = true;
    layer_on(_GAME);
    combo_disable();
}
void disable_gaming_mode(void) {
    gaming = false;
    layer_off(_GAME);
    combo_enable();
}
void toggle_gaming_mode(void) {
    if (layer_state_is(_GAME)) {
        disable_gaming_mode();
    } else {
        enable_gaming_mode();
    }
}

bool sw_win_active  = false;
bool sw_ctrl_active = false;

bool is_swapper_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        case OS_SHFT:
            return true;
        default:
            return false;
    }
}

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
                 keycode,
                 record->event.key.row,
                 record->event.key.col,
                 get_highest_layer(layer_state),
                 record->event.pressed,
                 get_mods(),
                 get_oneshot_mods(),
                 record->tap.count
                 );
        }
    #endif

    if (!record->event.pressed) {
        last_key_up = keycode;
    }

    update_swapper(&sw_win_active, KC_LALT, KC_TAB, ALT_TAB, keycode, record);
    update_swapper(&sw_ctrl_active, KC_LCTRL, KC_TAB, CTRL_TAB, keycode, record);

    if (!process_case_modes(keycode, record)) {
        return false;
    }
    if (!process_num_word(keycode, record)) {
        return false;
    }
    if (!gaming) {
        if (!process_tap_hold(keycode, record)) {
            // Extra register here to allow fast rolls without waiting for tap hold,
            // (which will also overwrite this).
            if (record->event.pressed) {
                register_key_to_repeat(keycode);
            }
            return false;
        }
    }

    switch (keycode) {
        case CAPSWORD:
            if (record->event.pressed) {
                toggle_caps_word();
            }
            return false;
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            layer_move(_BASE);
            return false;
        case CANCEL:
            layer_off(_NUM);
            layer_off(_SYM);
            // stop_leading();
            //disable_gaming();
            return false;
        case TILD:
            register_key_to_repeat(TILD);
            return tap_undead_key(record->event.pressed, KC_TILD);
        case TO_NUM:
            layer_on(_NUM);
            return false;
        case TG_GEM:
            if (record->event.pressed) {
                toggle_gaming_mode();
            }
            return false;
        case NUMWORD:
            process_num_word_activation(record);
            return false;
        case SAVE_VIM:
            if (record->event.pressed) {
                tap_code16(KC_ESC);
                tap_code16(KC_COLN);
                tap_code(KC_W);
                tap_code(KC_ENT);
            }
            return false;
        case VIM_SP:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_S);
            }
            return false;
        case VIM_VS:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_V);
            }
            return false;
        case NUM_G:
            if (record->event.pressed) {
                tap_code16(S(KC_G));
            }
            return false;
        case REPEAT:
            // Enable fast UI rolls with repeat key
            end_tap_hold();
            update_repeat_key(record);
            return false;
        case REV_REP:
            update_reverse_repeat_key(record);
            return false;
    }

    return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_oneshot_pre(keycode, record);

    bool res = _process_record_user(keycode, record);

    // If `false` was returned, then we did something special and should register that manually.
    // Otherwise register it here by default.
    // Ignore Space to not interfere with NAV toggling.
    if (res && record->event.pressed && keycode != MT_SPC) {
        register_key_to_repeat(keycode);
    }

    process_oneshot_post(keycode, record);

    return res;
}

void matrix_scan_user(void) { tap_hold_matrix_scan(); }

// layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, SYM, NAV, NUM); }
