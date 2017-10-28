//
//  YKDualLinkList.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKDualLinkList_hpp
#define YKDualLinkList_hpp

#include "YKLinkList.hpp"

namespace YKLib
{
    template <typename T>
    class YKDualLinkList : public YKList<T>
    {
    protected:
        
        struct Node: public YKObject
        {
            T value;
            Node* next;
            Node* pre;
        };
        
        mutable struct : public YKObject{
            char reserved[sizeof(T)];
            Node* next;
            Node* pre;
        } m_header;
        
        int m_length;
        int m_step;
        Node* m_current;
        
        
        Node* position(int i) const
        {
            Node* ret = reinterpret_cast<Node*>(&m_header);
            
            for (int p=0; p<i; p++)
            {
                ret = ret->next;
            }
            
            return ret;
        }
        
        virtual Node* create()
        {
            return new Node();
        }
        
        virtual void destroy(Node* pn)
        {
            delete pn;
        }
        
    public:
        
        YKDualLinkList()
        {
            m_header.next = nullptr;
            m_header.pre = nullptr;
            m_length = 0;
            m_step = 1;
            m_current = nullptr;
        }
        
        bool insert(const T& e)
        {
            return insert(m_length, e);
        }
        
        
        bool insert(int i, const T& e)
        {
            bool ret = ((0 <= i) && (i <= m_length));
            
            if (ret)
            {
                Node* node = create();
                
                if (node != nullptr)
                {
                    Node* current = position(i);
                    Node* next = current->next;
                    
                    node->value = e;
                    
                    node->next = next;
                    current->next = node;
                    
                    if (current != reinterpret_cast<Node*>(&m_header))
                    {
                        node->pre = current;
                    }else
                    {
                        node->pre = nullptr;
                    }
                    
                    if (next != nullptr)
                    {
                        next->pre = node;
                    }
                    
                    m_length++;
                }else
                {
                    THROW_EXCEPTION(YKNoEnoughMemoryException, "no memory to insert element ...");
                }
            }
            
            return ret;
        }
        
        bool remove(int i)
        {
            bool ret = ((0 <= i) && (i < m_length));
            
            if (ret)
            {
                Node* current = position(i);
                Node* toDel = current->next;
                Node* next = toDel->next;
                
                if (m_current == toDel)
                {
                    m_current = next;
                }
                
                current->next = next;
                if (next != nullptr)
                {
                    next->pre = toDel->pre;
                }
                
                m_length--;
                
                destroy(toDel);
            }
            
            return ret;
        }
        
        bool set(int i, const T& e)
        {
            bool ret = ((0 <= i) && (i < m_length));
            
            if (ret)
            {
                Node* current = position(i);
                current->next->value = e;
            }
            
            return ret;
        }
        
        bool get(int i, T& e) const
        {
            bool ret = ((0 <= i) && (i < m_length));
            
            if (ret)
            {
                Node* current = position(i);
                e = current->next->value;
            }
            
            return ret;
        }
        
        virtual T get(int i) const
        {
            T ret;
            
            if (get(i, ret))
            {
                return ret;
            }else
            {
                THROW_EXCEPTION(YKIndexOutOfBoundsException, "index out of Bounds!");
            }
        }
        
        int length() const
        {
            return m_length;
        }
        
        void clear()
        {
            while (m_length > 0)
            {
                remove(0);
            }
            
            m_length = 0;
        }
        
        int find(const T& e) const
        {
            int ret = -1;
            int i=0;
            
            Node* node = m_header.next;
            
            while (node)
            {
                if (node->value == e)
                {
                    ret = i;
                    break;
                }else
                {
                    node = node->next;
                    i++;
                }
            }
            return ret;
        }
        
        virtual bool move(int i, int step = 1)
        {
            bool ret = ((0 <= i) && (i<m_length) && (step > 0));
            
            if (ret)
            {
                m_current = position(i)->next;
                m_step = step;
            }
            
            return ret;
        }
        
        virtual bool pre()
        {
            int i=0;
            
            while ((i<m_step) && !end())
            {
                m_current = m_current->pre;
                i++;
            }
            
            return (i == m_step);
        }
        
        virtual bool end()
        {
            return (m_current == nullptr);
        }
        
        T current()
        {
            if (!end())
            {
                return m_current->value;
            }else
            {
                THROW_EXCEPTION(YKInvalidOperationException, "no value at current position ...");
            }
        }
        
        bool next()
        {
            int i=0;
            
            while ((i<m_step) && !end())
            {
                m_current = m_current->next;
                i++;
            }
            
            return (i == m_step);
        }
        
        ~YKDualLinkList()
        {
            clear();
        }
    };
}

#endif /* YKDualLinkList_hpp */
