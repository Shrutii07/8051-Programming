;connection of switches to LED
;switches are connected to port 2 and LED's to port 1

; closed switch represents logic 0 which is then copied to port 1

HERE:  
    MOV P1, P2
    JMP HERE