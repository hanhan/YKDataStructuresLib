//
//  YKQueue.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKQueue_hpp
#define YKQueue_hpp

#include "YKObject.hpp"

namespace YKLib
{
    template <typename T>
    class YKQueue: public YKObject
    {
    public:
        virtual void add(const T& e) = 0;
        virtual void remove() = 0;
        virtual T front() const = 0;
        virtual void clear() = 0;
        virtual int length() const = 0;
    };
}

#endif /* YKQueue_hpp */
