#include "fl_options.h"
#include "fl_write.h"

#include "common/fcpp_string_utils.h"

#include <filesystem>

int g_fl_version = 1;

int main(int argc, char * argv[])
{
	flOptions options;
	fl_read_options(argc, argv, &options);

	switch(options.m_target)
	{
	case flOptionsTarget::windows64:
	case flOptionsTarget::windows32:
		break;
	case flOptionsTarget::unknown:
	default:
		fprintf(stderr, "Target is not set. Use -target your_target_here. Use -targets to print all available targets\n");
		return 1;
	}

	switch(options.m_type)
	{
	case flOptionsType::executable:
		break;
	case flOptionsType::unknown:
	default:
		fprintf(stderr, "Type is not set. Use -type your_type_here. Use -types to print all available types\n");
		return 1;
	}

	if(!options.m_name.size())
	{
		fprintf(stderr, "Output is not set. Use -name output_file_name\n");
		return 1;
	}

	std::string output_dir  = options.m_dir;
	if( output_dir.size() )
	{
		fcpp_string_flip_slash(output_dir);
		if( output_dir[output_dir.size()-1] != '/' )
			output_dir += '/';
	
	}
	std::string output_name = output_dir;
	if(options.m_name.size())
	{
		output_name += options.m_name;
	}
	if(options.m_extension.size())
	{
		output_name += '.';
		output_name += options.m_extension;
	}

	if(output_name.size())
	{
		if(output_dir.size())
		{
			if(!std::filesystem::exists(output_dir))
			{
				std::filesystem::create_directory(output_dir);
			}
		}

		switch(options.m_target)
		{
		case flOptionsTarget::windows32:
			fl_write_windows_file(&options, output_name.data());
			break;
		default:
			break;
		}
	}


	return 0;
}