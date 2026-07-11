// ConsoleApplication80.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:

    Date(int y = 0, int m = 0, int d = 0) {
        year = y;
        month = m;
        day = d;
    }

    void input() {

        do {
            cout << "Roz : ";
            cin >> day;
        } while (day < 1 || day > 31);

        do {
            cout << "Mah : ";
            cin >> month;
        } while (month < 1 || month > 12);

        do {
            cout << "Sal : ";
            cin >> year;
        } while (year < 1300);
    }

    void print() const {
        cout << year << "/" << month << "/" << day;
    }
};


class Traconesh {//کلاس تاریخ تراکنش
private:
    Date tarikh;
    double mablagh;
    string noe;
public:
    Traconesh() {
        mablagh = 0;
        noe = "";
    }
    Traconesh(
        const Date& d, double m,
        string n) {
        tarikh = d;
        mablagh = m;
        noe = n;
    }

    void setTarikh(const Date& d) {
        tarikh = d;
    }

    void setMablagh(double m) {
        mablagh = m;
    }
    void setNoe(string n) {
        noe = n;
    }
    Date getTarikh() const {
        return tarikh;
    }

    double getMablagh() const {
        return mablagh;
    }
    string getNoe() const {
        return noe;
    }
    void print() const {
        cout << "Noe : "
            << noe
            << " | ";

        cout << "Mablagh : "
            << mablagh
            << " | ";

        cout << "Tarikh : ";

        tarikh.print();

        cout << endl;
    }
};

class Hesab {
protected:
    static int shomarehesab;
    int countshomareh;
    double Mogodi;
    Date Akharintraconesh;
    Traconesh* tarakonesh;
    int trCount;
    int trCapacity;

public:
    Hesab() {
        countshomareh = shomarehesab++;
        Mogodi = 0;
        Akharintraconesh = Date(0, 0, 0);

        trCapacity = 10;
        trCount = 0;
        tarakonesh = new Traconesh[trCapacity];
    }

    virtual ~Hesab() {
        delete[] tarakonesh;
    }

    double getMogodi() const { return Mogodi; }
    int getcountshomareh() const { return countshomareh; }

    virtual string gettype() const = 0;

    // -------- VARIZ --------
    void Variz(double mablagh, const Date& d) {

        if (mablagh <= 0) {
            cout << "mablagh ghalat ast\n";
            return;
        }

        Mogodi += mablagh;
        Akharintraconesh = d;

        if (trCount == trCapacity) {
            trCapacity *= 2;
            Traconesh* temp = new Traconesh[trCapacity];

            for (int i = 0; i < trCount; i++)
                temp[i] = tarakonesh[i];

            delete[] tarakonesh;
            tarakonesh = temp;
        }

        tarakonesh[trCount].setTarikh(d);
        tarakonesh[trCount].setMablagh(mablagh);
        tarakonesh[trCount].setNoe("variz");
        trCount++;
        


        cout << "Variz anjam shod\n";
    }

    // -------- BARDASHT --------
    void bardasht(double mablagh, const Date& d) {

        if (mablagh <= 0) {
            cout << "mablagh ghalat ast\n";
            return;
        }

        if (mablagh > Mogodi) {
            cout << "mojodi kafi nist\n";
            return;
        }

        Mogodi -= mablagh;
        Akharintraconesh = d;

        if (trCount == trCapacity) {
            trCapacity *= 2;
            Traconesh* temp = new Traconesh[trCapacity];

            for (int i = 0; i < trCount; i++)
                temp[i] = tarakonesh[i];

            delete[] tarakonesh;
            tarakonesh = temp;
        }

        tarakonesh[trCount].setTarikh(d);
        tarakonesh[trCount].setMablagh(mablagh);
        tarakonesh[trCount].setNoe("BARDASHT");
        trCount++;
        
        
        cout << "Bardasht anjam shod\n";
    }

    // -------- PRINT --------
    virtual void print() const {

        cout << "Shomare Hesab: " << getcountshomareh() << endl;
        cout << "Mogodi: " << Mogodi << endl;
        cout << "Akharin Tarikh: ";
        Akharintraconesh.print();
        cout << endl;

        cout << "---- Traconeshha  ----\n";
        for (int i = 0; i < trCount; i++) {
            tarakonesh[i].print();
        }
    }
};

