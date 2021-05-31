#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите строки:"<<endl;
    char s[100];
    char s2[256];
    char str[] = "%s";

    char st1[] = "%d\n";
  

    _asm {
        //вводим первую строку
        lea esi, s
        push esi
        lea ecx, str
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi
        //вводим вторую строку
        lea esi, s2
        push esi
        lea ecx, str
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi
        //Поиск подстроки
        lea ebx, s
        dec ebx
        lea ecx, s2
        b1 :
        inc ebx
            mov al, [ebx]
            cmp al, 0
            je b5
            cmp al, [ecx]
            jnz b1
            mov edx, ebx
            b2 :
        inc ebx
            inc ecx
            mov al, [ebx]
            cmp al, 0
            je b3
            mov al, [ecx]
            cmp al, 0
            je b4
            cmp al, [ebx]
            je b2
            mov ebx, edx
            lea ecx, s2
            jmp b1
            b3 :
        mov al, [ecx]
            cmp al, 0
            jne b5
            b4 :
        lea ebx, s
            add ebx, -1
            sub edx, ebx
            push edx
            jmp b6
            //Вывод результата
            b5 :
        mov ebx, -1
            push ebx
            b6 :
        lea ebx, st1
            push ebx
            call printf
            add esp, 8
    }

}

