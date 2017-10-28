//
//  YKString.cpp
//  YKLib
//
//  Created by nethanhan on 2017/10/22.
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#include "YKString.hpp"
#include <cstring>
#include <cstdlib>
#include "YKException.hpp"

namespace YKLib
{
    int* YKString::make_pmt(const char* p)
    {
        int len = static_cast<int>(strlen(p));
        int* ret = static_cast<int*>(malloc(sizeof(int)* len));
        
        if (ret != nullptr)
        {
            int ll = 0;
            
            ret[0] = 0;
            
            for (int i=1; i<len; i++)
            {
                while ((ll > 0) && (p[ll] != p[i]))
                {
                    ll = ret[ll-1];
                }
                
                if (p[ll] == p[i])
                {
                    ll++;
                }
                
                ret[i] = ll;
            }
        }
        
        return ret;
    }
    
    int YKString::kmp(const char* s, const char* p)
    {
        int ret = -1;
        
        int sl = static_cast<int>(strlen(s));
        int pl = static_cast<int>(strlen(p));
        int* pmt = make_pmt(p);
        
        if ((pmt != nullptr) && (0 < pl) && (pl <= sl))
        {
            for (int i=0, j=0; i<sl; i++)
            {
                while ((j > 0) && (s[i] != p[j]))
                {
                    j = pmt[j-1];
                }
                if (s[i] == p[j])
                {
                    j++;
                }
                
                if (j == pl)
                {
                    ret = i + 1 - pl;
                    break;
                }
            }
        }
        
        free(pmt);
        
        return ret;
    }
    
    void YKString::init(const char* s)
    {
        m_str = strdup(s);
        
        if (m_str)
        {
            m_length = static_cast<int>(strlen(m_str));
        }else
        {
            THROW_EXCEPTION(YKNoEnoughMemoryException, "No memory to create string object ...");
        }
    }
    
    bool YKString::equal(const char* l, const char* r, int len) const
    {
        bool ret = true;
        
        for (int i=0; i<len && ret; i++)
        {
            ret = ret && (l[i] == r[i]);
        }
        
        return ret;
    }
    
    YKString::YKString()
    {
        init("");
    }
    
    YKString::YKString(char c)
    {
        char s[] = {c, '\0'};
        
        init(s);
    }
    
    YKString::YKString(const char* s)
    {
        init(s ? s : "");
    }
    
    YKString::YKString(const YKString& s)
    {
        init(s.m_str);
    }
    
    int YKString::length() const
    {
        return m_length;
    }
    
    const char* YKString::str() const
    {
        return m_str;
    }
    
    bool YKString::operator == (const YKString& s) const
    {
        return (strcmp(m_str, s.m_str) == 0);
    }
    
    bool YKString::operator == (const char* s) const
    {
        return (strcmp(m_str, (s ? s : "")) == 0);
    }
    
    bool YKString::operator != (const YKString& s) const
    {
        return !(*this == s);
    }
    
    bool YKString::operator != (const char* s) const
    {
        return !(*this == s);
    }
    bool YKString::operator > (const YKString& s) const
    {
        return (strcmp(m_str, s.m_str) > 0);
    }
    bool YKString::operator > (const char* s) const
    {
        return (strcmp(m_str, (s ? s : "")) > 0);
    }
    bool YKString::operator < (const YKString& s) const
    {
        return (strcmp(m_str, s.m_str) < 0);
    }
    bool YKString::operator < (const char* s) const
    {
        return (strcmp(m_str, (s ? s : "")) < 0);
    }
    bool YKString::operator >= (const YKString& s) const
    {
        return (strcmp(m_str, s.m_str) >= 0);
    }
    bool YKString::operator >= (const char* s) const
    {
        return (strcmp(m_str, (s ? s : "")) >= 0);
    }
    bool YKString::operator <= (const YKString& s) const
    {
        return (strcmp(m_str, s.m_str) <= 0);
    }
    bool YKString::operator <= (const char* s) const
    {
        return (strcmp(m_str, (s ? s : "")) <= 0);
    }
    
    YKString YKString::operator + (const YKString& s) const
    {
        return (*this + s.m_str);
    }
    YKString YKString::operator + (const char* s) const
    {
        YKString ret;
        
        int len = m_length + static_cast<int>(strlen(s ? s : ""));
        char* str = reinterpret_cast<char*>(malloc(len+1));
        
        if (str)
        {
            strcpy(str, m_str);
            strcat(str, s ? s : "");
            
            free(ret.m_str);
            
            ret.m_str = str;
            ret.m_length = len;
        }else
        {
            THROW_EXCEPTION(YKNoEnoughMemoryException, "No memory to add String value ...");
        }
        
        return ret;
    }
    YKString& YKString::operator += (const YKString& s)
    {
        return (*this = *this + s);
    }
    YKString& YKString::operator += (const char* s)
    {
        return (*this = *this + s);
    }
    
    YKString YKString::operator - (const YKString& s) const
    {
        return YKString(*this).remove(s);
    }
    YKString YKString::operator - (const char* s) const
    {
        return YKString(*this).remove(s);
    }
    
    YKString& YKString::operator -= (const YKString& s)
    {
        return remove(s);
    }
    YKString& YKString::operator -= (const char* s)
    {
        return remove(s);
    }
    
