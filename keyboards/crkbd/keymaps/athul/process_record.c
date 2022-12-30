// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "jpe230.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer_reset();
        set_keylog(keycode, record);

        switch (keycode) {
            case QK_BOOT:
                rgb_matrix_set_color_all(30, 0, 0);
                rgb_matrix_driver.flush();
                oled_off();
                return true;
        }
    }
    return true;
}
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
		if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
			switch(get_highest_layer(layer_state|default_layer_state)) {
				case 1:
					rgb_matrix_set_color(i, RGB_BLUE);
					break;
				case 2:
					rgb_matrix_set_color(i, RGB_GREEN);
					break;
				case 3:
					rgb_matrix_set_color(i, RGB_MAGENTA);
					break;
				default:
					break;
			}
        }
    }
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
}
