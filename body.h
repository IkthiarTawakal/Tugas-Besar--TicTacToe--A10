void play()
{
   char winner = ' ';
   int papan;
   UILevel(); // Pilihan level
   scanf("%d", &papan);
   switch (papan)
   {
   case 1:
      papan = 3;
      break;
   case 2:
      papan = 5;
      break;
   case 3:
      papan = 7;
      break;
   default:
      system("cls");
      play();
      break;
   }
   system("cls");
   ResetBoard(papan);
   while (winner == ' ' && CekKosong(papan) != 0)
   {
      CetakPapan(papan);
      P1Turn(papan);
      winner = checkWinner(papan);
      system("cls");
      if (winner != ' ' || CekKosong(papan) == 0)
      {
         break;
      }
      CetakPapan(papan);
      P2Turn(papan);
      winner = checkWinner(papan);
      system("cls");
      if (winner != ' ' || CekKosong(papan) == 0)
      {
         break;
      }
   }
   PrintWinner(winner);
   system("cls");
   MainLagi();
}

void InputNama(Player *p, int i)
{
UlangInputNama:
   printf("\n\n\t\t\t\t\t\t\t\t\t\t\tInput Nama Pemain %d: ", i);
   scanf(" %[^\n]", &p->nama);
   if (strlen(p->nama) > 20)
   {
      goto UlangInputNama;
   }
}

void ResetBoard(int a)
{
   for (int i = 0; i < a; i++)
   {
      for (int j = 0; j < a; j++)
      {
         board[i][j] = ' ';
      }
   }
}

