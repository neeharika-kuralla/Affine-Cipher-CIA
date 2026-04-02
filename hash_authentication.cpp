#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string findhash(string s, int k) {
    int p = 31;
    long long hash = 0;
    long long power = 1;

    long long mod = 1;
    for (int i = 0; i < k; i++) mod *= 10;

    for (char ch : s) {
        int val;

        if (ch >= 'A' && ch <= 'Z') 
            val = ch - 'A' + 1;
        else if (ch >= 'a' && ch <= 'z') 
            val = ch - 'a' + 27;
        else if (isdigit(ch)) 
            val = ch - '0' + 53;
        else 
            val = 0;

        hash = (hash + val * power) % mod;
        if (hash < 0) hash += mod;  

        power = (power * p) % mod;
    }

    string res = to_string(hash);

    if (res.length() < k) {
        res = string(k - res.length(), '0') + res;
    }

    return res;
}

string encrypt(string st, int a, int b) {
    string cipher = "";

    for (char ch : st) {
        int val;

        if (ch >= 'A' && ch <= 'Z') val = ch - 'A';
        else if (ch >= 'a' && ch <= 'z') val = ch - 'a' + 26;
        else if (ch >= '0' && ch <= '9') val = ch - '0' + 52;
        else if (ch == '-') { cipher += '-'; continue; } 
        else continue;

        int calculated_val = (a * val + b) % 62;

        if (calculated_val < 26) cipher += 'A' + calculated_val;
        else if (calculated_val < 52) cipher += 'a' + (calculated_val - 26);
        else cipher += '0' + (calculated_val - 52);
    }

    return cipher;
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

string decrypt(string st, int a, int b) {
    int m = 62;
    int a_inverse = modInverse(a, m);

    if (a_inverse == -1) {
        cout << "Invalid key! No modular inverse exists.\n";
        return "";
    }

    string res = "";

    for (char ch : st) {
        int val;

        if (ch >= 'A' && ch <= 'Z') val = ch - 'A';
        else if (ch >= 'a' && ch <= 'z') val = ch - 'a' + 26;
        else if (ch >= '0' && ch <= '9') val = ch - '0' + 52;
        else if (ch == '-') { res += '-'; continue; }
        else continue;

        int calculated_val = (a_inverse * (val - b + m)) % m;

        if (calculated_val < 26) res += 'A' + calculated_val;
        else if (calculated_val < 52) res += 'a' + (calculated_val - 26);
        else res += '0' + (calculated_val - 52);
    }

    return res;
}

int main() {
    string plainText;

    cout << "Enter plain text: ";
    getline(cin, plainText);

    int plain_len = plainText.length();
    int k = 10;

    string hashed = findhash(plainText, k);
    cout << "Hashed value: " << hashed << endl;

    string concat = plainText + hashed;
    cout << "Concatenated value: " << concat << endl;

    string cipher_text = encrypt(concat, 5, 8);
    cout << "Cipher Text: " << cipher_text << endl;
    

    string decrypted_text = decrypt(cipher_text, 5, 8);
    cout << "Decrypted Text: " << decrypted_text << endl;

    string decrypted_plain = decrypted_text.substr(0, plain_len);
    string decrypted_hash = decrypted_text.substr(plain_len, k);

    string final_hash = findhash(decrypted_plain, k);

    if (decrypted_hash == final_hash)
        cout << "Authenticated" << endl;
    else
        cout << "Not Authenticated" << endl;

    return 0;
}