from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium import webdriver
from bs4 import BeautifulSoup
import time

def clickEsc(driver):
    webdriver.ActionChains(driver).send_keys(Keys.ESCAPE).perform()

def click(driver, xpath):
    button = driver.find_element_by_xpath(xpath)
    driver.execute_script("arguments[0].click();", button)

def send_keys(driver, xpath, key):
    WebDriverWait(driver, 20).until(EC.element_to_be_clickable((By.XPATH, xpath))).send_keys(key)

def openUrl(driver, url):
    if driver.current_url != url:
        driver.get(url)
        time.sleep(3)

def createDriver():
    chrome_options = webdriver.ChromeOptions()
    chrome_options.add_argument("start-maximized")
    chrome_options.add_argument("--disable-extensions")
    prefs = {"profile.default_content_setting_values.notifications" : 2}
    chrome_options.add_experimental_option("prefs",prefs)
    driver = webdriver.Chrome(ChromeDriverManager().install(), chrome_options=chrome_options)
    return driver
