#pragma once

#include QMK_KEYBOARD_H

#include "alpha/vv-config.h"   // definitions for the alpha layer and mnemonic combos
#include "alpha/vv-adaptive.h" // definitions for the adaptive keys (depends on alpha layer)
#include "layers.h"            // definitions for all the other layers
#include "keyrecords/process_records.h"
#include "callbacks.h"
#include "tap_hold.h"

#ifndef USERSPACE
#    define USERSPACE
#endif
#ifdef LINGER_ENABLE
#    include "linger.h"
#endif

// enum my_layers for layout layers
enum my_layers {
    L_QWERTY, // 0 - QWERTY compatibility layer
    L_HD,     // 1 - Hands Down Alpha layer
    L_SYM,    // 2 - symbols, punctuation, off-map alphas
    L_EXT,    // 3 - extra symbols
    L_FUN,    // 4 - function & number rows
    L_NUM,    // 5 - numpad (right); navpad (left)
    L_NAV,    // 6 - nav pad (right); meta keys (left)
    L_CFG     // 7 - Media/Consumer controls; Keyboard settings
};

void tap_undead_key(uint16_t keycode);
void tap_space_shift(uint16_t keycode);
void double_tap(uint16_t keycode);
void double_tap_space(uint16_t keycode);
void triple_tap(uint16_t keycode);
void double_parens_left(uint16_t left, uint16_t right);
void triple_tap(uint16_t keycode);

bool mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed);
bool mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer);
bool hasAllBitsInMask(uint8_t value, uint8_t mask);
void tap_code16_nomods(uint16_t kc);
void format_layer_bitmap_string(char* buffer, layer_state_t state, layer_state_t default_state);

void linger(uint16_t keycode);
void unlinger(uint16_t keycode);

// Userspace config
typedef union {
    uint32_t raw;
    struct {
        bool adaptive_keys; // Adaptive Keys On? (and advanced combos)
    };
} user_config_t;

_Static_assert(sizeof(user_config_t) == sizeof(uint32_t), "Userspace EECONFIG out of spec.");

extern user_config_t user_config;

void print_user_config(void);
