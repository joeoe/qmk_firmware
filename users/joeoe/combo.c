uint16_t COMBO_LEN = COMBO_LENGTH;

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        switch(combo_index) {
            case PC_STAB ... COMBO_LENGTH:// these may have a hold delay BEFORE triggering
            case HC_AT ... HC_COLN: //
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;

            case HC_CAPW: // turn on capsword (automatically turns off on delimiter)
                toggle_caps_word();
                break;

            case HC_Q: //
                if (saved_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) // interested?
                    break;
                tap_code16(KC_Q); //
                unregister_mods(MOD_MASK_SHIFT);  //
                tap_code16(KC_U); //
                combo_on = combo_index; // if held, delete the 'u' in matrix_scan_user_process_combo
                break;

/*
 * H digraphs here
 */
            case HC_Th: // on first press
                tap_code(KC_T); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Sh:
                tap_code(KC_S); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
           case HC_Wh:
                tap_code(KC_W); // send "W" honoring caps
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
            case HC_Sch: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                tap_code(KC_S); // send "S"
                unregister_mods(MOD_MASK_SHIFT);  //
            case HC_Ch: // not held
                tap_code(KC_C); // send "C" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Gh: // not held
                tap_code(KC_G); // send "G" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Ph:
                tap_code(KC_P); // send "P" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;


            case HC_ACUT:
                tap_code16(A(KC_E)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_GRV:
//                tap_code16(A(KC_NUBS)); // this should use semkeys
                tap_code16(A(KC_GRAVE)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_CIRC:
                 tap_code16(A(KC_6)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_MACR:
                tap_code16(A(KC_A)); // this should use semkeys
                combo_on = combo_index; // may add "o" in matrix_scan_user_process_combo
                break;
            case HC_DIER:
                tap_code16(A(KC_U)); // this should use semkeys
                combo_on = combo_index; // may add "u" in matrix_scan_user_process_combo
                break;
            case HC_RING:
                tap_code16(A(KC_K)); // this should use semkeys
                combo_on = combo_index; // may add "a" for å in matrix_scan_user_process_combo
                break;
            case HC_CEDILLE:
                tap_code16(A(KC_C)); // this should use semkeys
                combo_on = combo_index; // may add "c" in matrix_scan_user_process_combo
                break;
            case HC_ENYE:
                tap_code16(A(KC_N)); // this should use semkeys
                combo_on = combo_index; // may add "n" in matrix_scan_user_process_combo
                break;
            case HC_AE: // Æ
                tap_code16(A(KC_QUOT)); // this should use semkeys
                break;
            case HC_OE: // Œ
                tap_code16(A(KC_Q)); // this should use semkeys
                tap_code16(KC_U); // almost always "œu"
                combo_on = combo_index; // but like qu, we'll take it back if we must.
                break;
/*
            case HC_OSLSH:
                tap_code16(A(KC_O)); // this should use semkeys
                break;
*/
            case HC_NDSH:
                register_code16(A(KC_MINS));  // should be a semkey
                break;
            case HC_MDSH:
                 register_code16(A(S(KC_MINS))); // should be a semkey
                break;
            case HC_UNDS:
                    tap_code16(S(KC_MINS)); // _ underscore (semkey this?)
                break;
        } // end switch (combo_index)
        if (combo_on) linger_timer = timer_read(); // start timing for linger process
        // should GUARD this with return instead
    } else { // end if (pressed) so this is the key up switch, hold threshold not met.
/*
 This is the key up event
*/
        // make this smarter/smaller/faster.
        // lookup keys to output from the key_combos[key_combos] table, bypassing this switch?
        // wrapup the combo and send the underlying keys if necessary
        //
        if (combo_on && !combo_triggered) { // combo NOT triggered in matrix_scan_user_process_combo
            switch(combo_index) {
        // the H digraphs
                case HC_Sch: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                case HC_Ch:
                case HC_Th:
                case HC_Sh:
                case HC_Wh:
                case HC_Gh:
                case HC_Ph:
                    unregister_mods(MOD_MASK_SHIFT);
                    tap_code(KC_H); // send "h" honoring CAPSLK state
                    break;
        // END the H digraphs

                case HC_FIND:  // Simple Find if not held
                    tap_SemKey(SK_FIND);
                    break;
                case HC_NEW:
                    tap_SemKey(SK_NEW);
                    break;
                case HC_COPY: // not held, so simple copy
                    tap_SemKey(SK_COPY);
                    break;
                case HC_PSTE: // not held, so simple paste
                    tap_SemKey(SK_PSTE);
                    break;

                case HC_AT:
                    tap_code16(KC_AT);
                    break;
                case HC_COLN:
                    tap_code16(KC_COLN);
                    break;

                case PC_DASH:
                    tap_code(KC_P1);
                    tap_code(KC_P2);
                    break;
                case PC_TILD:
                    tap_code(KC_P1);
                    tap_code(KC_P3);
                    break;
                case PC_ELIP:
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    break;
                case PC_LPRN:
                    tap_code(KC_P4);
                    tap_code(KC_P5);
                    break;
                case PC_RPRN:
                    tap_code(KC_P5);
                    tap_code(KC_P6);
                    break;
                case PC_COLN:
                    tap_code(KC_P4);
                    tap_code(KC_P6);
                    break;
                case PC_PERC:
                    tap_code(KC_P6);
                    tap_code(KC_PPLS);
                    break;
                case PC_JYEN:
                    tap_code(KC_SLSH);
                    tap_code(KC_7);
                    break;
                case PC_DOLR:
                    tap_code(KC_7);
                    tap_code(KC_8);
                    break;
                case PC_CENT:
                    tap_code(KC_7);
                    tap_code(KC_9);
                    break;
                case PC_EURO:
                    tap_code(KC_8);
                    tap_code(KC_9);
                    break;

                case HC_TYPE_LEFTCOMBO:
                    send_string(LeftComboTapE);
                    break;
                case HC_TYPE_RIGHTCOMBO:
                    send_string(RightComboTapE); // send "Japan" right away
                    break;

                case HC_Q:
                    unregister_code16(KC_Q);
                    linger_key = 0;
                    break;
                case HC_EQL:
                    tap_code16(KC_EQL); // Not held, so…
                    linger_key = 0;
                    break;

            }  // end switch(combo_index)
        } else {
        // Key up, threshold met, so we'll WRAP-UP the combo action if neccessary.
        // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch(combo_index) {
                case HC_NDSH:
                    unregister_code16(A(KC_MINS));  // this should use semkeys
                    break;
                case HC_MDSH:
                    unregister_code16(A(S(KC_MINS)));  // this should use semkeys
                    break;

            }  // end switch(combo_index)
        } // else if (threshold met)
        combo_on = combo_triggered = false;
    } // ELSE IF (pressed) meaning keyup
    return;
}

