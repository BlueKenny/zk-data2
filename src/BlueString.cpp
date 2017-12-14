#include <iostream>// cout
#include <fstream>

#include <string>
using namespace std;

/*
extern void AddString(string text, string dateix) {
	ofstream fileSt(dateix, ios::app);
	fileSt << text << endl;
	return;
}*/


extern void Debug(std::string text) {
	
	ofstream file("DEBUGING", ios::app);
	file << text << endl;
	cout << "DEBUGING : "<< text << endl;
	return;
}
