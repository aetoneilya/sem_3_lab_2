#include "Interface.h"

std::istream &operator>>(std::istream &is, commands &command)
{
    std::string input;
    is >> input;
    if (input == "clock")
        command = commands::CLOCK;
    else if (input == "add")
        command = commands::ADD;
    else if (input == "pause")
        command = commands::PAUSE;
    else if (input == "continue")
        command = commands::CONTINUE;
    else if (input == "fstream")
        command = commands::TESTFSTREAM;
    else if (input == "sstream")
        command = commands::TESTSSTREAM;
    else if (input == "exit")
        command = commands::EXIT;
    else
        command = commands::NONE;
    return is;
}

void Interface::run()
{
    while (true)
    {
        std::cin >> cmd;
        if (cmd == commands::EXIT)
            return;
        doCommand(cmd);
        std::cin.clear();
    }
}

void Interface::doCommand(commands cmd)
{
    switch (cmd)
    {
    case commands::CLOCK:
        setTime();
        break;
    case commands::PAUSE:
        clock.pause();
        break;
    case commands::CONTINUE:
        clock.startClock();
        break;
    case commands::ADD:
        addTime();
        break;
    case commands::TESTFSTREAM:
        fileStreamTest();
        break;
    case commands::TESTSSTREAM:
        stringStreamTest();
        break;
    case commands::EXIT:
        exit(0);
        break;
    case commands::NONE:
        std::cout << "Error: unkoun command" << std::endl;
        break;

    default:
        std::cout << "Error: unknoun command" << std::endl;
        break;
    }
}

void Interface::setTime()
{
    int hour, minute, second;
    char ch1, ch2;
    std::cin >> hour >> ch1 >> minute >> ch2 >> second;
    //if (scanf("%d:%d:%d", &hour, &minute, &second) == 3)
    if (!std::cin || (ch1 != ':' && ch2 != ':'))
    {
        std::cout << "Error: wrong time format" << std::endl;
    }
    else
    {
        Time newTime{hour, minute, second};
        clock.setTime(newTime);
        clock.startClock();
    }
}

void Interface::addTime()
{
    int hour, minute, second;
    char ch1, ch2;
    std::cin >> hour >> ch1 >> minute >> ch2 >> second;
    if (!std::cin || (ch1 != ':' && ch2 != ':'))
    {
        std::cout << "Error: wrong time format" << std::endl;
    }
    else
    {
        Time newTime(hour, minute, second);
        clock.setTime(clock.time + newTime);
        clock.startClock();
    }
}

void Interface::fileStreamTest()
{
    std::string fileName;
    std::cin >> fileName;

    std::fstream file;
    file.open(fileName, std::fstream::out);
    if (!file)
    {
        std::cout << "Error: file can't be opened" << std::endl;
        return;
    }

    std::cout << "Enter time to put in file" << std::endl;

    int hour, minute, second;
    char ch1, ch2;
    std::cin >> hour >> ch1 >> minute >> ch2 >> second;
    while (!std::cin || (ch1 != ':' && ch2 != ':'))
    {
        std::cout << "Error: wrong time format" << std::endl;
        std::cin.clear();
        std::cin >> hour >> ch1 >> minute >> ch2 >> second;
    }
    Time time{hour, minute, second};

    file << time << std::endl;
}

void Interface::stringStreamTest()
{
    std::stringstream ss;

    int hour, minute, second;
    char ch1, ch2;
    std::cin >> hour >> ch1 >> minute >> ch2 >> second;
    while (!std::cin || (ch1 != ':' && ch2 != ':'))
    {
        std::cout << "Error: wrong time format" << std::endl;
        std::cin.clear();
        std::cin >> hour >> ch1 >> minute >> ch2 >> second;
    }
    Time time{hour, minute, second};

    ss << time << std::endl;
    std::string test;
    ss >> test;
    std::cout << "Output from stringstream - " << test << std::endl;
}