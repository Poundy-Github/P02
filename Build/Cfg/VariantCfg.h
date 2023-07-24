#ifndef _VARIANT_CFG_H_
#define _VARIANT_CFG_H_

#if ((!(defined GWM_V35_PROJECT_TYPE_B03)) && (!(defined GWM_V35_PROJECT_TYPE_B02)))


#define PLATFOEM_OF_GNSS_USED

#ifdef PLATFOEM_OF_GNSS_USED
#define PLATFORM_OF_STB_IPC_USED
#endif

#endif

/*#define VARIANT_XX     0x00000000*/
#endif

