;Write X86/64 ALP to perform overlapped block transfer with string specific instructions Block containing data can be defined in the data segment the data segment
;Name- Shubham malik		ROLL NO- 3249		

%macro print 2					;MACRO with two parameters, first is the name of the buffer, second is it's size
	mov rax, 1				;assign system call in rax(1 for sys_write)
	mov rdi, 1				;assign file descriptor to rdi(1 for stdout)
	mov rsi, %1				;assign the buffer address to rsi (%1 represent the first parameter)
	mov rdx, %2				;assign the size of the buffer to rdx (%2 represent the second parameter)
	syscall					;system call
%endmacro					;MACRO END

%macro read 2					;MACRO with two parameters, first is the name of the buffer, second is it's size
	mov rax, 0				;assign system call in rax(0 for sys_read)
	mov rdi, 0				;assign file descriptor to rdi(0 for std input)
	mov rsi, %1				;assign the buffer address to rsi(%1 represent the first parameter)
	mov rdx, %2				;assign the size of the buffer to rdx (%2 represent the second parameter)
	syscall					;system call
%endmacro	

section .data
	Problem_statement db "Write X86/64 ALP to perform overlapped block transfer with string specific instructions Block containing data can be defined in the data segment "
	Problem_len equ $- Problem_statement 
	
	input_message db "Enter Hexadecimal Number: "			;output display message
	len_input_message equ $-input_message				;message length
	
	output_message db "FOR OUTPUT DATA ", 10
	output_message_len equ $- output_message
	
	for_input db "FOR INPUT DATA ", 10				; input data display message
	for_input_len equ $- for_input
	
	address db "        ADDRESS:        "                           ; address display message
	address_len equ $- address			
	
	data db "        DATA ", 10					;data display message
	data_len equ $- data
	
	choice_message db " Enter your choice:  ", 
	choice_len equ $- choice_message
	
	choice1 db " Select 1 for overlapped-block transfer using string instructions", 10 		;different choices
	choice1_len equ $- choice1
	
	choice2 db " Select 2 for overlapped-block transfer without using string instructions", 10	;different choices
	choice2_len equ $- choice2
	
	choice3 db " Select 3 for exit from the program", 10						;different choices
	choice3_len equ $- choice3
	
	before_transfer db 10, " ---->Status before Transfer<---- ", 10
	before_transfer_len equ $- before_transfer
	
	after_transfer db 10, " ---->Status after Transfer<---- ", 10
	after_transfer_len equ $- after_transfer
	
	Default_message db " Wrong choice ", 10
	Def_len equ $- Default_message
	
	error_msg db "Wrong Input Encountered, Enter Again: "		;error Handling message
	error_len equ $- error_msg 					;lenght of error message
	newline db 10
	tab db 9                                       			;TAB
	
	
section .bss
	choice resb 2                   		;for taking choice from the user
	value resb 17					;reserve 17 bytes, 16 input + 1 enter
	input_data resq 5				;For storing the input array
	output_data resq 5				;For storing the output array
	temp64 resb 16					;for displaying the 16- digit hexadecimal number
	
section .text
	global _start
_start:
	print Problem_statement, Problem_len         	;print problem statement
	print newline, 1	                        ;print newline
	
error_skip:
	call _choice_menu                               ;calling choice menu
	print choice_message, choice_len
	read choice, 2                                  ;reading the input from the user

	switch_1:
		cmp byte[choice], 31h                   ;comparing with '1' or 31(ascii equivalent of 1)
		jne switch_2                            ;jump to switch_3 label if choice is not equal to '1'
		call blocktransfer_string
		jmp error_skip                          ;After Subtraction start the loop once again
	
	switch_2:
		cmp byte[choice], 32h                   ;comparing with '2' or 32(ascii equivalent of 2)
		jne switch_3                            ;jump to switch_3 label if choice is not equal to '2'
		call blocktransfer
		jmp error_skip                          ;After Subtraction start the loop once again
	
	switch_3:                                       
		cmp byte[choice], 33h                   ;comparing with '5' or 35(ascii equivalent of 5)
		jne dflt                                ;jump to default label if choice is not equal to '5'
		mov rax, 60				;system call to rax for exit
		mov rdi, 0				;no error found
		syscall					;system call
	
		
	dflt:
		print Default_message, Def_len
		jmp error_skip
	
