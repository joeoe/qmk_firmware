#include "keyrecords/process_records.h"
#include "action.h"
#include "joeoe.h"
#include "casemode.h"
#include "layermodes.h"
#include "quantum.h"
#include "swapper.h"
#include "linger.h"

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
extern uint8_t       saved_mods;

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
    uprintf("kc: 0x%04X, col: %2u, row: %2u, pressed: %1d, time: %5u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time);
#endif

    // print_user_config();

    bool return_state = true;

#ifdef SWAPPER_ENABLE
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, ALT_TAB, keycode, record);
    update_swapper(&sw_ctrl_active, KC_LCTL, KC_TAB, CTRL_TAB, keycode, record);
#endif

#ifdef NUMWORD_ENABLE
    if (!process_num_word(keycode, record)) {
        return false;
    }
#endif

    if (!process_tap_hold(keycode, record)) {
        return false;
    }

#ifdef ADAPTIVE_ENABLE
    // Should we handle an adaptive key?  (Semkey may send Adaptive?)
    if (record->event.pressed        // keyup = not rolling = no adaptive -> return.
        && user_config.adaptive_keys // AdaptiveKeys is on
    ) {
        if (!process_adaptive_key(keycode, record)) {
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
              )) {
        return false;
    }

    // only process for SHIFT/ALT & no CTRL or GUI mods
    if (saved_mods & MOD_MASK_CG) // CTRL or GUI/CMD?
        return true;              // do default if CTRL or GUI/CMD are down

    if (record->event.pressed) {
        switch (keycode) {
            case CLEAR:
                layer_clear();
                return false;
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
            case KG_AB:
                register_code16(KG_A);
                register_code16(KG_B);
                unregister_code16(KG_A);
                unregister_code16(KG_B);
                break;
            case KG_XY:
                register_code16(KG_X);
                register_code16(KG_Y);
                unregister_code16(KG_Y);
                unregister_code16(KG_X);
                break;
            case CTRL_STAB:
                register_code16(KC_LSFT);
                tap_code16(CTRL_TAB);
                unregister_code16(KC_LSFT);
                break;
            case C_LNSFT:
                tap_code16(S(KC_SCLN));
                set_oneshot_mods(MOD_BIT(KC_LSFT));
                break;
#ifdef NUMWORD_ENABLE
            case NUMWORD:
                enable_num_word();
                break;
#endif
#ifdef CASEMODE_ENABLE
            case CAPSWORD:
                enable_caps_word();
                break;
#endif
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

                // case K_GRV:
                //     tap_undead_key(KC_GRAVE);
                //     linger(K_GRV);
                //     break;

            case K_LBRC:
                tap_code(KC_LBRC);
                linger(KC_LBRC);
                break;
            case C_QU:
                tap_code(KC_Q);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_U);
                break;
            case C_GH:
                tap_code(KC_G);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_H);
                linger(C_GH);
                break;
            case C_CH:
                tap_code(KC_C);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_H);
                linger(C_CH);
                break;
            case C_WH:
                tap_code(KC_W);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_H);
                linger(C_WH);
                break;
            case C_PH:
                tap_code(KC_P);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_H);
                linger(C_PH);
                break;
            case C_SCH:
                tap_code(KC_S);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_C);
                tap_code(KC_H);
                linger(C_SCH);
                break;
                // case KG_A:
                //     tap_code16(KC_A);
                //     break;
                // case KG_B:
                //     tap_code16(KC_B);
                //     break;
                // case KG_X:
                //     tap_code16(KC_X);
                //     break;
                // case KG_Y:
                //     tap_code16(KC_Y);
                //     break;
                // case KG_L1:
                //     tap_code16(KC_L);
                //     break;
                // case KG_L2:
                //     tap_code16(KC_M);
                //     break;
                // case KG_L3:
                //     tap_code16(KC_N);
                //     break;
                // case KG_R1:
                //     tap_code16(KC_R);
                //     break;
                // case KG_R2:
                //     tap_code16(KC_S);
                //     break;
                // case KG_R3:
                //     tap_code16(KC_T);
                //     break;
                // case KG_START:
                //     tap_code16(KC_F8);
                //     break;
                // case KG_SELECT:
                //     tap_code16(KC_F9);
                //     break;
                // case KG_HOME:
                //     tap_code16(KC_F10);
                //     break;

        } // switch (keycode)
#ifdef ADAPTIVE_ENABLE
        prior_keydown = timer_read(); // (re)start prior_key timing
        prior_keycode = keycode;      // this keycode is now stripped of mods+taps
#endif
    } else {               // key up event
        switch (keycode) { // clean up on keyup.
            case K_LBRC:
            // case K_GRV:
            case C_GH:
            case C_CH:
            case C_WH:
            case C_PH:
            case C_SCH:
                unlinger(keycode);
                break;

        } // end switch (keycode)
    }     // end key up event

    return return_state; // keep processing record
}

__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_record_keymap(keycode, record);
}
