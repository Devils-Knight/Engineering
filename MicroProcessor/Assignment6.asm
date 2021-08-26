;Write a switch case driven X86/64 ALP to convert 4-digit HEX to 5-digit BCD and 5-digit BCD to 4-digit HEX 
;Roll No- 3249   Name - Shubham malik    

%macro print 2			;Macro for printing 
	mov rax, 1		;rax = 1 for sys_write	
	mov rdi, 1		;unsigned int file descriptor
	mov rsi, %1		;Buffer address
	mov rdx, %2		;Buffer length
	syscall			;Makes system call
%endmacro

%macro read 2			;Macro for reading 
	mov rax, 0		;rax = 0 for sys_read
	mov rdi, 0		;unsigned int file descriptor
	mov rsi, %1		;Buffer address
	mov rdx, %2		;Buffer length
	syscall			;Makes system call
%endmacro	

section .data			;For declaring initialized data
	
	problem_statement db "Write a switch case driven X86/64 ALP to convert 4-digit HEX to 5-digit BCD and 5-digit BCD to 4-digit HEX." , 10 , "Name Shubham malik	Roll No- 3249", 10
	problem_statement_len equ $- problem_statement						
	
	message_menu db "--> Select an option from the menu : ", 10 , " 1-> HEXADECIMAL TO BCD ", 10, " 2-> FOR  BCD TO HEXADECIMAL", 10, " 3-> EXITING FROM THE PROGRAM ", 10, "Enter Your Choice :  " 
	message_menu_len: equ $ - message_menu
	
	 
	input_hex db "Enter your 4-digit Hex number : "			
	input_hex_len: equ $-input_hex		
	input_bcd db "Enter your 5-digit BCD number : "		
	input_bcd_len: equ $-input_bcd
	
	output_hex db "Given number in HEX form is : "
	output_hex_len: equ $-output_hex
	output_bcd db "Given number in BCD form is : "
	output_bcd_len: equ $-output_bcd
	
	error_msg db "Wrong read Encountered, Enter Again: "	;error Handling message
	error_len equ $- error_msg 					;lenght of error message
	newline db 10							;newline						
	
section .bss
	hexadecimal resb 5			;reserve 5 bytes, 4 for hexa decimal and last for enter
	decimal resb 6				;reserve 6 bytes, 5 for hexa decimal and last for enter
	ans_hex resb 4				;reserve 4 bytes for ans_hex variable
	ans_bcd resb 5				;reserve 5 bytes for ans_bcd variable
	choice resb 2				;reserving 2 bytes for your choice
	
section .text						;Actual code is present.
	global _start					;has to be declared for linker(ld).
	_start: 					;tells linker entry point.
	
	print problem_statement, problem_statement_len		;Problem Statement.
	print newline, 1				
	
	error_skip:
		
		print message_menu, message_menu_len	;Printing menu
		read choice, 2
		print newline, 1
		
		case_1:
			cmp byte[choice], '1'		
			jne case_2
			call HEX_TO_BCD			;Calling HEX_TO_BCD Procedure when choice is 1
			print newline, 1
			jmp error_skip
		case_2:	
			cmp byte[choice], '2'
			jne case_3
			call BCD_TO_HEX			;Calling BCD_TO_HEX Procedure when choice is 2
			print newline, 1
			jmp error_skip
		case_3:
			cmp byte[choice], '3'
			je Exit			;Exiting when choice is 3
			print newline, 1
			print error_msg, error_len
			print newline, 1
			jmp error_skip
			
	Exit:
	mov rax, 60					;rax = 60 for sys_exit.
	mov rdi, 0
	syscall
	
	
HEX_TO_BCD:
	print input_hex, input_hex_len				
	read hexadecimal, 5				;read in hex form
	call ascii_hex					;Converting ascii to hex
							;Hex value got stored in rbx
	mov ax, bx					;Storing hex value in ax
	mov bx, 0Ah					;Storing 10 in bx for division
	mov cx, 5
	mov rdi, ans_bcd+4				;Pointing to last index of bcd to traverse in reverse order
	next_itr:
		mov dx, 0				;Making rdx 0 as dividend is rdx:rax
		div bx					;This divides edx:eax by ebx
		add dl, 30h				;dl stores remainder, thus we converting it into ascii
		mov byte[rdi], dl			;And add to bcd 
		dec rdi					;Moving to previous index
	loop	next_itr
	
	print output_bcd, output_bcd_len		;Printing messg for bcd
	print ans_bcd, 5				;Required bcd output
	print newline, 1
ret

BCD_TO_HEX:
	print input_bcd, input_bcd_len				
	read decimal, 6					;read in bcd form
	
	mov rcx, 5					;To iterate over all elements of bcd
	mov rdi, decimal				;Point to first element of bcd
	mov rax, 0					;Making ax equal to zero
	mov rbx, 10					;Moving 10 for multiplication
	
	next1_itr:
		mul bx					;multiplying bx, 10
		mov edx, 0				;Clearing dx
		mov dl, byte[rdi]			;Moving char pointed by rsi to dl
		sub dl, 30h				;Ascii to hex
		add eax, edx				;Adding dx to ax
		inc rdi					;Moving to next index
	loop 	next1_itr
		
		mov ebx, eax
		print output_hex, output_hex_len			;Printing messg for hex
		call display_hex					;Required hex output
		print newline, 1
	ret

check:						;To check wheter the value is greater than 4fh or not
	cmp al, 40h				;comparing two values
	jle error_label				;if al <= 4fh, then jump to 'error_label' to print error message
	jmp return_check			;otherwise jump to the next line of 'check' inside ascii_hex
	 
error_label:					;label to print error message and jump back to error_skip
	print error_msg, error_len   		;print the error message
	print newline, 1			;newline
	jmp error_skip 				;jump the main loop without incrementing rcx, so next time read for same loop will be taken

ascii_hex:					;label-> under this label we convert ascii values to hexadecimal
	mov rcx, 4				;assign 4 to cx, for looping 4 times
	mov rsi, hexadecimal			;rsi now have the address of 'value'
	mov bx, 0				;clear buffer from bx register
	loop1:					;label for looping 
		rol bx, 4			;rotating rbx left by 4 bits 
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
		loop loop1			;loop
	ret


display_hex:
	mov rcx, 4					
	mov rsi, ans_hex				;rsi points to len
	loop2:	
		rol bx, 4				;rotating by 4 bits to left
		mov al, bl				
		and al, 0Fh				;To get only last digit, eg. 5Ah & 0Fh = 0Ah
		cmp al, 9h				;Case : al <= 9h (9)
		jbe add30h				;If True add 30h
		add al, 7h				;Else add 37h

		add30h:
			add al, 30h			;Adding 30h to al
		mov [rsi], al				;Storing al in temp
		inc rsi								
	loop loop2
	
	print ans_hex, 4				;Printing number in ascii
ret							;Return





