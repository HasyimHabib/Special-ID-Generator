# Foodie Special ID Generator

## Deskripsi Singkat

Program ini menerima 4 data masukan dari pengguna melalui terminal (Nama, Umur, Warna Favorit, Tanggal Lahir), lalu mengolahnya menjadi satu ID unik sepanjang 10 karakter berupa kombinasi huruf dan angka. Pengolahan melibatkan operasi aritmatika dasar (perkalian, modulo) dan manipulasi nilai ASCII dari karakter-karakter input. Seluruh bagian ID kemudian digabungkan menjadi satu string utuh menggunakan fungsi `sprintf()`.

## Format Susunan ID

`[C1] [NNN] [C2] [PP] [C3] [UU]`

| Bagian | C1 | NNN | C2 | PP | C3 | UU |
|---|---|---|---|---|---|---|
| Jumlah karakter | 1 | 3 | 1 | 2 | 1 | 2 |

Total: **10 karakter**

## Alur Pengolahan Data

1. **C1** — huruf pertama nama digeser sejauh `tanggal_lahir % 26` posisi alfabet (Caesar cipher), makin beda tanggal lahir makin beda hasil geserannya.
2. **NNN** — `umur * tanggal_lahir`, diambil 3 digit terakhir lewat `% 1000`.
3. **C2** — huruf pertama warna favorit dibalik posisi alfabetnya (Atbash cipher: A↔Z, B↔Y, dst).
4. **PP** — panjang nama dihitung pakai loop manual (bukan `strlen()`).
5. **C3** — huruf terakhir nama, diambil pakai indeks `panjang - 1` dari hasil langkah PP.
6. **UU** — sisa hasil bagi umur dengan 100 (`umur % 100`).
7. Keenam bagian di atas digabung berurutan lewat `sprintf()` menjadi satu ID final.

## Contoh Perhitungan

Input: `Nama=Rian, Umur=19, Warna=Biru, Tanggal Lahir=14`

| Bagian | Perhitungan | Hasil |
|---|---|---|
| C1 | `R` (posisi 17) + geser 14 → `31 % 26 = 5` → huruf ke-5 | `F` |
| NNN | `19 x 14 = 266` → `266 % 1000` | `266` |
| C2 | `'Z' - ('B' - 'A')` | `Y` |
| PP | panjang kata "Rian" | `04` |
| C3 | huruf terakhir "Rian" | `N` |
| UU | `19 % 100` | `19` |

**ID akhir: `F266Y04N19`**

## Lampiran Hasil Running Code

*(tempel screenshot hasil running program di sini)*
