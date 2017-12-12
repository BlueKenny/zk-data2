//#include <boost/filesystem.hpp>

#include <string>
using namespace std;

#include <sys/stat.h>
#include <sys/types.h>

#include <iostream>
extern bool PathExists(std::string directory){/*
	boost::filesystem::path DIR (directory);
	
	if (boost::filesystem::exists(DIR)) {
		return true;
	 }
	else {*/
		return false;/*
	}*/
	
}

extern void MkDir(std::string directory){ // MkDir if not exists
	cout << "mkdir \"" << directory << "\"" << endl;

	//int status;
	//status = mkdir(directory, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	/*	
	boost::filesystem::path dir(directory);
	;
	if(boost::filesystem::create_directory(dir){
		cout << "ok" << endl;
	}
	else {
		cout << "no" << endl;
	}*/
	return;
}

