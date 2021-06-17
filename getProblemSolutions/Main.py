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
                if columns[5].text == 'Accepted' and problem_name not in problemNames:
                    try:
                        columns[0].click()
                        problemNames.add(problem_name)
                        # problem Tags and rating
                        problem_real_name = getProblemName(problem_link)
                        problemData = getProblemData(problem_link, dic_problem_Data)
                        if problemData != -1:
                            problemTags = problemData['tags']
                            problemRating = problemData['rating']
                            print('Tags -> ' , problemTags)
                            print('Rating -> ' , problemRating)
                        else:
                            print('no data exist for the problem')
                        tableInside = -1
                        all_li = -1
                        for rep in range(3):
                            try:
                                tableInside = driver.find_element_by_xpath('//*[@id="facebox"]/div/div/div/pre/code/ol')
                                all_li = tableInside.find_elements_by_tag_name('li')
                                break
                            except Exception as e:
                                print(e)
                        if all_li == -1:
                            continue
                        lines = ''
                        for i in all_li:
                            lines += i.text + '\n'
                        problem_name = problem_name.split('-')[1]
                        problem_name = problem_real_name + '-' + problem_name
                        add(problem_name, lines, lang)
                    except Exception as e:
                        print(e)
                    finally:
                        clickEsc(driver)
        except Exception as e:
            print(e)
            break
    driver.quit()

# set 0 to get problems without login
# set 1 to get problems with login
storeProblems(0)
