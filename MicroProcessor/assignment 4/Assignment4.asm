;Write a X86/64 ALP to apply addition, subtraction, multiplication, division as per user choice


%macro print 2				;MACRO with two parameters, first is the name of the buffer, second is it's size
	mov rax, 1				;assign system call in rax(1 for sys_write)
	mov rdi, 1				;assign file descriptor to rdi(1 for stdout)
	mov rsi, %1				;assign the buffer address to rsi (%1 represent the first parameter)
	mov rdx, %2				;assign the size of the buffer to rdx (%2 represent the second parameter)
	syscall				;system call
%endmacro					;MACRO END

%macro read 2				;MACRO with two parameters, first is the name of the buffer, second is it's size
	mov rax, 0				;assign system call in rax(0 for sys_read)
	mov rdi, 0				;assign file descriptor to rdi(0 for std input)
	mov rsi, %1				;assign the buffer address to rsi(%1 represent the first parameter)
	mov rdx, %2				;assign the size of the buffer to rdx (%2 represent the second parameter)
	syscall				;system call
%endmacro					;MACRO END


section .data
	problem_statement db "Write a X86/64 ALP to apply addition, subtraction, multiplication, division as per user choice ",10
	problem_length equ $- problem_statement
	
	message db "Enter number(hex): "				;output display message
	message_len equ $- message					;message length
	
	error_msg db "Wrong Input Encountered, Enter Again: "	;error Handling message
	error_len equ $- error_msg 					;lenght of error message
	
	
	Addition_message db " Press 1 for ADDITION  ", 10
	Add_len equ $- Addition_message
	
	Subtraction_message db " Press 2 for SUBTRACTION  ", 10
	Sub_len equ $- Subtraction_message
	
	Multiplication_message db " Press 3 for MULTIPLICATION  ", 10
	Mul_len equ $- Multiplication_message
	
	Division_message db " Press 4 for DIVISION ", 10
	Div_len equ $- Division_message
	
	Exit_message db " Press 5 for EXITING FROM THE PROGRAM  ", 10
	Exit_len equ $- Exit_message
	
	Default_message db " Wrong choice ", 10
	Def_len equ $- Default_message
	
	choice_message db " Enter your choice:  ", 
	choice_len equ $- choice_message
	
	result_message db " The result is : "
	result_len equ $- result_message
	
	Divident_message db " Enter the Divident: ",
	Divident_len equ $- Divident_message
	
	Divisor_message db " Enter Divisor: ",
	Divisor_len equ $- Divisor_message
	
	Quotient_message db " QUOTIENT IS: "
	Quotient_len equ $- Quotient_message
	
	Remainder_message db " REMAINDER IS: "
	Remainder_len equ $- Remainder_message
		
	newline db 10					;newline
	tab db 9                                        ;TAB


section .bss
	choice resb 2                   ;for taking choice from the user
	first resq 1                    ;for reserving the first of the two quad numbers
	second resq 1                   ;for reserving the second of the two quad numbers
	divisor resd 1                  ;for storing divisor in case of division method 
	value64 resb 17                 ;for taking 16 byte of input and 1 for enter 
	value32 resb 9                  ;for taking 8 byte of input and 1 for enter 
	temp64 resb 16                  ;for storing 16 bytes in the memory (for printing pupose in the program)
	temp32 resb 8                   ;for storing 8 bytes in the memory (for printing pupose in the program)
		
	

section .text
	global _start
_start:
	print problem_statement, problem_length         ;print problem statement
	print newline, 1	                        ;print newline
	
