#include<stdio.h>
#include<string.h>
#include <SPI.h>          //Library for using SPI Communication 
#include <mcp2515.h>      //Library for using CAN Communication
#include "Arduino.h"
MCP2515 mcp2515(10);




struct can_frame singleread(String test)
{
  int i;
  struct can_frame Msg;
  char delimiter[] = ",";
  char *p;
  char string[128];
  int lapse;

  test.toCharArray(string, sizeof(string));
  i = 0;
  p = strtok(string, delimiter);
  lapse = (int)strtol(p, NULL, 10);
  p = strtok(NULL, delimiter);
  Msg.can_id=strtol(p, NULL, 16);
  p = strtok(NULL, delimiter);
  Msg.can_dlc=(int)strtol(p, NULL, 10);
  for(int j=0;j<(int)Msg.can_dlc;j++)
  {
    p = strtok(NULL, delimiter);
    Msg.data[j]=(int)strtol(p, NULL, 16);
  }
  for(int j=(int)Msg.can_dlc;j<8;j++)
  {
    Msg.data[j]=(int)strtol(00, NULL, 16);
  }
  
  
  Serial.println("Sending message: ");
  Serial.print(' ');
  Serial.print(Msg.can_id,HEX);
  Serial.print(' ');
  Serial.print('[');
  Serial.print(Msg.can_dlc);
  Serial.print(']');
  Serial.print(' ');
  for(int i=0;i<8;i++)
  {    
    Serial.print(Msg.data[i],HEX); 
    Serial.print(' ');
  }
  
  Serial.println();
  return Msg;
}


void setup(){

  SPI.begin();               //Begins SPI communication
  Serial.begin(115200);
  mcp2515.reset();
  mcp2515.setBitrate(CAN_20KBPS,MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();

}

void loop(){

 struct can_frame canMsg;

 
 String part0;
 String part1;
 String part2;
 String part3;
 String part4;
 String part5;
 String part6;
 String part7;
 String part8;
 String part9;
 String part10;
 String part11;
 String part12;
 String part13;
 String part14;
 
 int t[15]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
 
 part0=" 1.0 ,02B7 ,8 ,00 ,00 ,00 ,B1 ,00 ,AE ,00 ,B0  ";
 part1=" 1.5 ,02B0 ,4 ,00 ,00 ,00 ,00  ";
 part2=" 2.6 ,04E3 ,3 ,00 ,00 ,00  ";
 part3=" 3.0 ,04B6 ,4 ,50 ,78 ,B0 ,81  ";
 part4=" 100.9 ,02B7 ,8 ,00 ,03 ,00 ,B6 ,00 ,B6 ,00 ,00  ";
 part5=" 101.5 ,02B0 ,4 ,00 ,00 ,00 ,00  ";
 part6=" 102.6 ,04E4 ,3 ,00 ,00 ,00  ";
 part7=" 103.0 ,04B6 ,4 ,50 ,78 ,B0 ,81  ";
 part8=" 202.9 ,01B7 ,8 ,00 ,00 ,0C ,B5 ,0C ,BA ,0C ,B8  ";
 part9=" 203.3 ,02B0 ,4 ,00 ,00 ,00 ,00  ";
 part10=" 204.2 ,04E5 ,3 ,00 ,00 ,00  ";
 part11=" 204.6 ,04B6 ,4 ,50 ,78 ,B0 ,81  ";
 part12=" 300.8 ,01B7 ,8 ,00 ,03 ,0C ,B7 ,0C ,B6 ,0C ,B8  ";
 part13=" 301.4 ,02B0 ,4 ,00 ,00 ,00 ,00  ";
 part14=" 302.5 ,01B2 ,3 ,00 ,00 ,00  ";



  

  
  canMsg = singleread(part0);
  mcp2515.sendMessage(&canMsg);
delay(t[0]);
 canMsg = singleread(part1);
  mcp2515.sendMessage(&canMsg);
delay(t[1]);
 canMsg = singleread(part2);
  mcp2515.sendMessage(&canMsg);
delay(t[2]);
 canMsg = singleread(part3);
  mcp2515.sendMessage(&canMsg);
delay(t[3]);
 canMsg = singleread(part4);
  mcp2515.sendMessage(&canMsg);
delay(t[4]);
 canMsg = singleread(part5);
  mcp2515.sendMessage(&canMsg);
delay(t[5]);
 canMsg = singleread(part6);
  mcp2515.sendMessage(&canMsg);
delay(t[6]);
 canMsg = singleread(part7);
  mcp2515.sendMessage(&canMsg);
delay(t[7]);
 canMsg = singleread(part8);
  mcp2515.sendMessage(&canMsg);
delay(t[8]);
 canMsg = singleread(part9);
  mcp2515.sendMessage(&canMsg);
delay(t[9]);
 canMsg = singleread(part10);
  mcp2515.sendMessage(&canMsg);
delay(t[10]);
 canMsg = singleread(part11);
  mcp2515.sendMessage(&canMsg);
delay(t[11]);
 canMsg = singleread(part12);
  mcp2515.sendMessage(&canMsg);
delay(t[12]);
 canMsg = singleread(part13);
  mcp2515.sendMessage(&canMsg);
delay(t[13]);
 canMsg = singleread(part14);
  mcp2515.sendMessage(&canMsg);
delay(t[14]);
 
  
 



}
