typedef struct
{
    char nama[20];
} Player; //Data Pemain

typedef struct
{
    int x,y;
    char batas;
}InputKoordinat; //Data Input Koordinat 

char board[9][9]; //Matriks Papan
const char PLAYER1 = 'X'; //SimbolPemain1
const char PLAYER2 = 'O'; //SimbolPemain2

InputKoordinat pl1, pl2;
Player p1, p2;
time_t waktusebelum,waktusesudah; //Waktu  

void play();
/*  Prosedur untuk menampilkan pilihan level permainan (3x3,5x5,7x7)
    I.S : Layar output belum menampilkan pilihan level permainan, prosedur ini mewadahi alur game secara umum
    F.S : Pilihan level permainan tampil pada layar. User dapat memilih untuk bermain level:
          1. 3x3
          2. 5x5
          3. 7x7
*/

void settings();
/*  Prosedur untuk menampilkan pilihan settings
    I.S : Layar output belum menampilkan pilihan settings
    F.S : Pilihan settingtims tampil pada layar. User dapat memilih:
          1. Mengubah warna UI
          2. Melihat tutorial permainan
          3. Kembali ke menu
*/
void theme();
/*  Prosedur untuk menampilkan pilihan pengubahan tema UI
    I.S : Layar output belum menampilkan pilihan pengubahan tema UI
    F.S : Pilihan pengubahan tema UI tampil pada layar. User dapat memilih 6 tema UI:
          1. Font putih dengan background hitam
          2. Font hitam dengan background putih
          3. Font merah dengan background hitam
          4. Font kuning dengan background biru
          5. Font hijau dengan background hitam
          6. Font hijau dengan background ungu
*/
void about();
/*  Prosedur untuk menampilkan tutorial bermain, deskripsi pembuat program, dan referensi
    I.S : Layar output belum menampilkan tutorial bermain, deskripsi pembuat program, dan referensi
    F.S : Tutorial bermain, deskripsi pembuat program, dan referensi tampil pada layar.
*/

void InputNama(Player *p, int i);
/*  Prosedur untuk pengisian nama pemain 1 dan pemain 2
    I.S : Layar output belum menampilkan baris pengisian nama pemain
    F.S : Pemain dapat mengisi namanya masing-masing
*/

void CetakPapan(int papan);
/*  Prosedur untuk menampilkan papan 3x3, 5x5, atau 7x7
    I.S : Layar output belum menampilkan papan bermain
    F.S : Layar output menampilkan petak kosong 3x3, 5x5, atau 7x7
*/
void ResetBoard(int a);
/*  Prosedur untuk mengosongkan papan 3x3, 5x5, atau 7x7
    I.S : Petak papan masih terisi oleh simbol-simbol 'X' dan 'O'
    F.S : Saat petak papan dipanggil, isi petak sudah kosong
*/
int CekKosong(int a);
//  Fungsi untuk memeriksa dan mengembalikan nilai dari variabel "freeSpaces"
void P1Turn(int papan);
/*  Prosedur untuk memberi kesempatan pemain 1 untuk bermain
    I.S : Pemain 1 belum mendapat giliran bermain
    F.S : Pemain 1 mendapat giliran bermain
*/
void P2Turn(int papan);
/*  Prosedur untuk memberi kesempatan pemain 2 untuk bermain
    I.S : Pemain 2 belum mendapat giliran bermain
    F.S : Pemain 2 mendapat giliran bermain
*/
char checkWinner(int papan);
//Fungsi untuk memeriksa kondisi menang tictactoe dan mengembalikan character 'X' atau 'O' ke variabel winner
void PrintWinner(char winner);
/*  Prosedur untuk menampilkan pemenang pada layar output
    I.S : Layar output belum menampilkan pemenang
    F.S : Layar output menampilkan pemenang
*/
void InputXY(InputKoordinat *p);
/*  Prosedur untuk menginput koordinat (x,y) pada petak
    I.S : Pemain 1 dan/ 2 belum bisa menginput koordinat (x,y) petak
    F.S : Pemain 1 dan/ 2 bisa menginput koordinat (x,y) petak
*/
void MainLagi();
/*  Prosedur untuk menanyakan apakah user ingin bermain lagi
    I.S : Layar output belum menampilkan pilihan untuk bermain lagi/tidaknya, dan user belum bisa memilih
    F.S : Layar output menampilkan pilihan untuk bermain lagi/tidaknya, dan user dapat memilih
*/
int main();