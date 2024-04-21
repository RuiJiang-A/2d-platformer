import os

# 加载 SCons 环境
environment = SConscript("godot-cpp/SConstruct")

# 从命令行接收 'godot-project-directory' 和 'source-directory' 参数
# 如果未指定，使用默认值
godot_project_directory = ARGUMENTS.get('godot-project-directory', 'game')
source_directory = ARGUMENTS.get('source-directory', 'src')

# 显示使用的目录
print(f"Using Godot project directory: {godot_project_directory}")
print(f"Using source directory: {source_directory}")

# 添加源代码目录到包含路径
environment.Append(CPPPATH=[source_directory])

# 使用 os.walk() 遍历 source_directory 并找到所有的 .cpp 文件
source_files = []
for dirpath, dirnames, filenames in os.walk(source_directory):
    for filename in filenames:
        if filename.endswith('.cpp'):
            full_path = os.path.join(dirpath, filename)
            source_files.append(full_path)

if not source_files:
    print(f"No source files found in {source_directory}. Check the source directory path.")
    Exit(1)  # 如果没有找到文件，则退出构建

# 根据平台配置输出
platform = environment['platform']
target = environment['target']
suffix = environment.get('suffix', '')
shared_library_suffix = environment['SHLIBSUFFIX']
bin_directory = os.path.join(godot_project_directory, 'bin')

if platform == "macos":
    # macOS 框架路径格式
    macos_format = f"{bin_directory}/cppscripts.{platform}.{target}.framework/cppscripts.{platform}.{target}"
    shared_library = environment.SharedLibrary(macos_format, source=source_files)
else:
    # 标准共享库路径格式
    library_path = f"{bin_directory}/cppscripts{suffix}{shared_library_suffix}"
    shared_library = environment.SharedLibrary(library_path, source=source_files)

# 设置默认构建目标
Default(shared_library)
