;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
  first_matrix DB 03 DUP (01H, 02H, 03H) ; allocate 3x3 byte matrix and init
  ORG 10H
  second_matrix DB 03 DUP (04H, 05H, 06H) ; allocate 3x3 byte matrix and init
  ORG 20H
  sum_matrix DB 09 DUP (00H) ; allocate 3x3 byte matrix 
  ORG 30H
  mul_matrix DB 09 DUP (00H) ; allocate 3x3 byte matrix 
  ORG 40H
  i DB 00H
  j DB 00H
  k DB 00H
DTSEG ENDS
;------------
; code segment :
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; code here
  
  ; initialize
  MOV CX, 09
  MOV SI, OFFSET first_matrix
  MOV DI, OFFSET sum_matrix
  
  ; loop to add first and second and store the resault in sum
  sum:
    MOV AL, [SI]
    ADD AL, [SI+10H]
    MOV [DI], AL
    INC SI
    INC DI
    LOOP sum
    
  ; multiply matrixes
  MOV SI, OFFSET first_matrix
  MOV DI, OFFSET mul_matrix
  raws:
    cols:
      MOV BX, 00H
      ADD BX, [i]
      ADD BX, [j]
      MOV [DI + BX], 00H
      MOV CX, 03H
        cells:
          MOV AX, [SI + BX]
          ADD AX, [SI + BX + 10H]
          ADD [DI + BX], AX
          LOOP cells
      INC [j]
      CMP [j], 03H
      JNZ cols
    ADD [i], 03H
    CMP [i], 09H
    JNZ raws
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
