#include "citaMedica.h"
using namespace std;
int main() {
    CitaMedica cita1;

    cita1.programarCita(123, 456, 2023, 9, 20, 48, 0, "Fiebre y dolor de garganta");

    cout << "Cita medica programada para el paciente con ID "
    << cita1.getIdPaciente()
    << " y el medico con ID " << cita1.getIdMedico() << endl;

    cout << "Fecha: " << cita1.getFechaHora().tm_year + 1900
    << "-" << cita1.getFechaHora().tm_mon + 1 << "-"
    << cita1.getFechaHora().tm_mday << endl;

    cout << "Hora: " << cita1.getFechaHora().tm_hour
    << ":" << cita1.getFechaHora().tm_min << endl;
    cout << "Motivo: " << cita1.getMotivo() << endl;

    cita1.realizarCita("Gripe", "Descanso y medicamentos");
    cout << "Cita medica realizada.El diagnostico es: "
    << cita1.getDiagnostico() << endl;

    return 0;
}
