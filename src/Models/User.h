#pragma once

#include <string>

namespace Models {

class User 
{
public:
    User(std::string id)
        : id(std::move(id))
    {
    }

    std::string id;
};

} // namespace Models
