;to & fro pattern on the LED's.

; Logic 0 on a port 1 pin turns on the LED and vice versa.

MOV A, #FEH 
 
HERE:
    MOV P1, A          
;MOVE A TO PORT 1  i.e. 0th LED

    RL A              
;ROTATE CONTENT OF A 
;LEFT BY ONE BIT

    CJNE A, #01111111B, HERE
;check if a == 7f i.e.7th led
;continue here 

THERE: 
    MOV P1, A  
    RR A	;ROTATE RIGHT
    CJNE A, #1111110B, THERE   
;check if a == FE i.e.0th led
;continue There
JMP HERE
