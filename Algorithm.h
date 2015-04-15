/*
 * Schelet Tema 3 SD 2014 - Biblioteca
 * Autor: emil.racec@gmail.com
 */

#ifndef __Algorithm__H
#define __Algorithm__H

#define INITIAL_CAPACITY 128

#include <vector>
#include <memory>
#include <string>

#define PUT "PUT"
#define GET "GET"
#define QUERY "PLAY"

#define GET_NULL "BOOK_NOT_FOUND"
#define QUERY_TRUE "YOU_WIN"
#define QUERY_FALSE "YOU_LOSE"

using namespace std;

class Algorithm
{
private:

	/*
	 * Definii membrii private necesari clasei Algoritm. Ex: hashtable?
	 */

	/* TODO: sterge asta dupa ce citesti
		* observati ca metodele split, indexBook, getBook si query sunt
		  private. Motivul este simplu: acestea sunt apelate *doar* in cadrul
		  algoritmului si nu este necesara vizibilitatea lor in exteriorul
		  clasei.
	*/

	/* functie ce parseaza un string s dupa delimitatorul delim si
	   completeaza vectorul elems cu substring-urile rezultate*/
	vector<string> &split(const string &s, char delim,
									vector<string> &elems);

	/* Proceseaza o comanda PUT */
	void putBook(vector<string> &words);

	/* Proceseaza o comanda GET */
	string getBooks(vector<string> &words);

	/** Proceseaza o comanda PLAY */
	string query(vector<string> &words);

public:
	Algorithm(void);
	~Algorithm(void);

	/* Proceseaza fiecare comanda, pana cand se intalneste EOF */
	void resolve();
};

#endif
