/*
 Adaptive Keys
 Called from within process_record_user

 Tailored for HD Vibranium-v (vv)

 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).

 All the goto shenanigans should be resolved after complete migration to STM/RP controllersr
 (not totally possible, as many of my boards have embedded AVR mcus)

 */

#include "vv-adaptive.h"
#include "casemode.h"
#include "joeoe.h"

extern uint16_t prior_keycode;
extern uint16_t prior_keydown;
extern uint8_t  saved_mods;

bool process_adaptive_key(uint16_t *calling_keycode, const keyrecord_t *record) {
    bool     return_state = true; // assume we don't do anything.
    uint16_t keycode      = *calling_keycode;

    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM || ((keycode == KC_SLSH) && (timer_elapsed(prior_keydown) > ADAPTIVE_TERM * 16))) {
        prior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true;                       // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    if (!caps_word_on) {                 // turn off shift, (first-words & Proper nouns)
        unregister_mods(MOD_MASK_SHIFT); // CAPS_WORD/LOCK won't be affected.
    }                                    // may want more granular control than this…

    // custom keycodes & QK_BASIC_MAX do not result in their desired keycodes
    // i.e. K_DQUO & QK_BASIC_MAX !== KC_DQUO
    // TODO find better solution
    switch (keycode) {
        case K_DQUO:
            switch (prior_keycode) {
                case KC_B:
                    tap_code(KC_Y);
                    return false;
                case KC_DOT:
                    send_string("edu");
                    return false;
            }
            break;
        case K_QUOT:
            switch (prior_keycode) {
                case KC_DOT:
                    send_string("com");
                    return false;
                case KC_QUOT:
                case KC_B:
                    tap_code(KC_O);
                    return false;
            }
            break;
    }

    switch (keycode & QK_BASIC_MAX) { // process ignoring multi-function keys
        case KC_G:
            switch (prior_keycode) {
                case KC_W:
                    tap_code(KC_BSPC);
                    send_string("lml");   // for "calmly" but not quite intuitive…
                    return_state = false; // done.
                    break;
                case KC_J:
                    tap_code(KC_P); // yields jpg
                    break;
                case KC_K:
                    goto PullUpLAndExit; // short jumps save bytes
                case KC_M:
                    goto ReplacePriorWithL;
            }
            break;
        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_G: // pull up "L" (GL is 5x more common than GM)
                case KC_C: // rolling "xwm" is captured here, resulting in "xcl" (taking a trigram that would step down a row at each letter, and making it a simple inward roll, replacing a trigram that does not appear in Mayzner's corpus = infinite win)
                case KC_X: // pull up "L" (XL is 1.5x more common than XM)
                PullUpLAndExit:
                    tap_code(KC_L);       // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_W:                   // WM = LM (LM 20x more common)
                    *calling_keycode = KC_L; // tricksy - pretend the last was L, for "lml"
                ReplacePriorWithL:
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break;
            }
            break;
        case KC_D:                   // (for KD=KL; least code, no side effects)
            switch (prior_keycode) { //
                case KC_K:
                    goto PullUpLAndExit; // short jumps save bytes
            }
            break;

        case KC_L: // catch this so we can unshift L on these rolls.
            switch (prior_keycode) {
                case KC_S:               //
                    goto PullUpLAndExit; // no change except shift is now off
            }
            break;
        case KC_W:
            switch (prior_keycode) {
                case KC_M:               // eliminate SFB (modest 7x gain)
                case KC_L:               // tricksy - trilling "wmw" results in "lml" trigram instead of SFB
                    goto PullUpLAndExit; // short jumps save bytes
                case KC_G:
                    tap_code(KC_D);       // eliminate SFB.
                    return_state = false; // done.
                    break;
                case KC_X:                   // XC is 117x more common than XW (also set up "xc"+l)
                    *calling_keycode = KC_C; // tricksy - pretend the last was C, for "xcl"
                    tap_code(KC_C);          // eliminate row step.
                    return_state = false;    // done.
                    break;
            }
            break;
        case KC_F:
            switch (prior_keycode) {
                case KC_D:                //
                    tap_code(KC_G);       // eliminate SFB (DG is 10x more common than DF)
                    return_state = false; // done.
                    break;
                case KC_V: //
                    tap_code(KC_BSPC);
                    tap_code(KC_S); // avoid row step (311x more common than VF)
                    break;
            }
            break;
        case KC_C:
            switch (prior_keycode) {
                case KC_T:                // roll for tch
                    send_string("ch");    // 85% of tc is tch, so this saves a lot of "H" key presses
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_V:
            switch (prior_keycode) {
                case KC_F: // avoid row step (91x more frequent)
                    tap_code(KC_S);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_K: // remedy ring-index split by shifting fingering
            switch (prior_keycode) {
                case KC_T: // TK/DK/GK = CK (252x more frequent)
                    tap_code(KC_BSPC);
                    tap_code(KC_C);
                    break;
                case KC_D:                  // DK = LK (11x more frequent)
                case KC_G:                  // GK = LK (74x more frequent)
                    goto ReplacePriorWithL; // short jumps save bytes
            }
            break;
        case KC_T: // alt fingering remedy for middle-index splits
            switch (prior_keycode) {
                case KC_K: // quickly typing "k?" yields "kn" (+48x)
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_R: // LL is the highest consonant repeat, and it's off home, so eliminate this SFB
            switch (prior_keycode) {
                case KC_L: // quickly typing "lr" yields "ll" (+56x)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_X:
            switch (prior_keycode) {
                case KC_W: // eliminate scissor (2818x gain)
                    goto PullUpLAndExit;
                case KC_M:                // eliminate scissor (107x gain)
                    tap_code(KC_F);       // pull up F from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G:
                    tap_code(KC_T);       // eliminate SFB (778x gain)
                    return_state = false; // done.
                    break;
            }
            break;

            /*
            // right hand adaptives
            */

        case KC_H:                        // H precedes a vowel much more often than it follows (thanks, Ancient Greek!)
            switch (prior_keycode) {      // maybe OK? What about xxR? resulting in a SFB on thumb?
                case KC_A:                // AE is a fraction less common, but I find the EAE trill harder than EAH.
                    tap_code(KC_U);       // "AH" yields "AU" (8x more common, eliminates SFB)
                    return_state = false; // done.
                    break;
                case KC_E:
                    tap_code(KC_O);       // "EH" yields "EO" (1.75:1)
                    return_state = false; // done.
                    break;
                case KC_O:
                    tap_code(KC_E);       // "OH" yields "OE" (almost 1:1, but eliminates an SFB)
                    return_state = false; // done.
                    break;
                case KC_U:
                    tap_code(KC_A);       // "UH" yields "UA" (126x more common)
                    return_state = false; // done.
                    break;
                case KC_I:                // avoid row skip on outward pinky roll
                    tap_code(KC_P);       // "IH" yields "IP" (41x more common)
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_P:
            switch (prior_keycode) {
                case KC_Y:                //
                    tap_code(KC_I);       // YP = YI (eliminate SFB on ring finger YI is 37x YF)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_DQUO:
            switch (prior_keycode) {
                case KC_B:                //
                    tap_code(KC_Y);       // BJ = BY (eliminate scissor on ring finger BY is 6x BJ)
                    return_state = false; // done.
                    break;
                case KC_DOT:
                    send_string("edu");
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_QUOT:
            switch (prior_keycode) {
                case KC_DOT:
                    send_string("com");
                    return_state = false; // done.
                    break;
                case KC_QUOT:             //
                case KC_B:                //
                    tap_code(KC_O);       // (eliminate scissor)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_DOT:
            switch (prior_keycode) {
                case KC_QUOT:             // This could be smarter (only after O rolled up)
                case KC_B:                //
                    tap_code(KC_U);       // (eliminate scissor)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_B:
            switch (prior_keycode) {
                case KC_DOT:
                    tap_code(KC_BSPC);
                    send_string(".org");
                    return_state = false; // done.
                    break;
            }
            break;
    }
    if (return_state) { // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);
        prior_keycode = keycode = 0;
    }
    return return_state; //
}
