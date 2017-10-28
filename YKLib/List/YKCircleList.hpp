//
//  YKCircleList.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKCircleList_hpp
#define YKCircleList_hpp

#include "YKLinkList.hpp"

namespace YKLib
{
    template <typename T>
    class YKCircleList: public YKLinkList<T>
    {
    protected:
        typedef typename YKLinkList<T>::Node Node;
        Node* last() const
        {
            return this->position(this->m_length-1)->next;
        }
        
        void last_to_first() const
        {
            last()->next = this->m_header.next;
        }
        
        int mod(int i) const
        {
            return (this->m_length == 0)?0:(i%this->m_length);
        }
        
    public:
        bool insert(const T&e)
        {
            return insert(this->m_length, e);
        }
        
        bool insert(int i, const T&e)
        {
            bool ret = true;
            
            i = i % (this->m_length + 1);
            
            ret = YKLinkList<T>::insert(i, e);
            
            if (ret && (i==0))
            {
                last_to_first();
            }
            return ret;
        }
        
        bool remove(int i)
        {
            bool ret = true;
            
            i = mod(i);
            
            if (i == 0)
            {
                Node* toDel = this->m_header.next;
                
                if (toDel != nullptr)
                {
                    this->m_header.next = toDel->next;
                    this->m_length--;
                    
                    if (this->m_length > 0)
                    {
                        last_to_first();
                        
                        if (this->m_current == toDel)
                        {
                            this->m_current = toDel->next;
                        }
                    }else
                    {
                        this->m_header.next = nullptr;
                        this->m_current = nullptr;
                    }
                    
                    this->destroy(toDel);
                }else
                {
                    ret = false;
                }
            }else
            {
                ret = YKLinkList<T>::remove(i);
            }
            
            return ret;
        }
        
        bool set(int i, const T& e)
        {
            return YKLinkList<T>::set(mod(i), e);
        }
        
        T get(int i) const
        {
            return YKLinkList<T>::get(mod(i));
        }
        
        bool get(int i, const T& e) const
        {
            return YKLinkList<T>::get(mod(i), e);
        }
        
        int find(const T&e) const
        {
            int ret = -1;
            
            Node* slider = this->m_header.next;
            
            for (int i=0; i<this->m_length; i++)
            {
                if (slider->value == e)
                {
                    ret = i;
                    break;
                }
                
                slider = slider->next;
            }
            
            return ret;
        }
        
        void clear()
        {
            while (this->m_length>1)
            {
                remove(1);
            }
            
            if (this->m_length == 1)
            {
                Node* toDel = this->m_header.next;
                
                this->m_header.next = nullptr;
                this->m_length = 0;
                this->m_current = nullptr;
                
                this->destroy(toDel);
            }
        }
        
        bool move(int i, int step)
        {
            return YKLinkList<T>::move(mod(i), step);
        }
        
        bool end()
        {
            return ((this->m_length == 0) || (this->m_current == nullptr));
        }
        
        ~YKCircleList()
        {
            clear();
        }
    };
}

#endif /* YKCircleList_hpp */
