import open3d as o3d
import numpy as np
import matplotlib.pyplot as plt

# LiDAR 데이터를 pcd 파일에서 불러오기
def load_lidar_data_from_pcd(file_path):
    # Open3D를 사용해 pcd 파일 읽기
    pcd = o3d.io.read_point_cloud(file_path)
    # numpy 배열로 변환 (x, y, z 좌표)
    points = np.asarray(pcd.points)
    return points

# LiDAR 데이터를 시각화하고 JPG로 저장하는 함수
def save_lidar_as_jpg(lidar_data, output_path):
    # x, y 좌표에 대해 산점도 생성, z 값에 따라 색상 설정
    plt.scatter(lidar_data[:, 0], lidar_data[:, 1], c=lidar_data[:, 2], cmap='viridis')
    plt.colorbar(label='Height (z)')  # 컬러바 추가하여 z 값 표현
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('LiDAR Data 2D Visualization')
    
    # JPG 파일로 저장
    plt.savefig(output_path)
    plt.show()

# LiDAR 파일 경로와 저장할 JPG 파일 경로
lidar_file_path = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\lidar\\BK_ALL_20220826_111022_lidar.pcd'  # LiDAR 데이터 PCD 파일 경로
output_jpg_path = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\lidar\\image'  # 저장할 JPG 경로

# LiDAR 데이터 불러오기
lidar_data = load_lidar_data_from_pcd(lidar_file_path)

# JPG 파일로 저장
save_lidar_as_jpg(lidar_data, output_jpg_path)
