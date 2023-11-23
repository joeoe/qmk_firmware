#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"
#include "swapper.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_MINS,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, QK_REP,  KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_C_BSPC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,  KC_O, MT_C_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_Z, KC_UNDS,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   EXT, MT_SPC, MT(MOD_MEH, KC_TAB),   LT_MED_DEL, OS_SHFT, SYM
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS,     GRV,                      KC_PLUS, OS_CTRL, OS_SHFT,  OS_ALT,  OS_GUI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_RBRC, KC_RCBR, KC_RPRN, KC_DQUO,   ARROW,                      _______, KC_COLN,  KC_EQL, KC_TILD, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              FUN, _______, _______,    _______,   CLEAR, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_EXT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, RALT(KC_Y), RALT(KC_Q), _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL,  OS_GUI,  OS_ALT,  OS_SHFT, OS_CTRL, _______,                      _______, KC_QUES, KC_LBRC, KC_RBRC, RALT(KC_P) , _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, OS_RALT, _______, _______, _______,                      _______, _______, KC_LABK, KC_RABK, RALT(KC_S), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   CLEAR,     FUN
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______,  _______, _______,                      KC_PSCR, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LSFT,  KC_LCTL, _______,                       KC_INS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, ALT_TAB, C(KC_W), CTRL_TAB, _______,                      KC_NUM, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
  //|--------+--------+--------+--------+---------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _______, _______, _______,    _______,   CLEAR, _______
                                       //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                         KC_J, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_6,    KC_4,    KC_0,    KC_2,   NUM_G,                      _______,    KC_3,    KC_1,    KC_5,    KC_7, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,    KC_8, _______,                         KC_K,    KC_9, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,  CANCEL, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F6,   KC_F4,  KC_F10,   KC_F2,  KC_F12,                       KC_F11,   KC_F3,   KC_F1,   KC_F5,   KC_F7, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,   KC_F8, _______,                      _______,   KC_F9, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,  CANCEL, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,                      _______, OS_CTRL, OS_SHFT, OS_ALT, OS_GUI,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_MSTP, KC_MRWD, KC_MPLY, KC_MFFD, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,  CLEAR, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_CTRL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_TOG, RGB_MOD, RGB_RMOD,  QK_BOOT, xxxxxxx,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_SAI, RGB_HUI, RGB_VAI, RGB_SPI, xxxxxxx,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_SPD, xxxxxxx,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   CLEAR, _______
                                      //`--------------------------'  `--------------------------'
  )
};


const uint32_t PROGMEM unicode_map[] = {
    [EN_DASH] = 0x2013,
    [EM_DASH] = 0x2014,
    [SNEK] = 0x1F40D,
};
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
            return true;
        default:
            return false;
    }
}

bool tap_undead_key(bool key_down, uint16_t code) {
    if (key_down) {
        tap_code16(code);
        tap_code16(KC_SPACE);
    }
    return false;
}

