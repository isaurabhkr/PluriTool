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
const char *feature[] = {"DEKHR","ILV","FHWY","DERKQN","AGHPSTY","CVLIMFW","HKR","DE","ACDGST","EHILKMNPQV","FRWY"};
std::vector<std::string> features(feature, feature+11);

void initialize(string s)
{
    ofstream writer;
    string st=s;
    st += ".csv";

    writer.open(st.c_str());
    string::iterator it;
    for (it = s.begin(); it < s.end(); it++)
    {
        writer<<*it<<",";
    }
    writer<<"class,";
    writer<<endl;
    writer.close();

}
void writeforneg(string s)
{
string st=s;
ofstream out;
st += ".csv";
out.open(st.c_str(),ios::app);
string::iterator it;
int counter;
for (it = s.begin(); it < s.end(); it++)
    {
        counter=count(content.begin(), content.end(),*it);
        float per;
        per=(float)((float)(counter*100)/tl);
        out<<per<<",";
    }
    out<<"no"<<endl;
}
void writeforpos(string s)
{
string st=s;
ofstream out;
st += ".csv";
out.open(st.c_str(),ios::app);
//ofstream out("feat.csv",ios::app);
string::iterator it;
int counter;
for (it = s.begin(); it < s.end(); it++)
    {
        counter=count(content.begin(), content.end(),*it);
        float per;
        per=(float)((float)(counter*100)/tl);
        out<<per<<",";
    }
    out<<"yes"<<endl;
}
int main()
{
int choice;
cout<<" Press 1 for % Composition of charged residues (DEKHR)"<<endl;
cout<<" Press 2 for % Composition of aliphatic residues (ILV)"<<endl;
cout<<" Press 3 for % Composition of Aromatic residues (FHWY)"<<endl;
cout<<" Press 4 % Composition of Polar residues (DERKQN)"<<endl;
cout<<" Press 5 % Composition of Neutral residues (AGHPSTY)"<<endl;
cout<<" Press 6 % Composition of Hydrophobic residues (CVLIMFW)"<<endl;
cout<<" Press 7 % composition of Positive charged residues (HKR)"<<endl;
cout<<" Press 8 % Composition of Negative charged residues (DE)"<<endl;
cout<<" Press 9 % Composition of tiny residues (ACDGST)*"<<endl;
cout<<" Press 10 % Composition of Small residues (EHILKMNPQV)*"<<endl;
cout<<" Press 11 % Composition of Large residues (FRWY)*"<<endl;

cin>>choice;
choice--;
fstream input;
input.open("negative.txt");
initialize(features[choice]);
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
                writeforneg(features[choice]);
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
input.open("positive.txt");
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
                writeforpos(features[choice]);
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
