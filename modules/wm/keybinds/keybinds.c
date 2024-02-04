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
  { MODKEY, XK_plus, incnmaster, {.i = +1 } },
  { MODKEY, XK_minus, incnmaster, {.i = -1 } },
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

    // Code editor
  { MODKEY, XK_c, spawn, SHCMD(CODE_EDITOR)}, 

    //  Healthy eyes
  { MODKEY, XK_r, spawn, SHCMD(MOD_COLORTEMP) },
  { MODKEY|ShiftMask, XK_r, spawn, SHCMD(RESET_COLORTEMP) },

    //  Screenshots
  { MODKEY, XK_s, spawn, SHCMD(SCRIPT_SC)}, 
  { MODKEY|ShiftMask, XK_s, spawn, SHCMD(SCRIPT_SC_SELECTED)}, 
  { MODKEY|ControlMask, XK_s, spawn, SHCMD(SCRIPT_SC_FOCUSED)}, 


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
