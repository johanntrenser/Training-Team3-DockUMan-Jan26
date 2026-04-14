#include "pch.h"
#include "FileIO.h"

std::vector<std::string> FileIO::readAllLines(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::ofstream newFile(path);
        newFile.close();
        file.open(path);
    }    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        lines.push_back(line);
    return lines;
}

void FileIO::writeAllLines(const std::string& path,
    const std::vector<std::string>& lines)
{
    std::ofstream file(path, std::ios::trunc);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file " + path);
    for (const auto& line : lines)
        file << line << '\n';
}