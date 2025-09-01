#pragma once
#include "library_fwd.hpp"

class Library {
public:
    virtual ~Library() = default;
    virtual void accept(Visitor& vi) = 0;
    virtual void itemGet() = 0;
    virtual void itemGive() = 0;
};