int CekKosong(int a)
{
   int freeSpaces = pow(a, 2);

   for (int i = 0; i < a; i++)
   {
      for (int j = 0; j < a; j++)
      {
         if (board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}

void P1Turn(int papan)
{
   waktusebelum = time(NULL);
P1Turn:
   printf("\t\t\t\t\t\t\t\t\t\t\t%s's turn!\n\n\t\t\t\t\t\t\t\t\t\t\tMasukkan (baris,kolom): ", p1.nama);
   InputXY(&pl1);
   waktusesudah = time(NULL);
   if (waktusesudah - waktusebelum >= 10)
   {
      system("cls");
      UITimesUp();
      getch();
   }
   else if (pl1.x > papan || pl1.y > papan)
   {
      printf("\t\t\t\t\t\t\t\t\t\t\tInvalid move!\n");
      getch();
      goto P1Turn;
   }
   else if (pl1.batas != ',' || board[pl1.x][pl1.y] != ' ')
   {
      printf("\t\t\t\t\t\t\t\t\t\t\tInvalid move!\n");
      getch();
      goto P1Turn;
   }
   else
   {
      board[pl1.x][pl1.y] = PLAYER1;
   }
}

void P2Turn(int papan)
{
   waktusebelum = time(NULL);
P2Turn:
   printf("\t\t\t\t\t\t\t\t\t\t\t%s's turn!\n\n\t\t\t\t\t\t\t\t\t\t\tMasukkan (baris,kolom): ", p2.nama);
   InputXY(&pl2);
   waktusesudah = time(NULL);
   if (waktusesudah - waktusebelum >= 10)
   {
      system("cls");
      UITimesUp();
      getch();
   }
   else if (pl2.x > papan || pl2.y > papan)
   {
      printf("\t\t\t\t\t\t\t\t\t\t\tInvalid move!\n");
      getch();
      goto P2Turn;
   }
   else if (pl2.batas != ',' || board[pl2.x][pl2.y] != ' ')
   {
      printf("\t\t\t\t\t\t\t\t\t\t\tInvalid move!\n");
      getch();
      goto P2Turn;
   }
   else
   {
      board[pl2.x][pl2.y] = PLAYER2;
   }
}

void InputXY(InputKoordinat *p)
{
   scanf("%d%c%d", &p->x, &p->batas, &p->y);
   p->x--;
   p->y--;
}

void PrintWinner(char winner)
{
   if (winner == PLAYER1)
   {
      UIXWin();
      getch();
   }
   else if (winner == PLAYER2)
   {
      UIYWin();
      getch();
   }
   else
   {
      UIDraw();
      getch();
   }
}

void CetakPapan(int papan)
{
   switch (papan)
   {
   case 3:
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // Enter
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 191);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c       %c       %c       %c\n", 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c   %c   %c   %c   %c   %c   %c\n", 179, board[0][0], 179, board[0][1], 179, board[0][2], 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c       %c       %c       %c\n", 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c       %c       %c       %c\n", 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c   %c   %c   %c   %c   %c   %c\n", 179, board[1][0], 179, board[1][1], 179, board[1][2], 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c       %c       %c       %c\n", 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c       %c       %c       %c\n", 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c   %c   %c   %c   %c   %c   %c\n", 179, board[2][0], 179, board[2][1], 179, board[2][2], 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c       %c       %c       %c\n", 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 217);
      printf("\n");
      break;
   case 5:
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); // Enter
      printf("\t\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 191);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[0][0], 179, board[0][1], 179, board[0][2], 179, board[0][3], 179, board[0][4], 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[1][0], 179, board[1][1], 179, board[1][2], 179, board[1][3], 179, board[1][4], 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[2][0], 179, board[2][1], 179, board[2][2], 179, board[2][3], 179, board[2][4], 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[3][0], 179, board[3][1], 179, board[3][2], 179, board[3][3], 179, board[3][4], 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[4][0], 179, board[4][1], 179, board[4][2], 179, board[4][3], 179, board[4][4], 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 217);
      printf("\n");
      break;
   case 7:
      printf("\n\n\n\n\n\n\n\n\n"); // Enter
      printf("\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196, 196, 191);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[0][0], 179, board[0][1], 179, board[0][2], 179, board[0][3], 179, board[0][4], 179, board[0][5], 179, board[0][6], 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[1][0], 179, board[1][1], 179, board[1][2], 179, board[1][3], 179, board[1][4], 179, board[1][5], 179, board[1][6], 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[2][0], 179, board[2][1], 179, board[2][2], 179, board[2][3], 179, board[2][4], 179, board[2][5], 179, board[2][6], 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[3][0], 179, board[3][1], 179, board[3][2], 179, board[3][3], 179, board[3][4], 179, board[3][5], 179, board[3][6], 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[4][0], 179, board[4][1], 179, board[4][2], 179, board[4][3], 179, board[4][4], 179, board[4][5], 179, board[4][6], 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[5][0], 179, board[5][1], 179, board[5][2], 179, board[5][3], 179, board[5][4], 179, board[5][5], 179, board[5][6], 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196, 196, 180);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 179, board[6][0], 179, board[6][1], 179, board[6][2], 179, board[6][3], 179, board[6][4], 179, board[6][5], 179, board[6][6], 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c       %c       %c       %c       %c       %c       %c       %c\n", 179, 179, 179, 179, 179, 179, 179, 179);
      printf("\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 217);
      printf("\n");
      break;
   }
}

char checkWinner(int papan)
{
   switch (papan)
   {
   case 3:
      for (int i = 0; i < 3; i++)
      {
         if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
         {
            return board[i][0];
         }
      }
      // check columns
      for (int i = 0; i < 3; i++)
      {
         if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
         {
            return board[0][i];
         }
      }
      // check diagonals
      if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
      {
         return board[0][0];
      }
      if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
      {
         return board[0][2];
      }

      return ' ';
   case 5: // check rows
      for (int i = 0; i < 5; i++)
      {
         if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board[i][4])
         {
            return board[i][0];
         }
      }
      // check columns
      for (int i = 0; i < 5; i++)
      {
         if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i])
         {
            return board[0][i];
         }
      }
      // check diagonals
      if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4])
      {
         return board[0][0];
      }
      if (board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0])
      {
         return board[0][4];
      }

      return ' ';
   case 7: // check rows
      for (int i = 0; i < 7; i++)
      {
         if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board[i][4] && board[i][0] == board[i][5] && board[i][0] == board[i][6])
         {
            return board[i][0];
         }
      }
      // check columns
      for (int i = 0; i < 7; i++)
      {
         if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i] && board[0][i] == board[5][i] && board[0][i] == board[6][i])
         {
            return board[0][i];
         }
      }
      // check diagonals
      if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[4][4] == board[5][5] && board[5][5] == board[6][6])
      {
         return board[0][0];
      }
      if (board[0][6] == board[1][5] && board[1][5] == board[2][4] && board[2][4] == board[3][3] && board[3][3] == board[4][2] && board[4][2] == board[5][1] && board[5][1] == board[6][0])
      {
         return board[0][6];
      }

      return ' ';
   }
}

void MainLagi()
{
   char Cek;
   printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tMain lagi? (y/n) : ");
   scanf("%c", &Cek);
   switch (Cek)
   {
   case 'y':
      system("cls");
      play();
      break;
   case 'n':
      system("cls");
      main();
      break;
   default:
      system("cls");
      MainLagi();
      break;
   }
}

void settings()
{
   int setting;
   UISettings();
   scanf("%d", &setting);
   switch (setting)
   {
   case 1:
      system("cls");
      theme();
      main();
      break;
   case 2:
      system("cls");
      about();
      system("cls");
      main();
      break;
   case 0:
      system("cls");
      main();
      break;
   default:
      system("cls");
      settings();
      break;
   }
}

void theme()
{
   int opsi;
   UITheme(); // Pilihan tema
   scanf("%d", &opsi);
   switch (opsi)
   {
   case 1:
      system("cls");
      system("color 0F");
      break;
   case 2:
      system("cls");
      system("color F0");
      break;
   case 3:
      system("cls");
      system("color 0C");
      break;
   case 4:
      system("cls");
      system("color E9");
      break;
   case 5:
      system("cls");
      system("color 02");
      break;
   case 6:
      system("cls");
      system("color 5A");
      break;
   default:
      system("cls");
      theme();
      break;
   }
}

