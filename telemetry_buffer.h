#pragma once

#include "bit_converter.h"

class TelemetryBuffer {
public:
    static std::vector<char> to_buffer(long reading)
    {
        auto result        = std::vector<char>{0x2};
        auto reading_bytes = BitConverter::get_bytes<unsigned short>(reading);
        result.insert(result.end(), reading_bytes.begin(), reading_bytes.end());
        for (int i = 0; i < 6; i++)
            result.push_back(0x0);

        return result;
    }
};
