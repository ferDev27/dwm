static const char *colorname[] = {

    // Normal
    "#414868", "#df5b61", "#78b892", "#de8f78", "#6791c9", "#bc83e3", "#67afc1",
    "#c0caf5",

    // Bright
    "#414868", "#e8646a", "#81c19b", "#e79881", "#709ad2", "#c58cec", "#70b8ca",
    "#c0caf5",

    [255] = 0,

    "#364a82", // 256
    "#6e6a86", // 257 -> Cursor
    "#c0caf5", // 258 -> Foreground
    "#181922", // 259 -> Background 
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 258;
unsigned int defaultbg = 259;
unsigned int defaultcs = 257;
unsigned int defaultrcs = 256;
