//
//  YKArray.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKArray_hpp
#define YKArray_hpp

#include "YKObject.hpp"
#include "YKException.hpp"

namespace YKLib
{
    template <typename T>
    class YKArray: public YKObject
    {
    protected:
        
        T * m_array;
        
    public:
        
        virtual bool set(int i, const T& e)
        {
            bool ret = ((0 <= i) && (i < length()));
            
            if (ret)
            {
                m_array[i] = e;
            }
            
            return ret;
        }
        
        virtual bool get(int i, T& e) const
        {
            bool ret = ((0 <= i) && (i < length()));
            
            if (ret)
            {
                e = m_array[i];
            }
            
            return ret;
        }
        
        T& operator[] (int i)
        {
            if ((0 <= i) && (i < length()))
            {
                return m_array[i];
            }else
            {
                THROW_EXCEPTION(YKIndexOutOfBoundsException, "Paramter i is invalid...");
            }
        }
        
        T operator[] (int i) const
        {
            return (const_cast<YKArray<T>&>(*this))[i];
        }
        
        T* array() const
        {
            return m_array;
        }
        
        virtual int length() const = 0;
        
    };
}

#endif /* YKArray_hpp */
