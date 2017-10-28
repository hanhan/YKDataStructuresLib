//
//  YKLinkQueue.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKLinkQueue_hpp
#define YKLinkQueue_hpp

#include "YKQueue.hpp"
#include "YKLinkList.hpp"
#include "YKException.hpp"

namespace YKLib
{
    template <typename T>
    class YKLinkQueue : public YKQueue<T>
    {
    protected:
        YKLinkList<T> m_list;
    public:
        YKLinkQueue()
        {}
        
        void add(const T& e)
        {
            m_list.insert(e);
        }
        
        void remove()
        {
            if (m_list.length() > 0)
            {
                m_list.remove(0);
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current queue...");
            }
        }
        
        T front() const
        {
            if (m_list.length() > 0)
            {
                return m_list.get(0);
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current queue...");
            }
        }
        
        void clear()
        {
            m_list.clear();
        }
        
        int length() const
        {
            return m_list.length();
        }
    };
}

#endif /* YKLinkQueue_hpp */
