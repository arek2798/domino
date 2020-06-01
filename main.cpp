#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

using namespace std;

void usuwanieKamienia(int kamienie[28], int index, int &ileWPuli) {
    for(int i=index; i<ileWPuli-1; i++) {
        kamienie[i] = kamienie[i+1];
    }
    kamienie[ileWPuli-1] = 0;
    ileWPuli--;
}

int losujKamien(int kamienie[28], int &ileZostalo) {
    srand(time(NULL));
    int wylosowanaLiczba = rand() % ileZostalo;
    int wylosowanyKamien = kamienie[wylosowanaLiczba];
    
    usuwanieKamienia(kamienie, wylosowanaLiczba, ileZostalo);
    return wylosowanyKamien;
}

void wypiszTalon(int talon[28], int ile) {
    for(int i=0; i<ile; i++) {
        cout << i+1 << ". |" << floor(talon[i]/10) << "|" << talon[i]%10 << "|  ";
        if((i+1)%5 == 0) cout << endl;
    }
    cout << endl;
}

void rysujPlansze(char plansza[3][364], int ileKamieniNaPlanszy) {
    for(int i=0; i<ileKamieniNaPlanszy*13; i++) cout << "-";
    cout << endl;
    for(int i=0; i<3; i++) {                                
        for(int j=0; j<ileKamieniNaPlanszy*13; j++) {
            cout << plansza[i][j];
        }
        cout << endl;
    }
    for(int i=0; i<ileKamieniNaPlanszy*13; i++) cout << "-";
    cout << endl;
}

void dodanieKamieniaDoPlanszy(int kamienieNaPlanszy[28], int kamien, int gdzieKamien, int ileKamieniNaPlanszy) {
    if(gdzieKamien == 2) {
        kamienieNaPlanszy[ileKamieniNaPlanszy] = kamien;
    } else if(gdzieKamien == 1) {
        for(int i=ileKamieniNaPlanszy; i>0; i--) {
            kamienieNaPlanszy[i] = kamienieNaPlanszy[i-1];
        }
        kamienieNaPlanszy[0] = kamien;
    }
}

void rysowanieKamieniNaPlanszy(char plansza[3][364], int kamienieNaPlanszy[28], int ileKamieniNaPlanszy) {
    int kamien[2];
    for(int k=0; k<=ileKamieniNaPlanszy; k++) {
        int index = k*13;
        kamien[0] = floor(kamienieNaPlanszy[k]/10);
        kamien[1] = kamienieNaPlanszy[k]%10;
        plansza[0][index] = '|';
        plansza[1][index] = '|';
        plansza[2][index] = '|';
        for(int i=0; i<2; i++) {
            index = index+i*6;
            if(kamien[i] == 0) { 
                for(int j=0; j<3; j++) {
                    plansza[j][index+1] = ' ';
                    plansza[j][index+2] = ' ';
                    plansza[j][index+3] = ' ';
                    plansza[j][index+4] = ' ';
                    plansza[j][index+5] = ' ';
                }
            }else if(kamien[i] == 1) { 
                for(int j=0; j<3; j++) {
                    plansza[j][index+1] = ' ';
                    plansza[j][index+2] = ' ';
                    plansza[j][index+3] = ' ';
                    plansza[j][index+4] = ' ';
                    plansza[j][index+5] = ' ';
                }
                plansza[1][index+3] = '*';
            }else if(kamien[i] == 2) { 
                for(int j=0; j<3; j++) {
                    plansza[j][index+1] = ' ';
                    plansza[j][index+2] = ' ';
                    plansza[j][index+3] = ' ';
                    plansza[j][index+4] = ' ';
                    plansza[j][index+5] = ' ';
                }
                plansza[0][index+2] = '*';
                plansza[2][index+4] = '*';
            }else if(kamien[i] == 3) { 
                for(int j=0; j<3; j++) {
                    plansza[j][index+1] = ' ';
                    plansza[j][index+2] = ' ';
                    plansza[j][index+3] = ' ';
                    plansza[j][index+4] = ' ';
                    plansza[j][index+5] = ' ';
                }
                plansza[0][index+2] = '*';
                plansza[1][index+3] = '*';
                plansza[2][index+4] = '*';
            }else if(kamien[i] == 4) {
                for(int j=0; j<3; j++) {
                    plansza[j][index+1] = ' ';
                    plansza[j][index+2] = '*';
                    plansza[j][index+3] = ' ';
                    plansza[j][index+4] = '*';
                    plansza[j][index+5] = ' ';
                }
                plansza[1][index+2] = ' ';
                plansza[1][index+4] = ' ';
            }else if(kamien[i] == 5) {
                for(int j=0; j<3; j++) {
                    plansza[j][index+1] = ' ';
                    plansza[j][index+2] = '*';
                    plansza[j][index+3] = ' ';
                    plansza[j][index+4] = '*';
                    plansza[j][index+5] = ' ';
                }
                plansza[1][index+2] = ' ';
                plansza[1][index+3] = '*';
                plansza[1][index+4] = ' ';
            }else if(kamien[i] == 6) {
                for(int j=0; j<3; j++) {
                    plansza[j][index+1] = ' ';
                    plansza[j][index+2] = '*';
                    plansza[j][index+3] = ' ';
                    plansza[j][index+4] = '*';
                    plansza[j][index+5] = ' ';
                }
            }
            plansza[0][index+6] = '|';
            plansza[1][index+6] = '|';
            plansza[2][index+6] = '|';
        }
    }


}

