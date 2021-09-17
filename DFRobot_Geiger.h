/*!
 *@file DFRobot_Geiger.h
 *@brief Define the basic structure of class DFRobot_Geiger, the implementation of basic methods.
 *@copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2021-9-14
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_Geiger
*/

#ifndef DFRobot_GEIGER_H
#define DFRobot_GEIGER_H

#include <Arduino.h>
#define ENABLE_DBG

#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif
#define BUFFER_SIZE 10
class DFRobot_Geiger{

public:
  
  /*!
   * @brief Constructor
   * @param pin 外部中断引脚  
   */
  DFRobot_Geiger(int pin);

  /*!
   * @brief 开始计数，启用外部中断 
   */
  void start();
  
  /*!
   * @brief 暂停计数，关闭外部中断触发，CPM和辐射强度值保持在暂停前状态
   */
  void pause();
  
  /*!
   * @brief 获取当前CPM，若已暂停，则CPM为暂停前最后数值
   * @return CPM值
   */
  uint16_t getCPM();
  
  /*!
   * @brief 获取当前nSv/h，若已暂停，则nSv/h为暂停前最后数值
   */
  uint16_t getnSvh();
  
  /*!
   * @brief 获取当前μSv/h，若已暂停，则μSv/h为暂停前最后数值
   */
  float getuSvh();
 
  /*!
   * @brief 利用盖革计数器生成真随机数，这个功能与之前的辐射测量无关
   */
  uint16_t random();
  
private:
  int _intPin;
  long startTime1;
  long endTime;
  long startTime2;
  //long endTime2;
  long startTime3;
  //long endTime3;
  bool startMeasure;
  bool refresh1;
  bool refresh2;
  bool refresh3;
  float Pulse1[BUFFER_SIZE];
  float Pulse2[BUFFER_SIZE];
  float Pulse3[BUFFER_SIZE];
  uint8_t first1;
  uint8_t first2;
  uint8_t first3;
};


#endif

