import cv2 as cv
import numpy as np
import os
import re
from PIL import Image, ImageDraw

def sort_images(image_folder):
    images = os.listdir(image_folder)
    images.sort(key=lambda x: int(re.search(r'\d+', x).group()))
    return images

def find_dot(image):
    gray_image = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    _, thresholded_image = cv.threshold(gray_image, 200, 255, cv.THRESH_BINARY_INV)
    contours, _ = cv.findContours(thresholded_image, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        x, y, w, h = cv.boundingRect(contour)
        center_x = x + w // 2
        center_y = y + h // 2
        mask = np.zeros(image.shape[:2], dtype=np.uint8)
        cv.drawContours(mask, [contour], -1, color=255, thickness=-1)
        mean_color = cv.mean(image, mask=mask)[:3]
        return (center_x, center_y), tuple(map(int, mean_color))
    return None, None

def main():
    image_folder = 'Operation-Pixel-Merge/assets'  # Ensure this path points to your assets folder
    images = sort_images(image_folder)

    dot_positions = []
    dot_colors = []
    canvas_size = (512, 512)
    
    # Create a blank canvas
    canvas = Image.new("RGB", canvas_size, "white")
    draw = ImageDraw.Draw(canvas)
    
    for i, image_name in enumerate(images):
        image_path = os.path.join(image_folder, image_name)
        image = cv.imread(image_path)
        
        # Check if the image is completely white (line break)
        if np.mean(image) == 255:
            # Skip this image, indicating a line break
            dot_positions.append(None)
            dot_colors.append(None)
            continue
        
        # Find the dot and its color
        dot_position, dot_color = find_dot(image)
        if dot_position and dot_color:
            dot_positions.append(dot_position)
            dot_colors.append(dot_color)
        
        # Draw lines between consecutive dots
        if i > 0 and dot_positions[i-1] and dot_positions[i]:
            draw.line([dot_positions[i-1], dot_positions[i]], fill=dot_colors[i-1], width=2)

    # Save the final image
    canvas.save('stitched_image.png')
    print("Stitched image saved as stitched_image.png")

if __name__ == "__main__":
    main()
