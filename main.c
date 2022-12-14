#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <MMsystem.h>
#include <time.h>
#include <string.h>

#include "header.h"
#include "UI.h"
#include "body.h"

int main()
{
    int opsi, i = 1;
    UITitle(); // Tampilan awal,
    scanf("%d", &opsi);
    switch (opsi)
    {
        
    case 1:
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // Enter
        InputNama(&p1, i);
        i++;
        InputNama(&p2, i);
        system("cls");
        play();
        system("cls");
        break;
    case 2:
        system("cls");
        settings();
        break;
    case 0:
        system("cls");
        exit(0);
        break;
    default:
        system("cls");
        main();
        break;
    }
    return 0;
}