#include <iostream>
#include <string> 
#include <cstdlib>
#include <sstream>
#include <conio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include <random>
#include <ctime>
#include <math.h>


using namespace std;
using std::stoi;

string* leerArchivoHombres(){
    static string aux[1000];       
    int cont = 0;
    ifstream archivo;
    archivo.open("hombres.txt", ios::in);
    while(!archivo.eof()){
        string texto;
        getline(archivo,texto);
        aux[cont] = texto;
        cont++;
    }
    archivo.close();
    return aux;
}
string* leerArchivoMujeres(){
    static string aux[1000];
    int cont = 0;
    ifstream archivo;
    archivo.open("mujeres.txt", ios::in);
    while(!archivo.eof()){
        string texto;
        getline(archivo,texto);
        aux[cont] = texto;
        cont++;
    }
    archivo.close();
    return aux;
}
string* leerArchivoApellidos(){
    static string aux[1000];
    int cont = 0;
    ifstream archivo;
    archivo.open("apellidos.txt", ios::in);
    while(!archivo.eof()){
        string texto;
        getline(archivo,texto);
        aux[cont] = texto;
        cont++;
    }
    archivo.close();
    return aux;
}
string* leerArchivoProfesiones(){
    static string aux[50];
    int cont = 0;
    ifstream archivo;
    archivo.open("profesiones.txt", ios::in);
    while(!archivo.eof()){
        string texto;
        getline(archivo,texto);
        aux[cont] = texto;
        cont++;
    }
    archivo.close();
    return aux;
}
string* leerArchivoCreencias(){
    static string aux[10];
    int cont = 0;
    ifstream archivo;
    archivo.open("creencias.txt", ios::in);
    while(!archivo.eof()){
        string texto;
        getline(archivo,texto);
        aux[cont] = texto;
        cont++;
    }
    archivo.close();
    return aux;
}
string* leerArchivoPaises(){
    static string aux[100];
    int cont = 0;
    ifstream archivo;
    archivo.open("paises.txt", ios::in);
    while(!archivo.eof()){
        string texto;
        getline(archivo,texto);
        aux[cont] = texto;
        cont++;
    }
    archivo.close();
    return aux;
}
string* leerArchivoDeportes(){
    static string aux[20];
    int cont = 0;
    ifstream archivo;
    archivo.open("deportes.txt", ios::in);
    while(!archivo.eof()){
        string texto;
        getline(archivo,texto);
        aux[cont] = texto;
        cont++;
    }
    archivo.close();
    return aux;
}

