#include <iostream>
#include <vector>
#include <string>

#include "main.h"
#include "identificator.h"

using namespace std;

namespace IDENTTIFICATOR
{

Identificator::Identificator ()
{
    mCells.emplace_back(memoryCell("A1", 1));
}

bool Identificator::checkValid(string& ident)
{
    if(!ident.size())
        return false;
    if(ident.find_first_not_of(AllCharValue) < AllCharValue.size())
        return false;
    size_t pos1 = ident.find_first_of(CharValue), pos2 = ident.find_last_of(DigitValue);
    if(pos1 || pos2 != ident.size() - 1)
        return false;
    int count1 = 0, count2 = 0;
    for(auto c: ident)
    {
        if(c == ' ')
            count1++;
        if(c == '-')
            count2++;
    }
    if(count2 - count1 > 1)
        return false;
return true;
}

bool Identificator::incrPair(string& pair)
{
    int count = 0;
    unsigned n;
    for(auto ch: pair)
    {
        if(ch == '-')
            count++;
    }
    if(pair[pair.size() - 1] != DigitValue[DigitValue.size() - 1])
    {
        n = DigitValue.find(pair[pair.size() - 1]);
        if(n + 1 < DigitValue.size())
            pair[pair.size() - 1] = DigitValue[n + 1];
    }
    else
    {
        pair[pair.size() - 1] = DigitValue[0];
        if(pair[pair.size() - 2] != CharValue[CharValue.size() - 1])
        {
            n = CharValue.find(pair[pair.size() - 2]);
            if(n < CharValue.size())
                pair[pair.size() - 2] = CharValue[n + 1];
        }
        else
        {
            pair[pair.size() - 2] = CharValue[0];
            if(count)
            {
                if(pair[pair.size() - 4] != DigitValue[DigitValue.size() - 1])
                {
                    n = DigitValue.find(pair[pair.size() - 4]);
                    if(n + 1 < DigitValue.size())
                        pair[pair.size() - 4] = DigitValue[n + 1];
                }
                else
                {
                    pair[pair.size() - 4] = DigitValue[0];
                    if(pair[pair.size() - 5] != CharValue[CharValue.size() - 1])
                    {
                        n = CharValue.find(pair[pair.size() - 5]);
                        if(n + 1 < CharValue.size())
                            pair[pair.size() - 5] = CharValue[n + 1];
                    }
                    else
                    {
                        pair[pair.size() - 5] = CharValue[0];
                        return true;
                    }
                }
            }
            else
                pair += string("-A1");
        }
    }
return false;
}

string Identificator::calcIdent(const string& ident)
{
    string _ident(ident);
    if(!checkValid(_ident))
        return "Error";
    string temp, resultStr = ident;
    if(ident.size() < 6)
    {
        if(incrPair(resultStr))
            resultStr += string(" A1");
    }
    else
    {
        int count = 0, ncount;
        bool status;
        for(auto ch: resultStr)
            if(ch == ' ')
                count++;
        ncount = count;
        size_t n = resultStr.find_last_of(" ");
        temp = resultStr.substr(n + 1);
        resultStr.resize(n + 1);
        do {
            status = incrPair(temp);
            if(!status)
            {
                resultStr += temp;
                break;
            }
            else
            {
                memmove(&resultStr[n + 1], &temp[0], temp.size());
                if(--ncount)
                    n -= 5;
                else
                    n = 0;
                temp.clear();
                temp = resultStr.substr(n + 1);
                temp.resize(5);
            }
        } while(ncount);
        if(status && count < 9)
            resultStr += " A1";
        else if(status && count == 9)
            return "Full";
    }
return resultStr;
}

string Identificator::incrID()
{
    lock_guard lg(mx);
    int count = mCells.size();
    string temp = mCells[count - 1].id, newIdent;
    count = mCells[count - 1].number;
    newIdent = calcIdent(temp);
    if(newIdent != "Full" && newIdent != "Error")
    {
        mCells.emplace_back(memoryCell(move(newIdent), ++count));
    }
return mCells.back().id;
}

string Identificator::getIdent(int num)
{
    if((unsigned)num >= mCells.size() || num < 0)
        return string("Error Number");
    return mCells[num].id;
}

int Identificator::getNum() { return mCells.size(); }
string Identificator::getID() { return mCells[mCells.size() - 1].id; };
}
