#include "Clock.h"

void Clock::startClock()
{
    isActive = true;
    while (isActive)
    {
        system("cls");
        std::cout << time << std::endl;
        time.addSecond(1);
        Sleep(900);
        if (kbhit())
        {
            isActive = 0;
        }
    }
}

void Clock::pause()
{
    system("cls");
    std::cout << time << std::endl;
}