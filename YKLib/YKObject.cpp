//
//  YKObject.cpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#include "YKObject.hpp"
#include <cstdlib>

namespace YKLib
{
    void* YKObject::operator new (unsigned long size) throw()
    {
        return malloc(size);
    }
    
    void YKObject::operator delete (void* p)
    {
        free(p);
    }
    
    void* YKObject::operator new[] (unsigned long size) throw()
    {
        return malloc(size);
    }
    
    void YKObject::operator delete[] (void* p)
    {
        free(p);
    }
    
    bool YKObject::operator == (const YKObject& object)
    {
        return (this == &object);
    }
    
    bool YKObject::operator != (const YKObject& object)
    {
        return (this != &object);
    }
    
    YKObject::~YKObject()
    {
        
    }
}


