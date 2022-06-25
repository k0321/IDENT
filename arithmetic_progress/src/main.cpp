/* Задание 
Вот задание:
Есть последовательность идентификаторов, строящаяся по следующим правилам:
1. Первый идентификатор последовательности имеет вид «A1», второй — «A2», третий - «A3» и так далее. За «A9» следует «B1».
Следующий после «Z9» имеет вид «A1-A1», потом «A1-A2» и так далее. После «A1-Z9» следует «A2-A1».
2. Максимальная длина идентификатора - десять групп по два символа.
3. В идентификаторах никогда не должны присутствовать буквы «D», «F», «G», «J», «M», «Q», «V» и цифра «0».
Необходимо реализовать класс, обеспечивающий работу с идентификатором по заданным правилам.
Класс должен обладать следующим функционалом:
• Метод, устанавливающий текущее значение идентификатора
• Метод, инкрементирующий значение идентификатора и возвращающий новое значение
Технические требования к решению:
1. Код должен быть потокобезопасным.
2. Код должен компилироваться.
3. Код должен быть кроссплатформенным (успешно собираться компиляторами msvc/gcc/clang).
4. Для решения задачи разрешается использовать только стандартную библиотеку С++(стандарт до C++17 включительно).
*/
#include <iostream>
#include <vector>
#include <string>

#include "main.h"
#include "identificator.h"

using namespace std;

int main()
{
    string test("Z9-Z9");
    IDENTTIFICATOR::Identificator id;
    for(int i = 0; i < 294120; ++i)
        cout << i << " : " << id.incrID() << ", num = " << id.getNum() << endl;
    cout << id.incrID() << endl;
    cout << id.calcIdent(test) << endl;
    cout << id.getID() << endl;

return 0;
}

