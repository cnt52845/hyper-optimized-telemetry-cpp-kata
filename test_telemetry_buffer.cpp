#include "telemetry_buffer.h"

#include <gmock/gmock.h>
#include <vector>

using ::testing::ElementsAreArray;

TEST(ToBuffer, UnsignedShort)
{
    std::vector<char> expected{0x2, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    EXPECT_THAT(TelemetryBuffer::to_buffer(5), ElementsAreArray(expected));
}
