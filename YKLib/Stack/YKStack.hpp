//
//  YKStack.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKStack_hpp
#define YKStack_hpp

#include "YKObject.hpp"

namespace YKLib
{
    template <typename T>
    class YKStack: public YKObject
    {
    public:
        virtual void push(const T& e) = 0;
        virtual void pop() = 0;
        virtual T top() const = 0;
        virtual void clear() = 0;
        virtual int size() const = 0;
    };
}

#endif /* YKStack_hpp */
