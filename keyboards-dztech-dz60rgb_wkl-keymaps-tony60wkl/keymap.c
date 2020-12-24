/* Copyright 2018 'mechmerlin'
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MAC_1 = SAFE_RANGE,
  MAC_2
};

// Tap Dance declarations
enum {
  TD_1
};

// Define tap dance functions
void td_fn_ctrl_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
      register_code(KC_LSFT);
      layer_on(1);
  } else {
      layer_on(1);
  }
}
void td_fn_ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
      layer_off(1);
      unregister_code(KC_LSFT);
  } else {
      layer_off(1);
  }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Layer 2, twice for Shift Layer 2
  // [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_7)
  [TD_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_fn_ctrl_finished, td_fn_ctrl_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Bksp|Del|
   * |------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|   \  |
   * |------------------------------------------------------------|
   * |MO(1)  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Return |
   * |------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift|MO(1)|
   * |------------------------------------------------------------|
   * |Ctrl|Win |Alt |           Space            |Alt |MO(1)|Ctrl |
   * `------------------------------------------------------------'
   * Notes: MO(1) - Momentarily activate layer 1
   *        LM(1, MOD_LSFT) - Momentarily activate layer 1 with shift
   *        TG(1) - Toggle layer active/inactive
   *        TT(1) - Tap toggle layer with #define TAPPNG_TOGGLE 2
   *        TD(TD_1) - enable tapdance on a key like caps lock
   *
   */
	[0] = LAYOUT_60_tsangan_hhkb(
    KC_GESC, KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    MO(1),   KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),            \
    KC_LCTL, KC_LGUI, KC_LALT,                       KC_SPC,                        KC_RALT, MO(1),   KC_RCTL),

  /* Keymap MO(1) Layer
   * ,-------------------------------------------------------------.
   * |Esc ~|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del|Del|
   * |-------------------------------------------------------------|
   * |     |   |   |   |    |   |   |   |   |   |PSc|   |   |      |
   * |-------------------------------------------------------------|
   * |     |   |   |Shft|Bksp|Del|Lef|Dwn| Up|Rig|   |   |  Return |
   * |-------------------------------------------------------------|
   * |        |   |   |   |   |   |Mac1|Mac2|   |   |  |     | PUp |
   * |-------------------------------------------------------------|
   * |    |    |    |                       |       |       |      |
   * `-------------------------------------------------------------'
   * Notes: { is KC_LCBR, } is KC_RCBR
   *        KC_TRNS use setting of same key from bottom layer
   */
	[1] = LAYOUT_60_tsangan_hhkb(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL, \
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_NO,   KC_NO,   KC_NO,  \
    KC_TRNS, KC_NO,   KC_NO,   KC_LSFT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   KC_ENT,          \
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MAC_1,   MAC_2,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_PGUP,         \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  KC_TRNS, KC_TRNS, KC_TRNS)
};

// Define macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_1:
      if (record->event.pressed) {
        // https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros
        // https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes_basic
        //
        // SS_TAP() presses and releases a key.
        // SS_DOWN() presses (but does not release) a key.
        // SS_UP() releases a key.
        //
        // Example...
        // SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_RIGHT)SS_UP(X_LSHIFT)SS_UP(X_LCTRL)SS_TAP(X_DELETE));
        SEND_STRING(SS_DOWN(X_RALT)SS_TAP(X_LEFT)SS_UP(X_RALT));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MAC_2:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        // SEND_STRING("My first macro!");
        SEND_STRING("ls" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

// Define default RGB lighting
#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable();
  rgblight_sethsv(HSV_WHITE);
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
