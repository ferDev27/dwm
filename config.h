/*

________           ________            ______ ______
___  __/______________  __ \_______   ___|__ \/__  /
__  /_ _  _ \_  ___/_  / / /  _ \_ | / /___/ /__  /
_  __/ /  __/  /   _  /_/ //  __/_ |/ /_  __/ _  /
/_/    \___//_/    /_____/ \___/_____/ /____/ /_/


GitHub: https://github.com/ferDev27

*/

// --------------------------- Theme Selection ---------------------------------
#include "./themes/ferdev27.h"

// --------------------------- Gaps/Borders ------------------------------------
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 5;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

// ------------------------- Bar/innerPadding ----------------------------------
static const int horizpadbar        = 5;        /* horizontal padding for statusbar */
static const int vertpadbar         = 12;        /* vertical padding for statusbar */

// ------------------------------ Fonts ----------------------------------------
static const char *fonts[]          = { "UbuntuMono Nerd Font:size=12:weight=bold:antialias=true:autohint=true" };
static const char dmenufont[]       = "UbuntuMono Nerd Font:size=12:weight=bold:antialias=true:autohint=true";

// ---------------------------- Workspaces -------------------------------------
//static const char *tags[] = { " I ", " II ", " III ", " IV ", " V ", " VI ", " VII ", " VIII ", " IX " };
static const char *tags[] = { "   ", "   ", "   ", "   ", "  ", "   ", "   ", "   ", "   " };
//static const char *tags[] = { " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", " 9 " };

// ----------------------------- Colors ----------------------------------------
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_wsbg, col_barbg, col_winUnSel },
	[SchemeSel]  = { col_wsfg, col_tagbg, col_winSel },
	[SchemeUSel]  = { col_wsbg, col_tagbg, col_winSel },
	[SchemeTitle]  = { col_tifg, col_tibg,  col_tibg  },
	[SchemeOcc]  = { col_occ, col_barbg, col_winUnSel },

};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class/instance/title/tags/mask/isfloating/isterminal/noswallow/monitor */
	{ "Gimp", NULL, NULL, 0, 1, 0, 0, -1 },
	{ "Firefox", NULL, NULL, 1 << 8, 0, 0, -1, -1 },
	{ "st-256color", NULL, NULL, 0, 0, 1, 0, -1 },
	{ "Alacritty", NULL, NULL, 0, 0, 1, 0, -1 },
	{ "org.wezfurlong.wezterm", NULL, NULL, 0, 0, 1, 0, -1 },
	{ NULL, NULL, "Event Tester", 0, 0, 0, 1, -1 }, /* xev */
};


// ------------------------------ Layouts --------------------------------------
static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=", tile },    /* first entry is default */
	{ "|M|", centeredmaster },
	{ "HHH", grid },
	{ ">M>", centeredfloatingmaster },
	{ "><>", NULL },		/* no layout function means floating behavior */
	{ "[M]", monocle },	
	{ NULL, NULL },
};

/* custom symbols for nr. of clients in monocle layout */
/* when clients >= LENGTH(monocles), uses the last element */
static const char *monocles[] = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]", "[9]", "[9+]"};


// ----------------------------- Keybinds --------------------------------------
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "alacritty", NULL };


#include <X11/XF86keysym.h>
#include "movestack.c"


