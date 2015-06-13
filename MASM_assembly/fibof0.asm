; writes fibonacci series to data segment. starting from 0
;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
  DW 20 DUP (0000H)
DTSEG ENDS
;------------
; code segment :
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; initialize
  MOV CX, 10
  MOV DI, 00
  MOV AX, 00
  MOV DX, 01
  
  loop1:
    MOV [DI], AX
    INC DI
    INC DI
    MOV [DI], DX
    INC DI
    INC DI
    ADD AX, DX
    ADD DX, AX
    LOOP loop1
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
