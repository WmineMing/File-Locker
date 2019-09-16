#ifndef LOCKER_H
#define LOCKER_H
#include<string>
class locker
{
public:
    locker();
    locker(std::string,std::string,std::string);
    ~locker();
    int setinfile(std::string);
    int setoutfile(std::string);
    int setkey(std::string);
    int lockfile();
    int unlockfile();
    std::string getinfile();
    std::string getoutfile();
    std::string getkey();
private:
    std::string infilename;
    std::string outfilename;
    std::string key;
    int lockey();
    int unlockey();
};

#endif // LOCKER_H
