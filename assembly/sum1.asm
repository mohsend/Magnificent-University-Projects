;stack segment
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
;data segment
;------------
DTSEG SEGMENT
  ; place program data here
  INPUT DB 10H
  DB 20H
  DB 30H
  DB 40H
  DB 00H
  SUM DB 00H
  
DTSEG ENDS
;-----------
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; initialize
  MOV CX, 4
  MOV BX, OFFSET INPUT
  MOV AL, [BX]
  
  ; loop and add the 5 inputs and store the sum in AL
  TARGET1: INC BX
  ADD AL, [BX]
  LOOP TARGET1
  
  ; write AL (sum) to memory 
  MOV BX, OFFSET SUM
  MOV [BX], AL
  
  ; end program
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
