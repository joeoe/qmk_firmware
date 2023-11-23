#pragma once

#include QMK_KEYBOARD_H

enum layers {
    _BASE,  // default layer
    _SYM,   // symbols
    _NAV,   // system
    _EXT,   // extra symbols!
    _NUM,   // num nums
    _FUN,   // function keys
    _MEDIA, // media keys
    _CTRL,  // keyboard control
    _GAME,
    _GAME2
};

enum custom_keycodes {
    GRV = QK_USER,
    TILD,
    //todo quotes and other dead keys

    ARROW,
    DBL_DASH,

    // Misc
    SAVE_VIM,
    VIM_VS,
    VIM_SP,
    CLOSE_WIN,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    // Smart caps lock and layers that turn off on certain keys
    CAPSWORD,
    NUMWORD,

    // Layer management
    CANCEL,  // Cancel SYMWORD and NUMWORD
    CLEAR,   // Clear all WORD, one-shots and reset to BASE

    TO_NUM,
    TG_GEM,

    // Instant leader key
    LEADER,

    // Instant oneshot mods
    OS_SHFT,
    OS_CTRL,
    OS_RALT,
    OS_ALT,
    OS_GUI,
    OS_CTRL_SHFT,

    // Repeat keys
    REPEAT,
    REV_REP,

    // Swapper
    ALT_TAB,
    CTRL_TAB,

    // common bigram
    QU
};

enum unicode_names {
    SNEK,
    EN_DASH,
    EM_DASH
};

#define xxxxxxx KC_NO
// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_X RALT_T(KC_X)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)
#define HOME_DOT RALT_T(KC_DOT)

// #define MT_SPC KC_SPC
#define MT_SPC LT(_NAV, KC_SPC)

#define C_BSPC C(KC_BACKSPACE)
#define C_TAB C(KC_TAB)
#define SC_TAB S(C(KC_TAB))

#define MT_C_BSPC MT(MOD_LCTL, KC_BSPC)
#define MT_C_QUOT MT(MOD_RCTL, KC_QUOT)
#define LT_NUM_TAB LT(_NUM, KC_TAB)
#define LT_MED_DEL LT(_MEDIA, KC_DEL)

#define FUN OSL(_FUN)
#define SYM OSL(_SYM)
#define EXT OSL(_EXT)
#define NAV OSL(_NAV)

//  #define OS_SHFT OSM(MOD_LSFT)
//     #define OS_CTRL OSM(MOD_LCTL)
//     #define OS_RALT OSM(MOD_RALT)
//     #define OS_ALT OSM(MOD_LALT)
//     #define OS_GUI OSM(MOD_LGUI)
//     #define OS_CTRL_SHFT OSM(MOD_LCTL | MOD_LSFT)

// Colors
// by role
#define CL_BG {141, 153, 174}
#define CL_MOD {237, 242, 244}
#define CL_ACC {239, 35, 60}
#define CL_SEC {132, 144, 165}
#define CL_XXXXX {0,0,0}
#define CL_WARN {230, 57, 70}
// layer colors
#define CL_NAV {169, 222, 249}
#define CL_EXT {17, 138, 178}
#define CL_SYM {6, 214, 160}
#define CL_FUN {255, 209, 102}
#define CL_NUM {239, 71, 111}
#define CL_MED {255, 209, 102}

#define CL_GAM {254, 228, 64}
#define CL_GAM_HL {155, 93,  229}
#define CL_GAM_ALT {155, 93,  229}
#define CL_GAM_ALT_HL {254, 228, 64}
#define CL_GAM_MOD {0,   187, 249}
