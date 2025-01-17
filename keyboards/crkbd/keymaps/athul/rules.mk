# Shared rules for both of my Corne
OLED_ENABLE       = yes
OLED_DRIVER       = SSD1306
VIA_ENABLE        = yes
VIAL_ENABLE        = yes
VIALRGB_ENABLE    = yes 
RGB_MATRIX_ENABLE = yes
CAPS_WORD_ENABLE = yes

SRC += oled/oled_handler.c process_record.c

ifneq ($(CONVERT_TO),)
    # Asume ARM
    DEBUG_MATRIX_SCAN_RATE_ENABLE = yes
    WPM_ENABLE = yes
    CONSOLE_ENABLE = yes
    SRC +=  oled/rp2040/master/oled_master_handler.c \
            oled/rp2040/master/indicators_down.c \
            oled/rp2040/master/indicators_up.c \
            oled/rp2040/slave/oled_slave_handler.c \
            oled/rp2040/slave/ocean_dream.c
else
    # Asume AVR
    LTO_ENABLE = yes
    SRC +=  oled/avr/master/oled_master_handler.c \
            oled/avr/slave/oled_slave_handler.c
endif

