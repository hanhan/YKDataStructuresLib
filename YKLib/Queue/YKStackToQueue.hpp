//
//  YKStackToQueue.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKStackToQueue_hpp
#define YKStackToQueue_hpp

#include "YKLinkStack.hpp"
#include "YKQueue.hpp"

namespace YKLib
{
    template <typename T>
    class YKStackToQueue: public YKQueue<T>
    {
    protected:
        mutable YKLinkStack<T> m_stack_in;
        mutable YKLinkStack<T> m_stack_out;
        
        void move() const
        {
            if (m_stack_out.size() == 0)
            {
                while (m_stack_in.size() > 0)
                {
                    m_stack_out.push(m_stack_in.top());
                    m_stack_in.pop();
                }
            }
        }
        
    public:
        void add(const T& e)
        {
            m_stack_in.push(e);
        }
        
        void remove()
        {
            move();
            
            if (m_stack_out.size() > 0)
            {
                m_stack_out.pop();
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current queue ...");
            }
        }
        
        T front() const
        {
            move();
            
            if (m_stack_out.size() > 0)
            {
                return m_stack_out.top();
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current queue ...");
            }
        }
        
        void clear()
        {
            m_stack_out.clear();
            m_stack_in.clear();
        }
        
        int length() const
        {
            return m_stack_out.size() + m_stack_in.size();
        }
    };
}

#endif /* YKStackToQueue_hpp */
