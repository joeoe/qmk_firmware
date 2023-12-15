#include "joeoe.h"

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}
void                       keyboard_pre_init_user(void) {
    eeconfig_read_user();
    // if (!user_config.check) {
    //     eeconfig_init_user();
    // }
    keyboard_pre_init_keymap();
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void                       keyboard_post_init_user(void) {
#if defined(CUSTOM_RGBLIGHT)
    keyboard_post_init_rgb_light();
#endif
#if defined(CUSTOM_RGB_MATRIX)
    keyboard_post_init_rgb_matrix();
#endif
#ifdef CUSTOM_UNICODE_ENABLE
    keyboard_post_init_unicode();
#endif

    keyboard_post_init_keymap();
}

__attribute__((weak)) void shutdown_keymap(void) {}
void                       shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb(rgblight_get_val(), 0x00, 0x00);
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(rgb_matrix_get_val(), 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
#ifdef OLED_ENABLE
    oled_off();
#endif

    shutdown_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}
void                       suspend_power_down_user(void) {
#ifdef OLED_ENABLE
    oled_off();
#endif
    suspend_power_down_keymap();
}

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}
void                       suspend_wakeup_init_user(void) {
    suspend_wakeup_init_keymap();
}

extern uint8_t  saved_mods;
extern uint8_t  combo_on;
extern uint16_t linger_key;
extern uint32_t linger_timer;
extern uint32_t state_reset_timer;

// No global matrix scan code, so just run keymap's matrix scan function
__attribute__((weak)) void matrix_scan_keymap(void) {}
void                       matrix_scan_user(void) {
#ifdef COMBO_ENABLE
    // Is a combo_action being held for delayed action/linger combos)?
    if (combo_on) {
        matrix_scan_user_process_combo();
    }
#endif

    if (state_reset_timer) { // is there an active state to check on (caps_word)?

        // if (caps_word_on) { // caps_word mode on, (no mods) check if it needs to be cleared
        //     if (timer_elapsed(state_reset_timer) > STATE_RESET_TIME * 3) {// caps time over?
        //         disable_caps_word(); // turn off all open states
        //         state_reset_timer = 0;
        //     }
        // }

        // prior register_linger_key(kc) needs to be handled here
        //
        if (linger_key && user_config.adaptive_keys) {       // A linger key is being held down
            if (timer_elapsed(linger_timer) > LINGER_TIME) { // linger triggered
                saved_mods = get_mods();
                clear_mods();
                unregister_mods(MOD_MASK_SHIFT); // second char isn't shifted. CAPSLOCK UNAFFECTED.
                switch (linger_key) {            // only one linger_key at a time, obviously
                    case KC_Q:                   // already "Q" has been sent; if lingered, add "u"
                        tap_code(KC_U);
                        break;
                    case KC_LPRN:
                        tap_code16(KC_RPRN);
                        tap_code16(KC_LEFT);
                        break;
                    case KC_LBRC:
                        tap_code16(KC_RBRC);
                        tap_code16(KC_LEFT);
                        break;
                    case KC_LCBR:
                        tap_code16(KC_RCBR);
                        tap_code16(KC_LEFT);
                        break;
                    case KC_LT:
                        tap_code16(KC_GT);
                        tap_code16(KC_LEFT);
                        break;

                        //                     case KC_QUOT: // ‘|’ single paired quotes
                        //                         tap_code16(KC_BSPC);
                        //                         tap_SemKey(SK_SQUL);
                        //                         tap_SemKey(SK_SQUR);
                        //                         tap_code16(KC_LEFT);
                        //                         break;
                        //                     case KC_DQUO: // “|” double paired quotes
                        //                         tap_code16(KC_BSPC);
                        //                         clear_keyboard();  // QMK doesn't let go of shift here?
                        //                         tap_SemKey(SK_SDQL); // “
                        //                         tap_SemKey(SK_SDQR); // ”
                        //                         tap_code(KC_LEFT);
                        //                         break;
                        //                     case SK_FDQL: //  « | » double French quote
                        //                         tap_SemKey(SK_FDQR);
                        //                         goto pushspaceshere;
                        //                     case SK_FSQL: //  ‹ | › single French quote
                        //                         tap_SemKey(SK_FSQR);
                        // pushspaceshere:
                        //                         tap_code(KC_LEFT); // break up 2 dble spc
                        //                         tap_code16(KC_SPACE); // to thwart "smart" EOS.
                        //                         tap_code(KC_LEFT);
                        //                         tap_code16(KC_SPACE);
                        //                         //unregister_SemKey(linger_key);
                        //                         break;

                    default:
                        break;
                }
                linger_timer = state_reset_timer = 0; // stop lingering
                set_mods(saved_mods);                 // Restore mods
            }
        }
    }

    matrix_scan_keymap();
}

