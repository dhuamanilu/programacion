
import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# Constantes gravitacionales y masas (simplificadas para el ejemplo)
G = 1.0  # Constante gravitacional
m1 = 1.0  # Masa del primer cuerpo
m2 = 1.0  # Masa del segundo cuerpo
m3 = 1.0  # Masa del tercer cuerpo

def deriv(t, state):
    x1, y1, vx1, vy1, x2, y2, vx2, vy2, x3, y3, vx3, vy3 = state
    r12 = np.sqrt((x2 - x1)**2 + (y2 - y1)**2)
    r13 = np.sqrt((x3 - x1)**2 + (y3 - y1)**2)
    r23 = np.sqrt((x3 - x2)**2 + (y3 - y2)**2)

    ax1 = G * m2 * (x2 - x1) / r12**3 + G * m3 * (x3 - x1) / r13**3
    ay1 = G * m2 * (y2 - y1) / r12**3 + G * m3 * (y3 - y1) / r13**3

    ax2 = G * m1 * (x1 - x2) / r12**3 + G * m3 * (x3 - x2) / r23**3
    ay2 = G * m1 * (y1 - y2) / r12**3 + G * m3 * (y3 - y2) / r23**3

    ax3 = G * m1 * (x1 - x3) / r13**3 + G * m2 * (x2 - x3) / r23**3
    ay3 = G * m1 * (y1 - y3) / r13**3 + G * m2 * (y2 - y3) / r23**3

    return [vx1, vy1, ax1, ay1, vx2, vy2, ax2, ay2, vx3, vy3, ax3, ay3]

# Condiciones iniciales (posiciones y velocidades)
state0 = [1.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0, -1.0, 0.0, 1.0, 1.0, 0.0]

# Intervalo de tiempo y resolución de la ecuación diferencial
t_span = (0, 50)
t_eval = np.linspace(*t_span, 1000)

sol = solve_ivp(deriv, t_span, state0, t_eval=t_eval)

# Gráficos de las trayectorias
plt.plot(sol.y[0], sol.y[1], label='Cuerpo 1')
plt.plot(sol.y[4], sol.y[5], label='Cuerpo 2')
plt.plot(sol.y[8], sol.y[9], label='Cuerpo 3')

plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Trayectorias del Problema de los Tres Cuerpos')
plt.grid()
plt.show()

# Sección de Poincaré
poincare_section = sol.y[:, ::10]  # Muestra de cada 10 puntos
plt.plot(poincare_section[0], poincare_section[1], 'o', label='Cuerpo 1')
plt.plot(poincare_section[4], poincare_section[5], 'o', label='Cuerpo 2')
plt.plot(poincare_section[8], poincare_section[9], 'o', label='Cuerpo 3')

plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Sección de Poincaré del Problema de los Tres Cuerpos')
plt.grid()
plt.show()