#!/bin/sh
if [ -z "$1" ]
then
    echo "relaunch ./install.sh with -global or -local"
    exit 1
fi
git clone https://github.com/kevinmaxihu/Irrlicht.git
if [ "$1" = "-global" ]
then
    unzip Irrlicht/irrlicht-1.8.4.zip
    make -C irrlicht-1.8.4/source/Irrlicht clean
    make -C irrlicht-1.8.4/source/Irrlicht sharedlib
    sudo make -C irrlicht-1.8.4/source/Irrlicht install
    make -C irrlicht-1.8.4/source/Irrlicht
    rm -rf irrlicht-1.8.4
    
elif [ "$1" = "-local" ]
then
    rm -rf Irrlicht_dir
    mkdir Irrlicht_dir
    mv Irrlicht/libIrrlicht.so.1.8.4 ./Irrlicht_dir
    export LD_LIBRARY_PATH=$(pwd)libIrrlicht.so.1.8.4
fi

rm -rf Irrlicht
