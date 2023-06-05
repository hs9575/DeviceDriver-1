#include "DeviceDriver.h"
#include <cstdio>
#include <windows.h>

#include <vector>
#include <exception>

using namespace std;

class myException:public std::exception
{
public:
    explicit myException(char const* _Message) : exception(_Message)
    {
    }
};

DeviceDriver::DeviceDriver(FMDAPI* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    int value;
    int temp;
    value = (int)(m_hardware->read(address));
	for (int tryCount = 2; tryCount <= TotalReadTryCount; tryCount++)
    {
        temp = (int)(m_hardware->read(address));
        if (temp != value)
            throw myException("ReadFailException");
        //Sleep(500);
    }

    return value;
}