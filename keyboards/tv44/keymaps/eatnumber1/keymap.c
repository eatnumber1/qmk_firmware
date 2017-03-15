#include "tv44.h"

#define _L0 0
#define _L1 1
#define _L2 2
#define _L3 3

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_L0] = KEYMAP_TV44(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT,    LT(1, KC_SPC), LT(2, KC_SPC),            MO(3),   KC_RSFT,         KC_RCTL
  ),

  [_L1] = KEYMAP_TV44(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, KC_PSCR, _______, KC_VOLU, KC_VOLD, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_RSFT,
    _______, _______, _______,          _______, _______,                   _______, _______,          _______
  ),

  [_L2] = KEYMAP_TV44(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,          _______, _______,                   _______, _______,          _______
  ),

  [_L3] = KEYMAP_TV44(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    _______, _______, _______,          _______, _______,                   _______, _______,          _______
  )

};

// TODO: Review below this line.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  keyevent_t event = record->event;

  switch (id) {

  }
  return MACRO_NONE;
}

int backlightOn = 0;

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Backlight.
  if (record->event.pressed && keycode == BL_TOGG) {
    // Set B2 to output.
    DDRB |= (1 << 2);

    // Toggle backlight variable.
    if (backlightOn = !backlightOn) {
      // Turn backlight on.
      PORTB |= (1 << 2);
    } else {
      // Turn backlight off.
      PORTB &= ~(1 << 2);
    }

    // Disable the actual keycode.
    return false;
  }

  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 2); PORTB &= ~(1 << 2);
  } else {
    DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
