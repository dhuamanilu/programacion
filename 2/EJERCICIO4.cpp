#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct CitaMedica {
    int idPaciente;
    int idMedico;
    struct tm fechaHora; // Utilizamos la estructura tm para fecha y hora
    string motivo;
    string estado;
    string diagnostico;
    string tratamiento;

    // M�todo para programar una cita m�dica
    void programarCita(int idPac, int idMed, int year, int month, int day, int hour, int minute, string motivo) {
        idPaciente = idPac;
        idMedico = idMed;
        // Restamos 1900 al a�o para ajustarlo al formato de tm
        fechaHora.tm_year = year - 1900;
        // Restamos 1 al mes ya que en tm enero es 0
        fechaHora.tm_mon = month - 1;
        fechaHora.tm_mday = day;
        fechaHora.tm_hour = hour;
        fechaHora.tm_min = minute;
        fechaHora.tm_sec = 0;

        this->motivo = motivo;
        estado = "programada";
    }

    // M�todo para cancelar una cita m�dica
    void cancelarCita() {
        estado = "cancelada";
    }

    // M�todo para realizar una cita m�dica y registrar diagn�stico y tratamiento
    void realizarCita(string diag, string trat) {
        estado = "realizada";
        diagnostico = diag;
        tratamiento = trat;
    }
};

int main() {
    CitaMedica cita1;

    cita1.programarCita(123, 456, 2023, 9, 20, 10, 48, "Fiebre y dolor de garganta");

    cout << "Cita medica programada para el paciente con ID " << cita1.idPaciente << " y el medico con ID " << cita1.idMedico << endl;
    cout << "Fecha: " << cita1.fechaHora.tm_year + 1900 << "-" << cita1.fechaHora.tm_mon + 1 << "-" << cita1.fechaHora.tm_mday << endl;
    cout << "Hora: " << cita1.fechaHora.tm_hour << ":" << cita1.fechaHora.tm_min << endl;
    cout << "Motivo: " << cita1.motivo << endl;

    cita1.realizarCita("Gripe", "Descanso y medicamentos");
    cout << "Cita medica realizada. El diagnostico es: " << cita1.diagnostico << endl;

    return 0;
}
