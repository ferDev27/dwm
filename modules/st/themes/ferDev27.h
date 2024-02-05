static const char *colorname[] = {

    "#1d202f", "#F07178", "#cdea9f", "#ffd47e",
    "#93bbff", "#d3a7ee", "#98e4ff", "#bfd5de",


    "#414868", "#F07178", "#cdea9f", "#ffd47e",
    "#93bbff", "#d3a7ee", "#98e4ff", "#bfd5de",

//    "#414868", "#eb7f84", "#e0ffad", "#ffee7e",
//    "#a3c5ff", "#d6afed", "#98fffd", "#d1e5ed",

    [255] = 0,

    "#364a82", // 256
    "#C778DD", // 257 -> Cursor
    "#c0caf5", // 258 -> Foreground
    "#17181f", // 259 -> Background soft
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 258;
unsigned int defaultbg = 259;
unsigned int defaultcs = 257;
unsigned int defaultrcs = 256;
