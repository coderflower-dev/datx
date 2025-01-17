#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

struct IndexOrder {
    /*
        Example:
        Username, Password, Email
        John, 12344, john@email.com
        Then it will read a vector and put it in that order
        Username: John
        Password: 12344
        Email: john@email.com
    */
    std::vector<std::string> order;
};

/*
    Each vector in the vector is each own "category", like in index thing
    vector 1: username
    vector 2: password
    etc.
*/

struct IndexedData {
    /*
        IndexedData is the data that has been split by category as defined in the IndexOrder
    */
    std::map<std::string, std::vector<std::string>> data;
};

// Inputs an order and an Indexed data and will generate elements for the map containing the names of the orders
void genIndexDataMap(IndexedData& data, const IndexOrder& order) {
    for(const std::string& orderName : order.order) {
        data.data[orderName] = {};
    }
}

IndexedData parseVectorByIndex(std::vector<std::string> dataVec, IndexOrder order) {
    IndexedData data;

    int vectorSize = order.order.size(); // How many categories there are
    int orderNum = 0;

    genIndexDataMap(data, order); // "resizes" the map by order num

    for(std::string el : dataVec) {
        std::string orderName = order.order[orderNum];
        data.data[orderName].push_back(el);
        orderNum = (orderNum + 1) % vectorSize;
    }
    return data;
}

void printIndexedData(IndexedData data) {
    for(const auto& pair : data.data) {
        std::cout << pair.first << ":\n";
        for(std::string i : pair.second) {
            std::cout << " - " << i << "\n";
        }
    }
}

