CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
WEBUSB_ENABLE = yes
# ORYX_ENABLE = yes
COMBO_ENABLE = yes
# TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
AUDIO_ENABLE = no
UNICODEMAP_ENABLE = yes

# Easy combo definitions
VPATH += keyboards/gboards/

# SRC += matrix.c
SRC += oneshot.c
SRC += layermodes.c
SRC += casemodes.c
SRC += tap_hold.c
SRC += repeat.c
SRC += swapper.c
