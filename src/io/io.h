/* File: Modul input/output & parser program */

#ifndef IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<int> parse24(string input);
/* Mengembalikan array dengan 4 elemen yang berupa angka dengan nilai 1-13 jika input valid, */
/* dan mengembalikan empty vector jika input tidak sesuai */
/* input-input dipisahkan oleh spasi, parser mengabaikan input sisa setelah 4 input pertama telah valid */

string userIn();
/* Mengembalikan string berdasarkan input user dari keyboard */

string fileIn();
/* Mengembalikan string berdasarkan input dari file, mengembalikan "FAIL" jika gagal */

void printRes(vector<string> output);
/* I.S. output terdefinisi */
/* F.s. Mencetak elemen-elemen output ke layar yang dipisahkan dengan karakter newline (\n) */

void writeRes(vector<string> output, string fname = "output.out");
/* I.S. output terdefinisi */
/* F.s. Menuliskan output ke sebuah file dengan nama fname yang dipisahkan dengan karakter newline (\n) */

#endif