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

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "|M|",      centeredmaster },
  { ":::",      grid },
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle },
  { NULL,       NULL },
};

