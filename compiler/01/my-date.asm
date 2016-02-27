; Prints current system time and date to STDOUT in the following format:
; HH:MM:SS YY:MM:DD

;------------
;stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
;data segment :
DTSEG SEGMENT
  ; place program data here

  ; Define the character string 
  time DB "00:00:00 00/00/00", '$'
  
DTSEG ENDS
;-----------
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; Get system time
  MOV AH, 2Ch ; Get time code
  INT 21h ; Intrrupt DOS
  ; Return: CH = hour CL = minute DH = second DL = 1/100 seconds
  
  ; convert raw bytes to string for output
  ; Since we are dealing with time, we know the integer won't be longer than 2 decimal digits.
  ; So the following algorithm while not perfect, still works. 
  
  MOV DL, 10
  MOV AX, 0000h
  MOV AL, CH
  DIV DL ; AL = AX/10 ; AH = AX%10 ; converts byte to decimal
  ADD AX, '00' ; converts decimal to string
  MOV WORD ptr [time], AX ; Store hour ; XX:00:00 00/00/00
  
  MOV AX, 0000h
  MOV AL, CL
  DIV DL ; AL = AX/10 ; AH = AX%10
  ADD AX, '00'
  MOV WORD ptr [time + 3], AX ; Store Min ; 00:XX:00 00/00/00
  
  MOV AX, 0000h
  MOV AL, DH
  DIV DL ; AL = AX/10 ; AH = AX%10
  ADD AX, '00'
  MOV WORD ptr [time + 6], AX ; Store Sec ; 00:00:XX 00/00/00
  
  ; Get system date
  MOV AH, 2Ah ; Get time code
  INT 21h ; Intrrupt DOS
  ; Return: CX = year (1980-2099) DH = month DL = day AL = day of week (00h=Sunday)
  
  MOV DL, 100
  MOV AX, CX
  DIV DL ; AL = AX/100 ; AH = AX%100 ; AH = last two decimal digits of year
  
  MOV DL, 10
  MOV AL, AH
  MOV AH, 00h
  DIV DL ; AL = AX/10 ; AH = AX%10 ; converts byte to decimal
  ADD AX, '00' ; converts decimal to string
  MOV WORD ptr [time + 9], AX ; Store year ; 00:00:00 XX/00/00
  
  MOV AL, DH
  MOV AH, 00h
  DIV DL ; AL = AX/10 ; AH = AX%10 ; converts byte to decimal
  ADD AX, '00' ; converts decimal to string
  MOV WORD ptr [time + 12], AX ; Store Month ; 00:00:00 00/XX/00
  
  ; Get system date
  MOV AH, 2Ah ; Get time code
  INT 21h ; Intrrupt DOS
  ; Return: CX = year (1980-2099) DH = month DL = day AL = day of week (00h=Sunday)
  
  MOV AL, DL
  MOV AH, 00h
  MOV DL, 10
  DIV DL ; AL = AX/10 ; AH = AX%10 ; converts byte to decimal
  ADD AX, '00' ; converts decimal to string
  MOV WORD ptr [time + 15], AX ; Store Month ; 00:00:00 00/00/XX
  
  ; write the produced string on STDOUT
  MOV DX, OFFSET time ; Point to start of string
  MOV AH, 09h ; STDOUT intrrupt code
  INT 21h ; Intrrupt DOS
  
  ; end (terminate) program
  terminate:
  MOV AH, 4Ch
  INT 21h
  MAIN ENDP
CDSEG ENDS
  END MAIN
