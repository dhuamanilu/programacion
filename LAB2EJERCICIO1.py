def imprimir_valores(aceleracion,tension):
    print("La aceleracion es: ",aceleracion," m/s^2 y la tension es: ",tension," newtons.")

def main():
    print("Bienvenido a la calculadora de magnitudes (Maquina de Atwood)\n")
    ok=False 
    while(not ok):
        m1=float(input("Ingrese la masa 1(en Kilogramos):"))
        m2=float(input("Ingrese la masa 2(en Kilogramos):"))
        g=9.81
        if m1<=0:
            print("La masa 1 tiene que ser mayor que cero! Vuelva a intentarlo")
            continue
        elif m2<=0:
            print("La masa 2 tiene que ser mayor que cero! Vuelva a intentarlo")
            continue
        else:
            ok=True
            #Caso 1 m1=m2
            if m1==m2:
                aceleracion=0
                tension=m1*g
                imprimir_valores(aceleracion,tension)
            #Caso 2 m1<m2
            elif m1<m2:
                aceleracion=g*(m2-m1)/(m1+m2)
                tension=m1*(aceleracion+g)
                imprimir_valores(aceleracion,tension)
            #Caso 3 m2<m1
            else:
                aceleracion=g*(m1-m2)/(m1+m2)
                tension=m2*(aceleracion+g)
                imprimir_valores(aceleracion,tension)
        
            break

main()