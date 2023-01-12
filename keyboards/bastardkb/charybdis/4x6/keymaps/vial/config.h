/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 4

#    ifdef VIAL_ENABLE
/** Vial-specific configuration. */

#        define VIAL_KEYBOARD_UID \
            { 0x6D, 0xA5, 0xCD, 0x8D, 0xC7, 0x3D, 0x7B, 0xA8 }
#        define VIAL_UNLOCK_COMBO_ROWS \
            { 0, 5 }
#        define VIAL_UNLOCK_COMBO_COLS \
            { 0, 0 }
#    endif // VIAL_ENABLE
#endif     // VIA_ENABLE

/* Disable unused features. */
#define NO_ACTION_ONESHOT

#ifndef TAPPING_TERM
/**
 * \brief Configure the global tapping term (default: 200ms).
 *
 * If you have a lot of accidental mod activations, crank up the tapping term.
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
 */
#    define TAPPING_TERM 190.
#endif // TAPPING_TERM

/**
 * \brief Enable rapid switch from tap to hold.
 *
 * Note that a side-effect of this setting is to disable auto-repeat when
 * pressing key twice, except for one-shot keys.
 *
 * @see https://docs.qmk.fm/#/tap_hold?id=tapping-force-hold
 */
#define TAPPING_FORCE_HOLD

/*
 * Tap-or-Hold decision modes.
 *
 * Note that the following flags behave differently when combined (ie. when 2 or
 * more are enabled).
 *
 * See bit.ly/tap-or-hold for a visual explanation of the following tap-or-hold
 * decision modes.
 * @see https://docs.qmk.fm/#/tap_hold?id=tap-hold-configuration-options
 */

/**
 *
 * \brief Faster tap-hold trigger.
 *
 * Without `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ ae
 * With `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ Mod+e
 *
 * @see https://docs.qmk.fm/#/tap_hold?id=permissive-hold
 */
#define PERMISSIVE_HOLD

/**
 * \brief Prevent normal rollover on alphas from accidentally triggering mods.
 *
 * Ignores key presses that interrupt a mod-tap.  Must-have for Home Row mod.
 *
 * Without `IGNORE_MOD_TAP_INTERRUPT`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 ➞ Mod+e
 * With `IGNORE_MOD_TAP_INTERRUPT`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 ➞ ae
 *
 * @see https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
 */
#define IGNORE_MOD_TAP_INTERRUPT

/**
 * Holding and releasing a dual-function key without pressing another key will result in nothing happening.
 * With retro tapping enabled, releasing the key without pressing another will send the original keycode even if it is outside the tapping term.
 * @see https://docs.qmk.fm/#/tap_hold?id=retro-tapping
 */
#define RETRO_TAPPING
/* Charybdis-specific features. */



#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE
