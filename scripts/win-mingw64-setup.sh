#!/bin/bash

set -e

curl/wget https://github.com/msys2/msys2-installer/releases/download/2024-12-08/msys2-x86_64-20241208.exe
.\msys2-x86_64-latest.exe in --confirm-command --accept-messages --root C:/msys64
pacman -S mingw-w64-x86_64-cmake (in msys2 cmd)
pacman -S mingw-w64-x86_64-make (in msys2 cmd)
pacman -S mingw-w64-x86_64-gcc (in msys2 cmd)

c/msys64/mingw64

bash -c "/c/msys64/mingw64.exe pacman ..."