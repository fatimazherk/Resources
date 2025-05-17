.model small
.stack 100h
.data
    n1 db 'aatmahatya karney ka mann kar raha hai! :) $' ; string must end with a '$'
.code
main proc
    mov ax, @data
    mov ds, ax           
    lea dx, n1             ; load address of string
    mov ah, 9              ; print string
    int 21h               
    ; Exit program
    mov ah, 4Ch
    int 21h
main endp
end main
