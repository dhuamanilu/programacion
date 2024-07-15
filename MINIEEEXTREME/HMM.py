import numpy as np
import cv2
from hmmlearn import hmm
import pytesseract

# Función para convertir la imagen a escala de grises y normalizarla
def preprocess_image(image_path):
    image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    normalized_image = cv2.normalize(image, None, 0, 1, cv2.NORM_MINMAX, dtype=cv2.CV_32F)
    return normalized_image

# Función para obtener las características de la imagen para el HMM
def get_image_features(image):
    rows, cols = image.shape
    features = []

    for i in range(rows):
        for j in range(cols):
            features.append([image[i, j]])

    return np.array(features)

# Función para entrenar el HMM y binarizar la imagen
def binarize_image_with_hmm(image_path):
    image = preprocess_image(image_path)
    features = get_image_features(image)

    # Definir y entrenar el HMM
    model = hmm.GaussianHMM(n_components=2, covariance_type="diag", n_iter=100)
    model.fit(features)

    # Predecir los estados ocultos (binarización)
    hidden_states = model.predict(features)
    binarized_image = hidden_states.reshape(image.shape)

    return binarized_image

# Función para extraer texto usando pytesseract
def extract_text_from_image(image):
    text = pytesseract.image_to_string(image, lang='eng')
    return text

# Ruta de la imagen de entrada
image_path = 'numeros.png'

# Binarizar la imagen usando HMM
binarized_image = binarize_image_with_hmm(image_path)

# Guardar la imagen binarizada
cv2.imwrite('binarized_image.jpg', binarized_image * 255)

# Convertir la imagen binarizada a formato adecuado para pytesseract
binarized_image_uint8 = (binarized_image * 255).astype(np.uint8)

# Extraer texto de la imagen binarizada
extracted_text = extract_text_from_image(binarized_image_uint8)

# Mostrar la imagen binarizada y el texto extraído
cv2.imshow('Binarized Image', binarized_image_uint8)
cv2.waitKey(0)
cv2.destroyAllWindows()

print("Texto extraído:")
print(extracted_text)
