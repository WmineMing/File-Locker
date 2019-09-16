#include "locker.h"
#include<fstream>
#include<iostream>
locker::locker()
{
    infilename="";
    outfilename="";
    key="";
}

locker::locker(std::string infilename, std::string outfilename, std::string key)
{
    locker::infilename=infilename;
    locker::outfilename=outfilename;
    locker::key=key;
}

locker::~locker()
{

}

int locker::setinfile(std::string infilename)
{
    locker::infilename=infilename;
    return 0;
}
std::string locker::getinfile()
{
    return infilename;
}

int locker::setoutfile(std::string outfilename)
{
    locker::outfilename=outfilename;
    return 0;
}
std::string locker::getoutfile()
{
    return outfilename;
}

int locker::setkey(std::string key)
{
    locker::key=key;
    return 0;
}
std::string locker::getkey()
{
    return key;
}

int locker::lockey()
{
    int errorcode=0;
    std::ifstream infile(infilename.c_str(),std::ios::in|std::ios::binary);//open infile
    std::ofstream outfile(outfilename.c_str(),std::ios::out|std::ios::binary);//open outfile
    if(!infile){
        errorcode=11;//infilename error
       // exit(1);
    }
    if(!outfile){
        errorcode=22;//outfilename error
        //exit(1);
    }

    char datain,dataout;
    int keybytes=key.length();
    int n=0;
    while(infile.read(&datain,1)){
		dataout=key[n]^datain;
        outfile.write(&dataout,1);
        //std::cout<<std::hex<<(int)datain<<" "<<std::hex<<(int)key[n]<<" "<<std::hex<<(int)dataout<<std::endl;//debug
        n++;
        n%=keybytes;
        key[n]+=dataout;
    }
    infile.close();
    outfile.close();
    return errorcode;
}
int locker::unlockey()
{
    int errorcode=0;
    std::ifstream infile(infilename.c_str(),std::ios::in|std::ios::binary);//open infile
    std::ofstream outfile(outfilename.c_str(),std::ios::out|std::ios::binary);//open outfile
    if(!infile){
        errorcode=11;//infilename error
       // exit(1);
    }
    if(!outfile){
        errorcode=22;//outfilename error
        //exit(1);
    }

    char datain,dataout;
    int keybytes=key.length();
    int n=0;
    while(infile.read(&datain,1)){
		dataout=key[n]^datain;
        outfile.write(&dataout,1);
        //std::cout<<std::hex<<(int)datain<<" "<<std::hex<<(int)key[n]<<" "<<std::hex<<(int)dataout<<std::endl;//debug
        n++;
        n%=keybytes;
        key[n]+=datain;
    }
    infile.close();
    outfile.close();
    return errorcode;
}
int locker::lockfile()
{
    return lockey();
}

int locker::unlockfile()
{
    return unlockey();
}
