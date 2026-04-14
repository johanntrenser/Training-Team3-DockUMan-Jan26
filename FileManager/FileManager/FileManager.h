#pragma once
#include <stdexcept>
#include<map>
#include "FileIO.h"

template <typename T> using objects = std::map<std::string, T*>;

template <typename T>
class FileManager
{
private:
    std::string m_filePath;
public:
    FileManager() : m_filePath("") {}
    FileManager(const std::string& filePath) : m_filePath(filePath) {}
    objects<T> load();
    void save(const objects<T>&);
};

template <typename T>
objects<T> FileManager<T>::load()
{
    objects<T> records;
    auto lines = FileIO::readAllLines(m_filePath);
    bool isHeader = true;
    for (const auto& record : lines)
    {
        if (isHeader)
        {
            isHeader = false;
            continue;
        }
        auto object = T::deserialize(record);
        if (!object)
        {
            throw std::runtime_error("Failed to deserialize record");
        }
        records[object->getId()] = object;
    }
    return records;
}

template <typename T>
void FileManager<T>::save(const objects<T>& records)
{
    std::vector<std::string> lines;
    lines.push_back(T::getHeaders());
    for (const auto& recordPair : records)
    {
        lines.push_back(recordPair.second->serialize());
    }
    FileIO::writeAllLines(m_filePath, lines);
}