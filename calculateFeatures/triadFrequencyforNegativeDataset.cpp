#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
char ch,ch1,ch3;
string line, name, content;
int tl,counter1,counter2,counter3;
vector<string> comb;
const char *tri[] = {"AGV", "ILFP", "YMTS","HNOW","RK","DE","C"};
std::vector<std::string> triad(tri, tri+7);
void initialize()
{
ofstream out;
comb.clear();
out.open("triad.csv");
for(int i=1;i<=343;i++)
{
out<<i<<',';
}
out<<"class"<<endl;
out.close();
}
void printv()
{
    vector<string>::iterator it;
    cout << "The vector elements are : ";
    for (it = triad.begin(); it < triad.end(); it++)
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
ofstream output ("triad.csv",ios::app);
vector<string>::iterator it,it2,it3;
for (it = triad.begin(); it < triad.end(); it++)
    {
    for (it2 = triad.begin(); it2 < triad.end(); it2++)
        {
            for (it3 = triad.begin(); it3 < triad.end(); it3++)
                {
            counter1=countSubstring(content,*it);
            counter2=countSubstring(content,*it2);
            counter3=countSubstring(content,*it3);
            float per;
            per=(float)((float)(counter1*counter2*counter3)/(tl-2));
            output<<per<<",";
                }
        }
  }
output<<"no"<<endl;
}

int main(){
fstream input;
input.open("negative.txt");
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
