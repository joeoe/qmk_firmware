#pragma once

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

// #undef COMBO_TERM
// #define COMBO_TERM 22
// All combos are specified from the base layer, saves space
// #define COMBO_ONLY_FROM_LAYER 0

// Pick good defaults for enabling homerow modifiers
#define TAP_CODE_DELAY 10
#define TAP_HOLD_CAPS_DELAY 10
#define PERMISSIVE_HOLD

// #define IGNORE_MOD_TAP_INTERRUPT

#ifdef COMBO_ENABLE
#    ifdef COMBO_COUNT
#        undef COMBO_COUNT
#    endif

#    define COMBO_TERM_PER_COMBO
#    define COMBO_MUST_TAP_PER_COMBO
#    define COMBO_ALLOW_ACTION_KEYS
#    define COMBO_STRICT_TIMER
#    define EXTRA_SHORT_COMBOS
#    ifdef COMBO_TERM
#        undef COMBO_TERM
#    endif
// these COMBO_TERM have dilicate interactions with ADAPTIVE_TERM below.
#    define COMBO_TERM (TAPPING_TERM / 4) // time to get all combo keys down
#    define COMBO_HOLD (TAPPING_TERM)     // time to hold to trigger delayed combo
#endif

#ifdef COMBO_HOLD
#    undef ADAPTIVE_TERM
#    define ADAPTIVE_TERM COMBO_HOLD // use COMBO_HOLD time as a standard threshold (same recation time)
#else
#    define ADAPTIVE_TERM (TAPPING_TERM / 5) // rolling threshold
#endif

// how long to hold before a time-depentant behavior begins
#define LINGER_TIME TAPPING_TERM * 1.2
// how long to leave a state active before resetting like APPMENU or SHIFTWORD
#define STATE_RESET_TIME LINGER_TIME * 3

#define ADAPTIVE_ENABLE
#define ADAPTIVE_TRAILER KC_3

#define UNICODE_KEY_WINC KC_RIGHT_ALT

#define KEYLOGGER_ENABLE
