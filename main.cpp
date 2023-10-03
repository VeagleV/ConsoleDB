#include <iostream>
using namespace std;


void menuOut(bool admin)
{
    if(admin==true)
    {
        printf("//////////////////////////////////////////////////\n");
        printf("// %47s \n","//");
        printf("// %47s \n","//");
        printf("//%27s %24s \n","МЕНЮ","//");
        printf("//%41s %20s\n","1. Вывести таблицу","//");
        printf("//%53s %14s\n","2. Редактировать таблицу","//");
        printf("//%49s %16s\n","3. Распечатать таблицу", "//");
        printf("//%73s %2s\n","4. Вывести таблицу в текстовый файл ", "//");
        printf("//%22s %30s\n","5. Выйти","//");
        printf("// %47s \n","//");
        printf("// %47s \n","//");
        printf("//////////////////////////////////////////////////\n");
    } else {


    }
    
}
int main(){
    
    setlocale(LC_ALL,"Russian");
    menuOut(true);

    return 0;
}