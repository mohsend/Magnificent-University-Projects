;stack segment
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
;data segment
;------------
DTSEG SEGMENT
  ; place program data here
  DATA_IN DB 10H, 20H, 30H, 40H, 50H, 60H ; 6 bytes of data
  ORG 10H
  DEST DB 6 DUP (?) ; allocate space to copy data into it
  
DTSEG ENDS
;-----------
CDSEG SEGMENT
  MAIN PROC FAR
  ASSUME CS:CDSEG, DS:DTSEG, SS:STSEG
  MOV AX, DTSEG
  MOV DS, AX
  ; main code starts here
  
  ; initialize
  MOV CX, 03 ; cx = 3
  MOV SI, OFFSET DATA_IN ; SI = address of first byte of DATA_IN
  MOV DI, OFFSET DEST ; DI = adress of first byte of DEST
  
  ; loop to copy 2 bytes in each iteration, repeats 3 times
  TARGET1: MOV AX, [SI] ; AX = 2bytes of DATA_IN
  MOV [DI], AX ; 2bytes of DEST = AX
  INC SI ; SI++
  INC SI ; SI++
  INC DI ; DI++
  INC DI ; DI++
  LOOP TARGET1
  
  ;end program
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
