; sets (OV), and clears (NV) the overflow flag.
;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
DTSEG ENDS
;------------
; code segment :
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; set overflow flag (OV)
  PUSHF
  POP AX
  OR AX, 0800H
  PUSH AX
  POPF
  
  ; clear overflow flag (NV)
  PUSHF
  POP AX
  AND AX, 0F7FFH
  PUSH AX
  POPF
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
