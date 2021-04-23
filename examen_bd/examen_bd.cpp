#include <mysql.h>
#include <iostream>

using namespace std;

int q_estado;

int main() {

    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "4321crack", "examen_productos", 3306, NULL, 0);
    if (conectar) {
        cout << "conexion exitosa\n" << endl;
        string marca;
        cout << "ingrese marca: ";
        cin >> marca;
        string insert = "INSERT INTO marcas(marca) VALUES('" + marca + "');";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso exitoso" << endl;
        }
        else {
            cout << "error al ingresar" << endl;
        }

        system("pause");

        system("cls");
        string consulta = "SELECT* FROM marcas;";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << ": " << fila[1] << endl;
            }
            cout << "lectura exitosa" << endl;
        }
        else {
            cout << "error al leer" << endl;
        }

        system("pause");
        system("cls");

        string marca_mod, modificado;
        cout << "ingrese marca que desea modificar: ";
        cin >> marca_mod;
        cout << "ingrese marca modificada: ";
        cin >> modificado;

        string insertm = "UPDATE marcas SET marca = ('" + modificado + "') WHERE marca = ('" + marca_mod + "');";
        const char* m = insertm.c_str();
        q_estado = mysql_query(conectar, m);
        if (!q_estado) {
            cout << "Ingreso exitoso" << endl;
        }
        else {
            cout << "error al ingresar" << endl;
        }

        system("pause");
        system("cls");

        string consulta2 = "SELECT* FROM marcas;";
        const char* c2 = consulta2.c_str();
        q_estado = mysql_query(conectar, c2);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << ": " << fila[1] << endl;
            }
            cout << "lectura exitosa" << endl;
        }
        else {
            cout << "error al leer" << endl;
        }

        system("pause");
        system("cls");

        string marcad;
        cout << "ingrese marca que desea borrar: ";
        cin >> marcad;
        string insertd = "DELETE FROM marcas WHERE marca=('" + marcad + "');";
        const char* d = insertd.c_str();
        q_estado = mysql_query(conectar, d);
        if (!q_estado) {
            cout << "Ingreso exitoso" << endl;
        }
        else {
            cout << "error al ingresar" << endl;
        }

        system("pause");
        system("cls");

        string consulta3 = "SELECT* FROM marcas;";
        const char* c3 = consulta3.c_str();
        q_estado = mysql_query(conectar, c3);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << ": " << fila[1] << endl;
            }
            cout << "lectura exitosa" << endl;
        }
        else {
            cout << "error al leer" << endl;
        }

    }


    else {
        cout << "error en la conexion" << endl;
    }
}
