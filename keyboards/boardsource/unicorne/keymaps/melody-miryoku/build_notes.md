### PRINCIPLES
* (!) minimal mental state required for use
* consistent placement of commonly-used keys across all layers
* consistent fall-through logic; should be easy to get back to BASE layer from wherever you are
* no awkward same-hand gyrations, use alternate-hand chording whenever possible
* outer columns should be reserved for rarely-used functions, never mods
## TECH
* home-row mods - eliminates most awkward gyrations for chording, reduces pinky load
* tap-hold: used all over the place for function-overloading; helps to eliminate need for extra mod keys
* magic key: like a more granular auto-complete; meant to minimize same-finger-bigrams and scissoring
* repeat key: what-it-says-on-the-tin; meant to compensate for globally disabling auto key repeat in firmware
* leader key(?): allows for more extensive macros; still debating usefulness of this one
* shift layers: layers for number entry, symbols, navigation, settings
    *  number layer - should allow for quick entry of decimal digits, quick access to common math operators [+ - * / ^ =]
    *  symbol layer - arranged to allow for frequently used bigraphs and trigraphs
    *  media layer - media keys and ancillary settings (RGB controls, NKRO, &c.)
    *  nav layer - arrow keys, nav cluster
    *  fun layer - function keys
    *  pad layer - special layer on LHS for use with mouse. RHS is hexadecimal numpad
    *  mouse layer - FALLBACK OPTION - enables mouse control with keyboard
    *  numpad layer - allows access to numpad, with full hexadecimal input [0-9,A-F] and numpad operators [+ - * / . Enter]
    *  all layer shift keys are momentary
    *  layer lock: CURrent for locking currently active layer, OPPosite for corresponding layer on opposite hand (this allows single hand lock-and-use)
    *  primary functons of each layer on opposite hand from layer shift key
    *  global toggles: available on all shift layers, on same hand as layer shift:
        * QMK_BOOT - shift into bootloader mode for firmware update
        * Tap - FALLBACK OPTION - disable homerow mods, provide dedicated mod keys [Ctrl Alt Shift Super]
        * Base - switch base layer between available alpha layouts (currently Dvorak, Magic Sturdy, QWERTY)
    *  global toggles REQUIRE DOUBLE-TAP
* layer lock on all shift layers
* DROP_TOGGLES - unsets all layer toggles, quick escape to current base layer
## QMK options
* disable key repeat on base layer (is this necessary?)
* set QUICK_TAP_TERM to 0
* flow-tap: ignore tap-hold during rapid typing
* chordal input: must use opposite hand for mod input
## OLED

# code for extracting active layer
```C
const char *get_layer_name(layer_names_t layer) {
    switch (layer) {
        case QWERTY:
            return "QWERTY";

        case FN1:
            return "F-KEYS";

        case FN2:
            return "NUMPAD";

        case FN3:
            return "SYMBOLS";

        case RST:
            return "UTILS";

        default:
            return "???";
    }
}
```