;PRINTING THE CHOICE MENU
_choice_menu:
	print newline, 1
	print choice1, choice1_len	
	print choice2, choice2_len
	print choice3, choice3_len
	print newline, 1
ret


blocktransfer_string:
	
	mov rcx , 05h
	mov rsi , input_data
	
	; this Loop is for taking the input into the input array
	loop1:
		push rsi 				;push rsi into the stack
		push rcx				;push rcx into the stack
		print input_message, len_input_message  ;output message
		read value, 17				;reading from the console
		call ascii_hex				;converting ascii to hex
		pop rcx					;pop rcx from the stack
		pop rsi					;pop rsi from the stack
		mov [rsi] , rbx				;put value at rbx into the the location pointed by rsi
		add rsi, 8				;rsi = ris+8
	loop loop1
	
	print before_transfer,before_transfer_len
	print newline, 1 
	;This loop is for showing the status of the input variable before the Tranfer
	
	print for_input, for_input_len
	print newline, 1
	
	print address, address_len
	print data, data_len
	
	mov rcx, 05
	mov rsi , input_data
	loop6:
		push rcx				;push rcx into the stack
		push rsi 				;push rsi into the stack
		mov rbx, rsi				;point rbx to rsi
		call display64
		print tab, 1
		pop rsi					;pop rsi from the stack
		mov rbx, [rsi]
		push rsi 				;push rsi into the stack
		call display64				;displaying the output
		print newline, 1
		pop rsi					;pop rsi from the stack
		pop rcx					;pop rcx from the stack
		add rsi, 8				;rsi = rsi + 8 
	loop loop6
	
	print newline, 1
	
	;This loop prints the status of the output variable before the string transfer
	print output_message, output_message_len 
	print newline, 1
	
	print address, address_len
	print data, data_len
	
	mov rcx, 05
	mov rsi , output_data -16
	loop8:
		push rcx				;push rcx into the stack
		push rsi 				;push rsi into the stack
		mov rbx, rsi				;point rbx to rsi
		call display64
		print tab, 1
		pop rsi					;pop rsi from the stack
		mov rbx, [rsi]
		push rsi 				;push rsi into the stack
		call display64				;displaying the output
		print newline, 1
		pop rsi					;pop rsi from the stack
		pop rcx					;pop rcx from the stack
		add rsi, 8				;rsi = rsi + 8 
	loop loop8
	
	
	;Data transfer using string instructions
	
	
	mov rsi, input_data +32			;source is pointed by rsi(in this case value64)
	mov rdi, output_data +16		;destination is pointed by rdi(in this case value32)
	std 					;setting the direction i.e. rsi and rdi will decrement 
	mov rcx, 05				;counter value 05
	rep movsq				;mov string byte by byte from source to destination till rcx is non-zero
	
	;This loop will show the result of input_data after data transfer
	print after_transfer, after_transfer_len
	print newline, 1
	
	print for_input, for_input_len
	print newline, 1
	
	
	print address, address_len
	print data, data_len
	
	mov rcx, 05
	mov rsi , input_data
	loop9:
		push rcx				;push rcx into the stack
		push rsi 				;push rsi into the stack
		mov rbx, rsi				;point rbx to rsi
		call display64
		print tab, 1
		pop rsi					;pop rsi from the stack
		mov rbx, [rsi]
		push rsi 				;push rsi into the stack
		call display64				;displaying the output
		print newline, 1
		pop rsi					;pop rsi from the stack
		pop rcx					;pop rcx from the stack
		add rsi, 8				;rsi = rsi + 8 
	loop loop9
	
	
	print newline, 1
	
	;This loop will show the result of output_data after data transfer
	print output_message, output_message_len 
	print newline, 1
	
	print address, address_len
	print data, data_len
	
	mov rcx, 05
	mov rsi , output_data- 16
	loop10:
		push rcx				;push rcx into the stack
		push rsi 				;push rsi into the stack
		mov rbx, rsi				;point rbx to rsi
		call display64
		print tab, 1
		pop rsi					;pop rsi from the stack
		mov rbx, [rsi]
		push rsi 				;push rsi into the stack
		call display64				;displaying the output
		print newline, 1
		pop rsi					;pop rsi from the stack
		pop rcx					;pop rcx from the stack
		add rsi, 8				;rsi = rsi + 8 
	loop loop10
	