string * hombres = leerArchivoHombres();
string * mujeres = leerArchivoMujeres();
string * apellidos = leerArchivoApellidos();
string * profesiones = leerArchivoProfesiones();
string * creencias = leerArchivoCreencias();
string * paises = leerArchivoPaises();
string * deportes = leerArchivoDeportes();
string tiposPecados[] = {"Luguria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
string tiposBuenasAcciones[] = {"Castidad","Ayuno","Donacion","Diligencia","Calma","Solidaridad","Humildad"};

int getRandomInt(int inicio,int fin);
static std::mt19937 mt(time(0));
int getRandomInt(int inicio,int fin){
	std::uniform_int_distribution<int>dist(inicio,fin-1);
	return dist(mt);
}

string paraArchivo(){
    time_t now = time(0);
    tm * time = localtime(&now);
    string anio = to_string(1900 + time->tm_year);
    string mes = to_string(1 + time->tm_mon);
    string dia = to_string(time->tm_mday);
    string hora = to_string(time->tm_hour);
    string min = to_string(time->tm_min);
    string seg = to_string(time->tm_sec);
    string result = anio + "-" + mes + "-" + dia + " " + hora + ":" + min + ":" + seg;
    return result;
}

string nombreArchivo(){
    time_t now = time(0);
    tm * time = localtime(&now);
    string anio = to_string(1900 + time->tm_year);
    string mes = to_string(1 + time->tm_mon);
    string dia = to_string(time->tm_mday);
    string hora = to_string(time->tm_hour);
    string min = to_string(time->tm_min);
    string seg = to_string(time->tm_sec);
    string result = anio + mes + dia + "_" + hora + min + seg + ".txt";
    return result;
}

string fechaMuerte(){
    time_t now = time(0);
    tm * time = localtime(&now);
    string anio = to_string(1900 + time->tm_year);
    string mes = to_string(1 + time->tm_mon);
    string dia = to_string(time->tm_mday);
    string result = anio + "-" + mes + "-" + dia;
    return result;
}

struct Fecha{
    int dia;
    int mes;
    int anio;
    string _fecha;

    Fecha(){
        dia = getRandomInt(1,28);
        mes = getRandomInt(1,12);
        anio = getRandomInt(1900, 2022);
        _fecha = to_string(dia) + "-" + to_string(mes) + "-" + to_string(anio);
    }
    int edad(int _anio){
        int edad;
        edad = 2022 - _anio;
        return edad;
    }
};

struct NodoDeporte{
	string nombre;
    int cantidad;
	NodoDeporte * siguiente;

	NodoDeporte(string _nombre, int _cantidad){
		nombre = _nombre;
        cantidad = _cantidad;
		siguiente = NULL;
	}
};

struct ListaSimpleDeportes{
    NodoDeporte * primerNodo;
	NodoDeporte * ultimoNodo;
    ListaSimpleDeportes(){
		primerNodo = ultimoNodo = NULL;
	}
    void insertar(string deporte, int cant){
        if (primerNodo == NULL){
		    primerNodo = ultimoNodo = new NodoDeporte(deporte, cant);
        }
	    else{
		    ultimoNodo->siguiente = new NodoDeporte(deporte, cant);
		    ultimoNodo = ultimoNodo->siguiente;
	    }
    }

    NodoDeporte * buscarDeporte(string deporte){
        NodoDeporte * tmp = primerNodo;
	    while (tmp!= NULL){
  		    if (tmp->nombre == deporte)
		        return tmp;
            tmp = tmp ->siguiente;	
		    }
	    return NULL;
    }
    void imprimir(){
        NodoDeporte * tmp = primerNodo;
        while (tmp != NULL){
  		    cout << tmp->nombre << "\t" << tmp->cantidad << endl;
            tmp = tmp ->siguiente;	
		}
    }
};

struct Persona{
    int ID;
    string nombre;
	string apellido;
	string genero;
	string creencia;
    string profesion;
    Fecha * fechaN;
    int buenasAcciones[7];
    int pecados[7];
    string rangoEtario;
    string estadoM;
    string experiencias[100];
    Persona * amigos[50]; 
    Persona * pareja;
    Persona * hijos[4];
    ListaSimpleDeportes * salud;
    string ubicacion;
    bool vivo;
    int vecesEliminado;
    string personaje;
    bool tieneHijos;
    bool esHijo;
    Persona * padre;
    Persona * madre;
    bool tieneAmigos;
    bool salvado;

    Persona(int _ID, string _nombre, string _apellido, string _genero, string _creencia, string _profesion, string _ubicacion){
        ID = _ID;
        nombre = _nombre;
        apellido = _apellido;
        genero = _genero;
        creencia = _creencia;
        profesion = _profesion;
        fechaN = new Fecha();
        estadoM = generarEstadoM();
        rangoEtario = generarRangoEtario(fechaN);
        pareja = NULL;
        for (int i = 0; i < 4; i++){
            hijos[i] = NULL;
        }
        for(int i = 0; i < 50; i++){
            amigos[i] = NULL;
        }
        for(int i = 0; i < 7; i++){
            buenasAcciones[i] = 0;
        }
        for(int i = 0; i < 7; i++){
            pecados[i] = 0;
        };
        for (int i = 0; i < 100; i++){
            experiencias[i] = "";
        }
        generarPaises();
        salud = new ListaSimpleDeportes();
        ubicacion = _ubicacion;
        vivo = true;
        vecesEliminado = 0;
        personaje = "";
        tieneHijos = false;
        esHijo = false;
        padre = NULL;
        madre = NULL;
        tieneAmigos = false;
        salvado = false;
    }

    void consultarFamilia(){
        cout << "Padre: " << endl;
        padre->imprimir();
        cout << "Madre: " << endl;
        madre->imprimir();
        for (int i = 0; i < 4; i++){
            if(hijos[i] != NULL){
                hijos[i]->imprimir();
            }
        }
    }

    void consultarAmigos(){
        for (int i = 0; i < 50; i++){
            if(amigos[i]!=NULL)
                amigos[i]->imprimir();
        }
        
    }
    
    void imprimir(){
        cout << "ID: " << ID << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Apellido: " << apellido << endl;
        cout << "Padre: " << padre->ID << "    Madre: " << madre->ID << endl;
        cout << "Genero: " << genero << endl;
        cout << "Fecha de Nacimiento: " << fechaN->_fecha << endl;
		cout << "Rango Etario: " << rangoEtario << endl;
		cout << "Creencia: " << creencia << endl;
        cout << "Profesion: " << profesion << endl;
		cout << "Estado Marital: " << estadoM << endl;
		cout << "Pais: " << ubicacion << endl;
        if(vivo == false){
            cout << "Muerto" << endl;
            cout << "Personaje: " << personaje << endl; 
        }
        else{
            cout << "Vivo" << endl;
        }
        if(salvado == true){
            cout << "Salvado" << endl;
            cout << "Personaje: " << personaje << endl;
        }
        else{
            cout << "No ha sido salvado" << endl;
        }
        cout << "Veces eliminado: " << vecesEliminado << endl;
        if(pareja != NULL){
            cout << "Pareja: " << pareja->ID << "\t" << pareja->nombre << " " << pareja->apellido << endl;
        }
        else{
            cout << "No tiene pareja" << endl;
        }
        if(hijos[0] == NULL){
            cout << "No tiene hijos" << endl;
        }
        else{
            for (int i = 0; i < 4; i++){
                if(hijos[i] != NULL){
                    cout << "Hijo " << hijos[i]->ID << "\t" << hijos[i]->nombre << " " << hijos[i]->apellido << endl;
                }
            }
        }
        cout << endl;

        for (int i = 0; i < 50; i++){
            if(amigos[i] != NULL){
                cout << "Amigo " << amigos[i]->ID << "\t" << amigos[i]->nombre << " " << amigos[i]->apellido << endl;
            }
        }
        
		for (int i = 0; i < 7; i++){
            cout << tiposPecados[i] << " ";
			cout << pecados[i] << "   ";
		}
        cout << endl;
        for (int i = 0; i < 7; i++){
            cout << tiposBuenasAcciones[i] << " ";
			cout << buenasAcciones[i] << "   ";
		}
		cout << endl;
		salud->imprimir();
		cout << endl << endl;
    }

    void sumarPecados(){
        for (int i = 0; i < 7; i++){
            int xd = getRandomInt(0,101);
            pecados[i]+=xd;
        }  
    }

    void sumarBuenasAcciones(){
        for (int i = 0; i < 7; i++){
            int xd = getRandomInt(0,101);
            buenasAcciones[i]+=xd;
        }  
    }

    void generarDeportes(int inDeportes, int finDeportes){
        int cantDeportes = getRandomInt(1, 4);
        for(int i = 0;i < cantDeportes;i++){
            string deporte = deportes[getRandomInt(inDeportes, finDeportes)];
            if(salud->buscarDeporte(deporte)!=NULL){
                while(salud->buscarDeporte(deporte)!=NULL){
                    deporte = deportes[getRandomInt(inDeportes, finDeportes)];
                }
            }
            int cant = getRandomInt(1,8);
            salud->insertar(deporte, cant);
        }
    }

    string generarEstadoM(){
        int probabilidad = getRandomInt(0,100);
        string result;
        if(probabilidad <= 10){
            result = "Soltero";
        }
        else if(probabilidad <= 90){
            result = "Casado";       
        } 
        else{
            result = "Divorciado";
        }
        return result;
    }

    string generarRangoEtario(Fecha * _fecha){
        int edad = _fecha->edad(_fecha->anio);
        string result;
        if(edad <= 1){
            result = "Infantil";
        }
        else if(edad <= 4 ){
            result = "Pre-escolar";
        }
        else if(edad <= 10 ){
            result = "Escolar";
        }
        else if(edad <= 14 ){
            result = "Pubertad";
        }
        else if(edad <= 19 ){
            result = "Adolescencia";
        }
        else if(edad <= 24 ){
            result = "Joven";
        }
        else if(edad <= 34 ){
            result = "Adulto Joven";
        }
        else if(edad <= 64 ){
            result = "Adulto Maduro";
        }
        else{
            result = "Adulto Mayor";
        }
        return result;
    }
    void generarPaises(){
        int probabilidad = getRandomInt(0,100);
        if(probabilidad <= 30){
            int cant = getRandomInt(0,3);
            for (int i = 0; i < cant; i++){
                string pais = paises[getRandomInt(0,100)]; 
                while(existePais(this->experiencias, pais, cant)){
                    pais = paises[getRandomInt(0,100)];
                }
                this->experiencias[i]=pais;
            }        
        }
        else if(probabilidad <= 55){
            int cant = getRandomInt(2,11);
            for (int i = 0; i < cant; i++){
                string pais = paises[getRandomInt(0,100)]; 
                while(existePais(this->experiencias, pais, cant)){
                    pais = paises[getRandomInt(0,100)];
                }
                this->experiencias[i]=pais;
            }        
        } 
        else if(probabilidad <= 75){
            int cant = getRandomInt(10,16);
            for (int i = 0; i < cant; i++){
                string pais = paises[getRandomInt(0,100)]; 
                while(existePais(this->experiencias, pais, cant)){
                    pais = paises[getRandomInt(0,100)];
                }
                this->experiencias[i]=pais;
            }        
        }
        else if(probabilidad <= 90){
            int cant = getRandomInt(16,26);
            for (int i = 0; i < cant; i++){
                string pais = paises[getRandomInt(0,100)]; 
                while(existePais(this->experiencias, pais, cant)){
                    pais = paises[getRandomInt(0,100)];
                }
                this->experiencias[i]=pais;
            }        
        }
        else{
            int cant = getRandomInt(25,100);
            for (int i = 0; i < cant; i++){
                string pais = paises[getRandomInt(0,100)]; 
                while(existePais(this->experiencias, pais, cant)){
                    pais = paises[getRandomInt(0,100)];
                }
                this->experiencias[i]=pais;
            }        
        }   
    }
    bool existePais(string * array, string pais, int cant){
        for (int i = 0; i < cant; i++){
            if(array[i]==pais){
                return true;
            }
        }
        return false;
    }

    bool buscarAmigo(Persona * amigo){
        for(int i = 0; i < 50; i++){
            if(amigos[i] != NULL){
                if(amigos[i] == amigo){
                    return true;
                }
            }
        }
        return false;
    } 

    bool buscarHijo(Persona * hijo){
        for(int i = 0; i < 4; i++){
            if(hijos[i] != NULL){
                if(hijos[i] == hijo){
                    return true;
                }
            }
        }
        return false;
    } 

    bool compararAmigos(Persona * amigo){
        for(int j = 0; j<50; j++){
            for(int i = 0; i < 50; i++){
                if(amigos[j] != NULL && amigo->amigos[i]!=NULL ){
                    if(amigos[j] == amigo->amigos[i]){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int cantBuenasAcciones(){
        int result = 0;
        for (int i = 0; i < 7; i++){
            result += buenasAcciones[i];
        }
        return result;
    }

    int cantPecados(){
        int result = 0;
        for (int i = 0; i < 7; i++){
            result += pecados[i];
        }
        return result;
    }

    int buenosidad(){
        int puntos = 0; // el maximo de persona mas buena seria 1000, min 0
        for (int i = 0; i < 7; i++){
            puntos+=buenasAcciones[i];
            puntos-=pecados[i];
        }
        NodoDeporte * tmpDeporte = salud->primerNodo;
        while(tmpDeporte!=NULL){
            puntos+=2;
            puntos+=tmpDeporte->cantidad;
            tmpDeporte = tmpDeporte->siguiente;
        }
        for (int i = 0; i < 50; i++){
            if(amigos[i]!=NULL){
                puntos+=2;
            }
        }
        for (int i = 0; i < 4; i++){
            if(hijos[i]!=NULL){
                puntos+=10;
            }
        }
        int puntosEdad = (60/42) * (fechaN->anio - 1980);
        puntos+=puntosEdad;
        double puntosExp = 0;
        for (int i = 0; i < 100; i++){
            if(experiencias[i]!=""){
                puntosExp+=0.6;
            }
        }
        puntos+=(int)puntosExp;
        puntos = puntos/100;
        if(puntos<0) puntos=0;
        else if (puntos>9) puntos=9;
        
        return puntos;
    }
};

struct NodoPersona{
    Persona * persona;
    NodoPersona * siguiente;
    NodoPersona * anterior;

    NodoPersona(Persona * _persona){
        persona = _persona;
        siguiente = NULL;
        anterior = NULL;
    }
};

struct ListaDobleMundo{
    NodoPersona * primerNodo;
    NodoPersona * ultimoNodo;
    int cant;

    ListaDobleMundo(){
        primerNodo = ultimoNodo = NULL;
        cant = 0;
    }
    
    void generarParejas(){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if(tmp->persona->pareja == NULL && tmp->persona->estadoM != "Soltero"){
                Persona * _pareja = generarParejaAux(tmp);
                if(_pareja != NULL){
                    tmp->persona->pareja = _pareja;
                    _pareja->pareja = tmp->persona;
                }
                else{
                    tmp->persona->estadoM = "Soltero";
                }
            }
            tmp=tmp->siguiente;
        }
    }
    
    Persona * generarParejaAux(NodoPersona * persona){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if(tmp->persona->pareja == NULL && tmp->persona->genero != persona->persona->genero){
                return tmp->persona;
            }
            tmp=tmp->siguiente;
        }
        return NULL;
    }

    void generarHijos(){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if(tmp->persona->tieneHijos == false && tmp->persona->estadoM != "Soltero"){
                int _cant = getRandomInt(0,4);
                for(int i = 0; i < _cant; i++){
                    generarHijo(tmp->persona);
                    tmp->persona->tieneHijos = true;
                }
            }
            tmp=tmp->siguiente;
        }
    }

    void generarHijo(Persona * persona){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if((tmp->persona != persona) && (persona != tmp->persona->pareja) && (tmp->persona->esHijo == false) && (tmp->persona != persona->padre)  && (tmp->persona != persona->madre) && ((tmp->persona->apellido == persona->apellido) || (tmp->persona->apellido == persona->pareja->apellido)) && (!tmp->persona->buscarHijo(persona))) {
                tmp->persona->esHijo = true;
                if(persona->genero == "Masculino"){
                    tmp->persona->padre = persona;
                    tmp->persona->madre = persona->pareja;
                }
                else{
                    tmp->persona->madre = persona;
                    tmp->persona->padre = persona->pareja;
                }
                for (int i = 0; i < 4; i++){
                    if(persona->hijos[i] == NULL){
                        persona->hijos[i] = tmp->persona;
                        if(persona->pareja!=NULL)
                            persona->pareja->hijos[i] = tmp->persona;
                        return;
                    }
                }
            }
            tmp=tmp->siguiente;
        }
    }
    

    void generarAmigos(){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if(tmp->persona->tieneAmigos == false){
                
                int _cant = getRandomInt(0,51);
                for (int i = 0; i < _cant; i++){
                    Persona * amigo = generarAmigo(tmp->persona);
                    tmp->persona->amigos[i]=amigo;
                    
                }
                tmp->persona->tieneAmigos = true;
                tmp=tmp->siguiente;
            }
            else{
                tmp=tmp->siguiente;
            }
            
        }
    }

    Persona * generarAmigo(Persona * persona){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if((tmp->persona != persona) && (tmp->persona->ubicacion == persona->ubicacion) && (persona->buscarAmigo(tmp->persona) == false)){
                return tmp->persona;
            }
            else if(tmp->persona != persona && tmp->persona->ubicacion != persona->ubicacion && persona->buscarAmigo(tmp->persona) == false){
                int probabilidad = getRandomInt(0, 101);
                if(probabilidad <= 40){
                    return tmp->persona;
                }
                else if(persona->compararAmigos(tmp->persona) && probabilidad<=70){
                    return tmp->persona;
                }
            }
            tmp = tmp->siguiente;
        }
        return NULL;
    }
    

    void insertar(Persona * p){ //ADDED 2410
        if (primerNodo == NULL){
            ultimoNodo = primerNodo = new NodoPersona(p);           
        }
        else{
            NodoPersona * nuevo = new NodoPersona(p);
            NodoPersona * tmp = primerNodo;
            while ( (tmp!=NULL) && (tmp->persona->ID < p->ID) ){
                tmp = tmp->siguiente;
            }
            if (tmp==NULL){
                nuevo->anterior = ultimoNodo;
                ultimoNodo->siguiente = nuevo;
                ultimoNodo = nuevo;
            }
            else if( tmp == primerNodo){
                nuevo->siguiente = primerNodo;
                primerNodo->anterior = nuevo;
                primerNodo = nuevo;
            }
            else{
                tmp->anterior->siguiente = nuevo;
                nuevo->anterior = tmp->anterior;
                nuevo->siguiente = tmp;
                tmp->anterior = nuevo;
            }

        }
        cant++; 
    }

    void consultarDeporte(string deporte){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if(tmp->persona->salud->buscarDeporte(deporte) != NULL)
                tmp->persona->imprimir();
            tmp=tmp->siguiente;
        }
    }

    int cantVivos(){
        int result = 0;
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if(tmp->persona->vivo == true)
                result++;
            tmp=tmp->siguiente;
        }
        return result;
    }

    int cantSalvados(){
        int result = 0;
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            if(tmp->persona->salvado == true)
                result++;
            tmp=tmp->siguiente;
        }
        return result;
    }

    void pecados(){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            tmp->persona->sumarPecados();
            tmp=tmp->siguiente;
        }
        
    }

    void buenasAcciones(){
        NodoPersona * tmp = primerNodo;
        while (tmp != NULL){
            tmp->persona->sumarBuenasAcciones();
            tmp=tmp->siguiente;
        }
    }

    NodoPersona* buscarIzq(NodoPersona* raiz, int _id){ //ADDED2410
        NodoPersona * tmp = raiz; 
        if (tmp!=NULL)
            do {
                if (tmp->persona->ID == _id){
                    return tmp;
                }tmp = tmp->anterior;
            } while (tmp!=NULL && tmp->persona->ID >= _id);
        return NULL;
    }

    NodoPersona* buscarDer(NodoPersona* raiz, int _id){
        NodoPersona * tmp = raiz; 
        if (tmp!=NULL)
            do {
                if (tmp->persona->ID == _id){
                    return tmp;
                }tmp = tmp->siguiente;
            } while (tmp!=NULL && tmp->persona->ID <= _id); 
        return NULL;
    }

    NodoPersona* getPosPersona(int pos){
        NodoPersona * tmp = primerNodo;
        int cant = 0;
        while (cant < pos){
            tmp = tmp ->siguiente;
            cant++;	
        }
        return tmp;
    }
    
    string todasLasPersonas(){
        NodoPersona * tmp = primerNodo;
        string xd = "";
        while(tmp!=NULL){
            Persona * p = tmp->persona;
            xd += "Humano " + to_string(tmp->persona->ID) + "\t" + tmp->persona->nombre + " " + tmp->persona->apellido + "\t" + tmp->persona->ubicacion;
            xd += "\t"; 
            xd += "[";
            for (int i = 0; i < 50; i++){
                if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                    xd = xd + to_string(p->amigos[i]->ID) + ", ";
                }
                else if(p->amigos[i]!=NULL){
                    xd = xd + to_string(p->amigos[i]->ID);
                }
            }
            xd = xd + "]";
            xd = xd + "\t";
            if(p->pareja!=NULL)
                xd = xd + to_string(p->pareja->ID) + "\t";
            xd = xd + "[";
            for (int i = 0; i < 4; i++){
                if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                    xd = xd + to_string(p->hijos[i]->ID) + ", ";
                }
                else if(p->hijos[i]!=NULL){
                    xd = xd + to_string(p->hijos[i]->ID);
                }
            }
            xd = xd + "]"; 
            xd = xd + "\t";
            xd = xd + "[";
            for (int i = 0; i < 100; i++){
                if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                    xd = xd + p->experiencias[i] + ", ";
                }
                else if(p->experiencias[i]!=""){
                    xd = xd + p->experiencias[i];
                }
            }
            xd = xd + "]";
            xd = xd + "\n\n";
            tmp=tmp->siguiente;
        }
        return xd;
    }
};

