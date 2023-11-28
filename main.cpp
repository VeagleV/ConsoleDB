#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <unistd.h>
#include <stdlib.h>
#include <algorithm>
//#include <windows.h>
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
bool isLoggedIn;
int choice;
int baseSize = 10;
int credentialsCounter = 2;


// структура Студента
struct student{
    char surname[255];
    char birthdate[11];
    char group[15];
    char grade;
};

struct credentials{
    char login[16];
    char password[16];
};


//базовая БД студентов
student *baseOfStudents = new student[baseSize]{
    {"Пупкин  ","1.0.2005"," МК7-71Б", '4'},
    {"Зудин   ","21.7.2004 ","ИУК4-52Б",'3'},
    {"Фримен  ","8.3.2002"," МК8-31Б", '2'},
    {"Семёнов ","5.5.2005","ИУК4-12Б",'1'},
    {"Медведев","23.3.2001","ИУК4-12Б",'1'},
    {"Попова  ","29.12.2004","МК11-73Б",'4'},
    {"Смирнова","13.12.2002"," МК1-56Б",'3'},
    {"Иванова ","10.10.2005","ИУК5-31М",'2'},
    {"Иванов  ","7.6.2005","ИУК2-13М",'1'},
    {"Фёдорова","3.2.2006"," МК4-11Б",'2'},
};
    
credentials *baseOfLogins = new credentials[credentialsCounter]{};




bool compareStudent( student& a, student& b);
int getChoice(int maxnumber);
int loginFound(char login[16]);
void printMenu(bool isAdmin);
void sortTable();
void editTable();
void deleteElement(int id);
void saveTableAsFile();
void login();
void requestOut();
void signUp();
void viewTable();
void addElement();
void readFromFile(credentials credentials[], int& count);
void writeCredentialsToFile(const char* login, const char* password);
void save_students(char* file_name,  student* dataBaseOfStudent);

int main(){
    int variant;
    
    do
    {
        system("clear");
        readFromFile(baseOfLogins, credentialsCounter);
        login();
        do
        {        
            
            if(isLoggedIn == false){
                continue;
            }
            printMenu(isAdmin);
            
            variant = getChoice((5 + int(isAdmin)));
            switch (variant)
            {
            case 1:
                viewTable();
                break;
            case 2:
                requestOut();
                break;
            case 3:
                sortTable();
                break;
            case 4:
                if(isAdmin){
                    editTable();
                } else {
                    saveTableAsFile();
                }
                break;
            case 5:
                if(isAdmin){
                    saveTableAsFile();
                }
                break;
            
            default:
                cout <<"Такого пункта нет, попробуйте ещё раз: ";
            }
        }while (variant !=(5 + int(isAdmin)));
    }while(true);
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
        cout <<"//              2. Вывод таблицы по запросу     //\n";
        cout <<"//              3. Отсортировать таблицу        //\n";
        cout <<"//              4. Редактировать таблицу        //\n";
        cout <<"//              5. Вывести таблицу в файл       //\n";
        cout <<"//              6. Выйти                        //\n";
        cout <<"//                                              //\n";
        cout <<"//                                              //\n";
        cout <<"//////////////////////////////////////////////////\n";
    } else {
        cout <<"//////////////////////////////////////////////////\n";
        cout <<"//                                              //\n";
        cout <<"//                                              //\n";
        cout <<"//                       МЕНЮ                   //\n";
        cout <<"//              1. Вывести таблицу              //\n";
        cout <<"//              2. Вывод таблицы по запросу     //\n";
        cout <<"//              3. Отсортировать таблицу        //\n";
        cout <<"//              4. Вывести таблицу в файл       //\n";
        cout <<"//              5. Выйти                        //\n";
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
    system("clear");
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
    system("clear");
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
        addElement();
        break;
    case 2:
        /* code */
        break;
    case 3:
        cout << "Введите порядковый номер элемента, который хотите удалить: ";
        int id;
        cin >> id;
        deleteElement(id-1);
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
    system("clear");
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
            save_students("Students.txt",baseOfStudents);
        case 3:
            printMenu(isAdmin);
            break;
        default:
            break;
    }

}

