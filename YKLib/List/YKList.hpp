//
//  YKList.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKList_hpp
#define YKList_hpp

#include "YKObject.hpp"

namespace YKLib
{
    template <typename T>
    class YKList : public YKObject
    {
    protected:
        
        YKList(const YKList&);
        YKList& operator = (const YKList&);
        
    public:
        
        YKList(){}
        virtual bool insert(const T& e) = 0;
        virtual bool insert(int i, const T& e) = 0;
        virtual bool remove(int i) = 0;
        virtual bool set(int i, const T& e) = 0;
        virtual bool get(int i, T& e) const = 0;
        virtual int find(const T& e) const = 0;
        virtual int length() const = 0;
        virtual void clear() = 0;
    };
}

#endif /* YKList_hpp */
