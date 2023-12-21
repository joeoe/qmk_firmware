#include "joeoe.h"
#include "quantum.h"
#include "linger.h"

extern uint8_t saved_mods;

uint16_t linger_key        = 0; // keycode for linger actions (ex. "Qu")
uint32_t linger_timer      = 0; // time to hold a key before something else happens.
uint32_t state_reset_timer = 0; // time to leave a state active before shutting it down automatically.

void linger_matrix_scan() {
    if (state_reset_timer) {
        // if (caps_word_on) { // caps_word mode on, (no mods) check if it needs to be cleared
        //     //     if (timer_elapsed(state_reset_timer) > STATE_RESET_TIME * 3) {// caps time over?
        //     //         disable_caps_word(); // turn off all open states
        //     //         state_reset_timer = 0;
        //     //     }
        //     // }

        if (linger_key) {                                    // A linger key is being held down
            if (timer_elapsed(linger_timer) > LINGER_TIME) { // linger triggered
                saved_mods = get_mods();
                clear_mods();
                unregister_mods(MOD_MASK_SHIFT); // second char isn't shifted. CAPSLOCK UNAFFECTED.
                switch (linger_key) {            // only one linger_key at a time, obviously
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
                    case C_GH:
                        tap_code(KC_T);
                        break;
                    case C_CH:
                    case C_WH:
                    case C_PH:
                        tap_code(KC_I);
                        break;
                    case C_SCH:
                        tap_code(KC_O);
                        break;
                    default:
                        break;
                }
                linger_timer = state_reset_timer = 0; // stop lingering
                set_mods(saved_mods);                 // Restore mods
            }
        }
    }
}

void register_linger_key(uint16_t keycode) {
    // register_code16(keycode);
    linger_key   = keycode;
    linger_timer = state_reset_timer = timer_read();
}

void unregister_linger_key(uint16_t keycode) {
    // unregister_code16(keycode);
    linger_key = 0;
}
