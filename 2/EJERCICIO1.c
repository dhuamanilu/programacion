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

    // Método para programar una cita médica
    void programarCita(int idPac, int idMed, int year, int month, int day, int hour, int minute, string motivo) {
        idPaciente = idPac;
        idMedico = idMed;

        fechaHora.tm_year = year - 1900; // Restamos 1900 al año para ajustarlo al formato de tm
        fechaHora.tm_mon = month - 1;    // Restamos 1 al mes ya que en tm enero es 0
        fechaHora.tm_mday = day;
        fechaHora.tm_hour = hour;
        fechaHora.tm_min = minute;
        fechaHora.tm_sec = 0;            // Inicializamos los segundos en 0
        fechaHora.tm_isdst = -1;         // Indicamos que no hay información sobre horario de verano

        this->motivo = motivo;
        estado = "programada";
    }

    // Método para cancelar una cita médica
    void cancelarCita() {
        estado = "cancelada";
    }

    // Método para realizar una cita médica y registrar diagnóstico y tratamiento
    void realizarCita(string diag, string trat) {
        estado = "realizada";
        diagnostico = diag;
        tratamiento = trat;
    }

    // Otros métodos para obtener información de la cita médica
};

int main() {
    CitaMedica cita1;

    cita1.programarCita(1, 101, 2023, 9, 20, 10, 0, "Dolor en el pecho");

    cout << "Cita médica programada para el paciente con ID " << cita1.idPaciente << " y el médico con ID " << cita1.idMedico << endl;
    cout << "Fecha: " << cita1.fechaHora.tm_year + 1900 << "-" << cita1.fechaHora.tm_mon + 1 << "-" << cita1.fechaHora.tm_mday << endl;
    cout << "Hora: " << cita1.fechaHora.tm_hour << ":" << cita1.fechaHora.tm_min << endl;
    cout << "Motivo: " << cita1.motivo << endl;

    cita1.realizarCita("Infarto leve", "Descanso y medicamentos");
    cout << "Cita médica realizada. Diagnóstico: " << cita1.diagnostico << endl;

    return 0;
}
