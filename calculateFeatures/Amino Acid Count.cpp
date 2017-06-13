#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
char ch;
string line, name, content;
int tl,counter;
void initialize()
{
ofstream out;
out.open("t.csv");
for(ch='A';ch<'Z';ch++)
{
        out<<ch<<",";
}
out<<'Z'<<endl;
out.close();
}
void counts()
{
ofstream output ("t.csv",ios::app);
int cn=0;
for(ch='A';ch<'Z';ch++)
    {
        counter=count(content.begin(), content.end(), ch);
        float per;
        per=(float)((float)(counter*100)/tl);
        output<<per<<",";
    }
int cz=count(content.begin(), content.end(), 'Z');
float perz;
perz=(float)((float)(cz*100)/tl);
output<<perz<<endl;
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
                 counts();
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
