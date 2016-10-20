#include <iostream>
#include <fstream>
#include <string>
#include <vector>	
#include <stdlib.h> 
#include "vp.h"

using namespace std;


vector<string> readDocument (string file){
	vector<string> universe;
	string STRING;
    ifstream infile;
    infile.open (file);
        while(!infile.eof()) // To get you all the lines.
        {
            getline(infile,STRING); // Saves the line in STRING.
            universe.push_back(STRING);
        }
    
    infile.close();
    return universe;
}

int main (){
	cout<<"Hello World!"<<endl;
	vantagePointTree<string> ax ( readDocument("text.txt") );
	ax.insert_();
	ax.display();
	return 1;
}