#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;



int main(int argc, const char* argv[]) {
	fstream text;
	//define morse codes standard
	map<string, string> coder;
	coder = {
		{ "A",".-"},
		{ "B","-..." },
		{ "C","-.-." },
		{ "D","-.." },
		{ "E","." },
		{ "F","..-." },
		{ "G","--."},
		{ "H","...." },
		{ "I",".." },
		{ "J",".---" },
		{ "K","-.-" },
		{ "L",".-.." },
		{ "M","--" },
		{ "N","-." },
		{ "O","---" },
		{ "P",".--." },
		{ "Q","--.-" },
		{ "R",".-." },
		{ "S","..." },
		{ "T","-" },
		{ "U","..-" },
		{ "V","...-" },
		{ "W",".--" },
		{ "X","-..-" },
		{ "Y","-.--" },
		{ "Z","--.." },
		{ "1",".----" },
		{ "2","..---" },
		{ "3","...--" },
		{ "4","....-" },
		{ "5","....." },
		{ "6","-...." },
		{ "7","--..." },
		{ "8","---.." },
		{ "9","----." },
		{ "0","-----" },
		{ " ","   " },
	};

	//get filename from shell to read text from
	string infilename;
	if(argc > 1)
		infilename = argv[1];
	else
		infilename = "text.txt";

	//read text from input file
	string stext;
	text.open(infilename);
	getline(text, stext);
	text.close();
	cout << stext << endl;

	// convert string to upper case
	for_each(stext.begin(), stext.end(), [](char & c) {
		c = toupper(c);
	});
	cout << stext << endl;

	//coder
	string coded = "";
	string temp;
	for (int i = 0; i < stext.size();i++) {
		temp = stext[i];
		coded += coder.find(temp)->second;
		coded += " ";
	}

	cout << coded << endl;
	//write coded to a file 
	text.open("code.txt");
	text << coded;
	text.close();
	
	return 0;
}