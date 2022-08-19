#include "helper.h"

using namespace std;

void helper::Replace(string s1 , string s2)
{
    ofstream outFile;
    outFile.open("helper.h");
    size_t position = command.find(s1 , position);
    while(position != string::npos)
    {
        command.replace(position , s1.length() , s2);
        position = position + s1.length();
    }
    outFile.close();
}
void helper::replaceTabs()
{
    ofstream outFile;
    outFile.open("helper.h");
    size_t position = command.find("        " , position);
    while(position != string::npos)
    {
        command.replace(position , 8 , "\t");
        position = position + 8;
    }
}
void helper::CreateByTemplate(string address)
{
    ofstream fileout;
    fileout.open(address.c_str());
    fileout << "#include <iostream> \n#include <vector> \n#include <string> \n\nusing namespace std; \n\n";
    fileout << "typedef vector <int> ints \ntypedef vector <string> strings \n\nint main() \n{ \n\treturn 0; \n}";
    fileout.close();
}
void helper::save()
{
    ofstream output;
    output.open(address.c_str(), ios::trunc | ios::out);
    output << command;
    output.close();
}
void helper::MaxLengthFunction()
{
    vector <int> functionLines;
    int MaxLength = 0;
    while(bracesClose.size() != 0)
    {
        if(bracesClose.size() > 1)
        {
            if (bracesOpen[0] < bracesClose[0] && bracesClose[0] < bracesOpen[1])
            {
                if (bracesClose[0] - bracesOpen[0] + 1 > MaxLength)
                MaxLength = bracesClose[0] - bracesOpen[0] + 1;
                bracesOpen.erase(bracesOpen.begin());
                bracesClose.erase(bracesClose.begin());
            }
            else
            {
                if (bracesClose[0] - bracesOpen[1] + 1 > MaxLength)
                MaxLength = bracesClose[0] - bracesOpen[1] + 1;
                bracesOpen.erase(bracesOpen.begin() + 1);
                bracesClose.erase(bracesClose.begin());
            }
        }
        else
        {
            if (bracesClose[0] - bracesOpen[0] + 1 > MaxLength)
            MaxLength = bracesClose[0] - bracesOpen[0] + 1;
            bracesOpen.erase(bracesOpen.begin());
            bracesClose.erase(bracesClose.begin());
        }
    }
}
void helper::changeComment()
{
    size_t position1 = 0 , position2 = 0;
    while ((position1 = command.find("/*", position2)) != string::npos)
    {
        if(command[position1 + 2] == '\n')
            command.replace(position1 , 3, "");
        else
            command.replace(position1 , 2, "");
        command.insert(position1 , "//");
        position2 = command.find("*/", position1);
        command.replace(position2 , 3, "");
        for (int i = position1 ; i < position2; i++)
        {
            if (command[i] == '\n')
                command.insert(i + 1, "//");
        }
    }
}
void helper::setFile(string ad)
{
    ifstream file;
    address = ad;
    lines = 0;
    string s;
    file.open(address.c_str());
    size_t spos = s.find("{"), epos = s.find("}");
    while (getline(file , s))
    {
        command += s + '\n';
        lines++;
        if (spos != string::npos)
            bracesOpen.push_back(lines);
        if (epos != string::npos)
            bracesClose.push_back(lines);
    }
    command.erase(command.length() - 1);
    file.close();
}
void helper::funcL_funcMax()
{

    cout << "number of lines is : " << lines << endl << "max length of functions : ";
    MaxLengthFunction();
}
