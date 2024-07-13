import cv2
import numpy as np
import pytesseract
from scipy.ndimage import gaussian_filter

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

def process_image(image_path):
    image = cv2.imread(image_path)
    if image is None:
        print("Error al leer la imagen")
        return
    
    print("Imagen leída correctamente, dimensiones:", image.shape)
    
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    print("Imagen convertida a escala de grises")
    
    blurred = gaussian_filter(gray, sigma=1)
    _, binary = cv2.threshold(blurred, 128, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
    print("Imagen preprocesada")
    
    text = pytesseract.image_to_string(binary, lang='eng')
    print("Texto extraído:", text)

if __name__ == "__main__":
    image_path = 'image2.png'
    process_image(image_path)

