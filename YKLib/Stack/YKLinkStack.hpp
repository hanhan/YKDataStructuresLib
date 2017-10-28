//
//  YKLinkStack.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKLinkStack_hpp
#define YKLinkStack_hpp

#include "YKLinkList.hpp"
#include "YKStack.hpp"
#include "YKException.hpp"

namespace YKLib
{
    template <typename T>
    class YKLinkStack: public YKStack<T>
    {
    protected:
        
        YKLinkList<T> m_list;
        
    public:
        
        void push(const T& e)
        {
            m_list.insert(0, e);
        }
        
        void pop()
        {
            if (m_list.length() > 0)
            {
                m_list.remove(0);
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current stack ...");
            }
        }
        
        T top() const
        {
            if (m_list.length() > 0)
            {
                return m_list.get(0);
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element in current stack ...");
            }
        }
        
        void clear()
        {
            m_list.clear();
        }
        
        int size() const
        {
            return m_list.length();
        }
    };
}

#endif /* YKLinkStack_hpp */
