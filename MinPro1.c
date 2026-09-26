#include <stdio.h>

int main() {
    char nama[50], mbti[50];
    int umur, tanggal_lahir;
    int i, panjang;
    int shift, posisi, produk;
    char c1, c2, c3;
    char id[15];

    printf("Nama            : ");
    scanf("%s", nama);
    printf("Umur            : ");
    scanf("%d", &umur);
    printf("MBTI            : ");
    scanf("%s", mbti);
    printf("Tanggal lahir   : ");
    scanf("%d", &tanggal_lahir);

    // normalisasi 
    if (nama[0] >= 'a' && nama[0] <= 'z') {
        nama[0] = nama[0] - 32;
    }
    if (mbti[0] >= 'a' && mbti[0] <= 'z') {
        mbti[0] = mbti[0] - 32;
    }

    // lenght dari nama
    i = 0;
    while (nama[i] != '\0') {
        i++;
    }
    panjang = i;

    // huruf awal nama dan tanggal lahir (caesar)
    shift = tanggal_lahir % 26;
    posisi = (nama[0] - 'A' + shift) % 26;
    c1 = 'A' + posisi;

    // abjad urutan a-z menjadi z-a (atbash)
    c2 = 'Z' - (mbti[0] - 'A');

    // 3 angka unik
    produk = (umur * tanggal_lahir) % 1000;

    // balik huruf akhir pada nama (Z-A)
    c3 = nama[panjang - 1];
    if (c3 >= 'a' && c3 <= 'z') {
        c3 = c3 - 32;
    }

    sprintf(id, "%c%03d%c%02d%c%02d", c1, produk, c2, panjang, c3, umur % 100);

    printf("\n----------------------------------------------\n");
    printf("|\n");
    printf("|   ID            : %s\n", id);
    printf("|   Name          : %s\n", nama);
    printf("|   MBTI          : %s\n", mbti);
    printf("|\n");
    printf("----------------------------------------------\n");

    return 0;
}