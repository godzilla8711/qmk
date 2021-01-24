#!/bin/bash

# git remote add origin https://github.com/godzilla8711/qmk.git (main branch)
GIT_QMK_FOLDER=$HOME/qmk

# Copy in important files
cp notes.txt "$GIT_QMK_FOLDER/notes.txt"
cp compile.sh "$GIT_QMK_FOLDER/compile.sh"
cp export-to-git.sh "$GIT_QMK_FOLDER/export-to-git.sh"

# Copy in custom keyboard mappings
rm -rf "$GIT_QMK_FOLDER/keyboards-kbdfans-kbd67-rev2-keymaps-tony/"
cp -rf keyboards/kbdfans/kbd67/rev2/keymaps/tony/ "$GIT_QMK_FOLDER/keyboards-kbdfans-kbd67-rev2-keymaps-tony/"

rm -rf "$GIT_QMK_FOLDER/keyboards-kbdfans-kbd67-rev2-keymaps-tony_split_spacebar/"
cp -rf keyboards/kbdfans/kbd67/rev2/keymaps/tony_split_spacebar/ "$GIT_QMK_FOLDER/keyboards-kbdfans-kbd67-rev2-keymaps-tony_split_spacebar/"

rm -rf "$GIT_QMK_FOLDER/keyboards-dztech-dz60rgb_wkl-keymaps-tony60wkl/"
cp -rf keyboards/dztech/dz60rgb_wkl/keymaps/tony60wkl/ "$GIT_QMK_FOLDER/keyboards-dztech-dz60rgb_wkl-keymaps-tony60wkl/"

rm -rf "$GIT_QMK_FOLDER/keyboards-kbdfans-kbd67-mkiirgb-keymaps-tony67mkii/"
cp -rf keyboards/kbdfans/kbd67/mkiirgb/keymaps/tony67mkii/ "$GIT_QMK_FOLDER/keyboards-kbdfans-kbd67-mkiirgb-keymaps-tony67mkii/"

