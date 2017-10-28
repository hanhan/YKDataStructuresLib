//
//  YKString.hpp
//  YKLib
//
//  Created by nethanhan on 2017/10/22.
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKString_hpp
#define YKString_hpp

#include "YKObject.hpp"

namespace YKLib
{
    class YKString: public YKObject
    {
    protected:
        char* m_str;
        int m_length;
        
        void init(const char* s);
        bool equal(const char* l, const char* r, int len) const;
        
        static int* make_pmt(const char* p);
        static int kmp(const char* s, const char* p);
    public:
        YKString();
        YKString(char c);
        YKString(const char* s);
        YKString(const YKString& s);
        
        const char* str() const;
        int length() const;
        
        bool operator == (const YKString& s) const;
        bool operator == (const char* s) const;
        bool operator != (const YKString& s) const;
        bool operator != (const char* s) const;
        bool operator > (const YKString& s) const;
        bool operator > (const char* s) const;
        bool operator < (const YKString& s) const;
        bool operator < (const char* s) const;
        bool operator >= (const YKString& s) const;
        bool operator >= (const char* s) const;
        bool operator <= (const YKString& s) const;
        bool operator <= (const char* s) const;
        
        YKString operator + (const YKString& s) const;
        YKString operator + (const char* s) const;
        YKString& operator += (const YKString& s);
        YKString& operator += (const char* s);
        
        YKString operator - (const YKString& s) const;
        YKString operator - (const char* s) const;
        YKString& operator -= (const YKString& s);
        YKString& operator -= (const char* s);
        
        YKString& operator = (const YKString& s);
        YKString& operator = (const char* s);
        YKString& operator = (char c);
        
        char& operator [] (int i);
        char operator [] (int i) const;
        
        bool startWith(const char* s) const;
        bool startWith(const YKString& s) const;
        bool endof(const char* s) const;
        bool endof(const YKString& s) const;
        
        YKString& insert(int i, const char* s);
        YKString& insert(int i, const YKString& s);
        
        YKString& trim();
        
        int indexOf(const char* s) const;
        int indexOf(const YKString& s) const;
        
        YKString& remove(int i, int len);
        YKString& remove(const char* s);
        YKString& remove(const YKString& s);
        
        YKString& replace(const char* t, const char* s);
        YKString& replace(const YKString& t, const char* s);
        YKString& replace(const char* t, const YKString& s);
        YKString& replace(const YKString& t, const YKString& s);
        
        YKString sub(int i, int len) const;
        
        ~YKString();
    };
}

#endif /* YKString_hpp */
