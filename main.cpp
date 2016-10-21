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

/*	vector<int>d;
	d.push_back(3);
	d.push_back(7);
	d.push_back(1);
	d.push_back(9);
	d.push_back(0);
	d.push_back(2);
	d.push_back(56);

	ax.bubbleSort(d);
	for (int k = 0; k<d.size(); k++){
			cout<<d.at(k)<<'\t';
		}
	cout<<ax.getMedia (d);
*/	return 1;
}