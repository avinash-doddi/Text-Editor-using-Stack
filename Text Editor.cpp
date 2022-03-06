/* DS project by  avinash-doddi */

#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
#include <ctype.h>

#define strong "\e[1m"  // "\e" indicates font change
#define light "\e[2m"   // "[o,1,2,3,4m's indicate the font style
#define em "\e[3m"
#define undscrl "\e[4m"
#define clear "\e[0m"

using namespace std;

stack < string > txt, backup, backup1, rev;
/* dox: backup1 , backup are used to store any string that is deleted /*
string reff = "", alt = "";

void enter()  // Input function - takes input text and inserts them in stack 
{
    string s;

    cout << "Enter the Text:\n\n";
    
    cin.ignore(); /* to make getline() function to take compelete string as input i.e clears buffer*//

    std::getline(cin,s);

    for (int i = 0, n = s.size(); i < n; i++)
    {
        alt += s[i];
        if (s[i] == ' ')
        {
            rev.push(alt); 
            alt = "";
        }
        else if (i == n-1)
        {
            rev.push(alt);
            alt = "";
        }
    }
    while(!rev.empty())
    {
        txt.push(rev.top());
        rev.pop();
    }
    cout << "\n";
}

void printem() // print italic function - prints text in italic font
{
    if (txt.empty()) 
    {
        cout << em << "Nothing to print.. Please Enter Text\n\n" << clear;  // clear to clear the font style
        enter();
    }
    else{
        while(!txt.empty())
        {
            reff = txt.top(); 
            backup.push(reff);
            cout << em << reff << clear;  
            txt.pop();
        }
        cout << flush;
        while(!backup.empty()) // recovery
        {
            txt.push(backup.top());
            backup.pop();
        }
        cout << "\n\n";
    }
}

void printbold() // print bold function - prints text in bold font
{
    if (txt.empty()) 
    {
        cout << strong << "Nothing to print.. Please Enter Text\n\n" << clear;
        enter();
    }
    else{
        while(!txt.empty())
        {
            reff = txt.top(); 
            backup.push(reff);
            cout << strong << reff << clear;  
            txt.pop();
        }

        while(!backup.empty()) // recovery
        {
            txt.push(backup.top());
            backup.pop();
        }
        cout << "\n\n";
    }
}

void printundscrl() // print underline function - prints text in underlined style
{
    if (txt.empty()) 
    {
        cout << undscrl << "Nothing to print.. Please Enter Text\n\n" << clear;
        enter();
    }
    else{
        while(!txt.empty())
        {
            reff = txt.top(); 
            backup.push(reff);
            cout << undscrl << reff << clear;  
            txt.pop();
        }

        while(!backup.empty()) // recovery
        {
            txt.push(backup.top());
            backup.pop();
        }
        cout << "\n\n";
    }
}

void undo() // undo function - helps to undo the recent operation or text
{
    if (txt.empty())
    {
        cout << "Nothing to Undo\n\n";
        enter();
    }
    else
    {
        while(!txt.empty())
        {
            rev.push(txt.top());
            txt.pop();
        }
        
        backup1.push(rev.top());
        rev.pop();
        cout << "Undo performed\n";
        
        while(!rev.empty())
        {
            txt.push(rev.top());
            rev.pop();
        }
    }
}

void redo() // redo function - helps to redo the recent operation or text
{
    if (backup1.empty())
    {
        cout << "Nothing to Redo\n\n";
    }
    else
    {  
    
        while(!txt.empty())
        {
            rev.push(txt.top());
            txt.pop();
        }
        
        rev.push(backup1.top());
        backup1.pop();
        cout << "Redo performed\n";

        while(!rev.empty())
        {
            txt.push(rev.top());
            rev.pop();
        }
        
    }
}

void display()  // display function - to display the text in different styles
{
    cout << "Enter the font preffered:\n\n";

    cout  << "bold || " << "italic || " << "Underlined\n\n";

    string str;

        cin >> str;
        if (str == "bold")
        {
            printbold();
        }
        else if (str == "italic")
        {
            printem();
        }
        else if (str == "underlined")
        {
            printundscrl();
        }
        else
        {
            cout << strong << "Invalid choice , enter Again\n\n" << clear;
        }

}

void erase()  // erase function - erases the complete text
{
    if (txt.empty())
    {
        cout << light << "Nothing to Erase\n\n" << clear;
    }
    else
    {
        while(!txt.empty())
        {
            txt.pop();
        }
        while(!backup.empty())
        {
            backup.pop();
        }
        cout << light << "Text has be Erased\n\n" << clear;
    }
}

int main()  // main function
{
    string ch;
    cout << "1.enter - to enter input text \t\t 2.display - to display output\n";
    cout << "3.undo - to perform undo operation\t 4.redo - to perform redo operation\n";
    cout << "5.erase - to erase complete text\t 6.exit -  to exit text editor\n\n";
    do
    {   
        cout << "Enter Your Choice :\n\n";

        cin >> ch;

        cout << "\n";
        if (ch == "enter") enter();
        else if (ch == "display") display();
        else if (ch == "undo") undo();
        else if (ch == "redo") redo();
        else if (ch == "erase") erase();
        else if (ch == "exit"){ cout << strong << "\nThankyou..................\n" << clear; break; }
        else cout << strong << "Enter a valid choice \n\n" << clear;

    }while(true);

    return 0;
}
