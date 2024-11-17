// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
     _MAIN,
     _FN,
     _NAV
};

enum tap_dance_codes {
    TD_CMD_CMDSPC,
    HT_P_LBRC,
    HT_EQUAL_RBRCA,
    HT_ESC_LCTRL_CMDSFTSPC
};

// Hold-Tap wrapper for tap dance
#define HT(x) TD(x)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌─────────────────────────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬───────────────┬──────────────────────┐
     KC_GRAVE,                      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           KC_MINUS,
  //├─────────────────────────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼───────────────┼──────────────────────┤
     MT(MOD_LALT, KC_TAB),          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    TD(HT_P_LBRC),  TD(HT_EQUAL_RBRCA),
  //├─────────────────────────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼───────────────┼──────────────────────┤
     TD(HT_ESC_LCTRL_CMDSFTSPC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,        KC_QUOT,
  //├─────────────────────────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼───────────────┼──────────────────────┤
     KC_LSFT,                       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,        KC_BSLS,
  //└─────────────────────────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └────────┴────────┴────────┴────────┴────────┴───────────────┴──────────────────────┘
                                    _______,    LT(_FN, KC_SPACE),  TD(TD_CMD_CMDSPC),              MT(MOD_LCTL, KC_ENTER),     LT(_NAV, KC_BSPC),  _______
  //                               └──────────┴───────────────────┴────────────────────┘          └───────────────────────────┴────────────────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _______, KC_UP,   _______, QK_BOOT, _______,                            _______, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, EE_CLR,  _______, _______, _______, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, EE_CLR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t double_tap;
    uint16_t double_tap_hold;
    uint16_t currently_held;
} tap_dance_advanced_t;

void tap_dance_advanced_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_advanced_t *config = (tap_dance_advanced_t *)user_data;
    config->currently_held = 0;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            // Single tap and hold
            if (config->hold) {
                register_code16(config->hold);
                config->currently_held = config->hold;
            } else {
                register_code16(config->tap);
                config->currently_held = config->tap;
            }
        } else if (state->count == 2) {
            // Double tap and hold
            if (config->double_tap_hold) {
                register_code16(config->double_tap_hold);
                config->currently_held = config->double_tap_hold;
            } else if (config->double_tap) {
                register_code16(config->double_tap);
                config->currently_held = config->double_tap;
            } else {
                register_code16(config->tap);
                config->currently_held = config->tap;
            }
        }
    } else {
        // Not pressed, just tapped
        if (state->count == 1) {
            tap_code16(config->tap);  // Changed from register to tap_code
        } else if (state->count == 2 && config->double_tap) {
            tap_code16(config->double_tap);  // Changed from register to tap_code
        } else {
            tap_code16(config->tap);  // Changed from register to tap_code
        }
    }
}

void tap_dance_advanced_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_advanced_t *config = (tap_dance_advanced_t *)user_data;
    if (config->currently_held) {
        unregister_code16(config->currently_held);
        config->currently_held = 0;
    }
}

// Basic tap-hold behavior
#define ACTION_TAP_DANCE_TAP_HOLD(_tap, _hold) \
    { .fn = {NULL, tap_dance_advanced_finished, tap_dance_advanced_reset}, \
      .user_data = (void *)&((tap_dance_advanced_t){ \
          .tap = _tap, \
          .hold = _hold, \
          .double_tap = 0, \
          .double_tap_hold = 0, \
          .currently_held = 0 \
      }), }

// Tap-hold with double tap behavior
#define ACTION_TAP_DANCE_TAP_HOLD_DOUBLE_TAP(_tap, _hold, _dt) \
    { .fn = {NULL, tap_dance_advanced_finished, tap_dance_advanced_reset}, \
      .user_data = (void *)&((tap_dance_advanced_t){ \
          .tap = _tap, \
          .hold = _hold, \
          .double_tap = _dt, \
          .double_tap_hold = 0, \
          .currently_held = 0 \
      }), }

// Full tap-hold-double-tap-hold behavior
#define ACTION_TAP_DANCE_TAP_HOLD_DOUBLE_TAP_HOLD(_tap, _hold, _dt, _dt_hold) \
    { .fn = {NULL, tap_dance_advanced_finished, tap_dance_advanced_reset}, \
      .user_data = (void *)&((tap_dance_advanced_t){ \
          .tap = _tap, \
          .hold = _hold, \
          .double_tap = _dt, \
          .double_tap_hold = _dt_hold, \
          .currently_held = 0 \
      }), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_CMD_CMDSPC] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_GUI, LGUI(KC_SPACE)), // Command | Command + Space
    [HT_P_LBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_P, KC_LBRC), // P | [
    [HT_EQUAL_RBRCA] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQUAL, KC_RBRC), // = | ]
    [HT_ESC_LCTRL_CMDSFTSPC] = ACTION_TAP_DANCE_TAP_HOLD_DOUBLE_TAP(KC_ESC, KC_LEFT_CTRL, LGUI(LSFT(KC_LSFT))) // Esc | Ctrl | Cmd + Shift + Space
};
