#ifndef _PS2_H_
#define _PS2_H_
#include "main.h"

/*
需要
4个GPIO
    1.3个推挽输出模式 CLK DO CS
    2.1个上拉输入模式 DI
*/

#define PS2_CS_GPIOx GPIOA
#define PS2_CS_Pin GPIO_PIN_4

#define PS2_CLK_GPIOx GPIOA
#define PS2_CLK_Pin GPIO_PIN_5

#define PS2_DO_GPIOx GPIOA
#define PS2_DO_Pin GPIO_PIN_7

#define PS2_DI_GPIOx GPIOA
#define PS2_DI_Pin GPIO_PIN_6

typedef struct
{
    uint8_t A_D;                                       //模拟(红灯)为1 数字(无灯)为0
    int8_t Rocker_RX, Rocker_RY, Rocker_LX, Rocker_LY; //摇杆值(模拟状态为实际值0-0xFF)(数字态为等效的值0,0x80,0xFF)
    //按键值0为未触发,1为触发态
    uint8_t Key_L1, Key_L2, Key_R1, Key_R2;                //后侧大按键
    uint8_t Key_L_Right, Key_L_Left, Key_L_Up, Key_L_Down; //左侧按键
    uint8_t Key_R_Right, Key_R_Left, Key_R_Up, Key_R_Down; //右侧按键
    uint8_t Key_Select;                                    //选择键
    uint8_t Key_Start;                                     //开始键
    uint8_t Key_Rocker_Left, Key_Rocker_Right;             //摇杆按键

} PS2_TypeDef;
extern PS2_TypeDef PS2_Data;
void PS2_Read_Data(void);
#endif
