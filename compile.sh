#!/bin/sh

KEYBOARD_HEX_FOLDER=/mnt/c/keyboards

# Compile kbd67...
qmk compile -kb kbdfans/kbd67/rev2 -km tony
cp kbdfans_kbd67_rev2_tony.hex $KEYBOARD_HEX_FOLDER

# Compile kbd67 split spacebar...
qmk compile -kb kbdfans/kbd67/rev2 -km tony_split_spacebar
cp kbdfans_kbd67_rev2_tony_split_spacebar.hex $KEYBOARD_HEX_FOLDER

# Compile dz60 WKL hot swap...
qmk compile -kb dztech/dz60rgb_wkl/v2 -km tony60wkl
cp dztech_dz60rgb_wkl_v2_tony60wkl.hex $KEYBOARD_HEX_FOLDER

# Compile kbd67 mark ii rgb v2
qmk compile -kb kbdfans/kbd67/mkiirgb/v2 -km tony67mkii
cp kbdfans_kbd67_mkiirgb_v2_tony67mkii.hex $KEYBOARD_HEX_FOLDER

# Compile kbd67 mark ii rgb v3
qmk compile -kb kbdfans/kbd67/mkiirgb/v3 -km tony67mkii
cp kbdfans_kbd67_mkiirgb_v3_tony67mkii.bin $KEYBOARD_HEX_FOLDER
