/* *
 * Receiver file
 * Receiving pin is 11 by default
 * VirtualWire.h library by Mike McCauly
 * https://www.pjrc.com/teensy/td_libs_VirtualWire.html 
 */

#include <VirtualWire.h>

//wheels
int output_1 = 2;
int output_2 = 3;
int output_3 = 4;
int output_4 = 5;

void setup() {
  //Serial.begin(9600); debugging
  pinMode(output_1, OUTPUT);
  pinMode(output_2, OUTPUT);
  pinMode(output_3, OUTPUT);
  pinMode(output_4, OUTPUT);
 
  vw_setup(2000);   //bits per second
  vw_rx_start();    //start the receiver
}

void loop() {
    uint8_t buff[VW_MAX_MESSAGE_LEN];       //buffer to hold incoming message
    uint8_t buff_len = VW_MAX_MESSAGE_LEN;  //message length

    if (vw_get_message(buff, &buff_len))    //check for message
    {
      //Serial.print("Received: "); debugging
      for (int i = 0; i < buff_len; i++){
       //Serial.print(buff[i], DEC);         //print message as a decimal value
       //Serial.print(' ');
        
        if (buff[i] == 115){ //stationary
          digitalWrite(output_1, LOW);
          digitalWrite(output_2, LOW);
          digitalWrite(output_3, LOW);
          digitalWrite(output_4, LOW);
          Serial.println("stationary");
        } else{
            if (buff[i] == 114){ //right
              digitalWrite(output_1, LOW);
              digitalWrite(output_2, LOW);
              digitalWrite(output_3, HIGH);
              digitalWrite(output_4, LOW);
              Serial.println("right");
            } if (buff[i] == 108){  //left
              digitalWrite(output_1, HIGH);
              digitalWrite(output_2, LOW);
              digitalWrite(output_3, LOW);
              digitalWrite(output_4, LOW);
              Serial.println("left");
            } if (buff[i] == 102){  //forward
              digitalWrite(output_1, HIGH);
              digitalWrite(output_2, LOW);
              digitalWrite(output_3, HIGH);
              digitalWrite(output_4, LOW);
              Serial.println("forward");
            } if (buff[i] == 98){  //backward
              digitalWrite(output_1, LOW);
              digitalWrite(output_2, HIGH);
              digitalWrite(output_3, LOW);
              digitalWrite(output_4, HIGH);
              Serial.println("backward");
            }
        }
      } // end for
      //Serial.print("\n"); debugging
    
    } // end if
    
      //delay(1000); debugging

} // end loop
