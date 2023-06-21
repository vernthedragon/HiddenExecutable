#pragma once

#include <vector>
#include <filesystem>

class File
{
    std::vector<std::byte> binaryData;

public:
    explicit File(std::vector<std::byte>& filepath);

    constexpr auto& read()
    {
        return binaryData;
    };
};

