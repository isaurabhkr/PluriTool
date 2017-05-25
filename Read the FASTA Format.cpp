#include <iostream>
#include <fstream>
using namespace std;
int main(){

    fstream input;
    input.open("positive.txt");
    if(!input.good()){
        cout << "Error opening"<< endl;
        return -1;
    }

    string line, name, content;
    while( getline( input, line ) )
        {
        if( line.empty() || line[0] == '>' ){
            if( !name.empty() ){
                cout << name << " : " << content <<endl<<endl;
                name.clear();
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
        cout << name << " : " << content << endl;
    }

    return 0;
}
