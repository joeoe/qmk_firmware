#include "casemode.h"
#include "joeoe.h"
#include "keyrecords/process_records.h"

uint16_t        COMBO_LEN = COMBO_LENGTH;
extern uint8_t  saved_mods;
extern uint8_t  combo_on;
extern bool     combo_triggered;
extern uint16_t linger_key;
extern uint32_t linger_timer;

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        switch (combo_index) {
            case PC_STAB ... COMBO_LENGTH: // these may have a hold delay BEFORE triggering
            case HC_AT ... HC_COLN:
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;

            case HC_CAPW:
                toggle_caps_word();
                break;

            case HC_Q:
                if (saved_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) // interested?
                    break;
                tap_code16(KC_Q);                //
                unregister_mods(MOD_MASK_SHIFT); //
                tap_code16(KC_U);                //
                combo_on = combo_index;          // if held, delete 'u' in matrix_scan_user_process_combo
                break;

            // H digraphs
            case HC_Th:
                tap_code(KC_T);         // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Sh:
                tap_code(KC_S);         // send "S" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Wh:
                tap_code(KC_W);         // send "W" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
                /* this conflicts with home row tab, so using adaptive CS -> SC
                            case HC_Sc: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                                tap_code(KC_S); // send "S"
                                unregister_mods(MOD_MASK_SHIFT);  //
                                tap_code(KC_C); // send "C"
                                combo_on = combo_index; // if held, addd 'h' for "Sch" in matrix_scan_user_process_combo
                                break;
                */
            case HC_Sch:                         // to avoid outward roll on ring->pinky fingers moving in unison is easier
                tap_code(KC_S);                  // send "S"
                unregister_mods(MOD_MASK_SHIFT); //
            case HC_Ch:
                tap_code(KC_C);         // send "C" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Gh:
                tap_code(KC_G);         // send "G" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Ph:
                tap_code(KC_P);         // send "P" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;

            case HC_GRV:
                tap_code16(K_GRV);
                break;
            case HC_TILD:
                tap_code16(K_TILD);
                break;
            case HC_CIRC:
                tap_code16(K_CIRC);
                break;

            case HC_UNDS:
                tap_code16(S(KC_MINS));
                break;

            case HC_SS: // ß
                tap_code16(RALT(KC_S));
                break;
            case HC_UE: // Ü
                tap_code16(RALT(KC_Y));
                break;
            case HC_AE: // Ä
                tap_code16(RALT(KC_Q));
                break;
            case HC_OE: // Ö
                tap_code16(RALT(KC_P));
                break;
                // case HC_NDSH:
                //     register_code16(A(KC_MINS)); // should be a semkey
                //     break;
                // case HC_MDSH:
                //     register_code16(A(S(KC_MINS))); // should be a semkey
                //     break;
        }
        if (combo_on) linger_timer = timer_read(); // start timing for linger process
        // should GUARD this with return instead
    } else {
        // *key up* switch, hold threshold not met.
        if (combo_on && !combo_triggered) { // combo NOT triggered in matrix_scan_user_process_combo
            switch (combo_index) {
                // the H digraphs
                case HC_Sch:
                case HC_Ch:
                case HC_Th:
                case HC_Sh:
                case HC_Wh:
                case HC_Gh:
                case HC_Ph:
                    unregister_mods(MOD_MASK_SHIFT);
                    tap_code(KC_H); // send "h" honoring CAPSLK state
                    break;
                case HC_COPY: // not held, so simple copy
                    tap_code16(KC_COPY);
                    break;
                case HC_PSTE: // not held, so simple paste
                    tap_code16(KC_PSTE);
                    break;
                case HC_AT:
                    tap_code16(KC_AT);
                    break;
                case HC_COLN:
                    tap_code16(KC_COLN);
                    break;

                case HC_Q:
                    unregister_code16(KC_Q);
                    linger_key = 0;
                    break;
            } // end switch(combo_index)
        } else {
            // Key up, threshold met, so we'll WRAP-UP the combo action if neccessary.
            // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch (combo_index) {
                // case HC_NDSH:
                //     unregister_code16(A(KC_MINS)); // this should use semkeys
                //     break;
                // case HC_MDSH:
                //     unregister_code16(A(S(KC_MINS))); // this should use semkeys
                //     break;

            } // end switch(combo_index)
        }     // else if (threshold met)
        combo_on = combo_triggered = false;
    } // ELSE IF (pressed) meaning keyup
    return;
}

void matrix_scan_user_process_combo() { // called from matrix_scan_user if combo_on
    // These combos are to be held for COMBO_HOLD term before triggering
    // to avoid accidental triggers while fast typing these common rolls (or on home row).
    // If repeats aren't deemed necessary, use tap_code here, otherwise register_code here
    // and add unregister_code to the !pressed switch in process_combo_event above.
    // Checking combo_triggered above can enable sending untriggered keys
    // and thus allow for longer COMBO_TERM. (recommend < TAPPING_TERM / 2)
    // still, really fast rolls, esp if they can go both ways, are going to be
    // a problem for this (ex er, re; io oi), so maybe best to avoid them as
    // combos. On Hands Down, this means no combos on home row, but that's fine,
    // because home already has modifiers, so it all works out.
    //
    // I've since successfully added COMBO_HOLD Home Row combos without difficulty.
    // To use multiple home row mods, just put them down one at a time...works great.
    //
    if (!combo_triggered) {
        // do simple "on" on held actions and then turn on combo state in process_combo_event above,
        // then handle hold actions here,
        // before resolving in keyup event above.
        // if necessary (like releasing the underlying keys, or other cleanup)
        if ((timer_elapsed(linger_timer) > COMBO_HOLD) && combo_on) {
            saved_mods = get_mods();
            clear_mods();
            switch (combo_on) { // combo_on is global, set in process_combo above
                case HC_COPY:   // held, so cut
                    tap_code16(KC_CUT);
                    break;
                case HC_PSTE: // held, so pastematch
                    tap_code16(S(KC_PSTE));
                    break;

                case HC_Sh: // if these H digragh combos are held, then send T/SION instead
                case HC_Th: // TION = by far most common 4-gram, (then THAT/THER/WITH/MENT)
                    unregister_mods(MOD_MASK_SHIFT);
                    send_string("ion");
                    break;
                case HC_Gh:                          // held, send "ght"
                    unregister_mods(MOD_MASK_SHIFT); //
                    tap_code(KC_H);                  // send "h"
                    tap_code(KC_T);                  // add "t" ("ght" is 55% of all "gh" occurrences)
                    break;
                case HC_Sch:        //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_O); // add "o" // o is the most common after sch
                    break;
                case HC_Ch:                          //
                case HC_Wh:                          //
                case HC_Ph:                          //
                    unregister_mods(MOD_MASK_SHIFT); //
                    tap_code(KC_H);                  // send "h"
                    tap_code(KC_I);                  // add "i"
                    break;
                case HC_COLN:
                    tap_code16(S(KC_SCLN)); // held, so … (this could use semkeys)
                    break;
                case HC_Q:
                    tap_code16(KC_BSPC); // held, so delete u
                    break;

                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
            }
            set_mods(saved_mods);
            combo_triggered = true;
        }
    }
}
