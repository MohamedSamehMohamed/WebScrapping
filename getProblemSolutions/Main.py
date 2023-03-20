import time
from getProblemTags import getProblemTags
from SaveToFile import *
from OSPath import *
from Login import Login
from ExtractFrom import *
from SeleniumOperations import *

username = 'MohamedSameh'
email = ''
password = ''
from GitHub import git_push

def store_problems(with_login):
    dic_problem_data = getProblemTags()
    driver = WebDriver()
    if with_login:
        Login(driver, email, password)
    problem_names = set()
    last_page_number = get_last_page_number(driver, username)
    for pageNumber in range(1, last_page_number + 1):
        try:
            current_url = 'https://codeforces.com/submissions/'+username+'/page/' + str(pageNumber)
            driver.openUrl(current_url)
            rows = driver.getTableTR('status-frame-datatable')
            submissions_link = get_submissions(rows)
            for submission in submissions_link:
                try:
                    if submission.problem_name in problem_names:
                        continue
                    problem_names.add(submission.problem_name)
                    driver.openUrl(submission.submission_link)
                    lines = driver.readSourceLines()
                    add(submission.get_store_name(), lines, submission.submission_lang)
                    problem_meta = get_problem_data(submission.real_name, dic_problem_data)
                    git_push(get_Path('Codes/' + submission.get_store_name(), '.cpp'), problem_meta)
                except Exception as e:
                    print('1 ', e)
                    continue
        except Exception as e:
            print('2 ', e)
            continue
    driver.quit()

# set 0 to get problems without login
# set 1 to get problems with login
store_problems(0)
