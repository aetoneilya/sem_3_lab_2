#include "Time.h"

void Time::addHour(int h)
{
    hour += h;
    day += (hour / 24);
    hour = hour % 24;
}

void Time::addMinute(int m)
{
    minute += m;
    addHour(minute / 60);
    minute = minute % 60;
}

void Time::addSecond(int s)
{
    second += s;
    addMinute(second / 60);
    second = second % 60;
}

void Time::addMS(int _ms)
{
    ms += _ms;
    addSecond(ms / 1000);
    ms = ms % 1000;
}

