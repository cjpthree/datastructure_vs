#pragma once

#include<math.h> // floor(),ceil(),abs()

/* Ϊ����vs2010û�ж����͵����غ�����error */


inline long double __CRTDECL pow(_In_ int _X, _In_ int _Y)
    {return (_Pow_int(_X, _Y)); }

inline long double __CRTDECL log10(_In_ int _X)
    {return (log10l(_X)); }

inline long double __CRTDECL fabs(_In_ int _X)
    {return (fabsl(_X)); }

inline long double __CRTDECL log(_In_ int _X)
    {return (logl(_X)); }