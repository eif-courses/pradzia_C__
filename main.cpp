#include <iostream>
#include <cstdio>
#include <utility>

#define DARBUOTOJU_SKAICIUS 50
using namespace std;

struct Patiekalas{
  string pavadinimas;
  string aprasymas;
  int kaina;

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
      cout << i+1 <<". " << meniu.patiekalai[i].pavadinimas
           << meniu.patiekalai[i].aprasymas
           <<" kaina: " << meniu.patiekalai[i].kaina <<" eur" << endl;

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


int main() {

algoritmas();

  return 0;
}