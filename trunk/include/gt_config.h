#ifndef GT_CONFIG_INCLUDED
#define GT_CONFIG_INCLUDED

#include <string>
#include <vector>

namespace  GtGante {
	#ifdef _WIN32
		typedef unsigned __int64 Gt_uint64_t;
	#else
		typedef unsigned long long Gt_uint64_t;
	#endif

	#define Gt_String std::string

    typedef unsigned Gt_uint32_t;
}

#endif