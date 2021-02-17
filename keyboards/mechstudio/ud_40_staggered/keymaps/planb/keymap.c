/* Copyright 2021 Tony Höglund
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _NAV,
    _TRI
};

#define RSF_SLS RSFT_T(KC_SLSH)
#define LCT_ESC LCTL_T(KC_ESC)

#define LT_FN1_SPACE LT(_FN1, KC_SPACE)
#define LT_FN2_SPACE LT(_FN2, KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY Layer
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │BkS│
 * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │CEsc│ A │ S │ D │ F │ G │ H │ J │ K │ L │  ;:  │
 * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
 * │LShift│ Z │ X │ C │ V │ B │ N │ M │ , │ . │Sft/│
 * ├────┬─┴─┬─┴──┬┴───┴──┬┴───┴───┴┬──┴──┬┴───┼────┤
 * │Navi│Alt│ OS │LN2Spac│ LN1Space│RAlt │    │Navi│
 * └────┴───┴────┴───────┴─────────┴─────┴────┴────┘
*/
[_BASE] = LAYOUT_staggered(
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  LCT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,         KC_SCLN,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RSF_SLS,
  MO(_NAV), KC_LALT, KC_LGUI,   LT_FN2_SPACE,   _______, LT_FN1_SPACE,     KC_RALT,     _______,      MO(_NAV)
),

/* FN1 Layer
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ' │
 * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │    │   │   │   │   │   │   │ - │ = │ [ │   ]  │
 * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
 * │      │F11│F12│F13│F14│F15│F16│F17│F18│F19│F20 │
 * ├────┬─┴─┬─┴──┬┴───┴──┬┴───┴───┴┬──┴──┬┴───┼────┤
 * │    │   │    │       │         │     │    │    │
 * └────┴───┴────┴───────┴─────────┴─────┴────┴────┘
 */
[_FN1] = LAYOUT_staggered(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_QUOTE,
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC,      KC_RBRC,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,
  _______, _______, _______,   _______,        _______, _______,          _______,      _______,     _______
),

/* FN2 Layer
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ ~ │ ~ │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │ \ │
 * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │    │   │   │   │   │   │   │ _ │ + │ { │   }  │
 * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
 * │      │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10 │
 * ├────┬─┴─┬─┴──┬┴───┴──┬┴───┴───┴┬──┴──┬┴───┼────┤
 * │    │   │    │       │         │     │    │    │
 * └────┴───┴────┴───────┴─────────┴─────┴────┴────┘
 */
[_FN2] = LAYOUT_staggered(
  KC_TILDE,KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR,      KC_RCBR,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  _______, _______, _______,   _______,        _______, _______,          _______,      _______,     _______
),

/* NAV Layer
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │
 * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │    │   │   │   │   │   │   │   │   │   │      │
 * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
 * │      │   │   │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴──┬┴───┴──┬┴───┴───┴┬──┴──┬┴───┼────┤
 * │    │   │    │       │         │     │    │    │
 * └────┴───┴────┴───────┴─────────┴─────┴────┴────┘
 */
[_NAV] = LAYOUT_staggered(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,     KC_ENT,
  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
  _______, _______, _______,   _______,        _______, _______,          _______,      _______,     _______
),

/* TRI Layer
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │RES│   │   │   │   │   │   │   │   │   │   │DEL│
 * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │    │   │   │   │   │   │   │   │   │   │      │
 * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
 * │      │   │   │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴──┬┴───┴──┬┴───┴───┴┬──┴──┬┴───┼────┤
 * │    │   │    │       │         │     │    │    │
 * └────┴───┴────┴───────┴─────────┴─────┴────┴────┘
 */
[_TRI] = LAYOUT_staggered(
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
  _______, _______, _______,   _______,        _______, _______,          _______,      _______,     _______
),
};


/* TEMPLATE
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │
 * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │    │   │   │   │   │   │   │   │   │   │      │
 * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
 * │      │   │   │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴──┬┴───┴──┬┴───┴───┴┬──┴──┬┴───┼────┤
 * │    │   │    │       │         │     │    │    │
 * └────┴───┴────┴───────┴─────────┴─────┴────┴────┘
 */
/*
[_] = LAYOUT_staggered(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
  _______, _______, _______,   _______,        _______, _______,          _______,      _______,     _______
),
*/
