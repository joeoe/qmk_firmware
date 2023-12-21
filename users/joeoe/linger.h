#pragma once

#include QMK_KEYBOARD_H

uint16_t linger_key;
uint32_t linger_timer;
uint32_t state_reset_timer;

void linger_matrix_scan(void);
void register_linger_key(uint16_t keycode);
void unregister_linger_key(uint16_t keycode);
