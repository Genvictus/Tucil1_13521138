#include "io.h"
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <cctype>

// using namespace std;

vector<int> parse24(string input){
    /* KAMUS LOKAL */
    vector<int> nums;
    int n, num, length;
    int temp;
    string::iterator it;
    int state; // -1: currently no value, 0: 1 digit numeric, 1: 2 digit numeric / 1 char alphabet

    /* ALGORITMA */
    it = input.begin();
    state = -1;
    length = 0;
    n = 0;
    while(it != input.end() && n < 4){
        if(isblank(*it)){ // blank space
            if(state != -1){
                nums.push_back(num);
                n++;
                state = -1;
            }
            /* ignore blank spaces */
            while(it != (input.end()-1) && isblank(*it)){
                ++it;
            }
            /* it == input.end()-1 || !isblank(*it) */
            if(isblank(*it)){
                ++it;
            }
        }
        else{ // bukan blank space
            if(state == -1){ // currently no value, sebelumnya membaca blank space
                if(isalpha(*it)){ // alphabet
                    state = 1;
                    if(*it == 'a' || *it == 'A'){
                        num = 1;
                    }
                    else if(*it == 'j' || *it == 'J'){
                        num = 11;
                    }
                    else if(*it == 'q' || *it == 'Q'){
                        num = 12;
                    }
                    else if(*it == 'k' || *it == 'K'){
                        num = 13;
                    }
                    else{ // input invalid, break & return empty vector
                        nums.clear();
                        return nums;
                    }
                }
                else{ // numeric atau karakter lain
                    temp = *it - '0';
                    if(1 <= temp && temp <= 9){ // numerik digit pertama, tidak boleh 0
                        num = temp;
                        state = 0;
                    }
                    else{ // input invalid, break & return empty vector
                        nums.clear();
                        return nums;
                    }
                }
            }
            else if(state == 0 && num == 1){
                temp = *it - '0';
                if(0 <= temp && temp <= 3){ // digit kedua dari input bilangan 2 digit hanya boleh 0-3
                    num = num*10 + temp;
                    state = 1;
                }
                else{ // input invalid, break & return empty vector
                    nums.clear();
                    return nums;
                }
            }
            else{ // input invalid, break & return empty vector
                nums.clear();
                return nums;
            }
            ++it;
        }
    }
    /* it == input.end() || n == 4 */
    if(state != -1){
        nums.push_back(num);
        n++;
        state = -1;
    }
    // vector<int>::iterator v_it;
    // for(v_it = nums.begin(); v_it != nums.end(); ++v_it){
    //     cout << *v_it << "\n";
    // }
    if(n != 4){
        nums.clear();
    }
    return nums;
}

string userIn(){
    /* KAMUS LOKAL */
    string input;

    /* ALGORITMA */
    getline(cin, input);
    return input;
}

string fileIn(){
    /* KAMUS LOKAL */
    string input, filename;
    string repeat;
    string line;
    ifstream inFile;

    /* ALGORITMA */
    /* Validasi file */
    do{
        cout << "Masukkan nama file: ";
        getline(cin, input);
        filename = "..\\test\\" + input;
        inFile.open(filename);
        if(!inFile){    // jika file gagal dibuka, minta masukan mengulang berupa Y/N
            for(;;){
                cout<<"File tidak dapat dibuka, apakah anda ingin mengulangi input melalui file? (Y/N) ";
                getline(cin, repeat);
                if(repeat == "Y" || repeat == "y" || repeat == "N" || repeat == "n"){
                    break;
                }
                cout<<"Mohon masukkan input \"Y\" atau \"N\" ! [tanpa disertai tanda kutip (\")]\n";
            }
        }
        else{
            repeat = "N";
        }
    } while(repeat == "Y" || repeat == "y");

    line = "FAIL";

    /* Jika file dapat dibuka */
    if(inFile){
        getline(inFile, line);
        inFile.close();
    }

    return line;
}

void printRes(vector<string> output){
    /* KAMUS LOKAL */
    vector<string>::iterator it;

    /* ALGORITMA */
    for(it = output.begin(); it != output.end(); ++it){
        cout << *it << "\n";
    }
}

void writeRes(vector<string> output, string fname){
    /* KAMUS LOKAL */
    string saveDir;
    
    vector<string>::iterator it;

    /* ALGORITMA */
    saveDir = "..\\test\\" + fname;
    ofstream outFile(saveDir);
    for(it = output.begin(); it != output.end(); ++it){
        outFile << *it << "\n";
    }
    outFile.close();
}