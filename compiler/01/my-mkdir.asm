; Mimics the `mkdir` program in *nix
; The diffrence is it promps user for the name of the directory
; instead of accepting it as a comandline parameter

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
  promptstr DB 'Enter a name for the new folder: ', '$' ; '$' terminates string
  newdirname DB 30, ?, 32 dup (00h) ; max size, length, and content of the buffer
  
DTSEG ENDS

;-----------
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; Write string on STDOUT
  MOV DX, OFFSET promptstr ; Point to start of 'promptstr' string
  MOV AH, 09h ; STDOUT intrrupt code
  INT 21h ; Intrrupt DOS
  
  ; get new dir's name from user (STDIN)
  MOV AH, 0Ah ; Buffered input code
  MOV DX, OFFSET newdirname
  INT 21h ; Intrrupt DOS
  
  ; Convert buffer to ASCIZ
  MOV BX, OFFSET newdirname + 1 ; point to size of buffer
  MOV AL, [BX] ; calculate the address of end of content
  ADD BL, AL
  INC BL
  MOV [BX], 00h ; terminate content of buffer with zero
  
  ; Make new dir
  MOV DX, OFFSET newdirname + 2 ; point to content of buffer
  MOV AH, 39h ; make dir code
  INT 21h ; Intrrupt DOS
  
  ; end (terminate) program
  terminate:
  MOV AH, 4Ch
  INT 21h
  MAIN ENDP
CDSEG ENDS
  END MAIN
;-----------
