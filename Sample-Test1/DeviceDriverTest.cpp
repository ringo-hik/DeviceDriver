#include <thread>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Project1/DeviceDriver.h"

using namespace std;
using namespace testing;

class MockFlashMemoryDevice : public FlashMemoryDevice
{
public:
    MOCK_METHOD(unsigned char, read, (long address), (override));
    MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};

TEST(DeviceDriverTest, RepeatedRead)
{
    MockFlashMemoryDevice mockDevice;
    DeviceDriver driver(&mockDevice);
}

TEST(DeviceDriverTest, RepeatedReadFail)
{
    MockFlashMemoryDevice mockDevice;
    DeviceDriver driver(&mockDevice);
}