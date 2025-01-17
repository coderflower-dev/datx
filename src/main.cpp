#include "strmng.h"
#include "index.h"
#include "fileheader.h"

#define VERSION_MAJOR 1
#define VERSION_MINOR 0

void versionData();

int main(int argc, char *argv[]) {
    // datx example.datx
    if(argc == 1) {std::cerr << "DATX: No input parameters!\n"; return 1;}
    if(std::string(argv[1]) == "!version") {versionData(); return 0;}

    std::string strFile = readFileStr(std::string(argv[1])); // Read the file
    std::vector<std::string> splitStrFile = splitStr(strFile, '\n'); // Splits by line

    IndexOrder order = parseFileHeader(splitStrFile); // Gets the header of the file
    splitStrFile.erase(splitStrFile.begin()); // Removes the header from the file
    splitStrFile = flattenVector(splitStrFile);
    //printVector(order.order);

    
    IndexedData data = parseVectorByIndex(splitStrFile, order); // Parses the vector by index
    printIndexedData(data);
    return 0;
}

void versionData() {
    std::cout << "DATX utility Version " << VERSION_MAJOR << "." << VERSION_MINOR << '\n';
    std::cout << "Copyright 2025 Timur Gabdrakhmanov. See 'license.txt' for license\n";
}