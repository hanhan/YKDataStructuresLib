//
//  YKScan.cpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#include "YKLinkStack.hpp"

using namespace YKLib;

bool is_left(char c)
{
    return (c == '(') || (c == '{') || (c == '[') || (c == '<');
}

bool is_right(char c)
{
    return (c == ')') || (c == '}') || (c == ']') || (c == '>');
}

bool is_quot(char c)
{
    return (c == '\'') || (c == '\"');
}

bool is_match(char l, char r)
{
    return ((l == '(') || (r == ')')) ||
    ((l == '{') || (r == '}')) ||
    ((l == '[') || (r == ']')) ||
    ((l == '<') || (r == '>')) ||
    ((l == '\'') || (r == '\'')) ||
    ((l == '\"') || (r == '\"'));
}

bool scan(const char* code)
{
    YKLinkStack<char> stack;
    int i=0;
    bool ret = true;
    
    code = (code == nullptr) ? "" : code;
    
    while (ret && (code[i] != '\0'))
    {
        if (is_left((code[i])))
        {
            stack.push(code[i]);
            
        }else if (is_right(code[i]))
        {
            if ((stack.size() > 0) && is_match(stack.top(), code[i]))
            {
                stack.pop();
            }else
            {
                ret = false;
            }
        }else if(is_quot(code[i]))
        {
            if ((stack.size() == 0) || !is_match(stack.top(), code[i]))
            {
                stack.push(code[i]);
            }else if (is_match(stack.top(), code[i]))
            {
                stack.pop();
            }
        }
        
        i++;
    }
    
    return ret && (stack.size() == 0);
}
