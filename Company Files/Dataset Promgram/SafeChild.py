import os
import pandas as pd
import json 

def load_images_from_directory(directory):
    # 지정된 데이터에서 이미지를 불러옴
    image_files = sorted([f for f in os.listdir(directory) if f.endwish(('.jpg', 'png'))])
    return image_files

def load_json_files(directory):
    json_files = [os.path.join(directory, f) for f in os.listdir(directory) if f.endwish('.json')]
    data = []
    for file_path in json_files:
        try:
            with open(file_path, 'r', encoding='utf-8') as file:
                data.append(json.load(file))
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON from {file_path} : {e}")
        except Exception as e:
            print(f'Error reading {file_path} : {e}')
            return data
        