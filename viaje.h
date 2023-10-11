#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED
class Viaje{
 private:
    int nroViaje;
    int nroTarjeta;
    int medio;
    Fecha fechaViaje;
    float importe;
    bool estado;
  public:
    int getNroTarjeta(){return nroTarjeta;}
    int getMedioTransporte(){return medio;}
    int getDiaViaje(){return fechaViaje.getDia();}
    int getMesViaje(){return fechaViaje.getMes();}
    int getAnioViaje(){return fechaViaje.getAnio();}
    float getImporte(){return importe;}
    void setNroTarjeta(int n){ nroTarjeta=n;}
    void setMedioTransporte(int m){medio=m;}
    void setDiaViaje(int d){ fechaViaje.setDia(d);}
    void setMesViaje(int m){ fechaViaje.setMes(m);}
    void setAnioViaje(int a){ fechaViaje.setAnio(a);}
    void setImporte(float i){ importe=i;}
    void setEstado(bool e){estado=e;}
    void Cargar(int n=-1){
        if(n==-1){
        cout<<"Ingrese nro de Tarjeta "<<endl;
        cin>>nroTarjeta;
        }else{
        nroTarjeta=n;
        }
        cout<<"Ingrese nro de viaje "<<endl;
        cin>>nroViaje;
        cout<<"Ingrese medio[1- 2- 3-]"<<endl;
        cin>>medio;
        fechaViaje.Cargar();
        cout<<"Ingrese importe "<<endl;
        cin>>importe;
        estado=true;
    }
    void Mostrar(){
        cout<<"Nro de Tarjeta "<<nroTarjeta<<endl;
        cout<<"Nro de viaje "<<nroViaje<<endl;
        cout<<"Medio "<<medio<<endl;
        fechaViaje.Mostrar();
        cout<<"Importe "<<importe<<endl;
        cout<<endl;
    }
};


class ArchivoViaje{
private:
    char nombre[30];
public:
    ArchivoViaje(const char *n){
        strcpy(nombre,n);
    }
    bool cargarRegistro();
    bool modificarRegistro(Viaje via, int pos);
    int buscarNroTarjeta(int nroTarjeta);
    void listarRegistro();
    bool bajaLogica();
    Viaje leerRegistro(int pos){
        FILE *p;
        Viaje x;
        p=fopen(nombre,"rb");
        if(p==NULL) exit(1);
        fseek(p, pos* sizeof x,0);
        fread(&x, sizeof x, 1, p);
        fclose(p);
        return x;
      }
      int grabarRegistro(Viaje x){
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
        return tam/sizeof(Viaje);
      }
};

bool ArchivoViaje::cargarRegistro(){
    Viaje via;
    ArchivoViaje archiV("viajes.dat");
    int nroTarjeta;
    cout<<"Ingrese nro tarjeta "<<endl;
    cin>>nroTarjeta;
    int pos=archiV.buscarNroTarjeta(nroTarjeta);
    if(pos==-1){
        via.Cargar(nroTarjeta);
        bool viaje=archiV.grabarRegistro(via);
        return viaje;
    }
    return false;
}
int ArchivoViaje::buscarNroTarjeta(int n){
    ArchivoViaje archiV("viajes.dat");
    Viaje via;
    int cantV=archiV.contarRegistros();
    for(int i=0;i<cantV;i++){
        via=archiV.leerRegistro(i);
        if(via.getNroTarjeta()==n){
            return i;
        }
    }
    return -1;
}
void ArchivoViaje::listarRegistro(){
    ArchivoViaje archiV("viajes.dat");
    Viaje via;
    int cantV=archiV.contarRegistros();
    for(int i=0; i<cantV;i++){
        via=archiV.leerRegistro(i);
        via.Mostrar();
    }
}

bool ArchivoViaje::modificarRegistro(Viaje via,int pos){
    FILE *pVia;
    pVia=fopen("viajes.dat","rb+");///+ le agrega al modo lo que no tiene
    if(pVia==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(pVia,sizeof via*pos,0);
    bool viaje=fwrite(&via,sizeof(Viaje),1,pVia);
    fclose(pVia);
    return viaje;
}

bool ArchivoViaje::bajaLogica(){
    ArchivoViaje archiV("viajes.dat");
    Viaje via;
    int nroTarjeta;
    cout<<"Ingresa nro Tarjeta a eliminar"<<endl;
    cin>>nroTarjeta;
    int pos=archiV.buscarNroTarjeta(nroTarjeta);
    if(pos==-1){
        cout<<"No existe un registro con ese dni"<<endl;
        return false;
    }
    via=archiV.leerRegistro(pos);
    if(via.getNroTarjeta()==-1){
        cout<<"No existe el registro"<<endl;
    }
    via.setEstado(false);
    bool viaje=archiV.modificarRegistro(via,pos);
    cout<<viaje<<endl;
    return viaje;
}
void mostrarImportes(){
    ArchivoViaje archiV("viajes.dat");
    Viaje via;
    int cantVia=archiV.contarRegistros();
    for(int i=0;i<cantVia;i++){
        via=archiV.leerRegistro(i);
        cout<<"Nro Tarjeta: "<<via.getNroTarjeta()<<endl;
        cout<<"Importe: "<<via.getImporte()<<endl;
         cout<<endl;
    }
}

void subMenuViajes(){
    int opc;
    ArchivoViaje archiV("viajes.dat");
    bool band=true;
    while(band){
        system("cls");
        cout<<"MENU VIAJES"<<endl;
        cout<<"*************************"<<endl;
        cout<<"1. ALTA REGISTRO"<<endl;
        cout<<"2. LISTADO REGISTROS"<<endl;
        cout<<"3. BAJA LOGICA REGISTRO"<<endl;
        cout<<"4. MODIFICAR"<<endl;
        cout<<"5. MOSTRAR IMPORTES"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"************************"<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(archiV.cargarRegistro()) cout<<"REGISTRO AGREGADO";
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
            case 2: archiV.listarRegistro();
                break;
            case 3: if(archiV.bajaLogica()==true) cout<<"REGISTRO DADO DE BAJA"<<endl;
                    else cout<<"NO SE PUDO DAR DE BAJA EL REGISTRO"<<endl;
                break;
            /*case 4:  archiT.modificarRegistro();
                break;*/
            case 5:  mostrarImportes();
                break;
        }
        band=false;
    }

}

#endif // VIAJE_H_INCLUDED