int main()
{
    int kamienie[28] = {0, 1, 2, 3, 4, 5, 6, 11, 12, 13, 14, 15, 16, 22, 23, 24, 25, 26, 33, 34, 35, 36, 44, 45, 46, 55, 56, 66};
    char plansza[3][364];
    int kamien[2] = {0,0};
    int kamienieNaPlanszy[28];
    int ileKamieniNaPlanszy = 0;
    int ileZostalo = 28;
    int wybranyKamien, gdzieKamien, nowyKamien;
    int iluGraczy;
    int pierwszyRuch = 1;
    string blad = "";

    while(iluGraczy > 4 || iluGraczy < 2) {
        cout << "Ilu graczy bierze udzial(od 2 do 4)? ";
        cin >> iluGraczy;
        if(iluGraczy > 4 || iluGraczy < 2) {
            cout << "Podaj inna liczbe!" << endl;
        }
    }

    int talon1[28];
    int kolej = 1;
    for(int i=0; i<7; i++) {
        talon1[i] = losujKamien(kamienie, ileZostalo);
    }
    int talon1Ile = 7;
    int talon2[28];
    for(int i=0; i<7; i++) {
        talon2[i] = losujKamien(kamienie, ileZostalo);
    }

    int talon2Ile = 7;

    int talon3[28];
    int talon3Ile = 7;
    int talon4[28];
    int talon4Ile = 7;
    if(iluGraczy == 3) {
        for(int i=0; i<7; i++) {
            talon3[i] = losujKamien(kamienie, ileZostalo);
        }
    } else if(iluGraczy == 4) {
        for(int i=0; i<7; i++) {
            talon3[i] = losujKamien(kamienie, ileZostalo);
        }
        for(int i=0; i<7; i++) {
            talon4[i] = losujKamien(kamienie, ileZostalo);
        }
    }

    while(talon1Ile > 0 && talon2Ile > 0 && talon3Ile > 0 && talon4Ile > 0) {
        rysujPlansze(plansza, ileKamieniNaPlanszy);
        cout << "Kamienie w twoim talonie:" << endl;
        wypiszTalon(talon1, talon1Ile);
        if(blad != "") {
            cout << blad << endl;
            blad = "";
        }
        if(kolej == 2 && pierwszyRuch == 1) {
            cout << "Ruch gracza numer 2..." << endl;
            system("pause");
            pierwszyRuch = 0;
        } else if(kolej == 3 && pierwszyRuch == 1) {
            cout << "Ruch gracza numer 3..." << endl;
            system("pause");
            pierwszyRuch = 0;
        } else if(kolej == 4 && pierwszyRuch == 1) {
            cout << "Ruch gracza numer 4..." << endl;
            system("pause");
            pierwszyRuch = 0;
        }

        if(kolej == 1) {
            cout << "Wpisz numer kamienia, ktory chcesz wystawic (wpisz 0 jesli chcesz dodac nowy kamien do talonu): ";
            cin >> wybranyKamien;
            while(wybranyKamien > talon1Ile || wybranyKamien < 0) {
                cout << "Podaj inna liczbe (wpisz 0 jesli chcesz dodac nowy kamien do talonu): ";
                cin >> wybranyKamien;
            }
        } else if (kolej == 2) {
            if(gdzieKamien == 2) {
                wybranyKamien++;
                if(wybranyKamien == talon2Ile+1) wybranyKamien = 0;
            }
        } else if (kolej == 3) {
            if(gdzieKamien == 2) {
                wybranyKamien++;
                if(wybranyKamien == talon3Ile+1) wybranyKamien = 0;
            }
        } else if (kolej == 4) {
            if(gdzieKamien == 2) {
                wybranyKamien++;
                if(wybranyKamien == talon4Ile+1) wybranyKamien = 0;
            }
        }



        if(wybranyKamien == 0) {
            if(ileZostalo != 0) {
                if(kolej == 1) {
                    talon1[talon1Ile] = losujKamien(kamienie, ileZostalo);
                    talon1Ile++;
                } else if(kolej==2) {
                    talon2[talon2Ile] = losujKamien(kamienie, ileZostalo);
                    talon2Ile++;
                    wybranyKamien = talon2Ile - 1;
                } else if(kolej==3) {
                    talon3[talon3Ile] = losujKamien(kamienie, ileZostalo);
                    talon3Ile++;
                    wybranyKamien = talon3Ile - 1;
                } else if(kolej==4) {
                    talon4[talon4Ile] = losujKamien(kamienie, ileZostalo);
                    talon4Ile++;
                    wybranyKamien = talon4Ile - 1;
                }
            } else {
                cout << "Brak kamieni do wylosowania! Kolej nastepnego gracza" << endl;
                system("pause");
                kolej++;
                if(kolej > iluGraczy) kolej=1;
            }
        } else {
            if(ileKamieniNaPlanszy > 0) {
                if(kolej == 1) {
                    cout << "Chcesz go dodac na poczatku czy na koncu?(1-poczatek, 2-koniec): ";
                    cin >> gdzieKamien;
                    while(gdzieKamien != 1 && gdzieKamien!= 2) {
                        cout << "Zla wartosc! Chcesz go dodac na poczatku czy na koncu?(1-poczatek, 2-koniec): ";
                        cin >> gdzieKamien;
                    }
                } else if(kolej==2) {
                    if(gdzieKamien != 1) gdzieKamien = 1;
                } else if(kolej==3) {
                    if(gdzieKamien != 1) gdzieKamien = 1;
                } else if(kolej==4) {
                    if(gdzieKamien != 1) gdzieKamien = 1;
                }

                if(kolej == 1) { 
                    kamien[0] = floor(talon1[wybranyKamien-1]/10);
                    kamien[1] = talon1[wybranyKamien-1]%10;
                } else if(kolej == 2) {
                    kamien[0] = floor(talon2[wybranyKamien-1]/10);
                    kamien[1] = talon2[wybranyKamien-1]%10;
                } else if(kolej == 3) {
                    kamien[0] = floor(talon3[wybranyKamien-1]/10);
                    kamien[1] = talon3[wybranyKamien-1]%10;
                } else if(kolej == 4) {
                    kamien[0] = floor(talon4[wybranyKamien-1]/10);
                    kamien[1] = talon4[wybranyKamien-1]%10;
                }

                if(gdzieKamien == 1) {
                    int kamienBok = floor(kamienieNaPlanszy[0]/10);
                    if( kamienBok == kamien[0] || kamienBok == kamien[1] || kamien[0] == 0 || kamien[1] == 0 || kamienBok == 0) {
                        if(kamienBok == kamien[0]) nowyKamien = kamien[1]*10 + kamien[0];
                        else if(kamienBok == kamien[1]) nowyKamien = kamien[0]*10 + kamien[1];
                        else if(kamienBok == 0) nowyKamien = kamien[0]*10 + kamien[1];
                        else if(kamien[0] == 0) nowyKamien = kamien[1]*10 + kamien[0];
                        else if(kamien[1] == 0) nowyKamien = kamien[0]*10 + kamien[1];
                        dodanieKamieniaDoPlanszy(kamienieNaPlanszy, nowyKamien, gdzieKamien, ileKamieniNaPlanszy);
                        if(kolej == 1) usuwanieKamienia(talon1, wybranyKamien-1, talon1Ile); 
                        else if(kolej == 2) usuwanieKamienia(talon2, wybranyKamien-1, talon2Ile);
                        else if(kolej == 3) usuwanieKamienia(talon3, wybranyKamien-1, talon3Ile);
                        else if(kolej == 4) usuwanieKamienia(talon4, wybranyKamien-1, talon4Ile);
                        rysowanieKamieniNaPlanszy(plansza, kamienieNaPlanszy, ileKamieniNaPlanszy);
                        ileKamieniNaPlanszy++;
                        if(kolej == 1) {
                            kolej = 2;
                            wybranyKamien = 0;
                            gdzieKamien = 2;
                            pierwszyRuch = 1;
                        } else {
                            kolej++;
                            wybranyKamien = 0;
                            gdzieKamien = 2;
                            pierwszyRuch = 1;
                            if(kolej > iluGraczy) kolej = 1;
                        }
                    } else {
                        if(kolej == 1) blad = "Wybrany kamien nie pasuje!";
                        else if(kolej == 2) gdzieKamien = 2;
                        else if(kolej == 3) gdzieKamien = 2;
                        else if(kolej == 4) gdzieKamien = 2;
                    }
                } else if(gdzieKamien == 2) { 
                    int kamienBok = kamienieNaPlanszy[ileKamieniNaPlanszy-1]%10;
                    if( kamienBok == kamien[0] || kamienBok == kamien[1] || kamien[0] == 0 || kamien[1] == 0 || kamienBok == 0) {
                        if(kamienBok == kamien[1]) nowyKamien = kamien[1]*10 + kamien[0];
                        else if(kamienBok == kamien[0]) nowyKamien = kamien[0]*10 + kamien[1];
                        else if(kamienBok == 0) nowyKamien = kamien[0]*10 + kamien[1];
                        else if(kamien[1] == 0) nowyKamien = kamien[1]*10 + kamien[0];
                        else if(kamien[0] == 0) nowyKamien = kamien[0]*10 + kamien[1];
                        dodanieKamieniaDoPlanszy(kamienieNaPlanszy, nowyKamien, gdzieKamien, ileKamieniNaPlanszy);
                        if(kolej == 1) usuwanieKamienia(talon1, wybranyKamien-1, talon1Ile);
                        else if(kolej == 2) usuwanieKamienia(talon2, wybranyKamien-1, talon2Ile);
                        else if(kolej == 3) usuwanieKamienia(talon3, wybranyKamien-1, talon3Ile);
                        else if(kolej == 4) usuwanieKamienia(talon4, wybranyKamien-1, talon4Ile);
                        rysowanieKamieniNaPlanszy(plansza, kamienieNaPlanszy, ileKamieniNaPlanszy);
                        ileKamieniNaPlanszy++;
                        if(kolej == 1) {
                            kolej = 2;
                            wybranyKamien = 0;
                            gdzieKamien = 2;
                            pierwszyRuch = 1;
                        } else {
                            kolej++;
                            wybranyKamien = 0;
                            gdzieKamien = 2;
                            pierwszyRuch = 1;
                            if(kolej > iluGraczy) kolej = 1;
                        }
                    } else {
                        if(kolej == 1) blad = "Wybrany kamien nie pasuje!";
                        else if(kolej == 2) gdzieKamien = 2;
                        else if(kolej == 3) gdzieKamien = 2;
                        else if(kolej == 4) gdzieKamien = 2;
                    }
                }
            } else {
                kamienieNaPlanszy[ileKamieniNaPlanszy] = talon1[wybranyKamien-1];
                usuwanieKamienia(talon1, wybranyKamien-1, talon1Ile);
                rysowanieKamieniNaPlanszy(plansza, kamienieNaPlanszy, ileKamieniNaPlanszy);
                ileKamieniNaPlanszy++;
                if(kolej == 1) {
                    kolej = 2;
                    wybranyKamien = 0;
                    gdzieKamien = 2;
                    pierwszyRuch = 1;
                } else {
                    kolej++;
                    wybranyKamien = 0;
                    gdzieKamien = 2;
                    pierwszyRuch = 1;
                    if(kolej > iluGraczy) kolej = 1;
                }
            }
        }

    }

    if(talon1Ile == 0) cout << endl << "WYGRANA!!!" << endl;
    else if(talon2Ile == 0) cout << "WYGRAL GRACZ NUMER 2!!!" << endl;
    else if(talon3Ile == 0) cout << "WYGRAL GRACZ NUMER 3!!!" << endl;
    else if(talon4Ile == 0) cout << "WYGRAL GRACZ NUMER 4!!!" << endl;

    return 0;
}
