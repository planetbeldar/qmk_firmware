 /* 
 Copyright 2020 Alec Penland
 Copyright 2020 Garret Gartner
  
 This program is free software: you can redistribute it and/or modify 
 it under the terms of the GNU General Public License as published by 
 the Free Software Foundation, either version 2 of the License, or 
 (at your option) any later version. 
  
 This program is distributed in the hope that it will be useful, 
 but WITHOUT ANY WARRANTY; without even the implied warranty of 
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 GNU General Public License for more details. 
  
 You should have received a copy of the GNU General Public License 
 along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */ 

#include QMK_KEYBOARD_H

// Layer names
enum ats_layers{
  _BASE,
  _FN1,
  _FN2,
  _NAVIGATION,
  _TRI
};

#define RSF_SLS RSFT_T(KC_SLSH)
#define LCT_ESC LCTL_T(KC_ESC)

#define LT_FN1_SPACE LT(_FN1, KC_SPACE)
#define LT_FN2_SPACE LT(_FN2, KC_SPACE)
#define LT_FN2_ESC   LT(_FN2, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default QWERTY layer 
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┐
     * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ ' │BkS│   │PgU│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤   ├───┤
     * │CEsc│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │Enter │   │PgD│
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┘   ├───┤
     * │LShift│ Z │ X │ C │ V │ B │ N │ M │ , │ . │Sft/│ ┌───┐ │CAP│
     * ├────┬─┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───┼───┴┬───┘ │ ↑ │ └───┘
     * │LCtl│Alt│ OS │  LNSpace │  Space │RAlt│ Ln │ ┌───┼───┼───┐
     * └────┴───┴────┴──────────┴────────┴────┴────┘ │ ← │ ↓ │ → │
     *                                               └───┴───┴───┘
     */
    [_BASE] = LAYOUT_split_space(
        KC_TAB,           KC_Q,         KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,    KC_QUOTE, KC_BSPC,         KC_PGUP,
        LCT_ESC,          KC_A, 	KC_S,    KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN, 	KC_ENT,            KC_PGDN,
        KC_LSFT,          KC_Z,         KC_X,    KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  RSF_SLS,                KC_UP,      KC_CAPS,
        MO(_NAVIGATION),  KC_LALT,      KC_LGUI,    LT_FN2_SPACE,   LT_FN1_SPACE,   KC_RALT, MO(_FN2),               KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    /* FN1
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┐
     * │ ~ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │   │Del│   │VL+│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤   ├───┤
     * │    │   │   │   │   │   │   │ - │ = │ [ │ ] │  \   │   │VL-│
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┘   ├───┤
     * │      │F11│F12│F13│F14│F15│F16│F17│F18│F19│F20 │ ┌───┐ │   │
     * ├────┬─┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───┼───┴┬───┘ │   │ └───┘
     * │    │   │    │          │        │    │    │ ┌───┼───┼───┐
     * └────┴───┴────┴──────────┴────────┴────┴────┘ │   │   │   │
     *                                               └───┴───┴───┘
     */
    [_FN1] = LAYOUT_split_space(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    _______,  KC_DEL,                 KC_VOLU,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,      KC_BSLS,                     KC_VOLD,
        _______,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,                     _______,       _______,
        RESET,    _______,  _______,                    _______,            _______,             _______,  _______,          _______,  _______,   _______
    ),

    /* FN2
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┐
     * │   │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │ \ │Del│   │Hme│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤   ├───┤
     * │    │   │   │   │   │   │   │ _ │ + │ { │ } │  |   │   │End│
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┘   ├───┤
     * │      │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10 │ ┌───┐ │   │
     * ├────┬─┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───┼───┴┬───┘ │   │ └───┘
     * │    │   │    │          │        │    │    │ ┌───┼───┼───┐
     * └────┴───┴────┴──────────┴────────┴────┴────┘ │   │   │   │
     *                                               └───┴───┴───┘
     */
    [_FN2] = LAYOUT_split_space(
        KC_TILDE, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSLS,   KC_DEL,              KC_HOME,
        _______,  _______,  _______,  _______,  _______, _______,  _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,      KC_PIPE,                    KC_END,
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                     _______,      _______,
        RESET,    _______,  _______,                    _______,            _______,             _______,  _______,          _______,  _______,   _______
    ),

    /* Navigation
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤   ├───┤
     * │    │   │   │   │   │   │   │   │   │   │   │      │   │   │
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┘   ├───┤
     * │      │   │   │   │   │   │   │   │   │   │    │ ┌───┐ │   │
     * ├────┬─┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───┼───┴┬───┘ │   │ └───┘
     * │    │   │    │          │        │    │    │ ┌───┼───┼───┐
     * └────┴───┴────┴──────────┴────────┴────┴────┘ │   │   │   │
     *                                               └───┴───┴───┘
     */
    [_NAVIGATION] = LAYOUT_split_space(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,        _______,                    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                    KC_MS_U,        _______,
        _______,  _______,  _______,               _______,             _______,             _______,      _______,         KC_MS_L,   KC_MS_D,   KC_MS_R
    ),

    /* Tri
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │BkS│   │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤   ├───┤
     * │    │   │   │   │   │   │   │   │   │   │   │      │   │   │
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┘   ├───┤
     * │      │   │   │   │   │   │   │   │   │   │    │ ┌───┐ │   │
     * ├────┬─┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───┼───┴┬───┘ │   │ └───┘
     * │    │   │    │          │        │    │    │ ┌───┼───┼───┐
     * └────┴───┴────┴──────────┴────────┴────┴────┘ │   │   │   │
     *                                               └───┴───┴───┘
     */
    [_TRI] = LAYOUT_split_space(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DEL,                 _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,        _______,                    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                    _______,        _______,
        _______,  _______,  _______,               _______,             _______,             _______,      _______,         _______,   _______,   _______
    )
};

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(D0, layer_state_cmp(state, 0));
    writePin(D1, layer_state_cmp(state, 1));
    writePin(D2, layer_state_cmp(state, 2));
    return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
        case LCTL_T(KC_SCLN):
            return true;
        default:
            return false;
    }
}

void process_layer_change(enum ats_layers layer, keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(layer);
    }
    else {
        layer_off(layer);
    }

    if (layer == _FN1 || layer == _FN2) {
        update_tri_layer(_FN1, _FN2, _TRI);
    }
}