struct NodoArbol{
    NodoPersona * persona;
    NodoArbol * hijoIzq;
    NodoArbol * hijoDer;
    int feromonas; //ESTO 1/11


    NodoArbol(NodoPersona * p){
        persona = p;
        hijoDer = hijoIzq = NULL;
        feromonas = 0; //ESTO 1/11
    }
};

struct NodoArbolNodo{
    NodoArbol * nodoArbol;
    NodoArbolNodo * siguiente;
    NodoArbolNodo * anterior;

    NodoArbolNodo(NodoArbol * n){
        nodoArbol = n;
        siguiente = anterior = NULL;
    }
};

struct ListaNodoArbol{
    NodoArbolNodo * primerNodo;
    NodoArbolNodo * ultimoNodo;

    ListaNodoArbol(){
        primerNodo = ultimoNodo = NULL;
    }

    void insertar(NodoArbol * p){ //ADDED 2410
        if (primerNodo == NULL){
            ultimoNodo = primerNodo = new NodoArbolNodo(p);           
        }
        else{
            NodoArbolNodo * nuevo = new NodoArbolNodo(p);
            NodoArbolNodo * tmp = primerNodo;
            while ( (tmp!=NULL) && (tmp->nodoArbol->feromonas > p->feromonas) ){
                tmp = tmp->siguiente;
            }
            if (tmp==NULL){
                nuevo->anterior = ultimoNodo;
                ultimoNodo->siguiente = nuevo;
                ultimoNodo = nuevo;
            }
            else if( tmp == primerNodo){
                nuevo->siguiente = primerNodo;
                primerNodo->anterior = nuevo;
                primerNodo = nuevo;
            }
            else{
                tmp->anterior->siguiente = nuevo;
                nuevo->anterior = tmp->anterior;
                nuevo->siguiente = tmp;
                tmp->anterior = nuevo;
            }

        }
    }
};

