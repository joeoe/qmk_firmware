// bools to keep track of the caps word state
static bool caps_word_on = false;
static bool last_press_was_space = false;

// Enable caps word
void enable_caps_word(void) {

    caps_word_on = true;
    last_press_was_space = false;
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
    state_reset_timer = timer_read(); // (re)start timing hold for keyup below
}

// Disable caps word
void disable_caps_word(void) {
    caps_word_on = false;
    if (last_press_was_space) {
        tap_code(KC_BSPC);
    }
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

// Toggle caps word
void toggle_caps_word(void) {
    if (caps_word_on) {
        disable_caps_word();
    }
    else {
        enable_caps_word();
    }
}

// Called from process_record_user. assumes caps_word is on
bool process_caps_word(uint16_t keycode, const keyrecord_t *record) {

    // Filter out the actual keycode from MT and LT keys.
    // This isn't working right. need to allow a layer to happen.
/*    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
 #ifdef TAP_DANCE_ENABLE
         case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
 #endif
            if (record->tap.count == 0) // if not tapped yet…
                return true; // do that first
            keycode = keycode & 0xFF; // process the base key
        default:
            break;
    }
*/
    if (record->event.pressed) {
        keycode = keycode & QK_BASIC_MAX; // process the base key
        // check if the case modes have been terminated
        if ((get_mods() != 0)) { // hitting any mod...go handle it
            disable_caps_word();
            return true; // let QMK handle it.
        }
        state_reset_timer = timer_read(); // (re)start timing hold for auto-off delay
        switch (keycode) {
            case KC_1 ... KC_0: // let these pass through
            case KC_MINS:
            case KC_UNDS:
            case KC_BSPC:
            case KC_RIGHT ... KC_LEFT:
                last_press_was_space = false;
                return true; // let QMK handle it.
            case KC_SPC:
                if (last_press_was_space) {
                    disable_caps_word();
                    return true; // let QMK handle space normally
                } else {
                        register_code16(KC_UNDS);
                    last_press_was_space = true;
                    return false; // We handled it
                }
                break; // compiler takes this out if necessary?
            case KC_A ... KC_Z: // only works for ASCII. fix this.
                register_code(KC_LSFT); // for platforms that do CAPSLK differently
                register_code(keycode); // like iOS, etc.
                unregister_code(KC_LSFT);
                last_press_was_space = false;
               return false; // We handled it
            }
        disable_caps_word();
        return true;
    } else {
        switch (keycode) {
            case KC_SPC:
                if (last_press_was_space) {
                    unregister_code16(KC_UNDS);
                    return false; // We handled it
                }
        }
    } // end if event.pressed
    return true; // keep processing
}
