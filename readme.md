The [Ergodox Mechanical Keyboard](https://www.ergodox.io) is well suited to work with emacs.
[QMK FIRMWARE](https://docs.qmk.fm) tap dances -the ability to assign different strings of
key codes depending on whether a key is tapped once, twice or three
times, allow a great deal of flexibilty in custom function
assignment. Once installed the simple command  _qmk compile_ will produce the keyboard hex
file.

The [Teensy Loader Application](https://www.pjrc.com/teensy/) loads the hex file created from the
keymap into the keyboard.

In this keyboard layout standard emacs keychords such as C-x, M-x,
C-c, C-u etc are assigned to thumb keys in the middle of the keyboard.
Tap dances for working with files, bookmarks and registers, search and
replace, are also placed on thumb keys. Movement and bracket keys are
assigned to non letter keys on the left and right keyboards respectively.
Orgmode structure editing keys are overlaid on the thumb keys, utilising double and triple taps.

Some toggles for non letter keys such as pipe, colon and question mark
are defined to save pressing the shift key.

A custom key to toggle line numbers, focussed editing mode, and custom colour themes is also defined.
Thanks to [Protesiaos Stavrou](https://protesilaos.com) for these and his beautiful Modus Operandi and Vivendi Themes.

The ctrl and alt keys are currently defined as one shot keys on the left and right keyboards.  The keymap also contains
an action *caa* which could be assigned to these keys allowing for single and double hold functions to generate ctrl and alt.
I have left these definitions in place to allow for easy experimentation.

A diagram of the layout is shown below.



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
	 |  `¬  | Home | End  |Forw  | Back |                                | ([{  | )]}  | TOGS | TG_1 | TG_0 |
	 `----------------------------------'                                `----------------------------------'
				  ,---------------.           ,-------------.
				  | Files|Replace |           |Search| Bksp |
			   ,------|------|--------|           |------+------+------.
			   |      |      |   ORG  |           | ORG  |      |      |
			   |      |      |   C-c  |           | C-u  |      |
			   | Space| LSFT |--------|           |------| RSFT | Enter|
			   |      |      |   ORG  |           | ORG  |      |      |
			   |      | onesh|   C-x  |           | M-x  | onesh|      |
			   `----------------------'           `--------------------'


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
