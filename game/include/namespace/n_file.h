#ifndef NAMESPACE_FILE_H
#define NAMESPACE_FILE_H

#include <config/c_pch.h>
#include <engine/e_variant.h>

namespace file {
    std::vector<std::pair<std::string, VariantType>> read_whole_file_data(std::string path, std::string* search);
    std::vector<std::pair<std::string, VariantType>> read_data(std::string& dataString, std::string* search);
    
};

#endif