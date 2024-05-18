/*
For this question you will be creating a main function which will allow a user to interact with your program by providing their own 
target and input tunes. Your main function should present the user with a menu containing the following options:

Calculate the similarity between two tunes of the same length
Calculate the best similarity between two tunes of either equal or unequal length
Print three input tunes in order from most to least similar to the target tune
Exit
Your menu should run on a loop, continually offering the user each option until they choose to exit. Be sure to use the functions you wrote in questions 2 through 6.

Note: Your main function should account for any user input that isn't in valid SPN. If user input is not in valid SPN your program should print "Invalid input.
 Please enter a tune in valid SPN:" until the user enters valid SPN.

--- Sample Run 1--- (> indicates user input)

--- Menu ---
1. Calculate similarity between two tunes.
2. Calculate best similarity between two tunes of potentially different lengths.
3. Print three input tunes in order from most to least similar to the target tune.
4. Exit.
Please enter your choice (1 - 4):
> 6
Invalid input.
--- Menu ---
1. Calculate similarity between two tunes.
2. Calculate best similarity between two tunes of potentially different lengths.
3. Print three input tunes in order from most to least similar to the target tune.
4. Exit.
Please enter your choice (1 - 4):
> 1
Please enter the first tune:
> Hello!
Invalid input. Please enter a tune in valid SPN:
> A2F5G7B8
Please enter the second tune:
> F2B5G1D2
The similarity score is: -0.75
--- Menu ---
1. Calculate similarity between two tunes.
2. Calculate best similarity between two tunes of potentially different lengths.
3. Print three input tunes in order from most to least similar to the target tune.
4. Exit.
Please enter your choice (1 - 4):
> 4
Goodbye!
--- Sample Run 2--- (> indicates user input)

--- Menu ---
1. Calculate similarity between two tunes.
2. Calculate best similarity between two tunes of potentially different lengths.
3. Print three input tunes in order from most to least similar to the target tune.
4. Exit.
Please enter your choice (1 - 4):
> 2
Please enter the input tune:
> B3E1D7G4E1
Please enter the target tune:
> E3G2D7
The best similarity score is: 0.33
--- Menu ---
1. Calculate similarity between two tunes.
2. Calculate best similarity between two tunes of potentially different lengths.
3. Print three input tunes in order from most to least similar to the target tune.
4. Exit.
Please enter your choice (1 - 4):
> 1
Please enter the first tune:
> F4D1A0E9B6
Please enter the second tune:
> E4F1D0
The similarity score is 0.00
--- Menu ---
1. Calculate similarity between two tunes.
2. Calculate best similarity between two tunes of potentially different lengths.
3. Print three input tunes in order from most to least similar to the target tune.
4. Exit.
Please enter your choice (1 - 4):
> 3
Please enter the first tune:
> C0D9E3A5
Please enter the second tune:
> D7E2A4F9G1
Please enter the third tune:
> A8B1D4
Please enter the target tune:
> B7D5
1) Tune 3, 2) Tune 1, 3) Tune 2
--- Menu ---
1. Calculate similarity between two tunes.
2. Calculate best similarity between two tunes of potentially different lengths.
3. Print three input tunes in order from most to least similar to the target tune.
4. Exit.
Please enter your choice (1 - 4):
> 4
Goodbye!
*/

/*
CSCI 1300 Fall 2022
Author: Fedor Vlasov
Reatation: 104 - Lilac Intrater
Project 1 - Problem#7
*/
/*
1.
*/


 #include <iostream>
 #include <cassert>
 #include <iomanip>

