#include <iostream>
#include <fstream>
using namespace std;
int main(){
    cout<<"Enter the number of gene sequences for which you want to export the FASTA sequence"<<endl;
    int t;
    cin>>t;
    while(t--){
    ofstream output;
    output.open("ex.txt",ios::app);
    fstream input;
    input.open("Full.txt");
    if(!input.good()){
        cout << "Error opening"<< endl;
        return -1;
    }
    string gene;
    cout<<"Enter the gene sequence:"<<endl;
    cin>>gene;
    int flag=0;
    string line, name, content;
    while( getline( input, line ) )
        {
        if( line.empty() || line[0] == '>' ){
            if( !name.empty() ){
                std::size_t found = name.find(gene);
                if(found!=std::string::npos){
                cout << name << " : " << content <<endl<<endl;
                output<<name<<endl;
                output<<content<<endl;
                flag=1;
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

