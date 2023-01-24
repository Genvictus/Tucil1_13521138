/* File: Modul brute force solusi "Kartu 24" program */

#ifndef CARD24_H
#define CARD24_H

#include <vector>
#include <string>
#include <set>

using namespace std;

struct expression
{
    float val;
    string expr;
};

vector<string> solve24(vector<int> nums);
/* Mengembalikan ekspresi-ekspresi yang mungkin sebagai solusi dari sebuah kumpulan angka */

vector<vector<int>> permute(vector<int> nums);
/* Mengembalikan permutasi-permutasi yang mungkin dari sebuah kumpulan angka */

vector<expression> count24(vector<int> nums);
/* I.S. nums (permutasi angka-angka) terdefinisi, start dan end terdefinisi */
/* F.s. solusi-solusi baru yang valid ditambahkan ke dalam expressions */

// vector<int> segment(vector<int> nums, vector<int>::iterator start, vector<int>::iterator end);

// vector<int> random4(int seed);
// /* Mengembalikan 4 buah bilangan random dalam sebuah vector berdasarkan masukan seed awal */

#endif