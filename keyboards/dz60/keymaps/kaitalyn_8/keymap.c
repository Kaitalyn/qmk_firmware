#include QMK_KEYBOARD_H

#define ONESHOT_TAP_TOGGLE 3

#define ARROW 1
#define FN 2
#define NUMPAD 3
#define RGB 4
#define CUSTOM 5

//EEPROM definitions
typedef union {
  uint32_t raw;
  struct {
    uint16_t     user_rgb_mode:16;
  };
} user_config_t;

user_config_t user_config;

//Custom Keycode declaration
enum my_keycodes {
  saveRGB = SAFE_RANGE,
  lightOFF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0 Deufault Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | GESC|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | OSL(5)  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   RShift  | Up  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl |  Cmd  |  Alt  |              Space               | Alt | left | -- | down | right|
 * `-----------------------------------------------------------------------------------------'
 */
	[0] = LAYOUT_60_ansi(
  KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, \
  OSL(CUSTOM), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, \
  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_NO , KC_RGHT\
  ),
	
/* Layer 5 Custom Directory Layer
 * ,-----------------------------------------------------------------------------------------.
 * |  ~` | F1 |  F2 | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |   DEL      |
 * |-----------------------------------------------------------------------------------------+
 * |  Tab   | -vol|  up |+vol |mute |     |scrlk| ins | hom |pg up|     |      | Prnt |  BKS |
 * |-----------------------------------------------------------------------------------------+
 * |   NO    |left | down| rght|!!!!!|     |pause|!DEL!| end |pg dn| CAPS|Eject |  Enter     |
 * |-----------------------------------------------------------------------------------------+
 * |  Shift    | prev| nxt | play|     |     | loff|ctrl2|ctrl1| Wake|Sleep|  Shift  | to(2) |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl |  Cmd  |  Alt  |         Space                    | - | to(1) | - | to(3) | to(4) |
 * `-----------------------------------------------------------------------------------------'
 */
	[CUSTOM] = LAYOUT_60_ansi(
  KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, \
  KC_TAB, KC_VOLD, KC_UP, KC_VOLU, KC_MUTE, KC_NO, KC_SLCK, KC_INS, KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_PSCR, KC_BSPC, \
  KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_PAUS, KC_DEL, KC_END, KC_PGDN, KC_CAPS, KC_EJCT, KC_PENT, \
  KC_LSFT, KC_MPRV, KC_MNXT, KC_MPLY, KC_NO, KC_NO, lightOFF, LCTL(KC_P2), LCTL(KC_P1), KC_WAKE, KC_SLEP, KC_RSFT, TO(NUMPAD), \
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, TO(ARROW), TO(FN), KC_NO, TO(RGB) \
  ),

  /* Layer 1 Arrow Keys
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     | up  |     |     |      |      |      |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |LEFT!|down |right|     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |                 |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |                                  |       |       |       |       |
 * `-----------------------------------------------------------------------------------------'
 */
	[ARROW] = LAYOUT_60_ansi(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //14
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //14
  TG(ARROW), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, //13
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //12
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS //8
  ),

  /* Layer 2 Function Keys
 * ,-----------------------------------------------------------------------------------------.
 * | GESC| F1 |  F2 | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | BCKSPCE    |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |      |      |      |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |                 |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |                                  |       |       |       |       |
 * `-----------------------------------------------------------------------------------------'
 */
	[FN] = LAYOUT_60_ansi(
  KC_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC, //14
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //14
  TG(FN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //13
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //12
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS //8
  ),

  /* Layer 3 Numpad
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |NumLk|  /  |  *  |  -  |     |     |           |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |  7  |  8  |  9  |  +  |      |      |      |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |  4  |  5  |  6  | Entr|     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |  0  |  1  |  2  |  3  |  .  |                 |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |                                  |       |       |       |       |
 * `-----------------------------------------------------------------------------------------'
 */
	[NUMPAD] = LAYOUT_60_ansi(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, //14
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, //14
  TG(NUMPAD), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_ENT, KC_TRNS, KC_TRNS, //13
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_TRNS, KC_TRNS, //12
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS //8
  ),

  /* Layer 4 RGB settings
 * ,-----------------------------------------------------------------------------------------.
 * |     |+brit|-brit|+efct|-efct|     |     |     |     |     |     |     |     |           |
 * |-----------------------------------------------------------------------------------------+
 * |        |+sat |-sat |+bl  |-bl  |     |     |     |     |     |     |      |      |      |
 * |-----------------------------------------------------------------------------------------+
 * |         |+hue |-hue |bl tg|bl bt|     |     |     |     |     |     |     | saveRGB     |
 * |-----------------------------------------------------------------------------------------+
 * |           |+mode|-mode|rgbtg|     |     |     |     |     |     |     |                 |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |                                  |       |       |       |       |
 * `-----------------------------------------------------------------------------------------'
 */
	[RGB] = LAYOUT_60_ansi(
  KC_NO, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
  KC_NO, RGB_SAI, RGB_SAD, BL_INC, BL_DEC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
  TG(RGB), RGB_HUI, RGB_HUD, BL_TOGG, BL_BRTG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, saveRGB, 
  KC_NO, RGB_MOD, RGB_RMOD, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO , 
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO 
  )
};

void keyboard_post_init_user(void) { //Keyboard init
  user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {  // EEPROM init
  user_config.raw = 0;
  user_config.user_rgb_mode = 13; //Swirl on default
  eeconfig_update_user(user_config.raw); // Write to EEPROM
}

/*RGB underglow top: left 0 - 7 right, bottom: 15 - 8
13 for swirl, 32 for static, 25 for static rainbow*/
#ifdef RGBLIGHT_ENABLE

bool rgbon = true;
void rgbwhite(void){
  if (rgbon == false) {
        rgblight_disable_noeeprom();
  }
  rgblight_sethsv_at(111, 16, 100, 6);
  rgblight_sethsv_at(111, 16, 100, 7);
  rgblight_sethsv_at(111, 16, 100, 8);
  rgblight_sethsv_at(111, 16, 100, 9);
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case CUSTOM:
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(23);
      break;
    case ARROW:
      rgblight_mode_noeeprom(29);
      rgbwhite();
      break;
    case FN:
      rgblight_mode_noeeprom(30);
      rgbwhite();
      break;
    case NUMPAD:
      rgblight_mode_noeeprom(31);
      rgbwhite();
      break;
    case RGB:
      rgbwhite();
      rgblight_mode_noeeprom(user_config.user_rgb_mode);
      break;
    default:
      if (rgbon == false) {
        rgblight_disable_noeeprom();
      }
      else{
        rgblight_enable_noeeprom();
      }
      rgblight_mode_noeeprom(user_config.user_rgb_mode); 
      break;
    }
	return state;
  }
#endif

//Custom Keycode Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode){
    case saveRGB:
      if(record->event.pressed) {
        user_config.user_rgb_mode = rgblight_get_mode();
        eeconfig_update_user(user_config.raw);
      }
      return false;
    case lightOFF:
      if(record->event.pressed) {
        rgblight_toggle_noeeprom();
        rgbon = !rgbon;
      }
      return true;
    default:
      return true;
  }
}