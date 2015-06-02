; linear search 128  bytes of random data previously residing in data segment (RAM)
; query is in the first byte of data segment
; program checks every byte, if found one equal to query
; write 01H to the 8th byte of data segment and end program
;------------
; stack segment :
STSEG SEGMENT
  DB 64 DUP (?)
STSEG ENDS
;------------
; data segment :
DTSEG SEGMENT
  ; place program data here
  query DB 01H
  ORG 08H
  ans DB 00H
  ORG 10H
  random DB ?
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
  MOV CX, 127 ; CX = 127
  MOV BX, OFFSET random ; BX = 0010H (address of first byte of random data on RAM)
  MOV AH, [query] ; AH = [query]
  
  ; loop and compare
  compare:
    MOV AL, [BX] ; AL = value of address of BX
    CMP AL, AH ; (AL - AH) and set Zero Flag accordingly
    JZ tell ; if (ZeroFlag == 0) goto tell 
            ; JZ label Short Jump if Zero (equal). Set by CMP, SUB, ADD, TEST, AND, OR, XOR instructions.
    INC BX ; BX++
    LOOP compare ; CX--; if (CX != 0) goto compare
  
  JMP terminate ; goto terminate
  
  tell:
    MOV [ans], 01H ; make the ans byte 1
  
  ; end (terminate) program
  terminate:
  MOV AH, 4CH
  INT 21H
  MAIN ENDP
CDSEG ENDS
  END MAIN
