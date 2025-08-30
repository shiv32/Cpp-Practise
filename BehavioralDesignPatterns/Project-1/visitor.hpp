#pragma once
#include "library_fwd.hpp"

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(Books& book) = 0;
    virtual void visit(Magazine& magazine) = 0;
};