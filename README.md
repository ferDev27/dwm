# ferDev27's custom build of DWM

![dwmls](screenshots/dwmls.png)
![dwm1](screenshots/dwm1.png)
![dwm2](screenshots/dwm2.png)

# Contents
- [Youtube showcase](#showcase)
- [Patches included](#patches)
- [Extra features](#extra)
- [Future plans](#future)
- [Dependencies](#dependencies)
- [Additional software](#additional-software)
- [Installation](#installation)


# Showcase
[![Showcase](screenshots/yt.png)](https://youtu.be/r-ckyZHcYIo)


Suckless **[dwm](https://dwm.suckless.org/)**

# Patches
- *alwayscenter*
- *attachbottom*
- *autostart(.local/share/dwm/autostart.sh)*
- *centeredmaster*
- *cursorwarp*
- *cyclelayouts*
- *grid*
- *movestack*
- *pertag*
- *rainbowtags*
- *status2d*
- *Systray*
- *statuspadding*
- *swallow*
- *titlecolor*
- *underlinetags*
- *uselessgap*
- *windowmap*


# Extra
- Monocle layout doesn't stack the windows.
- Customizable systray iconsize.
- Fix transparent borders when using a compositor like picom.
- Added dynamic layout symbol highlighting.
- Occupied tags match it's own color, box indicator removed.
- Fix gaps not displaying correctly.
- Tags highlight only when windows are open on them.


# Future
**Future plans and patches I would like to implement**
- Keep it up to date with the latest dwm commits 


# Dependencies
**If you use different software feel free to tweak the config.h file.**
**Assuming a base install of Arch linux:**
- First we will need some basic things:

```bash
sudo pacman -S base-devel xorg-server xorg-xinit libx11 libxinerama libxft webkit2gtk
```

**Terminal:**
- [st](https://st.suckless.org/)

- Alacritty
```bash
sudo pacman -S alacritty
```

**Menu:**
- [dmenu](https://tools.suckless.org/dmenu/) 

**File Manager:**
- ranger

```bash
sudo pacman -S ranger
```

**Internet browser:**
```bash
sudo pacman -S qutebrowser
sudo pacman -S firefox
```
 
**Screen and Audio:**
- brightnessctl
- pulseaudio pamixer

```bash
sudo pacman -S brightnessctl pulseaudio pulseaudio-alsa pamixer
```
 
**Screenshots:**
- scrot

```bash
sudo pacman -S scrot
```

**Healthy Eyes**
```bash
sudo pacman -S redshift 
```

**Font:**
- Ubuntu Mono Nerd Font

```bash
sudo pacman -S ttf-ubuntu-mono-nerd ttf-jetbrains-mono-nerd 
```

- Emoji font

```bash
sudo pacman -S noto-fonts-emoji
```

**Status bar:**
- [dwmblocks](https://github.com/torrinfail/dwmblocks)

**Notifications**
- If you want notifications, you will need:

```bash
sudo pacman -S libnotify notification-daemon
```

```bash
sudo pacman -S dunst
```

- In the case of Tiling Window Managers, create this file:
```bash
sudo touch /usr/share/dbus-1/services/org.freedesktop.Notifications.service
```

And paste these:
```bash
[D-BUS Service]
Name=org.freedesktop.Notifications
Exec=/usr/lib/notification-daemon-1.0/notification-daemon
```

Check the Arch wiki for [details](https://wiki.archlinux.org/index.php/Desktop_notifications#Standalone)

# Additional software
***Software that I use alongside the WM:***

**Compositor:**
- picom

```bash
sudo pacman -S picom
```

**Media:**
- feh

```bash
sudo pacman -S feh
```
- lock screen

```bash
sudo pacman -S xautolock
```
- ffmpeg

```bash
sudo pacman -S ffmpeg
```
- sxiv

```bash
sudo pacman -S sxiv
```
- mpv

```bash
sudo pacman -S mpv
```

**PDF Reader:**
- zathura

```bash
sudo pacman -S zathura zathura-ps zathura-pdf-poppler 
```

**Clipboard:**
```bash
sudo pacman -S xclip 
```

**Other:**
- [wmname](https://tools.suckless.org/x/wmname/)

```bash
sudo pacman -S wmname pacman-contrib
```

- Xbanish
```bash
yay -S xbanish
```


**Optional:**
- Better formatting output:<br>

```bash
sudo pacman -S jq tidy
```

- CLI picker and image processing
 
```bash
sudo pacman -S gpick imagemagick
```

# Installation
I highly recommend placing the dwm folder into your .config folder and clone the repo

```bash
cd $HOME/.config
git clone https://github.com/ferDev27/dwm.git
```

I provide a simple install script for dwm, dmenu and dwmblocks

```bash
cd dwm/scripts 
./installScript 
```

