/*!
 *@file DFRobot_Geiger.cpp
 *@brief Define the basic structure of class DFRobot_Geiger, the implementation of the basic methods
 *@copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2021-9-14
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_Geiger
*/

#include <DFRobot_Geiger.h>
uint32_t numPulse1;
uint32_t numPulse2;
uint32_t numPulse3;
DFRobot_Geiger::DFRobot_Geiger(int pin)
{
  _intPin = pin;
  startMeasure = false;
}

void isr(){
	numPulse1++;
	numPulse2++;
	numPulse3++;
}

void DFRobot_Geiger::start()
{
	
  pinMode(_intPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(_intPin),isr, FALLING);
  startMeasure = true;
  numPulse1 = 0;
  numPulse2 = 0;
  numPulse3 = 0;
  startTime1 = millis();
  startTime2 = startTime1;
  startTime3 = startTime1;
}

void DFRobot_Geiger::pause()
{
  detachInterrupt(digitalPinToInterrupt(_intPin));
  endTime = millis();
  startMeasure = false;
}

uint16_t DFRobot_Geiger::getCPM()
{
  float CPM;
  uint32_t minutes;
  static uint8_t pos = 0;
  static uint8_t tail = 0;
  static uint8_t head = 0;
  
  if(startMeasure == false){
     minutes = (endTime - startTime1);
  } else {
	 minutes = (millis() - startTime1); 
     if(pos == 10) refresh1 = true;
  }
  CPM = (60000000)/(minutes-10);
  CPM = CPM/1000;
  //DBG(minutes);
  //DBG(numPulse1);
  CPM = CPM*numPulse1;
//DBG(CPM);
 // if(pos >= 10){
//	  pos = 0;
  //}

  Pulse1[tail] = CPM;
  pos++;
  tail ++;
  tail = (tail)%BUFFER_SIZE;
  
  //DBG(tail);
  if(first1){
	  uint32_t numAll = 0;
	  head  = (tail +7)%BUFFER_SIZE;
	  for(uint8_t i = 5 ; i < 8; i++){
		 
		 head++;
		
		 head =(head)%BUFFER_SIZE;
		  //Serial.print(head); Serial.print(" "); 
		 numAll += Pulse1[head];
		 
		 
	  }
	  
	  CPM = numAll / 3;
	  first1 --;
   } 
  
  if(refresh1 == true){
//Serial.println("------------------------");
		startTime1 =  millis();
        numPulse1 = 0;
		refresh1 = false;
		first1 = 3;
		pos = 0;
  }
  return (uint16_t)CPM;
}

uint16_t DFRobot_Geiger::getnSvh()
{
	
  float CPM;
  uint32_t minutes;
  static uint8_t pos = 0;
  static uint8_t tail = 0;
  static uint8_t head = 0;
  
  if(startMeasure == false){
     minutes = (endTime - startTime2);
  } else {
	 minutes = (millis() - startTime2); 
     if(pos == 10) refresh2 = true;
  }
  CPM = (60000000)/(minutes-10);
  CPM = CPM/1000;

  CPM = CPM*numPulse2;


  Pulse2[tail] = CPM;
  pos++;
  tail ++;
  tail = (tail)%BUFFER_SIZE;
  
  //DBG(tail);
  if(first2){
	  uint32_t numAll = 0;
	  head  = (tail +7)%BUFFER_SIZE;
	  for(uint8_t i = 5 ; i < 8; i++){
		 
		 head++;
		
		 head =(head)%BUFFER_SIZE;
		  //Serial.print(head); Serial.print(" "); 
		 numAll += Pulse2[head];
		 
		 
	  }
	  
	  CPM = numAll / 3;
	  first2 --;
   } 
  
  if(refresh2 == true){
//Serial.println("------------------------");
		startTime2 =  millis();
        numPulse2 = 0;
		refresh2 = false;
		first2 = 3;
		pos = 0;
  }
  //DBG(CPM);
  return (float(CPM/151))*1000;

}

float DFRobot_Geiger::getuSvh()
{
float CPM;
  uint32_t minutes;
  static uint8_t pos = 0;
  static uint8_t tail = 0;
  static uint8_t head = 0;
  
  if(startMeasure == false){
     minutes = (endTime - startTime3);
  } else {
	 minutes = (millis() - startTime3); 
     if(pos == 10) refresh3 = true;
  }
  CPM = (60000000)/(minutes-10);
  CPM = CPM/1000;
  //DBG(CPM);
  //DBG(numPulse1);
  CPM = CPM*numPulse3;
  //DBG(CPM);
 // if(pos >= 10){
//	  pos = 0;
  //}

  Pulse3[tail] = CPM;
  pos++;
  tail ++;
  tail = (tail)%BUFFER_SIZE;
  
  //DBG(tail);
  if(first3){
	  uint32_t numAll = 0;
	  head  = (tail +7)%BUFFER_SIZE;
	  for(uint8_t i = 5 ; i < 8; i++){
		 
		 head++;
		
		 head =(head)%BUFFER_SIZE;
		  //Serial.print(head); Serial.print(" "); 
		 numAll += Pulse3[head]; 
	  }
	  
	  CPM = numAll / 3;
	  first3 --;
   } 
  
  if(refresh3 == true){
//Serial.println("------------------------");
		startTime3 =  millis();
        numPulse3 = 0;
		refresh3 = false;
		first3 = 3;
		pos = 0;
  }
  
  return (float)CPM/151;
}

uint16_t DFRobot_Geiger::random()
{

}