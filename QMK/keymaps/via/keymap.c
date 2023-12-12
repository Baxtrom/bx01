// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
      KC_ESC,  KC_Q,  KC_W,   KC_E,  KC_R,
      KC_TAB,  KC_A,  KC_S,   KC_D,  KC_F, 
      KC_LSFT, KC_Z,  KC_X,   KC_C,  KC_V,
      KC_LCTL, KC_NO, TT(2), MO(1), KC_SPC
      ),
    [1] = LAYOUT(
      KC_PSCR,      KC_1, KC_2, KC_3, KC_F20,
      KC_BACKSPACE, KC_4, KC_5, KC_6, KC_F21,
      KC_CAPS_LOCK, KC_7, KC_8, KC_9, KC_F22,
      KC_LALT,      KC_NO, MO(3), KC_TRNS , KC_ENTER
      ),
    [2] = LAYOUT(
      TG(1), KC_MPRV, KC_UP, KC_MNXT, KC_VOLU,
      KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
      KC_LSFT, KC_COMM, KC_DOT, KC_SLSH, KC_MPLY,
      KC_LWIN, KC_NO,   KC_TRNS, KC_LALT, KC_TRNS
      ),
    [3] = LAYOUT(
      QK_RBT,KC_INS,KC_HOME,KC_PGUP,QK_BOOT,
      RCS(KC_ESC),KC_DEL,KC_END,KC_PGDN,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      RWIN(KC_G),KC_NO,KC_TRNS,KC_TRNS,KC_TRNS
      ),
  };
