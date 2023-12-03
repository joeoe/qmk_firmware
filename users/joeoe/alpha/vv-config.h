//
// The Hands Down Variation dependent defs & files
//
#define HD_adaptive_code "alpha/vv-adaptive.c"

//
// First, let's define HD alpha keycodes with any hold-taps/custom keycodes
//
#define HD_A RSFT_T(KC_A)
// #define HD_A KC_A
#define HD_B KC_B
#define HD_C RALT_T(KC_C)
// #define HD_C KC_C
#define HD_D KC_D
#define HD_E RGUI_T(KC_E)
// #define HD_E KC_E
#define HD_F KC_F
#define HD_G KC_G
#define HD_H RCTL_T(KC_H)
// #define HD_H KC_H
#define HD_I RALT_T(KC_I)
// #define HD_I KC_I
#define HD_J KC_J
#define HD_K LT(L_NUM,KC_K)
// #define HD_K KC_K
#define HD_L KC_L
#define HD_M KC_M
#define HD_N RGUI_T(KC_N)
// #define HD_N KC_N
#define HD_O KC_O
#define HD_P KC_P
#define HD_Q KC_Q
#define HD_R LT(L_NAV,KC_R)
// #define HD_R KC_R
#define HD_S RCTL_T(KC_S)
// #define HD_S KC_S
#define HD_T RSFT_T(KC_T)
// #define HD_T KC_T
#define HD_U KC_U
#define HD_V KC_V
#define HD_W KC_W
#define HD_X KC_X
#define HD_Y KC_Y
#define HD_Z KC_Z

#define HD_MINS KC_MINS
#define HD_HASH KC_HASH
#define HD_SPC  LT(L_NAV,KC_SPC)
#define HD_BSPC LT(L_FUN,KC_BSPC)
#define HD_ENT  LT(L_NAV,KC_ENT)
#define HD_QUOT KC_QUOT
#define HD_DQUO KC_DQUO
#define HD_SLSH KC_SLSH
#define HD_DOT  KC_DOT
#define HD_COMM LT(L_FUN, KC_COMM)

// Now let's place these HD keycodes on the keymap
// for variation independent spatial referencing by key position
//
//     Key Position Names for a 34 (-54) key split form factor
//        Should cover Ferris through Atreus-Kyria-Ergodox
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTA │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RM0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────╮ LH2 LH1 LH3 │ LH0 LHA  RHA RH0 │ RH3 RH1 RH2 ╭───────╯
//     LH5 LH4 ╰─────────────╯                  ╰─────────────╯ RH4 RH5
//
//
//    Base (alpha) Layer  Hands Down Vibranium-vv (HRMs /+ thumb mods)
//      ╭─────────────────────╮                 ╭─────────────────────╮
// esc  │  X   W   M   G   J  │ L_CFG     L_NUM │  #$  .:  '[  "]   B │ LANG2/henk
// tab  │  S   C   N   T   K  | (             ) |  ,;   A   E   I   H │ LANG1/mhen
//  Z   │  V   F   L   D  /*  │ [ copy   pste ] │  -+   U   O   Y   P │ Q
//      ╰───────╮ bsp  R  ___ │ &             | │ ___  spc ret ╭──────╯
//    left rght ╰─────────────╯                 ╰──────────────╯ tgLN  up  dn
//
// For small boards, Q (LT3) & Z (LT4) are (also) on the sym layer
// and accessible combos (defined below)
//

#define HD_LT5 KC_ESC
#define HD_LT4 HD_X
#define HD_LT3 HD_W
#define HD_LT2 HD_M
#define HD_LT1 HD_G
#define HD_LT0 HD_J
#define HD_LTA OSL(L_CFG)
#define HD_RTA TG(L_NUM)
#define HD_RT0 HD_HASH
#define HD_RT1 HD_DOT
#define HD_RT2 HD_QUOT
#define HD_RT3 HD_DQUO
#define HD_RT4 HD_B
#define HD_RT5 KC_LNG2

#define HD_LM5 KC_TAB
#define HD_LM4 HD_S
#define HD_LM3 HD_C
#define HD_LM2 HD_N
#define HD_LM1 HD_T
#define HD_LM0 HD_K
#define HD_LMA KC_LPRN
#define HD_RMA KC_RPRN
#define HD_RM0 HD_COMM
#define HD_RM1 HD_A
#define HD_RM2 HD_E
#define HD_RM3 HD_I
#define HD_RM4 HD_H
#define HD_RM5 KC_LNG1

#define HD_LB5 HD_Z
#define HD_LB4 HD_V
#define HD_LB3 HD_F
#define HD_LB2 HD_L
#define HD_LB1 HD_D
#define HD_LB0 HD_SLSH
#define HD_LBA LT(L_NUM, KC_LBRC)
#define HD_LBB LT(L_CFG, KC_LNG2)
#define HD_RBB LT(L_FUN, KC_LNG1)
#define HD_RBA LT(L_NAV, KC_RBRC)
#define HD_RB0 HD_MINS
#define HD_RB1 HD_U
#define HD_RB2 HD_O
#define HD_RB3 HD_Y
#define HD_RB4 HD_P
#define HD_RB5 HD_Q

