CLR A;CLR ACCUMULATOR

UP: ; START PROGRAM
MOV DPTR, #COS; POINTER FOR COS LOOKUP TABLE OF COS VALUES
MOV P0, 00H  ; SETTING WR HIGH TO ENABLE DAC
MOV R0, #00H ; UP COUNTER
MOV B, #40H ; NO. OF SAMPLES, DOWN COUNTER


HERE:
MOV A, R0
MOVC A, @A+DPTR
MOV P1, A
INC R0
DEC B
MOV A, B
JNZ HERE
JZ UP


COS:
DB 255, 253, 248, 240, 229, 215, 199, 182, 162, 142, 122, 101, 82, 63, 46, 32, 19, 10, 3, 0, 0, 3, 10, 19, 32, 46, 63, 82, 101, 122, 142, 162, 182, 199, 215, 229, 240, 248, 253, 255