#ifndef __FL_WRITE__
#define __FL_WRITE__

struct fl_dos_header
{  // DOS .EXE header
	unsigned short e_magic = 0;         // Magic number
	unsigned short e_cblp = 0;          // Bytes on last page of file
	unsigned short e_cp = 0;            // Pages in file
	unsigned short e_crlc = 0;          // Relocations
	unsigned short e_cparhdr = 0;       // Size of header in paragraphs
	unsigned short e_minalloc = 0;      // Minimum extra paragraphs needed
	unsigned short e_maxalloc = 0;      // Maximum extra paragraphs needed
	unsigned short e_ss = 0;            // Initial (relative) SS value
	unsigned short e_sp = 0;            // Initial SP value
	unsigned short e_csum = 0;          // Checksum
	unsigned short e_ip = 0;            // Initial IP value
	unsigned short e_cs = 0;            // Initial (relative) CS value
	unsigned short e_lfarlc = 0;        // File address of relocation table
	unsigned short e_ovno = 0;          // Overlay number
	unsigned short e_res[4] = {0,0,0,0};        // Reserved words
	unsigned short e_oemid = 0;         // OEM identifier (for e_oeminfo)
	unsigned short e_oeminfo = 0;       // OEM information; e_oemid specific
	unsigned short e_res2[10] = {0,0,0,0,0,0,0,0,0,0};       // Reserved words
	unsigned long e_lfanew = 0;					// File address of new exe header
};

struct fl_windows_image_file_header
{
    unsigned short  Machine = 0;
    unsigned short  NumberOfSections = 0;
    unsigned long   TimeDateStamp = 0;
    unsigned long   PointerToSymbolTable = 0;
    unsigned long   NumberOfSymbols = 0;
    unsigned short  SizeOfOptionalHeader = 0;
    unsigned short  Characteristics = 0;
};

void fl_write_windows_file(flOptions*, const char* outputFile);

#endif