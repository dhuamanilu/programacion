
import matplotlib.pyplot as plt

def main():
    print("Bienvenido a la calculadora de fuerza (MRUV)\n")
    ok=False 
    while(not ok):
        m=float(input("Ingrese la masa del movil(en Kilogramos):"))
        d=float(input("Ingrese la distancia recorrida (en metros):"))
        t=float(input("Ingrese el tiempo empleado (en segundos):"))
        vi=float(input("Ingrese la velocidad inicial (en metros/segundo):"))
        vf=float(input("Ingrese la velocidad final (en metros/segundo):"))
        
        if m<=0:
            print("La masa tiene que ser mayor que cero! Vuelva a intentarlo")
            continue
        elif d<=0:
            print("La distancia tiene que ser mayor que cero! Vuelva a intentarlo")
            continue
        elif t<=0:
            print("El tiempo tiene que ser mayor que cero! Vuelva a intentarlo")
            continue
        elif vi<0:
            print("La velocidad inicial tiene que ser mayor o igual a cero! Vuelva a intentarlo")
            continue
        else:
            ok=True
            #De acuerdo al analisis
            aceleracion=(vf-vi)/t
            fuerza=m*aceleracion
            print("El cuerpo tiene una aceleracion de: ",aceleracion,
            " m/s^2 y describe una fuerza de: ",fuerza," newtons.")
            
            # Crear datos para graficar la velocidad en función del tiempo
            tiempos = [0, t]  # Tiempo inicial y tiempo final
            velocidades = [vi, vf]  # Velocidad inicial y velocidad final
            
            # Crear datos para graficar la aceleración en función del tiempo
            aceleraciones = [aceleracion, aceleracion]
            
            # Crear datos para graficar la posición en función del tiempo
            posiciones = [vi * tiempo + 0.5 * aceleracion * tiempo**2 for tiempo in tiempos]
            
            # Graficar
            fig, axs = plt.subplots(3)
            
            # Gráfico de velocidad en función del tiempo
            axs[0].plot(tiempos, velocidades, marker='o', color='r')
            axs[0].set_title('Velocidad en función del Tiempo')
            axs[0].set_xlabel('Tiempo (s)')
            axs[0].set_ylabel('Velocidad (m/s)')
            axs[0].grid(True)
            
            # Gráfico de aceleración en función del tiempo
            axs[1].plot(tiempos, aceleraciones, marker='o', color='b')
            axs[1].set_title('Aceleración en función del Tiempo')
            axs[1].set_xlabel('Tiempo (s)')
            axs[1].set_ylabel('Aceleración (m/s^2)')
            axs[1].grid(True)
            
            # Gráfico de posición en función del tiempo
            axs[2].plot(tiempos, posiciones, marker='o', color='g')
            axs[2].set_title('Posición en función del Tiempo')
            axs[2].set_xlabel('Tiempo (s)')
            axs[2].set_ylabel('Posición (m)')
            axs[2].grid(True)
            
            plt.tight_layout()
            plt.show()
            break

main()