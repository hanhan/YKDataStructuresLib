//
//  YKObject.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKObject_hpp
#define YKObject_hpp

#include <stdio.h>

namespace YKLib
{
    class YKObject
    {
    public:
        
        void* operator new (unsigned long size) throw();
        void operator delete (void* p);
        void* operator new[] (unsigned long size) throw();
        void operator delete[] (void* p);
        bool operator == (const YKObject& object);
        bool operator != (const YKObject& object);
        
        virtual ~YKObject() = 0;
    };
}

#endif /* YKObject_hpp */
