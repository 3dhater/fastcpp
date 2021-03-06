#ifndef __FCPP_STRUTILS__
#define __FCPP_STRUTILS__

#include <string>
inline void fcpp_string_flip_slash(std::string& str)
{
	auto data = str.data();
	for(size_t i = 0, sz = str.size(); i < sz; ++i)
	{
		if(*data == '\\')
		{
			str[i] = '/';
		}
		data++;
	}
}

#endif