int Hesab::shomarehesab = 1001;


class hesabjari : public Hesab {
public:

    string gettype() const override {
        return "hesabjari";
    }

    void print() const override {

        cout << "\n===== Hesab Jari =====\n";

        Hesab::print();
    }
};

class hesabhasaneh : public Hesab {
public:

    string gettype() const override {
        return "hesabhasaneh";
    }

    void print() const override {

        cout << "\n===== Hesab Gharzolhasaneh =====\n";

        Hesab::print();
    }
};

class hesabsarmayeGozari : public Hesab {
public:

    string gettype() const override {
        return "hesabsarmayeGozari";
    }

    void print() const override {

        cout << "\n===== Hesab SarmayeGozari =====\n";

        Hesab::print();
    }
};
//            KELAS MOSHTARI       

class Moshtari {
private:

    static int shomaremoshtari;

    int countmoshtari;

    Hesab** hesab;

    int count;

    int zarfiat;

    string name;

    string phon;

    string codmeli;

public:

    Moshtari() {

        countmoshtari = shomaremoshtari++;

        count = 0;

        zarfiat = 10;

        name = "";

        phon = "";

        codmeli = "";

        hesab = new Hesab * [zarfiat];
    }

    Moshtari(string n,
        string cod,
        string p)
    {
        countmoshtari = shomaremoshtari++;

        count = 0;

        zarfiat = 10;

        name = n;

        phon = p;

        codmeli = cod;

        hesab = new Hesab * [zarfiat];
    }

    ~Moshtari() {

        for (int i = 0; i < count; i++) {
            delete hesab[i];
        }

        delete[] hesab;
    }

    void setname(string n) {
        name = n;
    }

    void setphon(string p) {
        phon = p;
    }

    void setcodmeli(string cod) {
        codmeli = cod;
    }

    string getname() const {
        return name;
    }

    int getcountmoshtari() const {
        return countmoshtari;
    }

    void print() const {

        cout << "Shomare karbar : "
            <<getcountmoshtari() << endl;

        cout << "Name va Namkhanevadegi : "
            << name << endl;

        cout << "Phone : "
            << phon << endl;

        cout << "Codmeli : "
            << codmeli << endl;

        cout << "Tedad Hesab : "
            << count << endl;
    }

    void Addhesab(Hesab* acc) {

        if (acc == nullptr)
            return;

        if (count == zarfiat) {

            zarfiat *= 2;

            Hesab** temp =
                new Hesab * [zarfiat];

            for (int i = 0; i < count; i++) {
                temp[i] = hesab[i];
            }

            delete[] hesab;

            hesab = temp;
        }

        hesab[count++] = acc;
        
    }

    int findhesab(int accnum) const {

        for (int i = 0; i < count; i++) {

            if (hesab[i]->getcountshomareh()
                == accnum)
            {
                return i;
            }
        }

        return -1;
    }

    Hesab* findhesabs(int accnum) const {

        int idx = findhesab(accnum);

        if (idx != -1)
            return hesab[idx];

        return nullptr;
    }

    void deletehesab(int accnum) {

        int idx = findhesab(accnum);

        if (idx == -1) {

            cout << "hesab peyda nashod\n";

            return;
        }

        delete hesab[idx];

        for (int i = idx;
            i < count - 1;
            i++)
        {
            hesab[i] = hesab[i + 1];
        }

        count--;

        cout << "hesab hazf shod\n";
    }

    void printAllhesabha() const {

        if (count == 0) {

            cout << "in karbar hesab nadarad\n";

            return;
        }

        for (int i = 0; i < count; i++) {

            cout << "-----------------\n";

            hesab[i]->print();
        }
    }
};

int Moshtari::shomaremoshtari = 5001;


//توابع 


Moshtari* findmoshtari(
    Moshtari* moshtari[],
    int moshtariCount,
    int num)
{
    for (int i = 0; i < moshtariCount; i++)
    {
        if (moshtari[i] != nullptr &&
            moshtari[i]->getcountmoshtari()
            == num)
        {
            return moshtari[i];
        }
    }

    return nullptr;
}


bool checkCodMeli(string cod)
{
    return cod.length() == 10;
}

bool checkPhone(string phon)
{
    return phon.length() >= 10;
}


