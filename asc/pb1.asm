; https://dosasm.com/BXkdXD/

.MODEL small
.STACK 100h
.DATA
    MESSAGE1 DB 'Introduceti numarul 1: $'
    MESSAGE2 DB 'Introduceti numarul 2: $'
    MESSAGE3 DB 'Suma:'
    NEWLINE  DB  13,10, '$'

    NUMA DB 0
    NUMB DB 0
    SUMA DB 0
.CODE
START:
    mov ax,@data
    mov ds,ax

    mov ah,09h
    lea dx,MESSAGE1
    int 21h
    
    mov ah,01h
    int 21h
    sub al,30h
    mov NUMA, al
    
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,09h
    lea dx,MESSAGE2
    int 21h
    
    mov ah,01h
    int 21h
    sub al,30h
    mov NUMB, al

    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,09h
    lea dx,MESSAGE3
    int 21h
     
    mov bl,0
    add bl,NUMA
    add bl,NUMB
    add bl,'0'
    
    mov SUMA,bl
    
    mov dl,SUMA
    mov ah,02h
    int 21h
   
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,4ch
    int 21h
end START