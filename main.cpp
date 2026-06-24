#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "");
    srand(clock());
    string username;
    int num = rand() % 998 + 1;
    cout << "Программа: угадай число.\n";
    cout << "Компьютер загадал число от 1 до 999. \n";
    cout << "Угадай его за минимальное число попыток. \n";
    int usernum;
    int count = 0;
    while (1) {
        do
        {
            cout << "Введите число: ";
            cin >> usernum;
            if (usernum < 1 || usernum > 999) {
                cout << "Число должно лежать в диапазоне от 1 до 999. Повторите ввод. \n";
            }
        } while (usernum < 1 || usernum > 999);
        count++;
        if (usernum > num) {
            cout << "Перелёт...\n";
        }
        else if (usernum < num) {
            cout << "Недолёт...\n";
        }
        else {
            cout << "Вы угадали число " << num <<
                " за " << count << " попыток.\n";
            break;
        }
    }
}