struct ArbolDelMundo{ 
    NodoArbol * raiz;
    ListaDobleMundo * mundo;
    int cantArbol;
    int cantLista;
    int elevar;
    int h;
    
    ArbolDelMundo(ListaDobleMundo * _mundo){
        raiz = NULL;
        mundo = _mundo;
        cantLista = _mundo->cant;
        cantArbol = 0; 
        h = 0;
        elevar = 0;
        while (elevar < cantLista/100){  
        	elevar = pow(2,h++) ;     
		}
        h--;
		elevar = elevar-1;  
        if (elevar<1) { elevar=1; h=1;} //para q siempre exista aunque sea la raiz							 
    }
    
    NodoArbol * insertar(NodoArbol * nodo, int pos, int altura, int indice){
        if (cantArbol < elevar && altura<h && nodo==NULL){
            nodo = new NodoArbol(mundo->getPosPersona(pos));
            cantArbol++;
            int restar = (cantLista/2) / indice;
            nodo->hijoIzq = insertar(nodo->hijoIzq, pos - restar, altura+1, indice*2);
            nodo->hijoDer = insertar(nodo->hijoDer, pos + restar , altura+1, indice*2);
            return nodo;
        }
        return NULL;
    }
    
    void reiniciarArbol(){
		raiz = insertar(raiz, cantLista/2, 0, 2); 
	}

    NodoPersona* existe(NodoArbol * raiz, int id){
    	if(raiz == NULL)
            return NULL;
        else{
            if(raiz->persona->persona->ID == id)
                return raiz->persona;
            
            else
                if (id < raiz->persona->persona->ID) 
                	if(raiz->hijoIzq!=NULL) 
                		return existe(raiz->hijoIzq, id);
                	else 
                		return mundo->buscarIzq(raiz->persona, id);                
                else
                    if (raiz->hijoDer!=NULL)
                    	return existe(raiz->hijoDer, id) ; 
                	else
                		return mundo->buscarDer(raiz->persona, id) ;             
	    }
    }
    void imprimir(){
        cout << endl;
        _imprimir(raiz, 0);
        cout << endl;
    }
    void _imprimir(NodoArbol * raiz,int n){
        if(raiz == NULL){
            return;
        }
        else{
            _imprimir(raiz->hijoDer,n+1);
            for (int i = 0; i < n; i++){
                cout<< "         ";
            }
            cout<<raiz->persona->persona->ID<<endl;
            _imprimir(raiz->hijoIzq,n+1);
        }
    }

};

struct Personaje{
    string nombre;
    int cant;
    ListaDobleMundo * asesinados;

    Personaje(string _nombre, int _cant){
        nombre = _nombre;
        cant = _cant;
        asesinados = new ListaDobleMundo();
    }
};

struct NodoPersonaje{
    Personaje * personaje;
    NodoPersonaje * siguiente;
    NodoPersonaje * anterior;

    NodoPersonaje(Personaje * _personaje){
        personaje = _personaje;
        siguiente = NULL;
        anterior = NULL;
    }
};

struct ListaSimplePersonajes{
    NodoPersonaje * primerNodo;
	NodoPersonaje * ultimoNodo;
    ListaSimplePersonajes(){
		primerNodo = ultimoNodo = NULL;
	}
    void insertar(string personaje, int cant){
        if (primerNodo == NULL){
		    primerNodo = ultimoNodo = new NodoPersonaje(new Personaje(personaje, cant));
        }
	    else{
		    ultimoNodo->siguiente = new NodoPersonaje(new Personaje(personaje, cant));
		    ultimoNodo = ultimoNodo->siguiente;
	    }
    }
};

struct Mundo{
    ArbolDelMundo * arbol;
    ListaDobleMundo * lista;
    ListaSimplePersonajes * listaPersonajes;

    Mundo(){
        lista = new ListaDobleMundo();
        arbol = new ArbolDelMundo(lista);
        listaPersonajes = new ListaSimplePersonajes();
        listaPersonajes->insertar("Thanos", 0);
        listaPersonajes->insertar("Corvus Glaive", 0);
        listaPersonajes->insertar("Midnight", 0);
        listaPersonajes->insertar("Nebula", 0);
        listaPersonajes->insertar("Ebony Maw", 0);
        listaPersonajes->insertar("Black Dwarf", 0);
        listaPersonajes->insertar("Ant Man", 0);
        listaPersonajes->insertar("Iron Man", 0);
        listaPersonajes->insertar("Thor", 0);
        listaPersonajes->insertar("Spiderman", 0);
    }
    void menu1(){
        int opcion = 999999;
        while (opcion != 0){
    	    cout << "1. Añadir personas al mundo "
            << "\n2. Sumar pecados a la humanidad "
            << "\n3. Sumar buenas acciones a la humanidad "
            << "\n4. Consultas del mundo "
            << "\n5. Aniquilacion "
            << "\n6. Salvacion "
            << "\n7. Ganador "
            << "\n0. Salir\n";
            cout << "Ingrese la opcion: ";
		    cin >> opcion;
            cout << endl;

            switch (opcion){	
                case 1: {
                    int cant;
                    cout << "Cuantas personas desea añadir: ";
                    cin >> cant;
                    
                    insertarPersonas(cant);
                    lista->generarParejas();
                    lista->generarHijos();
                    lista->generarAmigos();
                    arbol = new ArbolDelMundo(lista);
                    arbol->reiniciarArbol();
                    cout << endl;
                    break;
                }
                case 2: {
                    lista->pecados();
                    cout << "Se han agregado exitosamente los pecados a la humanidad" << endl << endl;
                	break;
                }
                case 3: {
                    lista->buenasAcciones();
                    cout << "Se han agregado exitosamente las virtudes a la humanidad" << endl << endl;
                	break;
                }
                case 4: {
                    menu2();
                	break;
                }
                case 5: {
                    menu3();
                	break;
                }
                case 6: {
                    menu4();
                	break;
                }
                case 7: {
                    ganador();
                    cout << endl;
                	break;
                }
                case 0: {
                	break;
                }
                default:{
                cout << "Ingrese una opcion correcta" << endl;
                }
            }
        }
    }

