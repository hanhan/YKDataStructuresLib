//
//  YKStaticArray.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKStaticArray_hpp
#define YKStaticArray_hpp

#include "YKArray.hpp"

namespace YKLib
{
    template <typename T, int N>
    class YKStaticArray : public YKArray<T>
    {
    protected:
        
        T m_space[N];
        
    public:
        
        YKStaticArray()
        {
            this->m_array = m_space;
        }
        
        YKStaticArray(const YKStaticArray<T, N>& obj)
        {
            this->m_array = m_space;
            
            for (int i=0; i<N; i++)
            {
                m_space[i] = obj.m_space[i];
            }
        }
        
        YKStaticArray<T, N>& operator = (const YKStaticArray<T, N>& obj)
        {
            if (this != &obj)
            {
                for (int i=0; i<N; i++)
                {
                    m_space[i] = obj.m_space[i];
                }
            }
            
            return *this;
        }
        
        int length() const
        {
            return N;
        }
    };
}

#endif /* YKStaticArray_hpp */
