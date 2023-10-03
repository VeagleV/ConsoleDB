#include <iostream>
#include <cstring>
using namespace std;

bool isAdmin;
int choice;


void printMenu(bool isAdmin)
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

int getChoice(int maxnumber){
    
    char in[100];
    cout << "Введите желаемый пункт: ";
    cin >> in;
    sscanf(in,"%d",&choice);

    while((choice < 0 || choice > maxnumber) ){
        cout <<"Неверный ввод, попробуйте ещё раз: ";
        cin >> choice;
        cout << choice; // пофиксить через поток cin(ignore, get и т д)
    }
    return choice;
}


void showTable(){   
  
    printf("+--------------------+----------------------+----------+-------+\n");
    printf("|      Фамилия       |     Дата рождения    |  Группа  |  Курс |\n");
    printf("+--------------------+----------------------+----------+-------+\n");

}
void sortTable(){
    system("clear");
    printf("////////////////////////////////////////////////////////\n");
    printf("//      По какому свойству желаете отсортировать?     //\n");
    printf("//                                                    //\n");
    printf("//      1. Фамилия(От А до Я)                         //\n");
    printf("//      2. Фамилия(От Я до А)                         //\n");
    printf("//      3. По дате рождения(по возрастанию возраста)  //\n");
    printf("//      4. По дате рождения(по убыванию возраста)     //\n");
    printf("//      5. По группе(От А до Я)                       //\n");
    printf("//      6. По группе(От Я до А)                       //\n");
    printf("//      7. По курсу(по возрастанию)                   //\n");
    printf("//      8. По курсу(по убыванию)                      //\n");
    printf("//      9. Вернуться назад                            //\n");
    printf("//                                                    //\n");
    printf("////////////////////////////////////////////////////////\n");
    choice = getChoice(9);
    switch (choice)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    case 9:
        printMenu(isAdmin);
        break;
    default:
        break;
    }
}
void editTable(){
    showTable();
    printf("\n");
    printf("\n");
    printf("////////////////////////////////////////////////////////\n");
    printf("//          Что конкретно вы хотите сделать?          //\n");
    printf("//                                                    //\n");
    printf("//      1. Добавить элемент                           //\n");
    printf("//      2. Редактировать элемент                      //\n");
    printf("//      3. Удалить элемент                            //\n");
    printf("//      4. Вернуться назад                            //\n");
    printf("//                                                    //\n");
    printf("////////////////////////////////////////////////////////\n");
    choice = getChoice(4);
    switch (choice)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        printMenu(isAdmin);
        break;
    default:
        break;
    }
}
void savetableAsFile(){
    cout << "Здесь сохраняться";
    printf("Здесь сохраняться");
    system("clear");
}

bool login(){
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
    setlocale(LC_ALL,"Russian");
    
    isAdmin = login();
    do
    {
        system("clear");
        printMenu(isAdmin);
        variant = getChoice((4 + int(isAdmin)));
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