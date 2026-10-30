/**
 * @file assignment_2.cpp
 * @author Rose Richards (rricha58@skyhawks.utm.edu)
 * @brief The second part of the Cryptographic Tools assignment
 * @version 0.1
 * @date 2026-10-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <iostream>
#include <fstream>
#include <vector>

int ord(char x){
    return x;
}

char chr(int x){
    char y = (char)x;
    return y;
}

int pow(int base, int exponent, int mod) {
    long long result = 1;
    long long factor = base % mod;

    while (exponent > 0) {
        if (exponent & 1) result = (result * factor) % mod;
        factor = (factor * factor) % mod;
        exponent >>= 1;
    }
    return static_cast<int>(result);
}

const int public_key = 3;
const int private_key = 7;
const int modulus = 33;

int letter_to_num(char letter){
    if (letter == ' ') return 0;
    return letter - 'A' + 1; //A=1, B=2, ...
}

char num_to_letter(int num){
    if (num == 0) return ' ';
    return static_cast<char>('A' + num - 1);
}

std::vector<int> encrypt(std::string message, int pub_key, int mod){
    std::vector<int> encrypted;
    int cipher_val;
    int num;
    for (int i = 0; i < message.length(); i++){
        num = letter_to_num(message[i]);
        cipher_val = pow(num, pub_key, mod);
        encrypted.push_back(cipher_val);
    }
    return encrypted;
}

std::string decrypt(std::vector<int> cipher_list, int priv_key, int mod){
    std::string decrypted = "";
    int plain_val;
    for (int i = 0; i < cipher_list.size(); i++){
        plain_val = pow(cipher_list[i], priv_key, mod);
        decrypted += num_to_letter(plain_val);
    }
    return decrypted;
}

int main(){
    std::string message = "CRYPTOGRAHY IS FUN";
    std::vector<int> cipher = encrypt(message, public_key, modulus);

    std::cout << "Encrypted: ";
    for (int i = 0; i < cipher.size(); i++){
        std::cout << cipher[i];
    }
    std::cout << std::endl << "Decrypted: " << decrypt(cipher, private_key, modulus) << std::endl;
    std::cout << std::endl << "Incorrect Decrypted: " << decrypt(cipher, private_key - 1, modulus) << std::endl;


    /*
1. Run the code and observe the ciphertext (note: it will be a list of numbers).
2. Change the message and try encrypting different words.
3. Try using the wrong key to decrypt — what happens?
4. Compare this with XOR encryption:
o In XOR, the same key is used both ways.
o In this toy asymmetric system, one key encrypts and a different one decrypts.
    */
    return 0;
}