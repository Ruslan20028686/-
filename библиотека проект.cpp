#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Класс книжного магазина
class bookshope {
public:
    void control_panel();
    void add_book();
    void show_book();
    void check_book();
    void update_book();
    void del_book();
};

// Функция для отображения меню
void bookshope::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t\tПАНЕЛЬ УПРАВЛЕНИЯ";
    cout << "\n\n1. ДОБАВИТЬ КНИГУ";
    cout << "\n2. ПОКАЗАТЬ ВСЕ КНИГИ";
    cout << "\n3. ПРОВЕРИТЬ КОНКРЕТНУЮ КНИГУ";
    cout << "\n4. ОБНОВИТЬ ДАННЫЕ КНИГИ";
    cout << "\n5. УДАЛИТЬ КНИГУ";
    cout << "\n6. ВЫЙТИ";
}

// Функция для добавления книги
void bookshope::add_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, a_name, b_id;
    cout << "\n\n\t\t\t\tДОБАВЛЕНИЕ КНИГИ";
    cout << "\n\nID Книги: ";
    cin >> b_id;
    cout << "\nНазвание книги: ";
    cin >> b_name;
    cout << "\nИмя автора: ";
    cin >> a_name;
    cout << "\nКоличество экземпляров: ";
    cin >> no_copy;

    // Открытие файла для добавления данных
    file.open("D:// book.txt", ios::out | ios::app);
    file << " " << b_id << " " << b_name << " " << a_name << " " << no_copy << "\n";
    file.close();
}

// Функция для отображения книг
void bookshope::show_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, b_id, a_name;
    cout << "\n\n\t\t\t\t\tВСЕ КНИГИ";

    // Открытие файла для чтения
    file.open("D:// book.txt", ios::in);
    if (!file)
        cout << "\n\nОшибка при открытии файла!";
    else {
        cout << "\n\n\nID Книги\t\tНазвание\t\tАвтор\t\tКоличество\n\n";
        file >> b_id >> b_name >> a_name >> no_copy;

        // Чтение данных до конца файла
        while (!file.eof()) {
            cout << "  " << b_id << "\t\t" << b_name << "\t\t" << a_name << "\t\t" << no_copy << "\n\n";
            file >> b_id >> b_name >> a_name >> no_copy;
        }

        system("pause");

        // Закрытие файла
        file.close();
    }
}

// Функция для проверки наличия книги
void bookshope::check_book()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string b_id, b_name, a_name, b_idd;

    cout << "\n\n\t\t\t\tПРОВЕРКА КОНКРЕТНОЙ КНИГИ";

    // Открытие файла для чтения
    file.open("D:// book.txt", ios::in);
    if (!file)
        cout << "\n\nОшибка при открытии файла!";
    else {
        cout << "\n\nID Книги: ";
        cin >> b_idd;
        file >> b_id >> b_name >> a_name >> no_copy;

        while (!file.eof()) {
            if (b_idd == b_id) {
                system("cls");
                cout << "\n\n\t\t\t\tПРОВЕРКА КОНКРЕТНОЙ КНИГИ";
                cout << "\n\nID Книги: " << b_id;
                cout << "\nНазвание: " << b_name;
                cout << "\nАвтор: " << a_name;
                cout << "\nКоличество экземпляров: " << no_copy;
                cout << endl << endl;
                count++;
                break;
            }
            file >> b_id >> b_name >> a_name >> no_copy;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nКнига с данным ID не найдена...";
    }
}
// Остальные функции аналогично перевести:
// Функция для обновления данных книги
void bookshope::update_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string b_name, b_na, a_name;
    string a_na, b_idd, b_id;

    cout << "\n\n\t\t\t\tОБНОВЛЕНИЕ ЗАПИСИ О КНИГЕ";
    file1.open("D:// book1.txt", ios::app | ios::out);
    file.open("D:// book.txt", ios::in);

    if (!file)
        cout << "\n\nОшибка при открытии файла!";
    else {
        cout << "\n\nID Книги: ";
        cin >> b_id;
        file >> b_idd >> b_name >> a_name >> no_copy;

        // Чтение данных до конца файла
        while (!file.eof()) {
            if (b_id == b_idd) {
                system("cls");
                cout << "\t\t\t\tОБНОВЛЕНИЕ ЗАПИСИ О КНИГЕ";
                cout << "\n\nНовое название книги: ";
                cin >> b_na;
                cout << "\nНовое имя автора: ";
                cin >> a_na;
                cout << "\nНовое количество экземпляров: ";
                cin >> no_co;
                file1 << " " << b_id << " " << b_na << " " << a_na << " " << no_co << "\n\n";
                count++;
            }
            else {
                file1 << " " << b_idd << " " << b_name << " " << a_name << " " << no_copy << "\n\n";
            }
            file >> b_idd >> b_name >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nКнига с данным ID не найдена...";
    }
    cout << endl;
    system("pause");

    // Закрытие файлов
    file.close();
    file1.close();
    remove("D:// book.txt");
    rename("D:// book1.txt", "D:// book.txt");
}
// Функция для удаления книги
void bookshope::del_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string b_id, b_idd, b_name, a_name;

    cout << "\n\n\t\t\t\tУДАЛЕНИЕ КНИГИ";

    // Открытие файла для записи
    file1.open("D:// book1.txt", ios::app | ios::out);
    file.open("D:// book.txt", ios::in);

    if (!file)
        cout << "\n\nОшибка при открытии файла...";
    else {
        cout << "\n\nID Книги: ";
        cin >> b_id;
        file >> b_idd >> b_name >> a_name >> no_copy;

        while (!file.eof()) {
            if (b_id == b_idd) {
                system("cls");
                cout << "\n\n\t\t\t\tУДАЛЕНИЕ КНИГИ";
                cout << "\n\nКнига успешно удалена...\n\n";
                count++;
            }
            else {
                file1 << " " << b_idd << " " << b_name << " " << a_name << " " << no_copy << "\n\n";
            }
            file >> b_idd >> b_name >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nКнига с данным ID не найдена...";
    }
    system("pause");

    // Закрытие файлов
    file.close();
    file1.close();
    remove("D:// book.txt");
    rename("D:// book1.txt", "D:// book.txt");
}
// Функция для управления записями книжного магазина
void bookShopRecord()
{
    int choice;
    char x;
    bookshope b;

    while (1) {
        b.control_panel();
        cout << "\n\nВведите ваш выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
            do {
                b.add_book();
                cout << "\n\nХотите добавить ещё одну книгу? (y/n): ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.show_book();
            break;

        case 3:
            b.check_book();
            break;

        case 4:
            b.update_book();
            break;

        case 5:
            b.del_book();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\n\nНеверный выбор!\n";
        }
    }
}
// Главная функция
int main()
{
    setlocale(LC_ALL, "RUS");
    // Вызов функции управления книжным магазином
    bookShopRecord();

    return 0;
}
