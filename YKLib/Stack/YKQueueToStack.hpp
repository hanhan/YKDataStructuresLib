//
//  YKQueueToStack.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKQueueToStack_hpp
#define YKQueueToStack_hpp

#include "YKStack.hpp"
#include "YKLinkQueue.hpp"
#include "YKException.hpp"

namespace YKLib
{
    template <typename T>
    class YKQueueToStack: public YKStack<T>
    {
    protected:
        YKLinkQueue<T>* m_pIn;
        YKLinkQueue<T>* m_pOut;
        YKLinkQueue<T> m_queue_1;
        YKLinkQueue<T> m_queue_2;
        
        void move() const
        {
            int n = m_pIn->length() - 1;
            
            for (int i=0; i<n; i++)
            {
                m_pOut->add(m_pIn->front());
                m_pIn->remove();
            }
        }
        
        void swap() const 
        {
            YKLinkQueue<T> * temp = nullptr;
            temp = m_pIn;
            m_pIn = m_pOut;
            m_pOut = temp;
        }
    public:
        YKQueueToStack()
        {
            m_pIn = &m_queue_1;
            m_pOut = &m_queue_2;
        }
        
        void push(const T& e)
        {
            m_pIn->add(e);
        }
        
        void pop()
        {
            if (m_pIn->length() > 0)
            {
                move();
                m_pIn->remove();
                swap();
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current stack ...");
            }
        }
        
        T top() const
        {
            if (m_pIn->length() > 0)
            {
                move();
                return m_pIn->front();
                
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current stack ...");
            }
        }
        
        void clear()
        {
            m_queue_1.clear();
            m_queue_2.clear();
        }
        
        int size() const
        {
            remove(m_queue_1.length() + m_queue_2.length());
        }
    };
}

#endif /* YKQueueToStack_hpp */
