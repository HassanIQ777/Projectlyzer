#include "libutils/src/file.hpp"
#include "libutils/src/funcs.hpp"
#include "libutils/src/table.hpp"

#include <iomanip>

using funcs::print;

std::string getSuffix(float size)
{
	std::string suffix = "B";

	std::string suffixes[] = {"B", "KB", "MB", "GB"};
	int i = 0;
	while (i < 4)
	{
		if (size >= 1024)
		{
			size /= 1024;
			i++;
			continue;
		}
		break;
	}

	return funcs::str(size) + suffixes[i];
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: \n"
				  << argv[1] << " <DIR>" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string path = argv[1];
	if (!File::m_isdirectory(path))
	{
		std::cerr << "Invalid path to a directory." << std::endl;
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		funcs::clearTerminal();
		std::cout.flush();
		std::vector<std::string> files = File::m_listfiles(path);
		for (size_t i = 0; i < files.size(); i++)
		{
			if (!File::m_isfile(files[i]))
			{
				files.erase(files.begin() + static_cast<long>(i)); // remove directories
			}
		}

		files = File::m_sortChronological(files);

		Table table;
		table.m_setHeader("Filename", "Lines", "Size", "Last Modification");

		int cum = 0;
		size_t total_size = 0;
		for (const auto &file : files)
		{
			std::string name = File::m_getFileName(file);
			std::string lines = funcs::str(File::m_numlines(file) + 1);
			cum += File::m_numlines(file) + 1;
			size_t fsize = File::m_getfilesize(file);
			total_size += fsize;
			std::string size = getSuffix(static_cast<float>(fsize));
			std::string last_mod = File::m_lastmodification_str(file);

			table.m_addRow(name, lines, size, last_mod);
		}

		std::string time = funcs::currentTime().substr(11);
		funcs::printLeftMiddleRight("", "Project Lines", time);
		print("\n\n", path, "\n\n");
		print(table);
		print("\nTotal lines: ", cum, "\n");
		print("Total size: ", getSuffix(static_cast<float>(total_size)), "\n");
		funcs::msleep(1000);
	}
}
