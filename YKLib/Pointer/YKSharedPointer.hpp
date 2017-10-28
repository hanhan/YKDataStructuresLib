//
//  YKSharedPointer.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKSharedPointer_hpp
#define YKSharedPointer_hpp

#include "YKPointer.hpp"
#include <cstdlib>
#include "YKException.hpp"

namespace YKLib
{
    template <typename T>
    class YKSharedPointer : public YKPointer<T>
    {
    protected:
        int* m_ref;
        
        void assign(const YKSharedPointer<T>& obj)
        {
            this->m_ref = obj.m_ref;
            this->m_pointer = obj.m_pointer;
            
            if (this->m_ref)
            {
                (*this->m_ref)++;
            }
        }
        
    public:
        YKSharedPointer(T* p = nullptr) : m_ref(nullptr)
        {
            if(p)
            {
                this->m_ref = static_cast<int*>(std::malloc(sizeof(int)));
                
                if (this->m_ref)
                {
                    *(this->m_ref) = 1;
                    this->m_pointer = p;
                }else
                {
                    THROW_EXCEPTION(YKNoEnoughMemoryException, "no memory to create sharedPointer object...");
                }
            }
        }
        
        YKSharedPointer(const YKSharedPointer<T>& obj) : YKPointer<T>(nullptr)
        {
            assign(obj);
        }
        
        YKSharedPointer<T>& operator = (const YKSharedPointer<T>& obj)
        {
            if (this != &obj)
            {
                clear();
                assign(obj);
            }
            
            return *this;
        }
        
        void clear()
        {
            T* toDel = this->m_pointer;
            int* ref = this->m_ref;
            
            this->m_pointer = nullptr;
            this->m_ref = nullptr;
            
            if (ref)
            {
                (*ref)--;
                if (*ref == 0)
                {
                    free(ref);
                    
                    delete toDel;
                }
            }
        }
        
        ~YKSharedPointer()
        {
            clear();
        }
    };
    
    template <typename T>
    bool operator == (const YKSharedPointer<T>& l, const YKSharedPointer<T>& r)
    {
        return (l.get() == r.get());
    }
    
    template <typename T>
    bool operator != (const YKSharedPointer<T>& l, const YKSharedPointer<T>& r)
    {
        return !(l == r);
    }
}

#endif /* YKSharedPointer_hpp */