//Функция входа в систему(ввод логина и пароля)
void login(){
    char login[17];
    char password[17];
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
    cout << "//  Добро пожаловать в Базу данных  студентов.   //\n";
    cout << "//                                               //\n";
    cout << "//                                               //\n";
    cout << "//         Для регистрации введите 1             //\n";
    cout << "//         Для авторизации введите 2             //\n";
    cout << "//         Для выхода из программы введите 3     //\n";
    cout << "//                                               //\n";
    cout << "//                                               //\n";
    cout << "//////////////////////////////////////////////////\n";
    choice = getChoice(3);
    
    if(choice == 1){
        signUp();
        isLoggedIn = false;
    } else {
        if(choice == 3){
            exit(2);
        }
        system("clear");
        cout <<"Введите логин(максимальное количество символов - 16):\n";
        cin.ignore();
        cin.getline(login,20);
        idOfLogin = loginFound(login);
        while(login[16] != '\0' && idOfLogin == -1){
            if(strlen(login)==0){
                cout<<"\nВы не ввели логин, попробуйте ещё раз:\n";
                cin.ignore();
                cin.getline(login,20);
            }
            if(strlen(login) > 16){
                cout <<"Логин слишком длинный, попробуйте ещё раз:\n";
                cin.ignore();
                cin.getline(login,20);
            }
            if(idOfLogin== -1){
                cout << "Логин не найден. Попробуйте ещё раз:\n";
                //cin.ignore();
                cin.getline(login,20);
            }
            idOfLogin = loginFound(login);
        };

        strcpy(requiredPassword, baseOfLogins[idOfLogin].password);
        do{
        cout << "\nВведите пароль, осталось попыток" << MAXNUMBEROFTRIES-counter << ":\n";
        //cin.ignore();
        cin.getline(password,20);
        counter++;
    }while((counter<MAXNUMBEROFTRIES) && (fabs(strcmp(password,requiredPassword))>0));
    //Выходим из программы если за 3 попытки не введён пароль
    if(counter>=MAXNUMBEROFTRIES){
        cout << "Пароль неверный, выход из программы";
        sleep(2);
        exit(2);
    }
    //Определяем явлеется ли пользователь администратором
    if(strcmp(login,ADMINLOGIN) + strcmp(password,ADMINPASSWORD) == 0){
        isAdmin = true;
    };
    isLoggedIn = true;
    }
}

//Функция регистрации
void signUp()
{
    char login[16];
    char password[16];
    int loginId = 0;
    system("clear");
    cout << "Введите ваш логин(максимальное количество символов - 16):\n";
    cin.ignore();
    cin.getline(login, 17);
    loginId = loginFound(login);

    while (!login[16] == '\0' && login[0] == '\0' && loginId == -1){
        if (login[16] == '\0')
        {
            cout << "Логин больше 16 символов, попробуйте ещё раз:\n";
        }
        if (login[0] == '\0')
        {
            cout << "Вы не ввели логин, попробуйте ещё раз: \n";
        }
        if(loginId == -1){
            cout << "Такой логин уже существует, попробуйте ещё раз:\n";
        }
        cin.getline(login, 18);
        loginId = loginFound(login);
    };

    cout << "Введите пароль(максимальная длинна - 16):\n";
    cin.getline(password, 18);
    while (!password[16] == '\0'){
        if (password[16] == '\0')
        {
            cout << "Пароль больше 16 символов, попробуйте ещё раз:\n";
        }
        if (password[0] == '\0')
        {
            cout << "Вы не ввели пароль, попробуйте ещё раз: \n";
        }
        cin.getline(password, 17);
    };
    writeCredentialsToFile(login,password);
}
//Функция вывода таблицы
void printTable() {
    //проверяем пуста ли таблица
    if (baseSize == 0) {
        cout << "Таблица студентов пуста\n";
        return;
    }

    // Выводим заголовки
    cout << left << setw(20) << "Фамилия"
         << left << setw(30) << "Дата рождения"
         << left << setw(15) << "Группа"
         << left << setw(9) << "Курс" << endl;

    // Выводим данные таблицы
    for (int i = 0; i < baseSize; i++) {
        student currentStudent = baseOfStudents[i];
        cout << left << setw(20) << currentStudent.surname
             << left << setw(12) << currentStudent.birthdate
             << left << setw(15) << currentStudent.group
             << left << setw(9) << currentStudent.grade << endl;
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
            return false;
        }
    }
    return false;
}

