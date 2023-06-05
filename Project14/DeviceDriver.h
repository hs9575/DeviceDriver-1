#pragma once
#include "FlashMemoryDevice.h"

class DeviceDriver
{
public:
    DeviceDriver(FMDAPI* hardware);
    int read(long address);
    void write(long address, int data);

protected:
    FMDAPI* m_hardware;

    const int TotalReadTryCount = 5;
};