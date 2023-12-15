#pragma once

#define EXTRA_SHORT_COMBOS

enum my_combos {
    FC_ESC,  // ESCape SIMPLE COMBO must be first (used as FALSE for combo_on)
    HC_CFG,  // The keyboard and media config/settings layer
    HC_CAPW, // CAPS WORD
    FC_CAPS, // CAPS LOCK (others)

    C_TO_NUM, // Go to NUM layer
    C_SAVE_VIM,
    C_VIM_VS,
    C_VIM_SP,
    C_CLOSE_WIN,

    HC_TAB,  // Tab
    HC_STAB, // Shift Tab
    HC_DOLR, // $
    HC_HASH, // #
    HC_QUES, // ?
    HC_EXLM, // !
    HC_SCLN, // ;
    HC_UNDS, // _ underscore
    HC_NDSH, // – N-dash
    HC_MDSH, // — M-dash
    HC_TILD, // ~ tilde
    HC_TIC,  // ` tic (not a dead key)
    HC_GRV,  // ` grave (dead key)
    HC_CIRC, // ˆ circumflex
    HC_MACR, // - macron

    HC_Q,  // Q is not on the map
    HC_L1, // ex. z not on the map (remappable)?

    HC_OE, // Ö
    HC_AE, // Ä
    HC_UE, // Ü
    HC_SS, // ß

    // ACTION COMBOS (ie, not simple combos as above)
    //
    // This group all have actions on press (no hold-delay),
    // may be repeated if held (register_code) or not (tap_code)
    // to be handled in process_combo_event and/or matrix_scan_user_process_combo
    HC_AT,   // @
    HC_COLN, // :

    HC_Th,  // treat as θ
    HC_Sh,  // TYPE "sh"
    HC_Wh,  // treat as digraph 'WH'
    HC_Ch,  // treat as digraph 'CH'
    HC_Gh,  // treat as digraph 'GH'
    HC_Ph,  // treat as φ
    HC_Sch, // treat as digraph 'SCH'

    // DELAYED ACTION COMBOS -- this block must be contiguous!!
    //
    // no action on press, action (in matrix_scan_user),
    // underlying keys seng if the hold threshold is not met.
    // may repeat as appropriate. (tap_code vs register_code)
    PC_STAB, // Shift-<tab>

    HC_ENT,
    HC_ENT2, // hard enter (cmd/ctrl-enter)
    HC_SPC,

    HC_PRNT,
    HC_UNDO,
    HC_REDO,
    HC_COPY, // hold for cut
    HC_PSTE, // hold for paste+match style

    COMBO_LENGTH
};
