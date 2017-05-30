#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
char ch,ch1,ch3;
string line, name, content;
int tl,counter;
vector<string> comb;
void initialize()
{
ofstream out;
comb.clear();
out.open("temp.csv");
for(ch='A';ch<='Z';ch++)
{
    for(ch1='A';ch1<='Z';ch1++)
    {
        string temp;
        string a(1,ch);
        string b(1,ch1);
        temp=a+b;
        comb.push_back(temp);
        out<<ch<<ch1<<",";
    }
}
out<<endl;
out.close();
}
void printv()
{
    vector<string>::iterator it;
    cout << "The vector elements are : ";
    for (it = comb.begin(); it < comb.end(); it++)
        cout << *it << endl;
}
int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    int counter = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
	 offset = str.find(sub, offset + sub.length()))
    {
        ++counter;
    }
    return counter;
}


void write()
{
ofstream output ("temp.csv",ios::app);
vector<string>::iterator it;
for (it = comb.begin(); it < comb.end(); it++)
    {
        counter=countSubstring(content,*it);
        float per;
        per=(float)((float)(counter*100)/tl);
        output<<per<<",";
    }
output<<endl;
}

int main(){
fstream input;
input.open("positive.txt");
initialize();
    if(!input.good()){
        cout << "Error opening"<< endl;
        return 0;
    }
    while( getline( input, line ) )
        {
        if( line.empty() || line[0] == '>' ){
            if( !name.empty() ){
                cout << name << " : " << content <<endl<<endl;
                tl=content.size();
                 write();
                 //printv();
                name.clear();
            }
            if( !line.empty() ){
                name = line.substr(1);
            }
            content.clear();
        }
        else if( !name.empty() ){
            if( line.find(' ') != std::string::npos ){
                name.clear();
                content.clear();
            } else {
                content += line;
            }
        }
    }
    if( !name.empty() )
    {
        cout << name << " : " << content << endl<<endl;
    }

    input.close();
    return 0;
}
