CLR P0.7  ;ENABLE DAC

;set Timer 1 in mode 1 
;set Timer 0 as counter
MOV TMOD,#15H

MOV TH0, #00H
MOV TL0, #00H
SETB TR0 ;START COUNTER

;20ms TIMER for verification
MOV TH1,#0B1H
MOV TL1,#0E0H	
SETB TR1        ;START TIMER	

SQUARE: 
;HIGH-LOW-HIGH-LOW
        CPL A	 
;DAC  Display
		MOV P1,A 
;AS P3.5 IS FEEDED TO COUNTER
		MOV P3,A      
;124 IS LOADED INTO REGISTER 3
		MOV R3,#7CH         
		ACALL DELAY	
;LOOP TILL TIMER 1 OVERFLOW FLAG =1
		JNB TF1,SQUARE       
JMP LAST  ;END PROGRAM

;DELAY FUNCTION
DELAY:  
     ;LOOP TILL R3 == 0
    	DJNZ R3,DELAY       
    	RET

LAST:
END