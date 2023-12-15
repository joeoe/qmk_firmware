SRC += $(USER_PATH)/joeoe.c \
	   $(USER_PATH)/callbacks.c \
	   $(USER_PATH)/keyrecords/process_records.c

EXTRAFLAGS += -flto
LTO_ENABLE = yes

EXTRAKEY_ENABLE = yes
ADAPTIVE_ENABLE = yes

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
COMMAND_ENABLE = yes
CONSOLE_ENABLE = yes

COMBO_ENABLE ?= yes
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += $(USER_PATH)/combo.c
endif

SWAPPER_ENABLE ?= yes
ifeq ($(strip $(SWAPPER_ENABLE)), yes)
	SRC += $(USER_PATH)/swapper.c
	OPT_DEFS += -DSWAPPER_ENABLE
endif

SRC += casemode.c
SRC += layermodes.c
# SRC += tap_hold.c

