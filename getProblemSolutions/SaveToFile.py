from OSPath import get_Path

def getExtension(lang):
    if 'C++' in lang:
        return '.cpp'
    if 'Java' in lang:
        return '.java'
    if 'Py' in lang:
        return '.py'
    # other lang
    return '.txt'

def empty(lines):
    count = 0
    for c in lines:
        if c != ' ' and c != '\n':
            count+= 1
    return count == 0

def valid(lines):
    return not empty(lines)

def add(problem_name, lines, lang):
    if not valid(lines):
        return
    exten = getExtension(lang)
    prefixPath = get_Path('Codes', '')
    # try to create the dir if not exist
    try:
        os.makedirs(prefixPath)
    except:
        pass
    f = open(get_Path('Codes/' + problem_name, exten), "w")
    f.write(lines)
    f.close()
    print(problem_name + ' added')