error_skip:
        print newline, 1
	call _choice_menu                               ;calling choice menu
	print newline, 1
	print tab, 1
	print choice_message, choice_len
	read choice, 2                                  ;reading the input from the user
	
		
	switch_1:
		cmp byte[choice], 31h                   ;comparing with '1' or 31(ascii equivalent of 1)
		jne switch_2                            ;jump to switch_3 label if choice is not equal to '1'
		print newline, 1
		print newline, 1
		call _Addition_                         ;call Addition procedure
		jmp error_skip                          ;After Subtraction start the loop once again
	
	switch_2:
		cmp byte[choice], 32h                   ;comparing with '2' or 32(ascii equivalent of 2)
		jne switch_3                            ;jump to switch_3 label if choice is not equal to '2'
		print newline, 1
		print newline, 1
		call _Subtraction_                      ;call Subtraction procedure
		jmp error_skip                          ;After Subtraction start the loop once again
	
	switch_3:
		cmp byte[choice], 33h                   ;comparing with '3' or 33(ascii equivalent of 3)
		jne switch_4                            ;jump to switch_4 label if choice is not equal to '3'
		print newline, 1
		print newline, 1
		call _Multiplication_                   ;call Multiplication procedure
		jmp error_skip                          ;After Subtraction start the loop once again
	
	
	switch_4:
		cmp byte[choice], 34h                   ;comparing with '4' or 34(ascii equivalent of 4)
		jne switch_5                            ;jump to switch_5 label if choice is not equal to '4'
		print newline, 1
		print newline, 1
		call _Division_                         ;call Division procedure
		jmp error_skip                          ;After Subtraction start the loop once again
	
	
	
	switch_5:                                       
		cmp byte[choice], 35h                   ;comparing with '5' or 35(ascii equivalent of 5)
		jne dflt                                ;jump to default label if choice is not equal to '5'
		mov rax, 60				;system call to rax for exit
		mov rdi, 0				;no error found
		syscall				;system call
	
		
	dflt:
		print Default_message, Def_len
		jmp error_skip
	
; PRINTING THE CHOICE MENU
_choice_menu:
        print tab, 1
	print Addition_message, Add_len
	print tab, 1	
	print Subtraction_message, Sub_len
	print tab, 1	
	print Multiplication_message, Mul_len
	print tab, 1	
	print Division_message, Div_len
	print tab, 1
	print Exit_message, Exit_len
	print tab, 1	
ret
	

	
	
_Addition_:
	print message, message_len
	read value64 , 17                       ;reading the first input
	call ascii_hex                          ;conveting ascii to hex
	mov qword[first], rbx                   ;storing in first variable
	print newline , 1
	
	
	print message, message_len
	read value64 , 17                       ;reading the second input
	call ascii_hex                          ;conveting ascii to hex
	mov qword[second], rbx                  ;storing in second variable
	print newline, 1
	
	mov rax, qword[first]                   ;moving value of first in rax
	add rax, qword[second]                  ;adding value of second to rax
	push rax
	print result_message, result_len
	pop rax
	mov rbx, rax                            ;moving the result of addition in rbx
	call display64                          ;priting the result of addition
	print newline, 1

ret



_Subtraction_:
	print message, message_len
	read value64 , 17                       ;reading the first input
	call ascii_hex                          ;conveting ascii to hex
	mov qword[first], rbx                   ;storing in first variable
	print newline , 1
	
	print message, message_len
	read value64 , 17                       ;reading the second input
	call ascii_hex                          ;conveting ascii to hex
	mov qword[second], rbx                  ;storing in second variable
	print newline, 1
	
	mov rax, qword[first]                   ;moving value of first in rax
	sub rax, qword[second]                  ;subtracting value of second from from rax
	push rax
	print result_message, result_len
	pop rax
	mov rbx, rax				;moving the result of subtraction in rbx
	call display64				;calling the display function to display the result of subtraction
	print newline, 1

ret


