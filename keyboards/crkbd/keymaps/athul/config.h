// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define VIAL_KEYBOARD_UID {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
/* ---------------------------
 * Common Spit Configuration
 * ---------------------------
 */
#define SPLIT_OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
/* ---------------------------
 * Common OLED Configuration
 * ---------------------------
 */
#define OLED_TIMEOUT 0
#define CUSTOM_OLED_TIMEOUT 10000

/* ---------------------------
 * Common Bootmagic Lite
 * ---------------------------
 */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

// Caps Word
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

/* ---------------------------
 * Common RGB Configuration
 * ---------------------------
 */
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_DISABLE_TIMEOUT 30000
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#define RGB_MATRIX_DEFAULT_HUE 215
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS

/* ---------------------------
 * Common other Configuration
 * ---------------------------
 */
#define ENABLE_COMPILE_KEYCODE

#if defined CONVERT_TO_KB2040 || defined CONVERT_TO_PROMICRO_RP2040
#    include "config_rp2040.h"
#else
#    include "config_avr.h"
#endif
