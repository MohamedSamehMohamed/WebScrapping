import requests
import os
import time
from datetime import datetime
import time

Handles = []
Problems = []
groupInfo = []
CurrentWeekProblems = []

def getRequest(url):
    while True:
        try: 
            ret = requests.get(url).json()
            if ret['status'] == 'OK':
                return ret['result']
        except Exception as e:
            time.sleep(2)
            continue

def get_Path(file_name):
    Path = os.path.dirname(os.path.abspath(__file__))
    my_file = os.path.join(Path, file_name)
    return my_file

def readFromFile(fileName, list):
    if len(list) != 0:
        return
    file = open(get_Path(fileName))
    for line in file:
        list.append(line[:-1])
    file.close()

def readHandles():
    if len(Handles) != 0:
        return
    file = open(get_Path('handles'))
    for handle in file:
        Handles.append(handle[:-1])
    file.close()

def get_contest_ids():
  result = getRequest('https://codeforces.com/api/contest.list')
  ids = []
  for row in result:
    # contest finished 
    if row['phase'] == 'FINISHED':
      ids.append(row['id'])
  return ids

def count_participate_contests(handle):
  # this is a shortcut method to calculate how many contest [handle] has participate 
  # it returns the rating change after each contest 
  # which mean that the size of the return list is the number of contests 
  url = 'https://codeforces.com/api/user.rating?handle=' + str(handle)
  result = getRequest(url)
  return len(result)

def count_solved_problems(handle):
  url = 'https://codeforces.com/api/user.status?handle=' + str(handle)
  result = getRequest(url)
  st = set()
  for row in result:
    try:
      p = row['problem']
      full_problem_name = str(p['contestId']) + str(p['index'])
      if full_problem_name not in st:
        st.add(full_problem_name)
    except Exception as e:
      pass 
  return len(st)
readHandles()
print ('Handle : number of contest Entered: number of solved Problems')
for handle in Handles:
  print (handle, end = ' ')
  print(count_participate_contests(handle), end = ' ')
  print (count_solved_problems(handle))
