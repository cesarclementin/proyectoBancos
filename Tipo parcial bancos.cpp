/*
Cuentas:
Deberán registrarse los datos de todas las cuentas de los clientes de un banco. Estos datos ingresan desordenados.
 De cada cuenta se conoce  el número de cuenta , monto límite diario para extracciones, saldo inicial de la cuenta y su clave para
 cajeros automáticos (4 dígitos).  Se ingresarán datos de las cuentas mientras se responda afirmativamente a la pregunta
  "¿Hay más cuentas para cargar (S/N)?"
  
  
Movimientos:
    
Luego se ingresarán los movimientos realizados en los cajeros automáticos en un día.  Estos datos vienen desordenados. Los datos son los siguientes:
-	Nro de cuenta (Fin ingreso de datos=0)  Validar que la cuenta exista.
-	Clave ingresada por el cliente. En el caso que la clave sea correcta deberá solicitarle al usuario:
o	Tipo de Movimiento (E: Extracción - D: Depósito  - C:Consulta de saldos) 
o	Monto (Sólo en el caso de una Extracción o Depósito)
Tener en cuenta que la clave ingresada por el usuario al realizar una operación, no podrá superar los 3 intentos erróneos. 
En este caso, se mostrará un mensaje indicando que no podrá realizarse ninguna operación en dicho día.
También deberá considerarse que cada cliente no puede realizar más de 3 extracciones por día y no podrá superar el límite 
diario establecido para su cuenta.

Informar:
1)	Al momento de realizar una operación: Un indicativo si pudo realizar la operación  y el saldo actual. En caso de no haber podido realizar
 la operación , indicar el motivo.
2)	Al finalizar el registro de todas las operaciones, por cada cuenta: Informar todos sus datos
3)	Al finalizar el registro de todas las operaciones, informar el promedio de todos los saldos actuales.
4)	Al finalizar el registro de todas las operaciones, la cantidad de cuentas con saldo acreedor, saldo deudor, y saldo nulo.
5)	Al finalizar el registro de todas las operaciones, la cantidad de cuentas con 3 extracciones realizadas.
Funciones
-	Función Promedio: Dado un vector con las cuentas y su longitud, devolver el promedio entre todos los saldos actuales.
-	Función Imprimir: Dado un vector con los datos de las cuentas y su longitud, mostrar por pantalla los datos de cada cuenta.
-	Función ValidarClave: Dado una clave, un número de cuenta, un vector con los datos de las cuentas y su longitud, devolver un indicador si la clave ingresada es correcta o no.
-	Función CantidadCuentas: Dado un vector con los datos de las cuentas y su longitud, devolver la cantidad de cuentas con saldo acreedor, cantidad de cuentas con saldo deudor, y cantidad de cuentas con saldo nulo.
-	Función ExtraccionesLimite: Dado una cuenta devolver un indicador si la cantidad de extracciones de dicha cuenta es 3.
*/

#include <conio.h>
#include <iostream>
#include <stdio.h>

struct Clientes
{
    int nroCuenta;
    double montoLimite;
    double saldoInicial;
    int clave;
    
    int intentosClave;
    int cantExtracciones;
};

// Cabeceras de funciones 
void IMPRIMIR(Clientes[],int);
double PROMEDIO(Clientes[],int);
void CANTIDADCUENTAS(Clientes vec[],int dim, int &acr , int & deud , int &nul );
bool EXTRACCIONESLIMITE(struct Clientes[]);
bool VALIDARCLAVE(Clientes vec[],int laclave, int cuenta, int dim);
//Fin cabeceras

