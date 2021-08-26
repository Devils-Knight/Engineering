; Write an assembly program to 

;		1.Converting ascii value into hex value

;		2.Than converting that hex number back to ascii value

; DOP: 24-02-2021

; Shubham Malik



		;<----MACRO--->

%macro print 2      ;Declaring MACRO with 2 parameters

  mov rax, 1        ;assigning system call in rax(1 for sys_write)

  mov rdi, 1        ;assign file descriptor to rdi(1 for stdout)

  mov rsi, %1       ;moving the buffer into rsi, 1st variale is represented by %1

  mov rdx, %2       ;moving the size of buffer into rdx, 2nd varable is represented by %2

  syscall           ;system call

%endmacro           ;MACRO END



%macro read 2       ;Declaring MACRO with 2 parameters

  mov rax, 0        ;assign system call to rax(0 for sys_read)

  mov rdi, 0        ;assign file descriptor to rdi(0 for stdin)

  mov rsi, %1       ;moving the buffer into rsi, 1st variale is represented by %1

  mov rdx, %2       ;moving the size of buffer into rdx, 2nd varable is represented by %2

  syscall           ;system call

%endmacro



		;<----Section Data---->

section .data

  message db "Enter number(hex): "      		   ;displaying output message

  message_length equ $- message			   ;Length of message

  error_msg db "Wrong Input Entered, Please try again: "   ;Handling error message

  error_len equ $- error_msg           		   ;lenght of error message

  newline db 10              				   ;newline

  

  		;<----Section BSS---->

section .bss

  value resb 17        ;reserve 17 bytes, 16 for hexa decimal and last for enter

  answer resq 5        ;reserve 5 quad word equivlent memory for storing the input data of 5 hexadecimal numbers

  temp resb 16         ;reserve 16 bytes for temp variable



		;<----Section Message---->

section .message

  global _start  

_start:    		;Main Program starts from here

      

error_skip:  

  mov rcx , 5    	;moving 5 in rcx to loop through 5 times for 5 inputs

    mov rsi, answer  	;now rsi has the address of answer

    

	;<----Loop 1 for ascii convertion into hex numbers---->

    loop1:

      

         push rcx	;push rcx into the stack so that we can fetch the same value of rcx after calling ascii_hex

         push rsi    	;push rsi into the stack so that we can fetch the same value of rsi after calling ascii_hex

                

          print message, message_length     ;Displaying message using print macro

          read value, 17	;Reading the input given by user using Read macro

          call ascii_hex        ;ASCII to HEX conversion

        

        

          pop rsi    		;fetching rsi from stack

          pop rcx    		;fetching rcx from stack

          mov [rsi], rbx  	;assigning value of address 'rsi' with 'rbx' i.e the converted form of ascii input

          add rsi, 8    	;increment rsi by 8 to continue for next loop



    

     loop loop1

    

     mov rcx, 5      	;moving 5 in rcx to loop through 5 times for 5 inputs

     mov rsi, answer    ;now rsi has the memory address of answer



	;<----Loop 2 for Hex convertion back to ascii---->    

     loop2:

          push rcx     ;push rcx into the stack so that we can fetch the same value of rcx after calling ascii_hex

          push rsi     ;push rsi into the stack so that we can fetch the same value of rsi after calling ascii_hex

          mov rbx, [rsi]

        

          call display64  ;diplay 5 hexa_decimal inputs by converting them back into ascii

        

          pop rsi      ;fetching rsi from stack

          pop rcx      ;fetching rcx from stack

          

          add rsi, 8

    

    loop loop2

  mov rax, 60     ;system call to rax for exit

  mov rdi, 0      ;no error found

  syscall         ;system call

    

    

;<----Error check label---->   

check:         	 ;To check wheter the value is greater than 4fh or not

  cmp al,40h        	 ;comparing two values

  jle error_label        ;if al <= 4fh, then jump to 'error_label' to print error message

  jmp return_check       ;otherwise jump to the next line of 'check' inside ascii_hex



;<----Error label---->  

error_label:        			;label to print error message and jump back to error_skip

  print error_msg, error_len     	;print the error message

  print newline, 1			;printing newline

  jmp error_skip       		;jump the main loop without incrementing rcx, so next time input for same loop will be taken



;<----ascii to hex convertion label---->

ascii_hex:        	;label-> under this label we convert ascii values to hexadecimal

  mov rcx, 16      	;assign 16 to rcx, for looping 16 times

  mov rsi, value        ;rsi now have the address of 'value'

  

  mov rbx, 0      		;clear buffer from rbx register

  next1:      			;label for looping 

    rol rbx, 4   	        ;rotating rbx left by 4 bits 

    mov al, [rsi]  		;al now have the value where rsi points

    

    ;<----Comparing for error handling---->

    cmp al, 2fh    		;comparing these two values

    	jbe error_label         ;if al <= 2fh, then jump to 'error_label'

    cmp al, 47h   	        ;comparing these two values

    	jge error_label         ;if al >= 47h,  then jump to 'error_label'

    cmp al, 3ah    		;comparing these two values

    	jge check   	        ;if al >= 40h, then jump to 'check' to check whether the value is smaller than 4fh or not

    return_check:  		;if al > 4fh, then above statement will jump here

    	

    	;<----Converting ascii to hex---->

    	cmp al, 39h 	        ;comparing 'al' with the ascii equivaluent of '0h' ->carry will be 1 if al <= 39h 

    		jbe sub30h      ;jump statement to label to line 

	    sub al, 7    	;al= al -7

	    sub30h:    	;label

	      sub al, 30h 	;al= al-30

	    add bl, al    	;bl= bl-al

	    inc rsi    	;rsi= rsi+1 (incrimenting one byte)

	    loop next1

  ret



		;<----Displaying ascii from hex Label---->

display64:        	;Label for HEX to ASCII conversion 

  mov rsi , temp

  mov rcx, 16

  

  

  next2:

    rol rbx, 4    	;Rotating rbx left by 4 bits

    mov al, bl    	;assign bl to al

    and al, 0Fh	;storing least significant hex value in al

    

    ;<----converting ascii from hex---->

    cmp al, 9    	;compare al and 39H [9]

    	jbe add30h    	;if al <= 39h [9] then add 30H

    

    add al, 7    	;if al is between A-F then add 7 to it

    

    add30h:

      add al, 30h  	;al=al+30

    

    mov [rsi], al	;assigning value of address 'rsi' with 'al', basically we are updating the memory pointed by temp

    inc rsi    	;rsi= rsi+1->increment rsi

    loop next2 	;loop

  

  print temp, 16	;Printing the output

  print newline, 1      ;print newline

  ret;