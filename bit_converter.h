#pragma once

#include <cstring>
#include <vector>
#include <cstdint>
#include <vector>

class BitConverter {
public:
    static std::vector<unsigned char> int16_to_bytes(int16_t value)
    {
        return int_to_bytes(value, sizeof(int16_t));
    }

    static std::vector<unsigned char> uint16_to_bytes(uint16_t value)
    {
        return int_to_bytes(value, sizeof(uint16_t));
    }

    static std::vector<unsigned char> int32_to_bytes(int32_t value)
    {
        return int_to_bytes(value, sizeof(int32_t));
    }

    static std::vector<unsigned char> uint32_to_bytes(uint32_t value)
    {
        return int_to_bytes(value, sizeof(uint32_t));
    }

    static std::vector<unsigned char> int64_to_bytes(int64_t value)
    {
        return int_to_bytes(value, sizeof(int64_t));
    }

    static std::vector<unsigned char> uint64_to_bytes(uint64_t value)
    {
        return int_to_bytes(value, sizeof(uint64_t));
    }

    static int64_t bytes_to_int64(const std::vector<unsigned char>& byte_list)
    {
        int64_t value = 0;
        std::memcpy(&value, byte_list.data(), sizeof(int64_t));
        return value;
    }

private:
    template <typename T> static std::vector<unsigned char> int_to_bytes(T value, size_t length)
    {
        std::vector<unsigned char> bytes(length);
        std::memcpy(bytes.data(), &value, length);
        return bytes;
    }
};
