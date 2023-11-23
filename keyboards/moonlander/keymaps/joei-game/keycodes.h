#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
    _GAME,
    _GAME2
};

enum custom_keycodes {
    GRV = ML_SAFE_RANGE,
    // Layer management
    CANCEL,  // Cancel SYMWORD and NUMWORD
    CLEAR,   // Clear all WORD, one-shots and reset to BASE


};

#define xxxxxxx KC_NO
// Miscellaneous keyboard shortcuts in direct access
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

#define CL_GAM {58,  12,  163}
#define CL_GAM_HL {247, 37,  133}
#define CL_GAM_ALT {114, 9,   183}
#define CL_GAM_ALT_HL {76,  201, 240}
#define CL_GAM_MOD {67,  97,  238}
