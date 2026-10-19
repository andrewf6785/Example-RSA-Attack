# Using Adaptive Chosen Ciphertext Attack (IND-CCA2) to attack traditional RSA

[Run demo](#running)

My RSA recreation (located here and also located <https://github.com/andrewf6785/RSA-Recreation-Cpp-Python>) does not use OAEP, or Optimal Asymmetric Encryption Padding, which pads the plaintext with random data before RSA encryption, making it non-deterministic.

This gives me a good opportunity to play with a Chosen Ciphertext attack, which allows an attacker to compute an original ciphertext, c, without knowing the private key d or, (obviously), the original message m.

## How does this work?

Traditional RSA without OAEP is what's known as malleable, meaning that an attacker can modify ciphertext in a structured way so when it is decrypted the resulting plaintext is altered predictably.

Mathematically:

suppose we know that the ciphertext we want to decrypt, c, is equal to `m^e (mod n)` (the traditional RSA encryption algorithm)

`c = m^e (mod n)`

we can calculate `c' = c * 2^e (mod n)`

and then ask for the decryption of c'

`(c')^d == m^e * 2^e == 2m (mod n)`

then, we simply multiply `(c')^d` by the inverse of 2 modulo n and we can get the original plaintext, m

I have placed a demonstration of this in ACCA.cpp:

## RUNNING

run `'make'` from the home directory, then run attack.exe

or

run the following command from `/RSA-Recreation-Cpp-Python/cppAlgos`

```
g++ -O2 -o attack bigInt/bigInt.cpp randomNumberGenerator/randomNumberGenerator.cpp decrypt.cpp ../../ACCA.cpp eea.cpp encrypt.cpp keys.cpp miller_rabin.cpp modexp.cpp pickPrime.cpp commonPrimeCheck.cpp montgomeryConstant.cpp montgomeryModularExpo.cpp montgomeryReduction.cpp
```

