from bs4 import BeautifulSoup
from SeleniumOperations import *
from OSthings import *

def get_problems_for_page(driver, page_number):
  openUrl(driver, 'https://leetcode.com/problemset/algorithms/?page=' + str(page_number))
  html = driver.page_source
  soup = BeautifulSoup(html, "html.parser")
  links = []
  link_prefix = 'https://leetcode.com'
  # get all the links in the page 
  for a in soup.find_all('a', href = True):
    link = a['href']
    # if the link is a problem link
    # pattern for a problem's link -> problems/[problemName]
    # list should be ['', 'problems', 'problemName', ''] if this link is for a problem
    list = link.split('/')
    if len(list) == 4 and list[-3] == 'problems' and list[-1] == '':
      links.append(link_prefix + link)
  return links

def get_all_problems_links(driver, max_page_numer = 1):
  problem_links = []
  try:
    page = 1 
    # get problems links in pages [1, 2, 3, 4, ..., max_page_number]
    while page <= max_page_numer:
      cur_page_links = get_problems_for_page(driver, page)
      # add the cur_page_links to the total links 
      problem_links.extend(cur_page_links)
      # move to the next page 
      page += 1 
  except Exception as e:
    # in case of any exception, site is down (rest of the script will fail :D) or page not exist ... etc
    print (e)
    return problem_links
  return problem_links

def get_problem_text(driver, problem_link):
  try:
    openUrl(driver, problem_link)
    html = driver.page_source
    soup = BeautifulSoup(html, "html.parser")
    # get the title of the page
    problem_name = soup.head.title.get_text()
    # there is a div which has a class named content__u3I1 question-content__JfgR -> get it's text
    problem_text = soup.find("div", {"class": "content__u3I1 question-content__JfgR"}).get_text() 

    # find the difficulty of the current problem
    # if the page contains div with diff attribute equal any of the ['easy', 'medium', 'hard']
    problem_difficulty = 'none'
    diffs = ['easy', 'medium', 'hard']
    for i in range(3):
      if soup.find("div", {"diff": diffs[i]}) != None:
        problem_difficulty = diffs[i]
        break
    # store the information I got in a dictionary [for easy use]
    dic = {}
    dic['problem_link'] = problem_link
    dic['problem_name'] = problem_name 
    dic['problem_text'] = problem_text
    dic['problem_difficulty'] = problem_difficulty
    return dic
  except Exception as e:
    print (e)
    # something wrong , just return None
    return None
'''
this part not done yet 
def get_solution_link(link):
  return link + 'solution'

def get_problem_solution_text(driver, problem_solution_link):
  try:
    openUrl(driver, problem_solution_link)
    html = driver.page_source
    soup = BeautifulSoup(html, "html.parser")
    solution_text = soup.find("div", {"class": "_16yfq _2YoR3"}).get_text()
    return solution_text
  except:
    return None

def add_solution(driver, link, dic):
  solution = get_problem_solution_text(driver, get_solution_link(link))
  if solution != None:
    dic['problem_solution'] = solution
'''
def save_problem_text(dic):
  # make a folder with difficulty [easy, medium, hard]
  folder_name = dic['problem_difficulty']
  folder_path = get_path(folder_name)
  if os.path.isdir(folder_path) == False:
    os.mkdir(folder_path)
  file_name = dic['problem_difficulty'] + '/' + dic['problem_name'] + '.txt'
  file_path = get_path(file_name) 
  with open(file_path, 'w', encoding='utf-8') as f:
    f.write('ProblemLink: [' + dic['problem_link'] + ']\n\n')
    f.write('ProblemName: [' + dic['problem_name'] + ']\n\n')
    split_line = '\n----------------------------------------------\n'
    for line in dic['problem_text'].split('\n'):
      if len(line) <= 2:
        f.write(split_line)
      else:
        f.write(line + '\n')  
    if 'problem_solution' in dic:
      f.write(split_line)
      f.write(split_line)
      f.write('problem solution')
      for line in dic['problem_solution'].split('\n'):
        if len(line) <= 2:
          f.write(split_line)
        else:
          f.write(line + '\n')
  print (dic['problem_name'] + ' added')



if __name__ == '__main__':
  # to open the browser
  driver = createDriver()
  # get problem links

  # set the number of pages you want to get problems from [page1, page2, page3, ...., MAX_PAGE_NUMBER]
  MAX_PAGE_NUMBER = 40
  problem_links = get_all_problems_links(driver, MAX_PAGE_NUMBER)

  for link in problem_links:
    dic = get_problem_text(driver, link)
    # if we got a problem data 
    if dic != None:
      save_problem_text(dic) 
    else:
      print ('cant get problem text')
  driver.close()
    
    
