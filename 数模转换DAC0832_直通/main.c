/*=============================================================================
工程         :Proj_ch7_DAC0832
作者	   	 :王老师
时间         :2016年09月13日
描述         :DAC0832
=============================================================================*/
#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
/**********************************
ADC0832PIN口定义
**********************************/
sbit CS=P2^0;

/**********************************
DAC0832子函数定义
**********************************/
void dac0832(uchar dig)
{
  CS=0;//选择ADC0832工作
  P0=dig;
}
																  
/**********************************
主函数main()
**********************************/
void main()
{
    uchar i=0;   								  
	while(1)
    {
	  for(i=0;i<255;i++)
	  {
	    dac0832(i);	
	  }
	}   
}			



