;------------
; stack segment
;------------
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment
;------------
DTSEG SEGMENT
  ; place program data here
  query DB 01H
  ans DB 00H
  ORG 10H
  random DB ?
DTSEG ENDS
;------------
; code segment
;------------
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; init
  MOV CX, 127;
  MOV BX, OFFSET random
  MOV AH, [query]
  
  ; loop and compare
  compare: MOV AL, [BX]
  CMP AL, AH
  JZ tell
  INC BX
  LOOP compare
  ; dec cx
  ; jnz compare
  JMP terminate
  
  ; make the ans byte 1
  tell: MOV [ans], 01H
  
  ;end (terminate) program
  terminate: MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