    void menu2(){
        int opcion = 999999;
        while (opcion != 0){
    	    cout << "1. Consulta humano por ID "
            << "\n2. Consultar la familia de un ID "
            << "\n3. Consultar la cadena de amigos de amigos de un ID "
            << "\n4. Consultar los humanos que practican un deporte en particular "
            << "\n5. Cantidad de humanos vivos, eliminados y salvados "
            << "\n6. Imprimir el arbol "
            << "\n0. Salir\n";
            cout << "Ingrese la opcion: ";
		    cin >> opcion;
            cout << endl;

            switch (opcion){	
                case 1: {
                    int id;
                    cout << "Ingrese el ID que desea consultar: ";
                    cin >> id;
                    if(arbol->existe(arbol->raiz, id)!=NULL){
                        cout << arbol->existe(arbol->raiz, id)->persona->ID << endl;
                        arbol->existe(arbol->raiz, id)->persona->imprimir();
                    }
                    else{
                        cout << "El ID ingresado no corresponde a nadie en el mundo " << endl;
                    }
                    cout << endl;
                    break;
                }
                case 2: {
                    int id;
                    cout << "Ingrese el ID que desea consultar: ";
                    cin >> id;
                    if(arbol->existe(arbol->raiz, id)!=NULL){
                        arbol->existe(arbol->raiz, id)->persona->consultarFamilia();
                    }
                    else{
                        cout << "El ID ingresado no corresponde a nadie en el mundo " << endl;
                    }
                    cout << endl;
                	break;
                }
                case 3: {
                    int id;
                    cout << "Ingrese el ID que desea consultar: ";
                    cin >> id;
                    if(arbol->existe(arbol->raiz, id)!=NULL){
                        arbol->existe(arbol->raiz, id)->persona->consultarAmigos();
                    }
                    else{
                        cout << "El ID ingresado no corresponde a nadie en el mundo " << endl;
                    }
                    cout << endl;
                	break;
                }
                case 4: {
                    string deporte;
                    cin.ignore(10000,'\n');
                    cout << "\nIngrese el deporte: ";
                    getline(cin, deporte);
                    NodoPersona * tmp = lista->primerNodo;
                    int cont = 0;
                    ListaDobleMundo * xd = new ListaDobleMundo(); 
                    while (tmp != NULL){
                        if(tmp->persona->salud->buscarDeporte(deporte) != NULL){
                            xd->insertar(tmp->persona);
                        }
                        tmp=tmp->siguiente;
                    }
                    tmp = xd->primerNodo;
                    if (tmp == NULL){
                        cout << "No hay personas con el deporte seleccionado" << endl;
                        return;
                    }
                    while(tmp!=NULL){
                        tmp->persona->imprimir();
                        tmp=tmp->siguiente;
                    }
                	break;
                }
                case 5: {
                    cout << "Cantidad de vivos: " << lista->cantVivos() << endl;
                    cout << "Cantidad de muertos: " << lista->cant - lista->cantVivos() << endl;
                    cout << "Cantidad de salvados: " << lista->cantSalvados() << endl;
                    cout << endl;
                	break;
                }
                case 6: {
                    arbol->imprimir();
                    cout << endl;
                	break;
                }
                case 0: {
            	break;
                }
                default:{
                    cout << "Ingrese una opcion correcta" << endl;
                }
            }
        }   
    }

    void menu3(){
        int opcion = 999999;
        while (opcion != 0){
    	    cout << "1. Thanos "
            << "\n2. Corvus Glaive "
            << "\n3. Midnight "
            << "\n4. Nebula "
            << "\n5. Ebony Maw "
            << "\n6. Black Dwarf "
            << "\n7. Consulta "
            << "\n0. Salir\n";
            cout << "Ingrese la opcion: ";
		    cin >> opcion;
            cout << endl;

            switch (opcion){	
                case 1: {
                    int anio;
                    cout << "Ingrese el anio que desea eliminar ";
                    cin >> anio;
                    int nivel;
                    cout<< "\nIngrese el nivel que desea eliminar: ";
                    cin>>nivel;
                    Thanos(anio,nivel);
                    break;
                }
                case 2: {
                    CorvusGlaive(lista->cant);
                	break;
                }
                case 3: {
                    Midnight(lista->cant);
                	break;
                }
                case 4: {
                    NodoArbol * persona = brincar();
                    cout << persona->persona->persona->ID << endl;
                    Nebula(persona->persona->persona->ID, persona->persona->persona->ID);
                	break;
                }
                case 5: {
                    int id;
                    id = getRandomInt(0,10000000);
                    if(arbol->existe(arbol->raiz, id)==NULL){
                        while(arbol->existe(arbol->raiz, id)==NULL){
                            id=getRandomInt(0,10000000);
                        }   
                    }
                    EbonyMaw(id, id);
                	break;
                }
                case 6: {
                    int cant;
                    cout << "Ingrese la cantidad que debe practicar el deporte: ";
                    cin >> cant;
                    string deporte = deportes[getRandomInt(0,20)];
                    cout << deporte << "   " << cant << endl;
                    BlackDwarf(deporte, cant);
                    cout << endl;
                 	break;
                }
                case 7: {
                    consultaAniquilacion();
                    cout << "La informacion ha sido introducida a un archivo de texto " << endl;
                	break;
                }
                case 0: {
                    system("C:\\Users\\50672\\Documents\\NetBeansProjects\\CorreoSpiderman_1\\dist\\CorreoSpiderman_1.jar");
                	break;
                }
                default:{
                    cout << "Ingrese una opcion correcta" << endl;
                }
            }
        }
    }

    void menu4(){
        int opcion = 999999;
        while (opcion != 0){
    	    cout << "1. Ant Man "
            << "\n2. Iron Man "
            << "\n3. Thor "
            << "\n4. Spiderman "
            << "\n5. Consulta "
            << "\n0. Salir\n";
            cout << "Ingrese la opcion: ";
		    cin >> opcion;
            cout << endl;

            switch (opcion){	
                case 1: {
                    int nivel;
                    cout << "Ingrese la cantidad de hormigas que desea enviar ";
                    cin >> nivel;
                    AntMan(nivel);
                    break;
                }
                case 2: {
                    IronMan();
                	break;
                }
                case 3: {
                    int nivel;
                    cout << "Ingrese el nivel cuyos amigos de la familia desea salvar: ";
                    cin >> nivel;
                    Thor(nivel);
                	break;
                }
                case 4: {
                    Spiderman();
                	break;
                }
                case 5: {
                    consultaSalvacion();
                    cout << "La informacion ha sido introducida a un archivo de texto " << endl;
                	break;
                }
                case 0: {
                    system("C:\\Users\\50672\\Documents\\NetBeansProjects\\CorreoSpiderman\\dist\\CorreoSpiderman.jar");
                	break;
                }
                default:{
                    cout << "Ingrese una opcion correcta" << endl;
                }
            }
        }
    }

    void insertarPersonas(int cant){
        int inNombre;
        int finNombre;
        cout << "Rango inicio nombre: ";
        cin >> inNombre;
        cout << "Rango final nombre: ";
        cin >> finNombre;

        int inApellido;
        int finApellido;
        cout << "Rango inicio apellido: ";
        cin >> inApellido;
        cout << "Rango final apellido: ";
        cin >> finApellido;

        int inCreencia;
        int finCreencia;
        cout << "Rango inicio creencia: ";
        cin >> inCreencia;
        cout << "Rango final creencia: ";
        cin >> finCreencia;

        int inProfesion;
        int finProfesion;
        cout << "Rango inicio profesion: ";
        cin >> inProfesion;
        cout << "Rango final profesion: ";
        cin >> finProfesion;

        int inPais;
        int finPais;
        cout << "Rango inicio pais: ";
        cin >> inPais;
        cout << "Rango final pais: ";
        cin >> finPais;

        int inDeportes;
        int finDeportes;
        cout << "Rango inicio deportes: ";
        cin >> inDeportes;
        cout << "Rango final deportes: ";
        cin >> finDeportes;

        for(int i=0;i<cant;i++){
            insertarNuevaPersona(inNombre, finNombre, inApellido, finApellido, inCreencia, finCreencia, inProfesion, finProfesion, inPais, finPais, inDeportes, finDeportes);
        }
    }

    void insertarNuevaPersona(int inNombre, int finNombre, int inApellido, int finApellido, int inCreencia, int finCreencia, int inProfesion, int finProfesion, int inPais, int finPais, int inDeportes, int finDeportes){
        int id=getRandomInt(0,10000000);
        if(arbol->existe(arbol->raiz, id)!=NULL){
            while(arbol->existe(arbol->raiz, id)!=NULL){
                id=getRandomInt(0,10000000);
            }
        }
        int genero = getRandomInt(0,101);

        if(genero <= 50){
            Persona * persona = new Persona(id,hombres[getRandomInt(inNombre,finNombre)],apellidos[getRandomInt(inApellido,finApellido)], "Masculino", creencias[getRandomInt(inCreencia,finCreencia)],profesiones[getRandomInt(inProfesion,finProfesion)], paises[getRandomInt(inPais,finPais)]);
            persona->generarDeportes(inDeportes, finDeportes);
            lista->insertar(persona);
        }
        else{
            Persona * persona = new Persona(id,mujeres[getRandomInt(inNombre,finNombre)],apellidos[getRandomInt(inApellido,finApellido)], "Femenino", creencias[getRandomInt(inCreencia,finCreencia)],profesiones[getRandomInt(inProfesion,finProfesion)], paises[getRandomInt(inPais,finPais)]);
            persona->generarDeportes(inDeportes, finDeportes);
            lista->insertar(persona);
        }
    }
    