//////////////////////////////////////#1
bool isValidNote (string note) {
    if (note.length() !=2) {
        return false;
    }   

else if (note[0] != 'A' && note[0] != 'B' && note[0] != 'C' && note[0] != 'D' && note[0] != 'E' && note[0] != 'F' && note[0] != 'G'){
    return false;
    }

    else if (note[1] != '0' && note[1] != '1' && note[1] != '2' && note[1] != '3' && note[1] != '4' && note[1] != '5' && note[1] != '6' && note[1] != '7' && note[1] != '8' && note[1] != '9'){
    return false;
    }
    
    else {
        return true;
    }

}
//////////////////////////////////////#2
bool isValidTune(string tune){

for (int i = 0; i < tune.length(); i = i +2 ) {  

    if (!(isValidNote(tune.substr(i,2)))) {
    return false;
    
}

}
    return true;
}
//////////////////////////////////////#3
int match = 0; //#of matches

 int numValidNotes(string input) {

    for(int i =0; i < input.length(); i+=2) {
        input.substr(i,2);   
          if (input.substr (i,2)) {
match = match +1;
    }
    }

return match;
 }
//////////////////////////////////////#4
double tuneSimilarity(string tune1, string tune2) {
    int tune1Length = tune1.length();   //setting variables for length
    int tune2Length = tune2.length();
double total =0;
double sim =0;
double plus =0;
double minus =0;
double notes =0;


     if (tune1Length != tune2Length) {  //if the 2 strings are not the same length return 0;
return 0;
     }


     

        for (int i = 0; i < tune1Length; i+=2){
if (tune1[i] == tune2[i]) {
sim++;                              //add simularity if 1 charecter is the same in both strings 
}
if(tune1[i] == tune2[i] && tune1[i+1] == tune2[i+1]) {
    plus++;                         //add simularity score if 2 charectors are same in 2 strings in a row
}
if (tune1[i] != tune2[i] && tune1[i+1] != tune2[i+1]){
    minus++;                        //subtract simularity score if 2 charectors in 2 strings are different in a row
}

notes++;     //ammount of inputs
}
double simularity =0;
simularity = ((sim/notes) + plus - minus);    // simularity / ammount of notes + added sim score - subtracted sim score
return simularity;
     }
//////////////////////////////////////#5
 double bestSimilarity(string inputTune, string targetTune){
     if (inputTune.length() < targetTune.length()) { 
return 0;
     }
double simularity_score = -99999;       //so the input will be larger then simularity_score
 for (int i =0; i < 2*((inputTune.length() - targetTune.length())/2+1); i+=2){
if (simularity_score < tuneSimilarity(inputTune.substr(i,targetTune.length()), targetTune)) {
simularity_score = tuneSimilarity(inputTune.substr(i,targetTune.length()), targetTune);
}
 }
 return simularity_score;
 }
 

//////////////////////////////////////#6

  void printTuneRankings(string tune1, string tune2, string tune3, string targetTune) {

double final1 = bestSimilarity(tune1,targetTune);
double final2 = bestSimilarity(tune2,targetTune);
double final3 = bestSimilarity(tune3,targetTune);



if (final1 >= final2 && final2 >= final3) {
    cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
}
else if (final1 >= final3 && final3 > final2) {
    cout << "1) Tune 1, 2) Tune 3, 3) Tune 2" << endl;
}
else if (final2 > final1 && final1 >= final3) {
    cout << "1) Tune 2, 2) Tune 1, 3) Tune 3" << endl;
}
else if (final2 >= final3 && final3 > final1) {
    cout << "1) Tune 2, 2) Tune 3, 3) Tune 1" << endl;
}
else if (final3 > final1 && final1 >= final2) {
    cout << "1) Tune 3, 2) Tune 1, 3) Tune 2" << endl;
}

else if (final3 > final2 && final2 > final1) {
    cout << "1) Tune 3, 2) Tune 2, 3) Tune 1" << endl;
}

 }
 

 ////////////////////////////////////// MAIN


