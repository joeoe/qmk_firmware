EXTRAFLAGS += -flto
BOOTLOADER = atmel-dfu

LTO_ENABLE = yes
MOUSEKEY_ENABLE = yes    # Mouse keys
RGBLIGHT_ENABLE = no    # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = no
OLED_ENABLE = no
UNICODE_COMMON = yes
UNICODEMAP_ENABLE = no
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes
CAPS_WORD_ENABLE = yes

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

# Debug
COMMAND_ENABLE = yes
CONSOLE_ENABLE = yes

# Easy combo definitions
VPATH += keyboards/gboards/

# SRC += matrix.c
# SRC += oneshot.c
SRC += layermodes.c
# SRC += casemodes.c
SRC += tap_hold.c
SRC += swapper.c
