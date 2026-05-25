#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Auto {
    string model, marka, typNadwozia, nrRej, skrzynia, kolor, dataWyp, dataZwrot;
    int liczbaMiejsc, pojCm3;
};

Auto newCar();
string printCar(Auto a);
Auto strToCar(string linia);
void readFile(vector<Auto>& auta);
void saveFile(vector<Auto>& auta);
void viewCars(vector<Auto>& auta);
void viewCar(vector<Auto>& auta);
void filterByGearbox(vector<Auto>& auta);
void viewAvailable(vector<Auto>& auta);
void rentCar(vector<Auto>& auta);
void returnCar(vector<Auto>& auta);
void menu(vector<Auto>& auta);

Auto newCar() {
    Auto a;
    cout << "Model: ";
    cin >> a.model;
    cout << "Marka: ";
    cin >> a.marka;
    cout << "Liczba miejsc: ";
    cin >> a.liczbaMiejsc;
    cout << "Typ nadwozia: ";
    cin >> a.typNadwozia;
    cout << "Nr rejestracyjny: ";
    cin >> a.nrRej;
    cout << "Rodzaj skrzyni biegow (manual/auto): ";
    cin >> a.skrzynia;
    cout << "Kolor: ";
    cin >> a.kolor;
    cout << "Pojemnosc silnika (cm3): ";
    cin >> a.pojCm3;
    cout << "Data ostatniego wypozyczenia (YYYY-MM-DD lub -): ";
    cin >> a.dataWyp;
    cout << "Data ostatniego zwrotu (YYYY-MM-DD lub -): ";
    cin >> a.dataZwrot;
    return a;
}

string printCar(Auto a) {
    return a.model + "," + a.marka + "," + to_string(a.liczbaMiejsc) + "," + a.typNadwozia + "," + a.nrRej + "," +
           a.skrzynia + "," + a.kolor + "," + to_string(a.pojCm3) + "," + a.dataWyp + "," + a.dataZwrot;
}

Auto strToCar(string linia) {
    Auto a;
    int poz;

    poz = linia.find(',');
    a.model = linia.substr(0, poz);
    linia = linia.substr(poz + 1, linia.length());

    poz = linia.find(',');
    a.marka = linia.substr(0, poz);
    linia = linia.substr(poz + 1, linia.length());

    poz = linia.find(',');
    a.liczbaMiejsc = stoi(linia.substr(0, poz));
    linia = linia.substr(poz + 1, linia.length());

    poz = linia.find(',');
    a.typNadwozia = linia.substr(0, poz);
    linia = linia.substr(poz + 1, linia.length());

    poz = linia.find(',');
    a.nrRej = linia.substr(0, poz);
    linia = linia.substr(poz + 1, linia.length());

    poz = linia.find(',');
    a.skrzynia = linia.substr(0, poz);
    linia = linia.substr(poz + 1, linia.length());

    poz = linia.find(',');
    a.kolor = linia.substr(0, poz);
    linia = linia.substr(poz + 1, linia.length());

    poz = linia.find(',');
    a.pojCm3 = stoi(linia.substr(0, poz));
    linia = linia.substr(poz + 1, linia.length());

    poz = linia.find(',');
    a.dataWyp = linia.substr(0, poz);
    linia = linia.substr(poz + 1, linia.length());

    a.dataZwrot = linia;
    return a;
}

void readFile(vector<Auto>& auta) {
    auta.clear();
    cout << "Podaj nazwe pliku CSV: ";
    string nazwa;
    cin >> nazwa;

    string linia;
    fstream plik;
    plik.open(nazwa, ios::in);
    if (plik.good()) {
        getline(plik, linia);
        while (!plik.eof()) {
            getline(plik, linia);
            if (linia.length() > 5) auta.push_back(strToCar(linia));
        }
        plik.close();
    }
    cout << "Wczytano: " << auta.size() << " samochodow.\n";
}

void saveFile(vector<Auto>& auta) {
    cout << "Podaj nazwe pliku CSV do zapisu: ";
    string nazwa;
    cin >> nazwa;

    fstream plik;
    plik.open(nazwa, ios::out);
    plik << "model,marka,liczba_miejsc,typ_nadwozia,nr_rejestracyjny,rodzaj_skrzyni,kolor,pojemnosc_cm3,data_ostatniego_wypozyczenia,data_ostatniego_zwrotu\n";
    int n = auta.size();
    for (int i = 0; i < n; i++) {
        plik << printCar(auta[i]) << endl;
    }
    plik.close();
}

