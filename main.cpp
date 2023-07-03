#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

/**
 * NAMA     :HENDRIYAWAN
 * KELAS    :04TPLK002
 * NIM      : 211011401536
 */

char reload = 'y';
int selected;
vector<int> selectedItems;
vector<int> quantities;
// Array untuk menyimpan data tabel menu
int nomor[5] = {1, 2, 3, 4, 5};
string judul[5] = {"Nasi Goreng Special", "Nasi Kebuli", "Nasi Ayam Kremes", "Nasi Sambel Bakar", "Nasi Goreng Ati"};
double harga[5] = {13500, 17000, 13000, 14000, 13000};

/// print line strip
/// @param letter symbol, example '=' or '-'
/// @param length length of line
void printLine(char letter, int length)
{
    for (int i = 1; i <= length; i++)
    {
        cout << letter;
    }
    cout << endl;
}

/// @brief count total price to order
/// @param selectedItems
/// @param harga
/// @return
double calculateTotalPrice(const vector<int> &selectedItems, const double *harga, const vector<int> &quantities)
{
    double total = 0.0;
    for (int i = 0; i < selectedItems.size(); i++)
    {
        int item = selectedItems[i];
        int quantity = quantities[i];
        total += harga[item - 1] * quantity;
    }
    return total;
}

/// @brief
void tampilkanMenu()
{
    // Menggunakan karakter '\r' untuk mengembalikan kursor ke awal baris
    cout << setw(2) << "No" << setw(25) << "Menu" << setw(8) << "Harga" << endl;
    printLine('-', 35);

    // Menampilkan data tabel
    for (int i = 0; i < 5; i++)
    {
        cout << setw(2) << nomor[i] << setw(25) << judul[i] << setw(8) << harga[i] << endl;
    }

    // Menggunakan karakter '\r' untuk mengembalikan kursor ke awal baris
    cout << "pilih menu (0 untuk selesai) : ";
    cin >> selected;
    // Check if the selection is valid
    if (selected >= 1 && selected <= 5)
    {
        // Add the selected item to the vector
        int quantity;
        cout << "Masukkan jumlah pemesanan: ";
        cin >> quantity;

        selectedItems.push_back(selected);
        quantities.push_back(quantity);
    }
    else
    {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }
}

int main()
{
    do
    {
        tampilkanMenu();
        cout << "\r"; // Menggunakan karakter '\r' untuk mengembalikan kursor ke awal baris
        // Ask if the user wants to continue ordering,
        cout << "Ada pesanan lain? (y/n): ";
        cin >> reload;
        cout << endl;

    } while (reload == 'y' || reload == 'Y');

    if (selectedItems.size() > 0)
    {
        // hitung total harga
        double totalPrice = calculateTotalPrice(selectedItems, harga, quantities);

        // Display the selected items and total price / tampilkan item yang terpilih dan harga
        cout << "Pesanan Anda:" << endl;
        printLine('-', 40);

        for (int i = 0; i < selectedItems.size(); i++)
        {
            cout << setw(2) << (i + 1) << setw(25) << judul[i] << setw(8) << harga[i] << 'x' << quantities[i] << endl;
        }

        cout << endl;
        cout << "Total harga: " << totalPrice << endl;

        bool continueOrder = true;
        do
        {
            // Tampilkan form pembayaran
            cout << "Silahkan Bayar Pesanan Anda:" << endl;
            printLine('-', 40);

            string yourName;
            string table;
            int cash;

            cout << "Masukkan nama Anda : ";
            cin >> yourName;
            cout << "Masukkan Nomor Meja : (1-10) : ";
            cin >> table;
            cout << "Masukkan uang Anda: ";
            cin >> cash;

            if (cash < totalPrice)
            {
                cout << "Maaf uang Anda kurang!" << endl;
            }
            else
            {
                cout << "Anda membayar sebesar: " << cash << endl;
                int change = cash - totalPrice;
                cout << "Kembalian: " << change << ", Silahkan ditunggu di meja nomor : " << table << " Terimakasih !"<< endl;
                cout << endl;
                cout << "Apakah Anda ingin memesan lagi? (y/n) : ";
                cin >> reload;
                cout << "Terima kasih, semoga harimu menyenangkan!" << endl;
                continueOrder = false;
            }
        } while (continueOrder);
    }
    cout << "Anda tidak memesan apapun !" << endl;
    return 0;
}
