# Tucil 1 STIMA - Brute Force Solusi Kartu 24
> 
> Aplikasi algoritme **Brute Force** pada pencarian solusi permainan kartu 24

## Creator
Johann Christian Kandani - 13521138

Kelas K02


## Daftar isi
* [Tentang Proyek](#tentang-proyek)
* [Fitur](#fitur)
* [Setup](#setup)
* [Usage](#usage)
* [Status Proyek](#status-proyek)
* [Room for Improvement](#room-for-improvement)
* [Acknowledgements](#acknowledgements)


## Tentang Proyek
- Program berbasis CLI (Command Line Interface) untuk mencari solusi-solusi permainan kartu 24

## Fitur
Program dapat menjalankan fitur-fitur:
- Input dari pengguna
- Input melalui file
- Pembangkit angka acak
- Penulisan solusi-solusi ke dalam file

## Setup
Pastikan telah ter-instal g++ 12.2.0 pada sistem jika menggunakan platform Linux, karena file binary hanya tersedia bagi platform Windows
1. Jalankan terminal dan clone repo ini ``git clone https://github.com/Genvictus/Tucil1_13521138.git``
2. Jika file binary tidak tersedia atau tidak sesuai dengan versi source code, jalankan ``run.bat`` pada Windows,
3. Atau, lakukan compile pada directory ``src``, dan jalankan perintah ``g++ main.cpp io\io.cpp card24\card24.cpp -o ..\bin\card24``
4. File binary akan tersedia pada directory ``bin``

## Usage
### Mode Program
Setelah menjalankan program, pengguna diharapkan memasukkan mode berjalan program yang diinginkan
Program dapat dijalankan dalam 3 mode:
1. Mode input pengguna melalui terminal - pengguna diharapkan memasukkan 4 simbol kartu bridge atau 4 desimal dalam range 1-13
2. Mode input melalui file - pengguna dapat mengspesifikasikan file input yang akan digunakan sebagai masukan program, directory default berada pada folder `

## Status Proyek
Proyek telah: _selesai_.

*Tidak ada rencana perubahan, penambahan, maupun optimisasi program dalam jangka waktu dekat.*

## Room for Improvement
Room for improvement:
- Dapat digunakan struktur data buatan baru yang dapat meningkatkan efisiensi program.
- Program dapat dimodifikasi ke dalam bentuk program berorientasi objek (PBO) untuk meningkatkan modularitas, agar dapat digunakan lebih mudah dalam program lain


## Acknowledgements
- Tugas ini didasari oleh deskripsi Permainan Kartu 24 [Penerapan Algoritma Brute Force pada Permainan Kartu 24 (24 game)](https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2015-2016/Makalah-2016/MakalahStima-2016-038.pdf)
- Template README oleh [@flynerdpl](https://www.flynerd.pl/): [README](https://github.com/ritaly/README-cheatsheet)
