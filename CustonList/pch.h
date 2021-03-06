#pragma once
#include <iostream>
#include <functional>

// 데이터형 정의
using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

using boolean = bool;

using namespace std;

//Node
enum class DumyNode
{
	First = 0,
	Last = 1,

	DumyNode_Max = 2
};