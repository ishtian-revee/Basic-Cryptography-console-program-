# Basic Cryptography (console program)

This is a console program of a very basic cryptography technique. This program
is written in c++ programming language.

This program contains total of 4 basic operations of cryptography technique.
These are:

* Encryption
* Decryption
* Show crypto-key
* Input new crypto-key

## Initial Step

Initially a secret key (crypto-key) is given which is:

`int crypto_key[3][3] = { { 1 , 2 , 3 },{ 1 , 1 , 2 },{ 0 , 1 , 2 } };`

Now, based on this crypto-key two functions are being called in the main
function which are: `find_determinant();` and `find_inverse_matrix();`

The first function is calculating the determinant from the crypto-key and the
second function firstly calculating the adjoint matrix from the crypto-key and
finally calculating the inverse matrix by using that determinant.

**[Note: Determinant can't be 0. If determinant is equal to 0 then there will be no inverse matrix.]**

## Encryption

After choosing the Encryption option the program calls for an user input which
is nothing but the message that needs to be encrypted.

As this is a basic cryptography technique the user has to input a string
which has the length divisible by n. Because, here the given crypto-key is
m*n matrix. [Here, for the given crypto-key m=3 and n=3] Otherwise, the program
will display an error message.

Example:

User input: `irevee` [which has the length divisible by 3]

After inserting the message it will show the encrypted matrix which is nothing but
the corresponding digits of each and every letters of the message as a m*n matrix.

Finally, it will print an encrypted code or the secret code of that message. For this
example the code is: `60 37 28 47 37 15`

## Decryption

After choosing Decryption option the program at fist calls for an user input of the
number of elements. That means it is asking for the number of elements of the secret
code. For our example we have total 6 elements in our secret code. So, the user input will
be: `6`

Then user have to insert those elements of the secret code sequentially. For this
example user input will be: `60 37 28 47 37 15`

After inserting the code it will show the decrypted matrix which is nothing but
the corresponding digits of each and every letters of the message as a m*n matrix.

And finally, it will display the actual message that had been encrypted first. For
this example we get the message: `IREVEE` [message will be in upper case]

## Show crypto-key

After choosing the Show Crypto-key option the program will display the crypto-key
that has been given as well as the inverse matrix which was also calculated in the
beginning.

## Input new crypto-key

After choosing the Input New Crypto-key option the program will ask for the elements
of the new crypto-key.

**[Note: For this program user has to input total 9 digits because the crypto-key
is itself a 3*3 matrix which can contain total 9 elements.]**

## Exit

Choosing Exit means it will close the program.
