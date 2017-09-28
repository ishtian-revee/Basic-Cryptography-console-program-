#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<stdlib.h>

using namespace std;

// global variables

int crypto_key[3][3] = { { 1 , 2 , 3 },{ 1 , 1 , 2 },{ 0 , 1 , 2 } };     // cryptokey declared
char upper_case_letter[100];
int ascii = 65;
char letter_array[100];
int x = 0;
int determinant;
int adjoint_matrix[3][3];
int inverse_matrix[3][3];
char message[100];
int number[50];
int encrypted_matrix[10][10];
int encrypted_code[10][10];
int decrypted_code[10][10];
char decrypted_letter[100];

// function prototypes

void message_input();
void find_determinant();
void find_inverse_matrix();
void encryption();
void decryption();
void show_crypto_key();
void new_crypto_key();

int main()      // main function
{
    system("cls");

    for( int i=0 , j=65; i<26; i++ ){       // assigning all upper case letters (A-Z) in an array

        upper_case_letter[i] = (char)j++;
    }

    for( int i=0; i<26; i++ ){      // assigning all A-Z and a-z letters in an array

        letter_array[i] = ascii;
        letter_array[i+32] = ascii + 32;
        ascii++;
    }

    find_determinant();     // calling functions where determinant and inverse matrix will be calculated
    find_inverse_matrix();

    char choice;

    while( 1==1 ){      // infinite loop

        cout << endl << "*** CRYPTOGRAPHY ***" << endl;
        cout << endl << "All operations : " << endl;
        cout << endl << "1. Encryption " << endl;
        cout << "2. Decryption " << endl;
        cout << "3. Show Crypto-Key " << endl;
        cout << "4. Input new Crypto-key " << endl;
        cout << "5. Exit " << endl;

        cout << endl << "Enter a number (1-5) to do the operation you are willing to : ";
        choice = getche();

        system("cls");

        if( choice == '1' ){

            encryption();       // call encryption function
            x = 0;              // setting x to 0 again
        }else if( choice == '2' ){

            decryption();       // call decryption function
        }else if( choice == '3' ){

            show_crypto_key();       // call crypto_key function
        }else if( choice == '4' ){

            new_crypto_key();       // call new_crypto_key function
        }else if( choice == '5' ){

            exit(1);
        }else{

            cout << endl << "!!!.....WRONG INPUT.....!!! " << endl;
            cout << "Please , enter valid number. " << endl;
        }

        cout << endl << endl << "Press any key to get back to the main menu. " << endl;
        choice = getche();

        system("cls");
    }

}

void message_input(){       // message input function

    int i = 0 , j = 0 , k = 0;

    while( 1==1 ){      // infinite loop

        message[i] = getche();

        if( message[i] == 13 ){     // checking if user inputs 'enter'

            break;
        }else if( message[i] == 27 ){       // checking if user inputs 'escape'

            main();
        }else if( message[i] == 8 ){        // checking if user inputs 'backspace'

            if( x>0 ){

                x = x-1;
                i = i-1;
            }

            system("cls");
            cout << endl << "Enter the message : ";

            for( int t = x-1; t>=0; t-- ){      // input message string as *

                cout << "*";
            }
        }else{

            system("cls");

            j = i+1;
            k = 0;

            cout << endl << "Enter the message : ";

            while( k<j ){

                cout << "*";
                k++;
            }

            ++i;
            x++;
        }
    }
}

void find_determinant(){        // finding determinant function

    int det;
    det = 0;

    det += ( crypto_key[0][0] ) * ( crypto_key[1][1] * crypto_key[2][2] - crypto_key[1][2] * crypto_key[2][1] );

    det += ( - crypto_key[0][1] ) * ( crypto_key[1][0] * crypto_key[2][2] - crypto_key[1][2] * crypto_key[2][0] );

    det += ( crypto_key[0][2] ) * ( crypto_key[1][0] * crypto_key[2][1] - crypto_key[1][1] * crypto_key[2][0] );

    determinant = det;
}

