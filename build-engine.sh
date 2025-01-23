#!/bin/bash

set -e

log_debug="[::: BUILD DEBUG :::] "
log_info="[::: BUILD INFO :::] "
log_warning="[::: BUILD WARNING :::] "
log_error="[::: BUILD ERROR :::] "

declare -A targets modes

targets=(
    ["VS17"]="Visual Studio 17 2022"
    ["VS16"]="Visual Studio 16 2019"
    ["VS15"]="Visual Studio 15 2017"
    ["VS14"]="Visual Studio 14 2015"
    ["MinGW"]="MinGW Makefiles"
    ["NMake"]="NMake Makefiles"
    ["MSYS"]="MSYS Makefiles"
    ["Unix"]="Unix Makefiles"
)

modes=(
    full
    test
    rebuild
)

# get compiler paths
gxx="CMAKE_CXX_COMPILER="`which g++`
gcc="CMAKE_C_COMPILER="`which gcc`

while getopts "t:m:" flag
do
    case "${flag}" in
        m) mode=${OPTARG};;
        t) target=${OPTARG};;
    esac
done

# detecting the target build
if [ -z "$target" ]
then
    echo $log_warning"Target is empty ... setting default to MinGW"
    target="MinGW Makefiles"
fi

# detecting build mode
if [ -z "$mode" ]
then
    echo $log_warning"Build mode is empty ... setting default to full"
    mode="full"
fi

target_exists=false
for t in "${!targets[@]}"
    do
        if [ "$target" == "$t" ]
        then
            target=${targets[$t]}
            echo -e "\n"$log_info"Target to build set to "$target
            break
        fi
    done

mode_exists=false
for m in "${!modes[@]}"
    do
        if [ "$mode" == "$m" ]
        then
            mode_set=true
            break
        fi
    done

if [ -z "$mode_set" ]
then
    echo $log_error"Mode set does not exists. Please select from $modes"
    exit 1
fi

