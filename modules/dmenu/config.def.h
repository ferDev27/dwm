/*
                  __           ____             ____ _____
                 / _| ___ _ __|  _ \  _____   _|___ \___  |
                | |_ / _ \ '__| | | |/ _ \ \ / / __) | / /
                |  _|  __/ |  | |_| |  __/\ V / / __/ / /
                |_|  \___|_|  |____/ \___| \_/ |_____/_/

                  GitHub: https://github.com/ferDev27
*/

/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0;                      /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int min_width = 1300;                    /* minimum width when centered */
static const unsigned int bar_hpad  = 7;    /* default 2px above/below font size  */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"UbuntuMono Nerd Font:size=12.7:weight=regular:antialias=true:autohint=true"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

#include "./themes/mo.h"

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 1;