ret






blocktransfer:
	mov rcx , 05h
	mov rsi , input_data
	
	; this Loop is for taking the input into the input array
	loop11:
		push rsi 				;push rsi into the stack
		push rcx				;push rcx into the stack
		print input_message, len_input_message	; printing input message
		read value, 17				;reading from the console
		call ascii_hex				;ascii to hex conversion
		pop rcx					;pop rcx
		pop rsi					;pop rsi
		mov [rsi] , rbx				;moving rbx to place where rsi points
		add rsi, 8				;rsi = rsi + 8
	loop loop11
	
	print before_transfer,before_transfer_len
	print newline, 1 
	;This loop is for showing the status of the input variable before the Tranfer
	
	print for_input, for_input_len
	print newline, 1
	
	print address, address_len
	print data, data_len
	
	mov rcx, 05
	mov rsi , input_data
	loop12:
		push rcx				;push rcx into the stack
		push rsi 				;push rsi into the stack
		mov rbx, rsi				;point rbx to rsi
		call display64
		print tab, 1
		pop rsi					;pop rsi from the stack
		mov rbx, [rsi]
		push rsi 				;push rsi into the stack
		call display64				;displaying the output
		print newline, 1
		pop rsi					;pop rsi from the stack
		pop rcx					;pop rcx from the stack
		add rsi, 8				;rsi = rsi + 8 
	loop loop12
	
	print newline, 1
	
	print output_message, output_message_len 
	print newline, 1
	
	print address, address_len
	print data, data_len
	
	mov rcx, 05
	mov rsi , output_data - 16
	loop13:
		push rcx				;push rcx into the stack
		push rsi 				;push rsi into the stack
		mov rbx, rsi				;point rbx to rsi
		call display64
		print tab, 1
		pop rsi					;pop rsi from the stack
		mov rbx, [rsi]
		push rsi 				;push rsi into the stack
		call display64				;displaying the output
		print newline, 1
		pop rsi					;pop rsi from the stack
		pop rcx					;pop rcx from the stack
		add rsi, 8				;rsi = rsi + 8 
	loop loop13
	
	
	;Data transfer without using string instructions
	
	mov rsi , input_data+ 32	;rsi points to last quad word of input data
	mov rdi , output_data+ 16	;rdi points to last quad word of output data
	mov rcx , 05			;assigning rcx with 5 for looping 5 times
	
	loop14:
		mov rax , [rsi]		;move value of rsi to rax
		mov [rdi] , rax		;move rax to value at rdi
		sub rsi, 8		;rsi= ris-8
		sub rdi, 8		;rdi = rid- 8
	loop loop14			;looping instruction

	
	print after_transfer, after_transfer_len
	print newline, 1
	
	
	print for_input, for_input_len
	print newline, 1
	
	
	print address, address_len
	print data, data_len
	
	mov rcx, 05
	mov rsi , input_data
	loop15:
		push rcx				;push rcx into the stack
		push rsi 				;push rsi into the stack
		mov rbx, rsi				;point rbx to rsi
		call display64
		print tab, 1
		pop rsi					;pop rsi from the stack
		mov rbx, [rsi]
		push rsi 				;push rsi into the stack
		call display64				;displaying the output
		print newline, 1
		pop rsi					;pop rsi from the stack
		pop rcx					;pop rcx from the stack
		add rsi, 8				;rsi = rsi + 8 
	loop loop15
	
	
	print newline, 1
	print output_message, output_message_len 
	print newline, 1
	
	print address, address_len
	print data, data_len
	
	mov rcx, 05
	mov rsi , output_data -  16
	loop16:
		push rcx				;push rcx into the stack
		push rsi 				;push rsi into the stack
		mov rbx, rsi				;point rbx to rsi
		call display64
		print tab, 1
		pop rsi					;pop rsi from the stack
		mov rbx, [rsi]
		push rsi 				;push rsi into the stack
		call display64				;displaying the output
		print newline, 1
		pop rsi					;pop rsi from the stack
		pop rcx					;pop rcx from the stack
		add rsi, 8				;rsi = rsi + 8 
	loop loop16
	

ret
	




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
	loop next3				;loop
	
	print temp64, 16
ret

	
		