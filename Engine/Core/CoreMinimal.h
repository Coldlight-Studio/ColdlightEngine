#include <Windows.h>

namespace Coldlight
{

#define MIN_DELTATIME 1.0f / 30.0f

typedef __int64 int64;

#define FE_LOG(Format, ...) \
	printf(Format##"\n", ##__VA_ARGS__)

}
