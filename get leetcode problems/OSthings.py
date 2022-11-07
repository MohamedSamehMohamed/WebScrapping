import os

def get_path(file_name):
  Path = os.path.dirname(os.path.abspath(__file__))
  my_file = os.path.join(Path, file_name)
  return my_file
