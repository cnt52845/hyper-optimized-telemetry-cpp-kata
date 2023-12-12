#pragma once

#include "bit_converter.h"

class TelemetryBuffer {
public:
    static std::vector<unsigned char> to_buffer(long reading)
    {
        auto buffer = std::vector<unsigned char>{0x02};

        auto reading_bytes = BitConverter::uint16_to_bytes(reading);
        buffer.insert(buffer.end(), reading_bytes.begin(), reading_bytes.end());

        for (int i = 0; i < 6; i++)
            buffer.push_back(0x00);

        return buffer;
    }
};