_Multiplication_:
	print message, message_len
	read value64 , 17                       ;reading the first input
	call ascii_hex                          ;conveting ascii to hex
	mov qword[first], rbx                   ;storing in first variable
	print newline , 1
	
	print message, message_len
	read value64 , 17                       ;reading the second input
	call ascii_hex                          ;conveting ascii to hex
	mov qword[second], rbx                  ;storing in second variable
	print newline, 1
	
	mov rax, [first]			;moving value of first in rax
	mov rbx, [second]			;moving the value of second in rbx
	mul rbx				; rdx:rax = rax * rbx
	push rax
	push rdx
	print result_message, result_len
	pop rdx
	pop rax
	
	mov rbx, rdx				;first displaying the rdx so rbx = rdx
	push rax
	call display64				;display the rbx
	pop rax
	mov rbx, rax				;now moving the rax in rbx
			
	call display64				;now displaying the rax
	print newline, 1
	print newline, 1
ret	
	
	
_Division_:
	print Divident_message, Divident_len
	read value64, 17			;firstly reading the Divident
	print Divisor_message, Divisor_len
	read value32 , 9			;secondly reading the Divisor
	
	call ascii_hex_32			;converting the ascii of divisor to hex_value
	mov [divisor], ebx			;now storing it in [divisor]
	
	; FORMAT FOR DIVISION -> DIVIDENT IN EDX:EAX , DIVISOR IN EBX
	; THE QUOTIENT WILL BE IN EAX AND REMAINDER WILL BE IN EDX
	
	mov rsi, value64			;source is pointed by rsi(in this case value64)
	mov rdi, value32			;destination is pointed by rdi(in this case value32)
	cld 					;clearing the direction i.e. rsi and rdi will increment 
	mov cx, 8				;counter value 8
	rep movsb				;mov string byte by byte from source to destination till cx is non-zero
	
	call ascii_hex_32			;converting the value32 ascii to hex
	mov edx, ebx				;moving ebx in edx
	
	mov rsi, value64 + 8			;source is pointed by rsi(in this case value64 + 8)
	mov rdi, value32			;destination is pointed by rdi(in this case value32)
	cld 					;clearing the direction i.e. rsi and rdi will increment 
	mov cx, 8				;counter value 8
	rep movsb				;mov string byte by byte from source to destination till cx is non-zero
	
	
	push rdx				;since our output is in edx so to save it push it into stack
	call ascii_hex_32			;converting the value32 ascii to hex
	pop rdx				;pop from stack
	mov eax, ebx				;moving ebx in eax
	
	mov ebx, dword[divisor]		;moving the divison in ebx
	
	div ebx				;dividing edx:eax by ebx
	
	push rax
	push rdx
	print newline, 1
	
	print Quotient_message, Quotient_len
	
	pop rdx
	pop rax
	
	mov ebx, eax				;moving eax to ebx to print
	push rax
	push rdx
	call display32				;displaying the quotient 
	
	print newline, 1
	print Remainder_message, Remainder_len
	pop rdx
	pop rax
	
	mov ebx, edx				;moving edx to ebx to print
	call display32				;displaying the remainder
	print newline , 1

ret	



check64:					;To check wheter the value is greater than 4fh or not
	cmp al, 40h				;comparing two values
	jle error_label			;if al <= 4fh, then jump to 'error_label' to print error message
	jmp return_check_64			;otherwise jump to the next line of 'check' inside ascii_hex
	
check32:					;To check wheter the value is greater than 4fh or not
	cmp al, 40h				;comparing two values
	jle error_label			;if al <= 4fh, then jump to 'error_label' to print error message
	jmp return_check_32			;otherwise jump to the next line of 'check' inside ascii_hex
	 
error_label:				;label to print error message and jump back to error_skip
	print error_msg, error_len   	;print the error message
	print newline, 1			;newline
	jmp error_skip 			;jump the main loop without incrementing rcx, so next time input for same loop will be taken

