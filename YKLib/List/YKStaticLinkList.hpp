//
//  YKStaticLinkList.hpp
//  YKLib
//
//  Copyright © 2017年 nethanhan. All rights reserved.
//

#ifndef YKStaticLinkList_hpp
#define YKStaticLinkList_hpp

#include "YKLinkList.hpp"

namespace YKLib
{
    template <typename T, int N>
    class YKStaticLinkList : public YKLinkList<T>
    {
    protected:
        typedef typename YKLinkList<T>::Node Node;
        
        struct SNode: public Node
        {
            void* operator new (unsigned long size, void * loc)
            {
                (void)size;
                return loc;
            }
        };
        
        unsigned char m_space[sizeof(SNode) * N];
        int m_used[N];
        
        Node* create()
        {
            SNode* ret = nullptr;
            
            for (int i=0; i<N; i++)
            {
                if (!m_used[i])
                {
                    ret = reinterpret_cast<SNode*>(m_space)+i;
                    ret = new(ret)SNode();
                    m_used[i] = 1;
                    break;
                }
            }
            
            return ret;
        }
        
        void destroy(Node* pn)
        {
            SNode* space = reinterpret_cast<SNode*>(m_space);
            SNode* psn = dynamic_cast<SNode*>(pn);
            
            for (int i=0; i<N; i++)
            {
                if (pn == (space + i))
                {
                    m_used[i] = 0;
                    psn->~SNode();
                    break;
                }
            }
        }
        
    public:
        
        YKStaticLinkList()
        {
            for (int i=0; i<N; i++)
            {
                m_used[i] = 0;
            }
        }
        
        int capacity()
        {
            return N;
        }
    };
}

#endif /* YKStaticLinkList_hpp */
