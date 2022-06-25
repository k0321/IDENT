#include <iostream>
#include <vector>
#include <string>

#include "main.h"
#include "identificator.h"

using namespace std;

namespace IDENTTIFICATOR
{
#include "identificator.h"

using namespace std;

Identificator::Identificator ()
{
    string temp("Z9-Z9");
    identV.emplace_back(derivativeCell(temp.c_str(), true));
    identV.emplace_back(derivativeCell(temp.c_str(), true));
}

bool Identificator::checkFull(const string& ident)
{
    if(ident.size() == 5)
    {
        if((ident[0] == CharValue[CharValue.size() - 1]) &&
                (ident[1] == DigitValue[DigitValue.size() - 1]) &&
                (ident[3] == CharValue[CharValue.size() - 1]) &&
                (ident[4] == DigitValue[DigitValue.size() - 1]))
            return true;
    }
    return false;
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

    if(checkFull(pair))
        return false;

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
                }
            }
            else
            {
                pair += '-';
                pair.append(BeginCell);
            }
        }
    }
return true;
}

string Identificator::incrID()
{
    lock_guard lg(mx);

    if(!incrPair(identV.back().pair) && identV.size() < NUM_PAIR)
    {
        identV.back().pair.clear();
        identV.back().pair.append(BeginPair);
        identV.back().status = false;
        if(identV.size() > 1)
        {
            bool status = true;
            for(unsigned i = 2; i < identV.size() + 1; ++i)
            {
                if(identV[identV.size() - i].status)
                {
                    identV[identV.size() - i].pair.clear();
                    identV[identV.size() - i].pair.append(BeginPair);
                    identV[identV.size() - i].status = false;
                }
                else
                {
                    incrPair(identV[identV.size() - i].pair);
                    identV[identV.size() - i].status = checkFull(identV[identV.size() - i].pair);
                    status = false;
                    break;
                }
            }
            if(status)
                identV.emplace_back(derivativeCell(BeginCell.c_str(), false));
        }
        else
            identV.emplace_back(derivativeCell(BeginCell.c_str(), false));
    }

    string temp {};
    for(const auto& ptr: identV)
        temp.append(ptr.pair + " ");
return temp;
}

string Identificator::getID() { string temp {}; for(const auto& ptr: identV) temp.append(ptr.pair + " "); return temp; };
}
