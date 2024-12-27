import os
import pandas as pd
import json
import re

def load_images_from_directory(directory):
    """Load image filenames from the specified directory"""
    try:
        image_files = [f for f in os.listdir(directory) if f.endswith('.png')]
        image_files.sort()  # Sort by filename
        return image_files
    except Exception as e:
        print(f"Error loading images: {e}")
        return []

def load_json_files(directory):
    """Load all JSON files from the specified directory and convert to pandas DataFrame"""
    json_files = [os.path.join(directory, f) for f in os.listdir(directory) if f.endswith('.json')]
    data = []
    for file_path in json_files:
        try:
            with open(file_path, 'r', encoding='utf-8') as file:
                data.append(json.load(file))
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON from {file_path}: {e}")
        except Exception as e:
            print(f"Error reading {file_path}: {e}")

    # Flatten JSON data and expand nested lists into individual rows
    records = []
    for entry in data:
        image_info = entry['images']
        for annotation in entry['annotation']:
            record = {**image_info, **annotation}
            records.append(record)

    df = pd.DataFrame(records)
    return df

def extract_frame_data(df, frame_filename):
    """Extract object location information for a specific frame"""
    frame_objects = []

    # Filter rows where 'filename' matches the frame_filename
    filtered_df = df[df['filename'] == frame_filename]

    if not filtered_df.empty:
        print(f"Processing frame: {frame_filename}")
        for _, row in filtered_df.iterrows():
            if row['label_type'] == "IMAGE_BBOX":
                bbox = row['bbox']
                if bbox:
                    frame_object = {
                        'label': row['label'],
                        'bbox': bbox
                    }
                    frame_objects.append(frame_object)

        if frame_objects:
            return frame_objects
        else:
            print(f"No annotation data found for {frame_filename}")
            return None

    print(f"No image data found for {frame_filename}")
    return None

# Image file paths and output directory settings
images_directory = r'D:\시각 장애인 사업 데이터셋\이륜자동차 위험 시설물 데이터\01.데이터\1.Training\원천데이터_230222_add\TS_Bounding Box_11.공사안내표지판'
json_files_directory = r'D:\시각 장애인 사업 데이터셋\이륜자동차 위험 시설물 데이터\01.데이터\1.Training\라벨링테이터_230222_add\TS_Bounding Box_11.공사안내표지판'
output_directory = r'D:\시각 장애인 사업 데이터셋\이륜자동차 위험 시설물 데이터\01.데이터\1.Training\원천데이터_230222_add\TS_Bounding Box_11.공사안내표지판\txt'

# Create output directory if it doesn't exist
os.makedirs(output_directory, exist_ok=True)

# Load image filenames from directory
image_files = load_images_from_directory(images_directory)
total_frames = len(image_files)
print(f"Total frames found: {total_frames}")

# Load JSON files and convert to DataFrame
json_data = load_json_files(json_files_directory)

# Verify loaded JSON data structure
print(f"Loaded JSON data columns: {json_data.columns}")

# Process each frame
for image_file in image_files:
    frame_filename = image_file  # Use the full image filename with extension

    # Extract object location information for the specific frame
    frame_data = extract_frame_data(json_data, frame_filename)

    if frame_data:
        # Save to text file (same name as image)
        txt_filename = os.path.splitext(frame_filename)[0] + '.txt'
        txt_file_path = os.path.join(output_directory, txt_filename)  # Set save path and filename
        with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
            for item in frame_data:
                label = item['label']
                bbox = ' '.join(map(str, item['bbox']))  # Convert bbox values to string
                txt_file.write(f"{label} {bbox}\n")

        print(f"Data saved to {txt_file_path}")
    else:
        print(f"No data found for {frame_filename}")
