#pragma once
#include "index.h"
#include "strmng.h"

// Parses the file header into the index order
IndexOrder parseFileHeader(std::vector<std::string> fileSplit) {
    IndexOrder order;
    std::string headerStr = fileSplit[0]; // First line
    std::vector<std::string> headerVec = splitStr(headerStr,','); // Divides the header
    for(std::string cat : headerVec) { // Adds each category to the order
        order.order.push_back(cat);
    }
    return order;
}