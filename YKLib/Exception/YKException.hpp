//
//  YKException.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKException_hpp
#define YKException_hpp

#include "YKObject.hpp"

/*
 ArithmeticException        计算异常
 IndexOutOfBoundsException  越界异常
 NoEnoughMemoryException    内存不足异常
 InvalidParameterException  参数错误异常
 NullPointerException       空指针异常
 */

namespace YKLib
{

    #define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))
    
    class YKException : public YKObject
    {
    protected:
        char* m_message;
        char* m_location;
        
        void init(const char* message, const char* file, int line);
        
    public:
        
        YKException(const char* message);
        YKException(const char* file, int line);
        YKException(const char* message, const char* file, int line);
        YKException(const YKException& e);
        YKException& operator = (const YKException& e);
        
        virtual const char* message() const;
        virtual const char* location() const;
        
        virtual ~YKException();
    };
    
    class YKArithmeticException:public YKException
    {
    public:
        
        YKArithmeticException() : YKException(nullptr){}
        YKArithmeticException(const char* message): YKException(message){}
        YKArithmeticException(const char* file, int line): YKException(file, line){}
        YKArithmeticException(const char* message, const char* file, int line): YKException(message, file, line){}
        YKArithmeticException(const YKArithmeticException& e): YKException(e){}
        YKArithmeticException& operator = (const YKArithmeticException& e)
        {
            YKException::operator=(e);
            return *this;
        }
    };
    
    class YKIndexOutOfBoundsException:public YKException
    {
    public:
        
        YKIndexOutOfBoundsException(): YKException(nullptr){}
        YKIndexOutOfBoundsException(const char* message): YKException(message){}
        YKIndexOutOfBoundsException(const char* file, int line): YKException(file, line){}
        YKIndexOutOfBoundsException(const char* message, char* file, int line): YKException(message, file, line){}
        YKIndexOutOfBoundsException(const YKIndexOutOfBoundsException& e): YKException(e){}
        YKIndexOutOfBoundsException& operator = (const YKIndexOutOfBoundsException& e)
        {
            YKException::operator=(e);
            
            return *this;
        }
    };
    
    
    class YKNoEnoughMemoryException:public YKException
    {
    public:
        
        YKNoEnoughMemoryException(): YKException(nullptr){}
        YKNoEnoughMemoryException(const char* message): YKException(message){}
        YKNoEnoughMemoryException(const char* file, int line): YKException(file, line){}
        YKNoEnoughMemoryException(const char* message, char* file, int line): YKException(message, file, line){}
        YKNoEnoughMemoryException(const YKNoEnoughMemoryException& e): YKException(e){}
        YKNoEnoughMemoryException& operator = (const YKNoEnoughMemoryException& e)
        {
            YKException::operator=(e);
            
            return *this;
        }
    };
    
    
    class YKInvalidParameterException:public YKException
    {
    public:
        
        YKInvalidParameterException(): YKException(nullptr){}
        YKInvalidParameterException(const char* message): YKException(message){}
        YKInvalidParameterException(const char* file, int line): YKException(file, line){}
        YKInvalidParameterException(const char* message, char* file, int line): YKException(message, file, line){}
        YKInvalidParameterException(const YKInvalidParameterException& e): YKException(e){}
        YKInvalidParameterException& operator = (const YKInvalidParameterException& e)
        {
            YKException::operator=(e);
            
            return *this;
        }
    };
    
    
    class YKNullPointerException:public YKException
    {
    public:
        
        YKNullPointerException(): YKException(nullptr){}
        YKNullPointerException(const char* message): YKException(message){}
        YKNullPointerException(const char* file, int line): YKException(file, line){}
        YKNullPointerException(const char* message, char* file, int line): YKException(message, file, line){}
        YKNullPointerException(const YKNullPointerException& e): YKException(e){}
        YKNullPointerException& operator = (const YKNullPointerException& e)
        {
            YKException::operator=(e);
            
            return *this;
        }
    };
    
    class YKInvalidOperationException:public YKException
    {
    public:
        
        YKInvalidOperationException(): YKException(nullptr){}
        YKInvalidOperationException(const char* message): YKException(message){}
        YKInvalidOperationException(const char* file, int line): YKException(file, line){}
        YKInvalidOperationException(const char* message, char* file, int line): YKException(message, file, line){}
        YKInvalidOperationException(const YKInvalidOperationException& e): YKException(e){}
        YKInvalidOperationException& operator = (const YKInvalidOperationException& e)
        {
            YKException::operator=(e);
            
            return *this;
        }
    };
    
}


#endif /* YKException_hpp */