    void CorvusGlaive(int cant){
        string fecha = "LogAniquilacion.txt";
        Persona * heap[cant];
        int heapSize = 0;
        int cont = 0;

        NodoPersona * tmp = lista->primerNodo;
        while(tmp!=NULL){
            heap[heapSize] = tmp->persona;
            int curr = heapSize;
            while(curr > 0 && heap[(curr-1)/2]->cantPecados() < heap[curr]->cantPecados()){ 
                Persona * temp = heap[(curr-1)/2];
                heap[(curr-1)/2] = heap[curr];
                heap[curr] = temp;
                curr = (curr-1)/2;    //Current pointer moves to parent
            }
            tmp=tmp->siguiente;
            heapSize++;
        }
        for(int i=0;i<heapSize*0.05;++i){
            if(heap[i]->vivo == true){
                heap[i]->vecesEliminado++;
                heap[i]->vivo=false;
                heap[i]->salvado=false;
                cout << "Corvus Glaive ha matado a " << heap[i]->ID << " por " << heap[i]->cantPecados() << " pecados" << endl;
                heap[i]->personaje = "Corvus Glaive";
                cont++;
                reporteCorvusGlaive(fecha,heap[i]);
                NodoPersonaje * lol = listaPersonajes->primerNodo;
                while(lol->personaje->nombre != "Corvus Glaive"){
                    lol = lol->siguiente;
                }
                lol->personaje->asesinados->insertar(heap[i]);
            }
        }
        NodoPersonaje * lol = listaPersonajes->primerNodo;
        while(lol->personaje->nombre != "Corvus Glaive"){
            lol = lol->siguiente;
        }
        lol->personaje->cant = lol->personaje->cant + cont;
    }

    void Midnight(int cant){
        string fecha = "LogAniquilacion.txt";
        Persona * heap[cant];
        int heapSize = 0;
        int cont = 0;

        NodoPersona * tmp = lista->primerNodo;
        while(tmp!=NULL){
            heap[heapSize] = tmp->persona;
            int curr = heapSize;
            while(curr > 0 && heap[(curr-1)/2]->cantBuenasAcciones() > heap[curr]->cantBuenasAcciones()){ 
                Persona * temp = heap[(curr-1)/2];
                heap[(curr-1)/2] = heap[curr];
                heap[curr] = temp;
                curr = (curr-1)/2;    //Current pointer moves to parent
            }
            tmp=tmp->siguiente;
            heapSize++;
        }
        for(int i=0;i<heapSize*0.05;++i){
            if(heap[i]->vivo == true){
                heap[i]->vecesEliminado++;
                heap[i]->vivo=false;
                heap[i]->salvado=false;
                cout << "Midnight ha matado a " << heap[i]->ID << " por " << heap[i]->cantBuenasAcciones() << " buenas acciones" << endl;
                heap[i]->personaje = "Midnight"; 
                cont++;
                reporteMidnight(fecha, heap[i]);
                NodoPersonaje * lol = listaPersonajes->primerNodo;
                while(lol->personaje->nombre != "Midnight"){
                    lol = lol->siguiente;
                }
                lol->personaje->asesinados->insertar(heap[i]); 
            }
        }
        NodoPersonaje * lol = listaPersonajes->primerNodo;
        while(lol->personaje->nombre != "Midnight"){
            lol = lol->siguiente;
        }
        lol->personaje->cant = lol->personaje->cant + cont;
    }

    void BlackDwarf(string deporte, int cant){
        string fecha = "LogAniquilacion.txt";
        NodoPersona * tmp = lista->primerNodo;
        int cont = 0;
        ListaDobleMundo * xd = new ListaDobleMundo(); 
        while (tmp != NULL){
            if(tmp->persona->salud->buscarDeporte(deporte) != NULL && tmp->persona->salud->buscarDeporte(deporte)->cantidad > cant && tmp->persona->vivo == true){
                xd->insertar(tmp->persona);
            }
            tmp=tmp->siguiente;
        }
        tmp = xd->primerNodo;
        if (tmp == NULL){
            cout << "No hay personas con el deporte seleccionado" << endl;
            return;
        }
        while (cont < xd->cant/2){
            tmp->persona->vecesEliminado++;
            tmp->persona->vivo=false;
            tmp->persona->salvado=false;
            cout << "Black Dwarf ha matado a " << tmp->persona->ID << " por practicar " << deporte << " " << tmp->persona->salud->buscarDeporte(deporte)->cantidad << " veces" << endl;
            tmp->persona->personaje = "Black Dwarf";  
            reporteBlackDwarf(fecha, tmp->persona, deporte, tmp->persona->salud->buscarDeporte(deporte)->cantidad); 
            cont++;
            NodoPersonaje * lol = listaPersonajes->primerNodo;
            while(lol->personaje->nombre != "Black Dwarf"){
                lol = lol->siguiente;
            }
            lol->personaje->asesinados->insertar(tmp->persona);
            tmp = tmp->siguiente;
        }

        NodoPersonaje * lol = listaPersonajes->primerNodo;
        while(lol->personaje->nombre != "Black Dwarf"){
            lol = lol->siguiente;
        }
        lol->personaje->cant = lol->personaje->cant + xd->cant/2;
    }

    void Thanos(int matarAnio, int matarNivel){
        string fecha = "LogAniquilacion.txt";
        ListaDobleMundo* Hash[122][10];
        for (int i = 0 ; i < 122; i++){ //de 1900 a 2022
            for(int j = 0 ; j < 10 ; j++){
                Hash[i][j] = new ListaDobleMundo();
            }
        }
        NodoPersona * tmp = lista->primerNodo;
        while(tmp!=NULL){
            int anio = tmp->persona->fechaN->anio - 1900;
            int nivel = tmp->persona->buenosidad();
            Hash[anio][nivel]->insertar(tmp->persona);
            tmp = tmp->siguiente;
        }
        //matar
        int cont = 0;
        ListaDobleMundo* tmpMatados = Hash[matarAnio-1900][matarNivel-1];
        if (tmpMatados!=NULL){
            NodoPersona* tmpPersona = tmpMatados->primerNodo;
        while(tmpPersona !=NULL){
            tmpPersona->persona->vecesEliminado++;
            tmpPersona->persona->vivo=false;
            tmpPersona->persona->salvado = false;
            tmpPersona->persona->personaje="Thanos";
            cout << "Thanos ha matado a " << tmpPersona->persona->ID << " anio " << tmpPersona->persona->fechaN->anio << " y nivel " << tmpPersona->persona->buenosidad()+1 << endl;
            reporteThanos(fecha, tmpPersona->persona, matarAnio, matarNivel);
            NodoPersonaje * lol = listaPersonajes->primerNodo;
            while(lol->personaje->nombre != "Thanos"){
                lol = lol->siguiente;
            }
            lol->personaje->asesinados->insertar(tmpPersona->persona); 
            tmpPersona= tmpPersona->siguiente;
            cont++;
            
        }}
        NodoPersonaje * lol = listaPersonajes->primerNodo;
        while(lol->personaje->nombre != "Thanos"){
            lol = lol->siguiente;
        }
        lol->personaje->cant+=cont; 
    }

    void EbonyMaw(int id, int familiar){
        string fecha = "LogAniquilacion.txt";
        NodoPersona * persona = arbol->existe(arbol->raiz,id);
        if(persona != NULL){
            eliminarTodaFamilia(persona->persona, familiar, fecha);
        }
        else{
            cout << "Persona no fue encontrada" << endl;
        }
    }

    void eliminarTodaFamilia(Persona * persona, int familiar, string fecha){
        if(persona != NULL && persona->vivo && persona->personaje != "Ebony Maw"){
            eliminarEbonyMaw(persona, familiar, fecha);
            eliminarTodaFamilia(persona->madre, familiar, fecha);
            eliminarTodaFamilia(persona->padre, familiar, fecha);
            for (int i = 0; i < 4; i++){
                if(persona->hijos[i]!=NULL){
                    eliminarTodaFamilia(persona->hijos[i], familiar, fecha);
                }
            }
        }
    }

    void eliminarEbonyMaw(Persona * persona, int familiar, string fecha){
        if (persona != NULL && persona->vivo == true){
            persona->personaje = "Ebony Maw";
            persona->vivo = false;
            persona->vecesEliminado++;
            persona->salvado = false;
            cout << "Ebony Maw ha matado a " << persona->ID << " por ser familiar de " << familiar << endl;
            reporteEbonyMaw(fecha, persona, familiar);
            NodoPersonaje * lol = listaPersonajes->primerNodo;
            while(lol!=NULL && lol->personaje->nombre != "Ebony Maw"){
                lol = lol->siguiente;
            }
            lol->personaje->asesinados->insertar(persona);
            lol->personaje->cant++;
        }
    }

