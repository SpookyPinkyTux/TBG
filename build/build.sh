#!/bin/bash

export TBG_INCLUDE=$HOME/TBG/include
export TBG_SRC=$HOME/TBG/src

    unameOut="$(uname -s)"

    if [[ ${unameOut} -eq Linux ]]
    then
        which apt || (echo "apt not installed" && exit)
        sudo apt-get update
        sudo apt-get install libsfml-dev
        [ -f /usr/bin/g++ ] && echo g++ is already installed || sudo apt install -y g++
    
    elif [[ ${unameOut} -eq Darwin ]]
    then
        brew install sfml
        [ -f /usr/bin/g++ ] && echo g++ is already installed || brew install g++
    fi

    g++ $TBG_SRC/player/player.cpp $TBG_SRC/player/bad_guy.cpp $TBG_SRC/network/network.cpp $TBG_SRC/system/loop.cpp $TBG_SRC/system/thread.cpp -o ../bin/run -I $TBG_INCLUDE/. -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -pthread