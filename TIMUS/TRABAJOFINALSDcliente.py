import socket
import cv2
import struct

def client_program(image_path):
    host = '127.0.0.1'
    port = 5000
    
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))
    
    # Leer la imagen
    image = cv2.imread(image_path)
    
    # Redimensionar la imagen a un tamaño pequeño fijo, por ejemplo, 50x50 píxeles
    resized_image = cv2.resize(image, (50, 50))
    
    # Convertir la imagen redimensionada a bytes
    _, img_encoded = cv2.imencode('.png', resized_image)
    img_bytes = img_encoded.tobytes()
    
    # Enviar tamaño de la imagen
    client_socket.sendall(struct.pack('>I', len(img_bytes)))
    
    # Enviar imagen
    client_socket.sendall(img_bytes)
    
    # Recibir texto extraído
    data = client_socket.recv(4096)
    print("Texto extraído:", data.decode('utf-8'))
    
    client_socket.close()

if __name__ == "__main__":
    image_path = 'image1.png'
    client_program(image_path)




