# DFRobot_Geiger
正常工作时，在盖革管两端加高电压，盖革管自身相当于断路。<br>
当有高能粒子射入盖革管内时，粒子能量使管内气体电离放电，<br>
盖革管负极输出一个脉冲信号。<br>

该脉冲信号经过处理，驱动蜂鸣器输出‘哒哒’声，并由数字电路计数。  <br>
计数的基本单位为CPM，即为每分钟脉冲数，再根据盖革管数据表中的<br>
转换系数，即可将CPM转换为辐射强度单位μSv。<br>

## 输出信号与计算

默认为**高电平**，盖革管产生信号时输出一个**下拉脉冲**，脉冲宽度约300μs。

CPM为每分钟脉冲计数，实际可以不计满一分钟，如计20秒有10脉冲，则10*(20/60)=30CPM

μSv/h为辐射强度单位，与CPM的关系为μSv/h=CPM/151，即CPM为30时，辐射强度为μSv/h=30/151=0.199

nSv/h为辐射强度单位，关系为1000nSv/h=1μSv/h
### 常见CPM水平

| CPM | 描述 |
| --- | ---- |
| 40 | 自然环境基本辐射 |
| 400 | 高空飞行的客机外部辐射 |
| 800 | 切尔诺贝利核电站旁边 |
| 150000 | 核电站内部高辐射危险区 |

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary


提供一个arduino库来获取盖革计数器数据

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

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
     @return CPM值
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
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
FireBeetle-ESP8266        |      √       |              |             | 
FireBeetle-ESP32        |      √       |              |             | 
Arduino MEGA2560        |      √       |              |             | 
Arduino Leonardo|      √       |              |             | 
Micro:bit        |      √       |              |             | 
FireBeetle-M0        |      √       |              |             | 
Raspberry Pi      |      √       |              |             | 


## History

- Date 2021-9-15
- Version V0.1


## Credits

Written by fengli(li.feng@dfrobot.com), 2021.9.15 (Welcome to our [website](https://www.dfrobot.com/))


