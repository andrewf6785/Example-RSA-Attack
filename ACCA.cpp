// Adaptive Chosen Ciphertext Attack (IND-CCA2)
// This is a short example of a chosen ciphertext attack on traditional RSA. Traditional RSA does not use 
// OAEP, or Optimal Asymmetric Encryption Padding, which pads the plaintext with random data before RSA encryption,
// making it non-deterministic. 


#include <iostream>
#include "RSA-Recreation-Cpp-Python/cppAlgos/bigInt/bigInt.h"
#include "RSA-Recreation-Cpp-Python/cppAlgos/modexp.h"
#include "RSA-Recreation-Cpp-Python/cppAlgos/keys.h"
#include "RSA-Recreation-Cpp-Python/cppAlgos/encrypt.h"
#include "RSA-Recreation-Cpp-Python/cppAlgos/decrypt.h"

// first, calculate c prime from a known ciphertext c
largeInt getCPrime(largeInt& e, largeInt& c, largeInt& n){
    // we do this by asking for the encrpytion of c multiplied by 2^e (our public key) modulo n (also part of the public key)
    return c*(modexp(2,e,n)); 
}


int main(){
    // generate a pair of RSA keys for this exercise:
    std::cout<<"Generating keys"<<std::endl;
    auto [n,e,d]= keys();

    //std::cout<<"n: "<<n<<std::endl;

    //std::cout<<"Public key e\n"<<e<<std::endl;

    //std::cout<<"Private key d\n"<<d<<std::endl;


    // let's say we have a secret, m, that we want to know. For this purpose, let's say we do not know that m=1234.
    largeInt m = 1234;
    largeInt c = encrypt(m,e,n);


    // for this exploit to work, you also assume that you have access to a decryption oracle which allows you to decrypt
    // certain allowed ciphertexts, but won't allow you to decrypt the original c
    // calculate cPrime = c * 2^e (mod n)
    std::cout<<"Calculating cPrime"<<std::endl;
    largeInt cPrime = getCPrime(e,c,n);

    // then, ask for the decryption of cPrime
    largeInt pPrime = decrypt(cPrime,d,n);

    // pPrime == 2m (mod n)
    // so multiplying by the modular inverse of 2 modulo n will give us m, the original plaintext
    std::cout<<"Calculating recovered plaintext"<<std::endl;
    largeInt recoveredPlaintext = (pPrime * ((n+1)/2)) % n;

    std::cout<<"Recovered plaintext: "<<recoveredPlaintext<<std::endl;

    return 0;
}


