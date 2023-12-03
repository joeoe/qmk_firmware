//
// The Hands Down Variation dependent defs & files
//
#define HD_adaptive_code "alpha/neu-adaptive.c"
//
//
//       Alpha Layer for a 34 key formfactor
// ╭─────────────────────╮ ╭─────────────────────╮
// │ LT4 LT3 LT2 LT1 LT0 │ │ RT0 RT1 RT2 RT3 RT4 │
// │ LM4 LM3 LM2 LM1 LM0 | | RT0 RM1 RM2 RM3 RM4 │
// │ LB4 LB3 LB2 LB1 LB0 │ │ RB0 RB1 RB2 RB3 RB4 │
// ╰───────────╮ LH2 LH1 │ │ RH1 RH2  ╭──────────╯
//             ╰─────────╯ ╰──────────╯
//              Hands Down Neu
// ╭─────────────────────╮ ╭─────────────────────╮
// │  W   F   M   P   V  │ │  #$  .:  /*  "[  '] │
// │  R   S   N   T   B  | |  ,;   A   E   I   H │
// │  X   C   L   D   G  │ │  -+   U   O   Y   K │
// ╰───────────╮ TAB BSP │ │ SPC  RET ╭──────────╯
//             ╰─────────╯ ╰──────────╯
// Q (LT3) & Z (LT4) are on the punc layer
// and on combos (defined below)
//
// for now...
// This will morph to being entirel properly abstracted
// similar to Miryoku, (maybe someone will make an HD Miryoku someday?)
//
//
// We want to be able to define a combo either
// by location for variation independent, spatial referencing, or
// or by letter for mnemonic/phonetic referencing (variation dependent)
//
// BE CAREFUL to not double define a combo!
//
// First, let's add any hold-taps to the keycodes
//
#define HD_A RSFT_T(KC_A)
#define HD_B KC_B
#define HD_C RALT_T(KC_C)
#define HD_D KC_D
#define HD_E RGUI_T(KC_E)
#define HD_F KC_F
#define HD_G KC_G
#define HD_H RCTL_T(KC_H)
#define HD_I RALT_T(KC_I)
#define HD_J KC_J
#define HD_K KC_K
#define HD_L KC_L
#define HD_M KC_M
#define HD_N RGUI_T(KC_N)
#define HD_O KC_O
#define HD_P KC_P
#define HD_Q KC_Q
#define HD_R RCTL_T(KC_R)
#define HD_S RALT_T(KC_S)
#define HD_T RSFT_T(KC_T)
#define HD_U KC_U
#define HD_V KC_V
#define HD_W KC_W
#define HD_X KC_X
#define HD_Y KC_Y
#define HD_Z KC_Z

#define HD_MINS KC_MINS
#define HD_HASH KC_HASH
#define HD_SPC  LT(L_PUNCT,KC_SPC)
#define HD_BSPC LT(L_FN_NUM,KC_BSPC)
#define HD_ENT  LT(L_NAV,KC_ENT)
#define HD_QUOT KC_QUOT
#define HD_DQUO KC_DQUO
#define HD_SLSH KC_SLSH
#define HD_DOT  KC_DOT
#define HD_COMM LT(L_FN_NUM, KC_COMM)

//
// Now let's also define the keycodes on the map for spatial referencing
//
// (is there any way to combine these 2 steps?)
//
#define HD_LT4 HD_W
#define HD_LT3 HD_F
#define HD_LT2 HD_M
#define HD_LT1 HD_P
#define HD_LT0 HD_V
#define HD_RT0 HD_HASH
#define HD_RT1 HD_DOT
#define HD_RT2 HD_SLSH
#define HD_RT3 HD_DQUO
#define HD_RT4 HD_QUOT

#define HD_LM4 HD_R
#define HD_LM3 HD_S
#define HD_LM2 HD_N
#define HD_LM1 HD_T
#define HD_LM0 HD_B
#define HD_RM0 HD_COMM
#define HD_RM1 HD_A
#define HD_RM2 HD_E
#define HD_RM3 HD_I
#define HD_RM4 HD_H

#define HD_LB4 HD_X
#define HD_LB3 HD_C
#define HD_LB2 HD_L
#define HD_LB1 HD_D
#define HD_LB0 HD_G
#define HD_RB0 HD_MINS
#define HD_RB1 HD_U
#define HD_RB2 HD_O
#define HD_RB3 HD_Y
#define HD_RB4 HD_K

//Primary Thumbs (others unique to the board)
#define HD_LH2 KC_TAB
#define HD_LH1 HD_BSPC
#define HD_RH1 HD_SPC
#define HD_RH2 HD_ENT



#ifdef COMBO_ENABLE
//
// Combo definitions that rely on phonetics/mnemonics for their locations.
//
// Combos that are spacially organized don't need to be redefined
// to match the base alpha layer, so they are not included here.
//
// These few spatial combos may move to accommodate some mnemonic combos,
// notably the H-digraph combos that inhabit close areas.
//
#define HD_tab_keys  HD_LM4, HD_LM3     // tab
#define HD_spc_keys  HD_LM1, HD_LM0     // SPACE
#define HD_ent_keys  HD_LT0, HD_LT1     // ENTER
#define HD_ent2_keys HD_LT0, HD_LT1, HD_LT2 // hard-ENTER/page break

// TEXT ENTRY - off map standard alphas (also on Layer L_PUNCT @ Z=LT4 & Q=LT3)
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
#define HD_Ch_keys HD_LM3, HD_LM1 // TYPE "ch"
#define HD_Wh_keys HD_LT4, HD_LT3 // TYPE "wh"
#define HD_Sh_keys HD_LM3, HD_LM2 // TYPE "sh"
#define HD_Ph_keys HD_LT2, HD_LT1 // TYPE "ph"
#define HD_Gh_keys HD_LB1, HD_LB0 // TYPE "gh"
#define HD_Sch_keys HD_LM4, HD_LM3, HD_LM2 // TYPE "Sch"

#define HD_OE_lig_keys HD_RM2, HD_RB2 // Œ
#define HD_AE_lig_keys HD_RM1, HD_RB1 // Æ


// SEMANTIC FUNCTIONS  ** uses SemKeys **
// Spatially arranged on the QWERTY ZXCV locations
//
#define HD_new_keys   HD_LM2, HD_LB2   // new
#define HD_open_keys  HD_LM1, HD_LB1   // open
#define HD_close_keys HD_LM3, HD_LB3   // close
#define HD_quit_keys  HD_LB0, HD_LM0   // quit
#define HD_find_keys  HD_RM4, HD_RB0   // find selection
#define HD_sall_keys  HD_LB4, HD_LB1   // select all
#define HD_swrd_keys  HD_LB4, HD_LB0   // select word
#define HD_undo_keys  HD_LB4, HD_LB3   // undo
#define HD_redo_keys  HD_LB4, HD_LB3, HD_LB2   // redo
//#define HD_cut_keys   HD_LB4, HD_LB2   // cut
#define HD_copy_keys  HD_LB3, HD_LB2   // copy (hold for cut)
#define HD_pste_keys  HD_LB2, HD_LB1   // paste (hold for paste-match)


#endif // COMBO_ENABLE
