//Starting Of File Tool Header File : 
#pragma once

#include <iostream> //For Terminal Input-Output Streaming
#include <fstream> //For File Streaming
#include <filesystem> //For File And Folder Management
#include <string> //For Easy Use Of String
#include <vector> //For Easy Use Of Dynamic Array

using namespace std; //Use Standart Namespace
namespace fs = filesystem; //File Management Namespace


//Get Name Of File On Given Directory
string getName(string target)
{
    string ans;
    ifstream file(target);
    if(file.is_open())
    {
        size_t size = target.size();
        char symbol;
        size_t lastPos = 0;
        for(size_t i = 0; i < size; i++)
        {
            symbol = target[i];
            if(symbol == '/' || symbol == '\\')
            {
                lastPos = i;
            }
        }    
        for(size_t i = lastPos; i < size; i++)
        {
            symbol = target[i];
            if(symbol != '.')
            {
                ans += symbol;
            }   
            else
            {
                break;
            }
        }
    }
    else
    {
        ans = "ERROR";
    }
    return ans;
}