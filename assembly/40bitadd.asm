; add two 40bit integers
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
  first DT 1100A8C054H
  ORG 10H
  second DT 63917788D7H
  ORG 20H
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
  MOV CX, 05
  MOV BX, 00
  MOV SI, OFFSET first
  
  CLC
  loop1: MOV AX, [SI+BX]
  ADC AX, [SI+BX+10H]
  MOV [SI+BX+20H], AX
  INC BX
  INC BX
  LOOP loop1
  
  ; end (terminate) program
  terminate: MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
