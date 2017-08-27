/*************************
 * 用于ADC控制器的头文件
 * 适用于6410和4412
 * Author: zht
 * Date: 2014-10-27
 *************************/
#ifndef _REGS_ADC_H
#define _REGS_ADC_H

/***********************
 * 定义寄存器地址偏移
 ***********************/
#define S3C_ADCCON	0x00
#define S3C_ADCTSC	0x04
#define S3C_ADCDLY	0x08
#define S3C_ADCDAT0	0x0C
#define S3C_ADCDAT1	0x10
#define S3C_ADCUPDN	0x14
#define S3C_ADCCLRINT	0x18
#define S3C_ADCCLRWK	0x20


/****************
 * ADCCON
 ****************/
#define ADCCON_10BITS		(0x0<<16)
#define ADCCON_12BITS		(0x1<<16)
#define ADCCON_ECFLG		(0x1<<15)
#define ADCCON_PRSCEN		(0x1<<14)
#define ADCCON_PRSCVL(x)	(((x)&0xFF)<<6)
#define ADCCON_PRSCVLMASK	(0xFF<<6)
#define ADCCON_SEL(x)		(((x)&0x7)<<3)
#define ADCCON_SELMASK		(0x7<<3)
#define ADCCON_STDBM		(0x1<<2)
#define ADCCON_READ_START	(0x1<<1)
#define ADCCON_ENABLE_START	(0x1<<0)

/***************
 *  ADCTSC
 ***************/
#define ADCTSC_UD_SEN		(1<<8)
#define ADCTSC_YM_SEN		(1<<7)
#define ADCTSC_YP_SEN		(1<<6)
#define ADCTSC_XM_SEN		(1<<5)
#define ADCTSC_XP_SEN		(1<<4)
#define ADCTSC_PULL_UP_DISABLE	(1<<3)
#define ADCTSC_AUTO_PST		(1<<2)
#define ADCTSC_XY_PST(x)	(((x)&0x3)<<0)

/****************
 * ADCDAT
 ****************/
#define ADCDAT_UPDOWN		(1<<15)
#define ADCDAT_AUTO_PST		(1<<14)
#define ADCDAT_XY_PST		(0x3<<12)
#define ADCDAT_DATA_MASK10	(0x03FF)
#define ADCDAT_DATA_MASK12 	(0x0FFF)

#endif /* _REGS_ADC_H */

