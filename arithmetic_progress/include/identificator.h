#ifndef IDENTIFICATOR_H
#define IDENTIFICATOR_H

#include <vector>
#include <string>
#include <cstring>
#include <mutex>
#include <threads.h>
#include "main.h"

#define NUM_PAIR 10

using namespace std;
namespace IDENTTIFICATOR
{

const string CharValue = {"ABCEHIKLNOPRSTUWXYZ"};
const string DigitValue = {"123456789"};
//const string CharValue = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //full
//const string DigitValue = {"0123456789"}; //full

const string ServisCharValue = {" -"};
const string AllCharValue = ServisCharValue + DigitValue + CharValue;

class Identificator
{
private:
    mutex mx;
    struct memoryCell
    {
        string id ;
        int number;
        memoryCell(string&& m_id, int m_number) : id(move(m_id)), number(m_number) {};
        memoryCell& operator = (const memoryCell& other) = default;
    };
    vector<memoryCell> mCells;
    bool checkValid(const string& ident);
    bool incrPair(string& pair);
public:
    Identificator();
    Identificator(const Identificator& _oth) { mCells = _oth.mCells; }
    ~Identificator() { mCells.clear(); };
    int getNum();
    string incrID();
    string getID();
    string calcIdent(const string& ident);
    string getIdent(int num);
};

}
#endif // IDENTIFICATOR_H
