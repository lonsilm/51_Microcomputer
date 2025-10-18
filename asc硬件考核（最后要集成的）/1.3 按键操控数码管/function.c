#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "smg.h"
#include "Clean.h"
#include "key.h"

void control_smg()
{
    unsigned char key;
    static unsigned char num=0;
    key=Key();
    if(key==3)
    {
        num++;
    }
    if(key==4)
    {
        num--;
    }
    SMG(7,num/10);
    SMG(8,num%10);
}