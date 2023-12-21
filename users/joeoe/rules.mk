SRC += $(USER_PATH)/joeoe.c \
	   $(USER_PATH)/callbacks.c \
	   $(USER_PATH)/keyrecords/process_records.c

EXTRAFLAGS += -flto
LTO_ENABLE = yes

EXTRAKEY_ENABLE = yes

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

SWAPPER_ENABLE ?= yes
ifeq ($(strip $(SWAPPER_ENABLE)), yes)
	SRC += $(USER_PATH)/swapper.c
	OPT_DEFS += -DSWAPPER_ENABLE
endif

CASEMODE_ENABLE ?= yes
ifeq ($(strip $(CASEMODE_ENABLE)), yes)
	SRC += $(USER_PATH)/casemode.c
	OPT_DEFS += -DCASEMODE_ENABLE
endif

LAYERMODE_ENABLE ?= yes
ifeq ($(strip $(LAYERMODE_ENABLE)), yes)
	SRC += $(USER_PATH)/layermodes.c
	OPT_DEFS += -DLAYERMODE_ENABLE
	OPT_DEFS += -DNUMWORD_ENABLE
endif

LINGER_ENABLE ?= yes
ifeq ($(strip $(LINGER_ENABLE)), yes)
	SRC += $(USER_PATH)/linger.c
	OPT_DEFS += -DLINGER_ENABLE
endif

# ADAPTIVE_ENABLE = yes
# ifeq ($(strip $(ADAPTIVE_ENABLE)), yes)
# 	OPT_DEFS += -DADAPTIVE_ENABLE
# endif
SRC += tap_hold.c

