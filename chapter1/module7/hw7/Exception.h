#pragma once
#include <iostream>
#include <exception>

class BadLength : public std::exception 
{
public: 
    virtual const char* what() const noexcept override
    {
        return "Error: Incorrect Array length! ";
    }
};

class BadRange : public std::exception 
{
public: 
    virtual const char* what() const noexcept override
    {
        return "Error: Incorrect Array index! ";
    }
};