#include <REGX52.H>
#include "SMG.h"
#include "key.h"
#include "delaY.H"


unsigned char KeyNUm;

void main()
{
	while(1)
	{
		KeyNUm=Key();
		if(KeyNUm)
		{
			SMG(1,KeyNUm);
		}
	}
}