    void Nebula(int id, int amigo){
        string fecha = "LogAniquilacion.txt";
        NodoPersona * persona = arbol->existe(arbol->raiz, id);
        if(persona!=NULL){
            eliminarAmigos(persona->persona, amigo, fecha);
        }
        else{
            cout << "Persona no fue encontrada" << endl;
        }
    }

    void eliminarAmigos(Persona * persona, int amigo, string fechaArchivo){
        if(persona != NULL && persona->vivo && persona->personaje != "Nebula"){
            eliminarNebula(persona, amigo, fechaArchivo);
            for (int i = 0; i < 50; i++){
                if(persona->amigos[i] != NULL){
                    eliminarAmigos(persona->amigos[i], amigo, fechaArchivo);
                }
            }
        }
    }

    void eliminarNebula(Persona * persona, int amigo, string fechaArchivo){
        if (persona != NULL && persona->vivo == true){
            persona->personaje = "Nebula";
            persona->vivo = false;
            persona->vecesEliminado++;
            persona->salvado = false;
            cout << "Nebula ha matado a " << persona->ID << " por ser parte de la cadena de amigos de " << amigo << endl;
            reporteNebula(fechaArchivo, persona, amigo);
            NodoPersonaje * lol = listaPersonajes->primerNodo;
            while(lol!=NULL && lol->personaje->nombre != "Nebula"){
                lol = lol->siguiente;
            }
            lol->personaje->asesinados->insertar(persona);
            lol->personaje->cant++;
        }
    }

    void Thor(int nivel){
        string fecha = "LogSalvacion.txt";
        ListaDobleMundo* elegidos = new ListaDobleMundo();
        Thor_getElegidos(elegidos, arbol->raiz,nivel);
        NodoPersona * tmp = elegidos->primerNodo;
        while(tmp!=NULL){
            Thor_salvar(fecha, tmp->persona);
            tmp = tmp->siguiente;
        }
    }

    void Thor_getElegidos(ListaDobleMundo* lista, NodoArbol * nodo, int nivel){
        if(nodo!=NULL){
            if (nivel == 0){
                lista->insertar(nodo->persona->persona);
            }
            else{
                Thor_getElegidos(lista, nodo->hijoIzq, nivel-1);
                Thor_getElegidos(lista, nodo->hijoDer, nivel-1);
            }
        }
    
    }

    void Thor_salvar(string fecha, Persona * persona){
        salvarAmigos(fecha, persona->madre, persona);
        salvarAmigos(fecha, persona->padre, persona);
        salvarAmigos(fecha, persona->pareja, persona);
        for (int i = 0; i < 4; i++){
            salvarAmigos(fecha, persona->hijos[i], persona);
        }       
    }

    void salvarAmigos(string fecha, Persona* persona, Persona * familiar){
        if (persona!=NULL && familiar != NULL){
            aux_ReporteThor(fecha, familiar->ID, persona->ID);
            for (int i = 0; i < 50; i++){
                if (persona->amigos[i]!=NULL && !persona->amigos[i]->vivo){
                    persona->amigos[i]->vivo = true;
                    persona->amigos[i]->personaje = "Thor";
                    persona->amigos[i]->salvado = true;
                    cout << "Thor salvo a " << to_string(persona->amigos[i]->ID) << " por ser amigo de " << to_string(persona->ID) << endl;
                    reporteThor(fecha, persona->amigos[i], persona->ID);
                    NodoPersonaje * lol = listaPersonajes->primerNodo;
                    while(lol!=NULL && lol->personaje->nombre != "Thor"){
                        lol = lol->siguiente;
                    }
                    lol->personaje->asesinados->insertar(persona->amigos[i]);
                    lol->personaje->cant++;
                }
            }
        }
    }

    void Spiderman(){
        string fecha = "LogSalvacion.txt";
        ListaDobleMundo * tela = new ListaDobleMundo();
        NodoArbol * tmp = arbol->raiz;
        while (tmp!=NULL && tmp->hijoDer!=NULL && tmp->hijoDer!=NULL){
            tmp = brincar();
            if(tmp!=NULL){
                tela->insertar(tmp->persona->persona);
                aux_ReporteSpiderman(fecha, tmp->persona->persona);
            }
        }
        NodoPersona * brincado = tela->primerNodo;
        int contador = 1;
        while (brincado!=NULL && brincado->siguiente!=NULL){
            contador++;
            brincado= brincado->siguiente;
        }
        salvarDerecha(fecha, brincado, contador);
    }

    NodoArbol *  brincar(){
        int random = getRandomInt(0, arbol->h);
        NodoArbol * tmp = arbol->raiz;
        while (random>0 && tmp!=NULL){
            int randomBool = getRandomInt(0,2);
            if(randomBool==0){
                tmp = tmp->hijoDer;
            }
            else{
                tmp = tmp->hijoIzq;
            }
            random--;
        }
        return tmp;
    }

    void salvarDerecha(string fecha, NodoPersona * persona, int cantidadSalvados){
       NodoPersona * inicio = arbol->existe(arbol->raiz,persona->persona->ID);
       int inicial = inicio->persona->ID;
       if (inicio!=NULL){
            while (cantidadSalvados>0){
                inicio->persona->personaje = "Spiderman";
                inicio->persona->vivo = true;
                inicio->persona->salvado = true;
                cout << "Spiderman salvo a " << to_string(inicio->persona->ID) << endl;
                reporteSpiderman(fecha, inicio->persona, inicial);
                NodoPersonaje * lol = listaPersonajes->primerNodo;
                while(lol!=NULL && lol->personaje->nombre != "Spiderman"){
                    lol = lol->siguiente;
                }
                lol->personaje->cant++;
                lol->personaje->asesinados->insertar(inicio->persona);
                inicio = inicio->siguiente;                
                cantidadSalvados--;
            }
       }
    }

    void IronMan(){ 
        string fecha = "LogSalvacion.txt";
        int probabilidad = getRandomInt(40,60);
        int cantBombeados = (int)((arbol->cantArbol)/100.0 * probabilidad);
        ListaDobleMundo * bombas = new ListaDobleMundo();  
        cout << "Explotaron " << cantBombeados << " bombas, por ser el " << probabilidad << "% de " << arbol->cantArbol << endl << endl;
        while (cantBombeados>0){
            NodoArbol * tmp = brincar();
            if(tmp!=NULL){
                bombas->insertar(tmp->persona->persona);
                cantBombeados--;
            }
        }
        
        NodoPersona * salvando = bombas->primerNodo;
        while(salvando!=NULL){
            salvarTodaFamilia(fecha, salvando->persona, salvando->persona->ID);
            salvando = salvando->siguiente;
        }

    }

    void salvarTodaFamilia(string fecha, Persona * persona, int familiar){
        if(persona != NULL && persona->personaje != "Iron Man"){
            salvarIronMan(fecha, persona, familiar);
            salvarIronMan(fecha, persona->madre, familiar);
            salvarIronMan(fecha, persona->padre, familiar);
            for (int i = 0; i < 4; i++){
                if(persona->hijos[i]!=NULL){
                    salvarIronMan(fecha, persona->hijos[i], familiar);
                }
            }
        }
    }

    void salvarIronMan(string fecha, Persona * persona, int familiar){
        if (persona != NULL && !persona->vivo){
            persona->personaje = "Iron Man";
            persona->vivo = true;
            persona->salvado = true;
            cout << "Iron Man ha salvado a " << persona->ID << " por ser familiar de " << familiar << endl;
            reporteIronMan(fecha, persona,familiar);
            NodoPersonaje * lol = listaPersonajes->primerNodo;
            while(lol!=NULL && lol->personaje->nombre != "Iron Man"){
                lol = lol->siguiente;
            }
            lol->personaje->cant++;
            lol->personaje->asesinados->insertar(persona);
        }
    }

    void bombear(NodoArbol * nodo, ListaDobleMundo * lista, int prob){
        if(nodo!=NULL){
            int probabilidad = getRandomInt(0,100);
            if(probabilidad<prob){
               lista->insertar(nodo->persona->persona);
            }
            bombear(nodo->hijoDer,lista,prob);
            bombear(nodo->hijoIzq, lista, prob);
        }
    }
    
