/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "sendstring_german.h"

// clang-format off
enum layers{
  L_01, // 0
  L_02, // 1
  L_03, // 2
  L_EMOJI, // 3
  L_GAME // 4
};

enum unicode_names {
    ANGRY,
    CRY,
    THUMB,
};

const uint32_t PROGMEM unicode_map[] = {
    [ANGRY] = 0x1F92C,  // 🤬
    [CRY]   = 0x1F622,  // 😢
    [THUMB] = 0x1F44D,  // 👍
};

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  EMOJI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_01] = LAYOUT_tkl_iso(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,            KC_PSCR,   KC_TRNS,  RGB_TOG,
     QK_LEAD,  DE_1,     DE_2,     DE_3,     DE_4,     DE_5,     DE_6,     DE_7,     KC_8,     KC_9,     DE_0,     DE_SS,    DE_ACUT,  KC_BSPC, KC_INS,    KC_HOME,  KC_PGUP,
     KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     DE_Z,     DE_U,     DE_I,     DE_O,     DE_P,     DE_UDIA,  DE_PLUS,           KC_DEL,    KC_END,   KC_PGDN,
     MO(L_03), DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     DE_ODIA,  DE_ADIA,  DE_HASH,  KC_ENT,
     KC_LSFT,  DE_LABK,  DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS,            KC_RSFT,            KC_UP,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(L_02),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[L_02] = LAYOUT_tkl_iso(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            RGB_RMOD, RGB_MOD,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_VAI,  RGB_HUI,  RGB_SAI,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            RGB_VAD,  RGB_HUD,  RGB_SAD,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            RGB_SPI,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SPD,  KC_TRNS),

[L_03] = LAYOUT_tkl_iso(
     DM_RSTP,  DM_REC1,  DM_REC2,  KC_TRNS,  KC_TRNS,  DM_PLY1,  DM_PLY2,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_PWR,   KC_WAKE,  KC_SLEP,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WHOM,  KC_TRNS,  KC_MAIL,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[L_EMOJI] = LAYOUT_tkl_iso(
     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  UM(THUMB), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  UM(ANGRY), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  UM(CRY),  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  EMOJI,    KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,   KC_TRNS,                                 KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[L_GAME] = LAYOUT_tkl_iso(
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     QK_LEAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

};

// helper functions
// https://getreuer.info/posts/keyboards/macros3/index.html#random-emojis
static uint8_t simple_rand(void) {
  static uint16_t random = 1;
  random *= UINT16_C(36563);
  return (uint8_t)(random >> 8);
}

// macros
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case UPDIR:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("../" SS_TAP(X_ENT));
      }
      return false;
    case EMOJI:
      if (record->event.pressed) {
        static const char* emojis[] = {"🤩", "🌞", "👍", "😁", "😃", "🍻", "🥳", "😻"};
        const int NUM_EMOJIS = sizeof(emojis) / sizeof(*emojis);

        // Pseudorandomly pick an index between 0 and NUM_EMOJIS - 2.
        uint8_t index = ((NUM_EMOJIS - 1) * simple_rand()) >> 8;

        // Don't pick the same emoji twice in a row.
        static uint8_t last_index = 0;
        if (index >= last_index) { ++index; }
        last_index = index;

        // Produce the emoji.
        send_unicode_string(emojis[index]);
      }
      return false;
  }
  return true;
}


// leader key stuff
void leader_end_user(void) {

  // switch to game layer (toggle)
  if (leader_sequence_one_key(KC_4)) {
    layer_invert(L_GAME);

  // one shot switch to emoji layer
  } else if (leader_sequence_one_key(KC_3)) {
    set_oneshot_layer(L_EMOJI, ONESHOT_START);
    clear_oneshot_layer_state(ONESHOT_PRESSED);

  // just an example
  } else if (leader_sequence_one_key(KC_M)) {
    SEND_STRING("Mit freundlichen Gr" SS_TAP(X_LBRC) SS_TAP(X_MINS) "en, \nClaus Malter");
  }
}

// RGB modifications
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i < led_max; i++) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
      case 4: // L_GAME
        rgb_matrix_set_color(i, RGB_RED);
        break;
      case 3: // L_EMOJI
        rgb_matrix_set_color(i, RGB_BLUE);
        break;
      case 2: // L_03
        rgb_matrix_set_color(i, RGB_GREEN);
        break;
      case 1: // L_02
        rgb_matrix_set_color(i, RGB_YELLOW);
        break;
      default: // L_01
        break;
      }
    }

  // if capslock is locked, set led color
  if (host_keyboard_led_state().caps_lock) {
    rgb_matrix_set_color(50, RGB_WHITE);
  } else {
    rgb_matrix_set_color(50, RGB_OFF);
  }

  return false;
}

