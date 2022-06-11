#include <iostream>
#include <fstream>
#include <string>


using namespace std;

string Gesinnung();

int main()
{
    fstream f;
    int hpmax, play = 1, ba, hp, hpba, lvl, ini = 0, rk, profbonus, konstba;
    char pm, exit, gs;
    string gesin = "", fullhp = "", str = "";

    f.open("DND_Kampf.txt", ios_base::in);
    if (f.is_open())
    {
        getline(f, str);
        f.close();
    }
    if (str == "")
    {

        cout << "welches level bist du?\n";
        cin >> lvl;
        cout << "wie hoch ist deine Rüstungsklasse?\n";
        cin >> rk;
        cout << "max hp?\n";
        cin >> hpmax;
        cout << "full hp? ja/nein\n";
        cin >> fullhp;
        if (fullhp == "ja")
        {
            hp = hpmax;
        }
        if (fullhp == "nein")
        {
            cout << "wie viel hp hast du?\n";
            cin >> hp;
        }
        gesin = Gesinnung();
        system("CLS");
    }
    else
    {
        f.open("DND_Kampf.txt", ios_base::in);
        if (f.is_open())
        {
            getline(f, str);
            lvl = stoi(str);
            getline(f, str);
            hpmax = stoi(str);
            getline(f, str);
            rk = stoi(str);
            getline(f, str);
            gesin = str;
            getline(f, str);
            hp = stoi(str);
            getline(f, str);
            ini = stoi(str);
            f.close();
        }
    }

    while (play == 1)
    {
        cout << "Konstante Werte:\n";
        cout << "dein level ist: " << lvl;
        cout << "\ndeine max hp sind: " << hpmax;
        cout << "\ndeine Rüstungsklasse ist: " << rk;
        cout << "\ndeine Gesinnung ist: " << gesin;
        cout << "\n\nAndere Werte:\n";
        cout << "deine aktuellen hp sind: " << hp;
        cout << "\ndeine Initiative ist: " << ini << "\n\n";
        cout << "hp bearbeiten(1), initiative bearbeiten(2), Konstanten bearbeitung(3),exit(4)\n";
        cin >> ba;
        if (ba == 1)
        {

            cout << "wie viel hp?\n";
            cin >> hpba;
            cout << "+ oder -?\n";
            cin >> pm;
            if (pm == '+')
            {
                hp = hp + hpba;
                if (hp > hpmax)
                {
                    hp = hpmax;
                }
            }
            else if (pm == '-')
            {
                hp = hp - hpba;
                if (hp <= 0)
                {
                    hp = 0;
                }
            }
        }
        else if (ba == 2)
        {
            cout << "welche Initiative hast du?\n";
            cin >> ini;
        }
       /* else if (ba == 3)
        {
            cout << "welche Konstante willst du bearbeiten?\nLVL(1), MaxHP(2), Rüstungsklasse(3)\n";
            switch (konstba)
            {
            case '1':
                cout << "Herzlichen" break;

            default:
                break;
            }
        }*/

        else if (ba == 4)
        {
            break;
        }
        system("CLS");
    }
    f.open("DND_Kampf.txt", ios_base::out);
    if (f.is_open())
    {
        f << lvl << endl;
        f << hpmax << endl;
        f << rk << endl;
        f << gesin << endl;
        f << hp << endl;
        f << ini;
        f.close();
    }
}

string Gesinnung()
{
    string gesin = "";
    char gs, egs;
    cout << "welche Gesinnung hast du?\nb, g, n\n";
    cin >> gs;
    cout << "welche spezialiesierung hat deine Gesinnung?\nc, l, n\n";
    cin >> egs;
    switch (gs)
    {
    case 'b':
        if (egs == 'c')
        {
            gesin = "chaotic evil";
        }
        else if (egs == 'l')
        {
            gesin = "lawfull evil";
        }
        else if (egs == 'n')
        {
            gesin = "neutral evil";
        }
        break;

    case 'g':
        if (egs == 'c')
        {
            gesin = "chaotic good";
        }
        else if (egs == 'l')
        {
            gesin = "lawfull good";
        }
        else if (egs == 'n')
        {
            gesin = "neutral good";
        }
        break;

    case 'n':
        if (egs == 'c')
        {
            gesin = "chaotic neutral";
        }
        else if (egs == 'l')
        {
            gesin = "lawfull neutral";
        }
        else if (egs == 'n')
        {
            gesin = "neutral";
        }
        break;

    default:
        break;
    }
    return gesin;
}