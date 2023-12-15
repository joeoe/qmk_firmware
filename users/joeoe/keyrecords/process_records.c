#include "joeoe.h"
#include "casemode.h"
#include "layermodes.h"
#include "swapper.h"

/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific customization
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

extern bool          sw_win_active;
extern bool          sw_ctrl_active;
extern user_config_t user_config;
extern uint16_t      prior_keycode;
extern uint16_t      prior_keydown;
extern bool          caps_word_on;

extern uint16_t linger_key;
/**
 * @brief Main user keycode handler
 *
 * This handles all of the keycodes for the user, including calling feature handlers.
 *
 * @param keycode Keycode from matrix
 * @param record keyrecord_t data structure
 * @return true Continue processing keycode and send to host
 * @return false Stop process keycode and do not send to host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef KEYLOGGER_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %1d, time: %5u, int: %1d, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    uprintf("keycode: 0x%04X, keycode&QK_BASIC_MAX: 0x%04X \n", keycode, keycode & QK_BASIC_MAX);
#endif

    bool return_state = true;

    update_swapper(&sw_win_active, KC_LALT, KC_TAB, ALT_TAB, keycode, record);
    update_swapper(&sw_ctrl_active, KC_LCTL, KC_TAB, CTRL_TAB, keycode, record);

    if (!process_num_word(keycode, record)) {
        return false;
    }
    // if (!process_tap_hold(keycode, record)) {
    //     return false;
    // }

#ifdef ADAPTIVE_ENABLE
    // Should we handle an adaptive key?  (Semkey may send Adaptive?)
    if (record->event.pressed        // keyup = not rolling = no adaptive -> return.
        && user_config.adaptive_keys // AdaptiveKeys is on
    ) {
        if (!process_adaptive_key(&keycode, record)) {
            prior_keydown = timer_read(); // (re)start prior_key timing
            prior_keycode = keycode;      // this keycode is stripped of mods+taps
            return false;                 // took care of that key
        }
    }
#endif

    // Do we need to filter multi-function keys?
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
#ifdef TAP_DANCE_ENABLE
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
#endif
            if (!record->tap.count)  // if not tapped yet…
                return true;         // let QMK do that first
            keycode &= QK_BASIC_MAX; // mods & taps have been handled.
    }

    if (caps_word_on) {
        if (!process_caps_word(keycode, record)) {
            return false; // took care of that key
        }
    }

    if (!(process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
#ifdef CUSTOM_UNICODE_ENABLE
          && process_record_unicode(keycode, record)
#endif
          && true)) {
        return false;
    }

    // only process for SHIFT/ALT & no CTRL or GUI mods
    // if (saved_mods & MOD_MASK_CG)  // CTRL or GUI/CMD?
    //     return true; // do default if CTRL or GUI/CMD are down

    if (record->event.pressed) {
        switch (keycode) {
            case CLEAR:
                layer_clear();
                return false;
            case K_GRV:
                tap_undead_key(KC_GRAVE);
                break;
            case K_TILD:
                tap_undead_key(KC_TILDE);
                break;
            case K_CIRC:
                tap_undead_key(KC_CIRC);
                break;
            case K_QUOT:
                tap_undead_key(KC_QUOT);
                break;
            case K_DQUO:
                tap_undead_key(KC_DQUO);
                break;
            case ARROW:
                SEND_STRING("->");
                break;
            case NUMWORD:
                enable_num_word();
                break;
            case SAVE_VIM:
                tap_code16(KC_ESC);
                tap_code16(KC_COLN);
                tap_code(KC_W);
                tap_code(KC_ENT);
                break;
            case VIM_SP:
                tap_code16(C(KC_W));
                tap_code(KC_S);
                break;
            case VIM_VS:
                tap_code16(C(KC_W));
                tap_code(KC_V);
                break;

        } // switch (keycode)
#ifdef ADAPTIVE_ENABLE
        prior_keydown = timer_read(); // (re)start prior_key timing
        prior_keycode = keycode;      // this keycode is now stripped of mods+taps
#endif
    } else {               // key up event
        switch (keycode) { // clean up on keyup.
            case KC_J:     //
            case KC_V:     //
            case KC_Z:     //
            case KC_Q:     // for linger Qu (ironically, need to handle this direclty w/o the macros.)
                unregister_code16(keycode);
                linger_key = 0;       // make sure nothing lingers
                                      //                unregister_linger_key();
                return_state = false; // stop processing this record.
                break;
        } // end switch (keycode)
    }     // end key up event

    return return_state; // keep processing record
}

__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_record_keymap(keycode, record);
}
