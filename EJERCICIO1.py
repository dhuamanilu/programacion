import math 
def mru_calcula_x():
    ok=False 
    while(not ok):
        velocidad=float(input("Ingrese velocidad (en mtr/seg):"))
        deltadet=float(input("Ingrese delta de t(en seg):"))
        if deltadet>0:
            ok=True
            deltadex=velocidad*deltadet
            print("El delta de x es: ",deltadex," metros.")
            break
        else:
            print("El delta de t tiene que ser mayor que cero! Vuelva a intentarlo.")

def mru_calcula_v():
    ok=False 
    while(not ok):
        deltadex=float(input("Ingrese delta de x(en mtr):"))
        deltadet=float(input("Ingrese delta de t(en seg):"))
        if deltadet<=0:
            print("El delta de t tiene que ser mayor que cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            velocidad=deltadex/deltadet
            print("La velocidad es : ",velocidad," metros/seg.")

def mru_calcula_t():
    ok=False 
    while(not ok):
        deltadex=float(input("Ingrese delta de x(en mtr):"))
        velocidad=float(input("Ingrese velocidad (en metros/seg):"))
        if velocidad<=0:
            print("La velocidad tiene que ser mayor a cero! Vuelva a intentarlo.")
            continue
        elif deltadex<0:
            print("El delta de x tiene que ser mayor o igual a cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            deltadet=deltadex/velocidad
            print("El delta de t es : ",deltadet," seg.")
         
def mru():
    print("Usted selecciono ∆x = v * ∆t")
    ok=False 
    while(not ok):
        opcion=input("Seleccione lo que desea calcular\na:∆x\nb:V \nc:∆t\n")
        if opcion=='a' or opcion=='b' or opcion=='c':
            ok=True
        else:
            print("Opción no válida. Por favor, seleccione 'a', 'b' o 'c'.")
    
    if opcion == 'a':
        mru_calcula_x()
    elif opcion == 'b':
        mru_calcula_v()
    elif opcion == 'c':
        mru_calcula_t()

def opcionb_calcula_deltadex():
    ok=False 
    while(not ok):
        vi=float(input("Ingrese velocidad inicial(en mtr/seg):"))
        deltadet=float(input("Ingrese delta de t(en seg):"))
        aceleracion=float(input("Ingrese aceleracion (en m/seg^2):"))
        if vi<0:
            print("La velocidad tiene que ser mayor o igual que cero! Vuelva a intentarlo.")
            continue
        elif deltadet<=0:
            print("El delta de t tiene que ser mayor que cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            deltadex=vi*deltadet + 0.5*aceleracion*deltadet*deltadet
            print("El delta de x es: ",deltadex," metros.")
            break

def opcionb_calcula_vi():
    ok=False 
    while(not ok):
        deltadex=float(input("Ingrese delta de x(en mtr):"))
        deltadet=float(input("Ingrese delta de t(en seg):"))
        aceleracion=float(input("Ingrese aceleracion (en m/seg^2):"))

        if deltadet<=0:
            print("El delta de t tiene que ser mayor que cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            vi=(deltadex - (0.5*aceleracion*deltadet*deltadet))/(deltadet)
            print("La velocidad inicial es: ",vi," metros/seg.")
            break

def opcionb_calcula_deltadet():
    ok=False 
    while(not ok):
        deltadex=float(input("Ingrese delta de x(en metros):"))
        vi=float(input("Ingrese velocidad inicial (en metros/seg):"))
        aceleracion=float(input("Ingrese aceleracion (en m/seg^2):"))
        if vi<0:
            print("La velocidad tiene que ser mayor o igual que cero! Vuelva a intentarlo.")
            continue
        elif aceleracion==0:
            #MRU
            ok=True
            delta_t=deltadex/vi
            print("El delta de t es : ",delta_t," segundos.")
            break
        #para que se cumpla la desigualdad vi^2 + 2*alfa*delta_x>=0 
        elif aceleracion<0:
            print("La aceleracion tiene que ser mayor que cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            #Solo la solucion positiva
            deltadet=(-vi + math.sqrt(vi*vi + 2*aceleracion*deltadex))/aceleracion 
            print("El delta de t es: ",deltadet," segundos.")
            break

def opcionb_calcula_aceleracion():
    ok=False 
    while(not ok):
        deltadex=float(input("Ingrese delta de x(en metros):"))
        vi=float(input("Ingrese velocidad inicial (en metros/seg):"))
        deltadet=float(input("Ingrese el delta de t (en seg):"))
        if vi<0:
            print("La velocidad tiene que ser mayor o igual que cero! Vuelva a intentarlo.")
            continue
        elif deltadet<=0:
            print("El delta de t tiene que ser mayor que cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            aceleracion=(2*(deltadex - vi * deltadet))/(deltadet*deltadet)
            print("La aceleracion es: ",aceleracion," m/s^2.")
            break

def mruv_falta_vf():
    ok=False 
    while(not ok):
        opcion=input("Seleccione lo que desea calcular\na:∆x\nb:Vi\nc:∆t\nd:α\n")
        if opcion=='a' or opcion=='b' or opcion=='c' or opcion=='d':
            ok=True
        else:
            print("Opción no válida. Por favor, seleccione 'a', 'b','c' o 'd.")

    if opcion == 'a':
        opcionb_calcula_deltadex()
    elif opcion == 'b':
        opcionb_calcula_vi()
    elif opcion == 'c':
        opcionb_calcula_deltadet()
    elif opcion=='d':
        opcionb_calcula_aceleracion()

def opcionc_calcula_vf():
    ok=False 
    while(not ok):
        vi=float(input("Ingrese velocidad inicial (en metros/seg):"))
        deltadet=float(input("Ingrese el delta de t (en seg):"))
        aceleracion=float(input("Ingrese aceleracion (en metros/seg^2):"))
        if vi<0:
            print("La velocidad tiene que ser mayor o igual que cero! Vuelva a intentarlo.")
            continue
        elif deltadet<=0:
            print("El delta de t tiene que ser mayor que cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            vf=vi + aceleracion*deltadet
            print("La velocidad final es: ",vf," m/s.")
            break

def opcionc_calcula_vi():
    ok=False 
    while(not ok):
        vf=float(input("Ingrese velocidad final (en metros/seg):"))
        deltadet=float(input("Ingrese el delta de t (en seg):"))
        aceleracion=float(input("Ingrese aceleracion (en metros/seg^2):"))
        if deltadet<=0:
            print("El delta de t tiene que ser mayor que cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            vi=vf-aceleracion*deltadet
            print("La velocidad inicial es: ",vi," m/s.")
            break

def opcionc_calcula_delta_t():
    ok=False 
    while(not ok):
        vi=float(input("Ingrese velocidad inicial (en metros/seg):"))
        vf=float(input("Ingrese velocidad final (en metros/seg):"))
        aceleracion=float(input("Ingrese aceleracion (en metros/seg^2):"))
        if vi<0:
            print("La velocidad tiene que ser mayor o igual que cero! Vuelva a intentarlo.")
            continue
        elif aceleracion==0:
            print("La aceleracion tiene que ser diferente a cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            deltadet=(vf-vi)/aceleracion
            print("El delta de t es: ",deltadet," segundos.")
            break

def opcionc_calcula_aceleracion():
    ok=False 
    while(not ok):
        vi=float(input("Ingrese velocidad inicial (en metros/seg):"))
        vf=float(input("Ingrese velocidad final (en metros/seg):"))
        deltadet=float(input("Ingrese delta de t (en seg):"))
        if vi<0:
            print("La velocidad tiene que ser mayor o igual que cero! Vuelva a intentarlo.")
            continue
        elif deltadet<=0:
            print("El delta de t tiene que ser mayor a cero! Vuelva a intentarlo.")
            continue
        else:
            ok=True
            aceleracion=(vf-vi)/deltadet
            print("La aceleracion es: ",aceleracion," m/seg^2.")
            break

def mruv_falta_x():
    ok=False 
    while(not ok):
        opcion=input("Seleccione lo que desea calcular\na:vf\nb:Vi\nc:∆t\nd:α\n")
        if opcion=='a' or opcion=='b' or opcion=='c' or opcion=='d':
            ok=True
        else:
            print("Opción no válida. Por favor, seleccione 'a', 'b','c' o 'd.")

    if opcion == 'a':
        opcionc_calcula_vf()
    elif opcion == 'b':
        opcionc_calcula_vi()
    elif opcion == 'c':
        opcionc_calcula_delta_t()
    elif opcion=='d':
        opcionc_calcula_aceleracion()

def main():
    print("Bienvenido a la calculadora\n")
    ok=False 
    while(not ok):
        opcion=input("Seleccione la ecuación a utilizar\na:∆x = v * ∆t\nb:∆x = Vi*∆t +0.5*(α*∆t^2)\nc:Vf = Vi*∆t + α*∆t\n")
        if opcion=='a' or opcion=='b' or opcion=='c':
            ok=True
        else:
            print("Opción no válida. Por favor, seleccione 'a', 'b' o 'c'.")
    
    if opcion == 'a':
        mru()
    elif opcion == 'b':
        mruv_falta_vf()
    elif opcion == 'c':
        mruv_falta_x()

main()