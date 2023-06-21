#include "File.h"
#include <fstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <Windows.h>

static std::string errMsg() {
    return "";
}

File::File(std::vector<std::byte>& filepath) {


    binaryData = filepath;
  
};