//Меню С таблицей
void viewTable(){
    char breakInput;
    system("clear");
    //Выводим таблицу
    while(breakInput != 'b'){
        printTable();
        cout << "Для возвращения в меню введите b\n";
        cin.ignore();
        breakInput = getchar();
    }

}
// Добавление нового студента
void addElement() {
    // добавляем студента
    baseOfStudents[baseSize] = student();
    student *newStudent = &baseOfStudents[baseSize];
    baseSize++;

    // Принимаем данные о студенте
    cout << "Введите Фамилию студента: ";
    cin.ignore();
    cin.getline(newStudent->surname, 256);

    int day, month, year, course;
    char group[7];
    char birthDate[11];
    cout << "Введите Дату рождения(в последовательности: день,месяц,год через пробел)";
    cin >> day >> month >> year;

    if (!isDateValid(day, month, year)) {
        cout << "Дата неверная, попробуйте ещё раз:\n";
        addElement();
        return;
    }
    sprintf(birthDate, "%d.%d.%d", day, month, year);
    cout << "Введите группу студента: ";
    cin.ignore();
    cin.getline(group, 14);
    cout << "Введите курс студента: ";
    cin >> course;
    // Добавляем данные студенту
    strcpy(newStudent->birthdate, birthDate);
    strcpy(newStudent->group, group);
    newStudent->grade = course;
}

//Удаление элемента
void deleteElement(int id) {
    if(id >= baseSize) {
        cout << "Индекс вне границ" << endl;
        return;
    }

    for(int i = id; i < baseSize - 1; i++) {
        baseOfStudents[i] = baseOfStudents[i + 1];
    }

    baseSize--;
    cout << "Элемент успешно удалён" << endl;
}


//Нахождения логина
int loginFound(char login[16]){

    for(int i = 0; i < credentialsCounter;i++){
        if(strcmp(login,baseOfLogins[i].login) == 0){
            return i;
        }
    }
    return -1;
}
//Запись реквезитов в файл
void writeCredentialsToFile(const char* login, const char* password) {
    ofstream file;

    //открываем файл
    file.open("Register.txt",ios_base::app); 

    if (file.is_open()) {
        file << login << "\n" << password << std::endl;
        file.close();
        cout << "Логин и пароль успешно сохранены" << std::endl;
    } else {
        cout << "Ошибка открытия файла." << std::endl;
    }
}

//считываем реквизиты с файла
void readFromFile(credentials credentials[], int& count) {
    ifstream file;
    file.open("Register.txt");

    if (file.is_open()) {
        char line[17];
        int index = 0;
        int i = 0;
        while (file.getline(line,16)) {
            if(index % 2 == 0){
                strcpy(credentials[i].login,line);
            } else {
                strcpy(credentials[i].password, line);
                i++;
            }
            index++;
        }
        count = index;
        file.close();
    } else {
        cout << "Ошибка в открытие файла." << endl;
    }
}

void save_students(char* file_name,  student* dataBaseOfStudent) {
    ofstream file;

    //Открываем файл
    file.open(file_name);

    // Сообщаем об ошибки если таковая имеется
    if (!file.is_open()) {
        cout <<"Файл не удалось открыть";
    }

    // Записываем данные студента в файл.
    for (int i = 0; i <baseSize; i++) {
        file << dataBaseOfStudent[i].surname << "," 
             << dataBaseOfStudent[i].birthdate << "," 
             << dataBaseOfStudent[i].group << "," 
             << dataBaseOfStudent[i].grade<< std::endl;
    }
}

//вывод информации по запросу(сортировка по группе)
void requestOut(){
    char breakInput;

    system("clear");
    //сортируем
    sort(baseOfStudents,baseOfStudents+baseSize, compareStudent);
    
    
    while(breakInput != 'b'){
        printTable();
        cout << "Для возвращения в меню введите b\n";
        cin.ignore();
        breakInput = getchar();
    }

}

//компаратор для функции requestOut()
bool compareStudent( student& a,  student& b) {
    return strcmp(a.group, b.group) < 0;
}


