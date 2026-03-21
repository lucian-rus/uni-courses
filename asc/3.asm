;https://dosasm.com/arTbdK/

.MODEL small
.STACK 100h
.DATA
    MESSAGE1 DB 'Introduceti un numar:$'
    MESSAGE2 DB 'Caracterul introdus de dumneavoastra +1 este:$' 
    NEWLINE  DB  13,10, '$'

.CODE
START:
    mov ax,@data
    mov ds,ax

    mov ah,09h
    lea dx,MESSAGE1
    int 21h
    
    mov ah,01h
    int 21h
    mov bl, al
    
    inc bl
    
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,09h
    lea dx,MESSAGE2
    int 21h
    
    mov dl,bl
    mov ah,02h
    int 21h
    
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,4ch
    int 21h
end START