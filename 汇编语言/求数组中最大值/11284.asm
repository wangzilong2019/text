ASSUME CS:CODE,DS:DATA
DATA  SEGMENT
  BUFFER DB 0CH,0DH
         DB 0AH,0BH
  MAX DB  ?
DATA  ENDS
CODE  SEGMENT

  START: MOV AX, DATA
      MOV DS, AX
      MOV CX, OFFSET MAX - OFFSET BUFFER
      SHR CX, 1      ;对字型数据，数据个数是单元数的一半

      LEA BX, BUFFER
      MOV AL, [BX]   ;先设第一个为最大
      INC BX
      DEC CX

  AGAIN: CMP AL, [BX]
      JAE NEXT
      MOV AL, [BX]
  NEXT:
      INC BX
      LOOP AGAIN

      MOV DL, AL
 MOV CX,1;计数 初始为1
 MOV BL,10;每次除10

ONE:
 MOV AH,0;清零（存余数）
 MOV AL,DL
 DIV BL;除10
 PUSH AX;进栈
 CMP AL,0;是否已除净
 JLE ENDL
 MOV DL,AL
 INC CX
 JMP ONE


ENDL:
  POP DX
  XCHG DH,DL;余数转入DL
  ADD DL,30H
  MOV AH,2;输出
  INT 21H
  LOOP ENDL

      MOV AX, 4C00H
      INT 21H

  CODE  ENDS
  END   START
 