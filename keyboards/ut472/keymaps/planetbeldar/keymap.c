/* Copyright 2018 Carlos Filoteo
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

enum my_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _TRI,
  _ADJUST,
  _NAVIGATION
};

enum my_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  NAVIGATION
};

#define LT_ADJUST_TAB LT(_ADJUST, KC_TAB)
#define MT_ALT_SPACE  MT(MOD_LALT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * QWERTY
   * ,-------------------------------------------------------------------------.
   * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Ct/Esc|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | NAV | Ctrl| Alt | Gui |LOWER | Alt/Space | RAISE|AltGr| Down|  Up |Right|
   * `-------------------------------------------------------------------------'
  */
[_QWERTY] = LAYOUT(
  LT_ADJUST_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  NAVIGATION,     KC_LCTL, KC_LALT, KC_LGUI, LOWER,    MT_ALT_SPACE,    RAISE,   KC_RALT, _______, _______, NAVIGATION
),

  /* Lower Layer
   * ,-------------------------------------------------------------------------.
   * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Bspace|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  _  |  +  |  { |  }  |   |   |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */
[_LOWER] = LAYOUT(
  KC_TILDE,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_BSPC,
  _______, _______, _______, _______, _______, _______, _______, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, _______, _______, KC_CAPS, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

  /* Raise Layer
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |Bspace |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */
[_RAISE] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
  _______, _______, _______, KC_CAPS, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

  /* Tri Layer
   * ,-------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */
[_TRI] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

  /* Adjust Layer
   * Backlighting, keyboard controls, music etc.
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|  Vol+ |
   * |-------------------------------------------------------------------------+
   * |      | VLK | Mod+| Hue+| Sat+| Val+|     |     |     |     |     | Vol- |
   * |-------------------------------------------------------------------------+
   * |       | TOG | Mod-| Hue-| Sat-| Val-|     |     |     |     | Stop| Mute|
   * |-------------------------------------------------------------------------+
   * |Sleep|     |     |     |      |   C+A+D  | C+A+I |     | Prev|Pause| Next|
   * `-------------------------------------------------------------------------'
  */
[_ADJUST] = LAYOUT(
  KC_ESC,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
  _______, VLK_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, KC_VOLD,
  _______, RGB_TOG, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, KC_MSTP, KC_MUTE,
  KC_SLEP, _______, _______,  _______, _______,  LCA(KC_DEL), LCA(KC_INS), _______, KC_MPRV, KC_MPLY, KC_MNXT
),

  /* Navigation Layer
   * ,-------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     | Left| Down|  Up |Right|      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |MLeft|MDown| MUp |MRigh|
   * `-------------------------------------------------------------------------'
   */
[_NAVIGATION] = LAYOUT( /* Navigation */
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, KC_MS_L, KC_MS_D,  KC_MS_U, KC_MS_R
)
};

void process_layer_change(enum my_layers layer, keyrecord_t *record) {
  if (record->event.pressed) {
    layer_on(layer);
  }
  else {
    layer_off(layer);
  }

  if (layer == _LOWER || layer == _RAISE) {
    update_tri_layer(_LOWER, _RAISE, _TRI);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case LOWER:
      process_layer_change(_LOWER, record);
      return false;
    case RAISE:
      process_layer_change(_RAISE, record);
      return false;
    case ADJUST:
      process_layer_change(_ADJUST, record);
      return false;
    case NAVIGATION:
      process_layer_change(_NAVIGATION, record);
      return false;
    default:
      return true;
  }
}
