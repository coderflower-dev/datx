// Manages strings: reading files, parsing text, etc.
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Reads a file into a string
std::string readFileStr(std::string filePath, std::string lineDiv = "\n") {
    std::ifstream file(filePath);
    if(!file) std::cout << "File not found!\n";
    std::string text;
    std::string line;
    while(getline(file,line)) {
        text += line + lineDiv;
    }
    return text;
}

// Splits a string by a delimeter
std::vector<std::string> splitStr(std::string text, char div) {
    std::vector<std::string> parsed;
    std::string acc;
    for(char c : text) {
        if(c == div) {
            parsed.push_back(acc);
            acc = "";
        } else {
            acc += c;
        }
    }
    parsed.push_back(acc);
    return parsed;
}

// Prints out a vector
void printVector(std::vector<std::string> text, char lineDiv = '\n') {
    for(std::string c : text) {
        std::cout << c << lineDiv;
    }
}

std::vector<std::string> flattenVector(std::vector<std::string> data) {
    // Input = ["john,1234,testmail", "bob,5678,anothermail"]
    // Output = ["john", "1234", "testmail", "bob", "5678", "anothermail"]
    std::vector<std::string> output;
    for(std::string datastr : data) {
        std::vector<std::string> split = splitStr(datastr, ',');
        for(std::string splitString : split) {
            output.push_back(splitString);
        }
    }
    return output;
}