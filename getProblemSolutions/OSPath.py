import os

def get_Path(file_name, exten = '.pkl'):
    Path = os.path.dirname(os.path.abspath(__file__))
    my_file = os.path.join(Path, file_name + exten)
    return my_file

def cookies_file_path():
    return get_Path('cookies')
