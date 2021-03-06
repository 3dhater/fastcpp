#include "fl_options.h"

void fl_read_options(int argc, char * argv[], flOptions* options)
{
	for(int i = 0; i < argc; ++i)
	{
		if(strcmp(argv[i], "-version") == 0)
		{
			fprintf(stdout, "fastlink version = %i\n", g_fl_version);
		}
		if(strcmp(argv[i], "-targets") == 0)
		{
			fprintf(stdout, "Available targets:\n");
			fprintf(stdout, "\t windows32 - output file is for Windows 32 bit\n");
		}
		if(strcmp(argv[i], "-types") == 0)
		{
			fprintf(stdout, "Available types:\n");
			fprintf(stdout, "\t executable - executable file\n");
		}
		if(strcmp(argv[i], "-target") == 0)
		{
			++i;
			if(i<argc)
			{
				if(strcmp(argv[i], "windows32") == 0)
				{
					options->m_target = flOptionsTarget::windows32;
				}
			//	if(strcmp(argv[i], "windows64") == 0)
			//	{
			//		options->m_target = flOptionsTarget::windows64;
			//	}
			}
		}
		if(strcmp(argv[i], "-type") == 0)
		{
			++i;
			if(i<argc)
			{
				if(strcmp(argv[i], "executable") == 0)
				{
					options->m_type = flOptionsType::executable;
				}
			}
		}
		if(strcmp(argv[i], "-name") == 0)
		{
			++i;
			if(i<argc)
				options->m_name = argv[i];
		}
		if(strcmp(argv[i], "-extension") == 0)
		{
			++i;
			if(i<argc)
				options->m_extension = argv[i];
		}
		if(strcmp(argv[i], "-dir") == 0)
		{
			++i;
			if(i<argc)
				options->m_dir = argv[i];
		}
	}
}