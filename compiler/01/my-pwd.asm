; Mimics the `pwd` program in *nix
; (Prints current working directory on standard out)

;------------
;stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
;data segment :
DTSEG SEGMENT
  ; place program data here
  dirname DB 67 dup(00h) ; ASCIZ string
  
DTSEG ENDS
;-----------
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; get current drive
  MOV DL, 00h
  MOV BX, OFFSET dirname
  MOV AH, 19h ; GET CURRENT DEFAULT DRIVE
  INT 21h ; dos
  ADD AL, 'A' ; Converts drive number to the ASCII value
  MOV [BX], AL ; Store the ASCII value
  INC BX
  MOV [BX], ':' ; Store trailing ':\'
  INC BX
  MOV [BX], '\\'
  
  ; get current dir
  MOV DL, 00h
  INC BX
  MOV SI, BX ; Point to string after drive name
  MOV AH, 47h ; GET CURRENT DIRECTORY
  INT 21h ; dos
  
  ; Convert ASCIZ to ASCII and add trailing '/' and new line
  MOV BX, OFFSET dirname ; Point to start of string
  loopchar1:
    INC BX
	CMP [BX], 00h ; Look for 00h (ASCIZ terminator). Loop till found
	jnz loopchar1
  MOV [BX], '\\' ; add trailing '\' and string terminator ('$')
  INC BX
  MOV [BX], '$'
  
  ; print the produced string
  MOV DX, OFFSET dirname ; Point to start of string
  MOV AH, 09h ; STDOUT intrrupt code
  INT 21h ; Intrrupt DOS
  
  ; end (terminate) program
  terminate:
  MOV AH, 4Ch
  INT 21h
  MAIN ENDP
CDSEG ENDS
  END MAIN
