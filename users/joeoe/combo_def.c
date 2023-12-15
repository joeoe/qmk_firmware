#include "joeoe.h"
#include "combo.h"

//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTB │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5

const uint16_t PROGMEM HC_cfg_combo[] = {HD_RH1, HD_RH2, COMBO_END}; // keyboard settings/config layer
// Spatially arranged on the QWERTY ZXCV locations
const uint16_t PROGMEM Htab_combo[]  = {HD_tab_keys, COMBO_END};    // tab
const uint16_t PROGMEM Hstab_combo[] = {HD_stab_keys, COMBO_END};   // shift-tab
const uint16_t PROGMEM Hspc_combo[]  = {HD_spc_keys, COMBO_END};    // SPACE
const uint16_t PROGMEM Hent_combo[]  = {HD_ent_keys, COMBO_END};    // ENTER
const uint16_t PROGMEM Hent2_combo[] = {HD_ent2_keys, COMBO_END};   // hard-ENTER/page break
const uint16_t PROGMEM F_ESC_combo[] = {HD_LM4, HD_LM1, COMBO_END}; // ESC

const uint16_t PROGMEM Hundo_combo[] = {HD_undo_keys, COMBO_END}; // undo
const uint16_t PROGMEM Hredo_combo[] = {HD_redo_keys, COMBO_END}; // redo
const uint16_t PROGMEM Hcopy_combo[] = {HD_copy_keys, COMBO_END}; // copy (hold for cut)
const uint16_t PROGMEM Hpste_combo[] = {HD_pste_keys, COMBO_END}; // paste (hold for paste-match)

const uint16_t PROGMEM F_CAPS_combo[] = {HD_LM3, HD_LM2, HD_RM2, HD_RM3, COMBO_END}; // CAPS LOCK (on until hit again)
const uint16_t PROGMEM H_CAPW_combo[] = {HD_LM1, HD_LM2, HD_RM1, HD_RM2, COMBO_END}; // CAPS WORD (on until word delimiter)

// RIGHT HAND
const uint16_t PROGMEM Hndsh_combo[]  = {HD_RB0, HD_RB1, COMBO_END}; // – n dash
const uint16_t PROGMEM Hmdsh_combo[]  = {HD_RB0, HD_RB2, COMBO_END}; // — m dash
const uint16_t PROGMEM Htild_combo[]  = {HD_RB1, HD_RB4, COMBO_END}; // ~
const uint16_t PROGMEM Hunds_combo[]  = {HD_RB1, HD_RB3, COMBO_END}; // _
const uint16_t PROGMEM Hequal_combo[] = {HD_RB2, HD_RB3, COMBO_END}; // =

// spatially arranged characters and diacritics
const uint16_t PROGMEM Hscln_combo[] = {HD_RM0, HD_RM1, COMBO_END}; // ;
const uint16_t PROGMEM Hcoln_combo[] = {HD_RT1, HD_RT3, COMBO_END}; // :
const uint16_t PROGMEM Hexlm_combo[] = {HD_RT1, HD_RT2, COMBO_END}; // !
const uint16_t PROGMEM Hques_combo[] = {HD_RT2, HD_RT3, COMBO_END}; // ?
const uint16_t PROGMEM Hdolr_combo[] = {HD_RT2, HD_RT4, COMBO_END}; // $
const uint16_t PROGMEM Htic_combo[]  = {HD_RT3, HD_RT4, COMBO_END}; // ` tic (not dead key grave)

const uint16_t PROGMEM Hat_combo[] = {HD_RT0, HD_RT1, COMBO_END}; // @
// const uint16_t PROGMEM Hgrv_combo[]  = {HD_RM2, HD_RM3, COMBO_END}; // ` grave (dead key)
// const uint16_t PROGMEM Hcirc_combo[] = {HD_RM1, HD_RM3, COMBO_END}; // ˆ circumflex (dead key)

// TEXT ENTRY - off map standard alphas (also on Layer L_SYM @ J & G respectively)
const uint16_t PROGMEM H_Q_combo[]  = {HD_Qu_keys, COMBO_END}; // TYPE "q" (Qu & Linger deletes u)
const uint16_t PROGMEM H_L1_combo[] = {HD_L1_keys, COMBO_END}; // ex. TYPE "z"
// const uint16_t PROGMEM H_L2_combo[] = {HD_L2_keys, COMBO_END}; // ex. TYPE "x"
// const uint16_t PROGMEM H_L3_combo[] = {HD_L3_keys, COMBO_END}; // ex. TYPE "j"

