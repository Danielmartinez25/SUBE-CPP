#ifndef PUNTOS_H_INCLUDED
#define PUNTOS_H_INCLUDED

void punto1(){
    ArchivoViaje archi("viajes.dat");
    Viaje via;
    int cantVia=archi.contarRegistros();
    int vViaje[3]={0};
    int tarjeta;
    cout<<"Ingresa numero de tarjeta "<<endl;
    cin>>tarjeta;
    for(int i=0;i<cantVia;i++){
        via=archi.leerRegistro(i);
        if(via.getNroTarjeta()==tarjeta && via.getAnioViaje()==2022){
                vViaje[via.getMedioTransporte()-1]++;
        }
    }
    cout<<"CANTIDAD DE VIAJES EN COLECTIVO "<<vViaje[0]<<endl;
    cout<<"CANTIDAD DE VIAJES EN SUBTE "<<vViaje[1]<<endl;
    cout<<"CANTIDAD DE VIAJES EN TREN "<<vViaje[2]<<endl;
}
void punto2(){
    ArchivoViaje archi("viajes.dat");
    Viaje via,barato;
    int menorImporteViaje;
    int cantVia=archi.contarRegistros();
    for(int i=0;i<cantVia;i++){
        via=archi.leerRegistro(i);
        if(i==0){
            menorImporteViaje=via.getImporte();
            barato=via;
        }else{
        if(via.getImporte()< menorImporteViaje){
        menorImporteViaje=via.getImporte();
        barato=via;
        }
        }
    }
    cout<<"El viaje de menor importe"<<endl;
    barato.Mostrar();
}


void buscarMaximo(int *v,int tam){
    int mayMes,pos;
    for(int i=0;i<tam;i++){

        if(i==0){
            mayMes=v[i];
            pos=i;
        }else{
        if(v[i]>mayMes){
            mayMes=v[i];
            pos=i;
        }
        }
    }
    cout<<"El mes de mayor recaudacion es "<<pos+1<<" con una recaudacion de "<<mayMes<<endl;
}

void punto3(){
    ArchivoViaje archi("viajes.dat");
    Viaje via;
    int vCantV[12]={0};
    int cantViajes=archi.contarRegistros();
    for(int i=0;i<cantViajes;i++){
        via=archi.leerRegistro(i);
        if(via.getMedioTransporte()==2 && via.getAnioViaje()<2023){
           vCantV[via.getMesViaje()-1]+=via.getImporte();
        }
    }
    buscarMaximo(vCantV,12);
}

bool grabarRegistroAnioActual(Viaje aux){
    FILE *p;
    p=fopen("viajes2023.dat", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&aux, sizeof aux, 1, p);
    fclose(p);
    return escribio;
}



void punto4(){
    ArchivoViaje archi("viajes.dat");
    Viaje via;
    int cantViajes=archi.contarRegistros();
    for(int i=0;i<cantViajes;i++){
        via=archi.leerRegistro(i);
        if(via.getAnioViaje()==2023){
             if(grabarRegistroAnioActual(via)==false){
                cout<<"No se pudo grabar el registro"<<endl;
                return;
             }
        }
    }
}

void MostrarViajes2023(){
    ArchivoViaje archiV("viajes2023.dat");
    Viaje via;
    int cantVi=archiV.contarRegistros();
    for(int i=0;i<cantVi;i++){
        via=archiV.leerRegistro(i);
        via.Mostrar();
    }
}

void punto5(){
    ArchivoViaje archi("viajes.dat");
    Viaje via;
    int numTar;
    int cV[4]={0};
    cout<<"Ingrese numero de tarjeta"<<endl;
    cin>>numTar;
    int cantViajes=archi.contarRegistros();
    for(int i=0;i<cantViajes;i++){
        via=archi.leerRegistro(i);
        if(via.getNroTarjeta()==numTar && via.getAnioViaje()== 2020){
        cV[0]+=1;
        }
        if(via.getNroTarjeta()==numTar && via.getAnioViaje()== 2021){
        cV[1]+=1;
        }
        if(via.getNroTarjeta()==numTar && via.getAnioViaje()== 2022){
        cV[2]+=1;
        }
        if(via.getNroTarjeta()==numTar && via.getAnioViaje()== 2023){
        cV[3]+=1;
        }
    }
    for(int j=0;j<4;j++){
        cout<<"En el anioo 202"<<j<<" hizo: "<<cV[j]<<endl;
    }
}

