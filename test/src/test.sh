#!/bin/bash

declare -A targets

targets=(
    ["VS17"]="Visual Studio 17 2022"
    ["VS16"]="Visual Studio 16 2019"
    ["VS15"]="Visual Studio 15 2017"
    ["VS14"]="Visual Studio 14 2015"
    ["MinGW"]="
        MinGW Makefiles
        export CC=/c/msys64/mingw64/bin/gcc
        export CXX=/c/msys64/mingw64/bin/g++
        mkp=/c/msys64/mingw64/bin/make"
    ["NMake"]="NMake Makefiles"
    ["MSYS"]="MSYS Makefiles"
    ["Unix"]="Unix Makefiles"
)

# the commands starts from 2
readarray -t cmds <<< "${targets["MinGW"]}"
for (( i=2 ; i<"$(("${#cmds[@]}"))" ; i++ )); do
    echo ${cmds[$i]}
    eval "${cmds[$i]}"
done