int main(void)
{
   char pregunta,movimiento;
   int i,pw,nro,j,auxclave,h;
   double monto;
   int cantidad,acredor,deudor,nulo,acumulador;
   
 cantidad=10;
 int limite=1000;
 acredor=0;
 deudor=0;
 nulo=0;
 acumulador=0;
 
   
   Clientes cliente[cantidad];
   
   
   ////// *********************** NO DEBRE INICIALIZAR TODOS LOS CAMPOS, SOLO LOS QUE LO REIQUIERAN.
   ////// *********************** TAMPOOCO DEBE SETEAR TODOS LOS ELEMENTOS DEL VECTOR DIMENSIONADO, SOLO HASTA DÓNDE SE CARGAN DATOS DE CUENTAS.
   
   for(h=0;h<cantidad;h++)
   {
     cliente[h].nroCuenta=0;
     cliente[h].montoLimite=limite;
     cliente[h].saldoInicial=0.0;
     cliente[h].clave=0;
     cliente[h].intentosClave=0;
     cliente[h].cantExtracciones=0;                   
   } 
   
   
   i=0;
   //Primera entrada datos
   cout<<"Hay cuentas para cargar?(s = si): "<<endl;
   cin>>pregunta;
   
   while (pregunta=='s')
    {
           cout<<"Ingrese el numero de cuenta: "<<endl;
           cin>>cliente[i].nroCuenta;
           
           cout<<"Ingrese el monto limite: "<<endl;
           cin>>cliente[i].montoLimite;     
           cout<<"Ingrese el saldo inicial de cuenta: "<<endl;
           cin>>cliente[i].saldoInicial;    
           cout<<"Ingrese clave: (4 digitos) "<<endl;
           cin>>auxclave;
           
           while(auxclave<999|| auxclave>9999)
           { 
			cout<<"Error! Ingrese nuevamente (4 digitos)"<<endl;
			cin>>auxclave;
	       }
           cliente[i].clave=auxclave;
           i++;
        
        cout<<"Hay cuentas para cargar?(s = si): "<<endl;
        cin>>pregunta;
    }   
     //Fin primera entrada  
       
       
       
       ////// *********************** OJO PORQUE TODAS LAS RECORRIDAS SOBRE EL VECTOR SE HACEN LA TOTALIZAD DE ELEMENTOS DIMEMSIONADOS DEL VECTOR Y NO LA CANTIDAD DE ELEMENTOS REALES CARGADOS..
       
       
       //Segunda entrada datos
       
       cout<<"Ingrese numero de la cuenta (Fin datos=0): "<<endl;
       cin>> nro;
       
       while (nro!=0)
       { 
                    do
                    {
                           j=0;
                           while ( (j<cantidad) && (nro!=cliente[j].nroCuenta) )  
                           {
                            j++;
                           }
                        
                            
                            if (nro!=cliente[j].nroCuenta)  
                            {
                              cout<< "Numero de cuenta inexistente. Ingreselo nuevamente"<<endl;
                              cin>>nro;
                            }                      
                        
                    }
                     while ( (nro!=cliente[j].nroCuenta) );
            
                    ////// *********************** NO CONTROLA QUE AQUÍ SE PUEDA INGRESAR UN NRO DE CUENTA 0 .   
            
            
                  cout<<"Ingrese la clave nuevamente: "<<endl;
                  cin>>pw;
          
                    
                ////// *********************** PARA VALIDAR LA CLAVE DEBE USAR LA FUNCIÓN.
          
                  if (pw==cliente[j].clave)
                  {
                        
                        cout<<"Ingrese Tipo de Movimiento (E: Extraccion - D: Deposito  - C:Consulta de saldos)"<<endl;
                        cin>>movimiento;
                        while ( (movimiento!='E')&& (movimiento!='D')&& (movimiento!='C') )
                        {
                              cout<<"Error. Ingrese Tipo de Movimiento (E: Extraccion - D: Deposito  - C:Consulta de saldos)"<<endl;
                              cin>>movimiento;
                        }
                        
                        
                        if ( (movimiento=='E') || (movimiento=='D') )
                        {
                            cout<<"Ingrese el monto"<<endl;
                            cin>>monto;
                            
                            
                            ////// *********************** NO CONTROLA QUE EL MONTO PARA EXTRACCIÓN ESTÉ DENTRO DEL LÍMITRE DIARIO QUE AÚN LE QUEDA
                            if ( (monto<cliente[j].saldoInicial) && (movimiento=='E') )
                            {
                                cout<<"Ha realizado la extraccion correctamente! "<<endl;
                                cliente[j].saldoInicial=cliente[j].saldoInicial-monto;
                                cout<<"Su saldo actual es: "<<cliente[j].saldoInicial<<endl;
                                cliente[j].cantExtracciones++;
                                
                                
                                ////// *********************** DEBE ACTUALIZAR EL LÍMITE DIARIO QUE AÚN LE QUEDA.
                            }
                            else
                            {
                                 cout<<"Ha realizado el deposito correctamente! "<<endl;
                                cliente[j].saldoInicial=cliente[j].saldoInicial+monto;
                                  cout<<"Su saldo actual es: "<<cliente[j].saldoInicial<<endl;
                            }
                            
                          
                        }
                        
                        
                        ////// *********************** ESTO DEBERÍA INCREMENTARSE EN EL CASO QUE SE INGRESE CLAVE INCORRECTA.
                        
                        cliente[j].intentosClave++;
                        
                        
                        
                    }
                    
            
           
           cout<<"Ingrese numero de la cuenta (Fin datos= 0): "<<endl;
           cin>>nro;   
        }
       
       cout<<"**PUNTO 2 ** "<<endl;
       IMPRIMIR(cliente,i);
       
       cout<<"**PUNTO 3**"<<endl;
       cout<<""<<endl;
       cout<<"El promedio de los saldos actuales es de: "<<PROMEDIO(cliente,i)<<endl;
       cout<<""<<endl;
       
       cout<<"**PUNTO 4**"<<endl;
       CANTIDADCUENTAS(cliente,i,acredor,deudor,nulo);
       cout<<"Cantidad de clientes acredores: "<<acredor<<endl;
       cout<<"Cantidad de clientes deudores: "<<deudor<<endl;
       cout<<"Cantidad de clientes nulo: "<<nulo<<endl;
       
       cout<<"**PUNTO 5**"<<endl;
      
       for (h=0;h<i;h++)
       {
           if (EXTRACCIONESLIMITE(cliente[h])   )
           {
           acumulador++;
           }
           
        }
       cout<<"Cantidad de cuentas con 3 extracciones realizadas: "<<acumulador<<endl;
     
       
    getch();
    return(0);
    
}


