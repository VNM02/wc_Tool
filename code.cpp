#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    // cout << argc << endl;
    // cout << "Enter the file name: ";
    // for (int i = 0; i < argc; i++)
    // {
    //     cout << argv[i] << endl;
    // }
    string data;
    fstream file;
    string filename = argv[2];
    file.open(filename, ios::in);
    if (!file)
    {
        cout << "No Such File\n";
    }
    else
    {
        string temp;
        int line = 0, chars = 0, words = 0, bytes = 0;
        while (getline(file, temp))
        {
            if (data.length() != 0)
            {
                data += "\n";
            }
            data += temp;
            line++;
        }
        file.close();
        //cout << data << endl;
        char ch = argv[1][1]; // sincee argv[1] is " -l or -w or -c" and we need the second character of it
        bytes = sizeof(data);
        switch (ch)
        {
        case 'l':
            cout << "Number of lines: " << line << endl;
            break;
        case 'm':
            for (int i = 0; i < data.length(); i++)
            {
                if (data[i] != ' ' && data[i] != '\n')
                {
                    chars++;
                }
            }
            cout << "Number of characters : " << chars << endl;
            break;
        case 'c':
            cout << "Number of bytes: " << bytes << endl;
            break;
        case 'w':
            for (int i = 0; i < data.length(); i++)
            {
                if (data[i] == ' ' || data[i] == '\n')
                {
                    words++;
                }
            }
            cout << "Number of words: " << words << endl;
            break;
        default:
            cout << "Enter some parameter : \n -l : Number of lines \n -c : Number of bytes \n -m : Number of characters \n -w : Number of words" << endl;
            break;
        }
    }

    return 0;
}
// wc_tool\batchfiles\xyz.txt