# PIN MAP

bash
```
                 _______HHH_____
              5V|                | CLK
             CND|                | SD0
             SD3|                | SD1
             SD2|                | P15
             P13|                | P2
             GND|                | P0
             p12|                | P4  -> SCK
             P14|                | P16 -> DOUT 
      T1 <-  P27|                | P17 -> Servo 1
      T2 <-  P26|                | P5
      T3 <-  P25|                | P18
      E1 <-  P33|                | P19
      E2 <-  P32|                | GND
      E3 <-  P35|                | P21 -> SDA X [ currently not in use]
     LDR <-  P34|                | RX
             SUN|                | TX
             SUP|                | P22 -> SCK X [ currently not in use]
              EN|                | P23
             3V3|                | GND
                 ----------------
```
    
- T1,T2,T3 -> Trigger pin
- E1, E2, E3 -> Echo pin ultrasound
