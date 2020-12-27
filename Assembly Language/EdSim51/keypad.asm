;KEYPAD

SETB  P3.7   ;INITIALIZE 7-SEG
SETB P3.6
SETB P3.5 ; ENABLE DISPLAY 3

;SET DATA POINTER TO 7-SEGMENT
MOV DPTR, #SEVENSEG     

AGAIN: 
; CHECKING FOR ROW 0
    ;CLEAR PO.0
    MOV P0, #11111110B  
    CLR A ;MOV 0 TO ACC
    ;COLUMN CHECK
    JNB P0.5, DISPLAY
    
; CHECKING FOR ROW 3
    ;CLEAR P0.3
    MOV P0, #11110111B  
    INC A
    ;COLUMN CHECK
    JNB P0.6, DISPLAY  
    INC A               
    JNB P0.5, DISPLAY
    INC A
    JNB P0.4, DISPLAY
    
; CHECKING FOR ROW 2
    ;CLEARING P0.2
    MOV P0, #11111011B  
    INC A
    ;COLUMN CHECK
    JNB P0.6, DISPLAY   
    INC A
    JNB P0.5, DISPLAY
    INC A
    JNB P0.4, DISPLAY
    
;CHECKING FOR ROW 1
    ;CLEARING P0.1
    MOV P0, #11111101B  
    INC A
    ;COLUMN CHECK
    JNB P0.6, DISPLAY   
    INC A
    JNB P0.5, DISPLAY
    INC A
    JNB P0.4, DISPLAY
    
;WHEN NO BUTTON IS PRESSED
    MOV P1,#0FFH ;ALL LES's OFF
    MOV P2,#0FFH ;7-SEG OFF
    JMP AGAIN

;DISPLAY BINARY EQUIVALENT ON LED"S
;DISPLAY NO. ON 7-SEG
DISPLAY:
;COMPLIMENT A TO DISPLAY BINARY EQUIVALENT ON LED's
		 CPL A 
		 MOV P1,A           
		 CPL A
;MOVE DATA FOR 7-SEGMENT IN ACC
         MOVC A,@A+DPTR         
         MOV P2,A
         JMP AGAIN
         
; DATASET OF VALUES TO DISPLAY 0-9 IN 7-SEGMENT DISPLAY

SEVENSEG:
DB 0C0H, 0F9H, 0A4H, 0B0H, 99H
DB 92H, 82H, 0F8H, 80H, 90H