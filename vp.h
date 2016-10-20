#include <iostream>

using namespace std;

template<typename T>
struct Node {
	T data;
	Node<T> * sons[2];
	Node (){
		sons[0] = NULL;
		sons[1] = NULL;
	} 
	Node ( T data_ ){
		data = data_;
		sons[0] = NULL;
		sons[1] = NULL;
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

	vector<int> distancesFromWord( vector<T> universe, string word ){
		vector<int> distances;
		for (int i = 0; i < universe.size(); ++i){
			distances.push_back( get_distance( universe.at(i), word ) );
		}
		return distances;
	}

	double getMedia ( vector<int> distances ){
		double media= 0;
		for (int i = 0; i < distances.size(); ++i){
			media+= distances.at(i);
		}
		return media/distances.size();
	}
	

	bool insert ( vector<T> universe, Node<T> ** current ){
		if ( universe.empty() ){
			return true;
		}

		else if ( !(*current) ){
			(*current) = new Node<T> ( universe.at( universe.size()-1 ) );
			universe.pop_back();
			double media = getMedia( distancesFromWord( universe, (*current)->data ) );
			vector<T> sub_universe1, sub_universe2;
			for (int i = 0; i < universe.size(); ++i){
				if ( get_distance( universe.at(i),(*current)->data )>= media ){
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