
Debian
====================
This directory contains files used to package experiencecoind/experiencecoin-qt
for Debian-based Linux systems. If you compile experiencecoind/experiencecoin-qt yourself, there are some useful files here.

## experiencecoin: URI support ##


experiencecoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install experiencecoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your experiencecoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/experiencecoin128.png` to `/usr/share/pixmaps`

experiencecoin-qt.protocol (KDE)

