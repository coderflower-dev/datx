#pragma once
#include "strmng.h"
#include "index.h"
#include "header.h"

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 1

void displayVersionData();

int handleArguments(int argc, char *argv[]) {
    if(argc == 1) { std::cerr << "DATX: Failure: No input parameters!\n"; return 1; }
    if(std::string(argv[1]) == "!version") { displayVersionData(); return 0; }

    std::string strFile = readFileStr(std::string(argv[1])); // Read the file
    std::vector<std::string> splitStrFile = splitStr(strFile, '\n'); // Splits by line

    IndexOrder order = parseFileHeader(splitStrFile); // Gets the header of the file
    splitStrFile.erase(splitStrFile.begin()); // Removes the header from the file
    splitStrFile = flattenVector(splitStrFile);
    
    IndexedData data = parseVectorByIndex(splitStrFile, order); // Parses the vector by index
    printIndexedData(data);
    return 0;
}

void displayVersionData() {
    std::cout << "DATX utility Version " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << "\n";
    std::cout << "Copyright 2025 Timur Gabdrakhmanov. See 'license.txt' for license\n";
}