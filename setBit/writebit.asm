
.model small
.code 

    
    public _myputchar
    public _getch
    public _WriteBit

    _WriteBit   PROC
                push bp
                mov bp,sp
                mov bx,[bp+4]
                mov cl,[bp+6]
                mov al,[bp+8]
                ;===============================
                mov dl,[bx]
                cmp al,0
                je @@cero_convert
                cmp al,1
                je @@one_convert
                ;====================================
                jmp @@out_convertion
                @@cero_convert:
                ;inicio
                mov al,254
                rol ax,cl
                and dl,al
                ;final
                jmp @@out_convertion
                ;===================================
                @@one_convert:
                ;inicio
                mov al,1
                rol ax,cl
                or dl,al
                ;final
                jmp @@out_convertion
                ;===============================
                @@out_convertion:
                pop bp
                ret
    _WriteBit   ENDP

    _inportb    PROC
                push bp
                mov bp,sp
                mov dx,[bp+4]
                in  al,dx
                pop bp
                ret
    _inportb    ENDP

    _outportb   PROC
                push bp
                mov bp,sp
                mov dx,[bp+4]
                mov al,[bp+6]
                out dx,al
                pop bp
                ret
    _outportb   ENDP

    _myputchar  PROC
                push bp
                mov bp,sp
                mov dl,[bp+4]
                mov ah,2
                int 21h
                pop bp
                ret
    _myputchar ENDP

    _getch	proc
            push bp
            mov bp,sp
			mov ah,8				
			int 21h	
            pop bp			
			ret
	_getch	ENDP

    END