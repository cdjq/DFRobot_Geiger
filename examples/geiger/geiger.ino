/*!
 *@file geiger.ino
 *@brief 检测CPM辐射强度
 *@copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2021-6-29
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_GM60
*/

#include <DFRobot_Geiger.h>

#define detect_pin 2
/*!
 * @brief Constructor
 * @param pin 外部中断引脚  
 */
DFRobot_Geiger  geiger(detect_pin);
void setup(){
   Serial.begin(115200);
   //开始计数，启用外部中断 
   geiger.start();
	
}

void loop(){ 
  //开始计数，启用外部中断 
  //geiger.start();
  delay(3000);
  //暂停计数，关闭外部中断触发，CPM和辐射强度值保持在暂停前状态
  //geiger.pause();
  //获取当前CPM，若已暂停，则CPM为暂停前最后数值
  Serial.println(geiger.getCPM());
  //获取当前nSv/h，若已暂停，则nSv/h为暂停前最后数值
  //Serial.println(geiger.getnSvh());
  //获取当前μSv/h，若已暂停，则μSv/h为暂停前最后数值
  //Serial.println(geiger.getuSvh());
   
}