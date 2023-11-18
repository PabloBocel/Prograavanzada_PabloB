#pragma once

#ifndef ADDDATA_H
#define ADDDATA_H

#include "cmake-build-debug/Readtxt.h"

class AddData {
public:
    AddData(Readtxt& reader);


    void addDataFromFile(const std::string& filename);

private:
    Readtxt& reader_;
};

#endif