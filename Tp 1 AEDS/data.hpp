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
        Data(int dia=0, int mes=0, int ano=0){
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
        }
        //destructor
        ~Data(){
            cout << "Data destructor" << endl;
        }

        //getters
        int getDia(){
            return this->dia;
        }
        int getMes(){
            return this->mes;
        }
        int getAno(){
            return this->ano;
        }
        
        //setters
        bool setDia(int dia){
            bool valido = false;
            if (dia > 0 && dia <= 31){
                this->dia = dia;
                valido = true;
            }
            return valido;
        }
        bool setMes(int mes){
            bool valido = false;
            if (mes > 0 && mes <= 12){
                this->mes = mes;
                valido = true;
            }
            return valido;
        }
        void setAno(int ano){
            this->ano = ano;
        }

        bool setData(int dia, int mes, int ano){
            bool valido = false;
            if(this->setDia(dia) && this->setMes(mes)) valido = true;
            this->setAno(ano);
            return valido;
        }

        void leData(){
            int dia,
                mes, 
                ano;
            bool valido = false;
            do{
                cout << "Digite a data (dd/mm/aaaa)";
                scanf("%i/%i/%i", dia, mes, ano);
                if(setData(dia, mes, ano)) {
                    valido = true;
                    cout << "Data valida!" << endl;
                }else cout << "Data invalida, Digite novamente" << endl;
            }while(!valido);
        }
        
        bool validadeData(){
            bool valido = false;
            if((getMes() > 0 && getMes() <=12) && (getDia() > 0 && getDia() <= 31)) valido = true;
            return valido;
        }

        string mesExtenso(){
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

        void escreverData(){
            cout << getDia() << "/" << getMes() << "/" << getAno() << endl;
        }

        bool chaveMes(int mes){
            bool valido = false;
            if (mes == getMes()) valido = true;
            return valido;
        }


};