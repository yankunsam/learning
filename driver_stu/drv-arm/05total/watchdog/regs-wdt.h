/***********************
 * 4412处理器看门狗设备的头文件
 * Author: zht
 * Date: 2014-11-11
 ***********************/
#ifndef __REGS_WDT_H
#define __REGS_WDT_H

/*********************
 * 看门狗寄存器的偏移
 *********************/
#define WTCON		0x0
#define WTDAT		0x4
#define WTCNT		0x8
#define WTCLRINT	0xC


/*********************
 * 具体寄存器的位设置
 *********************/
#define WTCON_RSTEN   (0x01)
#define WTCON_INTEN   (1<<2)
#define WTCON_ENABLE  (1<<5)

#define WTCON_DIV16   (0<<3)
#define WTCON_DIV32   (1<<3)
#define WTCON_DIV64   (2<<3)
#define WTCON_DIV128  (3<<3)

#define WTCON_PRESCALE(x) ((x) << 8)
#define WTCON_PRESCALE_MASK (0xff00)

#endif //__REGS_WDT_H
