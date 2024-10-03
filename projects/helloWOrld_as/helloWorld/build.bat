@echo off

as hello.asm -o hello.o

nasm.exe hello.o -o hello.exe

hello.exe