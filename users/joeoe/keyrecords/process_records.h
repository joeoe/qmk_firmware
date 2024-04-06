#pragma once
#include "joeoe.h"

enum userspace_custom_keycodes {
    K_GRV = QK_USER,
    K_TILD,
    K_CIRC,
    K_QUOT,
    K_DQUO,
    K_LBRC,

    // Symbols
    ARROW,
    DBL_DASH,

    SAVE_VIM,
    VIM_VS,
    VIM_SP,

    CLOSE_WIN,

    // Smart caps lock and layers that turn off on certain keys
    CAPSWORD,
    NUMWORD,

    // Layer management
    CANCEL, // Cancel CAPSWORD and NUMWORD
    CLEAR,  // Clear all XWORD, one-shots and reset to BASE

    // Go to NUM layer
    TO_NUM, // Obsolete?

    // Instant processing of G during NUMWORD
    NUM_G,

    // Swapper
    ALT_TAB,
    CTRL_TAB,

    // Default layer cycle
    LAYER_CYCLE,

    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5,

    // Common bigrams
    QU,

    C_TH,
    C_CH,
    C_WH,
    C_SH,
    C_PH,
    C_GH,
    C_SCH,
    C_QU,
    C_COPY,
    C_PSTE,
    C_LNSFT
};

#define xxxxxxx KC_NO

#define C_BSPC C(KC_BACKSPACE)
#define C_TAB C(KC_TAB)
#define SC_TAB S(C(KC_TAB))

// One-shot layers
#define FUN OSL(L_FUN)
#define SYM OSL(L_SYM)
#define EXT OSL(L_EXT)
#define NAV OSL(L_NAV)

// One-shot mods
#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_RALT OSM(MOD_RALT)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_CTRL_SHFT OSM(MOD_LCTL | MOD_LSFT)

// Umlauts
#define KC_UE RALT(KC_Y)
#define KC_OE RALT(KC_P)
#define KC_AE RALT(KC_Q)
#define KC_SS RALT(KC_S)
