/*!
 *@file geiger.ino
 *@brief 检测CPM辐射强度,开始几次的读数可能有较大偏差,3次后数据趋于稳定
 *@copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2021-9-17
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_Geiger
*/

#include <DFRobot_Geiger.h>
#if defined ESP32
#define detect_pin D3
#else
#define detect_pin 3
#endif
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
  //通过3秒内的下降沿脉冲预测CPM,误差为±3CPM
  Serial.println(geiger.getCPM());
  //获取当前nSv/h，若已暂停，则nSv/h为暂停前最后数值
  Serial.println(geiger.getnSvh());
  //获取当前μSv/h，若已暂停，则μSv/h为暂停前最后数值
  Serial.println(geiger.getuSvh());
}