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
  INPUT DB 10H, 20H, 30H, 40H, 00H
  SUM DB 00H
DTSEG ENDS
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
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
