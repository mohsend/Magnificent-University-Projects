; read 16 bytes from data segment and write them on the next line
; as is, if the byte is positive
; the positive equvilant value, if the byte is negative 
;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
  array DB 73H, 82H, 10H, 7FH, 0D0H, 20H, 0B3H, 01DH, 94H, 0A2H, 71H, 50H, 11H, 0B0H, 17H, 99H
  org 10H
  output DB 10H DUP (00H)
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
  MOV BX, OFFSET array
  MOV CX, 10H
  
  loop1:
    MOV AL, [BX]
    CMP AL, 00H
    JG writeout ; JG label Short Jump if first operand is Greater then second operand (as set by CMP instruction). Signed. 
    NOT AL ; toggle (NOT) AL bits
    INC AL ; AL = AL + 1
    ; last two lines are the same as "NEG AL". NEG: Negate. Makes operand negative (two's complement). 
    writeout:
    MOV [BX + 10H], AL
    INC BX
    LOOP loop1
    
  ;end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
