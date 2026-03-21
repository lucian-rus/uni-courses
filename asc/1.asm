;https://dosasm.com/9Aq8Cj/

.MODEL small
.STACK 100h
.DATA
    MESSAGE1 db 'hello! ',13,10, '$'

.CODE
START:
    mov ax,@data
    mov ds,ax

    mov ah,09h
    lea dx,MESSAGE1
    int 21h

    mov ah,4ch
    int 21h
end START