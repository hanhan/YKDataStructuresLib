//
//  YKStaticQueue.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKStaticQueue_hpp
#define YKStaticQueue_hpp

#include "YKQueue.hpp"
#include "YKException.hpp"

namespace YKLib
{
    template <typename T, int N>
    class YKStaticQueue : public YKQueue<T>
    {
    protected:
        T m_space[N];
        int m_front;
        int m_rear;
        int m_length;
    public:
        YKStaticQueue()
        {
            m_front = 0;
            m_rear = 0;
            m_length = 0;
        }
        
        int capacity() const
        {
            return N;
        }
        
        void add(const T& e)
        {
            if (m_length < N)
            {
                m_space[m_rear] = e;
                m_rear = (m_rear + 1) % N;
                m_length++;
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No space in current Queue ...");
            }
        }
        
        void remove()
        {
            if (m_length > 0)
            {
                m_front = (m_front + 1) % N;
                m_length--;
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current Queue ...");
            }
        }
        
        T front() const
        {
            if (m_length > 0)
            {
                return m_space[m_front];
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current Queue ...");
            }
        }
        
        void clear()
        {
            m_front = 0;
            m_rear = 0;
            m_length = 0;
        }
        
        int length() const
        {
            return m_length;
        }
    };
}

#endif /* YKStaticQueue_hpp */
