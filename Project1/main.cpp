#include <iostream>
#include <fstream>
#include <algorithm>
#include "dealer.h"

using namespace std;

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

void draw_cards( std::vector<int>& stack_length, int suits, int n )
{
	Dealer dealer( suits );
	Card prev = dealer();
	cout << "1: " << prev.to_string() << '\n';
	int length = 1;
	for ( int i = 1; i < n; ++i ){
		Card drawn = dealer();
		if ( drawn < prev ){
			stack_length.push_back( length );
			length = 0;
			cout << "New stack: " << '\n';
		}
		cout << i + 1 << ": " << drawn.to_string() << '\n';
		++length;
		prev = drawn;
	}
	stack_length.push_back( length );
	sort( stack_length.begin(), stack_length.end() );
}

void analise( std::vector<int>& stack_length, int suits, int n )
{

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

	std::vector<int> stack_length;
	draw_cards( stack_length, suits, n );
	for ( int i = 0; i < stack_length.size(); ++i )
		cout << stack_length[i] << " ";
	analise( stack_length, suits, n );
	
	return 0;
}
