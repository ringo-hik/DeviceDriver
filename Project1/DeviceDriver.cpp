#include <iostream>
#include <vector>
#include <exception>

#define interface struct
using namespace std;
#include "DeviceDriver.h"


class ReadFailException : public std::exception {
public:
    explicit ReadFailException(const char* _Message) : std::exception(_Message) {
        std::cout << _Message << std::endl;
    }
};

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    std::vector<int> values;
    for (int i = 0; i < 5; i++) {
        int value = static_cast<int>(m_hardware->read(address));
        values.push_back(value);
    }

    for (size_t i = 1; i < values.size(); i++) {
        if (values[i] != values[i - 1]) {
            throw ReadFailException("Read Fail");
        }
    }

    return values[0];
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}