void find_inverse_matrix(){     // find inverse matrix function

    find_determinant();

    if( determinant != 0 ){

        // calculating adjoint matrix

        adjoint_matrix[0][0] = crypto_key[1][1] * crypto_key[2][2] - crypto_key[1][2] * crypto_key[2][1];
        adjoint_matrix[0][1] = - ( crypto_key[1][0] * crypto_key[2][2] - crypto_key[1][2] * crypto_key[2][0] );
        adjoint_matrix[0][2] = crypto_key[1][0] * crypto_key[2][1] - crypto_key[1][1] * crypto_key[2][0];
        adjoint_matrix[1][0] = - ( crypto_key[0][1] * crypto_key[2][2] - crypto_key[0][2] * crypto_key[2][1] );
        adjoint_matrix[1][1] = crypto_key[0][0] * crypto_key[2][2] - crypto_key[0][2] * crypto_key[2][0];
        adjoint_matrix[1][2] = - ( crypto_key[0][0] * crypto_key[2][1] - crypto_key[0][1] * crypto_key[2][0] );
        adjoint_matrix[2][0] = crypto_key[0][1] * crypto_key[1][2] - crypto_key[0][2] * crypto_key[1][1];
        adjoint_matrix[2][1] = - ( crypto_key[0][0] * crypto_key[1][2] - crypto_key[0][2] * crypto_key[1][0] );
        adjoint_matrix[2][2] = crypto_key[0][0] * crypto_key[1][1] - crypto_key[0][1] * crypto_key[1][0];

        // calculating inverse matrix

        inverse_matrix[0][0] = adjoint_matrix[0][0] / determinant;
        inverse_matrix[0][1] = adjoint_matrix[1][0] / determinant;
        inverse_matrix[0][2] = adjoint_matrix[2][0] / determinant;
        inverse_matrix[1][0] = adjoint_matrix[0][1] / determinant;
        inverse_matrix[1][1] = adjoint_matrix[1][1] / determinant;
        inverse_matrix[1][2] = adjoint_matrix[2][1] / determinant;
        inverse_matrix[2][0] = adjoint_matrix[0][2] / determinant;
        inverse_matrix[2][1] = adjoint_matrix[1][2] / determinant;
        inverse_matrix[2][2] = adjoint_matrix[2][2] / determinant;
    }else{

        cout << endl << "!!!.....ERROR.....!!!" << endl;
        cout << "Determinant can't be 0." << endl;
        cout << "If determinant is equal to 0 then there will be no inverse matrix." << endl;
    }
}

void encryption(){      // encryption function

    cout << endl << "Enter the message : ";
    message_input();       // input a message string

    if( x%3 == 0 ){

        for( int i=0; i<x; i++ ){

            for( int j=0; j<26; j++ ){

                if( ( message[i] == letter_array[j] ) || ( message[i] == letter_array[j+32] ) ){

                    number[i] = j+1;        // comparing message character to it's corresponding decimal digit
                }                           // and store those digits in number array
            }
        }

        for( int i=0 , a=0; i<x/3; i++ ){     // putting those digits in a matrix

            for( int j=0; j<3; j++ ){

                encrypted_matrix[i][j] = number[a];
                a++;
            }
        }

        cout << endl << endl << "Encrypted matrix is :\t";

        for( int i=0; i<x/3; i++ ){     // displaying the matrix of digits corresponding to message characters

            for( int j=0; j<3; j++ ){

                cout << encrypted_matrix[i][j] << "\t";
            }

            cout << endl << "\t\t\t";
        }

        cout << endl << "Encrypted code is : ";
        int sum;

        for( int i=0; i<x/3; i++ ){       // calculate encrypted code by matrix multiplication

            for( int j=0; j<3; j++ ){

                sum = 0;

                for( int k=0; k<3; k++ ){       // matrix multiplication between crypto-key and encrypted matrix

                    sum += crypto_key[j][k] * encrypted_matrix[i][k];
                }

                encrypted_code[i][j] = sum;
            }
        }

        for( int i=0; i<x/3; i++ ){       // displaying encrypted code

            for( int j=0; j<3; j++ ){

                cout << encrypted_code[i][j] << " ";
            }
        }
    }else{

        cout << endl << "!!!.....ERROR.....!!! " << endl;
        cout << "String length must be divisible by 3. " << endl;
    }
}

