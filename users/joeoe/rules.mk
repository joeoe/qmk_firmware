# TODO: how dis

EXTRAFLAGS += -flto
LTO_ENABLE = yes

COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes # audio & system control

LEADER_ENABLE = no
MOUSEKEY_ENABLE = no
REPEAT_KEY_ENABLE = no
CAPS_WORD_ENABLE = no
TAP_DANCE_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
AUTO_SHIFT_ENABLE = no

# Debug
COMMAND_ENABLE = no
CONSOLE_ENABLE = no



SRC += joeoe.c

# SRC += layermodes.c
# SRC += tap_hold.c
# SRC += swapper.c
# ifeq ($(strip $(COMBO_ENABLE)), yes)
# 	SRC += combo.c
# endif

