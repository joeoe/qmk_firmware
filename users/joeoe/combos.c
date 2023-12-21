#include "joeoe.h"

//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTB │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5

const uint16_t PROGMEM tab_combo[]    = {HD_tab_keys, COMBO_END};    // tab
const uint16_t PROGMEM stab_combo[]   = {HD_stab_keys, COMBO_END};   // shift-tab
const uint16_t PROGMEM spc_combo[]    = {HD_spc_keys, COMBO_END};    // SPACE
const uint16_t PROGMEM enter_combo[]  = {HD_ent_keys, COMBO_END};    // ENTER
const uint16_t PROGMEM center_combo[] = {HD_ent2_keys, COMBO_END};   // hard-ENTER/page break
const uint16_t PROGMEM esc_combo[]    = {HD_LM1, HD_LM4, COMBO_END}; // ESC
const uint16_t PROGMEM undo_combo[]   = {HD_undo_keys, COMBO_END};   // undo
const uint16_t PROGMEM redo_combo[]   = {HD_redo_keys, COMBO_END};   // redo
const uint16_t PROGMEM copy_combo[]   = {HD_copy_keys, COMBO_END};   // copy (hold for cut)
const uint16_t PROGMEM pste_combo[]   = {HD_pste_keys, COMBO_END};   // paste (hold for paste-match)

const uint16_t PROGMEM caps_combo[]     = {HD_LM3, HD_LM2, HD_RM2, HD_RM3, COMBO_END}; // CAPS LOCK
const uint16_t PROGMEM capsword_combo[] = {HD_LM1, HD_LM2, HD_RM1, HD_RM2, COMBO_END}; // CAPS WORD

// const uint16_t PROGMEM ndash_combo[] = {HD_RB0, HD_RB1, COMBO_END}; // – n dash
// const uint16_t PROGMEM mdash_combo[] = {HD_RB0, HD_RB2, COMBO_END}; // — m dash
const uint16_t PROGMEM tild_combo[]  = {HD_RB1, HD_RB4, COMBO_END}; // ~
const uint16_t PROGMEM unds_combo[]  = {HD_RB1, HD_RB3, COMBO_END}; // _
const uint16_t PROGMEM equal_combo[] = {HD_RB2, HD_RB3, COMBO_END}; // =
const uint16_t PROGMEM scln_combo[]  = {HD_RM0, HD_RM1, COMBO_END}; // ;
const uint16_t PROGMEM coln_combo[]  = {HD_RM1, HD_RM2, COMBO_END}; // :
const uint16_t PROGMEM exlm_combo[]  = {HD_RT1, HD_RT2, COMBO_END}; // !
const uint16_t PROGMEM ques_combo[]  = {HD_RT2, HD_RT3, COMBO_END}; // ?
const uint16_t PROGMEM dolr_combo[]  = {HD_RT2, HD_RT4, COMBO_END}; // $
const uint16_t PROGMEM tic_combo[]   = {HD_RT3, HD_RT4, COMBO_END}; // ` tic (not dead key grave)
const uint16_t PROGMEM at_combo[]    = {HD_RT0, HD_RT1, COMBO_END}; // @
// const uint16_t PROGMEM Hgrv_combo[]  = {HD_RM2, HD_RM3, COMBO_END}; // ` grave (dead key)
// const uint16_t PROGMEM Hcirc_combo[] = {HD_RM1, HD_RM3, COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM num_combo[] = {HD_LH1, HD_RH1, COMBO_END};
// Quick access numbers
const uint16_t PROGMEM num_0_combo[] = {HD_RH1, HD_LM2, COMBO_END};
const uint16_t PROGMEM num_2_combo[] = {HD_RH1, HD_LM1, COMBO_END};
const uint16_t PROGMEM num_4_combo[] = {HD_RH1, HD_LM3, COMBO_END};
const uint16_t PROGMEM num_6_combo[] = {HD_RH1, HD_LM4, COMBO_END};
const uint16_t PROGMEM num_8_combo[] = {HD_RH1, HD_LB1, COMBO_END};
const uint16_t PROGMEM num_1_combo[] = {HD_LH1, HD_RM2, COMBO_END};
const uint16_t PROGMEM num_3_combo[] = {HD_LH1, HD_RM1, COMBO_END};
const uint16_t PROGMEM num_5_combo[] = {HD_LH1, HD_RM3, COMBO_END};
const uint16_t PROGMEM num_7_combo[] = {HD_LH1, HD_RM4, COMBO_END};
const uint16_t PROGMEM num_9_combo[] = {HD_LH1, HD_RB1, COMBO_END};

