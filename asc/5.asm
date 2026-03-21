;https://dosasm.com/xsunHK/

.MODEL small
.STACK 100h
.DATA
    MESSAGE1 DB 'Introduceti un numar:$'
    MESSAGE2 DB 'Caracterul introdus de dumneavoastra +1 este:$' 
    MESSAGE3 DB 'Caracterul introdus de dumneavoastra -1 este:$' 
    NEWLINE  DB  13,10, '$'
    
    SAVED     DB 0
    SAVED_DEC DB 0
    SAVED_INC DB 0
.CODE
START:
    mov ax,@data
    mov ds,ax

    mov ah,09h
    lea dx,MESSAGE1
    int 21h
    
    mov ah,01h
    int 21h
    mov SAVED, al
    
    mov bl, SAVED
    inc bl
    mov SAVED_INC,bl
    
    mov bl, SAVED
    dec bl
    mov SAVED_DEC,bl
    
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,09h
    lea dx,MESSAGE2
    int 21h
    
    mov dl,SAVED_INC
    mov ah,02h
    int 21h
    
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
        mov ah,09h
    lea dx,MESSAGE3
    int 21h
    
    mov dl,SAVED_DEC
    mov ah,02h
    int 21h
    
    mov ah,09h
    lea dx,NEWLINE
    int 21h
    
    mov ah,4ch
    int 21h
end START