void punto6(){
    ArchivoViaje archi("viajes.dat");
    Viaje via,may;
    int mayViaje;
    int cantViajes=archi.contarRegistros();
    for(int i=0;i<cantViajes;i++){
        via=archi.leerRegistro(i);
        if(i==0){
            mayViaje=via.getImporte();
            may=via;
        }
        else{
            if(via.getImporte()>mayViaje){
                mayViaje=via.getImporte();
                may=via;
            }
        }
    }
    cout<<"El viaje con mayor importe es"<<endl;
    may.Mostrar();
}

int ultNumero(int n) {
return n % 10;
}
void buscarMaximoMatriz(int v[3][12],int f,int c){
    int may,aRe,mRe;
    for(int i=0;i<f;i++){
        for(int j=0;j<c;c++){
            if(i==0){
                may=v[i][j];
            }
            else{
                if(v[i][j]>may){
                    may=v[i][j];
                     aRe=i;
                     mRe=j;
                }
            }
        }
    }
    cout<<"En el anio 202"<<aRe+1<<" y en el mes "<<mRe+1<<endl;
}

void punto7(){
    ArchivoViaje archi("viajes.dat");
    Viaje via;
    int m[3][12]={0};
    int cantViajes=archi.contarRegistros();
    for(int i=0;i<cantViajes;i++){
        via=archi.leerRegistro(i);
        if(via.getMedioTransporte()==3 && via.getAnioViaje()<2023){
            m[ultNumero(via.getAnioViaje()-1)][via.getMesViaje()-1]+=via.getImporte();
        }
    }
    buscarMaximoMatriz(m,3,12);
}

void punto8(){
ArchivoViaje archiV("viajes.dat");
    Viaje via;
    ArchivoTarjeta archiT("tarjetas.dat");
    Tarjeta tar;
    int acu;
    int cantViajes=archiV.contarRegistros();
    int cantTarjetas=archiT.contarRegistros();
    for(int i=0;i<cantTarjetas;i++){
    tar=archiT.leerRegistro(i);
    acu=0;
    for(int j=0;j<cantViajes;j++){
    via=archiV.leerRegistro(j);
    if(via.getMedioTransporte() == 1 && via.getAnioViaje()==2022 && via.getNroTarjeta()==tar.getNroTarjeta()){
        acu=via.getImporte()+acu;
    }
    }
    cout<<"EL TOTAL GASTADO POR LA TARJETA "<<tar.getNroTarjeta()<<" es: "<<acu<<endl;
    }
}
void punto9(){
    ArchivoViaje archiV("viajes.dat");
    Viaje via;
    ArchivoTarjeta archiT("tarjetas.dat");
    Tarjeta tar,cli;
    int menIm;
    int cantViajes=archiV.contarRegistros();
    int cantTarjetas=archiT.contarRegistros();
    for(int i=0;i<cantTarjetas;i++){
        tar=archiT.leerRegistro(i);
    for(int j=0;j<cantViajes;j++){
    via=archiV.leerRegistro(j);
        if(j==0){
           menIm=via.getImporte();
           cli=tar;
        }
        else{
            if(via.getImporte()<menIm && via.getNroTarjeta()== tar.getNroTarjeta()){
                    menIm=via.getImporte();
                    cli=tar;
            }
        }
    }
    }
    cout<<"NUMERO TARJETA CLIENTE: "<<cli.getNroTarjeta()<<endl;
    cout<<"DNI: "<<cli.getDNI()<<endl;
}
void punto10(){
    ArchivoViaje archiV("viajes.dat");
    Viaje via;
    ArchivoTarjeta archiT("tarjetas.dat");
    Tarjeta tar;
    int acu;
    int cantViajes=archiV.contarRegistros();
    int cantTarjetas=archiT.contarRegistros();
    for(int i=0;i<cantTarjetas;i++){
    tar=archiT.leerRegistro(i);
    acu=0;
    for(int j=0;j<cantViajes;j++){
    via=archiV.leerRegistro(j);
    if(via.getAnioViaje()==2023 && tar.getNroTarjeta()==via.getNroTarjeta()){
        acu+=via.getImporte();
    }
    }
    cout<<"EL TOTAL GASTADO POR LA TARJETA :"<<tar.getNroTarjeta()<<" es: "<<acu<<endl;
    }
}
class ViajesColectivoAnioPasado{
private:
    int nroTarjeta;
    int dni;
    int cantViajes;
public:
    int getNroTarjeta(){return nroTarjeta;}
    int getDNI(){return dni;}
    int getCantViajes(){return cantViajes;}
    void setNroTarjeta(int n){nroTarjeta=n;}
    void setDNI(int d){dni=d;}
    void setCantViajes(int c){cantViajes=c;}
};

