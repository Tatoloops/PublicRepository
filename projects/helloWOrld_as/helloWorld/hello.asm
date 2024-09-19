.section .data
hello:
    .ascii "Hello, World!\n"
hello_len = . - hello

.section .text
.globl _start

_start:
    # sys_write (write to stdout)
    mov $1, %rax        # syscall number for sys_write (1)
    mov $1, %rdi        # file descriptor 1 is stdout
    mov $hello, %rsi    # address of the string to output
    mov $hello_len, %rdx # length of the string
    syscall             # make the syscall

    # sys_exit (exit)
    mov $60, %rax       # syscall number for sys_exit (60)
    xor %rdi, %rdi      # exit code 0
    syscall             # make the syscall
