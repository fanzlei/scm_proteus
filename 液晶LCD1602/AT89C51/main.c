/* Main.c file generated by New Project wizard
 *
 * Created:   周一 五月 15 2017
 * Processor: AT89C51
 * Compiler:  Keil for 8051
 */

#include <reg51.h>
#include <stdio.h>
#define uchar unsigned char
#define uint unsigned int
#define LCD P1
sbit RS = P2^0;
sbit RW = P2^1;
sbit E = P2^2;

uchar code tab[] = {"Hello 137"};

void Delayms(uint ms)
{
 	uchar i;
	while(ms--)
	{
	 	for(i=0;i<120;i++);
	}
}

//判忙函数，课本上的代码没有判忙，LCD不显示内容
//液晶硬件规定：RS = 0，RW = 1时可以读出忙信号，D7=1为忙，D7=0为不忙
uchar Busy_Check()
{
 	uchar LCD_Status;
	RS = 0;
	RW = 1;
	E = 1;
	Delayms(1);
   	LCD_Status = P0;
	E = 0;
	return LCD_Status;
}

void writeCMD(uchar cmd){
	uchar m;
	while((Busy_Check()&0x80)==0x80);
	RW = 0;//0代表写，1代表读
	RS = 0;//0代表命令，1代表数据
	P1 = cmd;
	for(m-0;m<=2;m++);
	E = 1;//液晶使能
	for(m-0;m<=2;m++);
	E = 0;
}

void writeData(uchar c){
	uchar m;
	while((Busy_Check()&0x80)==0x80);
	RW = 0;
	RS = 1;
	P1 = c;
	for(m-0;m<=2;m++);
	E = 1;//液晶使能
	for(m-0;m<=2;m++);
	E = 0;
}

//液晶初始化,硬件固定初始化步骤，不用记
void init(){
	RW = 0;//使写操作有效
	E = 0;//液晶使能
	writeCMD(0x38);
	writeCMD(0x0c);
	writeCMD(0x06);
	writeCMD(0x01);
}

void show_char(uchar row,uchar column,uchar c){
	uchar m;
	writeCMD(0x80+row*0x40+column);//写命令，内容是地址
	for(m=0;m<252;m++);
	writeData(c);
	
}
void main(void)
 { 
	 uchar i;
	 uint j;
	 init();
	 for(i=0;i<=9;i++){
		show_char(0,i,tab[i]);
		show_char(1,15-i,tab[i]); 
	 }
	 while(1);
}