bool grabarRegistroViajesCole(ViajesColectivoAnioPasado aux){
    FILE *p;
    p=fopen("viajescole.dat", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&aux, sizeof aux, 1, p);
    fclose(p);
    return escribio;
}

void punto11(){
    ArchivoTarjeta archiT("tarjetas.dat");
    Tarjeta tar,cli;
    ArchivoViaje archiV("tarjetas.dat");
    Viaje via;
    ViajesColectivoAnioPasado viajesCole;
    int cantViajesCole;
    int cantViajes=archiV.contarRegistros();
    int cantTarjetas=archiT.contarRegistros();
    for(int i=0;i<cantTarjetas;i++){
    tar=archiT.leerRegistro(i);
    for(int j=0;j<cantViajes;j++){
    via=archiV.leerRegistro(j);
    cantViajesCole=0;
    if(via.getMedioTransporte() == 1 && via.getAnioViaje()==2022 && via.getNroTarjeta()==tar.getNroTarjeta()){
        cantViajesCole+=via.getMedioTransporte();
        cli=tar;
    }
    }
    viajesCole.setNroTarjeta(cli.getNroTarjeta());
    viajesCole.setDNI(cli.getDNI());
    viajesCole.setCantViajes(cantViajesCole);
    if(grabarRegistroViajesCole(viajesCole)==false){
        cout<<"El registro no se pudo grabar"<<endl;
        return;
    }
    }
}


void subMenuOpciones(){
    int opc;
    bool band=true;
    while(band){
        system("cls");
        cout<<"MENU PUNTOS"<<endl;
        cout<<"********"<<endl;
        cout<<"PUNTO 1"<<endl;
        cout<<"PUNTO 2"<<endl;
        cout<<"PUNTO 3"<<endl;
        cout<<"PUNTO 4"<<endl;
        cout<<"PUNTO 5"<<endl;
        cout<<"PUNTO 6"<<endl;
        cout<<"PUNTO 7"<<endl;
        cout<<"PUNTO 8"<<endl;
        cout<<"PUNTO 9"<<endl;
        cout<<"PUNTO 10"<<endl;
        cout<<"PUNTO 11"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"**********"<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: punto1();
                break;
            case 2: punto2();
                break;
            case 3: punto3();
                break;
            case 4: MostrarViajes2023();
                /*punto4();*/
                break;
            case 5: punto5();
                break;
            case 6: punto6();
                break;
            case 7: punto7();
                break;
            case 8: punto8();
                break;
            case 9: punto9();
                break;
            case 10: punto10();
                break;
            case 11: punto11();
                break;

        }
        band=false;
    }
}


#endif // PUNTOS_H_INCLUDED
