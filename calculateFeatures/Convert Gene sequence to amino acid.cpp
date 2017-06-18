#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
char ch;
string line, name, content;
int tl,counter;
void initializeopfile()
{
ofstream out;
out.open("ans.txt",std::fstream::trunc );
out.close();
}
void rep(string str)
{
    ofstream outp;
    outp.open("ans.txt",std::ios_base::app);
    if(str=="ATT"||str=="ATC", str=="ATA")
    {
        cout<<"I";
        outp<<"I";
    }
    else if(str=="CTT"||str=="CTC"||str=="CTA"||str=="CTG"||str=="TTA"||str=="TTG")
    {
        cout<<"L";
        outp<<"L";
    }
    else if(str=="CGT"||str=="CGC"||str=="CGA"||str=="CGG"||str=="AGA"||str=="AGG")
    {
        cout<<"R";
        outp<<"R";
    }
    else if(str=="GAG"||str=="GAA")
    {
        cout<<"E";
        outp<<"E";
    }
     else if(str=="GTT"||str=="GTC"||str=="GTA"||str=="GTG")
    {
        cout<<"V";
        outp<<"V";
    }
     else if(str=="TTT"||str=="TTC")
    {
        cout<<"F";
        outp<<"F";
    }
     else if(str=="ATG")
    {
        cout<<"M";
        outp<<"M";
    }
     else if(str=="TGT"||str=="TGC")
    {
        cout<<"C";
        outp<<"C";
    }
    else if(str=="GCT"||str=="GCC"||str=="GCA"||str=="GCG")
    {
        cout<<"A";
        outp<<"A";
    }
    else if(str=="GGT"||str=="GGC"||str=="GGA"||str=="GGG")
    {
        cout<<"G";
        outp<<"G";
    }
    else if(str=="CCT"||str=="CCC"||str=="CCA"||str=="CCG")
    {
        cout<<"P";
        outp<<"P";
    }
     else if(str=="ACT"||str=="ACC"||str=="ACA"||str=="ACG")
    {
        cout<<"T";
        outp<<"T";
    }
    else if(str=="TCT"||str=="TCC"||str=="TCA"||str=="TCG"||str=="AGT"||str=="AGC")
    {
        cout<<"S";
        outp<<"S";
    }
     else if(str=="TAT"||str=="TAC")
    {
        cout<<"Y";
        outp<<"Y";
    }
     else if(str=="TGG")
    {
        cout<<"W";
        outp<<"W";
    }
     else if(str=="CAA"||str=="CAG")
    {
        cout<<"Q";
        outp<<"Q";
    }
    else if(str=="AAT"||str=="AAC")
    {
        cout<<"N";
        outp<<"N";
    }
    else if(str=="CAT"||str=="CAC")
    {
        cout<<"H";
        outp<<"H";
    }
     else if(str=="GAT"||str=="GAC")
    {
        cout<<"D";
        outp<<"D";
    }
     else if(str=="AAA"||str=="AAG")
    {
        cout<<"K";
        outp<<"K";
    }
     else if(str=="TAA"||str=="TAG"||str=="TGA")
    {
        cout<<"X";
        outp<<"X";
    }
}
void callrep()
{
for(int i=0;i<tl;i=i+3)
{
    string str2 = content.substr (i,3);
    //cout<<"The substring is "<<str2<<endl<<endl;
    rep(str2);
}
}
void write()
{
    ofstream outp;
    outp.open("ans.txt",std::ios_base::app);
    cout<<">"<<name<<endl;
    outp<<">"<<name<<endl;
    callrep();
    cout<<endl;
    outp<<endl;
}
int main(){
fstream input;
initializeopfile();
input.open("sequence.fasta");
    if(!input.good()){
        cout << "Error opening"<< endl;
        return 0;
    }
    while( getline( input, line ) )
        {
        if( line.empty() || line[0] == '>' ){
            if( !name.empty() ){

                 tl=content.size();
                //cout << name << " : " << content <<endl<<endl;
                write();


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
        tl=content.size();
        write();
    }

    input.close();
    return 0;
}
