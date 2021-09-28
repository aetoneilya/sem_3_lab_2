#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "Clock.h"

enum class commands
{
    CLOCK,
    ADD,
    PAUSE,
    CONTINUE,
    TESTFSTREAM,
    TESTSSTREAM,
    NONE,
    EXIT
};

class Interface
{
private:
    commands cmd;
    Clock clock;
    void setTime();
    void addTime();
    void fileStreamTest();
    void stringStreamTest();

public:
    void run();
    void doCommand(commands cmd);
};