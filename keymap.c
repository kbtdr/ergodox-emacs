/*
Copyright 2020 David McHale <dr.d.mchale@protonmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
	 #include "ergodox_ez.h"
	 #include "version.h"
	 #include "action_layer.h"
	 #include "action_util.h"
	 #include "timer.h"

	 // A 'transparent' key code (that falls back to the layers below it)

	 #define ____ KC_TRANSPARENT

	 // A 'blocking' key code. Does nothing but prevent falling back to another layer

	 #define XXX KC_NO

	 // Emacs keychords

	 /* #define MK_C_X LCTL(KC_X)    // ctrl + x                        */
	 /* #define MK_C_C LCTL(KC_C)    // ctrl + c                        */
	 /* #define MK_C_U LCTL(KC_U)    // ctrl + u                        */
	 /* #define MK_C_W LCTL(KC_W)    // ctrl + w                        */
	 /* #define MK_C_R LCTL(KC_R)    // ctrl + r        search backward */
	 /* #define MK_C_S LCTL(KC_S)    // ctrl + s        search forward  */
	 /* #define MK_C_T LCTL(KC_T)    // ctrl + t                        */
	 /* #define MK_C_A LCTL(KC_A)    // ctrl + a        start of line   */
	 /* #define MK_C_E LCTL(KC_E)    // ctrl + e        end of line     */
	 /* #define MK_C_V LCTL(KC_V)    // ctrl + v        page up         */
	 /* #define MK_M_V LALT(KC_V)    // alt + v         page down       */
	 /* #define MK_M_X LALT(KC_X)    // M x                             */
	  #define MK_C_M LCTL(KC_LALT) // C-M


	 // function declarations used in Tap Dance allowing use in all keymaps

	 int cur_dance (qk_tap_dance_state_t *state);

	 //Standard  emacs keys

	 void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_pip_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_pip_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_qum_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_qum_reset (qk_tap_dance_state_t *state, void *user_data);


	 void dance_caa_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_caa_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_sch_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_sch_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_ccp_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_ccp_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_file_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_file_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_reg_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_reg_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_nar_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_nar_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_wid_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_wid_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_orgstp_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_orgstp_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_orgstd_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_orgstd_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_orgstmu_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_orgstmu_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_orgstmd_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_orgstmd_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_rep_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_rep_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_bkd_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_bkd_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_fwd_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_fwd_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_sta_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_sta_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_end_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_end_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_lbr_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_lbr_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_rbr_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_rbr_reset (qk_tap_dance_state_t *state, void *user_data);

	 void dance_cal_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_cal_reset (qk_tap_dance_state_t *state, void *user_data);

	 // Custom keys
	 void dance_ess_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_ess_reset (qk_tap_dance_state_t *state, void *user_data);


	 void dance_tog_finished (qk_tap_dance_state_t *state, void *user_data);

	 void dance_tog_reset (qk_tap_dance_state_t *state, void *user_data);


	 // structure definitions used in Tap Dance

	 typedef struct {
	   bool is_press_action;
	   int state;
	 } tap;

	 enum {
	   SINGLE_TAP = 1,
	   SINGLE_HOLD = 2,
	   DOUBLE_TAP = 3,
	   DOUBLE_HOLD = 4,
	   DOUBLE_SINGLE_TAP = 5, //send two single taps
	   TRIPLE_TAP = 6,
	   TRIPLE_HOLD = 7,
	   TRIPLE_SINGLE_TAP = 8, //send three single taps

	 };


	 /* Layers */

	 enum {
	   BASE = 0,
	   MEDIA,
	 };

	 /* Macros */

	 enum {
	   NONE = 0,
	   A_BSE,    // Toggle on Base layer and clear Numlock if set
	   A_MED,    // Toggle on Media layer and set NumLock

	 };

	 /* Fn keys */

	 enum {
	   F_LSFT = 0,
	   F_RSFT,
	   F_CTRL,
	   F_LALT,
	 };

	 /* States & timers */

	 uint16_t gui_timer = 0;

	 /* Custom keycodes for Tap Dance aCTions*/

	 enum {

	   CT_CLN = 0,     // single tap - semi colon,    double - colon
	   CT_PIP,         // single tap - back slash     double - pipe
	   CT_QUM,         // single tap - forward slash  double - question mark

	   CT_SCH,         // single tap - forward search double - backward search
	   CT_CCP,         // single tap - cut            double - copy                        triple - paste
	   CT_CAA,         // single hold - ctrl          double hold - alt
	   CT_FIL,         // single tap - find file,     double - save file,                  triple - write file, quadruple - sudo open read only file
	   CT_REG,         // single tap - bookmark jump  double - register mark      double tap and hold - register menu
	   CT_NAR,         // single tap - comma          double - org narrow buffer
	   CT_WID,         // single tap - dot            double - org widen buffer
	   CT_OSP,         // single tap - ctrl+c         double - org structure item promote  triple - org structure subtree promote
	   CT_OSD,         // single tap - ctrl+u         double - org structure item demote   triple - org structure subtree demote
	   CT_OSMU,        // single tap - ctrl+x         double - org structure - move item up
	   CT_OSMD,        // single tap - M-x            double - org structure - move item down
	   CT_REP,         // single tap - query-replace, double - query-replace-regexp
	   CT_BKD,         // single tap - C-b            double - C-a start of line
	   CT_FWD,         // single tap - C-f            double - C-e end of line
	   CT_STA,         // single tap - page up        double - buffer start
	   CT_END,         // single tap - page down      double - buffer end
	   CT_LBR,         // single tap - Left Bracket   double - left square bracket          triple - left curly bracket
	   CT_RBR,         // single tap - Right Bracket  double - right square bracket         triple - right curly bracket
	   CT_CAL,         // single tap - calc

	   CT_ESS,         // single tap - ESS

	   CT_TOG          // single tap - line nos       double - custom theme                 triple - olivetti mode

	 };

	 /* Custom Keycodes for layer toggling*/

	 enum {
	   TG_0 = SAFE_RANGE,
	   TG_1
	 };


	 const uint16_t PROGMEM  keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	     /*
					  Keymap: Default EMACS Layer

 ,--------------------------------------------------.           ,--------------------------------------------------.
 | CAPS   |   1  |   2  |   3  |   4  |   5  | ESC  |           | INS  |   6  |   7  |   8  |   9  |   0  |   =    |
 |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 | Tab    |   Q  |   W  |   E  |   R  |   T  | cut  |           | book |   Y  |   U  |   I  |   O  |   P  |   -    |
 |--------+------+------+------+------+------| copy |           | reg  |------+------+------+------+------+--------|
 |        |      |      |      |      |      | paste|           |      |      |      |      |      |      |        |
 | C-M    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 |        |      |      |      |      |      | LCtrl|           | LAlt |      |      |  ORG |  ORG |      |        |
 |   \|   |   Z  |   X  |   C  |   V  |   B  | onesh|           | onesh|   N  |   M  |   ,  |   .  |   /  |   #    |
 `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   |  `¬  | Home | End  |Forw  | Back |                                       | ([{  | )]}  | TOGS | TG_1 | TG_0 |
   `----------------------------------'                                       `----------------------------------'
				    ,---------------.           ,-------------.
				    | Files|Replace |           |Search| Bksp |
			     ,------|------|--------|           |------+------+------.
			     |      |      |   ORG  |           | ORG  |      |      |
			     |      |      |   C-c  |           | C-u  |      |
			     | Space| LSFT |--------|           |------| RSFT | Enter|
			     |      |      |   ORG  |           | ORG  |      |      |
			     |      | onesh|   C-x  |           | M-x  | onesh|      |
			     `----------------------'           `--------------------'
	      */


	 [BASE] = LAYOUT_ergodox(
		// left hand
		MK_C_M      ,KC_1      ,KC_2       ,KC_3       ,KC_4       ,KC_5       ,KC_ESC
	       ,KC_TAB      ,KC_Q      ,KC_W       ,KC_E       ,KC_R       ,KC_T       ,TD(CT_CCP)
	       ,KC_CAPS     ,KC_A      ,KC_S       ,KC_D       ,KC_F       ,KC_G
	       ,TD(CT_PIP)  ,KC_Z      ,KC_X       ,KC_C       ,KC_V       ,KC_B       ,OSM(MOD_LCTL)
	       ,KC_GRV      ,TD(CT_STA),TD(CT_END) ,TD(CT_BKD) ,TD(CT_FWD)

									   ,TD(CT_FIL) ,TD(CT_REP)
										       ,TD(CT_OSP)
								     ,KC_SPC, F(F_LSFT),TD(CT_OSMU)

									 // right hand
									,KC_INS        ,KC_6       ,KC_7       ,KC_8       ,KC_9       ,KC_0       ,KC_EQL
									,TD(CT_REG)    ,KC_Y       ,KC_U       ,KC_I       ,KC_O       ,KC_P       ,KC_MINS
										       ,KC_H       ,KC_J       ,KC_K       ,KC_L       ,TD(CT_CLN) ,KC_QUOT
									,OSM(MOD_LALT) ,KC_N       ,KC_M       ,TD(CT_NAR) ,TD(CT_WID) ,TD(CT_QUM) ,KC_NUHS
												   ,TD(CT_LBR) ,TD(CT_RBR) ,TD(CT_TOG) ,TO(1)     ,TO(0)

									,TD(CT_SCH) ,KC_BSPC
									,TD(CT_OSD)
									,TD(CT_OSMD),F(F_RSFT) ,KC_ENT
	     ),



	      /*
	 Keymap: Layer 1 Numeric Keypad, Media Player Keys

,--------------------------------------------------.           ,--------------------------------------------------.
| CAPS   |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |   F7 |  F8  |  F9  |  F10 | NumLk  |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
| Tab    |   Q  |   W  |   E  |   R  | Mute | cut  |           | book | CALC |   7  |   8  |   9  |   *  |   /    |
|--------+------+------+------+------+------| copy |           | reg  |------+------+------+------+------+--------|
|        |      |      |      |      |      |paste |           |      |      |      |      |      |      |        |
| C-M    |   A  |   S  |   D  |   F  | Vol+ |------|           |------| ESS  |   4  |   5  |   6  |   -  |  Clear |
|--------+------+------+------+------+------| LCtrl|           | LAlt |------+------+------+------+------+--------|
|     \| |   Z  |   X  |   C  |   V  | Vol- | onesh|           | onesh|  N   |   1  |   2  |   3  |   +  |   =    |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |  `¬  | Prev | Next | Stop | Play |                                       |   0  |   .  | Enter| TG_1 | TG_0 |
  `----------------------------------'                                       `----------------------------------'
					,---------------.       ,-------------.
					| Files|Replace |       |Search| Bksp |
				 ,------|------|--------|       |------+------+------.
				 |      |      |   ORG  |       | ORG  |      |      |
				 |      |      |   C-c  |       | C-u  |      |      |
				 | Space| LSFT |--------|       |------| RSFT | Enter|
				 |      |      |   ORG  |       | ORG  |      |      |
				 |      | onesh|   C-x  |       | M-x  | onesh|      |
				 `----------------------'       `--------------------'



	      */

		 [MEDIA] = LAYOUT_ergodox(
		 // layer 1: numpad, media, and function keys
		 // left hand
		 ____ , KC_F1,  KC_F2,   KC_F3, KC_F4,    KC_F5,KC_F11,
		 ____,   ____,   ____,    ____,  ____,  KC_MUTE,  ____,
		 ____,   ____,   ____,    ____,  ____,  KC_VOLU,
		 ____,   ____,   ____,    ____,  ____,  KC_VOLD,  ____,
		 ____,KC_MPRV,KC_MNXT, KC_MSTP,KC_MPLY,
							   ____,  ____,
								  ____,
						      ____,____,  ____,

									   // right hand
									      KC_F12, KC_F6  ,KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_NLCK,
										____,TD(CT_CAL) ,KC_P7,  KC_P8,  KC_P9,  KC_PAST, KC_PSLS,
										     TD(CT_ESS) ,KC_P4,  KC_P5,  KC_P6,  KC_PMNS, KC_CLEAR,
										____,   ____    ,KC_P1,  KC_P2,  KC_P3,  KC_PPLS, KC_PEQL,
												 KC_P0,KC_PDOT,  KC_PENT,   ____, ____,
										____,____,
										____,
										____,____,____
	     ),



	 };

	 /* id for user defined functions & macros */

	 const uint16_t PROGMEM fn_actions[] = {
	    [F_LSFT]  = ACTION_MODS_ONESHOT (MOD_LSFT)
	   ,[F_RSFT]  = ACTION_MODS_ONESHOT (MOD_RSFT)
	   ,[F_CTRL]  = ACTION_MODS_ONESHOT (MOD_LCTL)
	   ,[F_LALT]  = ACTION_MODS_ONESHOT (MOD_LALT)
	 };


	 // Tap Dance function definitions



	 int cur_dance (qk_tap_dance_state_t *state) {
	   if (state->count == 1) {
	     if (state->interrupted || !state->pressed)  return SINGLE_TAP;
	     //key has not been interrupted, but key is still held. Means you want to send a 'HOLD'.
	     else return SINGLE_HOLD;
	   }
	   else if (state->count == 2) {
	     /*
	      * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
	      * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
	      * keystrokes of the key, and not the 'double tap' action/macro.
	     */
	     if (state->interrupted) return DOUBLE_SINGLE_TAP;
	     else if (state->pressed) return DOUBLE_HOLD;
	     else return DOUBLE_TAP;
	   }
	   //Assumes no one is trying to type the same letter three times (at least not quickly).
	   //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
	   //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
	   if (state->count == 3) {
	     if (state->interrupted) return TRIPLE_SINGLE_TAP;
	     else if (state->pressed) return TRIPLE_HOLD;
	     else return TRIPLE_TAP;
	   }
	   //

	   else return 8; //magic number. At some point this method will expand to work for more presses
	 }


	 // Tap dances to save pressing shift

	 // Colon
	 void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
	   if (state->count == 1) {
	     register_code (KC_SCLN);
	   } else {
	     register_code (KC_RSFT);
	     register_code (KC_SCLN);
	   }
	 }

	 void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
	   if (state->count == 1) {
	     unregister_code (KC_SCLN);
	   } else {
	      unregister_code (KC_RSFT);
	      unregister_code (KC_SCLN);
	   }
	 }

	 // Pipe
	 void dance_pip_finished (qk_tap_dance_state_t *state, void *user_data) {
	   if (state->count == 1) {
	     register_code (KC_NUBS);
	   } else {
	     register_code (KC_RSFT);
	     register_code (KC_NUBS);
	   }
	 }

	 void dance_pip_reset (qk_tap_dance_state_t *state, void *user_data) {
	   if (state->count == 1) {
	     unregister_code (KC_NUBS);
	   } else {
	      unregister_code (KC_RSFT);
	      unregister_code (KC_NUBS);
	   }
	 }

	 // Question mark
	 void dance_qum_finished (qk_tap_dance_state_t *state, void *user_data) {
	   if (state->count == 1) {
	     register_code (KC_SLSH);
	   } else {
	     register_code (KC_RSFT);
	     register_code (KC_SLSH);
	   }
	 }

	 void dance_qum_reset (qk_tap_dance_state_t *state, void *user_data) {
	   if (state->count == 1) {
	     unregister_code (KC_SLSH);
	   } else {
	      unregister_code (KC_RSFT);
	      unregister_code (KC_SLSH);
	   }
	 }


	 // Standard Emacs functions

	 // Cut, copy, paste
	 static tap ccp_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_ccp_finished (qk_tap_dance_state_t *state, void *user_data) {
	   ccp_tap_state.state = cur_dance(state);
	   switch (ccp_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LCTRL);register_code(KC_W); break;   // ctrl+w  cut
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: register_code(KC_LALT);register_code(KC_W);  break;   // alt+w   copy
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: register_code(KC_LCTRL);register_code(KC_Y); break;   // ctrl+y  paste
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_ccp_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (ccp_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_W); break;   // ctrl+w  cut
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: unregister_code(KC_LALT);unregister_code(KC_W);  break;   // alt+w   copy
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_Y); break;   // ctrl+y  paste
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	   ccp_tap_state.state = 0;
	 }


	 // ctrl and alt
	 static tap caa_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_caa_finished (qk_tap_dance_state_t *state, void *user_data) {
	   caa_tap_state.state = cur_dance(state);
	   switch (caa_tap_state.state) {
	     case SINGLE_TAP: break;
	     case SINGLE_HOLD: register_code(KC_LCTRL); break;
	     case DOUBLE_TAP: break;
	     case DOUBLE_HOLD:  register_code(KC_LALT); break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP:        break;
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_caa_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (caa_tap_state.state) {
	     case SINGLE_TAP: break;
	     case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
	     case DOUBLE_TAP: break;
	     case DOUBLE_HOLD:  unregister_code(KC_LALT); break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP:        break;
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	   caa_tap_state.state = 0;
	 }

	 // File - read, save, write
	 static tap file_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_file_finished (qk_tap_dance_state_t *state, void *user_data) {
	   file_tap_state.state = cur_dance(state);
	   switch (file_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LCTRL);register_code(KC_X);register_code(KC_LCTRL);register_code(KC_F); break;     // ctrl+x ctrl+f
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: register_code(KC_LCTRL);register_code(KC_X);register_code(KC_LCTRL);register_code(KC_S); break;     // ctrl+x ctrl+s
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: register_code(KC_LCTRL);register_code(KC_X);register_code(KC_LCTRL);register_code(KC_W); break;     // ctrl+x ctrl+w
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_file_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (file_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_X);unregister_code(KC_LCTRL);unregister_code(KC_F); break;     // ctrl+x ctrl+f
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_X);unregister_code(KC_LCTRL);unregister_code(KC_S); break;     // ctrl+x ctrl+s
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_X);unregister_code(KC_LCTRL);unregister_code(KC_W); break;     // ctrl+x ctrl+w
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	   file_tap_state.state = 0;
	 }

	 // Bookmark and Registers
	 static tap reg_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_reg_finished (qk_tap_dance_state_t *state, void *user_data) {
	   reg_tap_state.state = cur_dance(state);
	   switch (reg_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LCTRL);register_code(KC_X);unregister_code(KC_LCTL);register_code(KC_R);register_code(KC_B); break; // ctrl+x r b bookmark jump
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: register_code(KC_LCTRL);register_code(KC_X);unregister_code(KC_LCTL);register_code(KC_R);register_code(KC_M); break;   // ctrl+x r m register mark
	     case DOUBLE_HOLD: register_code(KC_LCTRL);register_code(KC_X);unregister_code(KC_LCTL);register_code(KC_R); break;                    // ctrl+x r    register popup menu
	   }
	 }

	 void dance_reg_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (reg_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_X);unregister_code(KC_R);unregister_code(KC_B); break;     // ctrl+x r b bookmark jump
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_X);unregister_code(KC_R);unregister_code(KC_M); break;     // ctrl+x r m register mark
	     case DOUBLE_HOLD: unregister_code(KC_LCTRL);unregister_code(KC_X);unregister_code(KC_R); break;                          // ctrl+x r    register popup menu
	   }
	   reg_tap_state.state = 0;
	 }

	 // Orgmode - narrow buffer
	 static tap nar_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_nar_finished (qk_tap_dance_state_t *state, void *user_data) {
	   nar_tap_state.state = cur_dance(state);
	   switch (nar_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_COMMA); break;     //
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP: register_code(KC_LCTRL);register_code(KC_X);unregister_code(KC_LCTRL);register_code(KC_N); register_code(KC_S); break;  // ctrl+x n s  narrow subtree
	     case DOUBLE_HOLD: break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_nar_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (nar_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_COMMA); break;     //
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_X); unregister_code(KC_N); unregister_code(KC_S); break;
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	   nar_tap_state.state = 0;
	 }

	 // Orgmode - widen buffer
	 static tap wid_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_wid_finished (qk_tap_dance_state_t *state, void *user_data) {
	   wid_tap_state.state = cur_dance(state);
	   switch (wid_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_DOT); break;     //
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: register_code(KC_LCTRL);register_code(KC_X); unregister_code(KC_LCTRL); register_code(KC_N); register_code(KC_W); break;  // ctrl+x n w  widen subtree
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_wid_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (wid_tap_state.state) {
	     case SINGLE_TAP:  unregister_code(KC_DOT); break;     //
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP:  unregister_code(KC_LCTRL);unregister_code(KC_X); unregister_code(KC_N); unregister_code(KC_W); break;
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	   wid_tap_state.state = 0;
	 }

	 // Orgmode structure - promote
	 static tap orgstp_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_orgstp_finished (qk_tap_dance_state_t *state, void *user_data) {
	   orgstp_tap_state.state = cur_dance(state);
	   switch (orgstp_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LCTL);register_code(KC_C);    break;  // ctrl+c
	     case SINGLE_HOLD: register_code(KC_LEFT);                       break;  // Left Arrow
	     case DOUBLE_TAP: register_code(KC_LALT);register_code(KC_LEFT); break;  // M-<left>
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: register_code(KC_LALT);register_code(KC_LSHIFT);register_code(KC_LEFT); break;     // M-Shift-<left>
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_orgstp_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (orgstp_tap_state.state) {
	     case SINGLE_TAP:  unregister_code(KC_LCTL);unregister_code(KC_C);    break;  // ctrl+c
	     case SINGLE_HOLD: unregister_code(KC_LEFT);                          break;  // Left Arrow
	     case DOUBLE_TAP:  unregister_code(KC_LALT);unregister_code(KC_LEFT); break;  // M-<left>
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: unregister_code(KC_LALT);unregister_code(KC_LSHIFT);unregister_code(KC_LEFT); break;     // M-Shift-<left>
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	   orgstp_tap_state.state = 0;
	 }

	 // Orgmode structure - demote
	 static tap orgstd_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_orgstd_finished (qk_tap_dance_state_t *state, void *user_data) {
	   orgstd_tap_state.state = cur_dance(state);
	   switch (orgstd_tap_state.state) {
	     case SINGLE_TAP:  register_code(KC_LCTL);register_code(KC_U);     break;  // ctrl+u
	     case SINGLE_HOLD: register_code(KC_RIGHT);                        break;  // Right Arrow
	     case DOUBLE_TAP:  register_code(KC_LALT);register_code(KC_RIGHT); break;  // M-<right>
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: register_code(KC_LALT);register_code(KC_RSHIFT);register_code(KC_RIGHT); break;     // M-Shift-<right>
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_orgstd_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (orgstd_tap_state.state) {
	     case SINGLE_TAP:  unregister_code(KC_LCTL);unregister_code(KC_U);     break;  // ctrl+u
	     case SINGLE_HOLD: unregister_code(KC_RIGHT);                          break;  // Right Arrow
	     case DOUBLE_TAP:  unregister_code(KC_LALT);unregister_code(KC_RIGHT); break;  // M-<right>
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: unregister_code(KC_LALT);unregister_code(KC_RSHIFT);unregister_code(KC_RGHT); break;     // M-Shift-<right>
	     case TRIPLE_HOLD:       break;
	     case TRIPLE_SINGLE_TAP: break;
	   }
	   orgstd_tap_state.state = 0;
	 }

	 // Orgmode structure - move up
	 static tap orgstmu_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_orgstmu_finished (qk_tap_dance_state_t *state, void *user_data) {
	   orgstmu_tap_state.state = cur_dance(state);
	   switch (orgstmu_tap_state.state) {
	     case SINGLE_TAP:  register_code(KC_LCTRL);register_code(KC_X);  break;    // C-x
	     case SINGLE_HOLD: register_code(KC_UP);                         break;    // Up Arrow
	     case DOUBLE_TAP:  register_code(KC_LALT);register_code(KC_UP);  break;    // M-<up>
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_orgstmu_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (orgstmu_tap_state.state) {
	     case SINGLE_TAP:  unregister_code(KC_LCTRL);unregister_code(KC_X);  break;    // C-x
	     case SINGLE_HOLD: unregister_code(KC_UP);                           break;    // Up Arrow
	     case DOUBLE_TAP:  unregister_code(KC_LALT);unregister_code(KC_UP);  break;    // M-<up>
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	   orgstmu_tap_state.state = 0;
	 }

	 // Orgmode structure - move down
	 static tap orgstmd_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_orgstmd_finished (qk_tap_dance_state_t *state, void *user_data) {
	   orgstmd_tap_state.state = cur_dance(state);
	   switch (orgstmd_tap_state.state) {
	     case SINGLE_TAP:  register_code(KC_LALT);register_code(KC_X);    break;  // M-x
	     case SINGLE_HOLD: register_code(KC_DOWN);                        break;  // Down Arrow
	     case DOUBLE_TAP:  register_code(KC_LALT);register_code(KC_DOWN); break;  // M-<down>
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_orgstmd_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (orgstmd_tap_state.state) {
	     case SINGLE_TAP:  unregister_code(KC_LALT);unregister_code(KC_X);    break;  // ctrl+x
	     case SINGLE_HOLD: unregister_code(KC_DOWN);                          break;  // Down Arrow
	     case DOUBLE_TAP:  unregister_code(KC_LALT);unregister_code(KC_DOWN); break;  // M-<down>
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	   orgstmd_tap_state.state = 0;
	 }

	 // Query replace
	 static tap rep_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_rep_finished (qk_tap_dance_state_t *state, void *user_data) {
	   rep_tap_state.state = cur_dance(state);
	   switch (rep_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LALT);register_code(KC_LSHIFT); register_code(KC_5); break;     // M-% query-replace
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: register_code(KC_LCTRL);register_code(KC_LALT);register_code(KC_LSHIFT); register_code(KC_5); break;  // C-M-% query-replace-regexp
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_rep_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (rep_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LALT);unregister_code(KC_LSHIFT); unregister_code(KC_5); break;     // M-% query-replace
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_LALT);unregister_code(KC_LSHIFT); unregister_code(KC_5); break;  // M-<right> query-replace-regexp
	     case DOUBLE_HOLD:       break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	   rep_tap_state.state = 0;
	 }

	 // Movement - backward
	 static tap bkd_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_bkd_finished (qk_tap_dance_state_t *state, void *user_data) {
	   bkd_tap_state.state = cur_dance(state);
	   switch (bkd_tap_state.state) {
	     case SINGLE_TAP:  register_code(KC_LCTRL); register_code(KC_B);    break;     // C-b backward character
	     case SINGLE_HOLD: register_code(KC_LALT);  register_code(KC_B);    break;     // M-b backward word
	     case DOUBLE_TAP:  register_code(KC_LCTRL); register_code(KC_P);    break;     // C-p backward line
	     case DOUBLE_HOLD: register_code(KC_LALT);  register_code(KC_A);    break;     // M-a backward sentence
	     case TRIPLE_TAP:  register_code(KC_LALT);  register_code(KC_RSHIFT); register_code(KC_RBRACKET); break;     // M-} backward paragraph
	     case TRIPLE_HOLD: register_code(KC_LCTRL); register_code(KC_V);    break;     // C-v backward page
	   }
	 }

	 void dance_bkd_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (bkd_tap_state.state) {
	     case SINGLE_TAP:  unregister_code(KC_LCTRL); unregister_code(KC_B);    break;     // C-b backward character
	     case SINGLE_HOLD: unregister_code(KC_LALT);  unregister_code(KC_B);    break;     // M-b backward word
	     case DOUBLE_TAP:  unregister_code(KC_LCTRL); unregister_code(KC_P);    break;     // C-p backward line
	     case DOUBLE_HOLD: unregister_code(KC_LALT);  unregister_code(KC_A);    break;     // M-a backward sentence
	     case TRIPLE_TAP:  unregister_code(KC_LALT);  unregister_code(KC_RSHIFT); unregister_code(KC_RBRACKET); break;     // M-} backward paragraph
	     case TRIPLE_HOLD: unregister_code(KC_LCTRL); unregister_code(KC_V);    break;     // C-v backward page
	   }
	   bkd_tap_state.state = 0;
	 }

	 // Movement - forward
	 static tap fwd_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_fwd_finished (qk_tap_dance_state_t *state, void *user_data) {
	   fwd_tap_state.state = cur_dance(state);
	   switch (fwd_tap_state.state) {
	     case SINGLE_TAP:  register_code(KC_LCTRL); register_code(KC_F);    break;     // C-f forward character
	     case SINGLE_HOLD: register_code(KC_LALT);  register_code(KC_F);    break;     // M-f forward word
	     case DOUBLE_TAP:  register_code(KC_LCTRL); register_code(KC_N);    break;     // C-n forward line
	     case DOUBLE_HOLD: register_code(KC_LALT);  register_code(KC_E);    break;     // M-e forward sentence
	     case TRIPLE_TAP:  register_code(KC_LALT);  register_code(KC_RSHIFT);register_code(KC_LBRACKET); break;     // M-{ forward paragraph
	     case TRIPLE_HOLD: register_code(KC_LALT);  register_code(KC_V);    break;     // M-v forward page
	   }
	 }

	 void dance_fwd_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (fwd_tap_state.state) {
	     case SINGLE_TAP:  unregister_code(KC_LCTRL); unregister_code(KC_F);    break;     // C-f forward character
	     case SINGLE_HOLD: unregister_code(KC_LALT);  unregister_code(KC_F);    break;     // M-f forward word
	     case DOUBLE_TAP:  unregister_code(KC_LCTRL); unregister_code(KC_N);    break;     // C-n forward line
	     case DOUBLE_HOLD: unregister_code(KC_LALT);  unregister_code(KC_E);    break;     // M-e forward sentence
	     case TRIPLE_TAP:  unregister_code(KC_LALT);  unregister_code(KC_RSHIFT);unregister_code(KC_LBRACKET); break;     // M-{ forward paragraph
	     case TRIPLE_HOLD: unregister_code(KC_LALT);  unregister_code(KC_V);    break;     // M-v forward page

	   }
	   fwd_tap_state.state = 0;
	 }

	 // Movement - end
	 static tap end_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	void dance_end_finished (qk_tap_dance_state_t *state, void *user_data) {
	   end_tap_state.state = cur_dance(state);
	   switch (end_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LCTRL);register_code(KC_E); break;     // C-e end of line
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP: register_code(KC_LALT);register_code(KC_LSHIFT); register_code(KC_DOT); break;  // M-> buffer end
	     case DOUBLE_HOLD: break;
	   }
	 }

	 void dance_end_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (end_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_E); break;     // C-e end of line
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP: unregister_code(KC_LALT);unregister_code(KC_LSHIFT); unregister_code(KC_DOT); break;  // M-> buffer end
	     case DOUBLE_HOLD: break;
	   }
	   end_tap_state.state = 0;
	 }

	 // Movement - start
	 static tap sta_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_sta_finished (qk_tap_dance_state_t *state, void *user_data) {
	   sta_tap_state.state = cur_dance(state);
	   switch (sta_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LCTRL);register_code(KC_A); break;     // C-a start of line
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP: register_code(KC_LALT);register_code(KC_LSHIFT); register_code(KC_COMMA); break;  // M-< buffer start
	     case DOUBLE_HOLD: break;
	   }
	 }

	 void dance_sta_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (sta_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_A);                                break; // C-a start of line
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP: unregister_code(KC_LALT);unregister_code(KC_LSHIFT); unregister_code(KC_COMMA); break; // M-< buffer start
	     case DOUBLE_HOLD: break;
	   }
	   sta_tap_state.state = 0;
	 }

	 // Left brackets
	 static tap lbr_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_lbr_finished (qk_tap_dance_state_t *state, void *user_data) {
	   lbr_tap_state.state = cur_dance(state);
	   switch (lbr_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LSHIFT);register_code(KC_9);         break; // left bracket
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: register_code(KC_LBRACKET);                           break; // left square bracket
	     case DOUBLE_HOLD:       break;
	     case TRIPLE_TAP:  register_code(KC_LSHIFT);register_code(KC_LBRACKET); break; //left curly bracket
	   }
	 }

	 void dance_lbr_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (lbr_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LSHIFT);unregister_code(KC_9);         break; // left bracket
	     case SINGLE_HOLD:       break;
	     case DOUBLE_TAP: unregister_code(KC_LBRACKET);                             break; // left square bracket
	     case DOUBLE_HOLD:       break;
	     case TRIPLE_TAP:  unregister_code(KC_LSHIFT);unregister_code(KC_LBRACKET); break; //left curly bracket
	   }
	   lbr_tap_state.state = 0;
	 }

	 // Right brackets
	 static tap rbr_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_rbr_finished (qk_tap_dance_state_t *state, void *user_data) {
	   rbr_tap_state.state = cur_dance(state);
	   switch (rbr_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LSHIFT);register_code(KC_0);         break;  // right bracket
	     case SINGLE_HOLD:                                                      break;
	     case DOUBLE_TAP: register_code(KC_RBRACKET);                           break;  // right square bracket
	     case DOUBLE_HOLD:                                                      break;
	     case TRIPLE_TAP:  register_code(KC_LSHIFT);register_code(KC_RBRACKET); break;  //right curly bracket
	   }
	 }

	 void dance_rbr_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (rbr_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LSHIFT);unregister_code(KC_0);         break;  // right bracket
	     case SINGLE_HOLD:                                                          break;
	     case DOUBLE_TAP: unregister_code(KC_RBRACKET);                             break;  // right square bracket
	     case DOUBLE_HOLD:                                                          break;
	     case TRIPLE_TAP:  unregister_code(KC_LSHIFT);unregister_code(KC_RBRACKET); break;  //right curly bracket
	   }
	   rbr_tap_state.state = 0;
	 }

	 // Calc mode - on Level 2 numeric keyboard
	 static tap cal_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_cal_finished (qk_tap_dance_state_t *state, void *user_data) {
	   cal_tap_state.state = cur_dance(state);
	   switch (cal_tap_state.state) {
	     case SINGLE_TAP: register_code(KC_LCTRL);register_code(KC_X);unregister_code(KC_LCTRL);register_code(KC_LSHIFT); register_code(KC_8); register_code(KC_C); break;     //
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP:  break;
	     case DOUBLE_HOLD: break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_cal_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (cal_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LCTRL);unregister_code(KC_X);unregister_code(KC_LSHIFT); unregister_code(KC_8); unregister_code(KC_C); break;     //
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP:  break;
	     case DOUBLE_HOLD: break;
	     case DOUBLE_SINGLE_TAP: break;;
	   }
	   cal_tap_state.state = 0;
	 }

	 //Custom keybindings

	 // ESS mode - on Level 2 numeric keyboard
	 static tap ess_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_ess_finished (qk_tap_dance_state_t *state, void *user_data) {
	   ess_tap_state.state = cur_dance(state);
	   switch (ess_tap_state.state) {
	     case SINGLE_TAP:register_code(KC_LALT);register_code(KC_X);unregister_code(KC_LALT);register_code(KC_LSHIFT); register_code(KC_R);break; // M-x R launch ESS
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP:  break;
	     case DOUBLE_HOLD: break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	 }

	 void dance_ess_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (ess_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_LALT);unregister_code(KC_X);unregister_code(KC_LSHIFT); unregister_code(KC_R);                 break;  // M-x R launch ESS
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP:  break;
	     case DOUBLE_HOLD: break;
	     case DOUBLE_SINGLE_TAP: break;
	   }
	   ess_tap_state.state = 0;
	 }

	 // Toggles
	 static tap tog_tap_state = {
	   .is_press_action = true,
	   .state = 0
	 };

	 void dance_tog_finished (qk_tap_dance_state_t *state, void *user_data) {
	   tog_tap_state.state = cur_dance(state);
	   switch (tog_tap_state.state) {
	     case SINGLE_TAP:register_code(KC_F7);break; // toggle line numbers
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP:  register_code(KC_F3);break; // toggle olivetti mode
	     case DOUBLE_HOLD: break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: register_code(KC_F5); break; // toggle custom theme
	   }
	 }

	 void dance_tog_reset (qk_tap_dance_state_t *state, void *user_data) {
	   switch (tog_tap_state.state) {
	     case SINGLE_TAP: unregister_code(KC_F7);break; // toggle line numbers
	     case SINGLE_HOLD: break;
	     case DOUBLE_TAP: unregister_code(KC_F3);break; // toggle olivetti mode
	     case DOUBLE_HOLD: break;
	     case DOUBLE_SINGLE_TAP: break;
	     case TRIPLE_TAP: unregister_code(KC_F5);break; // toggle custom theme
	   }
	   tog_tap_state.state = 0;
	 }

	 //Tap Dance Definitions
	 qk_tap_dance_action_t tap_dance_actions[] = {

	    [CT_CLN]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)             // double tap colon
	   ,[CT_PIP]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_pip_finished, dance_pip_reset)             // double tap pipe
	   ,[CT_QUM]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_qum_finished, dance_qum_reset)             // double tap question mark

	   ,[CT_SCH]  = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_S), LCTL(KC_R))                                      // search forward reverse
	   ,[CT_CCP]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ccp_finished, dance_ccp_reset)             // cut copy yank
	   ,[CT_CAA]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_caa_finished, dance_caa_reset)             // ctrl and alt tap and hold
	   ,[CT_FIL]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_file_finished, dance_file_reset)           // files open save write
	   ,[CT_REG]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_reg_finished, dance_reg_reset)             // bookmarks and registers

	   ,[CT_NAR]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_nar_finished, dance_nar_reset)             // orgmode narrow buffer
	   ,[CT_WID]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_wid_finished, dance_wid_reset)             // orgmode widen buffer
	   ,[CT_OSP]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_orgstp_finished, dance_orgstp_reset)       // orgmode structure promote
	   ,[CT_OSD]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_orgstd_finished, dance_orgstd_reset)       // orgmode structure demote
	   ,[CT_OSMU] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_orgstmu_finished, dance_orgstmu_reset)     // orgmode move structure up
	   ,[CT_OSMD] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_orgstmd_finished, dance_orgstmd_reset)     // orgmode move structure down

	   ,[CT_REP]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rep_finished, dance_rep_reset)             // query replace regexp
	   ,[CT_BKD]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_bkd_finished, dance_bkd_reset)             // movement backward- char,word,line,sentence
	   ,[CT_FWD]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_fwd_finished, dance_fwd_reset)             // movement forward - char,word,line,sentence
	   ,[CT_STA]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_sta_finished, dance_sta_reset)             // movement start
	   ,[CT_END]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_end_finished, dance_end_reset)             // movement end
	   ,[CT_LBR]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_lbr_finished, dance_lbr_reset)             // left brackets
	   ,[CT_RBR]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rbr_finished, dance_rbr_reset)             // right brackets
	   ,[CT_CAL]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cal_finished, dance_cal_reset)             // calc mode

	   ,[CT_ESS]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ess_finished, dance_ess_reset)             // R ess mode

	   // Custom functions from https://protesilaos.com/dotemacs/
	   ,[CT_TOG]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_tog_finished, dance_tog_reset)             // Toggle keys
	 };

  bool process_record_user (uint16_t keycode, keyrecord_t *record) {

   switch (keycode) {
      case KC_ESC:
	if (record->event.pressed) {
	 bool queue = true;
	   if ((get_oneshot_mods ()) && !has_oneshot_mods_timed_out ()) {    //Esc cancels any one shot modifiers which have been pressed
	     clear_oneshot_mods ();
	     queue = false;
	   }

	return queue;
       }
      break;

     case TG_0:
       if (record->event.pressed) {

	   layer_on(BASE);
       }
     break;

     case TG_1:
       if (record->event.pressed) {

	layer_on(MEDIA);}
     break;
  }
  return true;

  };
	 // Runs just one time when the keyboard initializes.
	 void matrix_init_user(void) {
	 #ifdef RGBLIGHT_COLOR_LAYER_0
	   rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
	 #endif
	 };

     void led_set_user(uint8_t usb_led) {
      if (usb_led & (1<<USB_LED_NUM_LOCK)) {
	  ergodox_right_led_1_on();
       } else {
	  ergodox_right_led_1_off();
	}
      if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
	ergodox_right_led_2_on();
      } else {
	ergodox_right_led_2_off();
      }
      if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
	ergodox_right_led_3_on();
      } else {
	ergodox_right_led_3_off();
      }
  }

	 // Runs whenever there is a layer state change.
	 layer_state_t layer_state_set_user(layer_state_t state) {
	   ergodox_board_led_off();
	   ergodox_right_led_1_off();
	   ergodox_right_led_2_off();
	   ergodox_right_led_3_off();

	   uint8_t layer = biton32(state);
	   switch (layer) {
	       case 0:
		 #ifdef RGBLIGHT_COLOR_LAYER_0
		   rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
		 #else
		 #ifdef RGBLIGHT_ENABLE
		   rgblight_init();
		 #endif
		 #endif
		 break;
	       case 1:
		 ergodox_right_led_2_on();
		 #ifdef RGBLIGHT_COLOR_LAYER_1
		   rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
		 #endif
		 break;

	       default:
		 break;
	     }

	   return state;
	 };