//Primary Thumbs 1-3 (others are unique to the board)
#define HD_LH5 KC_LEFT
#define HD_LH4 LT(L_FUN,KC_MUTE)
// #define HD_LH3 KC_APP
// #define HD_LH2 HD_BSPC
#define HD_LH3 HD_BSPC
#define HD_LH2 OSL(L_FUN)
#define HD_LH1 HD_R
#define HD_LH0 LT(L_CFG,KC_MUTE)
#define HD_LHA LT(L_NAV,KC_LNG2)
#define HD_RHA LT(L_SYM,KC_LNG1)
#define HD_RH0 LT(L_CFG,KC_MPLY)
#define HD_RH1 HD_SPC
#define HD_RH2 OSL(L_SYM)
// #define HD_RH2 HD_ENT
#define HD_RH3 TG(L_NUM)
#define HD_RH4 LT(L_FUN,KC_MPLY)
#define HD_RH5 KC_DN

#ifdef COMBO_ENABLE
//
// We want to be able to define a combo by location
// for variation independent, spatial referencing, or
// by letter for mnemonic/phonetic referencing (variation dependent)
// put this sort of obscures the definitions…so…
//
// BE CAREFUL to not double define a combo!
//
// Combo definitions that rely on phonetics/mnemonics for their locations.
//
// Combos that are spacially organized don't need to be redefined
// to match the base alpha layer, so they are not included here.
//
// These few spatial combos may move to accommodate some mnemonic combos,
// notably the H-digraph combos that inhabit close areas.
//
// SEMANTIC FUNCTIONS  ** uses SemKeys **
// Spatially arranged on the QWERTY ZXCV locations
// independent of the HD Alphas, though since some of
// the above combos may compete for the same locations,
// we'll define them all here.
//
#define HD_new_keys   HD_LM2, HD_LB2   // new
#define HD_open_keys  HD_LM1, HD_LB1   // open
#define HD_close_keys HD_LM3, HD_LB3   // close
#define HD_quit_keys  HD_LB0, HD_LM0   // quit
#define HD_find_keys  HD_LM4, HD_LM0   // find selection
#define HD_sall_keys  HD_LB4, HD_LB1   // select all
#define HD_swrd_keys  HD_LB4, HD_LB0   // select word
#define HD_undo_keys  HD_LB4, HD_LB3   // undo
#define HD_redo_keys  HD_LB4, HD_LB3, HD_LB2   // redo
#define HD_copy_keys  HD_LB3, HD_LB2   // copy (hold for cut)
#define HD_pste_keys  HD_LB2, HD_LB1   // paste (hold for paste-match)

#define HD_tab_keys  HD_LT4, HD_LT3     // tab
#define HD_stab_keys HD_LT4, HD_LT3, HD_LT2  // Shift-tab
#define HD_spc_keys  HD_LM1, HD_LM0     // SPACE
#define HD_ent_keys  HD_LB0, HD_LB1     // ENTER
#define HD_ent2_keys HD_LB0, HD_LB1, HD_LB2 // hard-ENTER/page break
//#define APPMENU_keys  HD_LT1, HD_LT0  // APPMENU

// TEXT ENTRY - off map standard alphas (also on Layer L_SYM @ Z=LT4 & Q=LT3)
//
#define HD_Qu_keys HD_LT3, HD_LT1 // TYPE "q" (Qu & Linger deletes u)
#define HD_L1_keys HD_LM3, HD_LM1 // ex. TYPE "z"
#define HD_L1 HD_Z
//#define HD_L2_keys HD_LM3, HD_LM1 // ex. TYPE "x"
//#define HD_L2 HD_X
//#define HD_L3_keys HD_LM3, HD_LM1 // ex. TYPE "j"
//#define HD_L3 HD_J

//
// H digraph combos
// try to make these use the lead letter and a neighbor.
//
#define HD_Th_keys HD_LM2, HD_LM1 // TYPE "th"
#define HD_Ch_keys HD_LM3, HD_LM2 // TYPE "ch"
#define HD_Wh_keys HD_LT3, HD_LT2 // TYPE "wh"
#define HD_Sh_keys HD_LM4, HD_LM3 // TYPE "sh"
#define HD_Ph_keys HD_RB3, HD_RB4 // TYPE "ph"
#define HD_Gh_keys HD_LT2, HD_LT1 // TYPE "gh"
#define HD_Sch_keys HD_LM4, HD_LM3, HD_LM2 // TYPE "Sch"

// Should we put all the diacritic keys here?
// or get keep them all in the common area (if they all share
// HD Neu vowel block)?
#define HD_OE_lig_keys HD_RM2, HD_RB2 // Œ
#define HD_AE_lig_keys HD_RM1, HD_RB1 // Æ

#endif // COMBO_ENABLE
