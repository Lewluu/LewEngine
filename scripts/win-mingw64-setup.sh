#!/bin/bash

set -e

if test -d /c/msys64/; then
    echo "MSYS2 already installed in: /c/msys64/"
else
    curl -OL https://github.com/msys2/msys2-installer/releases/download/2024-12-08/msys2-x86_64-20241208.exe
    ./msys2-x86_64-20241208.exe in --confirm-command --accept-messages --root C:/msys64
    rm msys2-x86_64-20241208.exe
fi

bash -c "/c/msys64/mingw64.exe pacman -S --noconfirm mingw-w64-x86_64-cmake" &
bash -c "/c/msys64/mingw64.exe pacman -S --noconfirm mingw-w64-x86_64-make" &
bash -c "/c/msys64/mingw64.exe pacman -S --noconfirm mingw-w64-x86_64-gcc" &
wait

mv "/c/msys64/mingw64/bin/mingw32-make.exe" "/c/msys64/mingw64/bin/make.exe"