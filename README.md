Generar un programa para una red de cajeros automáticos.
Cuentas:
Deberán registrarse los datos de todas las cuentas de los clientes de un banco. Estos datos ingresan desordenados. De cada cuenta se conoce  el número de cuenta , monto límite diario para extracciones, saldo inicial de la cuenta y su clave para cajeros automáticos (4 dígitos).  Se ingresarán datos de las cuentas mientras se responda afirmativamente a la pregunta “¿Hay más cuentas para cargar (S/N)?”
Movimientos:
Luego se ingresarán los movimientos realizados en los cajeros automáticos en un día.  Estos datos vienen desordenados. Los datos son los siguientes:
-	Nro de cuenta (Fin ingreso de datos=0)  Validar que la cuenta exista.
-	Clave ingresada por el cliente. En el caso que la clave sea correcta deberá solicitarle al usuario:
o	Tipo de Movimiento (E: Extracción – D: Depósito  - C:Consulta de saldos) 
o	Monto (Sólo en el caso de una Extracción o Depósito)
Tener en cuenta que la clave ingresada por el usuario al realizar una operación, no podrá superar los 3 intentos erróneos. En este caso, se mostrará un mensaje indicando que no podrá realizarse ninguna operación en dicho día.
También deberá considerarse que cada cliente no puede realizar más de 3 extracciones por día y no podrá superar el límite diario establecido para su cuenta.

Informar:
1)	Al momento de realizar una operación: Un indicativo si pudo realizar la operación  y el saldo actual. En caso de no haber podido realizar la operación , indicar el motivo.
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

