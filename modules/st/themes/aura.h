static const char *colorname[] = {

    // Normal
    "#1c1b22",
    "#ff6767",
    "#c5f467",
    "#e0af68",
    "#7790ff",
    "#a277ff",
    "#60e4ff",
    "#c0caf5",

    // Bright
    "#4d4d4d",
    "#ff8c84",
    "#c5f467",
    "#e0af68",
    "#7790ff",
    "#a277ff",
    "#60e4ff",
    "#c0caf5",

    [255] = 0,

    "#364a82", // 256
    "#edecee", // 257 -> Cursor
    "#c0caf5", // 258 -> Foreground
    "#15141B", // 259 -> Background 
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 258;
unsigned int defaultbg = 259;
unsigned int defaultcs = 257;
unsigned int defaultrcs = 256;