void inputinfomoshtari(
    string& name,
    string& meli,
    string& phon)
{
    cout << "Name : ";
    cin >> name;

    do {

        cout << "Cod Meli : ";
        cin >> meli;

    } while (!checkCodMeli(meli));

    do {

        cout << "Phone : ";
        cin >> phon;

    } while (!checkPhone(phon));
}


Hesab* creathesab()
{
    int type;

    cout << "1-Hesab Jari\n";
    cout << "2-Hesab Hasaneh\n";
    cout << "3-Hesab SarmayeGozari\n";

    cin >> type;

    switch (type) {

    case 1:
        return new hesabjari();

    case 2:
        return new hesabhasaneh();

    case 3:
        return new hesabsarmayeGozari();

    default:

        cout << "entekhab namotabar\n";

        return nullptr;
    }
}

// Menu Moshtari


void menumoshtari(
    Moshtari* moshtari[],
    int& moshtariCount,
    int maxmoshtari)
{
    int choice;

    while (true) {

        cout << "\n===== MENU KARBARI =====\n";
        cout << "1-Ezafe Kardan Karbar\n";
        cout << "2-Jostojo Karbar\n";
        cout << "3-Virayesh Karbar\n";
        cout << "4-Hazf Karbar\n";
        cout << "5-Namayesh Hame Karbaran\n";
        cout << "0-Bazgasht\n";

        cin >> choice;

        switch (choice) {

        case 1: {

            if (moshtariCount >= maxmoshtari) {

                cout << "zarfiat por ast\n";
                break;
            }

            string name;
            string meli;
            string phone;

            inputinfomoshtari(
                name,
                meli,
                phone);

            moshtari[moshtariCount] =
                new Moshtari(
                    name,
                    meli,
                    phone);

            cout << "karbar ezafe shod\n" << "shomare karbari:" << moshtari[moshtariCount]->getcountmoshtari() << endl;

            moshtariCount++;

            break;
        }

        case 2: {

            int num;

            cout << "Shomare Karbar : ";
            cin >> num;

            Moshtari* c =
                findmoshtari(
                    moshtari,
                    moshtariCount,
                    num);

            if (c)
                c->print();
            else
                cout << "karbar peyda nashod\n";

            break;
        }

        case 3: {

            int num;

            cout << "Shomare Karbar : ";
            cin >> num;

            Moshtari* c =
                findmoshtari(
                    moshtari,
                    moshtariCount,
                    num);

            if (c) {

                string name;
                string meli;
                string phone;

                inputinfomoshtari(
                    name,
                    meli,
                    phone);

                c->setname(name);
                c->setcodmeli(meli);
                c->setphon(phone);

                cout << "virayesh anjam shod\n";
            }
            else {

                cout << "karbar peyda nashod\n";
            }

            break;
        }

        case 4: {

            int num;

            cout << "Shomare Karbar : ";
            cin >> num;

            bool found = false;

            for (int i = 0;
                i < moshtariCount;
                i++)
            {
                if (moshtari[i] &&
                    moshtari[i]->getcountmoshtari()
                    == num)
                {
                    delete moshtari[i];

                    for (int j = i;
                        j < moshtariCount - 1;
                        j++)
                    {
                        moshtari[j] =
                            moshtari[j + 1];
                    }

                    moshtariCount--;

                    found = true;

                    cout << "karbar hazf shod\n";

                    break;
                }
            }

            if (!found)
                cout << "karbar peyda nashod\n";

            break;
        }

        case 5: {

            for (int i = 0;
                i < moshtariCount;
                i++)
            {
                cout << "-------------------\n";

                moshtari[i]->print();
            }

            break;
        }

        case 0:
            return;

        default:
            cout << "entekhab namotabar\n";
        }
    }
}
// Menu Hesab


