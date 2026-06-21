#ifndef NAMESPACE_IDENTIFIER_H
#define NAMESPACE_IDENTIFIER_H

#include <config/c_pch.h>

namespace identifier {
    std::string generate_id(const std::string& text);
    std::string get_node_type_from_id(std::string& id);
};

#endif