// H digraph combos (ideally, these are phonetically/mnemonically arranged
const uint16_t PROGMEM H_Th_combo[]  = {HD_Th_keys, COMBO_END};  // TYPE "th"
const uint16_t PROGMEM H_Ch_combo[]  = {HD_Ch_keys, COMBO_END};  // TYPE "ch"
const uint16_t PROGMEM H_Wh_combo[]  = {HD_Wh_keys, COMBO_END};  // TYPE "wh"
const uint16_t PROGMEM H_Sh_combo[]  = {HD_Sh_keys, COMBO_END};  // TYPE "sh"
const uint16_t PROGMEM H_Ph_combo[]  = {HD_Ph_keys, COMBO_END};  // TYPE "ph"
const uint16_t PROGMEM H_Gh_combo[]  = {HD_Gh_keys, COMBO_END};  // TYPE "gh"
const uint16_t PROGMEM H_Sch_combo[] = {HD_Sch_keys, COMBO_END}; // TYPE "Sch"

const uint16_t PROGMEM Num_combo[] = {HD_LH1, HD_RH1, COMBO_END};

combo_t key_combos[] = {
    // These simple combos trigger on press, repeat. HC_cfg_combo
    [HC_CFG]  = COMBO(HC_cfg_combo, MO(L_CFG)), // keyboard/media settings/config layer
    [HC_SCLN] = COMBO(Hscln_combo, KC_SCLN),    // ;
    [HC_COLN] = COMBO(Hcoln_combo, S(KC_SCLN)), // :
    [HC_UNDS] = COMBO(Hunds_combo, S(KC_MINS)), // _
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),    // ~
    [HC_EXLM] = COMBO(Hexlm_combo, KC_EXLM),    // !
    [HC_QUES] = COMBO(Hques_combo, KC_QUES),    // ?
    [HC_DOLR] = COMBO(Hdolr_combo, KC_DLR),     // $
    [HC_TIC]  = COMBO(Htic_combo, K_GRV),
    [HC_AT]   = COMBO(Hat_combo, KC_AT), // @
    [HC_TAB]  = COMBO(Htab_combo, KC_TAB),
    [HC_STAB] = COMBO(Hstab_combo, S(KC_TAB)),

    [HC_Q]  = COMBO_ACTION(H_Q_combo),
    [HC_L1] = COMBO(H_L1_combo, HD_L1),
    //    [HC_L2] = COMBO(H_L2_combo, HD_L2),
    //    [HC_L3] = COMBO(H_L3_combo, HD_L3),
    [HC_Ch]  = COMBO_ACTION(H_Ch_combo),
    [HC_Sch] = COMBO_ACTION(H_Sch_combo),
    [HC_Gh]  = COMBO_ACTION(H_Gh_combo),
    [HC_Ph]  = COMBO_ACTION(H_Ph_combo),
    [HC_Th]  = COMBO_ACTION(H_Th_combo),
    [HC_Sh]  = COMBO_ACTION(H_Sh_combo),
    [HC_Wh]  = COMBO_ACTION(H_Wh_combo),

    [C_TO_NUM] = COMBO(Num_combo, NUMWORD),

    // action combos below
    // This group have custom actions on trigger (no hold-delay), repeat if held

    // this block should be contiguous,
    // Delayed action (COMBO_HOLD threshold). No repeat if held (tap_code)
    // should send the underlying combo keys if COMBO_HOLD is not met.

    [FC_ESC]  = COMBO(F_ESC_combo, KC_ESC),   // ESCape
    [FC_CAPS] = COMBO(F_CAPS_combo, KC_CAPS), // CAPS LOCK
    [HC_CAPW] = COMBO_ACTION(H_CAPW_combo),   // CAPS_WORD

    // [HC_NDSH] = COMBO_ACTION(Hndsh_combo), // – N-DASH
    // [HC_MDSH] = COMBO_ACTION(Hmdsh_combo), // — M-DASH

    // [HC_GRV]  = COMBO_ACTION(Hgrv_combo),  // ` grave
    // [HC_CIRC] = COMBO_ACTION(Hcirc_combo), // ˆ circumflex

    [HC_SPC]  = COMBO(Hspc_combo, KC_SPC),     // SPACE
    [HC_ENT]  = COMBO(Hent_combo, KC_ENT),     // ENTER
    [HC_ENT2] = COMBO(Hent2_combo, C(KC_ENT)), // hard-ENTER

    [HC_UNDO] = COMBO(Hundo_combo, KC_UNDO),
    [HC_REDO] = COMBO(Hredo_combo, S(KC_UNDO)),
    [HC_COPY] = COMBO_ACTION(Hcopy_combo), // using hold for cut
    [HC_PSTE] = COMBO_ACTION(Hpste_combo)  // using hold for paste-match
};
