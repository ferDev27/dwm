/*
                  __           ____             ____ _____
                 / _| ___ _ __|  _ \  _____   _|___ \___  |
                | |_ / _ \ '__| | | |/ _ \ \ / / __) | / /
                |  _|  __/ |  | |_| |  __/\ V / / __/ / /
                |_|  \___|_|  |____/ \___| \_/ |_____/_/

                  GitHub: https://github.com/ferDev27
*/

/* See LICENSE file for copyright and license details. */

//  Border/Gaps
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */

//  Swallow
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */

//  Systray
static const unsigned int systraypinning    = 0;    /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft     = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing    = 4;    /* systray spacing */
static const unsigned int systrayiconsize   = 16;   /* systray icon size in px */
static const int systraypinningfailfirst    = 1;    /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray                = 1;    /* 0 means no systray */

//  Bar
static const int showbar            = 1;    /* 0 means no bar */
static const int topbar             = 1;    /* 0 means bottom bar */
static const int horizpadbar        = 2;    /* horizontal padding for statusbar */
static const int vertpadbar         = 12;   /* vertical padding for statusbar */

// Font
static const char *fonts[]          = { "UbuntuMono Nerd Font:size=11:weight=bold:antialias=true:autohint=true" };

// Set theme
#include "./themes/ferDev27.h"

static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm] = { col_icoUnsel, col_barbg, col_winUnSel },
  [SchemeSel]  = { col_icosel, col_tagbg, col_winSel },
  [SchemeTitle]  = { col_tifg, col_tibg,  col_tibg  },
};

// Selected tags
static const char *tagsel[][2] = {
  { col_tag1, col_tagbg },
  { col_tag2, col_tagbg },
  { col_tag3, col_tagbg },
  { col_tag4, col_tagbg },
  { col_tag5, col_tagbg },
  { col_tag6, col_tagbg },
  { col_tag7, col_tagbg },
  { col_tag8, col_tagbg },
  { col_tag9, col_tagbg },
};

// Occupied tags
static const char *tagOcc[][2] = {
  { col_tag1, col_barbg },
  { col_tag2, col_barbg },
  { col_tag3, col_barbg },
  { col_tag4, col_barbg },
  { col_tag5, col_barbg },
  { col_tag6, col_barbg },
  { col_tag7, col_barbg },
  { col_tag8, col_barbg },
  { col_tag9, col_barbg },
};


// Main software 
const char MY_TERMINAL[] = "alacritty";
const char MY_MENU[] = "dmenu_run -l 10";
const char MY_BROWSER[] = "firefox";
const char MOD_COLORTEMP[] = "redshift -O 4400";
const char RESET_COLORTEMP[] = "redshift -x";

// Scripts (.local/bin) 
const char SCRIPT_EMOJI[] = "dmenuunicode";
const char SCRIPT_SC[] = "screenshot";
const char SCRIPT_SC_SELECTED[] = "screenshot-s";
const char SCRIPT_PICKER[] = "picker";


