#include <iostream>
#include <string>
// using string to had more powerful with object string :)
using namespace std;
// encrypt using const for string (plain text that we want to encypt in this function ) .....
string encrypt(const string& plaintext, int key) {
    string cipher_text;
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            cipher_text += char(base + (ch - base + key) % 26);
        }
        else {
            cipher_text += ch;
        }
    }
    return cipher_text;
}
// decrypt using const also for string and its will do decrypt oppsent of encrypt :))
string decrypt(const string& ciphertext, int key) {
    string plain_text;
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            plain_text += char(base + (ch - base - key + 26) % 26);  // +26 to handle negative shifts
        }
        else {
            plain_text += ch;
        }
    }
    return plain_text;
}
// main here we will cal functions and use cout and cin to input and output 
int main() {
    string mode;
    int key;

    cout << "Please enter a encrypt or decrypt sir :  ";
    cin >> mode;

    while (mode != "encrypt" && mode != "decrypt") {
        cout  << "Invalid mode selected. Please choose 'encrypt' or 'decrypt'." << endl;
        return 1;
    }
    // here we use while if the user doesn't enter that's we want its will be loop
    cout << "Enter key (integer): ";
    cin >> key;
    cin.ignore();  
    // ignore the space or new line 
    if (mode == "encrypt") {
        string plaintext;
        cout << "Enter plaintext: ";
        getline(cin, plaintext);
        // if mode equal encypt we will getline (using get line to get the full name ) cin had problem with that ..
        string cipher_text = encrypt(plaintext, key);
        cout << "Ciphertext: " << cipher_text << endl;

    }
    else if (mode == "decrypt") {
        string ciphertext;
        cout << "Enter ciphertext: ";
        getline(cin, ciphertext);
        // if mode equal encypt we will getline (using get line to get the full name ) cin had problem with that ..
        string plain_text = decrypt(ciphertext, key);
        cout << "Plaintext: " << plain_text << endl;
    }

    return 0;
} // this using cpp and I used my logic and some of search on google I hope its good >>> strudent : Mohammed Imad
