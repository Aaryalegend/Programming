from PIL import Image
import numpy as np
import heapq
from collections import defaultdict, Counter

# Load and process the image
def load_image(image_path):
    image = Image.open(image_path).convert('L')  # Convert image to 8-bit grayscale
    return np.array(image)

def extract_tiles(image_array):
    tile_size = 8
    grid_size = 26
    tiles = {}
    for i in range(grid_size):
        for j in range(grid_size):
            tile = image_array[i*tile_size:(i+1)*tile_size, j*tile_size:(j+1)*tile_size]
            tiles[(i, j)] = tile
    return tiles

# Huffman Coding Implementation
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(frequencies):
    priority_queue = [Node(char, freq) for char, freq in frequencies.items()]
    heapq.heapify(priority_queue)

    while len(priority_queue) > 1:
        left = heapq.heappop(priority_queue)
        right = heapq.heappop(priority_queue)
        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right
        heapq.heappush(priority_queue, merged)

    return priority_queue[0]

def build_huffman_code_table(root):
    def _build_code(node, prefix='', code_table={}):
        if node is not None:
            if node.char is not None:
                code_table[node.char] = prefix
            _build_code(node.left, prefix + '0', code_table)
            _build_code(node.right, prefix + '1', code_table)
        return code_table

    return _build_code(root)

def encode_data(data, code_table):
    return ''.join(code_table[char] for char in data)

def decode_data(encoded_data, code_table):
    reversed_code_table = {v: k for k, v in code_table.items()}
    current_code = ''
    decoded_chars = []
    for bit in encoded_data:
        current_code += bit
        if current_code in reversed_code_table:
            decoded_chars.append(reversed_code_table[current_code])
            current_code = ''
    return ''.join(decoded_chars)

def log_movements(movements):
    frequency = Counter(movements)
    root = build_huffman_tree(frequency)
    code_table = build_huffman_code_table(root)
    encoded_data = encode_data(movements, code_table)
    return encoded_data, code_table

def decode_movements(encoded_data, code_table):
    reversed_code_table = {v: k for k, v in code_table.items()}
    decoded_data = decode_data(encoded_data, reversed_code_table)
    return decoded_data

# Example Usage
if __name__ == "__main__":
    image_path = '/home/aryan/Downloads/Programming/CA_Lab/your_image.png'  # Update this path if needed
    image_array = load_image(image_path)
    tiles = extract_tiles(image_array)
    
    # For demonstration, let's assume some dummy movements
    movements = "moveA rotateB moveC rotateD"  # Replace with actual movement string
    encoded_data, code_table = log_movements(movements)
    
    print("Encoded Movements:", encoded_data)
    print("Code Table:", code_table)  # Print the Huffman code table for debugging
    
    decoded_movements = decode_movements(encoded_data, code_table)
    print("Decoded Movements:", decoded_movements)
