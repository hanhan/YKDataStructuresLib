//
//  YKSmartPointer.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKSmartPointer_hpp
#define YKSmartPointer_hpp

#include "YKPointer.hpp"

namespace YKLib
{
template <typename T>
class YKSmartPointer : public YKPointer<T>
{
public:
    YKSmartPointer(T *p = nullptr) : YKPointer<T>(p)
    {
    }
    
    YKSmartPointer(const YKSmartPointer<T>& obj)
    {
        this->m_pointer = obj.m_pointer;
        
        const_cast<YKSmartPointer<T> &>(obj).m_pointer = nullptr;
    }
    
    YKSmartPointer<T>& operator = (const YKSmartPointer<T>& obj)
    {
        if (this != &obj)
        {
            T* p = this->m_pointer;
            this->m_pointer = obj.m_pointer;
            
            const_cast<YKSmartPointer<T>&>(obj).m_pointer = nullptr;
            
            delete p;
        }
        
        return *this;
    }
    
    ~YKSmartPointer()
    {
        delete this->m_pointer;
    }
    
};
    
}

#endif /* YKSmartPointer_hpp */
