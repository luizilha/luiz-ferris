// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};

enum ferris_tap_dances {
  TD_Q_ESC
};


#define CEDILHA A(ALGR(KC_COMM))
#define SPC_NUM LT(2, KC_SPC)
#define BSPC_SYB  LT(1, KC_BSPC)
// press keys middle
#define SUP_F   LGUI_T(KC_F)
#define SFT_D   LSFT_T(KC_D)
#define SFT_A   LSFT_T(KC_A)
#define SFT_DQT   LSFT_T(KC_DQT)
#define SFT_K   LSFT_T(KC_K)
#define ALT_SL  LALT_T(KC_SLSH)
#define CTL_TAB LCTL_T(KC_TAB)
#define ALT_ENT LALT_T(KC_ENT) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* QWERTY */
    KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,        KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,   
    SFT_A, KC_S,  KC_D, SUP_F,    KC_G,        KC_H,    KC_J,  KC_K,    KC_L,   SFT_DQT,
    KC_Z,  KC_X,  KC_C,  KC_V,    KC_B,        KC_N,    KC_M,  KC_COMM, KC_DOT, ALT_SL,
                                  CTL_TAB, SPC_NUM,  BSPC_SYB, KC_ENT  
  ),

  [1] = LAYOUT( /* [> LOWER <] */
   	KC_AT,   KC_HASH, KC_DLR,  KC_COLN,  KC_SCLN, KC_NO,   KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
        KC_CIRC, KC_TILD, KC_GRV,  KC_QUOT,  KC_EXLM, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUES,
        KC_PIPE, KC_AMPR, CEDILHA, KC_UNDS,  KC_NO,   KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, KC_BSLS,
         			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [2] = LAYOUT( /* [> RAISE <] */
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_7, KC_8, KC_9, KC_NO,
    KC_PMNS, KC_PPLS, KC_PERC, KC_PEQL, KC_ESC, KC_PAST, KC_4, KC_5, KC_6, KC_NO,  
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG(3),  KC_NO,   KC_1, KC_2, KC_3, KC_NO,
                         KC_TRNS, KC_TRNS, KC_DEL, KC_0
  ),
  
  [3] = LAYOUT( /* [> RAISE <] */
    TG(3),  KC_ESC, KC_W,  KC_ENT, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,  KC_A,   KC_S,  KC_D,   KC_NO,  KC_NO,   KC_U,    KC_I,    KC_O,    KC_NO,
    KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,   KC_J,    KC_K,    KC_L,    KC_NO, 
                                    KC_TRNS, KC_W, KC_SPC, KC_TRNS
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
