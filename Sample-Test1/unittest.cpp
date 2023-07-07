#include "../Project1/DeviceDriver.cpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace testing;

class MockFlashMemoryDevice : public FlashMemoryDevice {
public:
    MOCK_METHOD(unsigned char, read, (long address), (override));
    MOCK_METHOD(void, write, (long adress, unsigned char data), (override));
};

TEST(DeviceDriverTest, ReadTest) {
    MockFlashMemoryDevice mockDevice;
    DeviceDriver driver(&mockDevice);

    long val = 0xA;
    const int expectedValue = 0xAA;
    EXPECT_CALL(mockDevice, read(_))
        .Times(5)
        .WillRepeatedly(Return(expectedValue));
    
    EXPECT_THAT(driver.read(val), Eq(expectedValue));
}