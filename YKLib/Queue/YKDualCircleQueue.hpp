//
//  YKDualCircleQueue.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKDualCircleQueue_hpp
#define YKDualCircleQueue_hpp

#include "YKQueue.hpp"
#include "YKException.hpp"
#include "LinuxList.h"

namespace YKLib
{
    template <typename T>
    class YKDualCircleQueue: public YKQueue<T>
    {
    protected:
        struct Node: public YKObject
        {
            list_head head;
            T value;
        };
        
        list_head m_header;
        int m_length;
        
    public:
        
        YKDualCircleQueue()
        {
            m_length = 0;
            
            INIT_LIST_HEAD(&m_header);
        }
        
        void add(const T& e)
        {
            Node* node = new Node();
            
            if (node != nullptr)
            {
                node->value = e;
                
                list_add_tail(&node->head, &m_header);
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No memory to add new element ...");
            }
        }
        
        void remove()
        {
            if (m_length > 0)
            {
                list_head* toDel = m_header.next;
                
                list_del(toDel);
                
                m_length--;
                
                delete list_entry(toDel, Node, head);
            }
        }
        
        T front() const
        {
            if (m_length > 0)
            {
                return list_entry(m_header.next, Node, head)->value;
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "No element to add new element ...");
            }
        }
        
        void clear()
        {
            while (m_length > 0)
            {
                remove();
            }
        }
        
        int length() const
        {
            return m_length;
        }
        
        ~YKDualCircleQueue()
        {
            clear();
        }
    };
}

#endif /* YKDualCircleQueue_hpp */
