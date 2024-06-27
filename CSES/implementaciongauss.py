import numpy as np
import scipy.special

def legendre_polynomial(n, x):
    """
    Calcula el valor del polinomio de Legendre de grado n en x.
    """
    return scipy.special.eval_legendre(n, x)

def legendre_polynomial_derivative(n, x):
    """
    Calcula el valor de la derivada del polinomio de Legendre de grado n en x.
    """
    Pn = scipy.special.eval_legendre(n, x)
    Pn_1 = scipy.special.eval_legendre(n-1, x)
    return n * (x * Pn - Pn_1) / (x**2 - 1)

def gauss_legendre_nodes_weights(n):
    """
    Calcula los nodos y los pesos para la cuadratura de Gauss-Legendre de orden n.
    """
    nodes = np.zeros(n)
    weights = np.zeros(n)
    
    # Los nodos son las raíces del polinomio de Legendre de grado n
    for i in range(1, n+1):
        # Primera aproximación para la i-ésima raíz
        x = np.cos(np.pi * (i - 0.25) / (n + 0.5))
        
        # Newton-Raphson para encontrar la raíz con más precisión
        for _ in range(10):
            Pn = legendre_polynomial(n, x)
            Pn_deriv = legendre_polynomial_derivative(n, x)
            x -= Pn / Pn_deriv
        
        nodes[i-1] = x
        weights[i-1] = 2 / ((1 - x**2) * legendre_polynomial_derivative(n, x)**2)
    
    return nodes, weights

def gauss_quadrature(f, a, b, n):
    """
    Aproxima la integral de f en el intervalo [a, b] usando la cuadratura de Gauss-Legendre de orden n.
    """
    # Transformar los nodos y pesos al intervalo [a, b]
    nodes, weights = gauss_legendre_nodes_weights(n)
    transformed_nodes = 0.5 * (b - a) * nodes + 0.5 * (b + a)
    transformed_weights = 0.5 * (b - a) * weights
    
    # Calcular la suma ponderada
    integral = np.sum(transformed_weights * f(transformed_nodes))
    
    return integral

# Ejemplo de uso
def f(x):
    return np.sin(x)

a = 0
b = np.pi
n = 5

result = gauss_quadrature(f, a, b, n)
print(f"La integral aproximada es: {result}")
