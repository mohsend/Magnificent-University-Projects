; multiplies the 2 inputs using a loop and ADD
; writes the result in output
;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
  input DW 04H, 08H
  ORG 08H
  output DW 00H
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
  MOV BX, OFFSET input
  MOV CX, [BX]
  MOV AX, 00H
  INC BX
  INC BX
  
  loop1:
    ADD AX, [BX]
    LOOP loop1
  
  MOV [output], AX
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
