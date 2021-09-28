#pragma once
#include <conio.h>
#include "Time.h"

class Clock
{
private:
    bool isActive;

public:
    Time time{0, 0, 0};
    Clock(Time time_)
    {
        time = time_;
        isActive = 0;
    }
    Clock()
    {
        isActive = 0;
    }

    void setTime(Time time_)
    {
        time = time_;
    }

    void startClock();
    void pause();
};