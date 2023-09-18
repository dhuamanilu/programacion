#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class CitaMedica {
private:
    int idPaciente;
    int idMedico;
    tm fechaHora;
    string motivo;
    string estado;
    string diagnostico;
    string tratamiento;

public:
    // Constructor
    CitaMedica() {
        estado = "programada";
    }

    // Setters
    void setIdPaciente(int idPac) {
        idPaciente = idPac;
    }

    void setIdMedico(int idMed) {
        idMedico = idMed;
    }

    void setFechaHora(int year, int month, int day, int hour, int minute) {
        fechaHora.tm_year = year - 1900;
        fechaHora.tm_mon = month - 1;
        fechaHora.tm_mday = day;
        fechaHora.tm_hour = hour;
        fechaHora.tm_min = minute;
        fechaHora.tm_sec = 0;
        fechaHora.tm_isdst = -1;
    }

    void setMotivo(string motivo) {
        this->motivo = motivo;
    }

    void setDiagnostico(string diag) {
        diagnostico = diag;
    }

    void setTratamiento(string trat) {
        tratamiento = trat;
    }

    int getIdPaciente(){
        return idPaciente;
    }

    int getIdMedico(){
        return idMedico;
    }

    tm getFechaHora(){
        return fechaHora;
    }

    string getMotivo(){
        return motivo;
    }

    string getEstado(){
        return estado;
    }

    string getDiagnostico(){
        return diagnostico;
    }

    string getTratamiento(){
        return tratamiento;
    }

    // Metodo para programar una cita medica
    void programarCita(int idPac, int idMed, int year, int month, int day, int hour, int minute, string motivo) {
        setIdPaciente(idPac);
        setIdMedico(idMed);
        setFechaHora(year, month, day, hour, minute);
        setMotivo(motivo);
        estado = "programada";
    }

    // Metodo para cancelar una cita medica
    void cancelarCita() {
        estado = "cancelada";
    }

    // Metodo para realizar una cita medica y registrar diagnostico y tratamiento
    void realizarCita(string diag, string trat) {
        estado = "realizada";
        setDiagnostico(diag);
        setTratamiento(trat);
    }
};


