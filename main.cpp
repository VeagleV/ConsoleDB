#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;


void printMenu(bool isAdmin)
{
    system("clear");
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
void showTable(){   
    
    printf("Тут должна быть табличка");
    sleep(2);
}
void sortTable(){
    
    printf("А тут сортировка");
    sleep(2);
}
void editTable(){
    printf("А тут всё редактируется");
    sleep(2);
}
void savetableAsFile(){
    
    printf("Здесь сохраняться");
    sleep(2);
}

int getMenuChoice(bool isAdmin){
    int choice;
    char in[100];
    cout << "Введите желаемый раздел меню: ";
    cin >> in;
     
    while(sscanf(in,"%d",&choice)!= 1 ||(choice<0 || choice>(4 + int(isAdmin))) ){
        cout <<"Неверный ввод, попробуйте ещё раз: ";
        cin >> choice;
    }
    return choice;
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
    int variant;
    bool isAdmin;
    setlocale(LC_ALL,"Russian");
    isAdmin = login();
    do
    {
        printMenu(isAdmin);
        variant = getMenuChoice(isAdmin);
        switch (variant)
        {
        case 1:
            showTable();
            break;
        case 2:
            sortTable();
            break;
        case 3:
            if(isAdmin==true){
                editTable();
            } else {
                savetableAsFile();
            }
            break;
        case 4:
            if(isAdmin==true){
                savetableAsFile();
            }
            break;
        }
       
    } while (variant !=(4 + int(isAdmin)));
    
    return 0;
}