void tap_space_shift(uint16_t key, bool key_down) {
    if (key_down) {
        tap_code16(key);
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
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

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    // register_key_to_repeat(keycode);
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


bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // case REPEAT:
        // case REV_REP:
        //     return false;
        // Keycodes to ignore (don't disable caps word)
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case QU:
        // case EM_DASH:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        // case REPEAT:
        // case REV_REP:
        //     // If mod chording disable the mods
        //     if (record->event.pressed && (get_mods() != 0)) {
        //         return true;
        //     }
        //     break;
        default:
            if (record->event.pressed) {
                return true;
            }
            break;
    }
    return false;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        // case MT_SPC:
        case SYM:
        case NAV:
        case FUN:
        case EXT:
        case LT(_MEDIA, KC_DEL):
        case CLEAR:
        case OS_CTRL_SHFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_gui_state  = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_pre(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_pre(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_pre(&os_alt_state, KC_RALT, OS_RALT, keycode, record);
    update_oneshot_pre(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_post(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_post(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_post(&os_alt_state, KC_RALT, OS_RALT, keycode, record);
    update_oneshot_post(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
}

bool tap_hold(uint16_t keycode) {
    switch (keycode) {
        case KC_DQUO:
        case KC_LABK:
        case KC_RABK:
        case KC_UNDS:
        case KC_DOT:
        case GRV:
        case KC_PIPE:
        case KC_AMPR:
        case KC_EQL:
        case KC_LPRN:
        case KC_LCBR:
        case KC_LBRC:
        case KC_PERC:
        case KC_SLSH:
        case KC_BSPC:
        case KC_COMM:
        case QU:
        // case DBL_DASH:
        case ARROW:
        case KC_A ... KC_Z:
            return true;
        default:
            return false;
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case QU:
            SEND_STRING("qu");
            return;
        // case DBL_DASH:
        //     send_unicode_string("—");
        //     return;
        case GRV:
            tap_undead_key(true, KC_GRV);
            return;
        case ARROW:
            SEND_STRING("=>");
            return;
        default:
            tap16_repeatable(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    disable_caps_word();

    switch (keycode) {
        case KC_LABK:
        case KC_RABK:
        case KC_UNDS:
        case KC_LPRN:
        case KC_LBRC:
        case KC_LCBR:
            double_tap(keycode);
            return;
        case KC_DOT:
        case KC_EQL:
            triple_tap(keycode);
            return;
        case GRV:
            tap_undead_key(true, KC_GRV);
            tap_undead_key(true, KC_GRV);
            tap_undead_key(true, KC_GRV);
            return;
        case KC_PIPE:
        case KC_AMPR:
            double_tap_space(keycode);
            return;
        case QU:
            SEND_STRING("Qu");
            return;
        // case DBL_DASH:
        //     // shifted/held em_dash = en_dash
        //     send_unicode_string("–");
        //     return;
        case KC_COMM:
            tap16_repeatable(KC_SCLN);
            return;
        case KC_BSPC:
            tap16_repeatable(C(keycode));
            return;
        case ARROW:
            SEND_STRING("->");
            return;
        default:
            tap16_repeatable(S(keycode));
            // tap16_repeatable(keycode);
    }
}

uint16_t tap_hold_timeout(uint16_t keycode) {
    switch (keycode) {
        // Pinky/slow
        case KC_A:
        case KC_UNDS:
        case KC_6:
        case KC_7:
        case KC_SEMICOLON:
            return TAPPING_TERM + 20;
        // Awkward?
        case QU:
            return TAPPING_TERM + 10;
        default:
            return TAPPING_TERM;
    }
}

// Combos
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // Home-row and other tight combos
        case c_ctrl_l:
        case c_esc:
        case c_tab:
        case c_dquo:
        case c_olon:
        case c_enter:
        case c_quot:
        case c_ctrl_r:
        case c_save:
            return COMBO_TERM;
        // mid way relaxed?
        case capsword:
        case c_bspc:
        case c_equl:
            return COMBO_TERM + 10;

        // Vertical combos, very relaxed
        // case small_left_arrow:
        // case lt_eq:
        // case large_right_arrow:
        // case small_right_arrow:
        // case pipe_to:
        // case sp:
        // case sc_comb:
        // case gt_eq:
        //     return COMBO_TERM + 55;

        // Regular combos, slightly relaxed
        default:
            return COMBO_TERM + 20;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case num:
        case c_z:
        case c_del:
        case c_tab:
        case c_esc:
        case c_dquo:
        case c_olon:
        case c_enter:
        case c_quot:
        case c_save:
        case c_equl:
        case c_bspc:
        case c_q:
        case c_qu:
        case c_ctrl_l:

        case c_0:
        case c_1:
        case c_2:
        case c_3:
        case c_4:
        case c_5:
        case c_6:
        case c_7:
        case c_8:
        case c_9:
        case capsword:
            return false;
        default:
            return true;
    }
}

bool sw_win_active  = false;
bool sw_ctrl_active = false;

bool is_swapper_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        case OS_SHFT:
            return true;
        default:
            return false;
    }
}


bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
                 keycode,
                 record->event.key.row,
                 record->event.key.col,
                 get_highest_layer(layer_state),
                 record->event.pressed,
                 get_mods(),
                 get_oneshot_mods(),
                 record->tap.count
                 );
        }
    #endif

    update_swapper(&sw_win_active, KC_LALT, KC_TAB, ALT_TAB, keycode, record);
    update_swapper(&sw_ctrl_active, KC_LCTL, KC_TAB, CTRL_TAB, keycode, record);

    if (!process_case_modes(keycode, record)) {
        return false;
    }
    if (!process_num_word(keycode, record)) {
        return false;
    }
    if (!process_tap_hold(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case CAPSWORD:
            if (record->event.pressed) {
                toggle_caps_word();
            }
            return false;
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            layer_move(_BASE);
            return false;
        case CANCEL:
            layer_off(_NUM);
            layer_off(_SYM);
            // stop_leading();
            return false;
        case TO_NUM:
            layer_on(_NUM);
            return false;
        case NUMWORD:
            process_num_word_activation(record);
            return false;
        case SAVE_VIM:
            if (record->event.pressed) {
                tap_code16(KC_ESC);
                tap_code16(KC_COLN);
                tap_code(KC_W);
                tap_code(KC_ENT);
            }
            return false;
        case VIM_SP:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_S);
            }
            return false;
        case VIM_VS:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_V);
            }
            return false;
        case NUM_G:
            if (record->event.pressed) {
                tap_code16(S(KC_G));
            }
            return false;
        // case REPEAT:
        //     // Enable fast UI rolls with repeat key
        //     end_tap_hold();
        //     update_repeat_key(record);
        //     return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_oneshot_pre(keycode, record);

    bool res = _process_record_user(keycode, record);

    process_oneshot_post(keycode, record);

    return res;
}

void matrix_scan_user(void) { tap_hold_matrix_scan(); }
