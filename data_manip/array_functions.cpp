/*
 * array_functions.cpp
 *
 *  Created on: Oct 8, 2020
 *      Author: Savian Elam
 */

#include "../includes/array_functions.h"

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
		if(token!= " "){
			if(token.empty() == false){
				constants::entry mp;
				mp.word = token;
				mp.word_uppercase = token;
				mp.number_occurences = 1;
				entries.push_back(mp);
			}
		}

		for (int i = 0; i < entries.size(); i++){
			if(entries[i].word == token || entries[i].word_uppercase == token){
				entries[i].number_occurences++;
			}
		}

	}

	/*
	 * Sort myEntryArray based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo project for how to sort a vector of structs
	 */
	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so){

	}

}






