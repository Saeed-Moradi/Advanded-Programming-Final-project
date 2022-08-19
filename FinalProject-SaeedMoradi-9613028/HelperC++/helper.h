#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>

using namespace std;

class helper
{
    private:
	vector <int> bracesOpen,bracesClose;
	unsigned int lines, maxFunc;
	string command,address;
    public:
    void setFile(string);
    void funcL_funcMax();
    void changeComment();
    void save();
    void MaxLengthFunction();
    void CreateByTemplate(string address);
    void replaceTabs();
    void Replace(string , string);
};

#endif // HELPER_H_INCLUDED
