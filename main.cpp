#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#include <fstream>   // для работы с файлами (запись лога)
#include <ctime>     // для получения текущей даты и времени

using namespace std;

string getCurrentTime() // функция для получения текущей даты и времени
{
    time_t now = time(0);       // получаем текущее время в секундах
    tm* timeinfo = localtime(&now);  // превращаем в структуру с датой

    char buffer[30];  // массив для хранения строки времени
    // форматируем дату и время в нужном виде
    strftime(buffer, 30, "[%Y-%m-%d %H:%M:%S]", timeinfo);

    return string(buffer);  // возвращаем строку
}

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "");
    srand(clock());
    string username;
    int num = rand() % 998 + 1;

    ofstream logFile("game_log.txt", ios::app); // открываем файл

    cout << "Программа: угадай число.\n";
    cout << "Компьютер загадал число от 1 до 999. \n";
    cout << "Угадай его за минимальное число попыток. \n";

    logFile << getCurrentTime() << " Игра начата. Диапазон 1-999\n"; // запись начала

    int usernum;
    int count = 0;
    while (1)
    {
        do
        {
            cout << "Введите число: ";
            cin >> usernum;
            if (usernum < 1 || usernum > 999)
            {
                cout << "Число должно лежать в диапазоне от 1 до 999. Повторите ввод. \n";
            }
        } while (usernum < 1 || usernum > 999);
        count++;
        if (usernum > num)
        {
            cout << "Перелёт...\n";
            // запись перелета
            logFile << getCurrentTime() << " Введено: " << usernum << " (перелёт)\n";
        }
        else if (usernum < num)
        {
            cout << "Недолёт...\n";
            // запись недолета
            logFile << getCurrentTime() << " Введено: " << usernum << " (недолёт)\n";
        }
        else
        {
            cout << "Вы угадали число " << num <<
                " за " << count << " попыток.\n";
            // запись завершения игры
            logFile << getCurrentTime() << " Число " << num << " за " << count << " попытки\n";
            break;
        }
    }

    logFile.close(); // закрываем файл

}