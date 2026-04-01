#pragma once
#include <iostream>
#include <string>
#include "Crane.h"
#include "Container.h"

class Yardblock
{
private:
    std::string m_id;
    Crane m_assignedCrane;
    int m_rows;
    int m_columns;
    Enums::YardBlockType m_yardBlockType;
public:
    Yardblock() : m_id(""), m_assignedCrane(), m_rows(0), m_columns(0), m_yardBlockType(Enums::YardBlockType::GENERAL){}
    Yardblock(std::string id, Crane assignedCrane, int rows, int columns, Enums::YardBlockType blockType)
        : m_id(id), m_assignedCrane(assignedCrane), m_rows(rows), m_columns(columns), m_yardBlockType(blockType) {}
    std::string getId() const;
    void setId(const std::string& yardBlockId);
    Crane getAssignedCrane() const;
    void setAssignedCrane(const Crane& crane);
    int getRows() const;
    void setRows(int rows);
    int getColumns() const;
    void setColumns(int columns);
    Enums::YardBlockType getStatus() const;
    void setStatus(Enums::YardBlockType blockType);
};
