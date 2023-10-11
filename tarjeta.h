#ifndef TARJETA_H_INCLUDED
#define TARJETA_H_INCLUDED
#include <cstring>

class Tarjeta{
  private:
    int nroTarjeta;
    Fecha fechaAlta;
    int dni;
    float saldo;
    bool estado;
  public:
    int getNroTarjeta(){return nroTarjeta;}
    int getDiaAlta(){return fechaAlta.getDia();}
    int getMesAlta(){return fechaAlta.getMes();}
    int getAnioAlta(){return fechaAlta.getAnio();}
    int getDNI(){return dni;}
    float getSaldo(){return saldo;}
    void setNroTarjeta(int n ) {  nroTarjeta=n; }
    void setDiaAlta(int d ) {  fechaAlta.setDia(d); }
    void setMesAlta(int m) {  fechaAlta.setMes(m); }
    void setAnioAlta(int a) {  fechaAlta.setAnio(a); }
    void setDNI(int d) {  dni=d; }
    void setSaldo(float s) {  saldo=s; }
    void setEstado(bool e){estado=e;}
    void Cargar(int d = -1)
{
    if (d == -1)
    {
        cout << "Ingrese DNI: " << endl;
        cin >> dni;
    }
    else
    {
        dni = d;
    }
    cout << "Ingrese nro Tarjeta: " << endl;
    cin >> nroTarjeta;
    fechaAlta.Cargar();
    cout << "Ingrese saldo: " << endl;
    cin >> saldo;
    estado = true;
}
void Mostrar()
{
    cout << "Nro de DNI: " << dni << endl;
    cout << "Nro de Tarjeta: " << nroTarjeta << endl;
    fechaAlta.Mostrar();
    cout << "Saldo: " << saldo << endl;
    cout << endl;
}

};


class ArchivoTarjeta{
private:
    char nombre[30];
public:
    ArchivoTarjeta(const char *n){
        strcpy(nombre,n);
    }
    bool cargarRegistro();
    bool modificarRegistro(Tarjeta tar, int pos);
    int buscarDNI(int dni);
    void listarRegistro();
    void modificarNroTarjeta(int n);
    bool bajaLogica();
    Tarjeta leerRegistro(int pos){
        FILE *p;
        Tarjeta x;
        p=fopen(nombre,"rb");
        if(p==NULL) exit(1);
        fseek(p, pos* sizeof x,0);
        fread(&x, sizeof x, 1, p);
        fclose(p);
        return x;
      }
      int grabarRegistro(Tarjeta x){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int escribio=fwrite(&x, sizeof x, 1, p);
        fclose(p);
        return escribio;
      }
      int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Tarjeta);
      }
};


bool ArchivoTarjeta::cargarRegistro()
{
    Tarjeta tar;
    ArchivoTarjeta archiT("tarjetas.dat");
    int dni;
    cout << "Ingrese nro de DNI" << endl;
    cin >> dni;
    int pos = archiT.buscarDNI(dni);
    if (pos == -1)
    {
        tar.Cargar(dni);
        bool tarjeta = archiT.grabarRegistro(tar);
        return tarjeta;
    }
    return false;
}
int ArchivoTarjeta::buscarDNI(int d)
{
    ArchivoTarjeta archiT("tarjetas.dat");
    Tarjeta tar;
    int cantT = archiT.contarRegistros();
    for (int i = 0; i < cantT; i++)
    {
        tar = archiT.leerRegistro(i);
        if (tar.getNroTarjeta() == d)
        {
            return i;
        }
    }
    return -1;
}
void ArchivoTarjeta::listarRegistro()
{
    ArchivoTarjeta archiT("tarjetas.dat");
    Tarjeta tar;
    int cantV = archiT.contarRegistros();
    for (int i = 0; i < cantV; i++)
    {
        tar = archiT.leerRegistro(i);
        tar.Mostrar();
    }
}


bool ArchivoTarjeta::modificarRegistro(Tarjeta tar, int pos)
{
    FILE *ptar;
    ptar = fopen("tarjetas.dat", "rb+"); ///+ le agrega al modo lo que no tiene
    if (ptar == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    fseek(ptar, sizeof tar * pos, 0);
    bool tarjeta = fwrite(&tar, sizeof(Tarjeta), 1, ptar);
    fclose(ptar);
    return tarjeta;
}

int buscarPosicion(int n){
    ArchivoTarjeta archiT("tarjetas.dat");
    Tarjeta tar;
    int cantT=archiT.contarRegistros();
    for(int i=0;i<cantT;i++){
        tar=archiT.leerRegistro(i);
        if(tar.getNroTarjeta()==n){
            return i;
        }
    }
    return -1;
}

bool ArchivoTarjeta::bajaLogica()
{
    ArchivoTarjeta archiT("Tarjetas.dat");
    Tarjeta tar;
    int dni;
    cout << "Ingresa nro de DNI a eliminar" << endl;
    cin >> dni;
    int pos = archiT.buscarDNI(dni);
    if (pos == -1)
    {
        cout << "No existe un registro con ese dni" << endl;
        return false;
    }
    tar = archiT.leerRegistro(pos);
    if (tar.getNroTarjeta() == -1)
    {
        cout << "No existe el registro" << endl;
    }
    tar.setEstado(false);
    bool tarjeta = archiT.modificarRegistro(tar, pos);
    return tarjeta;
}

void subMenuTarjetas(){
    int opc;
    ArchivoTarjeta archiT("tarjetas.dat");
    Tarjeta tar;
    bool band=true;
    while(band){
        system("cls");
        cout<<"MENU TARJETAS"<<endl;
        cout<<"***********************"<<endl;
        cout<<"1. ALTA REGISTRO"<<endl;
        cout<<"2. LISTADO REGISTROS"<<endl;
        cout<<"3. BAJA LOGICA REGISTRO"<<endl;
        cout<<"4. MODIFICAR"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"***********************"<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(archiT.cargarRegistro()) cout<<"REGISTRO AGREGADO";
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
            case 2: archiT.listarRegistro();
                break;
            case 3: if(archiT.bajaLogica()==true) cout<<"REGISTRO DADO DE BAJA"<<endl;
                    else cout<<"NO SE PUDO DAR DE BAJA EL REGISTRO"<<endl;
                break;

            case 4:
            int pos;
            cout<<"Nro tarjeta a modificar "<<endl;
            cin>>pos;
            archiT.modificarRegistro(tar,pos);
                break;
        }
        band=false;
    }

}

#endif // FECHA_H_INCLUDED

