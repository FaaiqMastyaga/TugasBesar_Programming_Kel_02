# Tugas Besar Programming SEKURO 2023 Kelompok 2

Pada Tugas Besar Programming SEKURO 2023, cakru diminta membuat program sistem kapal yang mengimplementasikan object-oriented programming. Program dibuat dalam bahasa C++ dan menggunakan library iostream, stdlib.h, string, math.h, dan bits/stdc++.h

### **Overview Program**
Program dimulai dengan menampilkan koordinat kapal cakru (0, 0) dan kapal musuh (random), health kapal cakru dan kapal musuh, jarak antara dua kapal, serta jarak tembak maksimum (range) kapal cakru dan kapal musuh. Program memberikan 3 pilihan perintah, yaitu pilihan 1 untuk menembak, pilihan 2 untuk bergerak, dan pilihan 3 untuk diam di tempat. Pengguna dapat menembak hanya jika jarak terhadap musuh kurang dari range tembak kapal cakru. Pengguna dapat menggerakkan kapal satu satuan ke arah atas/bawah/kiri/kanan. Setiap kali pengguna menghancurkan kapal musuh, musuh baru akan muncul pada koordinat random dan pengguna akan mendapatkan tambahan health sebesar 10% dari health kapal yang dihancurkan sebelumnya. Hasil dari penambahan health tidak bisa membuat pengguna memiliki health yang melebihi batas maksimumnya. Program akan berhenti ketika health kapal pengguna habis (nol atau negatif).

### **Cara Menjalankan Program**
Compile dan run program di directory ``TugasBesar_Programming_Kel_02/src``

Berikut penjelasan detailnya:
- Buka terminal
- Ganti directory menjadi ``TugasBesar_Programming_Kel_02/src``
- Ketik `g++ -o main main.cpp` untuk membuat executable file
- Secara otomatis akan dibuat executable file: `main.exe` pada directory saat ini
- Ketik `./main.exe` untuk menjalankan executable file

link GitHub: https://github.com/FaaiqMastyaga/TugasBesar_Programming_Kel_02

### **Peran per Anggota**
Kelompok 2
- Faaiq Mastyaga - 16722329 - Membuat atribut serta fitur basic dan tambahan pada kapal
- nama - nim - peran
- nama - nim - peran
