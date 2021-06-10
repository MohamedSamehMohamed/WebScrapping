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
from selenium.webdriver.common.keys import Keys

# change those 
username = 'your username in codeforces'
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

def empty(lines):
    count = 0
    for c in lines:
        if c != ' ' and c != '\n':
            count+= 1
    return count == 0

def add(problem_name, lines):
    if empty(lines):
        return
    f = open(get_Path('Codes/' + problem_name, '.cpp'), "w")
    for i in lines:
        f.write(i.text + '\n')
    f.close()
    print(problem_name + ' added')

def storeProblems():
    driver = createDriver()
    driver.get(url)
    load_cookies(driver)
    problemNames = set()
    for pageNumber in range(1, 1000):
        try:
            currentUrl = 'https://codeforces.com/submissions/'+username+'/page/' + str(pageNumber)
            driver.get(currentUrl)
            time.sleep(.75)
            table = driver.find_element_by_class_name('status-frame-datatable')
            rows = table.find_elements_by_tag_name('tr')[1:]
            for row in rows:
                columns = row.find_elements_by_tag_name('td')
                problem_name = columns[3].text
                if columns[5].text == 'Accepted' and problem_name not in problemNames:
                    try:
                        columns[0].click()
                        problemNames.add(problem_name)
                        for rep in range(3):
                            try:
                                tableInside = driver.find_element_by_xpath('//*[@id="facebox"]/div/div/div/pre/code/ol')
                                lines = tableInside.find_elements_by_tag_name('li')
                                add(problem_name, lines)
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

storeProblems()
