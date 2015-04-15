/*
 * Schelet Tema 3 SD 2014 - Biblioteca
 * Autor: emil.racec@gmail.com
 */

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "Algorithm.h"

Algorithm::Algorithm(void) {

}

Algorithm::~Algorithm(void) {

}

vector<string> &Algorithm::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

void Algorithm::putBook(vector<string> &words){

	cout << "PUT command:" << "\n";
	/* Observati folosirea iteratorului generic c++ pe vector. De ce
	   este incurajata folosirea lui in comparatie cu iterarea clasica? */
	for(vector<string>::iterator it = words.begin();
			it != words.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";
}

string Algorithm::getBooks(vector<string> &words) {

	cout << "GET command" << "\n";
	for(vector<string>::iterator it = words.begin();
			it != words.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	/* returneaza rezultatul comenzii GET sub forma de string */
	return GET_NULL;
}


string Algorithm::query(vector<string> &words) {

	cout << "PLAY command" << "\n";
	for(vector<string>::iterator it = words.begin();
			it != words.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	/* returneaza QUERY_TRUE respectiv QUERY_FALSE corespunzator */
	return QUERY_TRUE;
}

void Algorithm::resolve() {

    string inputLine;
	while ( cin.good() )
	{
		getline(cin, inputLine);

		vector<string> words;
    	split(inputLine, ' ', words);

		if (words.size() == 0) {
			continue;
		}

		/* TODO: stergeti asta dupa ce raspundeti corect la intrebare :)
		   Observati folosirea operatorului '==' in comparatia a doua siruri
		   de caractere reprezentate ca string. De ce este posibil acest
		   lucru? */
		if (words[0] == PUT)
			putBook(words);
		else if (words[0] == GET)
			cout << getBooks(words) << "\n";
		else if (words[0] == QUERY)
			cout << query(words) << "\n";
		else
			cerr << "Invalid option" << "\n";
	}
}
