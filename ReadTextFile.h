#pragma once
#ifndef READFILE_H
#define READFILE_H
#include <string>
#include "TreeMap.h"

void ReadWords(const std::string& fileName, TreeMap<char, BinaryTree<std::string>>& letterTreeMap);

#endif 