;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
  DW 20 DUP (0000H)
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
  MOV CX, 10 ; counter register
  MOV DI, 00 ; Data segment pointer
  MOV AX, 00 ; First fibbo number
  MOV DX, 01 ; Second fibbo number
  
  loop1:
    ADD DX, AX ; DX = AX + DX (next fibbo number)
    MOV [DI], DX ; Store in memory
    INC DI ; Move pointer one word
    INC DI
    ADD AX, DX ; AX = AX + DX (Second next fibbo number)
    MOV [DI], AX ; Store in memory
    INC DI ; Move pointer one word
    INC DI
    LOOP loop1 ; CX--, jump to 'loop1' unless CX == 0
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