ascii_hex:					;label-> under this label we convert ascii values to hexadecimal
	mov rcx, 16				;assign 16 to rcx, for looping 16 times
	mov rsi, value64			;rsi now have the address of 'value'
	mov rbx, 0				;clear buffer from rbx register
	next1:				;label for looping 
		rol rbx, 4			;rotating rbx left by 4 bits 
		mov al, [rsi]		;al now have the value where rsi points
		cmp al, 2fh			;comparing these two values
		jbe error_label		;if al <= 2fh, then jump to 'error_label'
		cmp al, 47h			;comparing these two values
		jge error_label		;if al >= 47h,  then jump to 'error_label'
		cmp al, 3ah			;comparing these two values
		jge check64			;if al >= 40h, then jump to 'check' to check whether the value is smaller than 4fh or not
		return_check_64:		;if al > 4fh, then above statement will jump here
		cmp al, 39h			;comparing 'al' with the ascii equivaluent of '0h' ->carry will be 1 if al <= 39h 
			jbe sub30h		;jump statement to label to line 
		sub al, 7			;al= al -7
		sub30h:			;label
			sub al, 30h 	;al= al-30
		add bl, al			;bl= bl+al
		inc rsi			;rsi= rsi+1 (incrimenting one byte)
		loop next1			;loop
	ret					;return statement


ascii_hex_32:					;label-> under this label we convert ascii values to hexadecimal
	mov rcx, 8				;assign 8 to rcx, for looping 8 times
	mov rsi, value32			;rsi now have the address of 'value'
	mov ebx, 0				;clear buffer from ebx register
	next2:				;label for looping 
		rol ebx, 4			;rotating ebx left by 4 bits 
		mov al, [rsi]		;al now have the value where rsi points
		cmp al, 2fh			;comparing these two values
		jbe error_label		;if al <= 2fh, then jump to 'error_label'
		cmp al, 47h			;comparing these two values
		jge error_label		;if al >= 47h,  then jump to 'error_label'
		cmp al, 3ah			;comparing these two values
		jge check32			;if al >= 40h, then jump to 'check' to check whether the value is smaller than 4fh or not
		return_check_32:		;if al > 4fh, then above statement will jump here
		cmp al, 39h			;comparing 'al' with the ascii equivaluent of '0h' ->carry will be 1 if al <= 39h 
			jbe sub30_h		;jump statement to label to line 
		sub al, 7			;al= al -7
		sub30_h:			;label
			sub al, 30h 	;al= al-30
		add bl, al			;bl= bl+al
		inc rsi			;rsi= rsi+1 (incrimenting one byte)
		loop next2			;loop
	ret					;return statement


display64:					;HEX to ASCII conversion 
	mov rsi , temp64
	mov rcx, 16
	
	 					
	next3:
		rol rbx, 4			;Rotating rbx left by 4 bits
		mov al, bl			;assign bl to al
		and al, 0Fh			;storing least significant hex value in al
		cmp al, 9			;compare al and 39H [9]
		jbe add30h			;if al <= 39h [9] then add 30H
		
		add al, 7			;if al is between A-F then add 7 to it
		
		add30h:
			add al, 30h		;al=al+30
		
		mov [rsi], al		;assigning value of address 'rsi' with 'al', basically we are updating the memory pointed by temp
		inc rsi			;rsi= rsi+1->increment rsi
		loop next3			;loop
	print temp64, 16
ret




display32:
	mov rsi , temp32			;rsi will point to temp
	mov rcx, 8				;for looping 8 times
	next4:
		rol ebx, 4			;Rotating ebx left by 4 bits
		mov al, bl			;assign bl to al
		and al, 0Fh			;storing least significant hex value in al
		cmp al, 9			;compare al and 39H [9]
		jbe add30_h			;if al <= 39h [9] then add 30H
		
		add al, 7			;if al is between A-F then add 7 to it
		
		add30_h:
			add al, 30h		;al=al+30
		
		mov [rsi], al		;assigning value of address 'rsi' with 'al', basically we are updating the memory pointed by temp
		inc rsi			;rsi= rsi+1->increment rsi
		loop next4			;loop
	print temp32, 8
	ret




