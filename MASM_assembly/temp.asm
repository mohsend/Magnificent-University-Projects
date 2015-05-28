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
  
DTSEG ENDS
;------------
; code segment
;------------
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; code here
  
  
  ;end (terminate) program
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
