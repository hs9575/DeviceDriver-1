#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Project14/DeviceDriver.cpp"

using namespace testing;
using namespace std;


class FMDMock:public FlashMemoryDevice
{
public:
	MOCK_METHOD((unsigned char), read, (long addr), (override));
	MOCK_METHOD(void, write, (long addr, unsigned char data), (override));
};

TEST(TestCaseName, FiveRead) {
	FMDMock fmd_mock;
	DeviceDriver driver(&fmd_mock);

	EXPECT_CALL(fmd_mock, read)
		.Times(5);

	driver.read(0xA);
}
TEST(TestCaseName, ReadException) {
	FMDMock fmd_mock;
	DeviceDriver driver(&fmd_mock);

	EXPECT_CALL(fmd_mock, read(0x2))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x3));

	EXPECT_THROW(driver.read(0x2), myException);
}