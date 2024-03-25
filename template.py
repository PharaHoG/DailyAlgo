import os
import time
import shutil

def generate_files(file_prefix):
    # 生成当前时间戳
    timestamp = time.strftime("%y%m%d")
    # 生成文件夹名
    folder_name = f"{timestamp}_{file_prefix}"
    
    # 创建文件夹
    os.makedirs(folder_name)
    
    # 创建.cpp文件
    cpp_filename = f"{file_prefix}.cpp"
    with open(os.path.join(folder_name, cpp_filename), 'w') as cpp_file:
        cpp_file.write("// Write your C++ code here")
    
    # 复制.md文件
    source_md_file = "template.md"
    destination_md_file = f"{file_prefix}.md"
    shutil.copyfile(source_md_file, os.path.join(folder_name, destination_md_file))
    
    print(f"文件夹 '{folder_name}' 及文件 '{cpp_filename}' 和 '{destination_md_file}' 已成功创建。")

if __name__ == "__main__":
    file_prefix = input("请输入文件前缀(如 202_happy-number)：")
    generate_files(file_prefix)
