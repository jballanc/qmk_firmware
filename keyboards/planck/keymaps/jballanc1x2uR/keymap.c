/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _DATA,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define QWERTY DF(_QWERTY)
#define DATA DF(_DATA)
#define DVORAK DF(_DVORAK)
#define LW_MINS LT(_LOWER, KC_MINS)
#define RZ_SLSH LT(_RAISE, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |LowMns|RzSlsh|    Space    | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_1x2uR(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI, LW_MINS, RZ_SLSH,     KC_SPC,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Data
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | Home |  Up  | End  |  F1  |  F2  |  F3  |   7  |   8  |   9  |   /  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  | Left | Down | Right|  F4  |  F5  |  F6  |   4  |   5  |   6  |   *  | Tab  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |  F7  |  F8  |   1  |   2  |   3  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |LwMns |RzSlsh|    Space    |   0  |   .  |   +  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_DATA] = LAYOUT_planck_1x2uR(
    KC_ESC,  KC_HOME, KC_UP,   KC_END,   KC_F1,   KC_F2,   KC_F3,   KC_7,  KC_8, KC_9,   KC_SLSH, KC_BSPC,
    KC_TAB,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_F4,   KC_F5,   KC_F6,   KC_4,  KC_5, KC_6,   KC_ASTR, KC_TAB,
    KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_F7,   KC_F8,   KC_1,  KC_2, KC_3,   KC_MINS, KC_ENT,
    KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI,  LW_MINS, RZ_SLSH,      KC_SPC,    KC_0, KC_DOT, KC_PLUS, KC_ENT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |LowMns|RzSlsh|    Space    | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_1x2uR(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
    KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI, LW_MINS, RZ_SLSH,     KC_SPC,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   \  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   _  |   {  |   }  |   [  |   +  |   =  |   ]  |   )  |   (  |   :  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      -      | Prev | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_1x2uR(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_SLSH, _______,
    _______, KC_UNDS, KC_LCBR, KC_RCBR, KC_LBRC, KC_PLUS, KC_EQL,  KC_RBRC, KC_RPRN, KC_LPRN, KC_COLN, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, _______, _______, _______, _______, _______,      KC_SPC,      KC_MPRV, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ;  |   (  |   )  |   [  |   +  |   =  |   ]  |   }  |   {  |   |  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F11 |  F12 |      | End  |Pg Dn |Pg Up | Home |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      -      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_1x2uR(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_SCLN, KC_LPRN, KC_RPRN, KC_LBRC, KC_PLUS, KC_EQL,  KC_RBRC, KC_RCBR, KC_LCBR, KC_PIPE, _______,
    _______, KC_F11,  KC_F12,  _______, KC_END,  KC_PGDN, KC_PGUP, KC_HOME, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,      KC_MINS,     KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  DATA,     DVORAK,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, MAGIC_SWAP_CONTROL_CAPSLOCK, MAGIC_UNSWAP_CONTROL_CAPSLOCK, _______,
    KC_PWR,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