void decryption(){      // decryption function

    int num;

    cout << endl << "Enter number of elements : ";
    cin >> num;     // input total number of elements

    if( num%3 == 0 ){

        cout << endl << endl << "Enter encrypted codes : ";

        for( int i=0; i<num/3; i++ ){       // input encrypted codes

            for( int j=0; j<3; j++ ){

                cin >> encrypted_code[i][j];
            }
        }

        int sum;

        for( int i=0; i<num/3; i++ ){       // calculate decrypted code by matrix multiplication

            for( int j=0; j<3; j++ ){

                sum = 0;

                for( int k=0; k<3; k++ ){       // matrix multiplication between inverse matrix and encrypted code

                    sum += inverse_matrix[j][k] * encrypted_code[i][k];
                }

                decrypted_code[i][j] = sum;
            }
        }

        cout << endl << "Decrypted code is : ";

        for( int i=0; i<num/3; i++ ){       // display decrypted code

            for( int j=0; j<3; j++ ){

                cout << decrypted_code[i][j] << " ";
            }
        }

        int a = 0;

        for( int i=0; i<num/3; i++ ){       // converting decimal digits to it's corresponding alphabet

            for( int j=0; j<3; j++ ){

                for( int k=1; k<=26; k++ ){

                    if( decrypted_code[i][j] == k ){

                        decrypted_letter[a] = upper_case_letter[k-1];
                    }
                }

                a++;
            }
        }

        cout << endl << endl << "Decrypted message is : ";

        for( int i=0; i<num; i++ ){     // show decrypted message

            cout << decrypted_letter[i] << " ";
        }
    }else{

        cout << endl << "!!!.....ERROR.....!!! " << endl;
        cout << "Number of elements must be divisible by 3." << endl;
    }
}

void show_crypto_key(){      // show crypto-key function

    cout << endl << "Crypto-key :\t\t";

    for( int i=0; i<3; i++ ){       // display crypto-key

        for( int j=0; j<3; j++ ){

            cout << crypto_key[i][j] << "\t";
        }

        cout << endl << "\t\t\t";
    }

    cout << endl << endl << "Inverse matrix :\t";

    for( int i=0; i<3; i++ ){       // display inverse matrix of crypto-key

        for( int j=0; j<3; j++ ){

            cout << inverse_matrix[i][j] << "\t";
        }

        cout << endl << "\t\t\t";
    }
}

void new_crypto_key(){      // new crypto-key function

    for( int i=0; i<3; i++ ){       // clear default crypto-key

        for( int j=0; j<3; j++ ){

            crypto_key[i][j] = 0;       // insert 0 to every index of crypto-key matrix
            adjoint_matrix[i][j] = 0;       // insert 0 to every index of adjoint matrix
            inverse_matrix[i][j] = 0;       // insert 0 to every ndex of inverse matrix
        }
    }

    cout << endl << "Enter the elements of the new crypto-key ( 3*3 matrix ) : ";

    for( int i=0; i<3; i++ ){       // insert new crypto-key elements

        for( int j=0; j<3; j++ ){

            cin >> crypto_key[i][j];
        }
    }

    cout << endl << "The new crypto-key is :\t";

    for( int i=0; i<3; i++ ){       // display new crypto-key

        for( int j=0; j<3; j++ ){

            cout << crypto_key[i][j] << "\t";
        }

        cout << endl << "\t\t\t";
    }

    cout << endl << endl << "New crypto-key has been inserted successfully." << endl;

    find_determinant();     // calling functions where determinant and inverse matrix will be calculated
    find_inverse_matrix();

    if( determinant != 0 ){

        cout << endl << endl << "Inverse matrix :\t";

        for( int i=0; i<3; i++ ){       // show inverse matrix of new crypto-key

            for( int j=0; j<3; j++ ){

                cout << inverse_matrix[i][j] << "\t";
            }

            cout << endl << "\t\t\t";
        }
    }
}