    void ganador(){
        NodoPersonaje * lol = listaPersonajes->primerNodo;
        NodoPersonaje * ganador = listaPersonajes->primerNodo;
        while(lol != NULL){
            if(lol->personaje->cant > ganador->personaje->cant){
                ganador = lol;
            }
            lol = lol->siguiente;
        }
        if(ganador->personaje->nombre == "Thanos" || ganador->personaje->nombre == "Corvus Glaive" || ganador->personaje->nombre == "Midnight" || ganador->personaje->nombre == "Nebula" || ganador->personaje->nombre == "Ebony Maw" || ganador->personaje->nombre == "Black Dwarf"){
           cout << "Ganador: " << ganador->personaje->nombre << " por asesinar a " << ganador->personaje->cant << " personas" << endl;
        }
        else{
            cout << "Ganador: " << ganador->personaje->nombre << " por salvar a " << ganador->personaje->cant << " personas" << endl;
        }
    }

    void AntMan(int ants){
        string fecha = "LogSalvacion.txt";
        string reporte = "\n";
        for (int i = 0; i < ants; i++){
            reporte+= "Hormiga " + to_string(i) + "\t";
            reporte+= hormiga();
        }

        ListaNodoArbol *  listaFeromonas = new ListaNodoArbol();
        insertarNodos(listaFeromonas,arbol->raiz);
        NodoArbolNodo * tmp = listaFeromonas->primerNodo;
        
        NodoArbol * primero = listaFeromonas->primerNodo->nodoArbol;
        NodoArbol * segundo = listaFeromonas->primerNodo->siguiente->nodoArbol;
    
        reporte+= "\nRamas seleccionadas:\t " + to_string(primero->persona->persona->ID) + "\t" + to_string(segundo->persona->persona->ID) + "\n\n";
        reporteHormigas(fecha, reporte);

        if (primero->persona->persona->ID < segundo->persona->persona->ID)
            antMan_salvar(fecha, primero->persona, segundo->persona);
        else
            antMan_salvar(fecha, segundo->persona, primero->persona);
        
        limpiarFeromonas(arbol->raiz);
    }

    string hormiga(){
        NodoArbol * tmp = arbol->raiz;
        string reporte;
        while (tmp!=NULL){
            reporte+= "Cae en " + to_string(tmp->persona->persona->ID) + "\t";
            tmp->feromonas++;
            int randomBool = getRandomInt(0,2);
            if(randomBool==0){
                tmp = tmp->hijoDer;
                reporte+= "Derecha\t";
                
            }
            else{
                tmp = tmp->hijoIzq;
                reporte+= "Izquierda\t";
                
            }
        }
        reporte+= "Se cae\n";
        
        return reporte;
    }

    void limpiarFeromonas(NodoArbol* raiz){
        if(raiz!=NULL){
            raiz->feromonas = 0;
            limpiarFeromonas(raiz->hijoDer);
            limpiarFeromonas(raiz->hijoIzq);
        }
    }

    void insertarNodos(ListaNodoArbol * lista, NodoArbol* raiz){
        if(raiz!=NULL){
            lista->insertar(raiz);
            insertarNodos(lista, raiz->hijoIzq);
            insertarNodos(lista, raiz->hijoDer);
        }
    }
   
    void antMan_salvar(string fecha, NodoPersona * inicio, NodoPersona * final){
        while (inicio!=final){
            Persona * persona = inicio->persona;

            if (persona!=NULL && !persona->vivo){
                persona->vivo = true;
                persona->salvado = true;
                persona->personaje = "Ant Man";
                cout << "Ant Man ha salvado a " << persona->ID << endl;
                reporteAntMan(fecha, persona);

                NodoPersonaje * lol = listaPersonajes->primerNodo;
                while(lol!=NULL && lol->personaje->nombre != "Ant Man"){
                    lol = lol->siguiente;
                }
                lol->personaje->cant++;
                lol->personaje->asesinados->insertar(persona);
            }

            inicio = inicio->siguiente;
        }
    }

    void reporteThanos(string nombre, Persona * p, int anio, int nivel){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "aniquilado por Thanos por nacer en el ano " + to_string(anio) + " y estar en el nivel " + to_string(nivel) + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void reporteCorvusGlaive(string nombre, Persona * p){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "aniquilado por Corvus Glaive por " + to_string(p->cantPecados()) + " pecados" + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void reporteMidnight(string nombre, Persona * p){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "aniquilado por Midnight por " + to_string(p->cantBuenasAcciones()) + " buenas acciones" + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void reporteNebula(string nombre, Persona * p, int amigo){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "aniquilado por Nebula por ser parte de la cadena de amigos de ID " + to_string(amigo) + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void reporteEbonyMaw(string nombre, Persona * p, int familiar){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "aniquilado por Ebony Maw por ser parte de la familia de ID " + to_string(familiar) + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void reporteBlackDwarf(string nombre, Persona * p, string deporte, int cant){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "aniquilado por Black Dwarf por practicar " + deporte + " " + to_string(cant) + " veces a la semana." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void reporteHormigas(string nombre, string txt){
        ofstream archivo2;
        archivo2.open(nombre.c_str());
        archivo2 << txt ;
        archivo2.close();
    }

    void reporteAntMan(string nombre, Persona * p){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "Salvado por Ant-Man por estar entre las dos ramas con mas feromonas" + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }       

    void reporteThor(string nombre, Persona * p, int amigo){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "salvado por Thor por ser amigo de " + to_string(amigo) + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void aux_ReporteThor(string nombre, int p, int familiar){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd+= "Se van a salvar a los amigos de \t" + to_string(familiar) + "\t , familiar de \t" + to_string(p) + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void reporteIronMan(string nombre, Persona * p, int familiar){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "salvado por Iron Man por ser familiar de " + to_string(familiar) + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void aux_ReporteSpiderman(string nombre, Persona * p){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd+= "Spiderman brinca al nodo de \t" + to_string(p->ID)  + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void reporteSpiderman(string nombre, Persona * p, int inicio){
        string linea;
        string texto;
        ifstream archivo(nombre.c_str());
        while(getline(archivo,linea)){
            texto+=linea+"\n";
        }
        archivo.close();

        ofstream archivo2;
        archivo2.open(nombre.c_str());
        string xd = "";
        xd = xd + paraArchivo() + "\t";
        xd = xd + to_string(p->ID) + "\t" + p->nombre + " " + p->apellido + "\t" + p->ubicacion + "\t" + "[";
        for (int i = 0; i < 50; i++){
            if(p->amigos[i+1] != NULL && p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID) + ", ";
            }
            else if(p->amigos[i]!=NULL){
                xd = xd + to_string(p->amigos[i]->ID);
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        if(p->pareja!=NULL)
            xd = xd + to_string(p->pareja->ID) + "\t";
        xd = xd + "[";
        for (int i = 0; i < 4; i++){
            if(p->hijos[i+1] != NULL && p->hijos[i]!=NULL && i < 4){
                xd = xd + to_string(p->hijos[i]->ID) + ", ";
            }
            else if(p->hijos[i]!=NULL){
                xd = xd + to_string(p->hijos[i]->ID);
            }
        }
        xd = xd + "]"; 
        xd = xd + "\t";
        xd = xd + "[";
        for (int i = 0; i < 100; i++){
            if(p->experiencias[i+1] != "" && p->experiencias[i]!=""){
                xd = xd + p->experiencias[i] + ", ";
            }
            else if(p->experiencias[i]!=""){
                xd = xd + p->experiencias[i];
            }
        }
        xd = xd + "]";
        xd = xd + "\t";
        xd = xd + "Murio el " + fechaMuerte() + " ";
        xd = xd + "salvado por Spiderman por estar a la derecha de " + to_string(inicio) + "." + "\n";
        archivo2 << texto << xd;
        archivo2.close();
    }

    void consultaSalvacion(){
        ofstream archivo2;
        archivo2.open("ConsultaSalvacion.txt");
        string xd = "";

        NodoPersonaje * lol = listaPersonajes->primerNodo;
        while(lol->personaje->nombre != "Ant Man"){
            lol=lol->siguiente;
        }

        while(lol != NULL){
            xd += lol->personaje->nombre + "\t salvo a \t" + to_string(lol->personaje->cant) + " personas\n";
            xd += lol->personaje->asesinados->todasLasPersonas();
            lol=lol->siguiente;
        }
        archivo2 << xd;
        archivo2.close();
    
    }

    void consultaAniquilacion(){
        ofstream archivo2;
        archivo2.open("ConsultaAniquilacion.txt");
        string xd = "";

        NodoPersonaje * lol = listaPersonajes->primerNodo;
        while(lol->personaje->nombre != "Ant Man"){
            xd += lol->personaje->nombre + "\t mato a \t" + to_string(lol->personaje->cant) + " personas\n";
            xd += lol->personaje->asesinados->todasLasPersonas();
            lol=lol->siguiente;
        }
        archivo2 << xd;
        archivo2.close();
    }
};