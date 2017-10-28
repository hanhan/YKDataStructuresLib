//
//  YKException.cpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#include "YKException.hpp"
#include <cstring>
#include <cstdlib>
#include <stdio.h>

using namespace std;

namespace YKLib
{
    void YKException::init(const char* message, const char* file, int line)
    {
        
        if (message != nullptr)
        {
            m_message = strdup(message);
        }else
        {
            m_message = nullptr;
        }
        
        if(file != nullptr)
        {
            char sl[16] ={0};
            
            sprintf(sl, "%d", line);
            
            m_location = static_cast<char *>(malloc(strlen(file) + strlen(sl) + 2));
            
            if (m_location != nullptr)
            {
                m_location = strcpy(m_location, file);
                m_location = strcat(m_location, ":");
                m_location = strcat(m_location, sl);
            }
        }else
        {
            m_location = nullptr;
        }
    }
    
    YKException::YKException(const char* message)
    {
        init(message, nullptr, 0);
    }
    
    YKException::YKException(const char* file, int line)
    {
        init(nullptr, file, line);
    }
    
    YKException::YKException(const char* message, const char* file, int line)
    {
        init(message, file, line);
    }
    
    YKException::YKException(const YKException& e)
    {
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }
    YKException& YKException::operator = (const YKException& e)
    {
        if(this != &e)
        {
            free(m_message);
            free(m_location);
            
            m_message = strdup(e.m_message);
            m_location = strdup(e.m_location);
        }
        
        return *this;
    }
    
    const char* YKException::message() const
    {
        return m_message;
    }
    
    const char* YKException::location() const
    {
        return m_location;
    }
    
    YKException::~YKException()
    {
        free(m_location);
        free(m_message);
    }
    
}
