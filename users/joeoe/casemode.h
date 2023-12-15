#pragma once

#include QMK_KEYBOARD_H

bool caps_word_on;
bool last_press_was_space;

// Check whether caps word is on
bool caps_word_enabled(void);
// Enable caps word
void enable_caps_word(void);
// Disable caps word
void disable_caps_word(void);
// Toggle caps word
void toggle_caps_word(void);

// Function to be put in process user
bool process_caps_word(uint16_t keycode, const keyrecord_t *record);

// overrideable function to determine whether the case mode should stop
bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record);
