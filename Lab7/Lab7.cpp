#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    map<string, string> users;
    ifstream f("a.txt");
    string username, password;
    do
    {
        f >> username;
        f >> password;
        users[username] = password;
    } while (!f.eof());
    f.close();
    cout << "map size:" << users.size() << endl;
    int option;
    while (1)
    {
        cout << "\n 1.Add new user\n 2.Delete user\n 3.Verify user\n 4.print user\n 5.Quit";
        cin >> option;
        if (option == 1)
        {
            cout << "Enter username and password";
            string u, p;
            cin >> u >> p;
            users[u] = p;
        }
        else if (option == 2)
        {
            cout << "enter user to be deleted";
            string u;
            cin >> u;
            if (users.find(u) != users.end())
            {
                users.erase(u);
            }
        }

        else if (option == 3)
        {
            cout << "enter username and password";
            string u, p;
            cin >> u, p;
            if (users.find(u) == users.end())
            {
                if (users[u] == p)
                    cout << "valid users";
                else
                    cout << "\n invalid users";
            }
            else
                break;
        }

        else if (option == 4)
        {
            for (map<string, string>::iterator ii = users.begin(); ii != users.end(); ++ii)
            {
                cout << (*ii).first << ":"
                     << (*ii).second << endl;
            }
            break;
        }
        else if (option == 5)
        {
            ofstream f("a.txt");
            for (map<string, string>::iterator ii = users.begin(); ii != users.end(); ++ii)
            {
                f << (*ii).first << " " << (*ii).second << endl;
            }
            f.close();
            break;
        }
    }

    return 0;
}