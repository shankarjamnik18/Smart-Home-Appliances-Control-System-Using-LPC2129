#include<lpc21xx.h>
void uart0_init(int baud)
{
	int pclk,result=0;
	int a[]={15,30,60};
	pclk=a[VPBDIV]*1000000;
	
	result=pclk/(16*baud);
	PINSEL0=0X5;
	U0LCR=0X83;
	U0DLL=(result&0xFF);
	U0DLM=(result>>8)&0XFF;
	U0LCR=0X03;
}
#define THRE ((U0LSR>>5)&1) 
void uart0_tx(unsigned char data) 
{ 
 U0THR=data; 
 while(THRE==0); 
}
void uart0_tx_string(char *ptr)
{
	while(*ptr)
	{
		uart0_tx(*ptr);
		ptr++;
	}
}
#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
	while(RDR==0);
		return U0RBR;
}
void uart0_tx_integer(int num)
{
	int a[10],i;
	if(num<0)
	{
		num=-num;
		uart0_tx('-');
	}
	if(num==0)
	{
		uart0_tx('0');
	}
	for(i=0;num;num=num/10,i++)
	a[i]=num%10+48;
	for(i=i-1;i>=0;i--)
	uart0_tx(a[i]);
}
void uart0_float(double f)
{
	int num;
	if(f<0)
	{
		f=-f;
		uart0_tx('-');
	}
	if(f==0)
	{
		uart0_tx_string("0.0");
	}
	num=f;
	uart0_tx_integer(num);
	uart0_tx('.');
  num=(num-f)*100;
	uart0_tx_integer(num);
}
void uart0_readstring(char *buf)
{
    int i;

    for(i=0;i<12;i++)
        buf[i]=uart0_rx();

    buf[12]='\0';
}
	