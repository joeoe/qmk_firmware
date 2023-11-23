#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 170

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

#undef COMBO_TERM
#define COMBO_TERM 30
#define COMBO_TERM_PER_COMBO
#define COMBO_MUST_TAP_PER_COMBO
// All combos are specified from the base layer, saves space
// #define COMBO_ONLY_FROM_LAYER 0

#define USB_SUSPEND_WAKEUP_DELAY 0
// #define FIRMWARE_VERSION u8"yBMoJ/QgeOm"
#define RGB_MATRIX_STARTUP_SPD 60

#define UNICODE_SELECTED_MODES UC_WINC
