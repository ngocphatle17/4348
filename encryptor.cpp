#include <iostream>
#include <string>

using namespace std;

string passkey = "";  // Stores the passkey

// Vigenère Cipher Function
string vigenere_cipher(string text, string key, bool encrypt) {
    string result = "";
    int key_len = key.length();
    for (size_t i = 0; i < text.length(); i++) {
        char base = 'A';
        int text_pos = text[i] - base;
        int key_pos = key[i % key_len] - base;
        char new_char = encrypt ? 
            (text_pos + key_pos) % 26 + base : 
            (text_pos - key_pos + 26) % 26 + base;
        result += new_char;
    }
    return result;
}
