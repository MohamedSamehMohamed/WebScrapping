from getProblemTags import get_problem_tags
from SaveToFile import *
from OSPath import *
from Login import login
from ExtractFrom import *
from SeleniumOperations import *
from GitHub import git_push

username = 'MohamedSameh'
email = ''
password = ''
PATH_OF_GIT_REPO = r'E:\ProgrammingLangueTraining\python\WebScrapping\.git'

def store_problems(with_login, push_to_git_hub):
    driver = WebDriver()
    if with_login:
        login(driver, email, password)

    dic_problem_data = get_problem_tags()
    problem_names = set()
    last_page_number = get_last_page_number(driver, username)
    for pageNumber in range(1, last_page_number + 1):
        try:
            current_url = 'https://codeforces.com/submissions/{}/page/{}'.format(username, pageNumber)
            driver.openUrl(current_url)
            submissions_row = get_submissions_row(driver)
            submissions_link = get_submissions(submissions_row)
            for submission in submissions_link:
                try:
                    if submission.problem_name in problem_names:
                        continue
                    problem_names.add(submission.problem_name)
                    driver.openUrl(submission.submission_link)
                    lines = driver.readSourceLines()
                    add(submission.get_store_name(), lines, submission.submission_lang)
                    problem_meta = get_problem_data(submission.real_name, dic_problem_data)
                    if push_to_git_hub:
                        git_push(PATH_OF_GIT_REPO,
                                 get_Path('Codes/' + submission.get_store_name(), '.cpp'),
                                 problem_meta)
                except Exception as e:
                    print(e)
                    continue
        except Exception as e:
            print(e)
            continue
    driver.quit()

'''
first parameter to determine if you want to login or not 
second parameter to determine if you want to push files to git or not 
'''
store_problems(0, 1)