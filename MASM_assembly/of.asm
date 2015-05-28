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
  
  ; set overflow falg
  PUSHF
  POP AX
  OR AX, 0800H
  PUSH AX
  POPF
  
  ; clear overflow flag
  PUSHF
  POP AX
  AND AX, 0F7FFH
  PUSH AX
  POPF
  
  ;end (terminate) program
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
