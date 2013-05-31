#include "taskFlyport.h"

long tcounter = 0;
char mystr[20];
void FlyportTask()
{
	WFConnect(WF_DEFAULT);
	while (WFStatus != CONNECTED);
	UARTWrite(1,"Flyport connected... hello world!\r\n");
	while(1)
	{
		if ((tcounter % 1000) == 0)
		{
			sprintf(mystr,"Uptime: %.2f s\n",(double)tcounter/100);
			UARTWrite(1,mystr);
		}
		tcounter++;
		vTaskDelay(1/portTICK_RATE_MS);
		
		
	}
}
