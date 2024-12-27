import json

def restore_id_format(input_json_file, output_json_file):
    with open(input_json_file, 'r') as f:
        data = json.load(f)
    
    # Restore annotations section
    for annotation in data['annotations']:
        if 'id' in annotation and isinstance(annotation['id'], int):
            object_type = annotation.get('name', 'object')  # Get object type ('person', 'car', etc.)
            annotation['id'] = f"{object_type}_{annotation['id']}"
    
    # Restore background section if applicable
    if 'background' in data:
        for bg_item in data['background']:
            if 'id' in bg_item and isinstance(bg_item['id'], int):
                bg_item['id'] = f"car_{bg_item['id']}"  # Assuming it's always 'car', adjust if needed
    
    # Restore categories section
    for category in data['categories']:
        if 'id' in category and isinstance(category['id'], int):
            supercategory = category.get('supercategory', 'object')  # Get supercategory ('person', 'car', etc.)
            category['id'] = f"{supercategory}_{category['id']}"
     
    with open(output_json_file, 'w') as f:
        json.dump(data, f, indent=4)
    
    print(f"Restored JSON file saved to {output_json_file}.")

# Example usage
input_json_file = r"C:\Users\kiot\Yolo V5\yolov5\TL6_sa-bt_2\morning(9~12)\2021-09-08_09-51-00_wed_sunny_out_sa-bt_C0091.json"
output_json_file = r"C:\Users\kiot\Yolo V5\yolov5\TL6_sa-bt_2\morning(9~12)\restored_output.json"

restore_id_format(input_json_file, output_json_file)
