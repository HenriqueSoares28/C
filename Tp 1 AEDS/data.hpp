#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Data{
    private:
        int dia;
        int mes;
        int ano;
    public:
        //constructor
        Data::Data(int dia, int mes, int ano);
        //destructor
        Data::~Data();
        //getters
        int Data::getDia();
        int Data::getMes();
        int Data::getAno();
        //setters
        bool Data::setDia(int dia);
        bool Data::setMes(int mes);
        void Data::setAno(int ano);
        //others
        bool Data::setData(int dia, int mes, int ano);
        void Data::leData();
        bool Data::validadeData();
        string Data::mesExtenso();
        void Data::escreverData();
        bool Data::chaveMes(int mes);
};

//constructor
Data::Data(int dia=0, int mes=0, int ano=0){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}
//destructor
Data::~Data(){
    cout << "Data destructor" << endl;
}

//getters
int Data::getDia(){
    return this->dia;
}
int Data::getMes(){
    return this->mes;
}
int Data::getAno(){
    return this->ano;
}

//setters
bool Data::setDia(int dia){
    bool valido = false;
    if (dia > 0 && dia <= 31){
        this->dia = dia;
        valido = true;
    }
    return valido;
}
bool Data::setMes(int mes){
    bool valido = false;
    if (mes > 0 && mes <= 12){
        this->mes = mes;
        valido = true;
    }
    return valido;
}
void Data::setAno(int ano){
    this->ano = ano;
}

bool Data::setData(int dia, int mes, int ano){
    bool valido = false;
    if(this->setDia(dia) && this->setMes(mes)) valido = true;
    this->setAno(ano);
    cout << this->getDia() << endl;
    return valido;
}

void Data::leData(){
    int dia,
        mes, 
        ano;
    bool valido = false;
    do{
        cout << "Digite o dia: ";
        cin >> dia;
        cout << "Digite o mes: ";
        cin >> mes;
        cout << "Digite o ano: ";
        cin >> ano;
        if(this->setData(dia, mes, ano)) {
            this->setData(dia, mes, ano);
            valido = true;
            cout << "Data valida!" << endl;
        }else cout << "Data invalida, Digite novamente" << endl;
    }while(!valido);
}

bool Data::validadeData(){
    bool valido = false;
    if((getMes() > 0 && getMes() <=12) && (getDia() > 0 && getDia() <= 31)) valido = true;
    return valido;
}

string Data::mesExtenso(){
    string mesExtenso[12] = {"janeiro",
                                "fevereiro",
                                "marco",
                                "abril",
                                "maio",
                                "junho",
                                "julho",
                                "agosto",
                                "setembro",
                                "outubro",
                                "novembro",
                                "dezembro"};

    return mesExtenso[getMes()-1];
}

void Data::escreverData(){
    //printf("%i/%s/%i\n", this->getDia(), this->getMes(), this->getAno());
    cout << this->getDia() << "/" << this->mesExtenso() << "/" << this->getAno() << endl;
}

bool Data::chaveMes(int mes){
    bool valido = false;
    if (mes == getMes()) valido = true;
    return valido;
}