static Key keys[] = {

	/* modifier/key/function/argument */
// ---------------------------- Movement ---------------------------------------
	{ MODKEY, XK_j, focusstack, {.i = +1 } },
	{ MODKEY, XK_k, focusstack, {.i = -1 } },

// ----------------------------- Resize ----------------------------------------
    { MODKEY|ShiftMask, XK_c, incnmaster, {.i = +1 } },
    { MODKEY, XK_c, incnmaster, {.i = -1 } },
	{ MODKEY, XK_h, setmfact, {.f = -0.05} },
	{ MODKEY, XK_l, setmfact, {.f = +0.05} },

// ------------------------- Toggle Statusbar ----------------------------------
	{ MODKEY, XK_t, togglebar, {0} },

// -------------------------- Move windows -------------------------------------
	{ MODKEY|ShiftMask, XK_j, movestack, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_k, movestack, {.i = -1 } },

    // Make master
	{ MODKEY, XK_m, zoom, {0} }, // Make Master

// --------------------------- Kill window -------------------------------------
	{ MODKEY, XK_w, killclient, {0} },

// -------------------------- Select Layout ------------------------------------
// Dont need to bind layouts since you can cycle through them
//	{ MODKEY, XK_t, setlayout, {.v = &layouts[0]} },
//	{ MODKEY, XK_c, setlayout, {.v = &layouts[2]} },
//	{ MODKEY, XK_s, setlayout, {.v = &layouts[1]} },
//	{ MODKEY, XK_space, setlayout, {0} },
//	{ MODKEY|ShiftMask, XK_space, togglefloating, {0} },
	
// -------------------------- Cycle Layouts ------------------------------------
	{ MODKEY, XK_Tab, cyclelayout, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_Tab, cyclelayout, {.i = -1 } },


// -------------------------- Focus Monitor ------------------------------------
	{ MODKEY, XK_comma, focusmon, {.i = -1 } },
	{ MODKEY, XK_period, focusmon, {.i = +1 } },

// --------------------------- Tag Monitor -------------------------------------
	{ MODKEY|ShiftMask, XK_comma, tagmon, {.i = -1 } },
	{ MODKEY|ShiftMask, XK_period, tagmon, {.i = +1 } },


// ------------------------------ View Tags ------------------------------------
//	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY, XK_0, view, {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_0, tag, {.ui = ~0 } },

// ---------------------------- Workspaces -------------------------------------
	TAGKEYS(XK_1,0)
	TAGKEYS(XK_2,1)
	TAGKEYS(XK_3,2)
	TAGKEYS(XK_4,3)
	TAGKEYS(XK_5,4)
	TAGKEYS(XK_6,5)
	TAGKEYS(XK_7,6)
	TAGKEYS(XK_8,7)
	TAGKEYS(XK_9,8)

// --------------------------- Quit/Restart ------------------------------------
	{ MODKEY|ControlMask, XK_q, quit, {0} },
	{ MODKEY|ControlMask, XK_r, quit, {1} }, 

// ----------------------------- Software --------------------------------------
	// Terminal
	{ MODKEY, XK_Return, spawn, {.v = termcmd } },

	// Dmenu
	//{ MODKEY, XK_space, spawn, {.v = dmenucmd } },

    // Rofi
	{ MODKEY, XK_space, spawn, SHCMD("rofi -show drun")}, 
	{ MODKEY|ShiftMask, XK_space, spawn, SHCMD("rofi -show")}, 

    // Browser
	{ MODKEY, XK_b, spawn, SHCMD("firefox")}, 

    //Filemanager
	//{ MODKEY, XK_f, spawn, SHCMD("thunar")}, 

	// Healthy eyes
	{ MODKEY, XK_r, spawn, SHCMD("redshift -O 2400") },
	{ MODKEY|ShiftMask, XK_r, spawn, SHCMD("redshift -x") },
	

	// Screenshots
	{ MODKEY, XK_s, spawn, SHCMD("screenshot")}, 
	{ MODKEY|ShiftMask, XK_s, spawn, SHCMD("screenshot-s")}, 

    // Color picker
	{ MODKEY, XK_p, spawn, SHCMD("picker")}, 

// ----------------------------- SysKeys ---------------------------------------
    // Volume
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%")},
    {0, XF86XK_AudioMute, spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle")},

    //Mic
    { 0, XF86XK_AudioMicMute, spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },

    // Brightness
    {0, XF86XK_MonBrightnessUp, spawn, SHCMD("brightnessctl set +10%")},
    {0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 10%-")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

