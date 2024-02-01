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
#include "print.h"

// clang-format off
enum layers{
  L_01, // 0
  L_FN, // 1
  L_03, // 2
  L_GAME, // 3
  L_EMOJI // 4
};

enum unicode_names {
    ANGRY,
    BEER,
    EXCL,
    COOL,
    CRY,
    HEART,
    QUES,
    ROFL,
    SALU,
    THUMB,
    VOMIT,
    WINK,
    ZZZ,
};

const uint32_t PROGMEM unicode_map[] = {
    [ANGRY] = 0x1F92C,  // 🤬
    [BEER]  = 0x1F37B,  // 🍻
    [COOL]  = 0x1F60E,  // 😎
    [CRY]   = 0x1F622,  // 😢
    [EXCL]  = 0x2757,   // ❗
    [HEART] = 0x1F496,  // ️️💖
    [QUES]  = 0x2753,   // ❓
    [ROFL]  = 0x1F923,  // 🤣
    [SALU]  = 0x1FAE1,  // 🫡
    [THUMB] = 0x1F44D,  // 👍
    [VOMIT] = 0x1F92E,  // 🤮
    [WINK]  = 0x1F609,  // 😉
    [ZZZ]   = 0x1F634,  // 😴
};

enum custom_keycodes {
  EMOJI = SAFE_RANGE,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_01] = LAYOUT_tkl_iso(
    TD(0),   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                   TD(4),    KC_NO,    RGB_TOG,
    TD(5),   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,      KC_INS,   KC_HOME,  KC_PGUP,
    TD(6),   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                  KC_DEL,   KC_END,   KC_PGDN,
    TD(1),   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,
    KC_LSFT, KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,                KC_UP,
    KC_LCTL, TD(2),    KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(L_FN),   KC_RCTL,      KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [L_FN] = LAYOUT_tkl_iso(
    KC_TRNS,  KC_BRID,       KC_BRIU,  KC_TASK,        KC_FILE,  RGB_SPI,  RGB_SPD,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            RGB_RMOD, RGB_MOD,  RGB_TOG,
    KC_TRNS,  BT_HST1,       BT_HST2,  BT_HST3,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_VAI,  RGB_HUI,  RGB_SAI,
    KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            RGB_VAD,  RGB_HUD,  RGB_SAD,
    KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
    KC_TRNS,  KC_TRNS,       KC_TRNS,                                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [L_03] = LAYOUT_tkl_iso(
    DM_RSTP, DM_REC1,        DM_PLY1,     DM_REC2,        DM_PLY2,     DB_TOGG,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_PWR,   KC_WAKE,  KC_SLEP,
    KC_NUM,  KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS,        C(S(KC_W)),  C(S(KC_E)),     C(S(KC_R)),  C(S(KC_T)),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, C(G(KC_LEFT)),  C(S(KC_S)),  C(G(KC_RIGHT)), KC_TRNS,     C(S(KC_G)),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_WHOM,  KC_TRNS,  KC_MAIL,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
    KC_TRNS, KC_TRNS,        KC_TRNS,                                               KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [L_EMOJI] = LAYOUT_tkl_iso(
    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  UM(COOL), KC_TRNS,  KC_TRNS,  UM(QUES), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   UM(WINK), KC_TRNS,  UM(ROFL), UM(THUMB), UM(ZZZ),   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  UM(ANGRY), UM(SALU), KC_TRNS,  KC_TRNS,  KC_TRNS,   UM(HEART), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  UM(CRY),  UM(VOMIT), UM(BEER),  KC_TRNS,  KC_TRNS,  EMOJI,    KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,                                 KC_TRNS,                       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [L_GAME] = LAYOUT_tkl_iso(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             TD(4),     KC_NO,    RGB_TOG,
    TD(5),    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  KC_PGUP,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_DEL,    KC_END,   KC_PGDN,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
    KC_LCTL,  KC_NO,    KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_NO,    MO(L_FN), KC_RCTL,  KC_LEFT,   KC_DOWN,  KC_RGHT
  ),

};

// helper: memory efficient random function
// https://getreuer.info/posts/keyboards/macros3/index.html#random-emojis
static uint8_t simple_rand(void) {
  static uint16_t random = 1;
  random *= UINT16_C(36563);
  return (uint8_t)(random >> 8);
}

void keyboard_post_init_user(void) {
  // vial tap dances
  vial_tap_dance_entry_t td1 = { KC_ESC, KC_NO, KC_NO, LALT(KC_F4), TAPPING_TERM };
  dynamic_keymap_set_tap_dance(0, &td1); 
  vial_tap_dance_entry_t td2 = { KC_NO, MO(2), KC_CAPS_LOCK, KC_NO, TAPPING_TERM };
  dynamic_keymap_set_tap_dance(1, &td2); 
  vial_tap_dance_entry_t td3 = { KC_LGUI, KC_LGUI, LALT(KC_SPACE), KC_NO, TAPPING_TERM };
  dynamic_keymap_set_tap_dance(2, &td3);
  vial_tap_dance_entry_t td4 = { KC_BSPC, KC_LGUI, LCTL(KC_BSPC), KC_NO, TAPPING_TERM };
  dynamic_keymap_set_tap_dance(3, &td4);
  vial_tap_dance_entry_t td5 = { KC_PSCR, LCTL(KC_PSCR), LALT(KC_PSCR), KC_NO, TAPPING_TERM };
  dynamic_keymap_set_tap_dance(4, &td5);
  vial_tap_dance_entry_t td6 = { QK_LEAD, KC_GRAVE, TG(3), KC_NO, TAPPING_TERM };
  dynamic_keymap_set_tap_dance(5, &td6);
  vial_tap_dance_entry_t td7 = { KC_TAB, KC_NO, KC_NO, LGUI(KC_TAB), TAPPING_TERM };
  dynamic_keymap_set_tap_dance(6, &td7);
  vial_tap_dance_entry_t td8 = { KC_BSPC, KC_NO, LCTL(KC_BSPC), KC_NO, TAPPING_TERM };
  dynamic_keymap_set_tap_dance(7, &td8);
//  vial_tap_dance_entry_t td9 = { KC_1, KC_1, KC_1, UM(EXCL), TAPPING_TERM };
//  dynamic_keymap_set_tap_dance(8, &td9); 
//  vial_tap_dance_entry_t td10 = { KC_MINS, KC_MINS, KC_MINS, UM(QUES), TAPPING_TERM };
//  dynamic_keymap_set_tap_dance(9, &td10);

  /*  key overrides (values = bit shift)
  activate when the trigger key is pressed down (1),
  activate when a necessary modifier is pressed down (2)
  activate when a negative modifier is released (4),
  activate on one modifier (8),
  don't deactivate when another key is pressed down (16),
  don't register the trigger key again after the override is deactivated (32),
  key override enable = (128), 
  */

  // vial_key_override_entry_t ko1 = { KC_A, TD(5), 1, 2, 0, 2, 135 };
  // dynamic_keymap_set_key_override(0, &ko1);

}

// macros
bool process_record_user(uint16_t keycode, keyrecord_t* record) {

   dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

  switch (keycode) {

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
        dprintf("sending emoji %s\n", emojis[index]);
        send_unicode_string(emojis[index]);
      }
      return false;
  }
  return true;
}


// leader key stuff
void leader_end_user(void) {

  // toggle game layer (toggle)
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
      case 4: // L_EMOJI
        rgb_matrix_set_color(i, RGB_BLUE);
        break;
      case 3: // L_GAME
        rgb_matrix_set_color(i, RGB_RED);
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
