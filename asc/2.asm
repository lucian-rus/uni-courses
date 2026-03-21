; https://dosasm.com/BXkdXD/

.MODEL small
.STACK 100h
.DATA
    MESSAGE1 DB 'Introduceti un caracter: '
    MESSAGE2 DB 'Numarul tau este: ' 
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
    
    mov ah,02h
    mov dl,al
    int 21h
    
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,09h
    lea dx,MESSAGE2
    int 21h
    
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,4ch
    int 21h
end START