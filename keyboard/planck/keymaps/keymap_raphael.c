#include "keymap_common.h"

#define SOFT_COLEMAK_LAYER 0
#define HARD_COLEMAK_LAYER 1
#define LOWER_LAYER 2
#define RAISE_LAYER 3
#define ARROW_LAYER 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[SOFT_COLEMAK_LAYER] = { /* Raphael soft-coded colemak - OS in colemak - */
  {KC_TAB,  CM_Q,    CM_W,    CM_F,    CM_P,    CM_G,    CM_J,    CM_L,    CM_U,    CM_Y,    CM_SCLN, KC_BSPC},
  {KC_ESC,  CM_A,    CM_R,    CM_S,    CM_T,    CM_D,    CM_H,    CM_N,    CM_E,    CM_I,    CM_O,     KC_QUOT},
  {KC_LSFT, CM_Z,    CM_X,    CM_C,    CM_V,    CM_B,    CM_K,    CM_M,    CM_COMM, CM_DOT,  CM_SLSH, KC_ENT},
  {FUNC(ARROW_LAYER), KC_LCTL, KC_LALT, KC_LGUI, FUNC(LOWER_LAYER),    KC_SPC,   KC_SPC,    FUNC(RAISE_LAYER),   KC_LEFT, KC_UP, KC_DOWN,  KC_RGHT}
},
[HARD_COLEMAK_LAYER] = { /* Raphael hard-coded colemak - OS in en_US - */
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
  {FUNC(ARROW_LAYER), KC_LCTL, KC_LALT, KC_LGUI, FUNC(LOWER_LAYER),    KC_SPC,   KC_SPC,    FUNC(RAISE_LAYER),   KC_LEFT, KC_UP, KC_DOWN,  KC_RGHT}
},
[LOWER_LAYER] = { /* Raphael LOWER */
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_TRNS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY}
},
[RAISE_LAYER] = { /* Raphael RAISE */
  {S(KC_GRV),  S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0), KC_BSPC},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_MINS), S(KC_EQL),  S(KC_LBRC), S(KC_RBRC), S(KC_BSLS)},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY}
},
[ARROW_LAYER] = { /* Raphael ARROWS */
  {RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO, KC_NO},
  {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO},
  {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(SOFT_COLEMAK_LAYER), KC_TRNS, KC_TRNS, FUNC(HARD_COLEMAK_LAYER),   KC_NO,   KC_NO,   KC_NO, KC_NO}
}
};


const uint16_t PROGMEM fn_actions[] = {

    [SOFT_COLEMAK_LAYER] = ACTION_DEFAULT_LAYER_SET(SOFT_COLEMAK_LAYER),
    [HARD_COLEMAK_LAYER] = ACTION_DEFAULT_LAYER_SET(HARD_COLEMAK_LAYER),

    [LOWER_LAYER] = ACTION_LAYER_MOMENTARY(LOWER_LAYER),
    [RAISE_LAYER] = ACTION_LAYER_MOMENTARY(RAISE_LAYER),

    [ARROW_LAYER] = ACTION_LAYER_MOMENTARY(ARROW_LAYER)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
      case 0:
        return MACRODOWN(T(CM_T), END);
      break;
    }
    return MACRO_NONE;
};
