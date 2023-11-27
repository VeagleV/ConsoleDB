#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
using namespace std;




//TODO: Возврат до меню регистрации 
//TODO: Регистрация и сохранение БД ПОЛЬЗОВАТЕЛЕЙ В ФАЙЛЕ
//TODO: Сохранение БД студентов в файле
//TODO: Фикс вывода таблицы
//TODO: Добавление перс задания как пункт меню
//TODO: вынос всех функций в хедер\срр файл
//TODO: фикс ввода нуля
bool isAdmin;
int choice;
int baseSize = 10;
int registrationCounter = 2;

//структура дня рождения
struct dateOfBirth{
    char day[4];
    char month[4];
    char year[5];
};
// структура Студента
struct student{
    char surname[255];
    dateOfBirth birth;
    char group[15];
    char grade;
};

struct registration{
    char login[16];
    char password[16];
};


//базовая БД студентов
student *baseOfStudents = new student[baseSize]{
    {"Пупкин  ",{"01","01","2005"}," МК7-71Б", '4'},
    {"Зудин   ",{"21","07","2004"},"ИУК4-52Б",'3'},
    {"Фримен  ",{"08","03","2002"}," МК8-31Б", '2'},
    {"Семёнов ",{"05","05","2005"},"ИУК4-12Б",'1'},
    {"Медведев",{"23","03","2001"},"ИУК4-12Б",'1'},
    {"Попова  ",{"29","12","2004"},"МК11-73Б",'4'},
    {"Смирнова",{"13","12","2002"}," МК1-56Б",'3'},
    {"Иванова ",{"10","10","2005"},"ИУК5-31М",'2'},
    {"Иванов  ",{"07","06","2005"},"ИУК2-13М",'1'},
    {"Фёдорова",{"03","02","2006"}," МК4-11Б",'2'},
};
    
registration *baseOfLogins = new registration[registrationCounter]{};




void printMenu(bool isAdmin);
int getChoice(int maxnumber);
void sortTable();
void editTable();
void saveTableAsFile();
bool login();
void signUp();
void viewTable();
int loginIsFound(char login[16]);



int main(){
    int variant;
    setlocale(LC_ALL,"Russian");
    
    do
    {
        ////system("cls");
        isAdmin = login();
        printMenu(isAdmin);
        
        variant = getChoice((4 + int(isAdmin)));
        switch (variant)
        {
        case 1:
            viewTable();
            break;
        case 2:
            sortTable();
            break;
        case 3:
            if(isAdmin){
                editTable();
            } else {
                saveTableAsFile();
            }
            break;
        case 4:
            if(isAdmin){
                saveTableAsFile();
            }
            break;
        
        default:
            cout <<"Такого пункта нет, попробуйте ещё раз: ";
        }
    } while (variant !=(4 + int(isAdmin)));

    return 0;

}
//Функция вывода меню
void printMenu(bool isAdmin){
    //вывод меню в зависимости от того, пользователь является администратором или же нет
    if(isAdmin)
    {
        cout <<"//////////////////////////////////////////////////\n";
        cout <<"//                                              //\n";
        cout <<"//                                              //\n";
        cout <<"//                       МЕНЮ                   //\n";
        cout <<"//              1. Вывести таблицу              //\n";
        cout <<"//              2. Отсортировать таблицу        //\n";
        cout <<"//              3. Редактировать таблицу        //\n";
        cout <<"//              4. Вывести таблицу в файл       //\n";
        cout <<"//              5. Выйти                        //\n";
        cout <<"//                                              //\n";
        cout <<"//                                              //\n";
        cout <<"//////////////////////////////////////////////////\n";
    } else {
        cout <<"//////////////////////////////////////////////////\n";
        cout <<"//                                              //\n";
        cout <<"//                                              //\n";
        cout <<"//                       МЕНЮ                   //\n";
        cout <<"//              1. Вывести таблицу              //\n";
        cout <<"//              2. Отсортировать таблицу        //\n";
        cout <<"//              3. Вывести таблицу в файл       //\n";
        cout <<"//              4. Выйти                        //\n";
        cout <<"//                                              //\n";
        cout <<"//                                              //\n";
        cout <<"//////////////////////////////////////////////////\n";

    }
    
}
//функция, которая проверяет правильность ввода и возвращает пункт меню
int getChoice(int maxnumber){
    
    char input[255]{};
    cout << "Введите желаемый пункт: ";
    cin >> input;
    sscanf(input,"%d",&choice);
    //проверяем ввод на корректность
    while(choice <= 0 || choice > maxnumber || input[1] != '\0'){
        cout <<"Неверный ввод, попробуйте ещё раз: ";
        cin >> input;
        sscanf(input,"%d",&choice);
    }
    return choice;
}

