#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void initializeArray(char arr[]) {
    const char source[] = "apple,orange,banana,elephant,tiger,laptop,keyboard,piano,rocket,umbrella,gorilla,monkey,flower,guitar,coffee,mango,river,beach,sunset,quilt,wrist,train,grass,wrist,apple,hello,space,table,queen,chair,juice,honda,zebra,fence,brick,chain,crane,swirl,plant,river,train,quilt,grass,smile,wrist,apple,space,hello,queen,zebra,juice,chips,brick,quilt,train,table,bonus,chair,fence,crane,grass,wrist,river";


    int i;
    for (i = 0; source[i] != '\0'; i++) {
        arr[i] = source[i];
    }
    arr[i] = '\0'; 
}

void extractRandomWord(const char arr[], char result[]) {
    int startIndex, endIndex;
    int i = rand() % 300 + 1;

    while (i >= 0 && arr[i] != ',') {
        i--;
    }
    startIndex = i + 1;

    i = startIndex;
    while (arr[i] != ',' && arr[i] != '\0') {
        i++;
    }
    endIndex = i;

    int wordSize = endIndex - startIndex;

    for (int j = 0; j < wordSize; j++) {
        result[j] = arr[startIndex + j];
    }
    result[wordSize] = '\0';
}



void hangman(int n){

 if(n==1){
 cout<<"  +----+"<<endl;
 cout<<"  |    |"<<endl;
 cout<<"       |"<<endl;
 cout<<"       |"<<endl;
 cout<<"       |"<<endl;
 cout<<"       |"<<endl;
 cout<<"=========="<<endl;
      
 }
 if(n==2){
 cout<<"  +----+"<<endl;
 cout<<"  |    |"<<endl;
 cout<<"  0    |"<<endl;
 cout<<"       |"<<endl;
 cout<<"       |"<<endl;
 cout<<"       |"<<endl;
 cout<<"=========="<<endl;
      
 }
 if(n==3){
 cout<<"  +----+"<<endl;
 cout<<"  |    |"<<endl;
 cout<<"  0    |"<<endl;
 cout<<"  |    |"<<endl;
 cout<<"       |"<<endl;
 cout<<"       |"<<endl;
 cout<<"=========="<<endl;
      
 }
 if(n==4){
 cout<<"  +----+"<<endl;
 cout<<"  |    |"<<endl;
 cout<<"  0    |"<<endl;
 cout<<" /|    |"<<endl;
 cout<<"       |"<<endl;
 cout<<"       |"<<endl;
 cout<<"=========="<<endl;
      
 }
 if(n==5){
 cout<<"  +----+"<<endl;
 cout<<"  |    |"<<endl;
 cout<<"  0    |"<<endl;
 cout<<" /|\\   |"<<endl;
 cout<<"       |"<<endl;
 cout<<"       |"<<endl;
 cout<<"=========="<<endl;
      
 }
 if(n==6){
 cout<<"  +----+"<<endl;
 cout<<"  |    |"<<endl;
 cout<<"  0    |"<<endl;
 cout<<" /|\\   |"<<endl;
 cout<<" /     |"<<endl;
 cout<<"       |"<<endl;
 cout<<"=========="<<endl;
      
 }
 
}



bool guessWord(const char word[]) {
   
   
   
   cout << "ENTER your First Name :" <<endl;

    const int maximum2 = 15; 
    char nrr[maximum2];

    cin >> nrr;
    nrr[maximum2-1]='\0';
    
    cout<<endl;
    cout<<"*************WELCOME! to HANGMAN GAME************* "<<endl;
    cout<<"I am thinking of a word " << endl;
    

    
    int c = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        c += 1;
    }
    cout << "HINT: word I am thinking have letter's :" << c << endl;

    char crr[c];
    for (int i = 0; i < c; i++) {
        crr[i] = 'x';
    }
    crr[c] = '\0';
    cout << crr << endl<<endl;
    
    cout<<"*************RULES of HANGMAN********************"<<endl<<endl;
    cout<<"*You are supposed to GUESS the word  " << endl;
    cout<<"*You will GUESS letter by letter "<<endl;
    cout<<"*If you GUESS correct letter it will appear in all the places it's PRESENT"<<endl;
    cout<<"*Total chances/lifes you have are : 7" << endl;
    cout<<"*In each wrong GUESS your chances/lifes decrease by 1"<<endl;
    cout<<"*If your name and word has same letter and you guessed it right you life will increase by 1"<<endl<<endl;
    cout<<"*************GAME STARTS*************************"<<endl<<endl;

    int n = 0;
    char a;
    bool hasX;
    bool usedLetters[26] = { false };//newww

    do {
        cout << "Enter your letter" << endl;
        cin >> a;
        int j;
        bool flag2 = false;
        
        
        
        for (j = 0; word[j] != '\0'; j++) {
            if (a == word[j]) {
            	cout<<"GOOD! this letter is present in word"<<endl;
                crr[j] = word[j];
                cout << crr << endl;
                flag2 = true;
            }
        }
        
        for(int i=0;i < maximum2-1 && nrr[i] != '\0';i++){
     if(a==nrr[i] && flag2==true && n>0 && !usedLetters[a - 'a']){   //newwwwwwww
     n-=1;
     usedLetters[a - 'a'] = true;//newwwwwww
     cout<<"Your chances are incresed by 1 :)"<<endl;
     }  
    }

        if (flag2 == false) {
            cout << "NOPE! This letter is not present in word" << endl;
            cout << crr << endl;
            n += 1;
        }
        
        hangman(n);

        hasX = false;
        for (int k = 0; k < c; k++) {
            if (crr[k] == 'x') {
                hasX = true;
                break;
            }
        }

        cout << "Your chance left are : " << (7 - n) << endl<<endl;
        cout<<"************************************************"<<endl<<endl;
    } while (n < 7 && hasX);

    if (n < 7) {
        cout << "Congratulations :)  You guessed the word correctly: " << word << endl;
        return true;
    } else {
        cout<<"**********************GAME OVER*****************"<<endl;
        cout << "Oops, you ran out of tries :(" << endl;
        cout<<"  +----+"<<endl;
 	cout<<"  |    |"<<endl;
	cout<<"  0    |"<<endl;
 	cout<<" /|\\   |"<<endl;
 	cout<<" / \\   |"<<endl;
 	cout<<"       |"<<endl;
 	cout<<"=========="<<endl;
        cout << "The correct word is: " << word << endl;
        return false;
    }
}

int main() {
    char arr[600];
    initializeArray(arr);
    srand(static_cast<unsigned int>(time(0)));

    char word[20];
    extractRandomWord(arr, word);
   // cout << "Random word: " << word << endl;
    

    guessWord(word);

    return 0;
}