    YKString& YKString::operator = (const YKString& s)
    {
        return (*this = s.m_str);
    }
    YKString& YKString::operator = (const char* s)
    {
        if (m_str != s)
        {
            char* str = strdup(s ? s: "");
            
            if (str)
            {
                free(m_str);
                
                m_str = str;
                m_length = static_cast<int>(strlen(str));
            }else
            {
                THROW_EXCEPTION(YKNoEnoughMemoryException, "No memory to assign new String value ....");
            }
        }
        
        return *this;
    }
    YKString& YKString::operator = (char c)
    {
        char s[] = {c, '\0'};
        return (*this = s);
    }
    
    char& YKString::operator [] (int i)
    {
        if ((0 <= i) && (i < m_length))
        {
            return m_str[i];
        }else
        {
            THROW_EXCEPTION(YKIndexOutOfBoundsException, "Paramenter i is invalid ...");
        }
    }
    
    char YKString::operator [] (int i) const
    {
        return (const_cast<YKString&>(*this))[i];
    }
    
    bool YKString::startWith(const char* s) const
    {
        bool ret = (s != nullptr);
        
        if (ret)
        {
            int len = static_cast<int>(strlen(s));
            ret = (len < m_length) && equal(m_str, s, len);
        }
        
        return ret;
    }
    
    bool YKString::startWith(const YKString& s) const
    {
        return startWith(s.m_str);
    }
    
    bool YKString::endof(const char* s) const
    {
        bool ret = (s != nullptr);
        
        if (ret)
        {
            int len = static_cast<int>(strlen(s)) ;
            char* str = m_str + (m_length-len);
            ret = (len < m_length) && equal(str, s, len);
        }
        
        return ret;
    }
    
    bool YKString::endof(const YKString& s) const
    {
        return endof(s.m_str);
    }
    
    YKString& YKString::insert(int i, const char* s)
    {
        if ((0 <= i) && (i <= m_length))
        {
            if ((s != nullptr) && (s[0] != '\0'))
            {
                int len = static_cast<int>(strlen(s));
                char* str = reinterpret_cast<char*>(malloc(m_length + len + 1));
                
                if (str != nullptr)
                {
                    strncpy(str, m_str, i);
                    strncpy(str+i, s, len);
                    strncpy(str+i+len, m_str+i, m_length);
                    str[m_length + len] = '\0';
                    
                    free(m_str);
                    
                    m_str = str;
                    m_length = m_length + len;
                }else
                {
                    THROW_EXCEPTION(YKNoEnoughMemoryException, "No memory to insert string value ...");
                }
            }
        }else
        {
            THROW_EXCEPTION(YKIndexOutOfBoundsException, "Parameter i is invalid ...");
        }
        
        return *this;
    }
    
    YKString& YKString::insert(int i, const YKString& s)
    {
        return insert(i, s.m_str);
    }
    
    YKString& YKString::trim()
    {
        int b = 0;
        int e = m_length - 1;
        
        while (m_str[b] == ' ') b++;
        while (m_str[e] == ' ') e--;

        if (b == 0)
        {
            m_str[e + 1] = '\0';
            m_length = e + 1;
        }else
        {
            for (int i=0, j=b; j<=e; i++, j++)
            {
                m_str[i] = m_str[j];
            }
            
            m_str[e - b + 1] = '\0';
            m_length = e - b + 1;
        }
        
        return *this;
    }
    
    int YKString::indexOf(const char* s) const
    {
        return kmp(m_str, s ? s : "");
    }
    int YKString::indexOf(const YKString& s) const
    {
        return kmp(m_str, s.m_str);
    }
    
    YKString& YKString::remove(int i, int len)
    {
        if((0 <= i) && (i < m_length))
        {
            int n = i;
            int m = i + len;
            
            while((n < m) && (m < m_length))
            {
                m_str[n++] = m_str[m++];
            }
            
            m_str[n] = '\0';
            m_length = n;
        }
        
        return *this;
    }
    
    YKString& YKString::remove(const char* s)
    {
        return remove(indexOf(s), s?static_cast<int>(strlen(s)):0);
    }

    YKString& YKString::remove(const YKString& s)
    {
        return remove(indexOf(s), s.length());
    }
    
    YKString& YKString::replace(const char* t, const char* s)
    {
        int index = indexOf(t);
        if (index > 0)
        {
            remove(t);
            insert(index, s);
        }
        
        return *this;
    }
    
    YKString& YKString::replace(const YKString& t, const char* s)
    {
        return replace(t.m_str, s);
    }
    
    YKString& YKString::replace(const char* t, const YKString& s)
    {
        return replace(t, s.m_str);
    }
    YKString& YKString::replace(const YKString& t, const YKString& s)
    {
        return replace(t.m_str, s.m_str);
    }
    
    YKString YKString::sub(int i, int len) const
    {
        YKString ret;
        
        if ((0 <= i) && (i < m_length))
        {
            if (len < 0)
            {
                len = 0;
            }
            
            if (len + i > m_length)
            {
                len = m_length - i;
            }
            
            char* str = reinterpret_cast<char*>(malloc(len + 1));
            strncpy(str, m_str+i, len);
            str[len] = '\0';
            ret = str;
            
        }else
        {
            THROW_EXCEPTION(YKIndexOutOfBoundsException, "Parameter i is invalid ... ");
        }
        
        return ret;
    }
    
    YKString::~YKString()
    {
        free(m_str);
    }
}