void accountMenu(
    Moshtari* moshtari[],
    int Countkarbar)
{
    int choice;

    while (true) {

        cout << "\n===== MENU HESAB =====\n";


        cout << "    1-Ezafe Hesab\n";
        cout << "      2-Jostojo Hesab\n";
        cout << "        3-Hazf Hesab\n";
        cout << "          4-Namayesh Hame Hesab Haye Moshtari\n";
        cout << "            5-Variz\n";
        cout << "              6-Bardasht\n";
        cout << "                   7-Gozaresh Tarakonesh Ha\n";
        cout << "                         0-Bazgasht\n"; cout << "entekhab:\n";

        cin >> choice;

        switch (choice) {

        case 1: {

            int cnum;

            cout << "Shomare karbar : ";
            cin >> cnum;

            Moshtari* c =
                findmoshtari(
                    moshtari,
                    Countkarbar,
                    cnum);

            if (c) {

                Hesab* acc =
                    creathesab();

                if (acc) {

                    c->Addhesab(acc);

                    cout
                        << "hesab ijad shod\n" <<"shomaeh hesab : "<< acc->getcountshomareh() << endl;
                }
            }

            break;
        }

        case 2: {

            int cnum;
            int accnum;

            cout << "Shomare karbar: ";
            cin >> cnum;

            cout << "Shomare Hesab : ";
            cin >> accnum;

            Moshtari* c =
                findmoshtari(
                    moshtari,
                    Countkarbar,
                    cnum);

            if (c) {

                Hesab* a =
                    c->findhesabs(accnum);

                if (a)
                    a->print();
                else
                    cout << "hesab peyda nashod\n";
            }

            break;
        }

        case 3: {

            int cnum;
            int accnum;

            cout << "Shomare karbar: ";
            cin >> cnum;

            cout << "Shomare Hesab : ";
            cin >> accnum;

            Moshtari* c =
                findmoshtari(
                    moshtari,
                    Countkarbar,
                    cnum);

            if (c)
                c->deletehesab(accnum);

            break;
        }

        case 4: {

            int cnum;

            cout << "Shomare karbar : ";
            cin >> cnum;

            Moshtari* c =
                findmoshtari(
                    moshtari,
                    Countkarbar,
                    cnum);

            if (c)
                c->printAllhesabha();

            break;
        }

        case 5: {

            int cnum;
            int accnum;

            double amount;

            Date d;

            cout << "Shomare karbar : ";
            cin >> cnum;

            cout << "Shomare Hesab : ";
            cin >> accnum;

            cout << "Mablagh : ";
            cin >> amount;

            d.input();

            Moshtari* c =
                findmoshtari(
                    moshtari,
                    Countkarbar,
                    cnum);

            if (c) {

                Hesab* a =
                    c->findhesabs(accnum);

                if (a)
                    a->Variz(
                        amount,
                        d);
            }

            break;
        }

        case 6: {

            int cnum;
            int accnum;

            double amount;

            Date d;

            cout << "Shomare karbar : ";
            cin >> cnum;

            cout << "Shomare Hesab : ";
            cin >> accnum;

            cout << "Mablagh : ";
            cin >> amount;

            d.input();

            Moshtari* c =
                findmoshtari(
                    moshtari,
                    Countkarbar,
                    cnum);

            if (c) {

                Hesab* a =
                    c->findhesabs(accnum);

                if (a)
                    a->bardasht(
                        amount,
                        d);
            }
            else { cout << "hesab pida nashod."; }

            break;
        }

        case 7: {

            int cnum;
            int accnum;

            cout << "Shomare karbar : ";
            cin >> cnum;

            cout << "Shomare Hesab : ";
            cin >> accnum;
            Moshtari* c =
                findmoshtari(
                    moshtari,
                    Countkarbar,
                    cnum);

            if (c) {

                Hesab* a =
                    c->findhesabs(accnum);

                if (a)
                    a->print();
            }

            break;
        }

        case 0:
            return;

        default:
            cout << "entekhab namotabar\n";
        }
    }
}



// MAIN


int main()
{
    const int maxmoshtari = 100;

    Moshtari* moshtari[maxmoshtari];

    int customerCount = 0;

    for (int i = 0;
        i < maxmoshtari;
        i++)
    {
        moshtari[i] = nullptr;
    }

    int choice;

    while (true) {

        cout << "\n===== SYSTEM BANK =====\n";

        cout << "1-Amaliyat karbar\n";
        cout << "2-Amaliyat Hesab\n";
        cout << "0-Khoroj\n";

        cin >> choice;

        switch (choice) {

        case 1:

            menumoshtari(
                moshtari,
                customerCount,
                maxmoshtari);

            break;

        case 2:

            accountMenu(
                moshtari,
                customerCount);

            break;

        case 0:

            for (int i = 0;
                i < customerCount;
                i++)
            {
                delete moshtari[i];
            }

            return 0;

        default:

            cout << "entekhab namotabar\n";
        }
    }
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