// on layer change, no matter where the change was initiated
__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    //     state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    // #if defined(CUSTOM_RGBLIGHT)
    //     state = layer_state_set_rgb_light(state);
    // #endif
    state = layer_state_set_keymap(state);

#ifdef CONSOLE_ENABLE
    char layer_buffer[16 + 5];
    // format_layer_bitmap_string(layer_buffer, state, default_layer_state);
    dprintf("layer state: %s\n", layer_buffer);
#endif

    return state;
}

// Runs state check and changes underglow color and animation
__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) {
    return state;
}
layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (!is_keyboard_master()) {
        return state;
    }

    state = default_layer_state_set_keymap(state);
#if defined(CUSTOM_RGBLIGHT)
    state = default_layer_state_set_rgb_light(state);
#endif

    static bool has_init_been_ran = false;
    // We don't want to run this the first time it's called, since it's read from eeeprom and called
    // as part of the startup process. But after that, it's okay.
    if (has_init_been_ran) {
        eeconfig_update_default_layer(state);
    } else {
        has_init_been_ran = true;
    }

    return state;
}

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}
void                       led_set_user(uint8_t usb_led) {
    led_set_keymap(usb_led);
}

__attribute__((weak)) void eeconfig_init_keymap(void) {}
void                       eeconfig_init_user(void) {
    user_config.raw           = 0;
    user_config.adaptive_keys = true;
    eeconfig_update_user(user_config.raw);
    eeconfig_init_keymap();
}

void eeconfig_init_user_datablock(void) {
#if (EECONFIG_USER_DATA_SIZE) > 4
    uint8_t eeconfig_empty_temp[(EECONFIG_USER_DATA_SIZE)-4] = {0};
    eeconfig_update_user_data(eeconfig_empty_temp);
#endif
}

#ifdef SPLIT_KEYBOARD
__attribute__((weak)) void matrix_slave_scan_keymap(void) {}
void                       matrix_slave_scan_user(void) {
#    ifdef SEQUENCER_ENABLE
    sequencer_task();
#    endif
#    ifdef LED_MATRIX_ENABLE
    led_matrix_task();
#    endif
#    ifdef HAPTIC_ENABLE
    haptic_task();
#    endif

    matrix_slave_scan_keymap();
}
#endif

// Don't know what this does
// __attribute__((weak))
// void housekeeping_task_keymap(void) {}
// void housekeeping_task_user(void) {
//     static bool has_ran_yet;
//     if (!has_ran_yet) {
//         has_ran_yet = true;
//         startup_user();
//     }
// #ifdef TAP_DANCE_ENABLE // Run Diablo 3 macro checking code.
//     run_diablo_macro_check();
// #endif // TAP_DANCE_ENABLE
// #if defined(CUSTOM_RGB_MATRIX)
//     housekeeping_task_rgb_matrix();
// #endif
// #ifdef I2C_SCANNER_ENABLE
//     housekeeping_task_i2c_scanner();
// #endif
// #ifdef CUSTOM_OLED_DRIVER
//     housekeeping_task_oled();
// #endif
// #if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
//     housekeeping_task_transport_sync();
// #endif
//
//     housekeeping_task_keymap();
// }

// __attribute__((weak))
// void process_combo_event_keymap(uint16_t combo_index, bool pressed) {}
// void process_combo_event(uint16_t combo_index, bool pressed) {
//     process_combo_event_keymap(combo_index, pressed);
// }
