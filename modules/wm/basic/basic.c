//  Tags
static const char *tags[] = { "   ", "   ", "   ", " 󰊢  ", "   ", "   ", " 󰋩  ", "   ", " 󰘸  " };

//  Border/Gaps
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
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
static const int horizpadbar        = 0;    /* horizontal padding for statusbar */
static const int vertpadbar         = 12;   /* vertical padding for statusbar */

// Font
static const char *fonts[]          = { "UbuntuMono Nerd Font:size=11:weight=bold:antialias=true:autohint=true" };

static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm] = { col_icoUnsel, col_barbg, col_winUnSel },
  [SchemeSel]  = { col_icosel, col_tagbg, col_winSel },
  [SchemeTitle]  = { col_tifg, col_tibg,  col_tibg  },
};

// Selected tags
static const char *tagSel[][2] = {
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

// Empty Tags
static const char *tagEmpty[][2] = {
  { col_icoUnsel, col_tagbg },
};

//  Underline
static const unsigned int ulinepad	    = 0;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		        = 0;	/* 1 to show underline on all tags, 0 for just the active ones */

