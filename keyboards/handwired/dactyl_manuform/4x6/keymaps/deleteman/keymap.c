#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _MOUSE 3
#define _SYMBOLS 4

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MOUSE MO(_MOUSE)
#define SYMBOLS MO(_SYMBOLS)

#include "version.h"
#include "keymap_spanish.h"


enum my_keycodes {
    SQR_BRACKET_OPEN=SAFE_RANGE,
    SQR_BRACKET_CLOSE,
    COMM_AT,
    DOT_HASH,
    LT_HT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  |                                                         |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    ES_NTIL, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    COMM_AT, DOT_HASH,  KC_SLSH, KC_RIGHT_SHIFT,
                          KC_LBRC, KC_RBRC,                                                KC_PLUS, KC_EXCLAIM,
                                            RAISE,   KC_SPC,             KC_ENT,  LOWER,
                                            KC_SCLN,  KC_BSPC,            KC_LGUI,  KC_DEL,
                                            LT_HT, MOUSE,            KC_RIGHT_CTRL , KC_LALT
    ),

    [_LOWER] = LAYOUT(
        RGB_TOG, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_RGBTEST, KC_LBRC,             KC_RBRC, KC_7,   KC_8,   KC_9,   QK_BOOT,   KC_PLUS,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,                                           KC_RPRN, KC_4,   KC_5,   KC_6,   KC_MINS, KC_PIPE,
        KC_LSFT, _______, _______, _______, _______, _______,                                           _______, KC_1,   KC_2,   KC_3,   KC_EQL,  KC_UNDS,
                          _______, KC_PSCR,                                                                             _______, KC_0,
                                            _______, _______,                                       _______, _______,
                                            _______, _______,                                       RGB_MODE_BREATHE, _______,
                                            SYMBOLS, _______,                                       RGB_TOG, _______
    ),

    [_RAISE] = LAYOUT(
        RGB_TOG, QK_BOOT,   _______, KC_UP,  _______, KC_LBRC,             KC_RBRC, _______, KC_NLCK, KC_INS,  KC_SLCK, KC_MUTE,
        _______,_______, KC_LEFT,KC_DOWN, KC_RGHT,  KC_LPRN,             KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,      
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, KC_VOLD,
                          _______, _______,                                                 KC_EQL,  _______,
                                            _______, _______,             _______, SYMBOLS,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    ),
    [_MOUSE] = LAYOUT(
        _______, QK_BOOT,_______, KC_MU, _______, KC_LBRC,             KC_RBRC, _______, KC_NLCK, KC_INS,  KC_SLCK, KC_MUTE,
        _______,_______, KC_ML,KC_MD, KC_MR,  KC_LPRN,                     KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, KC_VOLD,
                          _______, _______,                                                 KC_EQL,  _______,
                                            _______, _______,             KC_MB1, KC_MB2,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    ),
  [_SYMBOLS] = LAYOUT(
        _______, _______,_______, KC_MU, _______, KC_LBRC,             KC_RBRC, _______, KC_NLCK, KC_INS,  KC_SLCK, KC_MUTE,
        _______,_______, KC_ML,KC_MD, KC_MR,  KC_LPRN,                    RALT(KC_LBRC), RALT(KC_RBRC), KC_MPLY, KC_MNXT, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______,             RALT(KC_QUOT), RALT(KC_BSLS), _______, _______, _______, KC_VOLD,
                          _______, _______,                                                 KC_EQL,  _______,
                                            _______, _______,             KC_MB1, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    ),


};
        
void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_at_timer;
    static uint16_t my_hash_timer;

    switch (keycode) {
        case LT_HT:
         if(record->event.pressed) {
                my_at_timer = timer_read();
            } else {
                if (timer_elapsed(my_at_timer) < TAPPING_TERM) {
                    tap_code(KC_GRV); // Change the character(s) to be sent on tap here
                } else {
                    SEND_STRING(SS_LSFT("º"));
                }
            }
            return false;
        
        case COMM_AT:
         if(record->event.pressed) {
                my_at_timer = timer_read();
            } else {
                if (timer_elapsed(my_at_timer) < TAPPING_TERM) {
                    SEND_STRING(","); // Change the character(s) to be sent on tap here
                } else {
                    SEND_STRING(SS_LALT("2"));
                }
            }
            return false;
        case DOT_HASH:
         if(record->event.pressed) {
                my_hash_timer = timer_read();
                //register_code(KC_DOT); // Change the key to be held here
            } else {
                //unregister_code(KC_DOT); // Change the key that was held here, too!
                if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
                    SEND_STRING("."); // Change the character(s) to be sent on tap here
                } else {
                    SEND_STRING(SS_LALT("3"));
                    //SEND_STRING("#"); // Change the character(s) to be sent on tap here
                }
            }
            return false; // We handled this keypress
        case SQR_BRACKET_CLOSE:
            if (record->event.pressed) {
                SEND_STRING("]");
            }
            break;
        case SQR_BRACKET_OPEN:
            if (record->event.pressed) {
                    SEND_STRING("[");
            }
            break;

    }

    return true;
}
