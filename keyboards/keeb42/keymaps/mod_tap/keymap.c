/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *

 */

#include QMK_KEYBOARD_H

enum layers {
  BASE,
  SYMB,
  NUMB,
  ARRW,
};

//enum combos {
//  LCOLON_ENTER,
//  DF_TAB,
//};
//
//const uint16_t PROGMEM lc_combo[] = {KC_L, KC_SCLN, COMBO_END};
//const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
//
//combo_t key_combos[COMBO_COUNT] = {
//  [LCOLON_ENTER] = COMBO(lc_combo, KC_ENT),
//  [DF_TAB] = COMBO(df_combo, KC_TAB)
//};

enum custom_keycodes {
  TG_LENC = SAFE_RANGE,
  TG_RENC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   *  CTCAP = Control (hold), CAPS (tap)
   *  SHTAB = Left Shift (hold), Tab (tap)
   *  WINDEL = Win (hold), Delete (tap)
   *  SHENT = Right Shift (hold), Enter (tap)
   *  SYMENT = Symbols (hold), Enter (tap)
   *  NUMSPC = Numbers (hold), Space (tap)
   *  ARWSPC = Arrows (hold), Space (tap)
   *  ALTSPC = Alt (hold), Space (tap)
   * ,-----------------------------------------.              ,-----------------------------------------.
   * |  ESC |  Q   |  W   |  E   |  R   |  T   |              |   Y  |   U  |  I   |  O   |  P   | BSPC |
   * |------/------+------+------+------\------|              |------/------+------+------+------\------|
   * |SHTAB |  A   |  S   |  D   |  F   |  G   |              |   H  |  J   |  K   |  L   |  ; : | ' "  |
   * |------\------+------+------+------/------| .----..----. |------\------+------+------+------/------|
   * |CTCAP |  Z   |  X   |  C   |  V   |  B   | | TG || TG | |   N  |  M   |  , < |  . > |  / ? |SHENT |
   * `------+------+------+------+------+------' '----''----' `------+------+------+------+------+------'
   *                    .------.   .------.   .------.  .------.   .------.   .------.
   *                    |WINDEL|   |NUMSPC|   |SYMENT|  |ARWSPC|   | ALT  |   | RWIN |
   *                    '------'   '------'   '------'  '------'   '------'   '------'
   */
  [BASE] = LAYOUT_keeb42(
      KC_ESC,               KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      MT(MOD_LSFT,KC_TAB),  KC_A, LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,   KC_H, RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
      MT(MOD_LCTL,KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT,KC_ENT),
         MT(MOD_LGUI,KC_DEL), LT(NUMB,KC_SPC), LT(SYMB,KC_ENT), TG_LENC,    TG_RENC, LT(ARRW,KC_SPC), KC_RALT, KC_RGUI
      ),

  /* Symbols layer
   *
   * ,-----------------------------------------.              ,-----------------------------------------.
   * |  `   |  !   |  @   |  #   |  $   |  %   |              |  ^   |  &   |  *   |  (   |  )   |  \ | |
   * |------/------+------+------+------\------|              |------/------+------+------+------\------|
   * |      |  `   |      |      |      |      |              |      |  {   |  }   |  |   |  _   |  +   |
   * |------\------+------+------+------/------| .----..----. |------\------+------+------+------/------|
   * |      |      |      |      |      |      | |    ||    | |      |      |      |      |      |      |
   * `------+------+------+------+------+------' '----''----' `------+------+------+------+------+------'
   *                    .------.   .------.   .------.  .------.   .------.   .------.
   *                    |      |   |      |   |      |  |      |   |      |   |      |
   *                    '------'   '------'   '------'  '------'   '------'   '------'
   */
  [SYMB] = LAYOUT_keeb42(
      KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
      _______, KC_GRV , _______, _______, _______, _______,    _______, KC_LCBR, KC_RCBR, KC_PIPE, KC_UNDS, KC_PLUS,
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______,    _______, _______, _______, _______
      ),

  /* Numbers layer
   *
   * ,-----------------------------------------.              ,-----------------------------------------.
   * |   ~  |   1  |  2   |   3  |   4  |   5  |              |  6   |  7   |  8   |  9   |  0   |      |
   * |------/------+------+------+------\------|              |------/------+------+------+------\------|
   * |      |      |      |      |  F12 |      |              |  .   |  [   |  ]   |  \   |  -   |  =   |
   * |------\------+------+------+------/------| .----..----. |------\------+------+------+------/------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |    ||    | |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * `------+------+------+------+------+------' '----''----' `------+------+------+------+------+------'
   *                    .------.   .------.   .------.  .------.   .------.   .------.
   *                    |      |   |      |   |      |  |      |   |      |   |      |
   *                    '------'   '------'   '------'  '------'   '------'   '------'
   */
  [NUMB] = LAYOUT_keeb42(
      KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, _______, _______, _______, KC_F12,  _______,    KC_DOT,  KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                        _______, _______, _______, _______,    _______, _______, _______, _______
      ),

  /* Arrows layer
   *
   * ,-----------------------------------------.              ,-----------------------------------------.
   * |      |      |      | VOLD | VOLU |      |              | INS  | HOME | UP   | END  | PGUP |      |
   * |------/------+------+------+------\------|              |------/------+------+------+------\------|
   * |      |      |      | PREV | NEXT | PLAY |              | DEL  | LEFT | DOWN | RGHT | PGDN |      |
   * |------\------+------+------+------/------| .----..----. |------\------+------+------+------/------|
   * |      |      |      | BRID | BRIU |      | |    ||    | |      |      |      |      |      |      |
   * `------+------+------+------+------+------' '----''----' `------+------+------+------+------+------'
   *                    .------.   .------.   .------.  .------.   .------.   .------.
   *                    |      |   |      |   |      |  |      |   |      |   |      |
   *                    '------'   '------'   '------'  '------'   '------'   '------'
   */
  [ARRW] = LAYOUT_keeb42(
      _______, _______, _______, KC_VOLD, KC_VOLU, _______,    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
      _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY,    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
      _______, _______, _______, KC_BRID, KC_BRIU, _______,    _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______,    _______, _______, _______, _______
      )
};

bool alt_enc_left = false;
bool alt_enc_right = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TG_LENC:
    if (record->event.pressed) {
      alt_enc_left = !alt_enc_left;
    }
    break;
  case TG_RENC:
    if (record->event.pressed) {
      alt_enc_right = !alt_enc_right;
    }
    break;
  }
  return true;
};

void encoder_left(bool clockwise) {
  if (alt_enc_left) {
    clockwise ? SEND_STRING(SS_LCTRL("d")) : SEND_STRING(SS_LCTRL("u"));
    return;
  }

  if (IS_LAYER_ON(NUMB)) {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
    return;
  }

  if (IS_LAYER_ON(ARRW)) {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
    return;
  }

  clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
}

void encoder_right(bool clockwise) {
  if (alt_enc_right) {
    clockwise ? SEND_STRING(SS_LCTRL("u")) : SEND_STRING(SS_LCTRL("d"));
    return;
  }

  if (IS_LAYER_ON(NUMB)) {
    clockwise ? tap_code16(KC_LCBR) : tap_code16(KC_RCBR);
    return;
  }

  if (IS_LAYER_ON(SYMB)) {
    clockwise ? tap_code(KC_B) : tap_code(KC_E);
    return;
  }

  if (IS_LAYER_ON(ARRW)) {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
    return;
  }

  clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
}

void encoder_update_user(uint8_t index, bool dir) {
  if (index == 0) {
    encoder_left(dir);
  }
  if (index == 1) {
    encoder_right(!dir);
  }
}
