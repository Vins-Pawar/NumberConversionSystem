#include<iostream>
#include<string>
#include<math.h>
#include <stdlib.h>
#include<windows.h>

using namespace std;


string decimalToBinary(int num)
{
    string binary;
    while(num>0)
    {
        binary=char('0' + num % 2) + binary;
        //cout<<binary<<endl;;
        num=num/2;
    }
    return binary;
}

string decimalToOctal(int num)
{
    string octal;
    while(num>0)
    {
        octal=char('0'+num%8)+octal;
        num=num/8;
    }
    return octal;
}

string decimalToHexadecimal(int num)
{
    string hexadecimal;
    while(num>0)
    {
        if(num%16>9)
        {
            hexadecimal=char('A'+(num%16)-10)+hexadecimal;
        }
        else
        {
            hexadecimal=char('0'+num%16)+hexadecimal;
        }
        num=num/16;
    }
    return hexadecimal;
}

int binaryToDecimal(string binary)
{
    int decimal=0;
    for(int i=0; i<binary.length(); i++)
    {
        if(binary[i]=='1')
        {
            decimal=decimal+pow(2,binary.length()-i-1);
        }
    }
    return decimal;
}

string binaryToOctal(string binary)
{
    int decimal=binaryToDecimal(binary);
    return decimalToOctal(decimal);
}

string binaryToHexadecimal(string binary)
{
    int decimal=binaryToDecimal(binary);
    return decimalToHexadecimal(decimal);
}

int octalToDecimal(int octal)
{
    int decimal=0;
    int i=0;
    while(octal>0)
    {
        decimal=decimal+(octal%10)*pow(8,i);
        octal/=10;
        i++;
    }
    return decimal;
}

string octalToBinary(int octal)
{
    int decimal=octalToDecimal(octal);
    return decimalToBinary(decimal);
}

string octalToHexadecimal(int octal)
{
    int decimal=octalToDecimal(octal);
    return decimalToHexadecimal(decimal);
}

int hexadecimalToDecimal(string hexa)
{
    int decimal=0;
    int expo=hexa.length()-1;
    for (char digit : hexa)
    {
        int digitValue;

        if (digit >= '0' && digit <= '9')
        {
            digitValue = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            digitValue = 10 + digit - 'A';
        }
        else if (digit >= 'a' && digit <= 'f')
        {
            digitValue = 10 + digit - 'a';
        }
        else
        {
            cout << "Invalid hexadecimal digit: " << digit << endl;
            return -1;
        }

        decimal += digitValue * pow(16, expo);
        expo--;
    }

    return decimal;
}

string hexadecimalToBinary(string hexa)
{
    int decimal=hexadecimalToDecimal(hexa);
    return decimalToBinary(decimal);
}

string hexadecimalToOctal(string hexa)
{
    int decimal=hexadecimalToDecimal(hexa);
    return decimalToOctal(decimal);
}

int main()
{


    cout<<"\t\t1. Decimal to Binary"<<endl;
    cout<<"\t\t2. Decimal to Octal"<<endl;
    cout<<"\t\t3. Decimal to HexaDecimal"<<endl;


    cout<<"\t\t4. Binary to Decimal"<<endl;
    cout<<"\t\t5. Binary to Octal"<<endl;
    cout<<"\t\t6. Binary to HexaDecimal"<<endl;


    cout<<"\t\t7. Octal to Decimal"<<endl;
    cout<<"\t\t8. Octal to Binary"<<endl;
    cout<<"\t\t9. Octal to HexaDecimal"<<endl;

    cout<<"\t\t10. HexaDecimal to Decimal"<<endl;
    cout<<"\t\t11. HexaDecimal to Binary"<<endl;
    cout<<"\t\t12. HexaDecimal to Octal"<<endl;

    cout<<"\t\t13. Exit"<<endl<<endl;;

    int choice,num1;
    string num2;

    while(1)
    {

        cout<<"Enter your Choice ";
        cin>>choice;

        switch (choice)
        {

        case 1:
            cout<<"Enter Decimal Number ";
            cin>>num1;
            cout<<"Decimal to Binary "<<decimalToBinary(num1)<<endl;
            break;
        case 2:
            cout<<"Enter Decimal Number ";
            cin>>num1;
            cout<<"Decimal to Octal "<<decimalToOctal(num1)<<endl;
            break;

        case 3:
            cout<<"Enter Decimal Number ";
            cin>>num1;
            cout<<"Decimal to HexaDecimal "<<decimalToHexadecimal(num1)<<endl;
            break;


        case 4:
            cout<<"Enter Binary Number ";
            cin>>num2;
            cout<<"Binary to Decimal "<<binaryToDecimal(num2)<<endl;
            break;

        case 5:
            cout<<"Enter Binary Number ";
            cin>>num2;
            cout<<"Binary to octal "<<binaryToOctal(num2)<<endl;
            break;

        case 6:
            cout<<"Enter Binary Number ";
            cin>>num2;
            cout<<"Binary to HexaDecimal "<<binaryToHexadecimal(num2)<<endl;
            break;

        case 7:
            cout<<"Enter Octal Number ";
            cin>>num1;
            cout<<"Octal to Decimal "<<octalToDecimal(num1)<<endl;
            break;

        case 8:
            cout<<"Enter Octal Number ";
            cin>>num1;
            cout<<"Octal to Binary "<<octalToBinary(num1)<<endl;
            break;

        case 9:
            cout<<"Enter Octal Number ";
            cin>>num1;
            cout<<"Octal to HexaDecimal "<<octalToHexadecimal(num1)<<endl;
            break;


        case 10:
            cout<<"Enter HexaDecimal Number ";
            cin>>num2;
            cout<<"HexaDecimal to Decimal"<<hexadecimalToDecimal(num2)<<endl;
            break;

        case 11:
            cout<<"Enter HexaDecimal Number ";
            cin>>num2;
            cout<<"HexaDecimal to Binary"<<hexadecimalToBinary(num2)<<endl;
             break;

        case 12:
            cout<<"Enter HexaDecimal Number ";
            cin>>num2;
            cout<<"HexaDecimal to Octal"<<hexadecimalToOctal(num2)<<endl;
            break;

        case 13:
            return 0;

        default:
            cout<<"Please Enter Valid Choice..."<<endl;
            break;
        }

    }
}
