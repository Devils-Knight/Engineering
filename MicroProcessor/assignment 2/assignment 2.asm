; Write an assembly program to Display the length of the Input string

; DOP: 24-02-2021

; Shubham Malik



			;<----MACRO--->

%macro print 2			;Declaring MACRO with 2 parameters

	mov rax, 1		;assigning system call in rax(1 for sys_write)

	mov rdi, 1		;assign file descriptor to rdi(1 for stdout)

	mov rsi, %1		;moving the buffer into rsi, 1st variale is represented by %1

	mov rdx, %2		;moving the size of buffer into rdx, 2nd varable is represented by %2

	syscall		;system call

%endmacro			;MACRO END



%macro read 2			;Declaring MACRO with 2 parameters

	mov rax, 0		;assign system call to rax(0 for sys_read)

	mov rdi, 0		;assign file descriptor to rdi(0 for stdin)

	mov rsi, %1		;moving the buffer into rsi, 1st variale is represented by %1

	mov rdx, %2		;moving the size of buffer into rdx, 2nd varable is represented by %2

	syscall		;system call

%endmacro





			;<----Displaying the Length of the input string--->

DisplayLength:					;Converting the HEX value to ASCII  	

	mov rcx, 2				;assigning 2 to rcx, for looping 2 times 

	mov rbx, rax				;rbx has now have the address of rax

	mov rsi, temp				;rsi has now have the address of temp

	next2:					;label for rotating 2 times

		rol bl, 4			;Rotating rbx left by 4 bits

		mov al, bl			;assign bl to al

		and al, 0Fh			;storing least significant hex value in al

		

		cmp al, 9			;compare al and 39H [9]

		jbe add30h			;if al <= 39h [9] then add 30H

		

		add al, 7			;if al is between A-F then add 7 to it

		

		add30h:

			add al, 30h		;al=al+30

		

		mov [rsi], al			;assigning value of address 'rsi' with 'al'

		

		inc rsi			;rsi= rsi+1-> increment rsi by 1 byte

		loop next2			;loop

	print output,output_length

	print temp, 2

	print newline, 1			;print newline

	ret					;return 



			;<---Section Data--->

section .data

	message db "Enter the Input: "

	message_len equ $- message

	newline db 10

	output db "Length of the Input String is: "

	output_length equ $- output

	

			;<---Section BSS--->

section .bss

	

	input resb 255				;taking the input from the user

	temp resb 2				;reserving 2 bytes for displaying output

	

			;<---Section text---> 

section .text

	global _start

	

_start:

	print message , message_len		;Displaying the message

	print newline, 1			;newline display

	read input, 255

	dec rax				;removing the extra value taken up by enter

	call DisplayLength			;Calling DisplayLength display

	

	mov rax, 60				;system call to rax for exit

	mov rdi, 0				;no error found

	syscall				;no error found

	



