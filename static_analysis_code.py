import os
import subprocess
import shutil

def delete_output_dir(directory):
    """Deletes the specified directory if it exists."""
    if os.path.exists(directory):
        shutil.rmtree(directory)
        print(f"Directory {directory} deleted.")

def run_clang_tidy(directory, build_path, file_extensions, checks, exclude_paths=None, exclude_extensions=None, header_filter=".*"):
    # Create the S_A_C directory if it doesn't exist
    output_dir = "S_A_C"
    
    # Delete the S_A_C directory if it already exists
    delete_output_dir(output_dir)
    
    os.makedirs(output_dir, exist_ok=True)
    
    # Initialize exclusion lists if they are None
    if exclude_paths is None:
        exclude_paths = []
    if exclude_extensions is None:
        exclude_extensions = []
    
    # Traverse all file paths in the directory
    for root, dirs, files in os.walk(directory):
        # Check if the path should be excluded
        if any(excluded in root for excluded in exclude_paths):
            continue
        
        for file in files:
            # Filter files by the given extensions and check if they should be excluded
            if any(file.endswith(ext) for ext in file_extensions) and not any(file.endswith(ext) for ext in exclude_extensions):
                file_path = os.path.join(root, file)
                # Build the clang-tidy command
                command = [
                    "clang-tidy",
                    "-p", build_path,
                    file_path,
                    f"-checks={','.join(checks)}",
                    f"-header-filter={header_filter}"
                ]
                # Define the output file
                output_file = os.path.join(output_dir, f"{file}.txt")
                
                # Run the command and save the output in a .txt file
                try:
                    with open(output_file, "w") as f:
                        subprocess.run(command, stdout=f, stderr=subprocess.STDOUT, check=True)
                    print(f"Clang-tidy executed successfully on: {file_path}")
                except subprocess.CalledProcessError as e:
                    print(f"Error running clang-tidy on {file_path}: {e}")

# Example function call
directory = "./linearLib/matrix/"
build_path = "build"
file_extensions = [".hpp", ".cpp", ".c", ".inl"]
checks = ["cppcoreguidelines-*", "clang-analyzer-*","readability-*","bugprone-*", "performance-*"]

# Paths and extensions to exclude
exclude_paths = ["./linearLib/vector/src/"]
exclude_extensions = [".inl"]

run_clang_tidy(directory, build_path, file_extensions, checks, exclude_paths, exclude_extensions)
