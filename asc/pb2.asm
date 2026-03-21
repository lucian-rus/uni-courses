.MODEL small
.STACK 100h
.DATA
    msg    db 'Introduceti numarul: $'
    newline db 13,10,'$'
.CODE
Start:
    mov ax, @data
    mov ds, ax

    lea dx, msg
    mov ah, 09h
    int 21h

    mov ah, 01h
    int 21h
    sub al, '0'
    mov ch, al
    mov cl, al

Loop_lines:
    cmp cl, 0
    je  Done

    lea dx, newline
    mov ah, 09h
    int 21h

    mov bl, ch

Loop_columns:
    cmp bl, 0
    je  Endline

    mov dl, '*'
    mov ah, 02h
    int 21h

    dec bl
    jmp Loop_columns

Endline:
    dec cl
    jmp Loop_lines

Done:
    lea dx, newline
    mov ah, 09h
    int 21h
    mov ah, 4Ch
    int 21h
END Start