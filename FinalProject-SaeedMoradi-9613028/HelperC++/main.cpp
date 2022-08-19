#include "helper.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "helper.h"

using namespace std;
int main(int argc , char* argv[])
{
    map <string , string> :: iterator iter;
    helper object;
    string command;
    string address;
    command = string(argv[1]);
    address = string(argv[2]);
    if(command == "create-by-template")
    {
        object.CreateByTemplate(address);
    }
    if(command == "format")
    {
        object.setFile(address);
		object.funcL_funcMax();
		object.replaceTabs();
		object.changeComment();
		object.save();
    }
	else if (command == "replace")
	{
		object.setFile(address);
		map <string , string> :: iterator iter;
		map <string , string > replaceList;
		for (int i = 0 ; i < argc ; i++)
		{
			string s = argv[i];
			if (s == "-r")
			{
				string s = argv[i + 1], value = argv[i + 2];
				s.erase(s.length() - 1);
				replaceList[s] = value;
			}
		}
		for (iter = replaceList.begin(); iter != replaceList.end(); iter++)
			object.Replace(iter->first, iter->second);
		object.save();
	}
	return 0;
}

