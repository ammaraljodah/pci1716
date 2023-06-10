#include "slrtappmapping.h"
#include "./maps/driver_test.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <driver_test> */
		{ /* SignalMapInfo */
			driver_test_BIOMAP,
			driver_test_LBLMAP,
			driver_test_SIDMAP,
			driver_test_SBIO,
			driver_test_SLBL,
			{0,5},
			6,
		},
		{ /* ParamMapInfo */
			driver_test_PTIDSMAP,
			driver_test_PTNAMESMAP,
			driver_test_SPTMAP,
			{0,4},
			5,
		},
		"driver_test",
		"",
		"driver_test",
		1,
		driver_test_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}