#pragma once

#include "ProcessInfo.h"
#include "File.h"
#include "MMap.h"

class Shtreeba
{
    ProcessInfo processInfo;
    File file;
    MMap mmap;

public:
    explicit Shtreeba(const ProcessInfo& _processInfo, std::vector<std::byte>& _file) : processInfo{ _processInfo }, file{ _file }, mmap(_processInfo, file.read()) { };

    bool inject() { return mmap.run(); };

    constexpr auto& getProcessInfo() { return processInfo; }
};