int main(){
    int option; 
    string inputT; 
    string tune1; 
    string tune2; 
    string tune3; 
    string tune1st;   
    string tune2nd;   
    string targetT; 
    string targetT2; 
while {
    cout<<"--- Menu ---"<<endl;
    cout<<"1. Calculate similarity between two tunes."<<endl;
    cout<<"2. Calculate best similarity between two tunes of potentially different lengths."<<endl;
    cout<<"3. Print three input tunes in order from most to least similar to the target tune." <<endl;
    cout<<"4. Exit."<<endl;
    cout<<"Please enter your choice (1 - 4):"<<endl;
    cin>>option;
    if(option < 1 || option > 4){
        cout<<"Invalid Input."<<endl;
    cout<<"--- Menu ---"<<endl;
    cout<<"1. Calculate similarity between two tunes."<<endl;
    cout<<"2. Calculate best similarity between two tunes of potentially different lengths."<<endl;
    cout<<"3. Print three input tunes in order from most to least similar to the target tune." <<endl;
    cout<<"4. Exit."<<endl;
    cout<<"Please enter your choice (1 - 4):"<<endl;
    cin>>option;
    }
    if(option == 4){
        cout<<"Goodbye!"<<endl;
        return 0;
    }
switch(option){
    case 1:
    cout<<"Please enter the first tune:"<<endl;
    cin >>tune1st;
    while(isValidTune(tune1st) != true){
        cout<< "Invalid input. Please enter a tune in valid SPN:"<<endl;
        cin>>tune1st;
    }
    cout<<"Please enter the second tune:"<<endl;
    cin >>tune2nd;
    while(isValidTune(tune2nd) != true){
        cout<< "Invalid input. Please enter a tune in valid SPN:"<<endl;
        cin>>tune2nd;
    }
    cout<<"The similarity score is "<< fixed<< setprecision(2)<<tuneSimilarity(tune1st, tune2nd)<<endl;
    break;
    case 2:
    cout<<"Please enter the input tune:"<<endl;
    cin>>input_tune;
    while(isValidTune(inputT) != true){
        cout<< "Invalid input. Please enter a tune in valid SPN:"<<endl;
        cin >>inputT;
    }
    cout<<"Please enter the target tune:"<<endl;
    cin>>targetT;
    while(isValidTune(targetT) != true){
        cout<< "Invalid input. Please enter a tune in valid SPN:"<<endl;
        cin >>targetT;
    }
    cout<<"The best similarity score is: "<< fixed<< setprecision(2)<<bestSimilarity(inputT, targetT)<<endl;  //fix something to do with sepresision
    break;
    case 3:
         cout<<"Please enter the first tune:"<<endl;
         cin>>tune1;
         while(isValidTune(tune1) != true){
            cout<< "Invalid input. Please enter a tune in valid SPN:"<<endl;
            cin>>tune1;
         }
         cout<<"Please enter the second tune:"<<endl;
         cin>>tune2;
         while(isValidTune(tune2) != true){
            cout<< "Invalid input. Please enter a tune in valid SPN:"<<endl;
            cin>>tune2;
         }
         cout<<"Please enter the third tune:"<<endl;
         cin>>tune3;
         while(isValidTune(tune3) != true){
            cout<< "Invalid input. Please enter a tune in valid SPN:"<<endl;
            cin>>tune3;
         }
         cout<<"Please enter the target tune:"<<endl;
         cin>>targetT2;
         while(isValidTune(targetT2) != true){
            cout<< "Invalid input. Please enter a tune in valid SPN:"<<endl;
            cin>>targetT2;
         }
         printTUneRankings(tune1,tune2,tune3,targetT2);
         break;

         case 4:
         cout <<"Goodbye!"<<endl;
            return 0;
            break;
        default:
            if(option == 4){
                cout <<"Goodbye!"<<endl;
            return 0;
            }
            cout<< "Invalid Input."<<endl;
    cout<<"--- Menu ---"<<endl;
    cout<<"1. Calculate similarity between two tunes."<<endl;
    cout<<"2. Calculate best similarity between two tunes of potentially different lengths."<<endl;
    cout<<"3. Print three input tunes in order from most to least similar to the target tune." <<endl;
    cout<<"4. Exit."<<endl;
    cout<<"Please enter your choice (1 - 4):"<<endl;
    cin>>option;
    break;
}
}
}
while(option<= 3 && option >= 1) {
if(option == 4)
    {
        cout <<"Goodbye!"<<endl;
        return 0;
        }
}
