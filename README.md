# Special ID Generator

## Deskripsi Singkat

Program ini menerima 4 data masukan dari pengguna melalui terminal (Nama, Umur, MBTI, Tanggal Lahir), lalu mengolahnya menjadi satu ID unik sepanjang 10 karakter berupa kombinasi huruf dan angka. Pengolahan melibatkan operasi aritmatika dasar (perkalian, modulo) dan manipulasi nilai ASCII dari karakter-karakter input. Seluruh bagian ID kemudian digabungkan menjadi satu string utuh menggunakan fungsi `sprintf()`.

## Format Susunan ID

`[C1] [NNN] [C2] [PP] [C3] [UU]`

| Bagian | C1 | NNN | C2 | PP | C3 | UU |
|---|---|---|---|---|---|---|
| Jumlah karakter | 1 | 3 | 1 | 2 | 1 | 2 |

Total: **10 karakter**

## Alur Pengolahan Data

1. **C1** — huruf pertama nama digeser sejauh `tanggal_lahir % 26` posisi alfabet (Caesar cipher), makin beda tanggal lahir makin beda hasil geserannya.
2. **NNN** — `umur * tanggal_lahir`, diambil 3 digit terakhir lewat `% 1000`.
3. **C2** — huruf pertama MBTI dibalik posisi alfabetnya (Atbash cipher: A↔Z, B↔Y, dst).
4. **PP** — panjang nama dihitung pakai loop manual (bukan `strlen()`).
5. **C3** — huruf terakhir nama, diambil pakai indeks `panjang - 1` dari hasil langkah PP.
6. **UU** — sisa hasil bagi umur dengan 100 (`umur % 100`).
7. Keenam bagian di atas digabung berurutan lewat `sprintf()` menjadi satu ID final.

## Lampiran Hasil Running Code

<img width="959" height="505" alt="Screenshot 2026-09-26 104233" src="https://github.com/user-attachments/assets/7be5a275-c267-4177-82a6-48fbdbc2ea5b" />

