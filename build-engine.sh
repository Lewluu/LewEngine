#!/bin/bash

set -e

log_debug="[::: BUILD DEBUG :::] "
log_info="[::: BUILD INFO :::] "
log_warning="[::: BUILD WARNING :::] "
log_error="[::: BUILD ERROR :::] "

# set targets with environment variables
declare -A targets
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

help () {
    echo ""
    echo "Script for the LewEngine build process."
    echo ""
    echo "Arguments options:"
    echo ""
    echo "-t = Defines build target. Possible argument values: "${!targets[@]}""
    echo "Default is 'MinGW' if empty."
    echo ""
    echo "-m = Defines build mode. Possible argument values: "${modes[@]}""
    echo "Default is 'full' if empty."
    echo ""

    exit 0
}

while getopts ":ht:m:" flag; do
    case "${flag}" in
        m) mode=${OPTARG};;
        t) target=${OPTARG};;
        h) help;;
    esac
done

# detecting the target build
if [ -z "$target" ]; then
    echo $log_warning"Target is empty ... setting default to MinGW"
    target="MinGW"
    target_set=true
else
    for t in "${!targets[@]}"; do
        if [ "$target" == "$t" ]; then
            echo $log_info"Target to build set to "$target
            target_set=true
            break
        fi
    done
fi

if [ -z "$target_set" ]; then
    echo $log_error"Target set does not exists. Please select from ${!targets[@]}"
    exit 1
fi

# detecting build mode
if [ -z "$mode" ]; then
    echo $log_warning"Build mode is empty ... setting default to full"
    mode="full"
    mode_set=true
else
    for m in "${modes[@]}"; do
        if [ "$mode" == "$m" ]; then
            mode_set=true
            echo $log_info"Mode to build set to "$mode
            break
        fi
    done
fi

if [ -z "$mode_set" ]; then
    echo $log_error"Mode set does not exists. Please select from ${modes[@]}"
    exit 1
fi

# starting build process
rm -rf build/

# removing the blank space from the first target parameter
echo $log_info'Calling command: 'cmake' -S . -G '"${targets[$target]}"' -B build/ -D CMAKE_MAKE_PROGRAM='${make}' -D MODE='${mode}''
${CMAKE} -S . -G "${targets[$target]}" -B build/ -D CMAKE_MAKE_PROGRAM=${make} -D MODE=$mode | sed -e 's/^/'"${log_debug}"'/;'

cd build/
echo $log_info'Calling command: make'
${MAKE} | sed -e 's/^/'"${log_debug}"'/;'

