import cv2
import numpy as np
import matplotlib.pyplot as plt

def getGradients(image, kernel):
    height, width = image.shape
    k_height, k_width = kernel.shape
    output = np.zeros((height - k_height + 1, width - k_width + 1))

    for i in range(height - k_height + 1):
        for j in range(width - k_width + 1):
            output[i, j] = np.sum(image[i:i+k_height, j:j+k_width] * kernel)

    return output

# Load the image
image_path = r'D:\College\DSA\Data-Structures-and-Algorithms\Dhakkshin S R\test2.jpg' 
original_image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

# Sobel kernels
sobel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
sobel_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

# Calculatiing the x anf y gradients of the image with Sobel kernels
sobel_x_result = getGradients(original_image, sobel_x)
sobel_y_result = getGradients(original_image, sobel_y)

# Calculate the magnitude of the gradient
gradient_magnitude = np.sqrt(sobel_x_result**2 + sobel_y_result**2)

# Save the final result
output_path = r'D:\College\DSA\Data-Structures-and-Algorithms\Dhakkshin S R\gradient_magnitude.jpg' 
cv2.imwrite(output_path, gradient_magnitude)


