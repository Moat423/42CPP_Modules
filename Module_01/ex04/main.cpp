#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

void mySed(std::ifstream &file, std::ofstream &outfile, std::string oldstr, std::string newstr);

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./mySed <filename> <toReplace> <replacement>" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cout << "string to find should not be empty" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::ifstream file(argv[1], std::ios_base::in);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::ofstream outputfile(filename.append(".replace").c_str());
	if (!outputfile.is_open())
	{
		std::cout << "Error: could not create output file" << std::endl;
		return (1);
	}
	mySed(file, outputfile, argv[2], argv[3]);
	return (0);
}

void mySed(std::ifstream &file, std::ofstream &outfile, std::string oldstr, std::string newstr)
{
	std::string		filecontent;
	std::size_t		pos;
	std::stringstream	buffer;

	buffer << file.rdbuf();
	filecontent = buffer.str();
	while ((pos = filecontent.find(oldstr)) != std::string::npos)
	{
		filecontent.erase(pos, oldstr.length());
		filecontent.insert(pos, newstr);
	}
	file.close();
	outfile << filecontent;
	outfile.close();
}
