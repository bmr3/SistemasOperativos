#!/bin/sh
cd ~
cd Documents
mkdir CommandTestFolder
ls
mv ~/Documents/CommandTestFolder ~/Desktop/CommandTestFolder
cd -
cd Desktop
ls
rmdir CommandTestFolder
ls
