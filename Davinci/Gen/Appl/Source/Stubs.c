#include "Compiler.h"
#include "Platform_Types.h"

#include "Rte_power.h"
#include "ecum.h"
#include "icu.h"
#include "rtm.h"

/*unsigned char test_flag;
unsigned int long test_w_value,test_r_value;*/



void IoHwAb_Adc_Notification_Group0(void)
{
}

void IoHwAb_Adc_Notification_Group1(void)
{
}

void Gpt_Notification_1(void)
{
}
#pragma weak IPC_IsrCsDetect_Standby
void IPC_IsrCsDetect_Standby(void)
{
	Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
	Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
}

#pragma weak IPC_IsrSocReqDetect2
void IPC_IsrSocReqDetect2(void)
{
}

void SpiJob0Notification(void)
{
}

void SpiSequenceEndNotification(void)
{
}








