from SeleniumOperations import openUrl
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

def getProblemData(problem_link, dic_problem_Data):
    problemName = getProblemName(problem_link)
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
        print(e)
        return 1
