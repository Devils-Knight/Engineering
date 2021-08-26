;Write a X86/64 ALP to compare 5 64-bit digit and print the number of positive and number of negative numbers among them 
;Name- Shubham malik		ROLL NO- 3249		

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
	Problem_statement db "Write a X86/64 ALP to compare 5 64-bit digit and print the number of positive and number of negative numbers among them  "
	Problem_len equ $- Problem_statement 
	input_message db "Enter the element "			;output display message
	len_input_message equ $-input_message			;message length
	output_message_neg db "Number of negative numbers: "
	output_len_neg equ $- output_message_neg
	output_message_pos db "Number of positive numbers: "
	output_len_pos equ $- output_message_pos					
	error_msg db "Wrong Input Encountered, Enter Again: "	;error Handling message
	error_len equ $- error_msg 					;lenght of error message
	newline db 10
	
section .bss
	value resb 17					;reserve 17 bytes, 16 input + 1 enter
	temp resb 2					;for printing the output value
	array resq 5
	maxx resq 1					;for storing the maximum value
	neg_numbers resb 1
	pos_numbers resb 1
	
	
section .text
	global _start
_start:
	print Problem_statement, Problem_len		;Problem statement
	print newline, 1				;newline
error_skip:
	mov rsi , array
	mov rcx , 05h			;moving 5 in rcx for 5 inputs
  	mov qword[maxx] , 0		;initialising maxx with 0
  	mov byte[neg_numbers], 0
  	mov byte[pos_numbers], 0
  	
	loop1:				;loop starts
  		
		push rcx		;push rcx into the stack so that we can fetch the same value of rcx after calling ascii_hex
	   	push rsi
	    	print input_message, len_input_message	;calling macro with two parameter, first->buffer(here message), second->len
	    	read value, 17		;16 input and one enter
	    	call ascii_hex    	;ASCII to HEX conversion
	    	pop rsi			;pop back the value that was pushed into the stack
	    	mov [rsi], rbx 	
	    	pop rcx			;fetching rcx from stack
	    	add rsi, 8
	    	
        loop loop1
	 	
	 	
	 	
	 mov rcx , 05h
	 mov rsi , array
	 
	 loop2:
	 	push rcx
	 	mov rax, [rsi]
	 	bt rax ,63 		;puts the 64th bit of rax in the carry flag(0-based indexing)
	    	jc label1
	    	inc byte[pos_numbers]
	    	jmp label2
		label1: inc byte[neg_numbers]
		label2:
		pop rcx
		add rsi, 8
	loop loop2
	
	
	 mov bl, byte[pos_numbers]
	 call displaymax
	 print output_message_pos, output_len_pos
	 print temp, 2
	 print newline, 1
	 print newline, 1
	
	 mov bl, byte[neg_numbers]
	 print output_message_neg,output_len_neg
	 
	 call displaymax
	 print temp, 2
	 print newline,1 
	 print newline, 1 
	 
	 
	 print newline, 1
	 	
	 	
	mov rax, 60
	mov rdi, 0
	syscall

check:						;To check wheter the value is greater than 4fh or not
	cmp al, 40h				;comparing two values
	jle error_label				;if al <= 4fh, then jump to 'error_label' to print error message
	jmp return_check			;otherwise jump to the next line of 'check' inside ascii_hex
	 
error_label:					;label to print error message and jump back to error_skip
	print error_msg, error_len   		;print the error message
	print newline, 1			;newline
	jmp error_skip 				;jump the main loop without incrementing rcx, so next time input for same loop will be taken

ascii_hex:					;label-> under this label we convert ascii values to hexadecimal
	mov rcx, 16				;assign 16 to rcx, for looping 16 times
	mov rsi, value				;rsi now have the address of 'value'
	mov rbx, 0				;clear buffer from rbx register
	next1:					;label for looping 
		rol rbx, 4			;rotating rbx left by 4 bits 
		mov al, [rsi]			;al now have the value where rsi points
		cmp al, 2fh			;comparing these two values
		jbe error_label			;if al <= 2fh, then jump to 'error_label'
		cmp al, 47h			;comparing these two values
		jge error_label			;if al >= 47h,  then jump to 'error_label'
		cmp al, 3ah			;comparing these two values
		jge check			;if al >= 40h, then jump to 'check' to check whether the value is smaller than 4fh or not
		return_check:			;if al > 4fh, then above statement will jump here
		cmp al, 39h			;comparing 'al' with the ascii equivaluent of '0h' ->carry will be 1 if al <= 39h 
			jbe sub30h		;jump statement to label to line 
		sub al, 7			;al= al -7
		sub30h:				;label
			sub al, 30h 		;al= al-30
		add bl, al			;bl= bl+al
		inc rsi				;rsi= rsi+1 (incrimenting one byte)
		loop next1			;loop
	ret					;return statement
	

displaymax:
	mov rsi , temp
	mov rcx, 2
	
	
	next2:
		rol bl, 4			;Rotating bl left by 4 bits
		mov al, bl			;assign bl to al
		and al, 0Fh			;storing least significant hex value in al
		cmp al, 9			;compare al and 39H [9]
		jbe add30h			;if al <= 39h [9] then add 30H
		
		add al, 7			;if al is between A-F then add 7 to it
		
		add30h:
			add al, 30h		;al=al+30
		
		mov [rsi], al		;assigning value of address 'rsi' with 'al', basically we are updating the memory pointed by temp
		inc rsi			;rsi= rsi+1->increment rsi
		loop next2			;loop
	ret


