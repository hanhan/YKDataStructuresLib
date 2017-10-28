//
//  YKPointer.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKPointer_hpp
#define YKPointer_hpp

#include "YKObject.hpp"

namespace YKLib
{
    template <typename T>
    class YKPointer: public YKObject
    {
    protected:
        T* m_pointer;
    public:
        YKPointer(T* p = nullptr)
        {
            m_pointer = p;
        }
        
        T* operator -> ()
        {
            return m_pointer;
        }
        
        T& operator * ()
        {
            return *m_pointer;
        }
        
        const T* operator -> () const
        {
            return m_pointer;
        }
        
        const T& operator * () const
        {
            return *m_pointer;
        }
        
        bool isNull()
        {
            return (m_pointer == nullptr);
        }
        
        T* get() const
        {
            return m_pointer;
        }
    };
}

#endif /* YKPointer_hpp */
