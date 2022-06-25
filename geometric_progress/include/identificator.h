#ifndef IDENTIFICATOR_H
#define IDENTIFICATOR_H

#include <vector>
#include <string>
#include <cstring>
#include <mutex>
#include <threads.h>
#include "main.h"

//#define NUM_PAIR 10

using namespace std;
namespace IDENTTIFICATOR
{
const int NUM_PAIR = 10;

const string CharValue = {"ABCEHIKLNOPRSTUWXYZ"};
const string DigitValue = {"123456789"};
//const string CharValue = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //full
//const string DigitValue = {"0123456789"}; //full

const string ServisCharValue = {" -"};
const string AllCharValue = ServisCharValue + DigitValue + CharValue;
const string BeginCell = {CharValue[0], DigitValue[0]};
const string BeginPair = {CharValue[0], DigitValue[0],'-',CharValue[0], DigitValue[0]};


class Identificator
{
private:
    mutex mx;
    struct derivativeCell
    {
        string pair ;
        bool status; //FALSE not FULL, TRUE is FULL
        derivativeCell(string&& m_pair, bool m_status) : pair(string(move(m_pair))), status(m_status) {};
        derivativeCell& operator = (const derivativeCell& other) = default;
    };

    vector<derivativeCell> identV;
    bool checkFull(const string& ident);
    bool incrPair(string& pair);
public:
    Identificator();
    Identificator(const Identificator& _oth) { identV = _oth.identV; }
    ~Identificator() { identV.clear(); };
    string incrID();
    string getID();
};

}
#endif // IDENTIFICATOR_H
