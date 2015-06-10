; bubble sort algorithm implemented in assembly
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
  MOV CX, 0FH
  
  loop1:
     MOV BX, OFFSET array
    loop2:
      MOV AL, [BX]
      MOV AH, [BX + 01H]
      CMP AL, AH
      JA swapval ;  JA label Short Jump if first operand is Above second operand (as set by CMP instruction). Unsigned. 
      ; use JG if you wish to use signed bytes
      ; JG label Short Jump if first operand is Greater then second operand (as set by CMP instruction). Signed. d. 
      continueloop2:
      INC BX
      CMP CX, BX
      JA loop2
    CMP CX, 01H
    JA loop1
  
  swapval:
    MOV [BX], AH
    MOV [BX + 01H], AL
    JMP continueloop2
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
