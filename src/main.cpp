#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include "io\io.h"
#include "card24\card24.h"

using namespace std;

int main(){
    /* KAMUS */
    char option;
    string input, line;
    string filename;
    int nsol, randnum;

    vector<int> nums;
    vector<string> solutions;
    vector<string>::iterator sol_it;

    /* ALGORITMA */
    cout << "           Selamat datang pada program \"Permainan Kartu 24\" Solver!\n";
    cout << "   ------------------------------------------------------------------------\n";
    cout << "Program akan menghasilkan solusi-solusi dari masukan 4 buah nilai kartu bridge\n";
    cout << "==============================================================================\n";
    
    for(;;){
        cout << "\n\nMode program:\n1. Masukan dari keyboard\n2. Masukan dari file\n3. Pembangkit acak program\n4. Keluar\n";
        cout << "Silakan pilih mode program (input berupa angka 1-4): ";
        getline(cin, line);
        option = *(line.begin());
        if(option == '1'){
            cout << "Masukkan 4 angka atau simbol kartu yang masing-masing dipisahkan oleh spasi\n";
            input = userIn();
            nums = parse24(input);
        }
        else if(option == '2'){
            cout << "Pastikan file berada pada directory \"test\"\n";
            cout << "Format file input berupa 4 angka atau simbol kartu yang masing-masing dipisahkan oleh spasi\n";
            input = fileIn();
            nums = parse24(input);
        }
        else if(option == '3'){
            srand(time(0)); // inisialisasi seed random
            randnum = rand()%12 + 1;
            cout << randnum << " ";
            nums.push_back(randnum);

            randnum = rand()%12 + 1;
            cout << randnum << " ";
            nums.push_back(randnum);

            randnum = rand()%12 + 1;
            cout << randnum << " ";
            nums.push_back(randnum);

            randnum = rand()%12 + 1;
            nums.push_back(randnum);
            cout << randnum << "\n";
        }
        else if(option == '4'){
            cout << "Program telah selesai dijalankan, semoga membantu!\n";
            break;
        }
        else{
            cout << "Input gagal, mohon hanya input angka dengan nilai dari 1 hingga 4!\n";
            continue;
        }

        /* check if fail */
        if(!nums.empty()){
            auto start = chrono::high_resolution_clock::now();
            solutions = solve24(nums);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            nsol = solutions.size();
            if(nsol == 0){
                cout << "Tidak ada solusi yang mungkin\n";
                cout << "(time taken: " << duration.count() << " microseconds)\n";
            }
            else{
                cout << "Jumlah solusi yang mungkin: " << nsol << "\n";
                printRes(solutions);
                cout << "Proses telah selesai dijalankan.\n";
                cout << "(time taken: " << duration.count() << " microseconds)\n";
                for(;;){
                    cout << "Simpan hasil dalam file (Y/N)? ";
                    getline(cin, line);
                    option = *(line.begin());
                    if(option == 'y' || option == 'Y'){
                        cout << "Masukkan nama file untuk menyimpan hasil: ";
                        getline(cin, filename); // less security, but not my job
                        if(filename.empty()){
                            filename = "output.out";
                        }
                        writeRes(solutions, filename);
                        cout << "File berhasil disimpan pada folder \"test\" dengan nama " << filename << "\n";
                        break;
                    }
                    else if(option == 'n' || option == 'N'){
                        break;
                    }
                    cout << "Input gagal, mohon hanya masukkan \"Y\" atau \"N\"!";
                }
                cout << "Program akan kembali ke menu utama\n";
            }
            nums.clear();
        }
        else{
            cout << "Input gagal, mohon pastikan input anda sudah tepat\n";
        }
    }
    return 0;
}