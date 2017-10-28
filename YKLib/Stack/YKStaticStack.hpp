//
//  YKStaticStack.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKStaticStack_hpp
#define YKStaticStack_hpp

#include "YKStack.hpp"
#include "YKException.hpp"

namespace YKLib
{
    template <typename T, int N>
    class YKStaticStack: public YKStack<T>
    {
    protected:
        T m_space[N];
        int m_top;
        int m_size;
        
    public:
        YKStaticStack()
        {
            m_top = -1;
            m_size = 0;
        }
        
        int capacity() const
        {
            return N;
        }
        
        void push(const T& e)
        {
            if (m_size < N)
            {
                m_space[m_top + 1] = e;
                m_top++;
                m_size++;
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No Space in current stack ...");
            }
        }
        
        void pop()
        {
            if (m_size > 0)
            {
                m_top--;
                m_size--;
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current stack ...");
            }
        }
        
        T top() const
        {
            if (m_size > 0)
            {
                return m_space[m_top];
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No Space in current stack ...");
            }
        }
        
        void clear()
        {
            m_top = -1;
            m_size = 0;
        }
        
        int size() const
        {
            return m_size;
        }
    };
}

#endif /* YKStaticStack_hpp */
