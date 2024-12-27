import os
import json
import re

def rename_filenames_in_json(directory):
    """Rename filenames in JSON files in the specified directory"""
    json_files = [os.path.join(directory, f) for f in os.listdir(directory) if f.endswith('.json')]
    
    # Regex pattern to identify the filename structure
    pattern = re.compile(r'(.+_\d+_)')
    
    # Counter for numbering
    counter = 0

    for file_path in json_files:
        try:
            with open(file_path, 'r', encoding='utf-8') as file:
                data = json.load(file)
            
            # Extract the original filename
            original_filename = data['images']['filename']
            
            # Find the base part using regex
            match = pattern.search(original_filename)
            if match:
                base_filename = match.group(1)
                new_filename = f"{base_filename}w0022.png"
                data['images']['filename'] = new_filename
                
                
                # Save the modified JSON file
                with open(file_path, 'w', encoding='utf-8') as file:
                    json.dump(data, file, ensure_ascii=False, indent=4)
                
                print(f"Processed {file_path}: {original_filename} -> {new_filename}")
            else:
                print(f"No match found in filename: {original_filename}")

        except json.JSONDecodeError as e:
            print(f"Error decoding JSON from {file_path}: {e}")
        except Exception as e:
            print(f"Error reading {file_path}: {e}")

# JSON files directory
json_files_directory = r'D:\시각 장애인 사업 데이터셋\이륜자동차 위험 시설물 데이터\01.데이터\1.Training\라벨링테이터_230222_add'

# Rename filenames in JSON files
rename_filenames_in_json(json_files_directory)
