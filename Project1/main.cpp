#include <iostream>
#include <fstream>
#include <algorithm>
#include "dealer.h"

using namespace std;
const int ranks = 13;

void readInput( int& suits, int& cards_drawn )
{
	ifstream f( "input.txt" );
	if ( !f )
		throw runtime_error( "Input file couldn't be open" );
	
	{
		int temp = 0;
		f >> temp;
		if ( f.fail() || temp <= 0 )
			throw invalid_argument( "Suits number must be positive integer" );
		suits = temp; 
	}

	{
		int temp = 0;
		f >> temp;
		if ( f.fail() || temp <= 0 )
			throw invalid_argument( "Cards drawn number must be positive integer" );
		cards_drawn = temp; 
	}

	{
		char temp;
		if ( f>>temp )
			throw invalid_argument( "Too many arguments in input file" );
	}
} 

void draw_cards( vector<int>& stack_length, int suits, int n )
{
	Dealer dealer( suits );
	Card prev = dealer();
	int length = 1;
	for ( int i = 1; i < n; ++i ){
		Card drawn = dealer();
		if ( drawn < prev ){
			stack_length.push_back( length );
			length = 0;
		}
		++length;
		prev = drawn;
	}
	stack_length.push_back( length );
	sort( stack_length.begin(), stack_length.end() );
}

void analise( vector<int>& stack_length, int suits, int n )
{
	ofstream f("output.txt");
	pair<int, int> most_frequent_length {0, -1};
	int pos = 0;
	for ( int length = 1; length <= min(n, ranks * suits + suits); ++length ){
		int num = 0;
		while (pos < stack_length.size() && stack_length[pos]==length){
		++num;
		++pos;
		}
		f<<"Stacks with length " << length << ": " << (double)num / stack_length.size() * 100 << "%" << '\n';
	}
	f<<"Average stack length: " << (double)n / stack_length.size() << '\n';
	double median;
	if ( stack_length.size() % 2 == 0 )
		median = (stack_length[stack_length.size()/2 -1] + stack_length[stack_length.size()/2] ) / 2;
	else
		median = stack_length[stack_length.size()/2];
	f<<"Stack length median: " << median << '\n';
}

int main()
{
	int suits, n;
	try{
		readInput( suits, n );
	}
	catch ( const exception& e ){
		cout << "Error while reading input file: " << e.what();
		return 1;
	}

	vector<int> stack_length;
	draw_cards( stack_length, suits, n );

	analise( stack_length, suits, n );
	
	return 0;
}
