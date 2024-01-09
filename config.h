/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

// enables DEBUGGING with Keycode DB_TOGG and CONSOLE_ENABLE
#undef NO_DEBUG

//Vial Keyboard UID
#define VIAL_KEYBOARD_UID {0x5C, 0x1E, 0xC0, 0x71, 0x8A, 0x45, 0x35, 0xAD}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 13 }

#define DYNAMIC_KEYMAP_MACRO_COUNT 32
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define VIAL_TAP_DANCE_ENTRIES 32
#define VIAL_COMBO_ENTRIES 32

#define ONESHOT_TIMEOUT 2500
#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 175

// Custom: spacet cadet mappings (for ISO-DE Layout)
/* 
#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8 // ( )
#define RSPC_KEYS KC_RSFT, KC_LSFT, KC_9 // ( )
#define LAPO_KEYS KC_LALT, KC_RALT, KC_7 // { }
#define RAPC_KEYS KC_RALT, KC_RALT, KC_0 // { }
#define LCPO_KEYS KC_LCTL, KC_RALT, KC_8 // [ ]
#define RCPC_KEYS KC_RCTL, KC_RALT, KC_9 // [ ]
*/

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE