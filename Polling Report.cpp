#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Voter 
{
    string candidate;
    bool citizen; // true or false
    bool registered; // true or false
    int age;
    int zip; // in 5 digits only
    char gender; // F or M
    char ethnicity; // A, C, N, S, H, I
    char degree; // N, H, A, B, M, P
    
};

//By the way, the Ms in a variable mean Male and the Fs in a variable mean Female
float obamaTotalPercent, trumpTotalPercent, albernteTotalPercent;
float obamaMpercent, obamaFpercent;
float trumpMpercent, trumpFpercent;
float albernteMpercent, albernteFpercent;
float obamaAvgAge = 0, trumpAvgAge = 0, albernteAvgAge = 0;
float totalVoters = 8.0;
float trumpTally = 0.0, albTally = 0.0, obamaTally = 0.0;
float tmTally = 0.0, tfTally = 0.0, omTally = 0.0, ofTally = 0.0, amTally = 0.0, afTally = 0.0;
const int  ARRAY_SIZE = 8;
int option;
Voter voterArray[ARRAY_SIZE];
ifstream inFile;

void readFile();
void selection();
void candPerc();
void genderPerc();
void avgAge();
void tally();
void statMath();

int main ()
{
    string fileName = "voterinfo.dat";
    string inputFile;
    cout << "Welcome to the Hood Polling Report" << endl;
    cout << "Enter input file name: ";
    cin >> inputFile;
    do
    {
        if (inputFile == fileName)
        {
            cout << "1 Candidate Percentages\n"
                << "2 Percent Male/Female\n"
                << "3 Average Age\n"
                << "4 Quit" << endl;
            cout << "Option: ";
            cin >> option;
            break;
        }
        else
        {
            cout << "Input file " << inputFile << " does not exist. Please try again." << endl;
            cout << "Enter input file name: ";
        }
    }
    while (cin >> inputFile);
    readFile();
    tally();
    statMath();
    selection();    
}

//This function reads the file from "voterinfo.dat" into the voter array of structures
void readFile()
{
    int i;
    inFile.open("voterinfo.dat");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        inFile >> voterArray[i].candidate;
        inFile >> voterArray[i].citizen;
        inFile >> voterArray[i].registered;
        inFile >> voterArray[i].age;
        inFile >> voterArray[i].zip;
        inFile >> voterArray[i].gender;
        inFile >> voterArray[i].ethnicity;
        inFile >> voterArray[i].degree;      
    }
    inFile.close();
}

//This function works the menu
void selection()
{
    while (cin)
    {
        if (option == 1)
        {
            candPerc();
            cout << "1 Candidate Percentages\n"
                 << "2 Percent Male/Female\n"
                 << "3 Average Age\n"
                 << "4 Quit" << endl;
            cout << "Option: "; 
            cin >> option;
        }
        else if (option == 2)
        {
            genderPerc();
            cout << "1 Candidate Percentages\n"
                 << "2 Percent Male/Female\n"
                 << "3 Average Age\n"
                 << "4 Quit" << endl;
            cout << "Option: "; 
            cin >> option;
        }
        else if (option == 3)
        {
            avgAge();
            cout << "1 Candidate Percentages\n"
                 << "2 Percent Male/Female\n"
                 << "3 Average Age\n"
                 << "4 Quit" << endl;
            cout << "Option: "; 
            cin >> option;
        }
        else if (option == 4)
        {
            cout << "Thank you for using the Hood Polling Report." << endl << endl;
            break;
        }
        else 
        {   
            cout << "Incorrect option choice. Please try again." << endl << endl;
            cout << "1 Candidate Percentages\n"
                 << "2 Percent Male/Female\n"
                 << "3 Average Age\n"
                 << "4 Quit" << endl;
            cout << "Option: "; 
            cin >> option;
        }  
    }
}

//This function outputs the Candidate Percentage table
void candPerc()
{
    cout << "Candidate" << right << setw(40) << "Percentage Polled" << endl;
    for(int i = 0; i < 49; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << fixed << showpoint << setprecision(1);
    cout << left << setw(44) << "Obama" << right << obamaTotalPercent << "%" << endl;
    cout << left << setw(44) << "Albernte" << right << albernteTotalPercent << "%" << endl;
    cout << left << setw(44) << "Trump" << right << trumpTotalPercent << "%" << endl;
    cout << endl;
}

//This table outputs the Gender Percentage for each candidate in a table
void genderPerc()
{
    cout << "Candidate" << right << setw(20) << "Male" << setw(20) << "Female" << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << fixed << showpoint << setprecision(1);
    cout << left << setw(24) << "Obama" << obamaMpercent << "%" << setw(20) << right << obamaFpercent << "%" << endl;
    cout << left << setw(25) << "Albernte" << albernteMpercent << "%" << setw(20) << right << albernteFpercent << "%" << endl;
    cout << left << setw(24) << "Trump" << trumpMpercent << "%" << setw(20) << right << trumpFpercent << "%" << endl;
    cout << endl;
}

//This function outputs the average age of the voters for each candidate
void avgAge()
{
    cout << "Candidate" << right << setw(40) << "Average Age" << endl;
    for(int i = 0; i < 49; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << fixed << showpoint << setprecision(1);
    cout << left << setw(44) << "Obama" << right << obamaAvgAge << "%" << endl;
    cout << left << setw(44) << "Albernte" << right << albernteAvgAge << "%" << endl;
    cout << left << setw(44) << "Trump" << right << trumpAvgAge << "%" << endl;
    cout << endl;
}

//This function tallies up the total votes for each candidate, including the votes for each gender
void tally()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (voterArray[i].candidate == "Trump")
            trumpTally++;
        else if (voterArray[i].candidate == "Obama")
            obamaTally++;
        else if (voterArray[i].candidate == "Albernte")
            albTally++;
        else
            cout << "Error reading file." << endl;
    }
        
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (voterArray[i].candidate == "Trump" && voterArray[i].gender == 'M')
            tmTally++;
        else if(voterArray[i].candidate == "Trump" && voterArray[i].gender == 'F')
            tfTally++;
        else if (voterArray[i].candidate == "Obama" && voterArray[i].gender == 'M' )
            omTally++;
        else if (voterArray[i].candidate == "Obama" && voterArray[i].gender ==  'F')
            ofTally++;
        else if (voterArray[i].candidate == "Albernte" && voterArray[i].gender == 'M')
            amTally++;
        else if (voterArray[i].candidate == "Albernte" && voterArray[i].gender == 'F')
            afTally++;
    }
}

//This function calculates the percentages and the ages to be outputted
void statMath()
{
    obamaTotalPercent = (obamaTally / totalVoters) * 100;
    trumpTotalPercent = (trumpTally / totalVoters) * 100;
    albernteTotalPercent = (albTally / totalVoters) * 100; 
    
    obamaMpercent = (omTally / obamaTally) * 100;
    obamaFpercent = (ofTally / obamaTally) * 100;
    
    trumpMpercent = (tmTally / trumpTally) * 100;
    trumpFpercent = (tfTally / trumpTally) * 100;
    
    albernteMpercent = (amTally / albTally) * 100;
    albernteFpercent = (afTally / albTally) * 100;
    
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (voterArray[i].candidate == "Obama")
            obamaAvgAge = obamaAvgAge + voterArray[i].age;
        else if (voterArray[i].candidate == "Trump")
            trumpAvgAge = trumpAvgAge + voterArray[i].age;
        else if (voterArray[i].candidate == "Albernte")
            albernteAvgAge = albernteAvgAge + voterArray[i].age;
    }
    obamaAvgAge = (obamaAvgAge / obamaTally);
    trumpAvgAge = (trumpAvgAge / trumpTally);
    albernteAvgAge = (albernteAvgAge / albTally);
}
