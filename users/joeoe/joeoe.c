#include <stdio.h>
#include "joeoe.h"

// Globals
user_config_t user_config;
uint8_t  saved_mods = 0; // to pass state between process_record_user and matrix_scan_user
uint16_t record_keycode = 0; // the keykcode we poke at in process_record
uint16_t key_trap = 0; // the actual keycode registered (need to unregister)
#ifdef ADAPTIVE_ENABLE
uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0; // timer of keydown for adaptive threshhold.
#endif

uint16_t linger_key = 0;  // keycode for linger actions (ex. "Qu")
uint32_t linger_timer = 0; // time to hold a key before something else happens.
uint32_t state_reset_timer = 0;  // time to leave a state active before shutting it down automatically.
bool appmenu_on = false;  // state of windows-like app switcher
bool mods_held = false;  // nood to remember how we entered the appmenu state

#ifdef RGBLIGHT_ENABLE
int RGB_current_mode;
#endif


uint8_t  combo_on = 0;           // for combo actions to hold before triggering
bool  combo_triggered = false;   // for one-shot-combo-actions


// layer_state_t layer_state_set_user(layer_state_t layer_state) {


void keyboard_post_init_user(void) {
    // Read the user config from EEPROM to facilitate
    // appropriate platform support

    // user_config.OSIndex use 0 for Mac; 1 for Win
    user_config.raw = eeconfig_read_user();
    eeconfig_read_default_layer(); // get the default layer from eeprom.
}

#include "semantic.c" // anything could send a semantic, so…first

#ifdef COMBO_ENABLE
#include "combo.c"  // combo processing code (def in keymap)
#endif

#include "casemode.c"

#ifdef ADAPTIVE_ENABLE
#include HD_adaptive_code   // this is HD variation dependent
#endif

// #include HD_process_record_code   // this might need to be HD variation dependent?
#include "process_record.c"

// #include "matrix.c"
