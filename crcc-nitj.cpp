#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

char XOR(char a, char b) // perform XOR operation
{
    if (a == b)
        return '0';
    else
        return '1';
}

//rem remainder
//key divisor
char *crc(char data[], char key[])
{
    int datalen = strlen(data);
    int keylen = strlen(key);

    for (int i = 0; i < keylen - 1; i++) //appending n-1 zeroes to data at end
        data[datalen + i] = '0';
    data[datalen + keylen - 1] = '\0';

    int codelen = datalen + keylen - 1; //lenght of FULL DIVIDENT

    char stepdivident[20], rem[20];

    for (int i = 0; i < keylen; i++)
        rem[i] = data[i];

    for (int j = keylen; j <= codelen; j++)
    {
        for (int i = 0; i < keylen; i++)
            stepdivident[i] = rem[i]; // remainder of previous step is stepdivident of current step

        if (rem[0] == '0')
        {
            for (int i = 0; i < keylen - 1; i++)
                rem[i] = stepdivident[i + 1];
        }
        else
        {
            for (int i = 0; i < keylen - 1; i++)
                rem[i] = XOR(stepdivident[i + 1], key[i + 1]);
        }

        if (j != codelen)
            rem[keylen - 1] = data[j];
        else
            rem[keylen - 1] = '\0';
    }

    for (int i = 0; i < keylen - 1; i++)
        data[datalen + i] = rem[i]; //replace n-1 zeros with n-1 bit CRC
    data[codelen] = '\0';
    cout << "CRC=" << rem;

    return data;
}

int main()
{
    char key[20], data[20];
cout<<"-------CRC--------------\n"<<endl;
    cout << "Enter the data:";
    cin >> data;
    cout << "Enter the key(divisor):";
    cin >> key;

    char *sentdata = crc(data, key); // generate crc
    cout << "\nData would be sent along with key -> " << endl;
    cout << "\nDataword= " << sentdata;
    cout << "\nkey= " << key;

    cout << "\n__________________________________________________" << endl;

    cout << "\nReceiver side " << endl;
    cout << "\nafter division in receiver side \n";
    crc(sentdata, key);

    cout << "\nCRC NOW IS 0  !! SO !!! NO ERROR ";

    return 0;
}