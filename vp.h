#include <iostream>

using namespace std;

template<typename T>
struct Node {
	T data;
	double media;
	Node<T> * sons[2];
	Node (){
		sons[0] = NULL;
		sons[1] = NULL;
		media = 0;
	} 
	Node ( T data_ ){
		data = data_;
		sons[0] = NULL;
		sons[1] = NULL;
		media = 0;
	} 
};


template<typename T>
class vantagePointTree{
public:
	Node<T> * head;
	vector<T> universe;

	vantagePointTree( vector<T> universe_ ){
		head = NULL;
		universe = universe_;
	}


	int get_distance (string a, string b){
		int distance = 0;
		for (int i = 0; i < a.size() && i<b.size(); ++i){
			if ( a.at(i) != b.at(i) ){
				distance+=1;
			}
		}
		int d1 = a.size();
		int d2 = b.size();
		distance = distance + abs( d1-d2 );
		return distance;
	}

	void bubbleSort( vector<int> & distances ){
		int n = distances.size();
		for (int i = 0; i < n; ++i){
			for (int j = i+1; j < n; ++j){
				if ( distances.at(i) > distances.at(j) ){
					swap ( distances.at(i),distances.at(j) );
				}
			}
		}
	}


	vector<int> distancesFromWord( vector<T> universe, string word ){
		vector<int> distances;
		for (int i = 0; i < universe.size(); ++i){
			distances.push_back( get_distance( universe.at(i), word ) );
		}
		return distances;
	}

	double getMedia ( vector<int> distances ){
		double media= 0;
		bubbleSort (distances);
		int tmp =  distances.size()/2;
		if ( distances.size() == 0){
			media = 0;
		}
		else if ( distances.size() % 2 == 0 ){
			media = ( distances.at( tmp )+ distances.at( tmp -1 ))/2;
		}
		else { 
			media = distances.at( tmp );
		}	
		return media;
	}
	

	bool insert ( vector<T> universe, Node<T> ** current ){
		if ( universe.empty() ){
			return true;
		}

		else if ( !(*current) ){
			(*current) = new Node<T> ( universe.at( universe.size()-1 ) );
			universe.pop_back();
			vector<int> tmpDistances =distancesFromWord( universe, (*current)->data ); 
			double media_ = getMedia( tmpDistances );
			(*current)->media = media_;
			vector<T> sub_universe1, sub_universe2;
			for (int i = 0; i < universe.size(); ++i){
				if ( get_distance( universe.at(i),(*current)->data )>= media_ ){
					sub_universe2.push_back( universe.at(i) );
				}		
				else {
					sub_universe1.push_back( universe.at(i) );
				}
			}			
			insert (sub_universe1, &((*current)->sons[0]));
			insert (sub_universe2, &((*current)->sons[1]));
		}

		else{
			return false;
		}

	}

	bool insert_ (){
		return insert( universe, &head );
	}

	bool find (T data, Node<T> ** current){
		if (data == (*current)->data ){
			cout<<data<<" Encontrado!"<<endl;
			return true;
		}

	}

	void _display (Node<T>** current, int ident) {
		if (*current) {
			_display( &(*current)->sons[0], ident+1 );
			for (int i=0; i<ident; i++) {
				cout << "    ";
			}
			cout << (*current)->data << endl;
			_display( &(*current)->sons[1], ident+1 );
		}
	}

	void display () {
		_display(&head, 0);
	}
	

	~vantagePointTree(){}
	
};