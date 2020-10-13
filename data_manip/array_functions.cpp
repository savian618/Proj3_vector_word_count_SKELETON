/*
 * array_functions.cpp
 *
 *  Created on: Oct 8, 2020
 *      Author: Savian Elam
 */

#include "../includes/utilities.h"
#include "../includes/array_functions.h"
#include <algorithm>


using namespace std;

namespace KP{
	//zero out vector that tracks words and their occurrences
	void clear(std::vector<constants::entry>  &entries){
		entries.clear();
	}

	//how many unique words are in the vector
	int getSize(vector<constants::entry>  &entries){
		return entries.size();
	}

	//get data at a particular location, if i>size() then get the last value in the vector
	//(this is lazy, should throw an exception instead)
	string getWordAt(std::vector<constants::entry>  &entries, int i){
		int len = entries.size();

		if(i >= len){
			return entries.back().word;
		}

		else{
			return entries[i].word;
		}
	}

	int getNumbOccurAt(std::vector<constants::entry>  &entries,int i){
		int len = entries.size();

		if(i >= len){
			return entries.back().number_occurences;
		}

		else{
			return entries[i].number_occurences;
		}
	}

	/*loop through whole file, one line at a time
	 * call processLine on each line from the file
	 * returns false: myfstream is not open
	 *         true: otherwise*/
	bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream){


		if(!myfstream.is_open()){
			return false;
		}

		string line;

		while(!myfstream.eof()){
			getline(myfstream, line);
			processLine(entries, line);
		}

		return true;
	}

	/*take 1 line and extract all the tokens from it
	feed each token to processToken for recording*/
	void processLine(std::vector<constants::entry>  &entries,std::string &myString){
		stringstream ss(myString);
		string pToken;

		while(getline(ss, pToken, constants::CHAR_TO_SEARCH_FOR)){
			processToken(entries, pToken);
		}
	}

	/*Keep track of how many times each token seen*/
	void processToken(std::vector<constants::entry>  &entries,std::string &token){
		strip_unwanted_chars();
		constants::entry mp;
		mp.word = token;
		string tempTok = token;
		toUpper(tempTok);
		mp.word_uppercase = tempTok;
		mp.number_occurences = 1;
		entries.push_back(mp);

		int len = entries.size();

		for(int i = 0; i < len; i++){
			if(entries[i].word == token || entries[i].word_uppercase == token){
				entries[i].number_occurences++;
			}
		}
	}

	bool sortAscending(const constants::entry& a, const constants::entry b ){
		return a.word > b.word;
	}

	bool sortDescending(const constants::entry& a, const constants::entry b ){
			return a.word < b.word;
		}

	bool sortNum(const constants::entry& a, const constants::entry b ){
			return a.number_occurences > b.number_occurences;
		}

	/*
	 * Sort myEntryArray based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo project for how to sort a vector of structs
	 */
	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so){
		switch(so){

		case constants::NONE:
			break;

		case constants::ASCENDING:
			sort(entries.begin(), entries.end(), sortAscending);
			break;

		case constants::DESCENDING:
			sort(entries.begin(), entries.end(), sortDescending);
			break;

		case constants::NUMBER_OCCURRENCES:
			sort(entries.begin(), entries.end(), sortDescending);
			break;

		default:
			break;

		}
	}
}

