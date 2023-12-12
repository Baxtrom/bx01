// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
      KC_ESC,  KC_Q,  KC_W,          KC_E,  KC_R,
      KC_TAB,  KC_A,  KC_S,          KC_D,  KC_F, 
      KC_LSFT, KC_Z,  KC_X,          KC_C,  KC_V,
      KC_LCTL, KC_NO, LT(2,KC_LALT), MO(1), KC_SPC
      ),
    [1] = LAYOUT(
      KC_PSCR,      KC_1,    KC_2,    KC_3,    KC_4,
      KC_BACKSPACE, KC_TRNS, KC_TRNS, KC_TRNS, KC_5,
      KC_CAPS_LOCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_6,
      KC_TRNS,      KC_NO,   KC_NO,   KC_TRNS, KC_TRNS
      ),
    [2] = LAYOUT(
      QK_BOOT, KC_TRNS, KC_UP,   KC_TRNS, KC_VOLU,
      KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
      KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS
      ),
  };
