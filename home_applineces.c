#include<lpc21xx.h>
#include "header.h"

#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
#define sw3 ((IOPIN0>>16)&1)

#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
unsigned int flag=0,flag1=0,flag2=0;
unsigned char rx_data;
void UART0_Handler(void)__irq
{
	rx_data=U0RBR;
	if(flag2==0)
	{
			switch(rx_data)
			{
				case 'a': IOCLR0=LED1;flag=1;break;
				case 'b': IOSET0=LED1;flag=0;break;
				case 'c': IOCLR0=LED2;flag1=1;break;
				case 'd': IOSET0=LED2;flag1=0;break;
				default: uart0_tx_string("\r\n my dear invalid choice");
			}
		}
	VICVectAddr=0;
	}
int main()
{
	PINSEL0=0x00000005;
	PINSEL1=0x00000000;
	
	IODIR0=LED1|LED2|LED3;
	IOSET0=LED1|LED2|LED3;
	
	uart0_init(9600);
	uart0_tx_string("\r\n vector india");
	U0IER=(1<<0);
	
	VICIntSelect &=~(1<<6);
	VICVectAddr0=(unsigned int)UART0_Handler;
	VICVectCntl0= 6|(1<<5);
	VICIntEnable |=(1<<6);
	
	while(1)
	{
		if(sw3==0)
		{
			delay_ms(50);
			while(sw3==0);
			flag2^=1;
			if(flag2)
				IOCLR0=LED3;
			else
				IOSET0=LED3;
		}
			if(flag2==1)
			{
				if(sw1==0)
				{
					delay_ms(50);
					while(sw1==0);
					flag^=1;
					if(flag)
						IOCLR0=LED1;
					else
						IOSET0=LED1;
				}
				if(sw2==0)
				{
					delay_ms(50);
					while(sw2==0);
					flag1^=1;
					if(flag1)
						IOCLR0=LED2;
					else
						IOSET0=LED2;
				}
			}
		}
	}


