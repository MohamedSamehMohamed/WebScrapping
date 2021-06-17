from bs4 import BeautifulSoup
from selenium import webdriver
import time
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import pickle
import os
from getProblemTags import getProblemTags
from selenium.webdriver.common.keys import Keys

# change those
username = 'MohamedSameh'
email = 'email or username used in login'
password = 'password'

# don't change
url = 'https://codeforces.com/enter'
email_xpath = '//*[@id="handleOrEmail"]'
pass_xpath = '//*[@id="password"]'
login_xp = '//*[@id="enterForm"]/table/tbody/tr[4]/td/div[1]/input'

def clickEsc(driver):
    webdriver.ActionChains(driver).send_keys(Keys.ESCAPE).perform()

def get_Path(file_name, exten = '.pkl'):
    Path = os.path.dirname(os.path.abspath(__file__))
    my_file = os.path.join(Path, file_name + exten)
    return my_file

def cookies_file_path():
    return get_Path('cookies')

def save_cookies(driver):
    cookies = driver.get_cookies()
    pickle.dump(cookies, open(cookies_file_path(), "wb"))

def load_cookies(driver):
    try:
        cookies = pickle.load(open(cookies_file_path(), "rb"))
        for cookie in cookies:
            driver.add_cookie(cookie)
        driver.refresh()
    except:
        log_in(driver)

def click(driver, xpath):
    button = driver.find_element_by_xpath(xpath)
    driver.execute_script("arguments[0].click();", button)

def send_keys(driver, xpath, key):
    WebDriverWait(driver, 20).until(EC.element_to_be_clickable((By.XPATH, xpath))).send_keys(key)

def log_in(driver):
    driver.get(url)
    send_keys(driver, email_xpath, email)
    send_keys(driver, pass_xpath, password)
    click(driver, login_xp)
    save_cookies(driver)

def createDriver():
    chrome_options = webdriver.ChromeOptions()
    chrome_options.add_argument("start-maximized")
    chrome_options.add_argument("--disable-extensions")
    prefs = {"profile.default_content_setting_values.notifications" : 2}
    chrome_options.add_experimental_option("prefs",prefs)
    driver = webdriver.Chrome(ChromeDriverManager().install(), chrome_options=chrome_options)
    return driver
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
    if empty(lines):
        return 0
    return 1

def add(problem_name, lines, exten):
    if not valid(lines):
        return
    prefixPath = get_Path('Codes', '')
    try:
        os.makedirs(prefixPath)
    except:
        pass
    f = open(get_Path('Codes/' + problem_name, exten), "w")
    f.write(lines)
    f.close()
    print(problem_name + ' added')
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
        return -1

def getProblemData(problem_link, dic_problem_Data):
    problemName = getProblemName(problem_link)
    print(problemName)
    if problemName in dic_problem_Data:
        return dic_problem_Data[problemName]
    return -1
def getLastPageNumber(driver):
    currentUrl = 'https://codeforces.com/submissions/'+username+'/page/1'
    driver.get(currentUrl)
    time.sleep(.75)
    lastPageNumber = driver.find_element_by_class_name('pagination').find_elements_by_tag_name('li')[-2].find_element_by_tag_name('span')
    print(lastPageNumber.text)
    return 1000

def storeProblems(withLogin):
    dic_problem_Data = getProblemTags()
    driver = createDriver()
    driver.get(url)
    if withLogin:
        load_cookies(driver)
    time.sleep(5)
    problemNames = set()
    lastPageNumber = getLastPageNumber(driver)
    exit()
    for pageNumber in range(1, lastPageNumber):
        try:
            currentUrl = 'https://codeforces.com/submissions/'+username+'/page/' + str(pageNumber)
            driver.get(currentUrl)
            time.sleep(.75)
            table = driver.find_element_by_class_name('status-frame-datatable')
            rows = table.find_elements_by_tag_name('tr')[1:]
            for row in rows:
                columns = row.find_elements_by_tag_name('td')
                problem_name = columns[3].text
                problem_link = columns[3].find_element_by_tag_name('a').get_attribute('href')
                lang = columns[4].text
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
                        for rep in range(3):
                            try:
                                tableInside = driver.find_element_by_xpath('//*[@id="facebox"]/div/div/div/pre/code/ol')
                                all_li = tableInside.find_elements_by_tag_name('li')
                                lines = ''
                                for i in all_li:
                                    lines += i.text + '\n'
                                problem_name = problem_name.split('-')[1]
                                problem_name = problem_real_name + '-' + problem_name
                                add(problem_name, lines, getExtension(lang))
                                break
                            except:
                                time.sleep(1)
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
