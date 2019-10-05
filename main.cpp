#include <iostream>
#include <cstdio>
#include <utility>
#include <limits>

#define DARBUOTOJU_SKAICIUS 50
using namespace std;

struct Patiekalas{
  string pavadinimas;
  string aprasymas;
  int kaina{};

  Patiekalas sukurti_patiekala(int kain, string pav, string aprasymas){
    Patiekalas p;
    p.kaina = kain;
    p.pavadinimas = move(pav);
    p.aprasymas = move(aprasymas);
    return p;
  }

};




struct Meniu{
  Patiekalas patiekalai[100];
  int indeksas = 0;

  void ideti_patiekala(Patiekalas p){
    patiekalai[indeksas] = move(p);
    indeksas++;
  }






};
struct Darbuotojas{
  string vardas;
  string pareigos;
};





struct Valgykla{
  string pavadinimas; // Simboliu eilute
  Meniu meniu;
  Darbuotojas darbuotojai[DARBUOTOJU_SKAICIUS];


  int kiek_darbuotuju = 0;


  void sukurti_meniu(Meniu m){
    meniu = move(m);
  }
  void atvaizduoti_meniu() {
    for (int i = 0; i < meniu.indeksas; i++) {

      string temp = to_string(i+1)+"."+meniu.patiekalai[i].pavadinimas +", "+ meniu.patiekalai[i].aprasymas+", "+to_string(meniu.patiekalai[i].kaina);
      cout << temp;

    }
  }
  void prideti_darbuotojus(Darbuotojas darb[], int n){ // masyvas 100

    if(n <= DARBUOTOJU_SKAICIUS) {
      for (int i = 0; i < n; i++) {
        darbuotojai[i] = darb[i];
      }
      kiek_darbuotuju = n;
    }
  }
  void atvaizduoti_darbuotojus(){
    for (int i = 0; i < kiek_darbuotuju; i++) {
      cout << i+1 << ". " << "pareigos: "
      << darbuotojai[i].pareigos
      << ", vardas: "
      << darbuotojai[i].vardas<<"\n";
    }
  }

  Patiekalas gautiPatiekalaPagalIndeksa(int index){
    return meniu.patiekalai[index];
  }



};


struct Klientas{
  Meniu meniu;
  int indeksas = 0;
  Patiekalas patiekalai[50];

  void pasirinktas_patiekalas(int id, Valgykla valgykla){
    patiekalai[indeksas] = valgykla.gautiPatiekalaPagalIndeksa(id);
    indeksas++;
  }
  void uzsakymas(){
    for (int i = 0; i < indeksas; i++) {
      cout<< i<< ". " <<
          patiekalai[i].kaina <<
          patiekalai[i].pavadinimas<<
          patiekalai[i].aprasymas<< "\n";
    }
  }

};



void algoritmas(){
  int skaicius;
  Valgykla valgykla;

  Darbuotojas petras;
  petras.pareigos = "Virtuves darbuotojas";
  petras.vardas = "Petras";

  Darbuotojas jonas;
  jonas.pareigos = "Virtuves sefas";
  jonas.vardas = "Jonas";

  Darbuotojas darbuotojas[] = {petras, jonas, jonas, petras};

  int dydis = sizeof(darbuotojas) / sizeof(darbuotojas[0]);


  valgykla.prideti_darbuotojus(darbuotojas, dydis);

  valgykla.atvaizduoti_darbuotojus();




  Patiekalas patiekalas;

  Patiekalas karbonadas = patiekalas.sukurti_patiekala(10, "Karbonadas", "Mesa");
  Patiekalas lasisa = patiekalas.sukurti_patiekala(15, "Lasisa", "Zuvis");


  Meniu meniu;

  meniu.ideti_patiekala(karbonadas);
  meniu.ideti_patiekala(lasisa);

  Meniu meniu2;

  meniu2.ideti_patiekala(karbonadas);
  meniu2.ideti_patiekala(lasisa);
  meniu2.ideti_patiekala(karbonadas);
  meniu2.ideti_patiekala(lasisa);


  valgykla.sukurti_meniu(meniu);

  cout<<"---------------MENIU PIRMAS--------------------\n";

  valgykla.atvaizduoti_meniu();

  valgykla.sukurti_meniu(meniu2);

  cout<<"\n---------------MENIU ANTRAS--------------------\n";

  valgykla.atvaizduoti_meniu();


  cout<<"\n---------------KLIENTO UZSAKYMAI--------------------\n";

  Klientas klientas;
  klientas.pasirinktas_patiekalas(1, valgykla);
  klientas.pasirinktas_patiekalas(2, valgykla);
  klientas.pasirinktas_patiekalas(1, valgykla);
  klientas.pasirinktas_patiekalas(2, valgykla);


  klientas.uzsakymas();





}


Valgykla sukurtiValgiarasti(){

  Valgykla valgykla;
  Meniu valgiarastis;
  Patiekalas patiekalas;

  string pavadinimas;
  string aprasymas;
  int kaina;

  cout << "Nurodyti patiekalo kaina:"<<endl;
  cin >> kaina;
  patiekalas.kaina = kaina;

  // Useriui ivedus kaina spaudziamas mygtukas enter
  // ir jeigu yra naudojama getline() funkcija ji nuskaito nauja eilute
  // todel privaloma ignoruoti sia eilute naudojant funkciją cin.ignore()....
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

  cout << "Nurodyti patiekalo pav:"<<endl;
  getline(std::cin, pavadinimas);
  patiekalas.pavadinimas = pavadinimas;

  cout << "Nurodyti patiekalo aprasymas:"<<endl;
  getline(std::cin, aprasymas);
  patiekalas.aprasymas = aprasymas;

//  cout << "pavadinimas:" << patiekalas.pavadinimas << ", ";
//  cout << "aprasymas: " << patiekalas.aprasymas<< ", ";
//  cout << "kaina:" << patiekalas.kaina;

  valgiarastis.ideti_patiekala(patiekalas);

  valgykla.sukurti_meniu(valgiarastis);

  return valgykla;
}



void meniu() {

  int variantas = 0;

  while (true) {
    cout <<"\n";
    cout << "=============================================\n";
    cout << "1. Atvaizduoti meniu.\n";
    cout << "2. Patiekalo aprašymas pagal meniu nr.\n";
    cout << "3. Išeiti iš programos.\n";
    cout << "=============================================\n";

    cout << "Pasirinkite meniu punkta:";
    cin >> variantas;

    switch (variantas){
      case 1:{
        Valgykla valgykla = sukurtiValgiarasti();
        valgykla.atvaizduoti_meniu();
        break;
      }
      case 2:
        cout << "Antras variantas";
        break;
      case 3:
        cout << "Trecias variantas";
        //exit(-1);
        break;
      default:
        cout << "Toks meniu punktas neegzistuoja";
        break;
    }
    if(variantas == 3){break;}


  }
}


int main() {

  meniu();









//  int skaicius = 0;
//
//  int n = 0;
//
//  while(n < 4) {
//      cout << "\n iveskite " << n + 1 << " skaiciu:";
//      cin >> skaicius;
//      if(skaicius == 0) {
//        break;
//      }else {
//        cout << "\n Jusu ivestas skaicius: " << skaicius;
//        n++;
//      }
//    }
//
  //algoritmas();

  return 0;
}