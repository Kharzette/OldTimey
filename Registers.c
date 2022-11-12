#include	"Registers.h"


//check result for negative and zero flag set condition
void	FlagResultNZ(Registers *pRegs, const uint8_t result)
{
	if(result == 0)
	{
		pRegs->P	|=PFLG_ZERO;
	}
	else
	{
		pRegs->P	&=(!PFLG_ZERO);
	}

	if(result >> 7)
	{
		pRegs->P	|=PFLG_NEGATIVE;
	}
	else
	{
		pRegs->P	&=(!PFLG_NEGATIVE);
	}
}