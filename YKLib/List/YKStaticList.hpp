//
//  YKStaticList.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKStaticList_hpp
#define YKStaticList_hpp

#include "YKSeqList.hpp"

namespace YKLib
{
    template <typename T, int N>
    class YKStaticList : public YKSeqList<T>
    {
    protected:
        T m_space[N];
    public:
        YKStaticList()
        {
            this->m_array = m_space;
            this->m_length = 0;
        }
        
        int capacity() const
        {
            return N;
        }
    };
}

#endif /* YKStaticList_hpp */
