#!/usr/bin/env bash
# script para configurar a variavel local de biblioteca, permitindo a compilacao

mkdir bibliotecas
mkdir build

wget https://github.com/raysan5/raygui/archive/refs/tags/4.0.zip -P ./bibliotecas 
wget https://github.com/raysan5/raylib/releases/download/5.5/raylib-5.5_linux_amd64.tar.gz -P ./bibliotecas

unzip ./bibliotecas/4.0.zip -d ./bibliotecas/
tar -xvf ./bibliotecas/raylib-5.5_linux_amd64.tar.gz -C ./bibliotecas/

mv ./bibliotecas/raygui-4.0/src/raygui.h ./bibliotecas/raygui-4.0/src/raygui.c

gcc -o ./bibliotecas/raygui-4.0/src/libraygui.so ./bibliotecas/raygui-4.0/src/raygui.c -I./bibliotecas/raylib-5.5_linux_amd64/include -L./bibliotecas/raylib-5.5_linux_amd64/lib -shared -fpic -DRAYGUI_IMPLEMENTATION -lraylib -lm -lpthread -ldl -lrt

mv ./bibliotecas/raygui-4.0/src/raygui.c ./bibliotecas/raygui-4.0/src/raygui.h
