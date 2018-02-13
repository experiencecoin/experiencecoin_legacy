Experiencecoin Core version *3.0.0* is now available from:

  <https://github.com/experiencecoin/wallets>

This is a major update for the version 0.14.0. Current release is not compatible with previous releases, 
so any other version prior to 3.0.0 is not going to work and your only option is to upgrade.


This release introduces the following major changes:


    -   Support for Segwit (paving the way for Lightning Network)
    -   Reduction in total EPC from 450,000,000,000 to 21,500,000,000
    -   UI and logo redesign
    -   Reduced Block Reward to 64 EPC 
    -   Increased  block halving time from 12 Million to 25 Million
    -   Increased block size limit to 5MB
    -   2 blocks / 2 minute difficulty adjustment 
    -   A working Testnet
    -   Full nodes hosted across the globe
    -   Change network magic
    -   Removed Merged Mining going forward


Minor updates:


    -   Custom desktop wallet theme
    -   Legacy merged mining compatibility
  

Bug fixes:

Fix a crash with a shared pointer while trying to read merged mining blocks
Fix the way the logo was changed, having a different splash image


Please report bugs using the issue tracker at GitHub:

  <https://github.com/experiencecoin/experiencecoin/issues>


How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the 
installer (on Windows) or just copy over `/Applications/Experiencecoin-Qt` (on Mac)
or `experiencecoind`/`experiencecoin-qt` (on Linux).

Before running the version 3.0.0, you need to delete blocks and chainstate folders 
of the previous installation. Below instruction to find such folders.


Windows
=======

Go to Start -> Run (or press WinKey+R) and run this:

%APPDATA%\Experiencecoin
Experiencecoin's data folder will open. For most users, this is the following locations:

C:\Documents and Settings\YourUserName\Application data\Experiencecoin (XP)

C:\Users\YourUserName\Appdata\Roaming\Experiencecoin (Vista and 7)
"AppData" and "Application data" are hidden by default.

You can also store Experiencecoin data files in any other drive or folder.

If you have already downloaded the data then you will have to move the data to the new folder. 
If you want to store them in D:\ExperiencecoinData then click on "Properties" of a shortcut to 
experiencecoin-qt.exe and add -datadir=D:\ExperiencecoinData at the end as an example:

"C:\Program Files (x86)\Experiencecoin\experiencecoin-qt.exe" -datadir=d:\ExperiencecoinData
Start Experiencecoin, now you will see all the files are created in the new data directory.

Linux
====

By default Experiencecoin will put its data here:

~/.experiencecoin/
You need to do a "ls -a" to see directories that start with a dot.

If that's not it, you can do a search like this:

find / -name wallet.dat -print 2>/dev/null


Mac
===

By default Experiencecoin will put its data here:

~/Library/Application Support/Experiencecoin/


Compatibility
==============

Experiencecoin Core is extensively tested on multiple operating systems using
the Linux kernel, macOS 10.8+, and Windows Vista and later. Windows XP is not supported.

Experiencecoin Core should also work on most other Unix-like systems but is not
frequently tested on them.


Credits
=======
Thanks to everyone who directly contributed to this release:

- Milad Afdasta
- Spencer Dupre
- Salvatore De Paolis
- Alejandro Pasos
- Shaz Khan
