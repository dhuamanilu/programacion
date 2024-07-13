import socket
import cv2
import numpy as np
import pytesseract
from scipy.ndimage import gaussian_filter
import struct

def compute_gvf(f, mu, iterations):
    u = np.zeros_like(f, dtype=np.float64)
    v = np.zeros_like(f, dtype=np.float64)
    fx, fy = np.gradient(f.astype(np.float64))
    fx = np.clip(fx, -1e5, 1e5)
    fy = np.clip(fy, -1e5, 1e5)
    for _ in range(iterations):
        u_xx = cv2.Laplacian(u, cv2.CV_64F)
        u_yy = cv2.Laplacian(v, cv2.CV_64F)
        u = u + mu * u_xx - (u - fx) * (fx**2 + fy**2)
        v = v + mu * u_yy - (v - fy) * (fx**2 + fy**2)
        u = np.clip(u, -1e5, 1e5)
        v = np.clip(v, -1e5, 1e5)
    return u, v

def process_image(image):
    if image is None:
        print("Error al leer la imagen")
        return ""
    
    print("Imagen leída correctamente, dimensiones:", image.shape)
    
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    print("Imagen convertida a escala de grises")
    
    blurred = gaussian_filter(gray, sigma=1)
    _, binary = cv2.threshold(blurred, 128, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
    print("Imagen preprocesada")
    
    text = pytesseract.image_to_string(binary, lang='eng')
    print("Texto extraído:", text)
    return text

def recv_all(sock, size):
    data = b''
    while len(data) < size:
        packet = sock.recv(size - len(data))
        if not packet:
            return None
        data += packet
    return data

def server_program():
    host = '0.0.0.0'
    port = 5000
    
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(2)
    
    print("Servidor en espera de conexiones...")
    
    while True:
        conn, address = server_socket.accept()
        print("Conexión desde:", address)
        
        # Recibir el tamaño de la imagen
        img_size_data = recv_all(conn, 4)
        if img_size_data is None:
            conn.close()
            continue
        
        img_size = struct.unpack('>I', img_size_data)[0]
        
        # Recibir la imagen
        img_data = recv_all(conn, img_size)
        if img_data is None:
            conn.close()
            continue
        
        # Convertir bytes a imagen de OpenCV
        np_img = np.frombuffer(img_data, dtype=np.uint8)
        image = cv2.imdecode(np_img, cv2.IMREAD_COLOR)
        
        # Procesar la imagen y extraer texto
        text = process_image(image)
        
        # Enviar texto extraído al cliente
        conn.sendall(text.encode('utf-8'))
        
        conn.close()

if __name__ == "__main__":
    server_program()





