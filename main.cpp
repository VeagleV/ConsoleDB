#include <iostream>
#include <cstring>
using namespace std;


void menu(bool isAdmin)
{
    if(isAdmin==true)
    {
        printf("//////////////////////////////////////////////////\n");
        printf("// %47s \n","//");
        printf("// %47s \n","//");
        printf("//%27s %24s \n","МЕНЮ","//");
        printf("//%41s %20s\n","1. Вывести таблицу","//");
        printf("//%53s %14s \n","2. Отсортировать таблицу","//");
        printf("//%53s %14s\n","3. Редактировать таблицу","//");
        printf("//%54s %12s\n","4. Вывести таблицу в файл ", "//");
        printf("//%22s %30s\n","5. Выйти","//");
        printf("// %47s \n","//");
        printf("// %47s \n","//");
        printf("//////////////////////////////////////////////////\n");
    } else {
        printf("//////////////////////////////////////////////////\n");
        printf("// %47s \n","//");
        printf("// %47s \n","//");
        printf("//%27s %24s \n","МЕНЮ","//");
        printf("//%41s %20s\n","1. Вывести таблицу","//");
        printf("//%53s %14s \n","2. Отсортировать таблицу","//");
        printf("//%54s %12s\n","3. Вывести таблицу в файл ", "//");
        printf("//%22s %30s\n","4. Выйти","//");
        printf("// %47s \n","//");
        printf("// %47s \n","//");
        printf("//////////////////////////////////////////////////\n");

    }
    
}

int getMenuChoice(bool isAdmin){
    int choice;

    cin >> choice;
    if(isAdmin==true){
    while(choice>0 && choice<6){
        
    }
    }
}
bool login(){
    bool isAdmin;
    char login[16];
    char password[16];
    char admLogin[16]{"admin"};
    char admPassword[16]{"admin"};
    int equal;

    printf("%30s\n","ВХОД В СИСТЕМУ");
    cout << "\nВведите логин:";
    cin.getline(login,16);
    cout << "\nВведите пароль:";
    cin.getline(password,16);
    equal = strcmp(login,admLogin) + strcmp(password,admPassword);
    if (equal == 0){
        return true;
    } else {
        return false;
    };



}
int main(){
    
    setlocale(LC_ALL,"Russian");
    menu(login());
    return 0;
}