#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// custom keycodes
#define KC_SUPR KC_LGUI
#define SPR_LFT G(KC_LEFT)
#define SPR_RGT G(KC_RGHT)
#define SPR_UP  G(KC_UP)
#define SPR_DWN G(KC_DOWN)
#define GC_LEFT C(G(KC_LEFT))
#define GC_RGHT C(G(KC_RGHT))
#define GC_UP C(G(KC_UP))
#define GC_DOWN C(G(KC_DOWN))
#define GCS_LFT S(C(G(KC_LEFT)))
#define GCS_RGT S(C(G(KC_RGHT)))
#define GCS_UP S(C(G(KC_UP)))
#define GCS_DWN S(C(G(KC_DOWN)))
#define WD_NDIS S(G(KC_RGHT))
#define WD_PDIS S(G(KC_RGHT))
#define Z_IN C(KC_EQL)
#define Z_OUT C(KC_MINS)
#define Z_RESET C(KC_0)
#define CL_CUT C(KC_X)
#define CL_COPY C(KC_C)
#define CL_PAST C(KC_V)
#define CL_HIST G(KC_V)
#define KC_EXPO G(KC_TAB)
#define KC_LOCT G(KC_L)
#define TAP_GUI OSM(MOD_LGUI)
#define TAP_MEH OSM(MOD_MEH)
#define TAP_HYPR OSM(MOD_HYPR)
#define RAISE TT(2)
#define LOWER TT(3)
#define ADJUST TT(4)
#define NUMPAD TG(5)
#define KB_SET TT(6)

// combos
// LHS
const uint16_t PROGMEM LCB_CTRL[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM LCB_SHFT[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM LCB_ALT[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM LCB_SUPR[] = {KC_A, KC_U, COMBO_END};
// RHS
const uint16_t PROGMEM RCB_CTRL[] = {KC_H, KC_T, COMBO_END};
const uint16_t PROGMEM RCB_SHFT[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM RCB_ALT[] = {KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM RCB_SUPR[] = {KC_H, KC_S, COMBO_END};
combo_t key_combos[] = {
    // LHS
    COMBO(LCB_CTRL, KC_LCTL),
    COMBO(LCB_SHFT, KC_LSFT),
    COMBO(LCB_ALT,  KC_LALT),
    COMBO(LCB_SUPR, KC_LGUI),
    // RHS
    COMBO(RCB_CTRL, KC_RCTL),
    COMBO(RCB_SHFT, KC_RSFT),
    COMBO(RCB_ALT,  KC_RALT),
    COMBO(RCB_SUPR, KC_RGUI),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 0 - Dvorak
  [0] = LAYOUT_split_3x6_3(
     KC_ESC, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  KC_TAB,
    KC_LCTL,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_LGUI,
    KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSFT,
                                ADJUST,   RAISE,  KC_SPC,     KC_BSPC,   LOWER, KC_LALT
    ),

  // layer 1 - QWERTY
  [1] = LAYOUT_split_3x6_3(
     KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_TAB,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LGUI,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_QUOT, KC_RSFT,
                                ADJUST,   RAISE,  KC_SPC,      KC_SPC,   LOWER, KC_LALT
    ),

  // layer 2 - Raise
  [2] = LAYOUT_split_3x6_3(
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_PSCR, GC_LEFT,  SPR_UP, GC_RGHT, KC_VOLU,    Z_IN,
     KC_EQL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_SCRL, SPR_LFT, SPR_DWN, SPR_RGT, KC_VOLD,   Z_OUT,
     KC_F15, KC_SLSH, KC_BSLS, KC_MINS, KC_LBRC, KC_RBRC,     KC_PAUS, _______, _______, _______, _______, Z_RESET,
                                 KC_NO, _______, TAP_GUI,     KC_BSPC,  KC_ENT,  NUMPAD
    ),

  // layer 3 - Lower
  [3] = LAYOUT_split_3x6_3(
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     _______, WD_PDIS,  SPR_UP, WD_NDIS, _______,    Z_IN,
    KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,     _______, SPR_LFT, SPR_DWN, SPR_RGT, _______,   Z_OUT,
    _______, KC_QUES, KC_PIPE, KC_UNDS, KC_LCBR, KC_RCBR,     KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, _______, Z_RESET,
                                KC_F15,  KC_ENT, KC_BSPC,     _______, _______, _______
    ),

  // layer 4 - adjust
  [4] = LAYOUT_split_3x6_3(
    KC_EXPO,  KC_DEL, KC_PGDN,   KC_UP, KC_PGUP,  KC_INS,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
     KC_ENT, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
      TG(5), _______,  CL_CUT, CL_COPY, CL_PAST, CL_HIST,      KC_RGUI, KC_RALT, KC_RSFT, KC_RCTL,  KC_APP, KC_CAPS,
                               _______, _______, _______,      TAP_MEH,TAP_HYPR,  KB_SET
    ),

  // layer 5 - numpad
  [5] = LAYOUT_split_3x6_3(
      KC_NO,   KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,         KC_C,   KC_P7,   KC_P8,   KC_P9,    KC_D,  KC_TAB,
    _______,   KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,         KC_B,   KC_P4,   KC_P5,   KC_P6,    KC_E, KC_BSPC,
      TG(5), KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS,  KC_NUM,         KC_A,   KC_P1,   KC_P2,   KC_P3,    KC_F, KC_PENT,
                               KC_BTN3, KC_BTN2, KC_BTN1,      KC_COLN,   KC_P0, KC_PDOT
    ),

  // layer 6 - settings
  [6] = LAYOUT_split_3x6_3(
    RGB_TOG, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,        NK_ON, CG_SWAP, _______, _______, _______, _______,
    _______, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,      NK_OFF, CG_NORM, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,        DF(0),   DF(1), KB_SET
    )
};

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

