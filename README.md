# Affine Cipher & Polynomial Hash

## 1. Affine Cipher

The Affine Cipher is a **simple way to encrypt text** by mixing multiplication and addition. Each letter is first converted to a number, then scrambled using this formula:E(x) = (a * x + b) mod m


- **x**: number representing the letter  
- **a, b**: keys (a must be coprime with m)  
- **m**: number of letters in the alphabet  

To decrypt, we reverse the process:D(y) = a_inv * (y - b) mod m
## 2. Polynomial Hash

Polynomial Hash turns a string into a **single number** so it’s easier to compare or store. 

It works like this:H(s) = (s0 * p^(n-1) + s1 * p^(n-2) + ... + sn-1 * p^0) mod m

- **s0, s1, …**: numeric values of the characters  
- **p**: a small prime number base  
- **m**: a large prime to reduce collisions  

## Why Use Polynomial Hash

Polynomial Hash is used to **convert strings into numeric values**, making it easier and faster to compare or store them.  
It helps in **detecting even small changes** in strings, which is useful for validation or error checking.  
By using a prime number as the base and modulo, it **reduces collisions**, so different strings usually get different hash values.  
It also supports **rolling hash techniques**, allowing quick substring searches without recomputing the entire hash.  
Overall, it is an **efficient and reliable** way to handle string comparison and processing in algorithms.

## Authentication Type A
A hash of the message is first generated using the Hash function.
This hash is then concatenated with the original message to create a combined data block.
The combined data is encrypted using the Affine Cipher before being sent.
At the receiver’s end, the data is decrypted and split into the hash and the original message.
The receiver recomputes the hash of the message and compares it with the received hash.
If the hashes match, authentication is successful; otherwise, it is unsuccessful.

## Instructions to Run:

- Clone the repository
- Open terminal and navigate to the project folder
- Run the file : c++ hash_authentication.cpp, affine.cpp
- Enter the plaintext message
- View the hash, encrypted output, decrypted value, and authenticate the result


