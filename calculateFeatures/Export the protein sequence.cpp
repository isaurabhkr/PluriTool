#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream file ( "down.csv" ); // declare file stream: http://www.cplusplus.com/reference/iostream/ifstream/
    string gene;
    while ( file.good() )
    {
     getline ( file, gene, '\n' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
     //cout << string( gene, 1, gene.length()-2 ); // display gene removing the first and the last character from it
    //cout<<gene<<endl;
    ofstream output;
    output.open("down.txt",ios::app);
    fstream input;
    input.open("mouse.fasta");
    if(!input.good()){
        cout << "Error opening"<< endl;
        return -1;
    }
    int flag=0;
    string line, name, content;
    while( getline( input, line ) )
        {
        if( line.empty() || line[0] == '>' ){
            if( !name.empty() ){
                std::size_t found = name.find(gene);
               if(found!=std::string::npos){
                cout <<">"<<name << " : " << content <<endl<<endl;
                output<<">"<<name<<endl;
                output<<content<<endl;
                flag=1;
                break;
            }
            }
            if( !line.empty() ){
                name = line.substr(1);
            }
            content.clear();
        } else if( !name.empty() ){
            if( line.find(' ') != std::string::npos ){
                name.clear();
                content.clear();
            } else {
                content += line;
            }
        }
    }
    if( !name.empty() ){ // Print out what we read from the last entry
        //cout << name << " : " << content << endl;
    }

        if(flag==0)
            cout<<"Sorry! Not Found in our DB"<<endl;
    output.close();
    }
}

