// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _DVORAK,
    _RAISE,
    _LOWER,
    _ADJUST
};

enum custom_keycodes {
    TAB_L = SAFE_RANGE,
    TAB_R,
    SPC_L,
    SPC_R,
    TG_NEXT,
    TG_PREV
};

#define LW_BSPC LT(_LOWER, KC_BSPC)
#define RS_SPC LT(_RAISE, KC_SPC)
#define CT_TAB MT(MOD_LCTL, KC_TAB)
#define SH_MINS MT(MOD_LSFT, KC_MINS)
#define GUI_SLSH MT(MOD_LGUI, KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Dvorak
 * ,----------------------------------.             ,----------------------------------.
 * |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ;  |   Q  |   J  |   K  |   X  |  <<- |  ->> |   B  |   M  |   W  |   V  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  <-  |  ->  |GUI+/ |Ctl/- |Sh/Bsp|Lw/Tab|Rs/Spc| Bkspc|   /  |   \  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
  [_DVORAK] = LAYOUT( /* Dvorak */
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                        KC_F,   KC_G,    KC_C,    KC_R,    KC_L,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                        KC_D,   KC_H,    KC_T,    KC_N,    KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,      SPC_L,   SPC_R,   KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,
    KC_ESC,  KC_LEFT, KC_RGHT,GUI_SLSH, CT_TAB, LW_BSPC,  SH_MINS, RS_SPC, KC_ENT, KC_DOWN,   KC_UP, KC_LALT
  ),

/* Raise
 * ,----------------------------------.             ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   ;  |   (  |   )  |   [  |   +  |             |   =  |   ]  |   ~  |   `  |   |  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CTRTAB|      |      |  End | PgDn |  <-  |  ->  | PgUp | Home |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_SCLN, KC_LPRN, KC_RPRN, KC_LBRC, KC_GRV,                   KC_PLUS, KC_RBRC, LSFT(KC_SLSH), LSFT(KC_BSLS), KC_PIPE,
  C(KC_TAB), _______, _______, KC_END,  KC_PGDN, TG_PREV, TG_NEXT, KC_PGUP, KC_HOME, _______, _______, _______,
    _______, KC_MPRV, KC_MNXT, LOPT(KC_LGUI), _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, _______
  ),

/* Lower
 * ,----------------------------------.             ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   _  |   {  |   }  |   [  |   ~  |             |   `  |   ]  |   /  |   \  |   :  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT( /* [> LOWER <] */
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, A(KC_BSPC), KC_BSPC,
    KC_UNDS, KC_LCBR, KC_RCBR, KC_LBRC, KC_TILD,                   KC_EQL,  KC_RBRC, KC_SLSH, KC_BSLS, KC_COLN,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   TAB_L,   TAB_R,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  _______, _______, LSFT(KC_LGUI), _______, _______, _______, KC_RETURN, _______, _______, _______
 ),

/* Adjust
 * ,----------------------------------.             ,----------------------------------.
 * |Reset |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Power |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT( /* [> ADJUST <] */
      RESET, _______,  _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   KC_POWER, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SPC_L:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LCTL("h")));
      }
      break;
    case SPC_R:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LCTL("l")));
      }
      break;
    case TAB_L:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("{"));
      }
      break;
    case TAB_R:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("}"));
      }
      break;
    case TG_PREV:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("["));
      }
      break;
    case TG_NEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("]"));
      }
      break;
  }
  return true;
};