void about()
{
   printf("\n\t\t\t\t\t\t\t\t\t\t\t                             ___");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t     ___       ___          /  /\\");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    /  /\\     /  /\\        /  /x/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t   /  /+/    /  /+/       /  /o/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t  /  /+/    /__/xo\\      /  /x/  ___");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t /  /ox\\    \\__\\/\\+\\__  /__/o/  /  /\\");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t/__/+/\\+\\      \\  \\o\\/\\ \\  \\+\\ /  /x/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\\__\\/  \\o\\      \\__\\++/  \\  \\+\\  /o/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t     \\  \\+\\     /__/x/    \\  \\o\\/+/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t      \\__\\/     \\__\\/      \\  \\+x/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t                            \\__\\/");
	printf("\n\t\t\t\t\t\t\t\t\t     ___           ___           ___");
	printf("\n\t\t\t\t\t\t\t\t\t    /\\  \\         /\\  \\         /\\  \\");
	printf("\n\t\t\t\t\t\t\t\t\t    \\o\\  \\       /ox\\  \\       /+x\\  \\");
	printf("\n\t\t\t\t\t\t\t\t\t     \\x\\  \\     /+/\\o\\  \\     /+/\\o\\  \\ ");
	printf("\n\t\t\t\t\t\t\t\t\t     /x+\\  \\   /+o\\~\\x\\  \\   /x/  \\+\\  \\");
	printf("\n\t\t\t\t\t\t\t\t\t    /+/\\o\\__\\ /x/\\+\\ \\o\\__\\ /+/__/ \\x\\__\\");
	printf("\n\t\t\t\t\t\t\t\t\t   /x/  \\/__/ \\/__\\x\\/+/  / \\o\\  \\  \\/__/");
	printf("\n\t\t\t\t\t\t\t\t\t  /+/  /           \\xo/  /   \\+\\  \\");
	printf("\n\t\t\t\t\t\t\t\t\t  \\/__/            /+/  /     \\o\\  \\");
	printf("\n\t\t\t\t\t\t\t\t\t                  /x/  /       \\x\\__\\");
	printf("\n\t\t\t\t\t\t\t\t\t                  \\/__/         \\/__/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t                 ___           ___  ");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t   ___          /  /\\         /  /\\");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t  /__/\\        /  /x+\\       /  /+x\\ ");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t  \\  \\x\\      /  /o/\\x\\     /  /x/\\o\\");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t   \\__\\o\\    /  /x/  \\o\\   /  /o+\\ \\+\\ ");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t   /  /+x\\  /__/o/ \\__\\+\\ /__/x/\\x\\ \\x\\");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t  /  /x/\\o\\ \\  \\+\\ /  /x/ \\  \\+\\ \\o\\_\\/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t /  /o/__\\/  \\  \\x\\  /x/   \\  \\x\\ \\x\\ ");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t/__/+/        \\  \\+\\/o/     \\  \\o\\_\\/");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\\__\\/          \\  \\+x/       \\  \\+\\");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t                \\__\\/         \\__\\/ ");
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t\t\t\t\t                            __              __  __                  ");
	printf("\n\t\t\t\t\t\t\t\t\t                           /\\ \\__          /\\ \\/\\ \\                 ");
	printf("\n\t\t\t\t\t\t\t\t\t  ___   _ __    __     __  \\ \\ ,_\\    __   \\_\\ \\ \\ \\____  __  __    ");
	printf("\n\t\t\t\t\t\t\t\t\t /'___\\/\\`'__\\/'__`\\ /'__`\\ \\ \\ \\/  /'__`\\ /'_` \\ \\ '__`\\/\\ \\/\\ \\   ");
	printf("\n\t\t\t\t\t\t\t\t\t/\\ \\__/\\ \\ \\//\\  __//\\ \\L\\.\\_\\ \\ \\_/\\  __//\\ \\L\\ \\ \\ \\L\\ \\ \\ \\_\\ \\  ");
	printf("\n\t\t\t\t\t\t\t\t\t\\ \\____\\\\ \\_\\\\ \\____\\ \\__/.\\_\\\\ \\__\\ \\____\\ \\___,_\\ \\_,__/\\/`____ \\ ");
	printf("\n\t\t\t\t\t\t\t\t\t \\/____/ \\/_/ \\/____/\\/__/\\/_/ \\/__/\\/____/\\/__,_ /\\/___/  `/___/> \\");
	printf("\n\t\t\t\t\t\t\t\t\t                                                              /\\___/");
	printf("\n\t\t\t\t\t\t\t\t\t                                                              \\/__/ ");
	printf("\n\n\n\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
   printf("\t\t\t\t\t\t\t\t\t\t\t   %c         Created by        %c\n", 179, 179);
   printf("\t\t\t\t\t\t\t\t\t\t\t   %c     Mutiara Dwi Salma     %c\n", 179, 179);
   printf("\t\t\t\t\t\t\t\t\t\t\t   %c    Rayhan Fanez Fathiadi  %c\n", 179, 179);
   printf("\t\t\t\t\t\t\t\t\t\t\t   %c   Retryanzani Dwi Fauzan  %c\n", 179, 179);
   printf("\t\t\t\t\t\t\t\t\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
   printf("\n\n\n");








   
   



   getch();
}
