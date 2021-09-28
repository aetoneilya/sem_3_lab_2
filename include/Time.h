#pragma once
#include <windows.h>
#include <iostream>

class Time
{
public:
    int day;
    int hour;
    int minute;
    int second;
    int ms;

    void addHour(int h);
    void addMinute(int m);
    void addSecond(int s);
    void addMS(int ms);
    Time(int h, int m, int s)
    {
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
        ms = 0;
        addHour(h);
        addMinute(m);
        addSecond(s);
    }
    Time operator+(Time b)
    {
        Time resTime(this->hour, this->minute, this->second);
        resTime.addSecond(b.second);
        resTime.addMinute(b.minute);
        resTime.addHour(b.hour);
        return resTime;
    }
};

template <typename T>
T &operator<<(T &stream, Time time)
{
    stream << time.hour << ':' << time.minute << ':' << time.second;
    return stream;
};
