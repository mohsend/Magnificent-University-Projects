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
  array DB 73H, 32H, 10H, 7FH, 0D0H, 20H, 23H, 01DH, 44H, 0A2H, 71H, 50H, 01H, 0B0H, 17H, 99H
  org 10H
  maxi DB 00H
  ORG 18H
  mini DB 00H 
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
  
  ; init
  MOV BX, OFFSET array
  MOV AL, [BX]
  MOV DL, AL
  MOV DH, AL
  MOV CX, 10H
  
  loop1:
    INC BX
    MOV AL, [BX]
    CMP AL, DL
    JL newmin
    CMP DH, AL
    JL newmax
    continue:
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
    
  ;end (terminate) program
  terminate: MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
