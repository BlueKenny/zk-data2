#include <boost/filesystem.hpp>

#include <string>
using namespace std;


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