void viewCars(vector<Auto>& auta) {
    int n = auta.size();
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << auta[i].marka << " " << auta[i].model << endl;
    }
}

void viewCar(vector<Auto>& auta) {
    int nr;
    viewCars(auta);
    cout << "Podaj numer samochodu: ";
    cin >> nr;

    Auto a = auta[nr - 1];
    cout << "Model: " << a.model << endl;
    cout << "Marka: " << a.marka << endl;
    cout << "Liczba miejsc: " << a.liczbaMiejsc << endl;
    cout << "Typ nadwozia: " << a.typNadwozia << endl;
    cout << "Nr rejestracyjny: " << a.nrRej << endl;
    cout << "Rodzaj skrzyni biegow: " << a.skrzynia << endl;
    cout << "Kolor: " << a.kolor << endl;
    cout << "Pojemnosc silnika (cm3): " << a.pojCm3 << endl;
    cout << "Data ostatniego wypozyczenia: " << a.dataWyp << endl;
    cout << "Data ostatniego zwrotu: " << a.dataZwrot << endl;
}

void filterByGearbox(vector<Auto>& auta) {
    string s;
    cout << "Podaj skrzynie (manual/auto): ";
    cin >> s;
    int n = auta.size();
    for (int i = 0; i < n; i++) {
        if (auta[i].skrzynia == s) cout << i + 1 << ". " << auta[i].marka << " " << auta[i].model << endl;
        else cout << "brak samochodow z taka skrzynia biegow " << endl;
    }
}

void viewAvailable(vector<Auto>& auta) {
    string from, to;
    cout << "Podaj date od (YYYY-MM-DD): ";
    cin >> from;
    cout << "Podaj date do (YYYY-MM-DD): ";
    cin >> to;

    cout << "\nDostepne samochody w terminie " << from << " - " << to << ":\n";

    int n = auta.size();
    for (int i = 0; i < n; i++) {
        Auto a = auta[i];
        if (a.dataWyp == "-" || a.dataWyp == "") {
            cout << i + 1 << ". " << a.marka << " " << a.model << endl;
        } else if (a.dataZwrot == "-" || a.dataZwrot == "") {
            if (to < a.dataWyp) cout << i + 1 << ". " << a.marka << " " << a.model << endl;
        } else {
            bool overlap = !(to < a.dataWyp || a.dataZwrot < from);
            if (!overlap) cout << i + 1 << ". " << a.marka << " " << a.model << endl;
            else cout << "nie ma wolnego samochodu w tym terminie " << endl;
        }
    }
}

void rentCar(vector<Auto>& auta) {
    int nr;
    string d;
    viewCars(auta);
    cout << "Podaj numer samochodu do wypozyczenia: ";
    cin >> nr;
    cout << "Podaj date wypozyczenia (YYYY-MM-DD): ";
    cin >> d;
    auta[nr - 1].dataWyp = d;
    auta[nr - 1].dataZwrot = "-";
}

void returnCar(vector<Auto>& auta) {
    int nr;
    string d;
    viewCars(auta);
    cout << "Podaj numer samochodu do zwrotu: ";
    cin >> nr;
    cout << "Podaj date zwrotu (YYYY-MM-DD): ";
    cin >> d;
    auta[nr - 1].dataZwrot = d;
}

void menu(vector<Auto>& auta) {
    int wybor;
    do {
        cout << "\n\nWybierz: \n";
        cout << "1. koniec\n";
        cout << "2. wczytaj auta z CSV\n";
        cout << "3. wyswietl liste aut\n";
        cout << "4. wyswietl dane wybranego auta\n";
        cout << "5. pokaz dostepne auta w terminie\n";
        cout << "6. filtruj po skrzyni biegow\n";
        cout << "7. dodaj nowe auto\n";
        cout << "8. wypozycz auto\n";
        cout << "9. zwroc auto\n";
        cout << "10. zapisz do CSV\n";
        cin >> wybor;

        switch (wybor) {
        case 1:
            return;
        case 2:
            readFile(auta);
            break;
        case 3:
            viewCars(auta);
            break;
        case 4:
            viewCar(auta);
            break;
        case 5:
            viewAvailable(auta);
            break;
        case 6:
            filterByGearbox(auta);
            break;
        case 7:
            auta.push_back(newCar());
            break;
        case 8:
            rentCar(auta);
            break;
        case 9:
            returnCar(auta);
            break;
        case 10:
            saveFile(auta);
            break;
        default:
            break;
        }
    } while (wybor != 1);
}

int main() {
    vector<Auto> auta;
    menu(auta);
}