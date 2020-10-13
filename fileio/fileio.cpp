/*
 * fileio.cpp
 *
 *  Created on: Oct. 8, 2020
 *      Author: Savian Elam
 */


using namespace std;

#include "../includes/fileio.h"

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(fstream& myfile, const string& myFileName,
		ios_base::openmode mode){
	myfile.open(myFileName, mode);
	if(myfile.is_open()){
		return true;
	}
	else{
		return false;
	}
}

/*iff myfile is open then close it*/
void closeFile(fstream& myfile){
	if(myfile.is_open()){
		myfile.close();
	}
}

/* serializes all content in entries to file outputfilename
 * check out utils for helpful type conversion functions
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writetoFile(vector<constants::entry>  &entries, const string &outputfilename){
	fstream myfile;
	openFile(myfile, outputfilename, ios_base::out);
	if(!myfile.is_open()){
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}

	if(entries.empty()){
		return  constants::FAIL_NO_ARRAY_DATA;
	}

	for (int i = 0; i < entries.size(); i++){
		myfile << entries[i].word << " " << entries[i].number_occurences << endl;
	}

	closeFile(myfile);
	return constants::SUCCESS;
}


