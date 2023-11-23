// #include <stdint.h>
#include <quantum.h>

#include "keycodes.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_GAME] = LAYOUT_moonlander(
        KC_ESC,    KC_5,      KC_1,    KC_2,    KC_3,     KC_4,     KC_J,         _______, KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_MINS,
        KC_TAB,    KC_T,      KC_Q,    KC_W,    KC_E,     KC_R,     KC_I,         _______, KC_Y,    KC_U,    KC_UP,    KC_O,    KC_P,     KC_EQL,
        KC_TAB,    KC_LSHIFT, KC_A,    KC_S,    KC_D,     KC_F,     KC_M,         _______, KC_H,    KC_LEFT, KC_DOWN,  KC_RIGHT,KC_ENTER, KC_RSHIFT,
        KC_P,      KC_LCTRL,  KC_Z,    KC_X,    KC_C,     KC_V,                            KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_RCTRL,
        MO(_GAME2), KC_G,     KC_LBRC, KC_RBRC, KC_LALT,          KC_ESC,       KC_LWIN,          KC_RALT, _______,  _______, _______,  _______,
                                               KC_SPACE,  KC_B,  KC_SCLN,       _______, MO(_GAME2),  KC_SPACE
    ),
    [_GAME2] = LAYOUT_moonlander(
        xxxxxxx, KC_F5,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET,
        _______, KC_DOT,    KC_N,    _______, KC_U,    KC_Y, _______,       _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_LSHIFT, _______, _______, _______, KC_O,    _______,    _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_LCTRL,  KC_J,    KC_K,    KC_L,    _______,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______,   _______, _______, KC_LALT,          _______,    _______,          _______, _______, _______, _______, _______,
                                              _______, _______, _______,    _______, _______, _______
    ),
};
// clang-format on

// Colors
// extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable = true;
    // debug_matrix   = true;
    // debug_keyboard = true;
    // debug_mouse=true;
    rgb_matrix_enable();
}

// clang-format off
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // column by column, top down, outside in
    [_GAME]  = {
        CL_WARN,    CL_GAM,   CL_GAM,   CL_GAM,   CL_GAM_ALT,
        CL_GAM,  CL_GAM,   CL_GAM_MOD, CL_GAM_MOD, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM_HL, CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM_HL, CL_GAM_HL, CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM_HL, CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM,

        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM_HL, CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM_HL, CL_GAM_HL, CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM_HL, CL_GAM, CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,
        CL_GAM,  CL_GAM,   CL_GAM,   CL_GAM
        },

    [_GAME2] = {
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,    CL_GAM_ALT,    CL_GAM,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT_HL,  CL_GAM_ALT,    CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT_HL, CL_GAM_ALT_HL,  CL_GAM_ALT,    CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT_HL,  CL_GAM_ALT,    CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,    CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,   CL_GAM_ALT,    CL_GAM_ALT,

        CL_WARN,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,
        CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT,  CL_GAM_ALT
        },
};
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        RGB rgb = {
            .r = pgm_read_byte(&ledmap[layer][i][0]),
            .g = pgm_read_byte(&ledmap[layer][i][1]),
            .b = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!rgb.r && !rgb.g && !rgb.b) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (!keyboard_config.rgb_matrix_enable) { return; }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        case 6:
            set_layer_color(6);
            break;
        case 7:
            set_layer_color(7);
            break;
        case 8:
            set_layer_color(8);
            break;
        case 9:
            set_layer_color(9);
            break;
        case 10:
            set_layer_color(10);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool res = _process_record_user(keycode, record);
    return res;
}

// layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, SYM, NAV, NUM); }
