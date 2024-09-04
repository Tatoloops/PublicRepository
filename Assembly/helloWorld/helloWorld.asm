section .data
    hello db 'Hello, World!', 0  ; The string to print with a null terminator

section .text
    global main
    extern _ExitProcess@4
    extern _GetStdHandle@4
    extern _WriteFile@20

main:
    ; Get handle to standard output (stdout)
    push dword -11
    call _GetStdHandle@4
    mov ebx, eax   ; Save handle in ebx

    ; Write the string to stdout
    push dword 0   ; Pointer to number of bytes written (we don't care)
    push dword 13  ; Number of bytes to write
    push dword hello  ; Pointer to the string
    push dword ebx    ; Handle to stdout
    push dword ebx    ; Save handle again (will be modified)
    call _WriteFile@20

    ; Exit the program
    push dword 0   ; Exit code
    call _ExitProcess@4
