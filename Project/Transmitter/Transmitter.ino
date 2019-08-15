/**
 * Transmitter file
 *VirtualWire.h library by Mike McCauly
 *https://www.pjrc.com/teensy/td_libs_VirtualWire.html
 */

#include <VirtualWire.h>

int x_axis = 0;   //x axis motion read on analog pin a0
int y_axis = 1;   //y axis motion read on analog pin a1
int transmit_pin = 12;  //transmission pin set to pin 12

void setup() {
  //Serial.begin(9600); debugging
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);
}

void loop() {
  int x_value = analogRead(x_axis);
  int y_value = analogRead(y_axis);
/*
 *Debugging
  Serial.print  ("x_value is: ");
  Serial.println(x_value);

  Serial.print  ("y_value is: ");
  Serial.println(y_value);
*/
  // Transmitter orientations
  // Built in LED flashes only when transmitter is tilted in a direction
  if ((x_value > 294 && x_value < 340) && (y_value > 294 && y_value < 340)) {        //Transmitter is parallel to ground
    Send("s");  //stationary
    digitalWrite(LED_BUILTIN,LOW);
    //Serial.println("stationary");
  } else{ 
      if ((x_value > 280 && x_value < 330) && (y_value > 318 && y_value < 333)) {    //Transmitter is tilted right
        Send("r");  //right
        digitalWrite(LED_BUILTIN, HIGH);
        //Serial.println("right");
      } if ((x_value > 350 && x_value < 380) && (y_value > 318 && y_value < 333)) {  //Transmitter is tilted left
        Send("l");  //left
        digitalWrite(LED_BUILTIN, HIGH);
        //Serial.println("left");
      } if ((x_value > 325 && x_value < 340) && (y_value > 280 && y_value < 328)) {  //Transmitter is tilted forward
        Send("f");  //forward
        digitalWrite(LED_BUILTIN, HIGH);
        //Serial.println("forward");
      } if ((x_value > 330 && x_value < 350) && (y_value > 332 && y_value < 380)) {  //Transmitter is tilted back
        Send("b");  //backward
        digitalWrite(LED_BUILTIN, HIGH);
        //Serial.println("back");
      }
  }   

  //Serial.println("\n"); debugging
  //delay(1000);  //1 second delay; debugging

}

void Send(char *command){
  vw_send((uint8_t *)command, strlen(command));
  vw_wait_tx();
}

