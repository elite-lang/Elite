#pragma once

#include "Elite/Model/nodes.h"
#include <string>

namespace Elite
{

class GrammarParser {
public:
    Node* Parse(const std::string& data);
    Node* ParseFile(const std::string& file_path);

    
};

}