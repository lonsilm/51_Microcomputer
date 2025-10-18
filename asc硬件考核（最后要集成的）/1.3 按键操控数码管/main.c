#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "smg.h"
#include "Clean.h"
#include "key.h"
#include "function.h"

void main()
{
    while(1)
    {
        control_smg();
    }
}