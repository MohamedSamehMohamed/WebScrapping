from SeleniumOperations import *
import time
import pickle
from OSPath import cookies_file_path

# don't change
url = 'https://codeforces.com/enter'
email_xpath = '//*[@id="handleOrEmail"]'
pass_xpath = '//*[@id="password"]'
login_xp = '//*[@id="enterForm"]/table/tbody/tr[4]/td/div[1]/input'

def save_cookies(driver):
    cookies = driver.get_cookies()
    pickle.dump(cookies, open(cookies_file_path(), "wb"))

def load_cookies(driver, email, password):
    try:
        cookies = pickle.load(open(cookies_file_path(), "rb"))
        for cookie in cookies:
            driver.add_cookie(cookie)
        driver.refresh()
    except Exception as e:
        print(e)
        log_in(driver, email, password)

def log_in(driver, email, password):
    try:
        driver.openUrl(url)
        driver.send_keys(email_xpath, email)
        driver.send_keys(pass_xpath, password)
        driver.click(login_xp)
        save_cookies(driver)
    except Exception as e:
        print(e)

def Login(driver, email, password):
    load_cookies(driver, email, password)
