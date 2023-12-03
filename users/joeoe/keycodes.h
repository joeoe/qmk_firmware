#pragma once

enum custom_keycodes {
    GRV = QK_USER,
    TILD,
    // todo quotes and other dead keys

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
    CANCEL, // Cancel SYMWORD and NUMWORD
    CLEAR,  // Clear all WORD, one-shots and reset to BASE

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

    // Swapper
    ALT_TAB,
    CTRL_TAB,

    LAYER_CYCLE,

    // common bigram
    QU
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

#define FUN OSL(L_FUN)
#define SYM OSL(L_SYM)
#define EXT OSL(L_EXT)
#define NAV OSL(L_NAV)

#define KC_UE RALT(KC_Y)
#define KC_OE RALT(KC_P)
#define KC_AE RALT(KC_Q)
#define KC_SS RALT(KC_S)

#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_RALT OSM(MOD_RALT)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_CTRL_SHFT OSM(MOD_LCTL | MOD_LSFT)

