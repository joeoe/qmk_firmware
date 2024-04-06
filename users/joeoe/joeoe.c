#include "joeoe.h"
#include "keyrecords/process_records.h"

// Globals
user_config_t user_config;
uint8_t       saved_mods     = 0; // to pass state between process_record_user and matrix_scan_user
uint16_t      record_keycode = 0; // the keykcode we poke at in process_record
uint16_t      key_trap       = 0; // the actual keycode registered (need to unregister)
#ifdef ADAPTIVE_ENABLE
uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0; // timer of keydown for adaptive threshhold.
#endif
#ifdef SWAPPER_ENABLE
bool sw_win_active  = false;
bool sw_ctrl_active = false;
#endif
#ifdef ADAPTIVE_ENABLE
#    include HD_adaptive_code // this is HD variation dependent
#endif

void tap_undead_key(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(KC_SPACE);
}

void tap_space_shift(uint16_t keycode) {
    tap_code16(keycode);
    tap_code(KC_SPC);
    set_oneshot_mods(MOD_BIT(KC_LSFT));
}

void double_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_tap_space(uint16_t keycode) {
    tap_code16(KC_SPC);
    double_tap(keycode);
    tap_code16(KC_SPC);
}

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_parens_left(uint16_t left, uint16_t right) {
    tap_code16(left);
    tap_code16(right);
    tap_code16(KC_LEFT);
}

/**
 * @brief Handle registering a keycode, with optional modifer based on timed event
 *
 * @param code keycode to send to host
 * @param mod_code modifier to send with code, if held for tapping term or longer
 * @param pressed the press/release event (can use "record->event.pressed" for this)
 * @return true exits function
 * @return false exits function
 */
bool mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed) {
    static uint16_t this_timer;
    mod_key_press(code, mod_code, pressed, this_timer);
    return false;
}

/**
 * @brief Handle registation of keycode, with optional modifier based on custom timer
 *
 * @param code keycode to send to host
 * @param mod_code modifier keycode to send with code, if held for tapping term or longer
 * @param pressed the press/release event
 * @param this_timer custom timer to use
 * @return true
 * @return false
 */
bool mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer) {
    if (pressed) {
        this_timer = timer_read();
    } else {
        if (timer_elapsed(this_timer) < TAPPING_TERM) {
            tap_code(code);
        } else {
            register_code(mod_code);
            tap_code(code);
            unregister_code(mod_code);
        }
    }
    return false;
}

/**
 * @brief Performs exact match for modifier values
 *
 * @param value the modifer varible (get_mods/get_oneshot_mods/get_weak_mods)
 * @param mask the modifier mask to check for
 * @return true Has the exact modifiers specifed
 * @return false Does not have the exact modifiers specified
 */
bool hasAllBitsInMask(uint8_t value, uint8_t mask) {
    value &= 0xF;
    mask &= 0xF;

    return (value & mask) == mask;
}

/**
 * @brief Tap keycode, with no mods
 *
 * @param kc keycode to use
 */
void tap_code16_nomods(uint16_t kc) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_code16(kc);
    set_mods(temp_mod);
}

bool is_swapper_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case KC_LSFT:
        case KC_RSFT:
        case OS_SHFT:
            return true;
        default:
            return false;
    }
}

void print_user_config() {
#ifdef KEYLOGGER_ENABLE
    uprintf("user_config: adaptive_keys=%s \n", user_config.adaptive_keys ? "true" : "false");
#endif
}

// Register keys for tap_hold
bool tap_hold(uint16_t keycode) {
    switch (keycode) {
        case C_TH:
        case C_SH:
        case C_PSTE:
        case C_COPY:
        case K_GRV:
        case ARROW:
            return true;
        default:
            return false;
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case C_TH:
            tap_code(KC_T);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code(KC_H);
            return;
        case C_SH:
            tap_code(KC_S);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code(KC_H);
            return;
        case C_PSTE:
            tap_code(KC_PASTE);
            return;
        case C_COPY:
            tap_code(KC_COPY);
        case ARROW:
            SEND_STRING("->");
            break;
        case K_GRV:
            tap_undead_key(KC_GRAVE);
            break;

        default:
            tap_code16(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    switch (keycode) {
        case C_TH: // TION = by far most common 4-gram, (then THAT/THER/WITH/MENT)
            tap_code(KC_T);
            unregister_mods(MOD_MASK_SHIFT);
            send_string("ion");
            break;
        case C_SH:
            tap_code(KC_S);
            unregister_mods(MOD_MASK_SHIFT);
            send_string("ion");
            return;
        case C_PSTE:
            tap_code16(S(KC_PASTE));
            return;
        case C_COPY:
            tap_code(KC_CUT);
        case ARROW:
            SEND_STRING("=>");
            break;
        case K_GRV:
            tap_undead_key(KC_GRAVE);
            tap_undead_key(KC_GRAVE);
            tap_undead_key(KC_GRAVE);
            break;

        default:
            tap_code16(keycode);
    }
}

void linger(uint16_t keycode) {
#ifdef LINGER_ENABLE
    register_linger_key(keycode);
#endif
}

void unlinger(uint16_t keycode) {
#ifdef LINGER_ENABLE
    unregister_linger_key(keycode);
#endif
}
