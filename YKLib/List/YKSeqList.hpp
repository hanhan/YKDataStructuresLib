//
//  YKSeqList.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKSeqList_hpp
#define YKSeqList_hpp

#include "YKList.hpp"
#include "YKException.hpp"
#include <stdio.h>

namespace YKLib
{
    template <typename T>
    class YKSeqList : public YKList<T>
    {
    protected:
        
        T* m_array;
        int m_length;
        
    public :
        
        bool insert(int i, const T& e)
        {
            bool ret = ((0 <= i) && (i <= m_length));
            
            ret = ret && (m_length < capacity());
            
            if(ret)
            {
                for (int p = m_length-1; p>=i; p--)
                {
                    m_array[p+1] = m_array[p];
                }
            }
            
            m_array[i] = e;
            
            m_length++;
            
            return ret;
        }
        
        bool insert(const T& e)
        {
            return this->insert(m_length, e);
        }
        
        bool remove(int i)
        {
            bool ret = ((0 <= i) && (i <= m_length));
            
            if (ret)
            {
                for (int p=i; p<m_length-1; p++)
                {
                    m_array[p] = m_array[p+1];
                }
            }
            
            m_length --;
            
            return ret;
        }
        
        
        bool set(int i, const T& e)
        {
            bool ret = ((0 <= i)&&(i < m_length));
            
            if (ret)
            {
                m_array[i] = e;
            }
            
            return ret;
        }
        
        bool get(int i, T& e) const
        {
            bool ret = ((0 <= i)&&(i < m_length));
            
            if (ret)
            {
                e = m_array[i];
            }
            
            return ret;
        }
        int length() const
        {
            return m_length;
        }
        
        void clear()
        {
            m_length = 0;
        }
        
        T& operator[] (int i)
        {
            if ((0 <= i) && (i < m_length))
            {
                return m_array[i];
            }else
            {
                THROW_EXCEPTION(YKIndexOutOfBoundsException, "Paramter i is invalid...");
            }
        }
        
        T& operator[] (int i) const
        {
            return (const_cast<YKSeqList<T>&>(*this))[i];
        }
        
        int find(const T& e) const
        {
            int ret = -1;
            
            for (int i=0; i<m_length; i++)
            {
                if (m_array[i] == e)
                {
                    ret = i;
                    break;
                }
            }
            
            return ret;
        }
        
        virtual int capacity() const = 0;
        
    };
}

#endif /* YKSeqList_hpp */
