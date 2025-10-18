#include <REGX52.H>
#include "Timer0.h"
#include "function.h"

void main()
{
    Timer0_Init();
    while(1)
    {
        led_stream();
    }
}