/**
 * @file assignment_1.cpp
 * @author Rose Richards (rricha58@skyhawks.utm.edu)
 * @brief The first part of the Cryptographic Tools assignment
 * @version 0.5
 * @date 2026-10-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <fstream>

int ord(char x){
    return x;
}

char chr(int x){
    char y = (char)x;
    return y;
}

std::string xor_encrypt(std::string message, int key){
    std::string encrypted = "";
    char encrypted_char;
    for (int i = 0; i < message.length(); i++){
        encrypted_char = chr(ord(message[i]) ^ key);
        encrypted += encrypted_char;
    }
    return encrypted;
}

std::string xor_decrypt(std::string cipher, int key){
    std::string decrypted = "";
    char decrypted_char;
    for (int i = 0; i < cipher.length(); i++){
        decrypted_char = chr(ord(cipher[i]) ^ key);
        decrypted += decrypted_char;
    }
    return decrypted;
}

/*
1. Run the starter code and observe the results.
2. Change the value of the key and see how the ciphertext changes.
3. Try encrypting a longer message, such as "CRYPTOGRAPHY IS FUN".
4. Experiment by using the wrong key for decryption. What happens?
5. (Optional challenge) Read text from a file, encrypt it, save it, and then
decrypt it back.
*/

int main(){
    std::string message;
    int key;
    std::fstream file("mockDB.txt");
    std::getline(file, message);
    file >> key;
    
    std::string cipher = xor_encrypt(message, key);
    file << cipher;

    std::cout << std::fixed << "Encrypted: " << cipher << std::endl 
    << "Decrypted: " << xor_decrypt(cipher, key) << std::endl
    << "Incorrect Decryption: " << xor_decrypt(cipher, key + 1);

    file.close();
    return 0;
}