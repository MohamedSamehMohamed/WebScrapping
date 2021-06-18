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
class Problem:
    def __init__(self, problemName, submissionLink, problem_real_name, submissionLang):
        self.problemName = problemName
        self.submissionLink = submissionLink
        self.problem_real_name = problem_real_name
        self.submissionLang = submissionLang

    def getProblemStoreName(self):
        problem_name = self.problemName.split('-')[1]
        problem_name = self.problem_real_name + '-' + problem_name
        return problem_name

def getContestId(problem_link):
    linkParts = problem_link.split('/')
    contestId = ''
    cnt = -1
    for part in linkParts:
        if str(part) == 'gym' or str(part) == 'contest':
            cnt += 1
        if cnt == -1:
            continue
        contestId += str(part)
        cnt+=1
        if cnt == 2:
            break
        contestId += '/'
    return contestId

def getSubmissionsLink(rows):
    list = []
    for row in rows:
        columns = row.find_elements_by_tag_name('td')
        problem_name = columns[3].text
        problem_link = columns[3].find_element_by_tag_name('a').get_attribute('href')
        lang = columns[4].text
        # check if it can be open
        canSeeCode = 0
        try:
            temp = columns[0].find_element_by_class_name('hiddenSource')
            canSeeCode = 0
        except:
            canSeeCode = 1
        if not canSeeCode:
            continue
        if columns[5].text == 'Accepted':
            submissionId = columns[0].text
            contestId = getContestId(problem_link)
            submissionLink = 'https://codeforces.com/'+contestId + '/submission/' + str(submissionId)
            problemName = columns[3].text
            submissionLang = columns[4].text
            problem_real_name = getProblemName(problem_link)
            list.append(Problem(problemName, submissionLink, problem_real_name, submissionLang))
    return list

def printProblemData(problem_real_name, dic_problem_Data):
    problemData = getProblemData(problem_real_name, dic_problem_Data)
    if problemData != -1:
        problemTags = problemData['tags']
        problemRating = problemData['rating']
        print('Tags -> ' , problemTags)
        print('Rating -> ' , problemRating)
    else:
        print('no data exist for the problem')

def readSourceLines(driver):
    codeTable = driver.find_element_by_xpath('//*[@id="program-source-text"]/ol')
    codeLines = codeTable.find_elements_by_tag_name('li')
    lines = ''
    for i in codeLines:
        lines += i.text + '\n'
    return lines

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
                    #printProblemData(submission.problem_real_name, dic_problem_Data)
                except Exception as e:
                    print(e)
                    continue
        except Exception as e:
            print('Exception 2 ', e)
            break
    driver.quit()

# set 0 to get problems without login
# set 1 to get problems with login
storeProblems(0)
