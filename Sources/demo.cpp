#include <iostream>
#include <string>
#include <stdlib.h>
#include "locker.h"
using namespace std;
//locker demo

void printusage(char*);

int main(int argc,char* argv[])
{
	string options;
	string infile;
	string outfile;
	string key;
	string postfix=".lock";
	int errorcode;
	if(argc!=4&&argc!=5)
		printusage(argv[0]);
	else
	options=argv[1];
	infile=argv[2];
	key=argv[3];

	if(options=="-l")
		outfile=infile+postfix;
	else if(options=="-u"){
		outfile=infile;
		outfile.resize(outfile.length()-5);}
	else printusage(argv[0]);

	if(argc==5) outfile=argv[4];

	locker file(infile,outfile,key);
	if(options=="-l")
        errorcode=file.lockfile();
    else if(options=="-u")
        errorcode=file.unlockfile();
    else
        errorcode=-1;
	switch(errorcode)
	{
		case 0:break;
		case 11:cout<<"infile error"<<endl;break;
		case 22:cout<<"outfile error"<<endl;break;
		default:cout<<"unknown error"<<endl;
	}
	return errorcode;
}
void printusage(char* command)
{
	cout<<"Usage: "<<command<<" <options> <infile> <key>"<<" [outfile]"<<endl;
	cout<<"options:"<<endl;
	cout<<"	-l	lock file"<<endl;
	cout<<"	-u	unlock file"<<endl;
	exit(1);
}
