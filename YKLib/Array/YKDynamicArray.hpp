//
//  YKDynamicArray.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKDynamicArray_hpp
#define YKDynamicArray_hpp

#include "YKArray.hpp"
#include "YKException.hpp"

namespace YKLib
{
    template <typename T>
    class YKDynamicArray: public YKArray<T>
    {
    protected:
        
        int m_length;
        
        T* copy(T* array, int len, int newLen)
        {
            T* ret = new T[newLen];
            
            if (ret != nullptr)
            {
                int size = (len < newLen ? len : newLen);
                
                for (int i=0; i<size; i++)
                {
                    ret[i] = array[i];
                }
            }
            
            return ret;
        }
        
        void update(T* array, int length)
        {
            if (array != nullptr)
            {
                T* temp = this->m_array;
                
                this->m_array = array;
                this->m_length = length;
                
                delete [] temp;
            }else
            {
                THROW_EXCEPTION(YKNoEnoughMemoryException, "no memory to create DynamicArray object ...");
            }
        }
        
        void init(T* array, int length)
        {
            if (array != nullptr)
            {
                this->m_array = array;
                this->m_length = length;
            }else
            {
                THROW_EXCEPTION(YKNoEnoughMemoryException, "no memory to create DynamicArray object ...");
            }
        }
        
    public:
        
        YKDynamicArray(int length)
        {
            init(new T[length], length);
        }
        
        YKDynamicArray(const YKDynamicArray<T>& obj)
        {
            init(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
        }
        
        YKDynamicArray<T>& operator = (const YKDynamicArray<T>& obj)
        {
            if (this != &obj)
            {
                update(copy(obj.m_array, obj.length(), obj.m_length), obj.m_length);

            }else
            {
                THROW_EXCEPTION(YKNoEnoughMemoryException, "no memory to create DynamicArray object ...");
            }
            
            return *this;
        }
        
        int length() const
        {
            return m_length;
        }
        
        void resize(int length)
        {
            if (length != this->m_length)
            {
                update(copy(this->m_array, m_length, length), length);
            }
        }
        
        ~YKDynamicArray()
        {
            delete [] this->m_array;
        }
    };
}

#endif /* YKDynamicArray_hpp */
