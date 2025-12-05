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