//  Underline
static const unsigned int ulinepad	    = 0;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 1;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		        = 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class            instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
  { "Alacritty",      NULL,     NULL,           0,         0,          1,           0,        -1 },
  { "st-256color",    NULL,     NULL,           0,         0,          1,           0,        -1 },
  { MY_BROWSER,        NULL,     NULL,           1 << 0,    0,          0,          -1,        -1 },
  { NULL,             NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "gaplessgrid.c"
#include "fibonacci.c"

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "|M|",      centeredmaster },
  { "[@]",      spiral },
  { ":::",      gaplessgrid },
  { "TTT",      bstack },
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle },
  { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { MY_TERMINAL, NULL };

#include <X11/XF86keysym.h>
#include "movestack.c"

static const Key keys[] = {

    //  Movement 
  { MODKEY, XK_j, focusstack, {.i = +1 } },
  { MODKEY, XK_k, focusstack, {.i = -1 } },

  { MODKEY|ShiftMask, XK_j, movestack, {.i = +1 } },
  { MODKEY|ShiftMask, XK_k, movestack, {.i = -1 } },

    //  Resize 
  { MODKEY|ShiftMask, XK_c, incnmaster, {.i = +1 } },
  { MODKEY, XK_c, incnmaster, {.i = -1 } },
  { MODKEY|ControlMask, XK_h, setmfact, {.f = -0.05} },
  { MODKEY|ControlMask, XK_l, setmfact, {.f = +0.05} },

    //  Toggle Statusbar 
  { MODKEY, XK_t, togglebar, {0} },

    // Make master
  { MODKEY, XK_m, zoom, {0} },

    //  Kill window
  { MODKEY, XK_w, killclient, {0} },

    //  Cycle Layouts 
  { MODKEY, XK_Tab, cyclelayout, {.i = +1 } },
  { MODKEY|ShiftMask, XK_Tab, cyclelayout, {.i = -1 } },

    //  Set layout 
  // { MODKEY, XK_t, setlayout, {.v = &layouts[0]} },
  // { MODKEY, XK_f, setlayout, {.v = &layouts[1]} },
  // { MODKEY, XK_m, setlayout, {.v = &layouts[2]} },
  // { MODKEY, XK_u, setlayout, {.v = &layouts[3]} },
  // { MODKEY, XK_o, setlayout, {.v = &layouts[4]} },
  // { MODKEY, XK_g, setlayout, {.v = &layouts[5]} },
  // { MODKEY, XK_r, setlayout, {.v = &layouts[6]} },
  // { MODKEY, XK_space, setlayout, {0} },
  // { MODKEY|ShiftMask, XK_space, togglefloating, {0} },

    //  View Tags 
  { MODKEY, XK_0, view, {.ui = ~0 } },
  // { MODKEY, XK_Tab, view, {0} },
  // { MODKEY|ShiftMask, XK_0, tag, {.ui = ~0 } },

    //  Monitor
  { MODKEY, XK_comma, focusmon, {.i = -1 } },
  { MODKEY, XK_period, focusmon, {.i = +1 } },

  { MODKEY|ShiftMask, XK_comma, tagmon, {.i = -1 } },
  { MODKEY|ShiftMask, XK_period, tagmon, {.i = +1 } },

    //  Tags
  TAGKEYS( XK_1, 0)
  TAGKEYS( XK_2, 1)
  TAGKEYS( XK_3, 2)
  TAGKEYS( XK_4, 3)
  TAGKEYS( XK_5, 4)
  TAGKEYS( XK_6, 5)
  TAGKEYS( XK_7, 6)
  TAGKEYS( XK_8, 7)
  TAGKEYS( XK_9, 8)

    //  Quit
  { MODKEY|ControlMask, XK_q, quit, {0} },

    // Lockscreen
  { MODKEY, XK_l, spawn, SHCMD("slock")}, 

    //  Terminal
  { MODKEY, XK_Return, spawn, {.v = termcmd } },

    //  Dmenu
  { MODKEY, XK_space, spawn, SHCMD(MY_MENU)}, 
  { MODKEY|ControlMask, XK_space, spawn, SHCMD(SCRIPT_EMOJI)}, 

    //  Browser
  { MODKEY, XK_b, spawn, SHCMD(MY_BROWSER)}, 

    //  Healthy eyes
  { MODKEY, XK_r, spawn, SHCMD(MOD_COLORTEMP) },
  { MODKEY|ShiftMask, XK_r, spawn, SHCMD(RESET_COLORTEMP) },

    //  Screenshots
  { MODKEY, XK_s, spawn, SHCMD(SCRIPT_SC)}, 
  { MODKEY|ShiftMask, XK_s, spawn, SHCMD(SCRIPT_SC_SELECTED)}, 

    //  Color picker
  { MODKEY, XK_p, spawn, SHCMD(SCRIPT_PICKER)}, 

    //  System Keys
    //  Volume
  {0, XF86XK_AudioLowerVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%")},
  {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%")},
  {0, XF86XK_AudioMute, spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle")},

    //  Mic
  { 0, XF86XK_AudioMicMute, spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },

    //  Brightness
  {0, XF86XK_MonBrightnessUp, spawn, SHCMD("brightnessctl set +10%")},
  {0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 10%-")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