//Меню сортировки таблицы
void sortTable(){
    ////system("cls");
    cout <<"////////////////////////////////////////////////////////\n";
    cout <<"//      По какому свойству желаете отсортировать?     //\n";
    cout <<"//                                                    //\n";
    cout <<"//      1. Фамилия(От А до Я)                         //\n";
    cout <<"//      2. Фамилия(От Я до А)                         //\n";
    cout <<"//      3. По дате рождения(по возрастанию возраста)  //\n";
    cout <<"//      4. По дате рождения(по убыванию возраста)     //\n";
    cout <<"//      5. По группе(От А до Я)                       //\n";
    cout <<"//      6. По группе(От Я до А)                       //\n";
    cout <<"//      7. По курсу(по возрастанию)                   //\n";
    cout <<"//      8. По курсу(по убыванию)                      //\n";
    cout <<"//      9. Вернуться назад                            //\n";
    cout <<"//                                                    //\n";
    cout <<"////////////////////////////////////////////////////////\n";
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
//Меню редактирования таблицы
void editTable(){
    ////system("cls");
    cout <<"\n";
    cout <<"\n";
    cout <<"////////////////////////////////////////////////////////\n";
    cout <<"//          Что конкретно вы хотите сделать?          //\n";
    cout <<"//                                                    //\n";
    cout <<"//      1. Добавить элемент                           //\n";
    cout <<"//      2. Редактировать элемент                      //\n";
    cout <<"//      3. Удалить элемент                            //\n";
    cout <<"//      4. Вернуться назад                            //\n";
    cout <<"//                                                    //\n";
    cout <<"////////////////////////////////////////////////////////\n";
    choice = getChoice(4);
    switch (choice){
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

//Меню сохранения таблицы в бинарный / текстовый файл
void saveTableAsFile(){
    ////system("cls");
    cout << "////////////////////////////////////////////////////\n";
    cout << "//   В какой  файл вы хотите сохранить таблицу?   //\n";
    cout << "//                                                //\n";
    cout << "//                                                //\n";
    cout << "//             1, В бинарный                      //\n";
    cout << "//             2. В текстовый                     //\n";
    cout << "//             3. Вернутся в меню                 //\n";
    cout << "//                                                //\n";
    cout << "////////////////////////////////////////////////////\n";
    choice = getChoice(3);
    switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            printMenu(isAdmin);
            break;
        default:
            break;
    }

}

//Функция входа в систему(ввод логина и пароля)
bool login(){
    char login[16];
    char password[16];
    char requiredPassword[16];
    char const ADMINLOGIN[16]{"admin"}; // логин администратора
    char const ADMINPASSWORD[16]{"admin"}; //пароль администратора
    int loggedAsAdmin;
    int counter;
    int idOfLogin;
    int choice;
    int const MAXNUMBEROFTRIES = 3; //Максимальное количество попыток для ввода пароля  

    


    cout << "///////////////////////////////////////////////////\n";
    cout << "//                                               //\n";
    cout << "//  Добро пожаловать в Базу данных о студентах.  //\n";
    cout << "//                                               //\n";
    cout << "//                                               //\n";
    cout << "//         Для регистрации введите 1             //\n";
    cout << "//          Для авторизации введите 2            //\n";
    cout << "//                                               //\n";
    cout << "//                                               //\n";
    cout << "//                                               //\n";
    cout << "//////////////////////////////////////////////////\n";
    choice = getChoice(2);
    
    if(choice == 1){
        signUp();
    } else {
        //////system("cls");
        cout <<"Введите логин(максимальное количество символов - 16):";
        do{
            cin.getline(login,17);
            if(login[0] == '\0'){
                cout<<"\nВы не ввели логин, попробуйте ещё раз.";
            }
            if(login[16] != '\0'){
                cout <<"\n Логин слишком длинный, попробуйте ещё раз";
            }
            if(idOfLogin== -1){
                cout << "Логин не найден. Попробуйте ещё раз.";
            }
            idOfLogin = loginIsFound(login);
        }while(login[16] != '\0' && idOfLogin == -1);

        strcpy_s(requiredPassword,16, baseOfLogins[idOfLogin].password);
    }
    //Проверяем введённый пароль на соответствие с паролем администратора, если введён логин администратора
   
    do{
        cout << "\nВведите пароль, осталось попыток " << MAXNUMBEROFTRIES-counter << ":";
        cin.getline(password,1000);
        counter++;
        bool a = counter<MAXNUMBEROFTRIES;
    }while((counter<MAXNUMBEROFTRIES) && (fabs(strcmp(password,ADMINPASSWORD))>0));
    
    //Выходим из программы если за 3 попытки не введён пароль администратора
    if(counter>=MAXNUMBEROFTRIES){
        cout << "Пароль неверный, выход из программы";
        sleep(2);
        exit(2);
    }
    //Определяем явлеется ли пользователь администратором
    loggedAsAdmin = strcmp(login,ADMINLOGIN)+ strcmp(password,ADMINPASSWORD);
    if (loggedAsAdmin == 0){
        return true;
    } else {
        return false;
    };
}
void signUp()
{
    char login[16];
    char password[16];
    ////system("cls");
    cout << "Введите ваш логин(максимальное количество символов - 16): ";
    cin.getline(login, 18);
    do
    {
        if (login[16] == '\0')
        {
            cout << "Логин больше 16 символов, попробуйте ещё раз:";
        }
        if (login[0] == '\0')
        {
            cout << "Вы не ввели логин, попробуйте ещё раз: ";
        }
        cin.getline(login, 18);
    } while (!login[16] == '\0');

    cout << "Введите пароль(максимальная длинна - 16)";
    cin.getline(password, 18);
    do
    {
        if (password[16] == '\0')
        {
            cout << "Пароль больше 16 символов, попробуйте ещё раз:";
        }
        if (password[0] == '\0')
        {
            cout << "Вы не ввели пароль, попробуйте ещё раз: ";
        }
        cin.getline(password, 18);
    } while (!password[16] == '\0');

}
//Функция вывода таблицы
void printTable(){
    int number = 0;
    ////system("cls");

    cout << "+-+--------------------+---------------+--------+----+\n";
    cout << "|№|      Фамилия        | Дата рождения | Группа |Курс|\n";
    cout << "+-+--------------------+---------------+--------+----+\n";
    for(int i = 0; i < baseSize;i++ ){
        cout << "|"<< number << "|";
        cout << setw(12) << left << baseOfStudents[i].surname <<  "|";
        cout << setw(3) << left <<  baseOfStudents[i].birth.day << "." << baseOfStudents[i].birth.month << "." << baseOfStudents[i].birth.year << "|" ;
        cout << setw(5) << left <<  baseOfStudents[i].group<< "|" ;
        cout << setw(2) << left <<  baseOfStudents[i].grade<< "|" << endl;
        cout << "+-+--------------------+---------------+------------+------+\n";
        number++;
        }
}

bool isDateValid(int day,int month, int year){
    if(1960 <= year <= 2019){
        if((month==1 || month==3 || month==5|| month==7|| month==8||month==10||month==12) && day>0 && day<=31){
            return true;
         }else if(month==4 || month==6 || month==9|| month==11 && day>0 && day<=30){
            return true;
         }
         else if(month==2){
            if((year%400==0 || (year%100!=0 && year%4==0)) && day>0 && day<=29){
                return true;
                } else if(day>0 && day<=28){
                    return true;
                }else{
                  return false;
               }
        }
        else{
            return true;
        }
    }
    return false;
}
void addElement(){
    student *newStudent = baseOfStudents;
    printTable();
    int day;
    char cDay[3];
    int month;
    char cMonth[3];
    int year;
    char cYear[5];
    char surname[254];

    newStudent += baseSize-1;
    cout<<"Введите Фамилию студента: ";
    cin.getline(surname,99);
    cout << "Введите Дату рождения(в последовательности: день,месяц,год через пробел)";
    do{
    cin >>day>>month>>year;
    if(!isDateValid(day,month,year)){
        cout<<"Дата неверная";
    }
    }
    while(!isDateValid(day,month,year));
    strcpy(newStudent->surname, surname);
    strcpy(newStudent->birth.day, (char*)(to_wstring(day).c_str()));
    strcpy(newStudent->birth.month, (char*)(to_wstring(month).c_str()));
    strcpy(newStudent->birth.year,(char*)(to_wstring(year).c_str()));
}
//Меню С таблицей
void viewTable(){
    char breakInput;
    
    //Выводим таблицу
    while(breakInput != 'b'){
        printTable();
        cout << "Для возвращения в меню введите b\n";
        breakInput = getchar();
    }

}
//Функция расширения массива базы данных
void realloc(){
    baseSize++;
    student* temp = new student[baseSize];
    copy(baseOfStudents,baseOfStudents + baseSize,temp);
    delete [] baseOfStudents;
    baseOfStudents = temp;
}

int loginIsFound(char login[16]){

    for(int i = 0; i < registrationCounter;i++){
        if(strcmp(login,baseOfLogins[i].login)== 0){
            return i;
        }
    }
    return -1;
}
void readLoginData(char *baseOfLogins)
{
    ifstream fileInput("Register.txt");
    char inputBuffer[40];
    int count = 0;

    if (fileInput.is_open())
    {
        while (fileInput.getline(inputBuffer, 40))
        {
            char* token = strtok(inputBuffer, ":");
            while (token != nullptr && count < registrationCounter)
            {
                strcpy(baseOfLogins[count].login, token);
                baseOfLogins[count].login[15] = '\0'; // Убедимся, что строка завершена
                token = strtok(nullptr, ":");
            if (token != nullptr)
            {
                strcpy(baseOfLogins[count].password, token);
                baseOfLogins[count].password[15] = '\0'; // Убедимся, что строка завершена
                token = strtok(nullptr, ":");
                count++;
                registrationCounter++;
            }
            }
        }
    fileInput.close();
    }ф
}