void IMPRIMIR(Clientes vec[],int x)
{    int i; 
        for (i=0;i<x;i++)
        { 
            cout<<"Para la cuenta: "<<i+1<<endl;
            
            cout<<"Numero de cuenta: "<<vec[i].nroCuenta<<endl;
            cout<<"Monto limite: "<<vec[i].montoLimite<<endl;
            cout<<"Saldo: "<<vec[i].saldoInicial<<endl;
            cout<<"Clave: "<<vec[i].clave<<endl;
            cout<<"Intentos de clave: "<<vec[i].intentosClave<<endl;
            cout<<"Cantidad de extracciones realizadas: "<<vec[i].cantExtracciones<<endl;       
            cout<<""<<endl;
        }
}


//	Función Promedio: Dado un vector con las cuentas y su longitud, devolver el promedio entre todos los saldos actuales.

double PROMEDIO(Clientes vec[],int dim)
{
    double acum;
    
    ////// *********************** inicializar acum aquí. NO EN EL MAIN.
      for (int i=0;i<dim;i++)   
      {
        acum+=vec[i].saldoInicial;  
      }           
    return (acum/dim) ;  
}

//Función CantidadCuentas: Dado un vector con los datos de las cuentas y su longitud, devolver la cantidad de cuentas con saldo acreedor
//cantidad de cuentas con saldo deudor, y cantidad de cuentas con saldo nulo.
void CANTIDADCUENTAS(Clientes vec[],int dim, int &acr , int & deud , int &nul )
{
    ////// *********************** inicializar los CONTADORES aquí. NO EN EL MAIN.
    
    
    for (int i=0;i<dim;i++)
    {
        if(vec[i].saldoInicial<0)
        {
         deud++;         
        }
        else
         if (vec[i].saldoInicial>0)
         {
          acr++;                 
          }
          else 
          nul++; 
    }
}


//	Función ExtraccionesLimite: Dado una cuenta devolver un indicador si la cantidad de extracciones de dicha cuenta es 3.

bool EXTRACCIONESLIMITE(Clientes unaCuenta)
{
     
       ////// *********************** PIDE EVALUAR SI ES 3 NO SI ES >=.
       
       if (unaCuenta.cantExtracciones>=3)  
        {
         return (true);                                                                        
         }
          else
          return (false);
     
}


bool VALIDARCLAVE(Clientes vec[],int laclave, int cuenta, int dim)
{
	bool validar=false;
	
	
    ////// *********************** la búsqueda debe hacerse con un MIENTATRAS Y NO COMPARAR TODOS LOS ELEMENTOS.
    
    
    for(int h=0;h<dim;h++)
    {
		if(cuenta==vec[h].nroCuenta)
        {
			if(laclave==vec[h].clave)
            {
				validar=true;
			}
		}
	}
	return (validar);
}




