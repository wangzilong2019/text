DATA SEGMENT
D1 DW 00FFH ;存放16位数00FFH
DATA ENDS
CODE SEGMENT
     ASSUME DS:DATA,CS:CODE
BEGIN: MOV AX,DATA
      MOV DS,AX
      MOV BX,D1 ;将00FFH存放BX寄存器中
      MOV CH,4  ;设置NEXT循环次数
      MOV CL,4  ;设置BX循环左移位数
NEXT:  ROL BX,CL   ;BX循环左移
      MOV DL,BL   ;将BX低8位BL存入DL中
      AND DL,0FH  ;DL与0FH逻辑与使DL高4位为0（清楚高4位），低4位不变
      ADD DL,30H  ;转换为数字ASCII
      CMP DL,39H  ;大于39H输出字符
      JLE  AD1
      ADD DL,07H  ;显示DL中字符
AD1:   MOV AH,2
      INT 21H
      DEC CH   ;CH减1
      JNZ NEXT  ;CH不等于0使跳转NEXT循环
      MOV AH,4CH  ;返回dos
      INT 21H
CODE ENDS
     END BEGIN
 