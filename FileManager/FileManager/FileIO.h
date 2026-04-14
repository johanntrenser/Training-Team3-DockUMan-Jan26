#pragma once
#include<memory>
#include<vector>
#include<fstream>
#include<string>
#include<stdexcept>

#ifdef FILEMANAGER_EXPORTS
#define FILEMANAGER_API __declspec(dllexport)
#else
#define FILEMANAGER_API __declspec(dllimport)
#endif

class FILEMANAGER_API FileIO
{
public:
	static std::vector<std::string> readAllLines(const std::string& path);
	static void writeAllLines(const std::string& path, const std::vector<std::string>& lines);
};