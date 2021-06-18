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

def storeProblems(withLogin):
    dic_problem_Data = getProblemTags()
    driver = createDriver()
    if withLogin:
        Login(driver, email, password)
    problemNames = set()
    lastPageNumber = getLastPageNumber(driver, username)
    for pageNumber in range(1, lastPageNumber + 1):
        try:
            currentUrl = 'https://codeforces.com/submissions/'+username+'/page/' + str(pageNumber)
            openUrl(driver, currentUrl)
            table = driver.find_element_by_class_name('status-frame-datatable')
            rows = table.find_elements_by_tag_name('tr')[1:]
            submissionsLink = getSubmissionsLink(rows)
            for submission in submissionsLink:
                try:
                    if submission.problemName in problemNames:
                        continue
                    problemNames.add(submission.problemName)
                    openUrl(driver, submission.submissionLink)
                    lines = readSourceLines(driver)
                    add(submission.getProblemStoreName(), lines, submission.submissionLang)
                    printProblemData(submission.problem_real_name, dic_problem_Data)
                except Exception as e:
                    print('1 ', e)
                    continue
        except Exception as e:
            print('2 ', e)
            continue
    driver.quit()

# set 0 to get problems without login
# set 1 to get problems with login
storeProblems(0)