void matrix_scan_user_process_combo() {  // called from matrix_scan_user if combo_on

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
            switch(combo_on) {  // combo_on is global, set in process_combo above


                case HC_FIND: // Held, so find selection (should work with most apps/platforms)
                    tap_SemKey(SK_COPY); // copy the selection
                    tap_SemKey(SK_FIND); // start find
                    tap_SemKey(SK_PSTE); // paste the copy. will find the selection
//                    tap_code(KC_ENT); // register current find
//                    tap_SemKey(SK_FAGN); // now find the next...
                    break;

                case HC_COPY: // held, so cut
                    tap_SemKey(SK_CUT);
                    break;
                case HC_PSTE: // held, so pastematch
                    tap_SemKey(SK_PSTM);
                    break;


                case HC_Sh: // if these H digragh combos are held, then send T/SION instead
                case HC_Th: // TION = by far most common 4-gram, (then THAT/THER/WITH/MENT)
                    unregister_mods(MOD_MASK_SHIFT);
                    send_string("ion");
                    break;
                case HC_Gh: // held, send "ght"
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_T); // add "t" ("ght" is 55% of all "gh" occurrences)
                    break;
                case HC_Sch: //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_O); // add "o" // o is the most common after sch
                    break;
                case HC_Ch: //
                case HC_Wh: //
                case HC_Ph: //
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_I); // add "i"
                    break;
