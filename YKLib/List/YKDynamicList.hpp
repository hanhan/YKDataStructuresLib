//
//  YKDynamicList.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKDynamicList_hpp
#define YKDynamicList_hpp

#include "YKSeqList.hpp"
#include "YKException.hpp"

namespace YKLib
{
    template <typename T>
    class YKDynamicList : public YKSeqList<T>
    {
    protected:
        
        int m_capacity;
    public:
        
        YKDynamicList(int capacity)
        {
            this->m_array = new T[capacity];
            
            if (this->m_array != nullptr)
            {
                this->m_length = 0;
                this->m_capacity = capacity;
            }else
            {
                THROW_EXCEPTION(YKNoEnoughMemoryException, "no memory to create Dynamiclist object...");
            }
        }
        
        int capacity() const
        {
            return m_capacity;
        }
        
        void resize(int capacity)
        {
            if (capacity != m_capacity)
            {
                T* array = new  T[capacity];
                
                if (array != nullptr)
                {
                    int length = (this->m_length < capacity ? this->m_length : capacity);
                    
                    for (int i=0; i<length; i++)
                    {
                        array[i] = this->m_array[i];
                    }
                    
                    T* temp = this->m_array;
                    
                    this->m_array = array;
                    this->m_length = length;
                    this->m_capacity = capacity;
                    
                    delete [] temp;
                }else
                {
                    THROW_EXCEPTION(YKNoEnoughMemoryException, "no memory to resize Dynamiclist object...");
                }
            }
        }
        
        ~YKDynamicList()
        {
            delete [] this->m_array;
        }
    };
}

#endif /* YKDynamicList_hpp */
