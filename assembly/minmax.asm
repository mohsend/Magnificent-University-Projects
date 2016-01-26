; find minimum and maximum of 16 unsigned bytes, and write them to memmory.
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
  ORG 10H
  maxi DB 00H
  ORG 18H
  mini DB 00H 
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
  MOV AL, [BX]
  MOV DL, AL
  MOV DH, AL
  MOV CX, 10H
  
  loop1:
    MOV AL, [BX]
    CMP AL, DL
    JB newmin ;  JB label Short Jump if first operand is Below second operand (as set by CMP instruction). Unsigned. 
    ; use JL if you wish to use signed bytes
    ; JL label Short Jump if first operand is Less then second operand (as set by CMP instruction). Signed. 
    CMP DH, AL
    JB newmax
    continue:
    INC BX
    LOOP loop1
  
  JMP writeout
  
  newmin:
    MOV DL, AL
    JMP continue
  
  newmax:
    MOV DH, AL
    JMP continue
    
  writeout:
    MOV [mini], DL
    MOV [maxi], DH
    
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
