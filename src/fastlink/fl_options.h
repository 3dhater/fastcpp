#ifndef __FL_OPTIONS__
#define __FL_OPTIONS__

#include <string>
#include <vector>

enum class flOptionsTarget
{
	unknown,
	windows32,
	windows64,
};

enum class flOptionsType
{
	unknown,
	executable,
};

struct flOptions
{
	flOptionsTarget m_target = flOptionsTarget::unknown;
	flOptionsType   m_type   = flOptionsType::unknown;
	std::string  m_name;
	std::string  m_extension;
	std::string  m_dir;
	std::vector<std::string>  m_files;
};

extern int g_fl_version;

void fl_read_options(int argc, char * argv[], flOptions* options);

#endif