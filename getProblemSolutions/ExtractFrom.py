from SeleniumOperations import openUrl

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

def getProblemName(problem_link):
    try:
        strs = problem_link.split('/')
        contestId = -1
        problemOrder = -1
        cnt = 0
        idx = -1
        for s in strs:
            if s == 'gym' or s == 'contest':
                idx = cnt
                break
            cnt += 1
        if idx == -1:
            return -1
        contestId = strs[idx+1]
        problemOrder = strs[idx+3]
        return str(contestId) + str(problemOrder)
    except:
        print(e)
        return -1

def getProblemData(problemName, dic_problem_Data):
    if problemName in dic_problem_Data:
        return dic_problem_Data[problemName]
    return -1

def getLastPageNumber(driver, username):
    try:
        currentUrl = 'https://codeforces.com/submissions/'+username+'/page/1'
        openUrl(driver, currentUrl)
        lastPageNumber = driver.find_elements_by_class_name('pagination')[1].find_elements_by_tag_name('li')[-2].find_element_by_tag_name('span')
        return int(lastPageNumber.text)
    except Exception as e:
        print('here ', e)
        return 1

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
