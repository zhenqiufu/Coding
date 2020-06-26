/************************************************************************
    > File Name: q1.cpp
    > Author: FU Zhenqiu
    > Mail: fuzhenqiu0810@gmail.com
    > Created Time: Tue Jun 23 15:10:33 2020
 ************************************************************************/

//赋值运算符

#include<iostream>
class CMystring
{
public:
	CMystring(char* pData=nullptr);
	CMystring(const CMystring &str);
	~CMystring(void);
pricate:
	char* m_pDara;
};
