@echo off

as hello.asm -o hello.o

ld hello.o -o hello.exe

./hello.exe