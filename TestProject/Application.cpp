#include <iostream>
#include "Test.h"

namespace Coldlight
{
	__declspec(dllimport) void Print();
}

int main()
{
	Coldlight::Print();
	return 0;
}
