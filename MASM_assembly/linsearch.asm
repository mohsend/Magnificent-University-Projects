; linear search an array of bytes
; query is in the first byte of data segment
; program checks every byte of array, if found one equal to query
; writes the address to the 8th byte of data segment and end program
;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
  query DB 94H
  ORG 08H
  here DW 00H
  ORG 10H
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
  MOV CX, 10H ; CX = 127
  MOV BX, OFFSET array ; BX = 0010H (address of first byte of array data on RAM)
  MOV AL, [query] ; AH = [query]
  
  ; loop and compare
  compare:
    CMP AL, [BX] ; (AL - [BX]) and set Zero Flag accordingly
    JZ tell ; if (ZeroFlag == 0) goto tell 
    ; JZ label Short Jump if Zero (equal). Set by CMP, SUB, ADD, TEST, AND, OR, XOR instructions.
    INC BX ; BX++
    LOOP compare ; CX--; if (CX != 0) goto compare
  
  JMP terminate ; goto terminate
  
  tell:
    MOV [here], BX ; make the ans the address
    
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
