/* Main.c file generated by New Project wizard
 *
 * Created:   周五 五月 12 2017
 * Processor: AT89C51
 * Compiler:  Keil for 8051
 */

#include <reg51.h>
#include <stdio.h>
sbit led = P2^0;


void init(){
	IT1 = 1;//设置外部中断0为边缘触发
	EX1 = 1;//开外部中断0
	EA = 1;//开总中断允许
	}
void main(void)
 { 
   init();
	while(1);
 }
 
 
void int1() interrupt 2{
	led = ~led;
	}