// LabNo10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <fstream>
using namespace std;

struct Student {
    char Name[100];
    char Group[100];
    int Ochenka[3];
};

float srball(Student a) {
    return (float) (a.Ochenka[0]+ a.Ochenka[1]+ a.Ochenka[2] )/ 3;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int vvod;
    Student list[100];
    int n = 0;
    char t[100];
    bool Flag = true;
    int jk = 0;

    ofstream lout;
    cout << "Номера команды: \n1. Добавлять элементов в конце списка\n2. Удалить студента по ФИО\n3. Вставить студента на указанную списку\n4. Отредактировать данные студента на указанные позиции\n5. Отсортировать студентов в списке по возрастанию среднего балла\n6. Вывести всех студентов указанной группы\n7. Очистить список\n8. Сохранить список в файл\n0. Выход из программ\n";
    while (Flag) {
        cout << "Введите номер команды: ";
        cin >> vvod;
        cin.getline(t, 100);
        switch (vvod) {
        case 1:
            cout << "Введите ФИО студента: ";
            cin.getline(list[n].Name, 100);
            cout << "Введите группу студента: ";
            cin.getline(list[n].Group, 100);
            cout << "Введите оценка по 3 предметам студента: ";
            for (int j = 0; j < 3; j++) {
                cin >> list[n].Ochenka[j];
            }
            cin.getline(t, 100);
            n++;
            break;
        case 2:
            cout << "Введите ФИО студента: ";
            cin.getline(t, 100);
            for (int i = 0; i < n; i++) {
                if (strcmp(t, list[i].Name) == 0) {
                    for (int j = i; j < n - 1; j++) {
                        list[j] = list[j + 1];
                    }
                    n--;
                    break;
                }
            }
            break;
        case 3:
            cout << "Введите номер от 1 до " << n << " включительно: ";
            cin >> jk;
            cin.getline(t, 100);
            Student pd = list[jk - 2];
            cout << "Введите ФИО студента: ";
            cin.getline(list[jk-2].Name, 100);
            cout << "Введите группу студента: ";
            cin.getline(list[jk-2].Group, 100);
            cout << "Введите оценка по 3 предметам студента: ";
            for (int j = 0; j < 3; j++) {
                cin >> list[jk-2].Ochenka[j];
            }
            cin.getline(t, 100);
            for (int i = n; i > jk-2; i--) {
                list[i] = list[i - 1];
            }
            list[jk-2] = pd;
            n++;
            break;
        case 5:
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    Student tp;
                    if (srball(list[i]) > srball(list[j])) {
                        tp = list[j];
                        list[j] = list[i];
                        list[i] = tp;
                    }
                }
            }
            break;
        case 6:
            cin.getline(t, 100);
            for (int i = 0; i < n; i++) {
                if (strcmp(t, list[i].Group) == 0) {
                    cout << "ФИО студента: " << list[i].Name << " - Группа студента: " << list[i].Group << " - Оценка по 3 предметам: " << srball(list[i]) << endl;
                }
            }
            break;
        case 7:
            n = 0;
            break;
        case 4:
            cout << "Введите номер от 1 до " << n <<" включительно: ";
            cin >> jk;
            cin.getline(t, 100);
            cout << "Введите ФИО студента: ";
            cin.getline(list[jk-1].Name, 100);
            cout << "Введите группу студента: ";
            cin.getline(list[jk-1].Group, 100);
            cout << "Введите оценка по 3 предметам студента: ";
            for (int j = 0; j < 3; j++) {
                cin >> list[jk-1].Ochenka[j];
            }
            
            break;
        case 8:
            cout << "Введите название файла: ";
            cin.getline(t, 100);
            lout.open(t);
            lout << n << endl;
            for (int i = 0; i < n; i++) {
                lout << list[i].Name << ";" << list[i].Group << ";" << list[i].Ochenka[0] << ";" << list[i].Ochenka[1] << ";" << list[i].Ochenka[2] << endl;
            }
            lout.close();
            cout << "Файл сохранён!";
            break;
        case 0:
            Flag = false;
            break;
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << i+1 << ") ФИО студента: " << list[i].Name << " - Группа студента: " << list[i].Group << " - Оценка по 3 предметам: " << srball(list[i]) << endl;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
