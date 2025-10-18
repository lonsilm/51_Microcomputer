#include <REGX52.H>
#include "Delay.h"
#include "SMG.h"
#include "Clean.h"

void main()
{
    while(1)
    {
        SMG(1,2);Delay(1);clean();
        SMG(2,0);Delay(1);clean();
        SMG(3,0);Delay(1);clean(); 
        SMG(4,6);Delay(1);clean();
        SMG(5,1);Delay(1);clean();
        SMG(6,0);Delay(1);clean();
        SMG(7,0);Delay(1);clean();
        SMG(8,4);Delay(1);clean();
    }
}
