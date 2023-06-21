#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "Injector/Shtreeba.h"
#include "Injector/FindProcessId.h"
#include <fstream>
int main(const int argc, char* argv[])
{
    char DLLPath[MAX_PATH];

    GetFullPathNameA("Loader.dll", MAX_PATH, DLLPath, nullptr);

    std::string Path = DLLPath;
    FindProcessId processList;

    const auto processInfo{ processList.getProcess(L"Victim.exe") };

    std::basic_ifstream<std::byte> file(Path.c_str(), std::ios::binary);

    std::vector<std::byte> Contents = { std::istreambuf_iterator<std::byte>(file), std::istreambuf_iterator<std::byte>() };

    Shtreeba shtreeba(processInfo, Contents);

    shtreeba.inject();

    return 0;
}