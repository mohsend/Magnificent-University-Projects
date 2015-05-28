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
  MOV CX, 04 ; CX = 4
  MOV BX, OFFSET INPUT ; BX = 0000H
  MOV AL, [BX] ; AL = 10H
  
  ; loop and add the 5 inputs and store the sum in AL
  TARGET1: INC BX ; BX++
  ADD AL, [BX] ; AL = AL + [BX]
  LOOP TARGET1 ; CX--; if (CX != 0) goto target1
  
  ; write AL (sum) to memory 
  MOV BX, OFFSET SUM ; BX = 05H
  MOV [BX], AL ; [BX] = AL
  
  ; end program
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