//                case HC_Sc: //
//                    tap_code(KC_H); // add "h" (for "Sch", since were already on these keys.)
//                    break;
                case HC_AT:
                    send_string(At_ComboHeld);
                    break;
                case HC_COLN:
                    tap_code16(A(KC_SCLN)); // held, so … (this could use semkeys)
                    break;
                case HC_OE:
                case HC_Q:
                    tap_code16(KC_BSPC); // held, so delete u
                    break;
                case HC_EQL:
                    tap_code16(KC_PERC); // Held, so send % (instead of =)
                    break;

                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
                case PC_SENT:
                    tap_code16(S(KC_ENT));
                    break;
                case PC_LPRN:
                    tap_code16(KC_LPRN);
                    break;
                case PC_RPRN:
                    tap_code16(KC_RPRN);
                    break;
                case PC_COLN:
                    tap_code16(KC_COLN);
                    break;
                case PC_PERC:
                    tap_code16(KC_PERC);
                    break;
                case PC_DOLR:
                    tap_code16(S(KC_4));
                    break;
                case PC_TILD:
                    tap_code16(KC_TILD);
                    break;
                case PC_DASH:
                    tap_code16(A(KC_MINS)); // this should use semkeys
                    break;
//                case HC_ELIP:
                case PC_ELIP:
                    tap_code16(A(KC_SCLN)); // this should use semkeys
                    break;
                case PC_EURO:
                    tap_code16(A(S(KC_2))); // this should use semkeys
                    break;
                case PC_CENT:
                    tap_code16(A(KC_4)); // this should use semkeys
                    break;
                case PC_JYEN:
                    tap_code16(A(KC_Y)); // this should use semkeys
                    break;
                case PC_BPND:
                    tap_code16(A(KC_3)); // this should use semkeys
                    break;
                case PC_NEQL:
                    tap_code16(A(KC_EQL)); // this should use semkeys
                    break;
                case PC_DIV:
                    tap_code16(A(KC_SLSH)); // this should use semkeys
                    break;
                case PC_PLMN:
                    tap_code16(A(S(KC_EQL))); // this should use semkeys
                    break;
                case PC_DEG:
                    tap_code16(A(KC_0)); // this should use semkeys
                    break;


    // if lingered, these will followup with the most common composed letter (Latinate language mashup stats)
                case HC_ACUT:
                case HC_GRV:
                case HC_CIRC:
                    tap_code16(KC_E); // this should use semkeys? éêè
                    break;
                case HC_MACR:
                    tap_code16(KC_O); // this should use semkeys? ō
                    break;
                case HC_DIER:
                    tap_code16(KC_U); // this should use semkeys? ü
                    break;
                case HC_RING:
                    tap_code16(KC_A); // this should use semkeys? å
                    break;
                case HC_CEDILLE:
                    tap_code16(KC_C); // this should use semkeys? ç
                    break;
                case HC_ENYE:
                    tap_code16(KC_N); // this should use semkeys? ñ
                    break;


                case HC_TYPE_LEFTCOMBO: // already "LeftComboTap" has been sent; if held, undo and send "LeftComboHeld"
                        send_string(LeftComboHeldE);
                    break;
                case HC_TYPE_RIGHTCOMBO: // already "RightComboTap" has been sent; if held, add "RightComboHeld"

                        send_string(RightComboHeldE);
                    break;

            } // switch
            set_mods(saved_mods); // Restore mods
            combo_triggered = true;
           } //  if (combo_on)
    }
}
