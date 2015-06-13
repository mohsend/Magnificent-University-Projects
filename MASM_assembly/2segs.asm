; adds 5 bytes and writes the sum on the 6th byte. another algorithm.
;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
  INPUT_D DB 10H, 20H, 30H, 40H, 00H
  SUM_D DB 00H
DTSEG ENDS
; extra segment :
EXSEG SEGMENT
  ; place program data here
  INPUT_E DB 10H, 20H, 30H, 40H, 01H, 02H, 03H, 01H, 01H, 02H 
  SUM_E DB 00H
EXSEG ENDS
;-----------
; code segment :
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; initialize
  MOV CX, 5 ; CX = 5
  MOV AL, 0 ; AL = 0
  MOV BX, 00H ; BX = 00H
  
  ; loop
  TARGET1:
    ADD AL, [BX] ; AL = AL + [BX]
    INC BX ; BX++
    LOOP TARGET1 ; CX--; if (CX != 0) goto target1
  
  ; write AL (sum) to memory
  MOV [BX], AL ; [BX] = AL
  
  DEC AH
  JZ terminate
  
  ; init for the second segment (extra segement)
  ASSUME DS:EXSEG
  MOV AX, EXSEG
  MOV DS, AX
  MOV CX, 10 ; CX = 5
  MOV AL, 00H ; AL = 0
  MOV AH, 01H ; AH = 1
  MOV BX, 00H ; BX = 00H
  JMP TARGET1
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