// const uint16_t PROGMEM q_combo[]  = {HD_Qu_keys, COMBO_END}; // TYPE "q" (Qu & Linger deletes u)
const uint16_t PROGMEM qu_combo[] = {HD_Qu_keys, COMBO_END}; // TYPE "q" (Qu & Linger deletes u)
const uint16_t PROGMEM L1_combo[] = {HD_L1_keys, COMBO_END}; // ex. TYPE "z"

const uint16_t PROGMEM th_combo[]  = {HD_Th_keys, COMBO_END};  // TYPE "th"
const uint16_t PROGMEM ch_combo[]  = {HD_Ch_keys, COMBO_END};  // TYPE "ch"
const uint16_t PROGMEM wh_combo[]  = {HD_Wh_keys, COMBO_END};  // TYPE "wh"
const uint16_t PROGMEM sh_combo[]  = {HD_Sh_keys, COMBO_END};  // TYPE "sh"
const uint16_t PROGMEM ph_combo[]  = {HD_Ph_keys, COMBO_END};  // TYPE "ph"
const uint16_t PROGMEM gh_combo[]  = {HD_Gh_keys, COMBO_END};  // TYPE "gh"
const uint16_t PROGMEM sch_combo[] = {HD_Sch_keys, COMBO_END}; // TYPE "Sch"

combo_t key_combos[] = {
    COMBO(scln_combo, KC_SCLN),    // ;
    COMBO(coln_combo, S(KC_SCLN)), // :
    COMBO(unds_combo, S(KC_MINS)), // _
    COMBO(tild_combo, KC_TILD),    // ~
    COMBO(exlm_combo, KC_EXLM),    // !
    COMBO(ques_combo, KC_QUES),    // ?
    COMBO(dolr_combo, KC_DLR),     // $
    COMBO(tic_combo, K_GRV),       // `
    COMBO(at_combo, KC_AT),        // @
    COMBO(tab_combo, KC_TAB),      // tab
    COMBO(stab_combo, S(KC_TAB)),  // shift-tab

    COMBO(qu_combo, C_QU),   // qu
    COMBO(L1_combo, HD_L1),  // z
    COMBO(th_combo, C_TH),   // th
    COMBO(ch_combo, C_CH),   // ch
    COMBO(wh_combo, C_WH),   // wh
    COMBO(sh_combo, C_SH),   // sh
    COMBO(ph_combo, C_PH),   // ph
    COMBO(gh_combo, C_GH),   // gh
    COMBO(sch_combo, C_SCH), // sch

    COMBO(num_combo, NUMWORD),

    COMBO(esc_combo, KC_ESC),        // ESCape
    COMBO(caps_combo, KC_CAPS),      // CAPS LOCK
    COMBO(capsword_combo, CAPSWORD), // CAPS_WORD

    // COMBO(Hndsh_combo), // – N-DASH
    // COMBO(Hmdsh_combo), // — M-DASH
    // COMBO(Hgrv_combo),  // ` grave
    // COMBO(Hcirc_combo), // ˆ circumflex

    COMBO(spc_combo, KC_SPC),       // SPACE
    COMBO(enter_combo, KC_ENT),     // ENTER
    COMBO(center_combo, C(KC_ENT)), // hard-ENTER

    COMBO(undo_combo, KC_UNDO),    // undo
    COMBO(redo_combo, S(KC_UNDO)), // shift undo
    COMBO(copy_combo, C_COPY),     // using hold for cut
    COMBO(pste_combo, C_PSTE),     // using hold for paste-match
    COMBO(num_0_combo, KC_0),
    COMBO(num_2_combo, KC_2),
    COMBO(num_4_combo, KC_4),
    COMBO(num_6_combo, KC_6),
    COMBO(num_8_combo, KC_8),
    COMBO(num_1_combo, KC_1),
    COMBO(num_3_combo, KC_3),
    COMBO(num_5_combo, KC_5),
    COMBO(num_7_combo, KC_7),
    COMBO(num_9_combo, KC_9),

};
