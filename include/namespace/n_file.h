#ifndef NAMESPACE_FILE_H
#define NAMESPACE_FILE_H

#include <config/c_pch.h>

namespace file {
    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> read_whole_file_data(std::string path, std::string* search);
};

#endif