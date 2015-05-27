;stack segment
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
;data segment
;------------
DTSEG SEGMENT
  ; place program data here
  DATA_IN DB 10H, 20H, 30H, 40H, 50H, 60H
  ORG 30H
  DEST DB 6 DUP (?)
  
DTSEG ENDS
;-----------
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; initialize
  MOV CX, 3
  MOV SI, OFFSET DATA_IN
  MOV DI, OFFSET DEST
  
  ; loop to copy 2 bytes in each iteration, repeats 3 times
  TARGET1: MOV AX, [SI]
  MOV [DI], AX
  INC SI
  INC DI
  LOOP TARGET1
  
  ;end program
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
